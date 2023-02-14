/* Blink Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"
#include "lvgl_init.h"

#include "board_mfrc522.h"
#include "user_nfc.h"
#include "gui_guider.h"

#include <string.h>
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"

#include "lwip/err.h"
#include "lwip/sys.h"
#include <sys/param.h>
#include "esp_netif.h"
#include "driver/gpio.h"
#include "lwip/sockets.h"
#include "lwip/dns.h"
#include "lwip/netdb.h" 

#include "cJSON.h"
#include "mqtt_client.h"
#include "nvs_flash.h"



/* Can use project configuration menu (idf.py menuconfig) to choose the GPIO to blink,
   or you can edit the following line and set a number here.
*/
#define BLINK_GPIO CONFIG_BLINK_GPIO
#define FengMing_GPIO 16


extern void guiTask1(void *pvParameter);
//extern char *pr_t;

// 程序运行状态定义
u_int8_t zhuce=0;
u_int8_t xiaoka=0;
u_int8_t yi_miao=0;
u_int8_t ear_trace=0;
u_int8_t main_trace=0;

u_int32_t ear_id_n =1913000;
uint8_t card[4];

/* extern u_int32_t gui_id;
extern char *gui_species;
extern char *gui_sex;
extern char *gui_weight;

extern char *gui_sheep_age;
extern char *gui_use_value;
extern char *gui_place_of_production;
extern char *gui_vaccine;
extern char *gui_health; */

u_int32_t gui_id;
char *gui_species;
char *gui_sex;
char *gui_weight;
char *gui_sheep_age;
char *gui_use_value;
char *gui_place_of_production;
char *gui_vaccine;
char *gui_health;


//定义时间
u_int16_t time_year=2023;
u_int8_t time_month=1;
u_int8_t time_day=17;
char *time_weekend="Tue"; 

extern u_int16_t tr_time_year;
extern u_int8_t tr_time_month;
extern u_int8_t tr_time_day;

//定义天气
u_int8_t air_temp=10;
u_int8_t air_humidity=56;
u_int16_t air_pressure=1000;
u_int8_t air_api=156;
u_int8_t air_rain=300;
u_int8_t air_cloud=400;


u_int32_t er_num;
u_int8_t sheep_num;
u_int8_t sheep_zong;

u_int8_t sheep_s1=0;
u_int8_t sheep_s2=0;
u_int8_t sheep_s3=0;
u_int8_t sheep_s4=0;
u_int8_t sheep_s5=0;
u_int8_t sheep_s6=0;
u_int8_t sheep_s7=0;
u_int8_t sheep_s8=0;
u_int8_t sheep_s9=0;
/* --------------------------WIFI--------------------------------------------
用idf.py menuconfig进入菜单配置
或者修改下述宏定义进而配置wifi ssid、密码
*/
#define EXAMPLE_ESP_WIFI_SSID      "CMCC-LtRb"
#define EXAMPLE_ESP_WIFI_PASS      "JtyLHLD3"
//#define EXAMPLE_ESP_MAXIMUM_RETRY  CONFIG_ESP_MAXIMUM_RETRY             //最大重试数
#define EXAMPLE_ESP_MAXIMUM_RETRY  100             //最大重试数

/*连接成功时，FreeRTOS事件组来传递信号*/
static EventGroupHandle_t s_wifi_event_group;

/* The event group allows multiple bits for each event, but we only care about two events:
 * - we are connected to the AP with an IP
 * - we failed to connect after the maximum amount of retries */
/*
事件组设有多个比特位来标志每个事件，但我们仅关心其中两个
1.连接到了AP且分配到了个ip
2.重连次数超过最大重试数，判定为连接失败
*/
#define WIFI_CONNECTED_BIT BIT0
#define WIFI_FAIL_BIT      BIT1

static const char *TAG = "wifi station";

static int s_retry_num = 0;                     //记录重连次数

