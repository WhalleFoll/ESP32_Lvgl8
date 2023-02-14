/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"

extern u_int32_t ear_id_n;


extern u_int8_t sheep_s1;
extern u_int8_t sheep_s2;
extern u_int8_t sheep_s3;
extern u_int8_t sheep_s4;
extern u_int8_t sheep_s5;
extern u_int8_t sheep_s6;
extern u_int8_t sheep_s7;
extern u_int8_t sheep_s8;
extern u_int8_t sheep_s9;



static void checkbox_event_hander_1(lv_event_t * e) // 性别0 品种1 用途2
{
   lv_event_code_t code = lv_event_get_code(e);
   lv_obj_t * obj = lv_event_get_target(e);
   if(code == LV_EVENT_VALUE_CHANGED){
      const char * txt = lv_checkbox_get_text(obj);
      //const char * state = lv_obj_get_state(obj) & LV_STATE_CHECKED ? "Ckecked" : "Unckeck";
	  int state = lv_obj_get_state(obj) & LV_STATE_CHECKED ? 0: 1;
	  if(state)  
	  {
		//printf("s1 is no\n");
        sheep_s1=0;
	  }
	  else    //选中
	  {
        //printf("si is yes \n");
		sheep_s1=1;
	  }
   }
}

static void checkbox_event_hander_2(lv_event_t * e) // 性别0 品种1 用途2
{
   lv_event_code_t code = lv_event_get_code(e);
   lv_obj_t * obj = lv_event_get_target(e);
   if(code == LV_EVENT_VALUE_CHANGED){
      const char * txt = lv_checkbox_get_text(obj);
      //const char * state = lv_obj_get_state(obj) & LV_STATE_CHECKED ? "Ckecked" : "Unckeck";
	  int state = lv_obj_get_state(obj) & LV_STATE_CHECKED ? 0: 1;
	  if(state)  
	  {
		//printf("s1 is no\n");
        sheep_s2=0;
	  }
	  else    //选中
	  {
        //printf("si is yes \n");
		sheep_s2=1;
		
	  }
   }
}

static void checkbox_event_hander_3(lv_event_t * e) // 性别0 品种1 用途2
{
/*    sheep_s1=0;
   sheep_s2=0;
   sheep_s3=0;
   sheep_s4=0;
   sheep_s5=0;
   sheep_s6=0;
   sheep_s7=0;
   sheep_s8=0;
   sheep_s9=0;  */

   lv_event_code_t code = lv_event_get_code(e);
   lv_obj_t * obj = lv_event_get_target(e);
   if(code == LV_EVENT_VALUE_CHANGED){
      const char * txt = lv_checkbox_get_text(obj);
      //const char * state = lv_obj_get_state(obj) & LV_STATE_CHECKED ? "Ckecked" : "Unckeck";
	  int state = lv_obj_get_state(obj) & LV_STATE_CHECKED ? 0: 1;
	  if(state)  
	  {
		//printf("s1 is no\n");
        sheep_s3=0;
	  }
	  else    //选中
	  {
        //printf("si is yes \n");
		sheep_s3=1;
	  }
   }
}

static void checkbox_event_hander_4(lv_event_t * e) // 性别0 品种1 用途2
{
   lv_event_code_t code = lv_event_get_code(e);
   lv_obj_t * obj = lv_event_get_target(e);
   if(code == LV_EVENT_VALUE_CHANGED){
      const char * txt = lv_checkbox_get_text(obj);
      //const char * state = lv_obj_get_state(obj) & LV_STATE_CHECKED ? "Ckecked" : "Unckeck";
	  int state = lv_obj_get_state(obj) & LV_STATE_CHECKED ? 0: 1;
	  if(state)  
	  {
		//printf("s1 is no\n");
        sheep_s4=0;
	  }
	  else    //选中
	  {
        //printf("si is yes \n");
		sheep_s4=1;
	  }
   }
}

static void checkbox_event_hander_5(lv_event_t * e) // 性别0 品种1 用途2
{
   lv_event_code_t code = lv_event_get_code(e);
   lv_obj_t * obj = lv_event_get_target(e);
   if(code == LV_EVENT_VALUE_CHANGED){
      const char * txt = lv_checkbox_get_text(obj);
      //const char * state = lv_obj_get_state(obj) & LV_STATE_CHECKED ? "Ckecked" : "Unckeck";
	  int state = lv_obj_get_state(obj) & LV_STATE_CHECKED ? 0: 1;
	  if(state)  
	  {
		//printf("s1 is no\n");
        sheep_s5=0;
	  }
	  else    //选中
	  {
        //printf("si is yes \n");
		sheep_s5=1;
	  }
   }
}

