#include "lvgl_init.h"
#include "lvgl/examples/lv_examples.h"


#include "gui_guider.h"
#include "events_init.h"
#include "custom.h" 
/**********************
 *  STATIC PROTOTYPES
 **********************/

void lv_tick_task(void *arg)
{
    lv_tick_inc(LV_TICK_PERIOD_MS);
}
/* Creates a semaphore to handle concurrent call to lvgl stuff
 * If you wish to call *any* lvgl function from other threads/tasks
 * you should lock on the very same semaphore! */
SemaphoreHandle_t xGuiSemaphore;

/*********************** GUI_SHOW_CODE_START***********************/
lv_obj_t * label_1;
lv_obj_t * label_2;


/////////////////
static void btn_event_callback(lv_event_t* event)
{
    static uint32_t counter = 1;
 
    lv_obj_t* btn = lv_event_get_target(event); //获取事件对象
    if (btn != NULL)
    {
        lv_obj_t* label = lv_obj_get_child(btn, 0); // 获取第一个子对象
        if (label != NULL)
        {
            lv_label_set_text_fmt(label, "%d", counter); //设置显示内容
            counter++;
        }
    }
}
 
 
void lv_button_click_event_test()
{
    lv_obj_t* btn = lv_btn_create(lv_scr_act()); // 创建Button对象
    if (btn != NULL)
    {
        lv_obj_set_size(btn, 100, 50); // 设置对象大小,宽度和高度
        lv_obj_set_pos(btn, 300, 200);; // 设置按钮位置，即X和Y坐标
        lv_obj_add_event_cb(btn, btn_event_callback, LV_EVENT_CLICKED, NULL); // 给对象添加CLICK事件和事件处理回调函数
 
        lv_obj_t* label = lv_label_create(btn); // 基于Button对象创建Label对象
        if (label != NULL)
        {
            lv_label_set_text(label, "Click me!"); // 设置显示内容
            lv_obj_center(label); // 对象居中显示
        }
    }
}
/////////////////
/*
*/


static void event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);
    if(code == LV_EVENT_VALUE_CHANGED) {
        char buf[32];
        lv_dropdown_get_selected_str(obj, buf, sizeof(buf));
        LV_LOG_USER("Option: %s", buf);
    }
}

void lv_example_dropdown_1(void)
{

    /*Create a normal drop down list*/
    lv_obj_t * dd = lv_dropdown_create(lv_scr_act());
    lv_dropdown_set_options(dd, "Apple\n"
                                "Banana\n"
                                "Orange\n"
                                "Cherry\n"
                                "Grape\n"
                                "Raspberry\n"
                                "Melon\n"
                                "Orange\n"
                                "Lemon\n"
                                "Nuts");

    lv_obj_align(dd, LV_ALIGN_TOP_MID, 0, 20);
    lv_obj_add_event_cb(dd, event_handler, LV_EVENT_ALL, NULL);
}



void Show_State()
{
    lv_obj_t *scr = lv_scr_act(); //创建scr
    lv_obj_set_pos(scr,0,0);
    lv_scr_load(scr);

    label_1 =lv_label_create(scr);//创建label
    lv_label_set_recolor(label_1,1);//颜色可变换
    lv_label_set_long_mode(label_1,LV_LABEL_LONG_SCROLL_CIRCULAR);//设置滚动模式
    lv_obj_set_pos(label_1,10,10);//设置位置
    lv_obj_set_size(label_1,160,30);//设定大小
    lv_label_set_text(label_1, "This is a GUI thread yes");//设定文本内容


    label_2 =lv_label_create(scr);//创建label
    lv_label_set_recolor(label_2,1);//颜色可变换
    lv_label_set_long_mode(label_2,LV_LABEL_LONG_SCROLL_CIRCULAR);//设置滚动模式
    lv_obj_set_pos(label_2,10,40);//设置位置
    lv_obj_set_size(label_2,160,40);//设定大小
    lv_label_set_text(label_2, "This is the Intetnet thread");//设定文本内容

}
/*********************** GUI_SHOW_CODE_END***********************/

/* gui guider*/
lv_ui guider_ui;

void guiTask1(void *pvParameter) 
{

    (void) pvParameter;
    xGuiSemaphore = xSemaphoreCreateMutex();

    lv_init();
    /* Initialize SPI or I2C bus used by the drivers */
    lvgl_driver_init();

    lv_color_t* buf1 = heap_caps_malloc(DISP_BUF_SIZE * sizeof(lv_color_t), MALLOC_CAP_DMA);
   // memset(buf1,0x00ff,DISP_BUF_SIZE * sizeof(lv_color_t));
    assert(buf1 != NULL);

    /* Use double buffered when not working with monochrome displays */
#ifndef CONFIG_LV_TFT_DISPLAY_MONOCHROME
    lv_color_t* buf2 = heap_caps_malloc(DISP_BUF_SIZE * sizeof(lv_color_t), MALLOC_CAP_DMA);
    //memset(buf2,0x00ff,DISP_BUF_SIZE * sizeof(lv_color_t));
    assert(buf2 != NULL);
#else
    static lv_color_t *buf2 = NULL;
#endif

    static lv_disp_draw_buf_t disp_buf;

    uint32_t size_in_px = DISP_BUF_SIZE;

#if defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_IL3820         \
    || defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_JD79653A    \
    || defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_UC8151D     \
    || defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_SSD1306

    /* Actual size in pixels, not bytes. */
    size_in_px *= 8;
#endif

    /* Initialize the working buffer depending on the selected display.
     * NOTE: buf2 == NULL when using monochrome displays. */
    lv_disp_draw_buf_init(&disp_buf, buf1, buf2, size_in_px);

    lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res=LV_HOR_RES_MAX;
    disp_drv.ver_res=LV_VER_RES_MAX;
    disp_drv.flush_cb = disp_driver_flush;
    disp_drv.draw_buf = &disp_buf;
    lv_disp_drv_register(&disp_drv);
    /* Register an input device when enabled on the menuconfig */
#if CONFIG_LV_TOUCH_CONTROLLER != TOUCH_CONTROLLER_NONE
    lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.read_cb = touch_driver_read;
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    lv_indev_drv_register(&indev_drv);
#endif

    /* Create and start a periodic timer interrupt to call lv_tick_inc */
    const esp_timer_create_args_t periodic_timer_args = {
        .callback = &lv_tick_task,
        .name = "periodic_gui"
    };
    esp_timer_handle_t periodic_timer;
    ESP_ERROR_CHECK(esp_timer_create(&periodic_timer_args, &periodic_timer));
    ESP_ERROR_CHECK(esp_timer_start_periodic(periodic_timer, LV_TICK_PERIOD_MS * 1000));

    //Show_State();
    //lv_example_get_started_1();
    //lv_button_click_event_test();
    //lv_example_dropdown_1();

    setup_ui(&guider_ui);
    events_init(&guider_ui);
    custom_init(&guider_ui); 
    while (1) {
        /* Delay 1 tick (assumes FreeRTOS tick is 10ms */
        vTaskDelay(pdMS_TO_TICKS(10));

        /* Try to take the semaphore, call lvgl related function on success */
        if (pdTRUE == xSemaphoreTake(xGuiSemaphore, portMAX_DELAY)) {
            lv_task_handler();
            xSemaphoreGive(xGuiSemaphore);
       }
    }
    /* A task should NEVER return */
    free(buf1);
#ifndef CONFIG_LV_TFT_DISPLAY_MONOCHROME
    free(buf2);
#endif
    vTaskDelete(NULL);
}