static void event_handler(void* arg, esp_event_base_t event_base, int32_t event_id, void* event_data)   //事件处理函数                        
{
    if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_START) {         //如果是wifi事件相关&&事件id==wifi STA模式开始，开始连接WiFi
        esp_wifi_connect();
    } 
    else if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_DISCONNECTED) {   //如果是wifi事件相关&&事件id==wifi STA模式连接失败
        if (s_retry_num < EXAMPLE_ESP_MAXIMUM_RETRY) {                  //如果重连次数<预设的最大重连次数
            esp_wifi_connect();
            s_retry_num++;
            ESP_LOGI(TAG, "retry to connect to the AP");
        } else {                                                        
            xEventGroupSetBits(s_wifi_event_group, WIFI_FAIL_BIT);      //置位wifi事件组的失败标志位,表示连接失败
        }
        ESP_LOGI(TAG,"connect to the AP fail");
    } 
    else if (event_base == IP_EVENT && event_id == IP_EVENT_STA_GOT_IP) {       //如果是ip事件相关&&事件id==已取得ip
        ip_event_got_ip_t* event = (ip_event_got_ip_t*) event_data;
        ESP_LOGI(TAG, "got ip:" IPSTR, IP2STR(&event->ip_info.ip));             //串口打印ip
        s_retry_num = 0;
        xEventGroupSetBits(s_wifi_event_group, WIFI_CONNECTED_BIT);
    }
}

void wifi_init_sta(void)
{
    s_wifi_event_group = xEventGroupCreate();                   //初始化wifi事件组

    ESP_ERROR_CHECK(esp_netif_init());                          //检查

    ESP_ERROR_CHECK(esp_event_loop_create_default());
    esp_netif_create_default_wifi_sta();

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();        //配置wifi
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));

    esp_event_handler_instance_t instance_any_id;           //存id
    esp_event_handler_instance_t instance_got_ip;           //存ip
    ESP_ERROR_CHECK(esp_event_handler_instance_register(WIFI_EVENT,         //注册wifi事件
                                                        ESP_EVENT_ANY_ID,
                                                        &event_handler,
                                                        NULL,
                                                        &instance_any_id));
    ESP_ERROR_CHECK(esp_event_handler_instance_register(IP_EVENT,           //注册ip事件
                                                        IP_EVENT_STA_GOT_IP,
                                                        &event_handler,
                                                        NULL,
                                                        &instance_got_ip));

    wifi_config_t wifi_config = {               //wifi配置初始化
        .sta = {
            .ssid = EXAMPLE_ESP_WIFI_SSID,
            .password = EXAMPLE_ESP_WIFI_PASS,
            /* Setting a password implies station will connect to all security modes including WEP/WPA.
             * However these modes are deprecated and not advisable to be used. Incase your Access point
             * doesn't support WPA2, these mode can be enabled by commenting below line */
	     .threshold.authmode = WIFI_AUTH_WPA2_PSK,

            .pmf_cfg = {
                .capable = true,
                .required = false
            },
        },
    };
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA) );
    ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &wifi_config) );
    ESP_ERROR_CHECK(esp_wifi_start() );

    ESP_LOGI(TAG, "wifi_init_sta finished.");


    //等待，直到到连接建立，或者连接失败，事件标志bits被event_handler()置位
    EventBits_t bits = xEventGroupWaitBits(s_wifi_event_group,
            WIFI_CONNECTED_BIT | WIFI_FAIL_BIT,
            pdFALSE,
            pdFALSE,
            portMAX_DELAY);

    /* xEventGroupWaitBits()在回调发生之前就会返回Bits，所以我们可以用来测试事件是否真的发生了*/
    if (bits & WIFI_CONNECTED_BIT) {
        ESP_LOGI(TAG, "connected to ap SSID:%s password:%s",
                 EXAMPLE_ESP_WIFI_SSID, EXAMPLE_ESP_WIFI_PASS);
    } else if (bits & WIFI_FAIL_BIT) {
        ESP_LOGI(TAG, "Failed to connect to SSID:%s, password:%s",
                 EXAMPLE_ESP_WIFI_SSID, EXAMPLE_ESP_WIFI_PASS);
    } else {
        ESP_LOGE(TAG, "UNEXPECTED EVENT");
    }

    //事件注销后不会再被处理
    ESP_ERROR_CHECK(esp_event_handler_instance_unregister(IP_EVENT, IP_EVENT_STA_GOT_IP, instance_got_ip));
    ESP_ERROR_CHECK(esp_event_handler_instance_unregister(WIFI_EVENT, ESP_EVENT_ANY_ID, instance_any_id));
    vEventGroupDelete(s_wifi_event_group);
}