static void checkbox_event_hander_6(lv_event_t * e) // 性别0 品种1 用途2
{
   lv_event_code_t code = lv_event_get_code(e);
   lv_obj_t * obj = lv_event_get_target(e);
   if(code == LV_EVENT_VALUE_CHANGED){
      const char * txt = lv_checkbox_get_text(obj);
      //const char * state = lv_obj_get_state(obj) & LV_STATE_CHECKED ? "Ckecked" : "Unckeck";
	  int state = lv_obj_get_state(obj) & LV_STATE_CHECKED ? 0: 1;
	  if(state)  
	  {
		//printf("s1 is no\n");
        sheep_s6=0;
	  }
	  else    //选中
	  {
        //printf("si is yes \n");
		sheep_s6=1;
	  }
   }
}

static void checkbox_event_hander_7(lv_event_t * e) // 性别0 品种1 用途2
{
   lv_event_code_t code = lv_event_get_code(e);
   lv_obj_t * obj = lv_event_get_target(e);
   if(code == LV_EVENT_VALUE_CHANGED){
      const char * txt = lv_checkbox_get_text(obj);
      //const char * state = lv_obj_get_state(obj) & LV_STATE_CHECKED ? "Ckecked" : "Unckeck";
	  int state = lv_obj_get_state(obj) & LV_STATE_CHECKED ? 0: 1;
	  if(state)  
	  {
		//printf("s1 is no\n");
        sheep_s7=0;
	  }
	  else    //选中
	  {
        //printf("si is yes \n");
		sheep_s7=1;
	  }
   }
}


static void checkbox_event_hander_8(lv_event_t * e) // 性别0 品种1 用途2
{
   lv_event_code_t code = lv_event_get_code(e);
   lv_obj_t * obj = lv_event_get_target(e);
   if(code == LV_EVENT_VALUE_CHANGED){
      const char * txt = lv_checkbox_get_text(obj);
      //const char * state = lv_obj_get_state(obj) & LV_STATE_CHECKED ? "Ckecked" : "Unckeck";
	  int state = lv_obj_get_state(obj) & LV_STATE_CHECKED ? 0: 1;
	  if(state)  
	  {
		//printf("s1 is no\n");
        sheep_s8=0;
	  }
	  else    //选中
	  {
        //printf("si is yes \n");
		sheep_s8=1;
	  }
   }
}

static void checkbox_event_hander_9(lv_event_t * e) // 性别0 品种1 用途2
{
   lv_event_code_t code = lv_event_get_code(e);
   lv_obj_t * obj = lv_event_get_target(e);
   if(code == LV_EVENT_VALUE_CHANGED){
      const char * txt = lv_checkbox_get_text(obj);
      //const char * state = lv_obj_get_state(obj) & LV_STATE_CHECKED ? "Ckecked" : "Unckeck";
	  int state = lv_obj_get_state(obj) & LV_STATE_CHECKED ? 0: 1;
	  if(state)  
	  {
		//printf("s1 is no\n");
        sheep_s9=0;
	  }
	  else    //选中
	  {
        //printf("si is yes \n");
		sheep_s9=1;
	  }
   }
}

