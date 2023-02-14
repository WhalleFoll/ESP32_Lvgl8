import random
from paho.mqtt import client as mqtt_client
import json
import datetime
import time
import requests
import csv
''' official website  https://www.qweather.com '''
'''      dev website  https://dev.qweather.com'''
KEY = '你自己的密钥'
mykey = '&key=' + KEY # EDIT HERE!

url_api_weather = 'https://devapi.qweather.com/v7/weather/'
url_api_geo = 'https://geoapi.qweather.com/v2/city/'
url_api_rain = 'https://devapi.qweather.com/v7/minutely/5m'
url_api_air = 'https://devapi.qweather.com/v7/air/now'

def get(api_type):
    url = url_api_weather + api_type + '?location=' + '101180501' + mykey
    return requests.get(url).json()

def rain(lat, lon):
    url = url_api_rain  + '?location=' + lat + ',' + lon + mykey
    return requests.get(url).json()

def air(city_id):
    url = url_api_air + '?location=' + city_id + mykey
    return requests.get(url).json()

def get_city(city_kw):
    url_v2 = url_api_geo + 'lookup?location=' + city_kw + mykey
    city = requests.get(url_v2).json()['location'][0]

    city_id = city['id']
    district_name = city['name']
    city_name = city['adm2']
    province_name = city['adm1']
    country_name = city['country']
    lat = city['lat']
    lon = city['lon']

    return city_id, district_name, city_name, province_name, country_name, lat, lon

def now():
    return get_now['now']

def daily():
    return get_daily['daily']

def hourly():
    return get_hourly['hourly']



# AP 气压  WS 风速 ,WD 风向

now_time = datetime.date.today()

print(now_time)
# print(now_time.year)
# print(now_time.month)
# print(now_time.day)
# print(now_time.weekday()+1)
n_year=now_time.year
n_month=now_time.month
n_day=now_time.day
n_weekend=now_time.weekday()+1
#星期一：Mon.；星期二：Tue.；星期三：Wed.；星期四：Thur.；星期五：Fri.；星期六：Sat.；星期天：Sun.

# port = 1883
topic = "domoticz/esp32"
# generate client ID with pub prefix randomly
client_id = f'python-mqtt-{random.randint(0, 100)}'


def connect_mqtt() -> mqtt_client:
    def on_connect(client, userdata, flags, rc):
        if rc == 0:
            print("Connected to MQTT Broker!")
        else:
            print("Failed to connect, return code %d\n", rc)

    client = mqtt_client.Client(client_id)
    client.on_connect = on_connect
    client.connect(host='47.92.23.144', port=1883)
    return client


def subscribe(client: mqtt_client):
    def on_message(client, userdata, msg):
        print(f"topic :{msg.payload.decode()} topic from :{msg.topic}")
        msss=msg.payload.decode()
        msgjson = json.loads(msss)
        if msgjson['please'] == 1:
            print("时间请求：")
            now_time = datetime.date.today()
            month = now_time.month
            day = now_time.day
            weekend = now_time.weekday() + 1
            msg = {
                "please": 1,
                "year": 2023,
                "month": month,
                "day": day,
                "weekday": weekend,
            }
            msg = json.dumps(msg)
            result =  client.publish("domoticz/server", msg)
            # result: [0, 1]
            status = result[0]
            if status == 0:
                print(f"Time Send is ok")
            else:
                print(f"Time Failed to send")

        elif msgjson['please'] == 2:      # 天气状态请求
            print("Mqtt-天气数据请求：....")
            # city_input = input()
            city_input = '平顶山'
            city_idname = get_city(city_input)
            city_id = '101180501'
            get_now = get('now')
            get_rain = rain(city_idname[5], city_idname[6])  # input longitude & latitude
            air_now = air(city_id)['now']

            # print(json.dumps(get_now, sort_keys=True, indent=4))
            if city_idname[2] == city_idname[1]:
                print(city_idname[3], str(city_idname[2]) + '市')
            else:
                print(city_idname[3], str(city_idname[2]) + '市', str(city_idname[1]) + '区')

            #print(get_now)  #天气详细参数
            air_temp = get_now['now']['temp']
            air_humidity  = get_now['now']['humidity']
            air_pressure =get_now['now']['pressure']
            air_cloud =get_now['now']['cloud']
            air_api = air_now['aqi']
            air_rain =get_rain['code']

            air_temp=int(air_temp)
            air_humidity=int(air_humidity)
            air_pressure=int(air_pressure)
            air_cloud=int(air_cloud)
            air_api=int(air_api)
            air_rain=int(air_rain)


            #air_temp_1 =daily()[0]['tempMin']
            #daily_r=get_daily['daily']
            # air_temp_1 = daily_r[0]['tempMin']
            # air_temp_2 = daily_r[0]['tempMax']

            print('当前天气：', get_now['now']['text'], air_temp, '°C', '体感温度', get_now['now']['feelsLike'],
                  '°C','湿度：',air_humidity,'气压：',air_pressure)
            print('空气质量指数：', air_api)
            print('降水情况：', air_rain)
            print('云层情况：', air_cloud)



            msg = {
                "please": 2,
                "air_city": "city",
                "air_temp": air_temp,
                "air_humidity": air_humidity,
                "air_pressure": air_pressure,
                "air_api": air_api,
                "air_rain": air_rain,
                "air_cloud": air_cloud

            }
            msg = json.dumps(msg)
            result =  client.publish("domoticz/server", msg)
            # result: [0, 1]
            status = result[0]
            if status == 0:
                print(f"The weather date Send is ok")
            else:
                print(f"The weather date Failed to send")
        elif msgjson['please'] == 3:
            print('数据库数据请求...')
            if 'id' in msgjson:
                print(msgjson['id'])


            print(msgjson['sex'])
        elif msgjson['please'] == 4:
            print('数据库连接测试...')





    client.subscribe(topic)
    client.on_message = on_message



def publish_sss(client, SendTopic):
    # 发送信息到mqtt服务器
    i = 1
    while i <= 2:
        time.sleep(1)
        msg = {
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
                  "year" :2023,
                  "month": n_month,
                  "day": n_day,
                  "weekday": n_weekend,
                  "time_now" :{
                      "times":{"year": n_year, "month": n_month,"day": n_day,"weekday":n_weekend}
                   },
                  "illness_s" : {
                    "sheep_ill": {"s1": 1, "s2": 1,"s3": 0, "s4": 1, "s5": 1,"s6": 0,"s7": 1, "s8": 0,"s9": 0}
                   }
             }
        msg = json.dumps(msg)
        result = client.publish(SendTopic, msg)
        # result: [0, 1]
        status = result[0]
        if status == 0:
            print(f"Send is ok")
        else:
            print(f"Failed to send")

        i += 1
        time.sleep(2)



data = {
    "timestamp": "20211101T12351",
    "int_g":1,
    "status": "OK"
}


def run():
    client = connect_mqtt()
    subscribe(client)
    publish_sss(client,"domoticz/server")
    #publish_my(client)
    client.loop_forever()


if __name__ == '__main__':
    run()