/* - --------------------------------------------------------------------*/
//                          MQTT_clinet
/* - --------------------------------------------------------------------*/
/*  --------------------------消息体格式---------------------
{
    "method" : "thing.service.property.set",
    "please" : 1,
    "ear_id" : "1664271450",
    "species" : 1,
    "sex" : 1,
    "weight" : 50,
    "sheep_age" : 12,
    "use_value" : 1,
    "place_of_production":2,
    "vaccine" : 3,
    "health" : 1,
    "time_now" :{
                    "year": 2023, 
                    "month": 1,
                    "day": 15,
                    "weekday":7
                },
    "illness_s" : {
                   "s1": 1,
                   "s2": 1,
                   "s3": 0,
                   "s4": 1,
                   "s5": 1,
                   "s6": 0,
                   "s7": 1,
                   "s8": 0,
                   "s9": 0
                  }
*/
char *send_message;
void send_message_hal(u_int8_t i)
{
    if(i==0) //mqtt--测试
    {
        cJSON *TCP = cJSON_CreateObject();				//创建一个对象
        cJSON_AddStringToObject(TCP,"method","MQTT--MESSAGE");		//添加字符串 
        cJSON_AddStringToObject(TCP,"ear_id","1664271450");		//添加字符串
        cJSON_AddNumberToObject(TCP,"species",1);	    	//添加整型数字 
        cJSON_AddNumberToObject(TCP,"sex",1);	    	//添加整型数字 
        cJSON_AddNumberToObject(TCP,"weight",183.52);	//添加浮点型数字
        cJSON_AddNumberToObject(TCP,"sheep_age",12);	    	//添加整型数字 
        cJSON_AddNumberToObject(TCP,"use_value",1);	    	//添加整型数字
        cJSON_AddNumberToObject(TCP,"place_of_production",2);	    	//添加整型数字
        cJSON_AddNumberToObject(TCP,"vaccine",3);	    	//添加整型数字
        cJSON_AddNumberToObject(TCP,"health",1);	    	//添加整型数字
        
        cJSON *ADD	= cJSON_CreateObject();				//创建一个对象
        cJSON_AddNumberToObject(ADD,"year",2023);	//添加整型数字
        cJSON_AddNumberToObject(ADD,"month",1);	//添加整型数字
        cJSON_AddNumberToObject(ADD,"day",15);	//添加整型数字
        cJSON_AddNumberToObject(ADD,"weekday",7);	//添加整型数字
        cJSON_AddItemToObject(TCP,"time_now",ADD);

        cJSON *ADD2	= cJSON_CreateObject();				//创建一个对象
        cJSON_AddNumberToObject(ADD2,"s1",0);	//添加整型数字
        cJSON_AddNumberToObject(ADD2,"s2",1);	//添加整型数字
        cJSON_AddNumberToObject(ADD2,"s3",1);	//添加整型数字
        cJSON_AddNumberToObject(ADD2,"s4",1);	//添加整型数字
        cJSON_AddNumberToObject(ADD2,"s5",0);	//添加整型数字
        cJSON_AddNumberToObject(ADD2,"s6",1);	//添加整型数字
        cJSON_AddNumberToObject(ADD2,"s7",1);	//添加整型数字
        cJSON_AddNumberToObject(ADD2,"s8",0);	//添加整型数字
        cJSON_AddNumberToObject(ADD2,"s9",0);	//添加整型数字
        cJSON_AddItemToObject(TCP,"illness_s",ADD2);

        send_message = cJSON_Print(TCP);	//JSON数据结构转换为JSON字符串
        cJSON_Delete(TCP);//清除结构体
        //cJSON_Delete(ADD);//清除结构体
        //cJSON_Delete(ADD2);//清除结构体

    }
    else if(i==1) //mqtt 时间请求 年月日星期
    {
       cJSON *TCP = cJSON_CreateObject();				//创建一个对象
       cJSON_AddNumberToObject(TCP,"please",1);	    	//添加整型数字 
       send_message = cJSON_Print(TCP);	//JSON数据结构转换为JSON字符串
       cJSON_Delete(TCP);//清除结构体
    }

    else if(i==2) //mqtt 天气请求 
    {
       cJSON *TCP = cJSON_CreateObject();				//创建一个对象
       cJSON_AddNumberToObject(TCP,"please",2);	    	//添加整型数字 
       send_message = cJSON_Print(TCP);	//JSON数据结构转换为JSON字符串
       cJSON_Delete(TCP);//清除结构体
    }
    else
    {
        send_message=" ";
    }   
}
// 事件处理函数
esp_mqtt_client_handle_t client_s_p_my;
static void mqtt_event_handler(void *handler_args, esp_event_base_t base, int32_t event_id, void *event_data) 
{
    //printf("Event dispatched from event loop base=%s, event_id=%d \n", base, event_id);
    // 获取MQTT客户端结构体指针
    esp_mqtt_event_handle_t event = event_data;
    esp_mqtt_client_handle_t client = event->client;
    client_s_p_my=client;
    // 通过事件ID来分别处理对应的事件
    switch (event->event_id) 
    {
        // 建立连接成功
        case MQTT_EVENT_CONNECTED:
            printf("MQTT_client cnnnect to EMQ ok. \n");          
            //esp_mqtt_client_publish(client, "domoticz/out", "I am ESP32.", 0, 1, 0);
            esp_mqtt_client_publish(client, "domoticz/esp32", send_message, 0, 1, 0);
            // 订阅主题，qos=0
            esp_mqtt_client_subscribe(client, "domoticz/server", 0);           
            break;
        // 客户端断开连接
        case MQTT_EVENT_DISCONNECTED:
            printf("MQTT_client have disconnected. \n");
            break;
        // 主题订阅成功
        case MQTT_EVENT_SUBSCRIBED:
            printf("mqtt subscribe ok. msg_id = %d \n",event->msg_id);
            break;
        // 取消订阅
        case MQTT_EVENT_UNSUBSCRIBED:
            printf("mqtt unsubscribe ok. msg_id = %d \n",event->msg_id);
            break;
        //  主题发布成功
        case MQTT_EVENT_PUBLISHED:
            printf("mqtt published ok. msg_id = %d \n",event->msg_id);
            break;
        // 已收到订阅的主题消息
        case MQTT_EVENT_DATA:
            printf("mqtt received topic: %.*s \n",event->topic_len, event->topic);
            printf("topic data: %.*s\r\n", event->data_len, event->data);
            cJSON *root = cJSON_Parse(event->data);
            //cJSON *root_time=NULL;
            if (!root) {
                printf("JSON format error:%s \r\n", cJSON_GetErrorPtr());
            } 
            else {
                int please = cJSON_GetObjectItem(root, "please")->valueint; 

                if(please==1)
                {
                    time_year = cJSON_GetObjectItem(root, "year")->valueint;
                    time_month = cJSON_GetObjectItem(root, "month")->valueint;
                    time_day = cJSON_GetObjectItem(root, "day")->valueint;
                    int weekday_i = cJSON_GetObjectItem(root, "weekday")->valueint;

                    printf("y-m-d-w: %d %d %d %d",time_year,time_month,time_day,weekday_i);
                    //#星期一：Mon.；星期二：Tue.；星期三：Wed.；星期四：Thur.；星期五：Fri.；星期六：Sat.；星期天：Sun.
                    if(weekday_i==1)  time_weekend="Mon"; 
                    else if(weekday_i==2)  time_weekend="Tue";
                    else if(weekday_i==3)  time_weekend="Wed";
                    else if(weekday_i==4)  time_weekend="Thur";
                    else if(weekday_i==5)  time_weekend="Fri";
                    else if(weekday_i==6)  time_weekend="Sat";
                    else  time_weekend="Sun";
                }
                if(please==2)
                {
                    air_temp = cJSON_GetObjectItem(root, "air_temp")->valueint;
                    air_humidity = cJSON_GetObjectItem(root, "air_humidity")->valueint;
                    air_pressure = cJSON_GetObjectItem(root, "air_pressure")->valueint;
                    air_api = cJSON_GetObjectItem(root, "air_api")->valueint;
                    air_rain = cJSON_GetObjectItem(root, "air_rain")->valueint;
                    air_cloud = cJSON_GetObjectItem(root, "air_cloud")->valueint;  
                                 
                }
                //int32_t sex_i = cJSON_GetObjectItem(root, "sex")->valueint;                         
                cJSON_Delete(root); 
            }
            break;
        // 客户端遇到错误
        case MQTT_EVENT_ERROR:
            printf("MQTT_EVENT_ERROR \n");
            break;
        default:
            printf("Other event id:%d \n", event->event_id);
            break;
    }
}