void setup_scr_yimiao(lv_ui *ui){

	//Write codes yimiao
	ui->yimiao = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->yimiao, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_yimiao_main_main_default
	static lv_style_t style_yimiao_main_main_default;
	if (style_yimiao_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_yimiao_main_main_default);
	else
		lv_style_init(&style_yimiao_main_main_default);
	lv_style_set_bg_color(&style_yimiao_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_yimiao_main_main_default, 0);
	lv_obj_add_style(ui->yimiao, &style_yimiao_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes yimiao_imgbtn_1
	ui->yimiao_imgbtn_1 = lv_imgbtn_create(ui->yimiao);
	lv_obj_set_pos(ui->yimiao_imgbtn_1, 0, 5);
	lv_obj_set_size(ui->yimiao_imgbtn_1, 45, 33);
	lv_obj_set_scrollbar_mode(ui->yimiao_imgbtn_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_yimiao_imgbtn_1_main_main_default
	static lv_style_t style_yimiao_imgbtn_1_main_main_default;
	if (style_yimiao_imgbtn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_yimiao_imgbtn_1_main_main_default);
	else
		lv_style_init(&style_yimiao_imgbtn_1_main_main_default);
	lv_style_set_text_color(&style_yimiao_imgbtn_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_yimiao_imgbtn_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_yimiao_imgbtn_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_yimiao_imgbtn_1_main_main_default, 0);
	lv_style_set_img_opa(&style_yimiao_imgbtn_1_main_main_default, 255);
	lv_obj_add_style(ui->yimiao_imgbtn_1, &style_yimiao_imgbtn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_yimiao_imgbtn_1_main_main_pressed
	static lv_style_t style_yimiao_imgbtn_1_main_main_pressed;
	if (style_yimiao_imgbtn_1_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_yimiao_imgbtn_1_main_main_pressed);
	else
		lv_style_init(&style_yimiao_imgbtn_1_main_main_pressed);
	lv_style_set_text_color(&style_yimiao_imgbtn_1_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_yimiao_imgbtn_1_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_yimiao_imgbtn_1_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_yimiao_imgbtn_1_main_main_pressed, 0);
	lv_style_set_img_opa(&style_yimiao_imgbtn_1_main_main_pressed, 255);
	lv_obj_add_style(ui->yimiao_imgbtn_1, &style_yimiao_imgbtn_1_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_yimiao_imgbtn_1_main_main_checked
	static lv_style_t style_yimiao_imgbtn_1_main_main_checked;
	if (style_yimiao_imgbtn_1_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_yimiao_imgbtn_1_main_main_checked);
	else
		lv_style_init(&style_yimiao_imgbtn_1_main_main_checked);
	lv_style_set_text_color(&style_yimiao_imgbtn_1_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_yimiao_imgbtn_1_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_yimiao_imgbtn_1_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_yimiao_imgbtn_1_main_main_checked, 0);
	lv_style_set_img_opa(&style_yimiao_imgbtn_1_main_main_checked, 255);
	lv_obj_add_style(ui->yimiao_imgbtn_1, &style_yimiao_imgbtn_1_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->yimiao_imgbtn_1, LV_IMGBTN_STATE_RELEASED, NULL, &_fanhui2_alpha_45x33, NULL);
	lv_imgbtn_set_src(ui->yimiao_imgbtn_1, LV_IMGBTN_STATE_PRESSED, NULL, &_fanhui2_alpha_45x33, NULL);
	lv_obj_add_flag(ui->yimiao_imgbtn_1, LV_OBJ_FLAG_CHECKABLE);

	//Write codes yimiao_label_1
	ui->yimiao_label_1 = lv_label_create(ui->yimiao);
	lv_obj_set_pos(ui->yimiao_label_1, 59, 6);
	lv_obj_set_size(ui->yimiao_label_1, 163, 32);
	lv_obj_set_scrollbar_mode(ui->yimiao_label_1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->yimiao_label_1, "疫苗接种记录管理");
	lv_label_set_long_mode(ui->yimiao_label_1, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_yimiao_label_1_main_main_default
	static lv_style_t style_yimiao_label_1_main_main_default;
	if (style_yimiao_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_yimiao_label_1_main_main_default);
	else
		lv_style_init(&style_yimiao_label_1_main_main_default);
	lv_style_set_radius(&style_yimiao_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_yimiao_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_yimiao_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_yimiao_label_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_yimiao_label_1_main_main_default, 255);
	lv_style_set_text_color(&style_yimiao_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_yimiao_label_1_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_yimiao_label_1_main_main_default, 2);
	lv_style_set_text_line_space(&style_yimiao_label_1_main_main_default, 0);
	lv_style_set_text_align(&style_yimiao_label_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_yimiao_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_yimiao_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_yimiao_label_1_main_main_default, 8);
	lv_style_set_pad_bottom(&style_yimiao_label_1_main_main_default, 0);
	lv_obj_add_style(ui->yimiao_label_1, &style_yimiao_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes yimiao_cont_1
	ui->yimiao_cont_1 = lv_obj_create(ui->yimiao);
	lv_obj_set_pos(ui->yimiao_cont_1, 7, 48);
	lv_obj_set_size(ui->yimiao_cont_1, 466, 263);
	lv_obj_set_scrollbar_mode(ui->yimiao_cont_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_yimiao_cont_1_main_main_default
	static lv_style_t style_yimiao_cont_1_main_main_default;
	if (style_yimiao_cont_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_yimiao_cont_1_main_main_default);
	else
		lv_style_init(&style_yimiao_cont_1_main_main_default);
	lv_style_set_radius(&style_yimiao_cont_1_main_main_default, 0);
	lv_style_set_bg_color(&style_yimiao_cont_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_yimiao_cont_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_yimiao_cont_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_yimiao_cont_1_main_main_default, 255);
	lv_style_set_border_color(&style_yimiao_cont_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_yimiao_cont_1_main_main_default, 2);
	lv_style_set_border_opa(&style_yimiao_cont_1_main_main_default, 255);
	lv_style_set_pad_left(&style_yimiao_cont_1_main_main_default, 0);
	lv_style_set_pad_right(&style_yimiao_cont_1_main_main_default, 0);
	lv_style_set_pad_top(&style_yimiao_cont_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_yimiao_cont_1_main_main_default, 0);
	lv_obj_add_style(ui->yimiao_cont_1, &style_yimiao_cont_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes yimiao_cb_1
	ui->yimiao_cb_1 = lv_checkbox_create(ui->yimiao_cont_1);
	lv_obj_set_pos(ui->yimiao_cb_1, 16, 12);
	lv_obj_set_scrollbar_mode(ui->yimiao_cb_1, LV_SCROLLBAR_MODE_OFF);
	lv_checkbox_set_text(ui->yimiao_cb_1, "羊四联苗");

	//Write style state: LV_STATE_DEFAULT for style_yimiao_cb_1_main_main_default
	static lv_style_t style_yimiao_cb_1_main_main_default;
	if (style_yimiao_cb_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_yimiao_cb_1_main_main_default);
	else
		lv_style_init(&style_yimiao_cb_1_main_main_default);
	lv_style_set_radius(&style_yimiao_cb_1_main_main_default, 6);
	lv_style_set_bg_color(&style_yimiao_cb_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_yimiao_cb_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_yimiao_cb_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_yimiao_cb_1_main_main_default, 255);
	lv_style_set_text_color(&style_yimiao_cb_1_main_main_default, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_yimiao_cb_1_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_yimiao_cb_1_main_main_default, 2);
	lv_obj_add_style(ui->yimiao_cb_1, &style_yimiao_cb_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_yimiao_cb_1_main_indicator_default
	static lv_style_t style_yimiao_cb_1_main_indicator_default;
	if (style_yimiao_cb_1_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_yimiao_cb_1_main_indicator_default);
	else
		lv_style_init(&style_yimiao_cb_1_main_indicator_default);
	lv_style_set_radius(&style_yimiao_cb_1_main_indicator_default, 6);
	lv_style_set_bg_color(&style_yimiao_cb_1_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_yimiao_cb_1_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_yimiao_cb_1_main_indicator_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_yimiao_cb_1_main_indicator_default, 255);
	lv_style_set_border_color(&style_yimiao_cb_1_main_indicator_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_yimiao_cb_1_main_indicator_default, 2);
	lv_style_set_border_opa(&style_yimiao_cb_1_main_indicator_default, 255);
	lv_obj_add_style(ui->yimiao_cb_1, &style_yimiao_cb_1_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui->yimiao_cb_1,checkbox_event_hander_1,LV_EVENT_ALL,NULL);  //设置回调显示
	
 
	//Write codes yimiao_cb_2
	ui->yimiao_cb_2 = lv_checkbox_create(ui->yimiao_cont_1);
	lv_obj_set_pos(ui->yimiao_cb_2, 16, 46);
	lv_obj_set_scrollbar_mode(ui->yimiao_cb_2, LV_SCROLLBAR_MODE_OFF);
	lv_checkbox_set_text(ui->yimiao_cb_2, "羊五联苗");

	//Write style state: LV_STATE_DEFAULT for style_yimiao_cb_2_main_main_default
	static lv_style_t style_yimiao_cb_2_main_main_default;
	if (style_yimiao_cb_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_yimiao_cb_2_main_main_default);
	else
		lv_style_init(&style_yimiao_cb_2_main_main_default);
	lv_style_set_radius(&style_yimiao_cb_2_main_main_default, 6);
	lv_style_set_bg_color(&style_yimiao_cb_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_yimiao_cb_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_yimiao_cb_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_yimiao_cb_2_main_main_default, 255);
	lv_style_set_text_color(&style_yimiao_cb_2_main_main_default, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_yimiao_cb_2_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_yimiao_cb_2_main_main_default, 2);
	lv_obj_add_style(ui->yimiao_cb_2, &style_yimiao_cb_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_yimiao_cb_2_main_indicator_default
	static lv_style_t style_yimiao_cb_2_main_indicator_default;
	if (style_yimiao_cb_2_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_yimiao_cb_2_main_indicator_default);
	else
		lv_style_init(&style_yimiao_cb_2_main_indicator_default);
	lv_style_set_radius(&style_yimiao_cb_2_main_indicator_default, 6);
	lv_style_set_bg_color(&style_yimiao_cb_2_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_yimiao_cb_2_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_yimiao_cb_2_main_indicator_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_yimiao_cb_2_main_indicator_default, 255);
	lv_style_set_border_color(&style_yimiao_cb_2_main_indicator_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_yimiao_cb_2_main_indicator_default, 2);
	lv_style_set_border_opa(&style_yimiao_cb_2_main_indicator_default, 255);
	lv_obj_add_style(ui->yimiao_cb_2, &style_yimiao_cb_2_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui->yimiao_cb_2,checkbox_event_hander_2,LV_EVENT_ALL,NULL);  //设置回调显示
	
   
	//Write codes yimiao_cb_3
	ui->yimiao_cb_3 = lv_checkbox_create(ui->yimiao_cont_1);
	lv_obj_set_pos(ui->yimiao_cb_3, 16, 85);
	lv_obj_set_scrollbar_mode(ui->yimiao_cb_3, LV_SCROLLBAR_MODE_OFF);
	lv_checkbox_set_text(ui->yimiao_cb_3, "破伤风类毒素");

	//Write style state: LV_STATE_DEFAULT for style_yimiao_cb_3_main_main_default
	static lv_style_t style_yimiao_cb_3_main_main_default;
	if (style_yimiao_cb_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_yimiao_cb_3_main_main_default);
	else
		lv_style_init(&style_yimiao_cb_3_main_main_default);
	lv_style_set_radius(&style_yimiao_cb_3_main_main_default, 6);
	lv_style_set_bg_color(&style_yimiao_cb_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_yimiao_cb_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_yimiao_cb_3_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_yimiao_cb_3_main_main_default, 255);
	lv_style_set_text_color(&style_yimiao_cb_3_main_main_default, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_yimiao_cb_3_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_yimiao_cb_3_main_main_default, 2);
	lv_obj_add_style(ui->yimiao_cb_3, &style_yimiao_cb_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_yimiao_cb_3_main_indicator_default
	static lv_style_t style_yimiao_cb_3_main_indicator_default;
	if (style_yimiao_cb_3_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_yimiao_cb_3_main_indicator_default);
	else
		lv_style_init(&style_yimiao_cb_3_main_indicator_default);
	lv_style_set_radius(&style_yimiao_cb_3_main_indicator_default, 6);
	lv_style_set_bg_color(&style_yimiao_cb_3_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_yimiao_cb_3_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_yimiao_cb_3_main_indicator_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_yimiao_cb_3_main_indicator_default, 255);
	lv_style_set_border_color(&style_yimiao_cb_3_main_indicator_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_yimiao_cb_3_main_indicator_default, 2);
	lv_style_set_border_opa(&style_yimiao_cb_3_main_indicator_default, 255);
	lv_obj_add_style(ui->yimiao_cb_3, &style_yimiao_cb_3_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui->yimiao_cb_3,checkbox_event_hander_3,LV_EVENT_ALL,NULL);  //设置回调显示
	

	//Write codes yimiao_cb_4
	ui->yimiao_cb_4 = lv_checkbox_create(ui->yimiao_cont_1);
	lv_obj_set_pos(ui->yimiao_cb_4, 16, 127);
	lv_obj_set_scrollbar_mode(ui->yimiao_cb_4, LV_SCROLLBAR_MODE_OFF);
	lv_checkbox_set_text(ui->yimiao_cb_4, "第Ⅱ号炭疽菌苗");

	//Write style state: LV_STATE_DEFAULT for style_yimiao_cb_4_main_main_default
	static lv_style_t style_yimiao_cb_4_main_main_default;
	if (style_yimiao_cb_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_yimiao_cb_4_main_main_default);
	else
		lv_style_init(&style_yimiao_cb_4_main_main_default);
	lv_style_set_radius(&style_yimiao_cb_4_main_main_default, 6);
	lv_style_set_bg_color(&style_yimiao_cb_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_yimiao_cb_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_yimiao_cb_4_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_yimiao_cb_4_main_main_default, 255);
	lv_style_set_text_color(&style_yimiao_cb_4_main_main_default, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_yimiao_cb_4_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_yimiao_cb_4_main_main_default, 2);
	lv_obj_add_style(ui->yimiao_cb_4, &style_yimiao_cb_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_yimiao_cb_4_main_indicator_default
	static lv_style_t style_yimiao_cb_4_main_indicator_default;
	if (style_yimiao_cb_4_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_yimiao_cb_4_main_indicator_default);
	else
		lv_style_init(&style_yimiao_cb_4_main_indicator_default);
	lv_style_set_radius(&style_yimiao_cb_4_main_indicator_default, 6);
	lv_style_set_bg_color(&style_yimiao_cb_4_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_yimiao_cb_4_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_yimiao_cb_4_main_indicator_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_yimiao_cb_4_main_indicator_default, 255);
	lv_style_set_border_color(&style_yimiao_cb_4_main_indicator_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_yimiao_cb_4_main_indicator_default, 2);
	lv_style_set_border_opa(&style_yimiao_cb_4_main_indicator_default, 255);
	lv_obj_add_style(ui->yimiao_cb_4, &style_yimiao_cb_4_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui->yimiao_cb_4,checkbox_event_hander_4,LV_EVENT_ALL,NULL);  //设置回调显示
	
	//Write codes yimiao_cb_5
	ui->yimiao_cb_5 = lv_checkbox_create(ui->yimiao_cont_1);
	lv_obj_set_pos(ui->yimiao_cb_5, 16, 168);
	lv_obj_set_scrollbar_mode(ui->yimiao_cb_5, LV_SCROLLBAR_MODE_OFF);
	lv_checkbox_set_text(ui->yimiao_cb_5, "羔羊大肠杆菌疫苗");

	//Write style state: LV_STATE_DEFAULT for style_yimiao_cb_5_main_main_default
	static lv_style_t style_yimiao_cb_5_main_main_default;
	if (style_yimiao_cb_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_yimiao_cb_5_main_main_default);
	else
		lv_style_init(&style_yimiao_cb_5_main_main_default);
	lv_style_set_radius(&style_yimiao_cb_5_main_main_default, 6);
	lv_style_set_bg_color(&style_yimiao_cb_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_yimiao_cb_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_yimiao_cb_5_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_yimiao_cb_5_main_main_default, 255);
	lv_style_set_text_color(&style_yimiao_cb_5_main_main_default, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_yimiao_cb_5_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_yimiao_cb_5_main_main_default, 2);
	lv_obj_add_style(ui->yimiao_cb_5, &style_yimiao_cb_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_yimiao_cb_5_main_indicator_default
	static lv_style_t style_yimiao_cb_5_main_indicator_default;
	if (style_yimiao_cb_5_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_yimiao_cb_5_main_indicator_default);
	else
		lv_style_init(&style_yimiao_cb_5_main_indicator_default);
	lv_style_set_radius(&style_yimiao_cb_5_main_indicator_default, 6);
	lv_style_set_bg_color(&style_yimiao_cb_5_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_yimiao_cb_5_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_yimiao_cb_5_main_indicator_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_yimiao_cb_5_main_indicator_default, 255);
	lv_style_set_border_color(&style_yimiao_cb_5_main_indicator_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_yimiao_cb_5_main_indicator_default, 2);
	lv_style_set_border_opa(&style_yimiao_cb_5_main_indicator_default, 255);
	lv_obj_add_style(ui->yimiao_cb_5, &style_yimiao_cb_5_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui->yimiao_cb_5,checkbox_event_hander_5,LV_EVENT_ALL,NULL);  //设置回调显示
	
	//Write codes yimiao_cb_6
	ui->yimiao_cb_6 = lv_checkbox_create(ui->yimiao_cont_1);
	lv_obj_set_pos(ui->yimiao_cb_6, 17, 206);
	lv_obj_set_scrollbar_mode(ui->yimiao_cb_6, LV_SCROLLBAR_MODE_OFF);
	lv_checkbox_set_text(ui->yimiao_cb_6, "口疮弱毒细胞冻干苗");

	//Write style state: LV_STATE_DEFAULT for style_yimiao_cb_6_main_main_default
	static lv_style_t style_yimiao_cb_6_main_main_default;
	if (style_yimiao_cb_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_yimiao_cb_6_main_main_default);
	else
		lv_style_init(&style_yimiao_cb_6_main_main_default);
	lv_style_set_radius(&style_yimiao_cb_6_main_main_default, 6);
	lv_style_set_bg_color(&style_yimiao_cb_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_yimiao_cb_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_yimiao_cb_6_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_yimiao_cb_6_main_main_default, 255);
	lv_style_set_text_color(&style_yimiao_cb_6_main_main_default, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_yimiao_cb_6_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_yimiao_cb_6_main_main_default, 2);
	lv_obj_add_style(ui->yimiao_cb_6, &style_yimiao_cb_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_yimiao_cb_6_main_indicator_default
	static lv_style_t style_yimiao_cb_6_main_indicator_default;
	if (style_yimiao_cb_6_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_yimiao_cb_6_main_indicator_default);
	else
		lv_style_init(&style_yimiao_cb_6_main_indicator_default);
	lv_style_set_radius(&style_yimiao_cb_6_main_indicator_default, 6);
	lv_style_set_bg_color(&style_yimiao_cb_6_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_yimiao_cb_6_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_yimiao_cb_6_main_indicator_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_yimiao_cb_6_main_indicator_default, 255);
	lv_style_set_border_color(&style_yimiao_cb_6_main_indicator_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_yimiao_cb_6_main_indicator_default, 2);
	lv_style_set_border_opa(&style_yimiao_cb_6_main_indicator_default, 255);
	lv_obj_add_style(ui->yimiao_cb_6, &style_yimiao_cb_6_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui->yimiao_cb_6,checkbox_event_hander_6,LV_EVENT_ALL,NULL);  //设置回调显示
	

	//Write codes yimiao_cb_7
	ui->yimiao_cb_7 = lv_checkbox_create(ui->yimiao_cont_1);
	lv_obj_set_pos(ui->yimiao_cb_7, 247, 4);
	lv_obj_set_scrollbar_mode(ui->yimiao_cb_7, LV_SCROLLBAR_MODE_OFF);
	lv_checkbox_set_text(ui->yimiao_cb_7, "羊链球菌氢氧化铝菌苗");

	//Write style state: LV_STATE_DEFAULT for style_yimiao_cb_7_main_main_default
	static lv_style_t style_yimiao_cb_7_main_main_default;
	if (style_yimiao_cb_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_yimiao_cb_7_main_main_default);
	else
		lv_style_init(&style_yimiao_cb_7_main_main_default);
	lv_style_set_radius(&style_yimiao_cb_7_main_main_default, 6);
	lv_style_set_bg_color(&style_yimiao_cb_7_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_yimiao_cb_7_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_yimiao_cb_7_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_yimiao_cb_7_main_main_default, 255);
	lv_style_set_text_color(&style_yimiao_cb_7_main_main_default, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_yimiao_cb_7_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_yimiao_cb_7_main_main_default, 2);
	lv_obj_add_style(ui->yimiao_cb_7, &style_yimiao_cb_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_yimiao_cb_7_main_indicator_default
	static lv_style_t style_yimiao_cb_7_main_indicator_default;
	if (style_yimiao_cb_7_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_yimiao_cb_7_main_indicator_default);
	else
		lv_style_init(&style_yimiao_cb_7_main_indicator_default);
	lv_style_set_radius(&style_yimiao_cb_7_main_indicator_default, 6);
	lv_style_set_bg_color(&style_yimiao_cb_7_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_yimiao_cb_7_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_yimiao_cb_7_main_indicator_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_yimiao_cb_7_main_indicator_default, 255);
	lv_style_set_border_color(&style_yimiao_cb_7_main_indicator_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_yimiao_cb_7_main_indicator_default, 2);
	lv_style_set_border_opa(&style_yimiao_cb_7_main_indicator_default, 255);
	lv_obj_add_style(ui->yimiao_cb_7, &style_yimiao_cb_7_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);
   
    lv_obj_add_event_cb(ui->yimiao_cb_7,checkbox_event_hander_7,LV_EVENT_ALL,NULL);  //设置回调显示
	
	//Write codes yimiao_cb_8
	ui->yimiao_cb_8 = lv_checkbox_create(ui->yimiao_cont_1);
	lv_obj_set_pos(ui->yimiao_cb_8, 247, 39);
	lv_obj_set_scrollbar_mode(ui->yimiao_cb_8, LV_SCROLLBAR_MODE_OFF);
	lv_checkbox_set_text(ui->yimiao_cb_8, "羊黑疫菌苗");

	//Write style state: LV_STATE_DEFAULT for style_yimiao_cb_8_main_main_default
	static lv_style_t style_yimiao_cb_8_main_main_default;
	if (style_yimiao_cb_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_yimiao_cb_8_main_main_default);
	else
		lv_style_init(&style_yimiao_cb_8_main_main_default);
	lv_style_set_radius(&style_yimiao_cb_8_main_main_default, 6);
	lv_style_set_bg_color(&style_yimiao_cb_8_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_yimiao_cb_8_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_yimiao_cb_8_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_yimiao_cb_8_main_main_default, 255);
	lv_style_set_text_color(&style_yimiao_cb_8_main_main_default, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_yimiao_cb_8_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_yimiao_cb_8_main_main_default, 2);
	lv_obj_add_style(ui->yimiao_cb_8, &style_yimiao_cb_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_yimiao_cb_8_main_indicator_default
	static lv_style_t style_yimiao_cb_8_main_indicator_default;
	if (style_yimiao_cb_8_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_yimiao_cb_8_main_indicator_default);
	else
		lv_style_init(&style_yimiao_cb_8_main_indicator_default);
	lv_style_set_radius(&style_yimiao_cb_8_main_indicator_default, 6);
	lv_style_set_bg_color(&style_yimiao_cb_8_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_yimiao_cb_8_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_yimiao_cb_8_main_indicator_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_yimiao_cb_8_main_indicator_default, 255);
	lv_style_set_border_color(&style_yimiao_cb_8_main_indicator_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_yimiao_cb_8_main_indicator_default, 2);
	lv_style_set_border_opa(&style_yimiao_cb_8_main_indicator_default, 255);
	lv_obj_add_style(ui->yimiao_cb_8, &style_yimiao_cb_8_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui->yimiao_cb_8,checkbox_event_hander_8,LV_EVENT_ALL,NULL);  //设置回调显示
	
	//Write codes yimiao_cb_9
	ui->yimiao_cb_9 = lv_checkbox_create(ui->yimiao_cont_1);
	lv_obj_set_pos(ui->yimiao_cb_9, 247, 73);
	lv_obj_set_scrollbar_mode(ui->yimiao_cb_9, LV_SCROLLBAR_MODE_OFF);
	lv_checkbox_set_text(ui->yimiao_cb_9, "山羊痘灭活苗");

	//Write style state: LV_STATE_DEFAULT for style_yimiao_cb_9_main_main_default
	static lv_style_t style_yimiao_cb_9_main_main_default;
	if (style_yimiao_cb_9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_yimiao_cb_9_main_main_default);
	else
		lv_style_init(&style_yimiao_cb_9_main_main_default);
	lv_style_set_radius(&style_yimiao_cb_9_main_main_default, 6);
	lv_style_set_bg_color(&style_yimiao_cb_9_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_yimiao_cb_9_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_yimiao_cb_9_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_yimiao_cb_9_main_main_default, 255);
	lv_style_set_text_color(&style_yimiao_cb_9_main_main_default, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_yimiao_cb_9_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_yimiao_cb_9_main_main_default, 2);
	lv_obj_add_style(ui->yimiao_cb_9, &style_yimiao_cb_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_yimiao_cb_9_main_indicator_default
	static lv_style_t style_yimiao_cb_9_main_indicator_default;
	if (style_yimiao_cb_9_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_yimiao_cb_9_main_indicator_default);
	else
		lv_style_init(&style_yimiao_cb_9_main_indicator_default);
	lv_style_set_radius(&style_yimiao_cb_9_main_indicator_default, 6);
	lv_style_set_bg_color(&style_yimiao_cb_9_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_yimiao_cb_9_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_yimiao_cb_9_main_indicator_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_yimiao_cb_9_main_indicator_default, 255);
	lv_style_set_border_color(&style_yimiao_cb_9_main_indicator_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_yimiao_cb_9_main_indicator_default, 2);
	lv_style_set_border_opa(&style_yimiao_cb_9_main_indicator_default, 255);
	lv_obj_add_style(ui->yimiao_cb_9, &style_yimiao_cb_9_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui->yimiao_cb_9,checkbox_event_hander_9,LV_EVENT_ALL,NULL);  //设置回调显示

	//Write codes yimiao_label_2
	ui->yimiao_label_2 = lv_label_create(ui->yimiao);
	lv_obj_set_pos(ui->yimiao_label_2, 295, 6);
	lv_obj_set_size(ui->yimiao_label_2, 121, 32);
	lv_obj_set_scrollbar_mode(ui->yimiao_label_2, LV_SCROLLBAR_MODE_OFF);
	//lv_label_set_text(ui->yimiao_label_2, "12345");
	lv_label_set_text_fmt(ui->yimiao_label_2,"%d",ear_id_n);


	lv_label_set_long_mode(ui->yimiao_label_2, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_yimiao_label_2_main_main_default
	static lv_style_t style_yimiao_label_2_main_main_default;
	if (style_yimiao_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_yimiao_label_2_main_main_default);
	else
		lv_style_init(&style_yimiao_label_2_main_main_default);
	lv_style_set_radius(&style_yimiao_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_yimiao_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_yimiao_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_yimiao_label_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_yimiao_label_2_main_main_default, 255);
	lv_style_set_text_color(&style_yimiao_label_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_yimiao_label_2_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_yimiao_label_2_main_main_default, 2);
	lv_style_set_text_line_space(&style_yimiao_label_2_main_main_default, 0);
	lv_style_set_text_align(&style_yimiao_label_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_yimiao_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_yimiao_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_yimiao_label_2_main_main_default, 8);
	lv_style_set_pad_bottom(&style_yimiao_label_2_main_main_default, 0);
	lv_obj_add_style(ui->yimiao_label_2, &style_yimiao_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Init events for screen
	events_init_yimiao(ui);
}