esp_mqtt_client_handle_t client;
void mqtt_app_start(void)
{
    // 1、定义一个MQTT客户端配置结构体，输入MQTT的url
    esp_mqtt_client_config_t mqtt_cfg = {
        .uri = "mqtt://47.92.23.144",// ip地址
        .username = "ESP32",
        .port = 1883
        //.alpn_protos,
        // .use_secure_element
    };

    // 2、通过esp_mqtt_client_init获取一个MQTT客户端结构体指针，参数是MQTT客户端配置结构体
    //esp_mqtt_client_handle_t client = esp_mqtt_client_init(&mqtt_cfg);
    client = esp_mqtt_client_init(&mqtt_cfg);

    // 3、注册MQTT事件

    esp_mqtt_client_register_event(client, ESP_EVENT_ANY_ID, mqtt_event_handler, client);

    // 4、开启MQTT功能
    esp_mqtt_client_start(client);
}


#define N 30      //耳标上限
struct stu_info{
    u_int8_t statu;
    u_int32_t ear_id;
    char *species;
    char *sex;
    char *weight;
    char *sheep_age;
    char *use_value;
    char *place_of_production;
    char *vaccine;
    char *health;

    //u_int16_t time_year;
    //u_int8_t time_month;
    //u_int8_t time_day;
    //u_int8_t time_weekend;    
    u_int8_t s1,s2,s3,s4,s5,s6,s7,s8,s9;
    u_int16_t sheep_year;
    u_int8_t sheep_month;
    u_int8_t sheep_day;
}stu[N];

void stu_date_init(void)
{   
    stu[0].statu=1;
    stu[0].ear_id=1913001;
    stu[0].species="绵羊";
    stu[0].sex ="公羊";
    stu[0].weight ="70";
    stu[0].sheep_age="24";
    stu[0].use_value ="肉羊";
    stu[0].place_of_production ="EXUI基地";
    stu[0].vaccine ="3";
    stu[0].health ="健康";
    stu[0].sheep_year=2020;
    stu[0].sheep_month=12;
    stu[0].sheep_day = 12;

    stu[1].statu=1;
    stu[1].ear_id=1913002;
    stu[1].species="岩羊";
    stu[1].sex ="母羊";
    stu[1].weight ="72";
    stu[1].sheep_age="26";
    stu[1].use_value ="肉羊";
    stu[1].place_of_production ="EXUI养殖基地";
    stu[1].vaccine ="1";
    stu[1].health ="健康";
    stu[1].sheep_year=2023;
    stu[1].sheep_month=10;
    stu[1].sheep_day = 12;

    stu[2].statu=1;
    stu[2].ear_id=1913003;
    stu[2].species="绵羊";
    stu[2].sex ="公羊";
    stu[2].weight ="70";
    stu[2].sheep_age="24";
    stu[2].use_value ="肉羊";
    stu[2].place_of_production ="FXUI养殖场";
    stu[2].vaccine ="3";
    stu[2].health ="健康";
    stu[2].sheep_year=2021;
    stu[2].sheep_month=12;
    stu[2].sheep_day = 24;

    stu[3].statu=1;
    stu[3].ear_id=1913004;
    stu[3].species="羚羊";
    stu[3].sex ="公羊";
    stu[3].weight ="56";
    stu[3].sheep_age="20";
    stu[3].use_value ="产毛羊";
    stu[3].place_of_production ="EI绵羊基地";
    stu[3].vaccine ="2";
    stu[3].health ="健康";
    stu[3].sheep_year=2020;
    stu[3].sheep_month=9;
    stu[3].sheep_day = 12;

    sheep_num=4;
    sheep_zong=4;
    
    u_int8_t in_i;
    for(in_i=4;in_i<20;in_i++)
    {
        stu[in_i].statu=0;
        stu[in_i].ear_id=0;
        stu[in_i].species="error";
        stu[in_i].sex ="error";
        stu[in_i].weight ="0";
        stu[in_i].sheep_age="0";
        stu[in_i].use_value ="error";
        stu[in_i].place_of_production ="error";
        stu[in_i].vaccine ="error";
        stu[in_i].health ="error"; 
        stu[in_i].sheep_year=0;
        stu[in_i].sheep_month=0;
        stu[in_i].sheep_day = 0;  
    }
}
void stu_sheep_init(u_int8_t i)
{
    gui_id=stu[i].ear_id;
    gui_species=stu[i].species;
    gui_sex=stu[i].sex;
    gui_weight=stu[i].weight;
    gui_sheep_age=stu[i].sheep_age;

    printf("gui_weight %s\n",gui_weight);
    printf("gui_sheep_age %s\n",gui_sheep_age);
    gui_use_value=stu[i].use_value;
    gui_place_of_production=stu[i].place_of_production;
    gui_vaccine=stu[i].vaccine;
    gui_health=stu[i].health;

    sheep_s1 = stu[i].s1;
    sheep_s2 = stu[i].s2;
    sheep_s3 = stu[i].s3;
    sheep_s4 = stu[i].s4;
    sheep_s5 = stu[i].s5;
    sheep_s6 = stu[i].s6;
    sheep_s7 = stu[i].s7;
    sheep_s8 = stu[i].s8;
    sheep_s9 = stu[i].s9;

    tr_time_year=stu[i].sheep_year;
    tr_time_month=stu[i].sheep_month;
    tr_time_day=stu[i].sheep_day;

}

/*
u_int8_t stu_id_find(u_int32_t n)  //按 值 查 找
{
    for(u_int8_t i=0; i<sheep_num;i++)
    {
        if(stu[i].ear_id==n && stu[i].statu==1)
          return i;
    }
}
*/

/*
void stu_Registration(void)  // 注册
{
    stu[sheep_num].statu=1;
    stu[sheep_num].ear_id=ear_id_n;
    stu[sheep_num].species=gui_species;
    stu[sheep_num].sex =gui_sex;
    stu[sheep_num].weight =gui_weight;
    stu[sheep_num].sheep_age=gui_sheep_age;
    stu[sheep_num].use_value ="食用羊";
    stu[sheep_num].place_of_production ="EI绵羊基地";
    stu[sheep_num].vaccine ="0";
    stu[sheep_num].health ="健康";
    sheep_num++;
    sheep_zong++;
    zhuce=0;
}*/

u_int8_t stu_Registration(u_int32_t n)  // 注册
{

    u_int8_t i;
    for(i=0; i<sheep_num;i++)
    {
        if(stu[i].ear_id==n && stu[i].statu==1)
        {
            printf("Registration is error !\n");
            return 0;
        }

    }

    stu[sheep_num].statu=1;
    stu[sheep_num].ear_id=n;
    stu[sheep_num].species=gui_species;
    stu[sheep_num].sex =gui_sex;
    stu[sheep_num].weight =gui_weight;
    stu[sheep_num].sheep_age=gui_sheep_age;
    printf("stu[sheep_num].weight is : %s\n",stu[sheep_num].weight);
    printf("stu[sheep_num].sheep_age is : %s\n",stu[sheep_num].sheep_age);
    stu[sheep_num].use_value ="食用羊";
    stu[sheep_num].place_of_production ="EI绵羊基地";
    stu[sheep_num].vaccine ="0";
    stu[sheep_num].health ="健康";

    stu[sheep_num].sheep_year=time_year;
    stu[sheep_num].sheep_month=time_month;
    stu[sheep_num].sheep_day = time_day;

    sheep_num++;
    sheep_zong++;
    printf("Registration is ok .\n");
    return 1;

}

u_int8_t stu_delete_ear(u_int32_t n) //按值删除 
{
    u_int8_t i;
    for(i=0; i<sheep_num;i++)
    {
        if(stu[i].ear_id==n && stu[i].statu==1)
        {
            stu[i].statu=0;
            stu[i].ear_id=0;
            stu[i].species="error";
            stu[i].sex ="error";
            stu[i].weight ="error";
            stu[i].sheep_age="error";
            stu[i].use_value ="error";
            stu[i].place_of_production ="error";
            stu[i].vaccine ="error";
            stu[i].health ="error";

            stu[i].s1 = 0;
            stu[i].s2 = 0;
            stu[i].s3 = 0;
            stu[i].s4 = 0;
            stu[i].s5 = 0;
            stu[i].s6 = 0;
            stu[i].s7 = 0;
            stu[i].s8 = 0;
            stu[i].s9 = 0;

            stu[i].sheep_year=0;
            stu[i].sheep_month=0;
            stu[i].sheep_day = 0;
            sheep_zong--;
            printf("date delete is ok\n");
            return i;
            break;
        }          
    }
    return 0;
}


void yi_miao_Registration(u_int32_t n)  //疫苗信息录入
{
    u_int8_t i;
    for(i=0; i<=sheep_num;i++)
    {
        if(stu[i].ear_id==n && stu[i].statu==1)
        {
            stu[i].s1 = sheep_s1;
            stu[i].s2 = sheep_s2;
            stu[i].s3 = sheep_s3;
            stu[i].s4 = sheep_s4;
            stu[i].s5 = sheep_s5;
            stu[i].s6 = sheep_s6;
            stu[i].s7 = sheep_s7;
            stu[i].s8 = sheep_s8;
            stu[i].s9 = sheep_s9;
            printf("yi_miao_Registration is ok ok ok\n");
            break;
        }
          
    }
/*     sheep_s1=0;
    sheep_s2=0;
    sheep_s3=0;
    sheep_s4=0;
    sheep_s5=0;
    sheep_s6=0;
    sheep_s7=0;
    sheep_s8=0;
    sheep_s9=0; */
}

u_int8_t Find_stu(u_int32_t n)  //按照值 赋值
{
    u_int8_t i;
    for(i=0; i<=sheep_num;i++)
    {
        if(stu[i].ear_id==n && stu[i].statu==1)
        {
            gui_id=stu[i].ear_id;
            gui_species=stu[i].species;
            gui_sex=stu[i].sex;
            gui_weight=stu[i].weight;
            gui_sheep_age=stu[i].sheep_age;
            gui_use_value=stu[i].use_value;
            
            printf("Find stu[i].weight %s\n",stu[i].weight);
            printf("stu[i].sheep_age %s\n",stu[i].sheep_age);
            printf("Find gui_weight %s\n",gui_weight);
            printf("Find gui_sheep_age %s\n",gui_sheep_age);

            gui_place_of_production=stu[i].place_of_production;
            gui_vaccine=stu[i].vaccine;
            gui_health=stu[i].health;

            sheep_s1=stu[i].s1;
            sheep_s2=stu[i].s2;
            sheep_s3=stu[i].s3;
            sheep_s4=stu[i].s4;
            sheep_s5=stu[i].s5;
            sheep_s6=stu[i].s6;
            sheep_s7=stu[i].s7;
            sheep_s8=stu[i].s8;
            sheep_s9=stu[i].s9; 

            tr_time_year=stu[i].sheep_year;
            tr_time_month=stu[i].sheep_month;
            tr_time_day=stu[i].sheep_day;
            printf("Find trace is ok \n");
            return 1;          
        }
          
    }

    gui_id=n;
    gui_species="error";
    gui_sex="error";
    gui_weight="error";
    gui_sheep_age="error";
    gui_use_value="error";
    gui_place_of_production="error";
    gui_vaccine="error";
    gui_health="error";

    sheep_s1=0;
    sheep_s2=0;
    sheep_s3=0;
    sheep_s4=0;
    sheep_s5=0;
    sheep_s6=0;
    sheep_s7=0;
    sheep_s8=0;
    sheep_s9=0;

    printf("Find trace is error \n");
    return 0; 

}

void app_main(void)
{
       //Initialize NVS
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
      ESP_ERROR_CHECK(nvs_flash_erase());
      ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);
    ESP_LOGI(TAG, "ESP_WIFI_MODE_STA");

    stu_date_init();   //数据初始化
    stu_sheep_init(0); //赋值
    send_message_hal(1);  // *send_message 赋值
    
    wifi_init_sta();   // WIFI 连接
    mqtt_app_start();  // mqtt 连接
    
    NFC_Init();  // RC522初始化.

    esp_mqtt_client_publish(client, "domoticz/esp32", send_message, 0, 1, 0);

    //vTaskDelay(1000 / portTICK_PERIOD_MS);
    vTaskDelay(200 / portTICK_PERIOD_MS);
    send_message_hal(2);
    esp_mqtt_client_publish(client, "domoticz/esp32", send_message, 0, 1, 0);

    xTaskCreatePinnedToCore(guiTask1, "gui", 4096*2, NULL, 1, NULL, 1);
    // 复位引脚
    gpio_reset_pin(BLINK_GPIO);
    gpio_reset_pin(FengMing_GPIO);

    //gpio_pad_select_gpio(FengMing_GPIO);
    /* Set the GPIO as a push/pull output */
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
    gpio_set_direction(FengMing_GPIO, GPIO_MODE_OUTPUT);

    gpio_set_level(FengMing_GPIO, 1);
    vTaskDelay(300 / portTICK_PERIOD_MS);
    gpio_set_level(FengMing_GPIO, 0);
    while(1) {
        
        if(zhuce==1)   // 注册    触发条件  按下注册页面的 “确认”键
        {
           zhuce = 0;
           stu_Registration(ear_id_n);
           stu_sheep_init(sheep_num-1); //赋值
           vTaskDelay(1000 / portTICK_PERIOD_MS);
           printf("stu_Registration:...\n");

        }

        if(xiaoka==1)  //销卡  触发条件 ：销卡按键按下
        {
            xiaoka=0;
            //stu_delete_ear(ear_id_n);
            stu_sheep_init(stu_delete_ear(ear_id_n));
            vTaskDelay(1000 / portTICK_PERIOD_MS);
            printf("ready delate stu_delete_ear: %d \n",ear_id_n);
        }
        if(yi_miao==1)  //疫苗zhuce
        {
            yi_miao=0;
            yi_miao_Registration(ear_id_n);
            vTaskDelay(1000 / portTICK_PERIOD_MS);
            printf("yi_miao_Registration: ...\n");
        }

        if(main_trace == 1)  // 入口按键
        {
            main_trace =0;
            vTaskDelay(1000 / portTICK_PERIOD_MS);
            Find_stu(ear_id_n);
            
            vTaskDelay(1000 / portTICK_PERIOD_MS);
        }
        
        if(ear_trace == 1)  // 追溯页面刷新了  入口 “刷卡”按钮
        {
            ear_trace=0;
            //Find_stu(ear_id_n);
            //赋值 用于显示
        }

        
        MFRC522_ReadCardSerialNo(card);  // RFID 读卡
        if(card[0]!=0 ||card[1]!=0 || card[2]!=0 ||card[3]!=0)
        {
            
            ear_id_n=1913000+card[0]*100+card[1]*10+card[2];
            //char str[20];
            //memset(str, 0, sizeof(str));  //清空数组
            //sprintf(str, "%d%d%d%d",card[0], card[1], card[2], card[3]); //拼接       
            printf("card: %d %d %d %d\n",card[0], card[1], card[2], card[3]);
            //printf("str: %s\n", str);
            //pr_t=&str;
        } 
        //ESP_LOGI(TAG, "card: %02x%02x%02x%02x", card[0], card[1], card[2], card[3]);
        



        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
