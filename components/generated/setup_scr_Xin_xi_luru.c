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
extern u_int8_t zhuce;

extern u_int32_t gui_id;
extern char *gui_species;
extern char *gui_sex;
extern char *gui_weight;
extern char *gui_sheep_age;
extern char *gui_use_value;
extern char *gui_place_of_production;

static lv_obj_t * g_kb;
static void kb_event_cb(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t *kb = lv_event_get_target(e);
	if(code == LV_EVENT_READY || code == LV_EVENT_CANCEL){
		lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
	}
}
static void ta_event_cb(lv_event_t *e)
{

	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t *ta = lv_event_get_target(e);
    lv_obj_t *nn = lv_event_get_target(e);
	LV_UNUSED(nn);
	lv_obj_t *kb = lv_event_get_user_data(e);

	if (code == LV_EVENT_FOCUSED)
	{
		gui_sheep_age = lv_textarea_get_text(nn);
		lv_keyboard_set_textarea(kb, ta);
		lv_obj_move_foreground(kb);
		lv_obj_clear_flag(kb, LV_OBJ_FLAG_HIDDEN);
	}
	if (code == LV_EVENT_DEFOCUSED)
	{   
		gui_sheep_age = lv_textarea_get_text(nn);
		//gui_sheep_age=lv_textarea_get_placeholder_text(nn);
	    printf("bb55bb is %s \n",gui_sheep_age);
		lv_keyboard_set_textarea(kb, NULL);
		lv_obj_move_background(kb);
		lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
	}
}

static void ta_event_cb2(lv_event_t *e)
{
/* 	gui_species="";
    gui_sex="";
    gui_weight="";
    gui_sheep_age="";
    gui_use_value="";
    gui_place_of_production=""; */

	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t *ta = lv_event_get_target(e);
    lv_obj_t *nn = lv_event_get_target(e);
	LV_UNUSED(nn);
	lv_obj_t *kb = lv_event_get_user_data(e);

	if (code == LV_EVENT_FOCUSED)
	{
		gui_weight = lv_textarea_get_text(nn);
		lv_keyboard_set_textarea(kb, ta);
		lv_obj_move_foreground(kb);
		lv_obj_clear_flag(kb, LV_OBJ_FLAG_HIDDEN);
	}
	if (code == LV_EVENT_DEFOCUSED)
	{   
		gui_weight = lv_textarea_get_text(nn);
		//gui_weight=lv_textarea_get_placeholder_text(nn);
	    printf("ti zhong is %s \n",gui_weight);
		lv_keyboard_set_textarea(kb, NULL);
		lv_obj_move_background(kb);
		lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
	}
}


static void checkbox_event_hander(lv_event_t * e) // 性别0 品种1 用途2
{
   lv_event_code_t code = lv_event_get_code(e);
   lv_obj_t * obj = lv_event_get_target(e);
   if(code == LV_EVENT_VALUE_CHANGED){
      const char * txt = lv_checkbox_get_text(obj);
      //const char * state = lv_obj_get_state(obj) & LV_STATE_CHECKED ? "Ckecked" : "Unckeck";
	  int state = lv_obj_get_state(obj) & LV_STATE_CHECKED ? 0: 1;
	  if(state)
	  {
		printf("this is mu\n");
		gui_sex="母羊";
		//zhuce=1;
	  }
	  else 
	  {
        printf("this is gong \n");
		gui_sex="公羊";
		//zhuce=1;
	  }
   }
}

static void checkbox_event_hander2(lv_event_t * e) //  品种1 用途2
{
   lv_event_code_t code = lv_event_get_code(e);
   lv_obj_t * obj = lv_event_get_target(e);
   if(code == LV_EVENT_VALUE_CHANGED){
      const char * txt = lv_checkbox_get_text(obj);
      //const char * state = lv_obj_get_state(obj) & LV_STATE_CHECKED ? "Ckecked" : "Unckeck";
	  int state = lv_obj_get_state(obj) & LV_STATE_CHECKED ? 0: 1;
	  if(state==0)
	  {
		printf("this is 绵羊\n");
		gui_species="绵羊";
	  }
	    
      
   }
}

static void checkbox_event_hander2_2(lv_event_t * e) //  品种1 用途2
{
   lv_event_code_t code = lv_event_get_code(e);
   lv_obj_t * obj = lv_event_get_target(e);
   if(code == LV_EVENT_VALUE_CHANGED){
      const char * txt = lv_checkbox_get_text(obj);
      //const char * state = lv_obj_get_state(obj) & LV_STATE_CHECKED ? "Ckecked" : "Unckeck";
	  int state = lv_obj_get_state(obj) & LV_STATE_CHECKED ? 0: 1;
	  if(state==0)
	  {
		printf("this is shanyang\n");
		gui_species="山羊";
	  }    
   }
}

static void checkbox_event_hander2_3(lv_event_t * e) //  品种1 用途2
{
   lv_event_code_t code = lv_event_get_code(e);
   lv_obj_t * obj = lv_event_get_target(e);
   if(code == LV_EVENT_VALUE_CHANGED){
      const char * txt = lv_checkbox_get_text(obj);
      //const char * state = lv_obj_get_state(obj) & LV_STATE_CHECKED ? "Ckecked" : "Unckeck";
	  int state = lv_obj_get_state(obj) & LV_STATE_CHECKED ? 0: 1;
	  if(state==0)
	  {
		printf("this is ling yang\n");
		gui_species="羚羊";
	  }    
   }
}

static void checkbox_event_hander2_4(lv_event_t * e) //  品种1 用途2
{
   lv_event_code_t code = lv_event_get_code(e);
   lv_obj_t * obj = lv_event_get_target(e);
   if(code == LV_EVENT_VALUE_CHANGED){
      const char * txt = lv_checkbox_get_text(obj);
      //const char * state = lv_obj_get_state(obj) & LV_STATE_CHECKED ? "Ckecked" : "Unckeck";
	  int state = lv_obj_get_state(obj) & LV_STATE_CHECKED ? 0: 1;
	  if(state==0)
	  {
		printf("this is duboyang\n");
		gui_species="杜泊羊";
	  }    
   }
}

void setup_scr_Xin_xi_luru(lv_ui *ui){

	//Write codes Xin_xi_luru
	ui->Xin_xi_luru = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->Xin_xi_luru, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_xin_xi_luru_main_main_default
	static lv_style_t style_xin_xi_luru_main_main_default;
	if (style_xin_xi_luru_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_xin_xi_luru_main_main_default);
	else
		lv_style_init(&style_xin_xi_luru_main_main_default);
	lv_style_set_bg_color(&style_xin_xi_luru_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_xin_xi_luru_main_main_default, 0);
	lv_obj_add_style(ui->Xin_xi_luru, &style_xin_xi_luru_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Xin_xi_luru_tileview_1
	ui->Xin_xi_luru_tileview_1 = lv_tileview_create(ui->Xin_xi_luru);
	lv_obj_set_pos(ui->Xin_xi_luru_tileview_1, 11, 47);
	lv_obj_set_size(ui->Xin_xi_luru_tileview_1, 459, 256);
	lv_obj_set_scrollbar_mode(ui->Xin_xi_luru_tileview_1, LV_SCROLLBAR_MODE_ON);

	//Write style state: LV_STATE_DEFAULT for style_xin_xi_luru_tileview_1_main_main_default
	static lv_style_t style_xin_xi_luru_tileview_1_main_main_default;
	if (style_xin_xi_luru_tileview_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_xin_xi_luru_tileview_1_main_main_default);
	else
		lv_style_init(&style_xin_xi_luru_tileview_1_main_main_default);
	lv_style_set_radius(&style_xin_xi_luru_tileview_1_main_main_default, 0);
	lv_style_set_bg_color(&style_xin_xi_luru_tileview_1_main_main_default, lv_color_make(0xdf, 0xdd, 0xdd));
	lv_style_set_bg_grad_color(&style_xin_xi_luru_tileview_1_main_main_default, lv_color_make(0xf6, 0xf6, 0xf6));
	lv_style_set_bg_grad_dir(&style_xin_xi_luru_tileview_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_xin_xi_luru_tileview_1_main_main_default, 205);
	lv_obj_add_style(ui->Xin_xi_luru_tileview_1, &style_xin_xi_luru_tileview_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_xin_xi_luru_tileview_1_main_scrollbar_default
	static lv_style_t style_xin_xi_luru_tileview_1_main_scrollbar_default;
	if (style_xin_xi_luru_tileview_1_main_scrollbar_default.prop_cnt > 1)
		lv_style_reset(&style_xin_xi_luru_tileview_1_main_scrollbar_default);
	else
		lv_style_init(&style_xin_xi_luru_tileview_1_main_scrollbar_default);
	lv_style_set_radius(&style_xin_xi_luru_tileview_1_main_scrollbar_default, 0);
	lv_style_set_bg_color(&style_xin_xi_luru_tileview_1_main_scrollbar_default, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_opa(&style_xin_xi_luru_tileview_1_main_scrollbar_default, 255);
	lv_obj_add_style(ui->Xin_xi_luru_tileview_1, &style_xin_xi_luru_tileview_1_main_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//add new tile Xin_xi_luru_tileview_1_tile_2
	ui->Xin_xi_luru_tileview_1_tile_2 = lv_tileview_add_tile(ui->Xin_xi_luru_tileview_1, 0 , 1, LV_DIR_TOP);

	//Write codes Xin_xi_luru_label_9
	ui->Xin_xi_luru_label_9 = lv_label_create(ui->Xin_xi_luru_tileview_1_tile_2);
	lv_obj_set_pos(ui->Xin_xi_luru_label_9, 14, 15);
	lv_obj_set_size(ui->Xin_xi_luru_label_9, 62, 36);
	lv_obj_set_scrollbar_mode(ui->Xin_xi_luru_label_9, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->Xin_xi_luru_label_9, "其他：");
	lv_label_set_long_mode(ui->Xin_xi_luru_label_9, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_xin_xi_luru_label_9_main_main_default
	static lv_style_t style_xin_xi_luru_label_9_main_main_default;
	if (style_xin_xi_luru_label_9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_xin_xi_luru_label_9_main_main_default);
	else
		lv_style_init(&style_xin_xi_luru_label_9_main_main_default);
	lv_style_set_radius(&style_xin_xi_luru_label_9_main_main_default, 0);
	lv_style_set_bg_color(&style_xin_xi_luru_label_9_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_xin_xi_luru_label_9_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_xin_xi_luru_label_9_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_xin_xi_luru_label_9_main_main_default, 115);
	lv_style_set_text_color(&style_xin_xi_luru_label_9_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_xin_xi_luru_label_9_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_xin_xi_luru_label_9_main_main_default, 2);
	lv_style_set_text_line_space(&style_xin_xi_luru_label_9_main_main_default, 0);
	lv_style_set_text_align(&style_xin_xi_luru_label_9_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_xin_xi_luru_label_9_main_main_default, 0);
	lv_style_set_pad_right(&style_xin_xi_luru_label_9_main_main_default, 0);
	lv_style_set_pad_top(&style_xin_xi_luru_label_9_main_main_default, 8);
	lv_style_set_pad_bottom(&style_xin_xi_luru_label_9_main_main_default, 0);
	lv_obj_add_style(ui->Xin_xi_luru_label_9, &style_xin_xi_luru_label_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Xin_xi_luru_cb_1
	ui->Xin_xi_luru_cb_1 = lv_checkbox_create(ui->Xin_xi_luru_tileview_1_tile_2);
	lv_obj_set_pos(ui->Xin_xi_luru_cb_1, 102, 21);
	lv_obj_set_scrollbar_mode(ui->Xin_xi_luru_cb_1, LV_SCROLLBAR_MODE_OFF);
	lv_checkbox_set_text(ui->Xin_xi_luru_cb_1, "公羊");

	//Write style state: LV_STATE_DEFAULT for style_xin_xi_luru_cb_1_main_main_default
	static lv_style_t style_xin_xi_luru_cb_1_main_main_default;
	if (style_xin_xi_luru_cb_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_xin_xi_luru_cb_1_main_main_default);
	else
		lv_style_init(&style_xin_xi_luru_cb_1_main_main_default);
	lv_style_set_radius(&style_xin_xi_luru_cb_1_main_main_default, 6);
	lv_style_set_bg_color(&style_xin_xi_luru_cb_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_xin_xi_luru_cb_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_xin_xi_luru_cb_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_xin_xi_luru_cb_1_main_main_default, 255);
	lv_style_set_text_color(&style_xin_xi_luru_cb_1_main_main_default, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_xin_xi_luru_cb_1_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_xin_xi_luru_cb_1_main_main_default, 2);
	lv_obj_add_style(ui->Xin_xi_luru_cb_1, &style_xin_xi_luru_cb_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_xin_xi_luru_cb_1_main_indicator_default
	static lv_style_t style_xin_xi_luru_cb_1_main_indicator_default;
	if (style_xin_xi_luru_cb_1_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_xin_xi_luru_cb_1_main_indicator_default);
	else
		lv_style_init(&style_xin_xi_luru_cb_1_main_indicator_default);
	lv_style_set_radius(&style_xin_xi_luru_cb_1_main_indicator_default, 6);
	lv_style_set_bg_color(&style_xin_xi_luru_cb_1_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_xin_xi_luru_cb_1_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_xin_xi_luru_cb_1_main_indicator_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_xin_xi_luru_cb_1_main_indicator_default, 255);
	lv_style_set_border_color(&style_xin_xi_luru_cb_1_main_indicator_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_xin_xi_luru_cb_1_main_indicator_default, 2);
	lv_style_set_border_opa(&style_xin_xi_luru_cb_1_main_indicator_default, 255);
	lv_obj_add_style(ui->Xin_xi_luru_cb_1, &style_xin_xi_luru_cb_1_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    
	lv_obj_add_event_cb(ui->Xin_xi_luru_cb_1,checkbox_event_hander,LV_EVENT_ALL,NULL);  //设置回调显示


	//Write codes Xin_xi_luru_cb_2
	ui->Xin_xi_luru_cb_2 = lv_checkbox_create(ui->Xin_xi_luru_tileview_1_tile_2);
	lv_obj_set_pos(ui->Xin_xi_luru_cb_2, 103, 61);
	lv_obj_set_scrollbar_mode(ui->Xin_xi_luru_cb_2, LV_SCROLLBAR_MODE_OFF);
	lv_checkbox_set_text(ui->Xin_xi_luru_cb_2, "母羊");

	//Write style state: LV_STATE_DEFAULT for style_xin_xi_luru_cb_2_main_main_default
	static lv_style_t style_xin_xi_luru_cb_2_main_main_default;
	if (style_xin_xi_luru_cb_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_xin_xi_luru_cb_2_main_main_default);
	else
		lv_style_init(&style_xin_xi_luru_cb_2_main_main_default);
	lv_style_set_radius(&style_xin_xi_luru_cb_2_main_main_default, 6);
	lv_style_set_bg_color(&style_xin_xi_luru_cb_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_xin_xi_luru_cb_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_xin_xi_luru_cb_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_xin_xi_luru_cb_2_main_main_default, 255);
	lv_style_set_text_color(&style_xin_xi_luru_cb_2_main_main_default, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_xin_xi_luru_cb_2_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_xin_xi_luru_cb_2_main_main_default, 2);
	lv_obj_add_style(ui->Xin_xi_luru_cb_2, &style_xin_xi_luru_cb_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_xin_xi_luru_cb_2_main_indicator_default
	static lv_style_t style_xin_xi_luru_cb_2_main_indicator_default;
	if (style_xin_xi_luru_cb_2_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_xin_xi_luru_cb_2_main_indicator_default);
	else
		lv_style_init(&style_xin_xi_luru_cb_2_main_indicator_default);
	lv_style_set_radius(&style_xin_xi_luru_cb_2_main_indicator_default, 6);
	lv_style_set_bg_color(&style_xin_xi_luru_cb_2_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_xin_xi_luru_cb_2_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_xin_xi_luru_cb_2_main_indicator_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_xin_xi_luru_cb_2_main_indicator_default, 255);
	lv_style_set_border_color(&style_xin_xi_luru_cb_2_main_indicator_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_xin_xi_luru_cb_2_main_indicator_default, 2);
	lv_style_set_border_opa(&style_xin_xi_luru_cb_2_main_indicator_default, 255);
	lv_obj_add_style(ui->Xin_xi_luru_cb_2, &style_xin_xi_luru_cb_2_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write codes Xin_xi_luru_cb_3
	ui->Xin_xi_luru_cb_3 = lv_checkbox_create(ui->Xin_xi_luru_tileview_1_tile_2);
	lv_obj_set_pos(ui->Xin_xi_luru_cb_3, 190, 21);
	lv_obj_set_scrollbar_mode(ui->Xin_xi_luru_cb_3, LV_SCROLLBAR_MODE_OFF);
	lv_checkbox_set_text(ui->Xin_xi_luru_cb_3, "绵羊");

	//Write style state: LV_STATE_DEFAULT for style_xin_xi_luru_cb_3_main_main_default
	static lv_style_t style_xin_xi_luru_cb_3_main_main_default;
	if (style_xin_xi_luru_cb_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_xin_xi_luru_cb_3_main_main_default);
	else
		lv_style_init(&style_xin_xi_luru_cb_3_main_main_default);
	lv_style_set_radius(&style_xin_xi_luru_cb_3_main_main_default, 6);
	lv_style_set_bg_color(&style_xin_xi_luru_cb_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_xin_xi_luru_cb_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_xin_xi_luru_cb_3_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_xin_xi_luru_cb_3_main_main_default, 255);
	lv_style_set_text_color(&style_xin_xi_luru_cb_3_main_main_default, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_xin_xi_luru_cb_3_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_xin_xi_luru_cb_3_main_main_default, 2);
	lv_obj_add_style(ui->Xin_xi_luru_cb_3, &style_xin_xi_luru_cb_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_xin_xi_luru_cb_3_main_indicator_default
	static lv_style_t style_xin_xi_luru_cb_3_main_indicator_default;
	if (style_xin_xi_luru_cb_3_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_xin_xi_luru_cb_3_main_indicator_default);
	else
		lv_style_init(&style_xin_xi_luru_cb_3_main_indicator_default);
	lv_style_set_radius(&style_xin_xi_luru_cb_3_main_indicator_default, 6);
	lv_style_set_bg_color(&style_xin_xi_luru_cb_3_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_xin_xi_luru_cb_3_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_xin_xi_luru_cb_3_main_indicator_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_xin_xi_luru_cb_3_main_indicator_default, 255);
	lv_style_set_border_color(&style_xin_xi_luru_cb_3_main_indicator_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_xin_xi_luru_cb_3_main_indicator_default, 2);
	lv_style_set_border_opa(&style_xin_xi_luru_cb_3_main_indicator_default, 255);
	lv_obj_add_style(ui->Xin_xi_luru_cb_3, &style_xin_xi_luru_cb_3_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui->Xin_xi_luru_cb_3,checkbox_event_hander2,LV_EVENT_ALL,NULL);  //设置回调显示

	//Write codes Xin_xi_luru_cb_4
	ui->Xin_xi_luru_cb_4 = lv_checkbox_create(ui->Xin_xi_luru_tileview_1_tile_2);
	lv_obj_set_pos(ui->Xin_xi_luru_cb_4, 190, 63);
	lv_obj_set_scrollbar_mode(ui->Xin_xi_luru_cb_4, LV_SCROLLBAR_MODE_OFF);
	lv_checkbox_set_text(ui->Xin_xi_luru_cb_4, "山羊");

	//Write style state: LV_STATE_DEFAULT for style_xin_xi_luru_cb_4_main_main_default
	static lv_style_t style_xin_xi_luru_cb_4_main_main_default;
	if (style_xin_xi_luru_cb_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_xin_xi_luru_cb_4_main_main_default);
	else
		lv_style_init(&style_xin_xi_luru_cb_4_main_main_default);
	lv_style_set_radius(&style_xin_xi_luru_cb_4_main_main_default, 6);
	lv_style_set_bg_color(&style_xin_xi_luru_cb_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_xin_xi_luru_cb_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_xin_xi_luru_cb_4_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_xin_xi_luru_cb_4_main_main_default, 255);
	lv_style_set_text_color(&style_xin_xi_luru_cb_4_main_main_default, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_xin_xi_luru_cb_4_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_xin_xi_luru_cb_4_main_main_default, 2);
	lv_obj_add_style(ui->Xin_xi_luru_cb_4, &style_xin_xi_luru_cb_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_xin_xi_luru_cb_4_main_indicator_default
	static lv_style_t style_xin_xi_luru_cb_4_main_indicator_default;
	if (style_xin_xi_luru_cb_4_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_xin_xi_luru_cb_4_main_indicator_default);
	else
		lv_style_init(&style_xin_xi_luru_cb_4_main_indicator_default);
	lv_style_set_radius(&style_xin_xi_luru_cb_4_main_indicator_default, 6);
	lv_style_set_bg_color(&style_xin_xi_luru_cb_4_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_xin_xi_luru_cb_4_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_xin_xi_luru_cb_4_main_indicator_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_xin_xi_luru_cb_4_main_indicator_default, 255);
	lv_style_set_border_color(&style_xin_xi_luru_cb_4_main_indicator_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_xin_xi_luru_cb_4_main_indicator_default, 2);
	lv_style_set_border_opa(&style_xin_xi_luru_cb_4_main_indicator_default, 255);
	lv_obj_add_style(ui->Xin_xi_luru_cb_4, &style_xin_xi_luru_cb_4_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui->Xin_xi_luru_cb_4,checkbox_event_hander2_2,LV_EVENT_ALL,NULL);  //设置回调显示

	//Write codes Xin_xi_luru_cb_5
	ui->Xin_xi_luru_cb_5 = lv_checkbox_create(ui->Xin_xi_luru_tileview_1_tile_2);
	lv_obj_set_pos(ui->Xin_xi_luru_cb_5, 190, 99);
	lv_obj_set_scrollbar_mode(ui->Xin_xi_luru_cb_5, LV_SCROLLBAR_MODE_OFF);
	lv_checkbox_set_text(ui->Xin_xi_luru_cb_5, "羚羊");

	//Write style state: LV_STATE_DEFAULT for style_xin_xi_luru_cb_5_main_main_default
	static lv_style_t style_xin_xi_luru_cb_5_main_main_default;
	if (style_xin_xi_luru_cb_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_xin_xi_luru_cb_5_main_main_default);
	else
		lv_style_init(&style_xin_xi_luru_cb_5_main_main_default);
	lv_style_set_radius(&style_xin_xi_luru_cb_5_main_main_default, 6);
	lv_style_set_bg_color(&style_xin_xi_luru_cb_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_xin_xi_luru_cb_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_xin_xi_luru_cb_5_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_xin_xi_luru_cb_5_main_main_default, 255);
	lv_style_set_text_color(&style_xin_xi_luru_cb_5_main_main_default, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_xin_xi_luru_cb_5_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_xin_xi_luru_cb_5_main_main_default, 2);
	lv_obj_add_style(ui->Xin_xi_luru_cb_5, &style_xin_xi_luru_cb_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_xin_xi_luru_cb_5_main_indicator_default
	static lv_style_t style_xin_xi_luru_cb_5_main_indicator_default;
	if (style_xin_xi_luru_cb_5_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_xin_xi_luru_cb_5_main_indicator_default);
	else
		lv_style_init(&style_xin_xi_luru_cb_5_main_indicator_default);
	lv_style_set_radius(&style_xin_xi_luru_cb_5_main_indicator_default, 6);
	lv_style_set_bg_color(&style_xin_xi_luru_cb_5_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_xin_xi_luru_cb_5_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_xin_xi_luru_cb_5_main_indicator_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_xin_xi_luru_cb_5_main_indicator_default, 255);
	lv_style_set_border_color(&style_xin_xi_luru_cb_5_main_indicator_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_xin_xi_luru_cb_5_main_indicator_default, 2);
	lv_style_set_border_opa(&style_xin_xi_luru_cb_5_main_indicator_default, 255);
	lv_obj_add_style(ui->Xin_xi_luru_cb_5, &style_xin_xi_luru_cb_5_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui->Xin_xi_luru_cb_5,checkbox_event_hander2_3,LV_EVENT_ALL,NULL);  //设置回调显示



	//Write codes Xin_xi_luru_cb_6
	ui->Xin_xi_luru_cb_6 = lv_checkbox_create(ui->Xin_xi_luru_tileview_1_tile_2);
	lv_obj_set_pos(ui->Xin_xi_luru_cb_6, 190, 138);
	lv_obj_set_scrollbar_mode(ui->Xin_xi_luru_cb_6, LV_SCROLLBAR_MODE_OFF);
	lv_checkbox_set_text(ui->Xin_xi_luru_cb_6, "杜泊羊");

	//Write style state: LV_STATE_DEFAULT for style_xin_xi_luru_cb_6_main_main_default
	static lv_style_t style_xin_xi_luru_cb_6_main_main_default;
	if (style_xin_xi_luru_cb_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_xin_xi_luru_cb_6_main_main_default);
	else
		lv_style_init(&style_xin_xi_luru_cb_6_main_main_default);
	lv_style_set_radius(&style_xin_xi_luru_cb_6_main_main_default, 6);
	lv_style_set_bg_color(&style_xin_xi_luru_cb_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_xin_xi_luru_cb_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_xin_xi_luru_cb_6_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_xin_xi_luru_cb_6_main_main_default, 255);
	lv_style_set_text_color(&style_xin_xi_luru_cb_6_main_main_default, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_xin_xi_luru_cb_6_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_xin_xi_luru_cb_6_main_main_default, 2);
	lv_obj_add_style(ui->Xin_xi_luru_cb_6, &style_xin_xi_luru_cb_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_xin_xi_luru_cb_6_main_indicator_default
	static lv_style_t style_xin_xi_luru_cb_6_main_indicator_default;
	if (style_xin_xi_luru_cb_6_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_xin_xi_luru_cb_6_main_indicator_default);
	else
		lv_style_init(&style_xin_xi_luru_cb_6_main_indicator_default);
	lv_style_set_radius(&style_xin_xi_luru_cb_6_main_indicator_default, 6);
	lv_style_set_bg_color(&style_xin_xi_luru_cb_6_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_xin_xi_luru_cb_6_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_xin_xi_luru_cb_6_main_indicator_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_xin_xi_luru_cb_6_main_indicator_default, 255);
	lv_style_set_border_color(&style_xin_xi_luru_cb_6_main_indicator_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_xin_xi_luru_cb_6_main_indicator_default, 2);
	lv_style_set_border_opa(&style_xin_xi_luru_cb_6_main_indicator_default, 255);
	lv_obj_add_style(ui->Xin_xi_luru_cb_6, &style_xin_xi_luru_cb_6_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui->Xin_xi_luru_cb_6,checkbox_event_hander2_4,LV_EVENT_ALL,NULL);  //设置回调显示
	
	//Write codes Xin_xi_luru_cb_7
	ui->Xin_xi_luru_cb_7 = lv_checkbox_create(ui->Xin_xi_luru_tileview_1_tile_2);
	lv_obj_set_pos(ui->Xin_xi_luru_cb_7, 190, 178);
	lv_obj_set_scrollbar_mode(ui->Xin_xi_luru_cb_7, LV_SCROLLBAR_MODE_OFF);
	lv_checkbox_set_text(ui->Xin_xi_luru_cb_7, "黑山羊");

	//Write style state: LV_STATE_DEFAULT for style_xin_xi_luru_cb_7_main_main_default
	static lv_style_t style_xin_xi_luru_cb_7_main_main_default;
	if (style_xin_xi_luru_cb_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_xin_xi_luru_cb_7_main_main_default);
	else
		lv_style_init(&style_xin_xi_luru_cb_7_main_main_default);
	lv_style_set_radius(&style_xin_xi_luru_cb_7_main_main_default, 6);
	lv_style_set_bg_color(&style_xin_xi_luru_cb_7_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_xin_xi_luru_cb_7_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_xin_xi_luru_cb_7_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_xin_xi_luru_cb_7_main_main_default, 255);
	lv_style_set_text_color(&style_xin_xi_luru_cb_7_main_main_default, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_xin_xi_luru_cb_7_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_xin_xi_luru_cb_7_main_main_default, 2);
	lv_obj_add_style(ui->Xin_xi_luru_cb_7, &style_xin_xi_luru_cb_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_xin_xi_luru_cb_7_main_indicator_default
	static lv_style_t style_xin_xi_luru_cb_7_main_indicator_default;
	if (style_xin_xi_luru_cb_7_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_xin_xi_luru_cb_7_main_indicator_default);
	else
		lv_style_init(&style_xin_xi_luru_cb_7_main_indicator_default);
	lv_style_set_radius(&style_xin_xi_luru_cb_7_main_indicator_default, 6);
	lv_style_set_bg_color(&style_xin_xi_luru_cb_7_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_xin_xi_luru_cb_7_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_xin_xi_luru_cb_7_main_indicator_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_xin_xi_luru_cb_7_main_indicator_default, 255);
	lv_style_set_border_color(&style_xin_xi_luru_cb_7_main_indicator_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_xin_xi_luru_cb_7_main_indicator_default, 2);
	lv_style_set_border_opa(&style_xin_xi_luru_cb_7_main_indicator_default, 255);
	lv_obj_add_style(ui->Xin_xi_luru_cb_7, &style_xin_xi_luru_cb_7_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write codes Xin_xi_luru_cb_8
	ui->Xin_xi_luru_cb_8 = lv_checkbox_create(ui->Xin_xi_luru_tileview_1_tile_2);
	lv_obj_set_pos(ui->Xin_xi_luru_cb_8, 313, 21);
	lv_obj_set_scrollbar_mode(ui->Xin_xi_luru_cb_8, LV_SCROLLBAR_MODE_OFF);
	lv_checkbox_set_text(ui->Xin_xi_luru_cb_8, "食用羊");

	//Write style state: LV_STATE_DEFAULT for style_xin_xi_luru_cb_8_main_main_default
	static lv_style_t style_xin_xi_luru_cb_8_main_main_default;
	if (style_xin_xi_luru_cb_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_xin_xi_luru_cb_8_main_main_default);
	else
		lv_style_init(&style_xin_xi_luru_cb_8_main_main_default);
	lv_style_set_radius(&style_xin_xi_luru_cb_8_main_main_default, 6);
	lv_style_set_bg_color(&style_xin_xi_luru_cb_8_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_xin_xi_luru_cb_8_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_xin_xi_luru_cb_8_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_xin_xi_luru_cb_8_main_main_default, 255);
	lv_style_set_text_color(&style_xin_xi_luru_cb_8_main_main_default, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_xin_xi_luru_cb_8_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_xin_xi_luru_cb_8_main_main_default, 2);
	lv_obj_add_style(ui->Xin_xi_luru_cb_8, &style_xin_xi_luru_cb_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_xin_xi_luru_cb_8_main_indicator_default
	static lv_style_t style_xin_xi_luru_cb_8_main_indicator_default;
	if (style_xin_xi_luru_cb_8_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_xin_xi_luru_cb_8_main_indicator_default);
	else
		lv_style_init(&style_xin_xi_luru_cb_8_main_indicator_default);
	lv_style_set_radius(&style_xin_xi_luru_cb_8_main_indicator_default, 6);
	lv_style_set_bg_color(&style_xin_xi_luru_cb_8_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_xin_xi_luru_cb_8_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_xin_xi_luru_cb_8_main_indicator_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_xin_xi_luru_cb_8_main_indicator_default, 255);
	lv_style_set_border_color(&style_xin_xi_luru_cb_8_main_indicator_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_xin_xi_luru_cb_8_main_indicator_default, 2);
	lv_style_set_border_opa(&style_xin_xi_luru_cb_8_main_indicator_default, 255);
	lv_obj_add_style(ui->Xin_xi_luru_cb_8, &style_xin_xi_luru_cb_8_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write codes Xin_xi_luru_cb_9
	ui->Xin_xi_luru_cb_9 = lv_checkbox_create(ui->Xin_xi_luru_tileview_1_tile_2);
	lv_obj_set_pos(ui->Xin_xi_luru_cb_9, 314, 60);
	lv_obj_set_scrollbar_mode(ui->Xin_xi_luru_cb_9, LV_SCROLLBAR_MODE_OFF);
	lv_checkbox_set_text(ui->Xin_xi_luru_cb_9, "产毛羊");

	//Write style state: LV_STATE_DEFAULT for style_xin_xi_luru_cb_9_main_main_default
	static lv_style_t style_xin_xi_luru_cb_9_main_main_default;
	if (style_xin_xi_luru_cb_9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_xin_xi_luru_cb_9_main_main_default);
	else
		lv_style_init(&style_xin_xi_luru_cb_9_main_main_default);
	lv_style_set_radius(&style_xin_xi_luru_cb_9_main_main_default, 6);
	lv_style_set_bg_color(&style_xin_xi_luru_cb_9_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_xin_xi_luru_cb_9_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_xin_xi_luru_cb_9_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_xin_xi_luru_cb_9_main_main_default, 255);
	lv_style_set_text_color(&style_xin_xi_luru_cb_9_main_main_default, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_xin_xi_luru_cb_9_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_xin_xi_luru_cb_9_main_main_default, 2);
	lv_obj_add_style(ui->Xin_xi_luru_cb_9, &style_xin_xi_luru_cb_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_xin_xi_luru_cb_9_main_indicator_default
	static lv_style_t style_xin_xi_luru_cb_9_main_indicator_default;
	if (style_xin_xi_luru_cb_9_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_xin_xi_luru_cb_9_main_indicator_default);
	else
		lv_style_init(&style_xin_xi_luru_cb_9_main_indicator_default);
	lv_style_set_radius(&style_xin_xi_luru_cb_9_main_indicator_default, 6);
	lv_style_set_bg_color(&style_xin_xi_luru_cb_9_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_xin_xi_luru_cb_9_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_xin_xi_luru_cb_9_main_indicator_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_xin_xi_luru_cb_9_main_indicator_default, 255);
	lv_style_set_border_color(&style_xin_xi_luru_cb_9_main_indicator_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_xin_xi_luru_cb_9_main_indicator_default, 2);
	lv_style_set_border_opa(&style_xin_xi_luru_cb_9_main_indicator_default, 255);
	lv_obj_add_style(ui->Xin_xi_luru_cb_9, &style_xin_xi_luru_cb_9_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//add new tile Xin_xi_luru_tileview_1_tile_1
	ui->Xin_xi_luru_tileview_1_tile_1 = lv_tileview_add_tile(ui->Xin_xi_luru_tileview_1, 0, 0, LV_DIR_BOTTOM);

	//Write codes Xin_xi_luru_label_1
	ui->Xin_xi_luru_label_1 = lv_label_create(ui->Xin_xi_luru_tileview_1_tile_1);
	lv_obj_set_pos(ui->Xin_xi_luru_label_1, 17, 25);
	lv_obj_set_size(ui->Xin_xi_luru_label_1, 138, 32);
	lv_obj_set_scrollbar_mode(ui->Xin_xi_luru_label_1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->Xin_xi_luru_label_1, "耳标：");
	lv_label_set_long_mode(ui->Xin_xi_luru_label_1, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_xin_xi_luru_label_1_main_main_default
	static lv_style_t style_xin_xi_luru_label_1_main_main_default;
	if (style_xin_xi_luru_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_xin_xi_luru_label_1_main_main_default);
	else
		lv_style_init(&style_xin_xi_luru_label_1_main_main_default);
	lv_style_set_radius(&style_xin_xi_luru_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_xin_xi_luru_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_xin_xi_luru_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_xin_xi_luru_label_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_xin_xi_luru_label_1_main_main_default, 115);
	lv_style_set_text_color(&style_xin_xi_luru_label_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_xin_xi_luru_label_1_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_xin_xi_luru_label_1_main_main_default, 2);
	lv_style_set_text_line_space(&style_xin_xi_luru_label_1_main_main_default, 0);
	lv_style_set_text_align(&style_xin_xi_luru_label_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_xin_xi_luru_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_xin_xi_luru_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_xin_xi_luru_label_1_main_main_default, 8);
	lv_style_set_pad_bottom(&style_xin_xi_luru_label_1_main_main_default, 0);
	lv_obj_add_style(ui->Xin_xi_luru_label_1, &style_xin_xi_luru_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Xin_xi_luru_label_2
	ui->Xin_xi_luru_label_2 = lv_label_create(ui->Xin_xi_luru_tileview_1_tile_1);
	lv_obj_set_pos(ui->Xin_xi_luru_label_2, 16, 74);
	lv_obj_set_size(ui->Xin_xi_luru_label_2, 138, 32);
	lv_obj_set_scrollbar_mode(ui->Xin_xi_luru_label_2, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->Xin_xi_luru_label_2, "羊龄/月：");
	lv_label_set_long_mode(ui->Xin_xi_luru_label_2, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_xin_xi_luru_label_2_main_main_default
	static lv_style_t style_xin_xi_luru_label_2_main_main_default;
	if (style_xin_xi_luru_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_xin_xi_luru_label_2_main_main_default);
	else
		lv_style_init(&style_xin_xi_luru_label_2_main_main_default);
	lv_style_set_radius(&style_xin_xi_luru_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_xin_xi_luru_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_xin_xi_luru_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_xin_xi_luru_label_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_xin_xi_luru_label_2_main_main_default, 124);
	lv_style_set_text_color(&style_xin_xi_luru_label_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_xin_xi_luru_label_2_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_xin_xi_luru_label_2_main_main_default, 2);
	lv_style_set_text_line_space(&style_xin_xi_luru_label_2_main_main_default, 0);
	lv_style_set_text_align(&style_xin_xi_luru_label_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_xin_xi_luru_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_xin_xi_luru_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_xin_xi_luru_label_2_main_main_default, 8);
	lv_style_set_pad_bottom(&style_xin_xi_luru_label_2_main_main_default, 0);
	lv_obj_add_style(ui->Xin_xi_luru_label_2, &style_xin_xi_luru_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Xin_xi_luru_label_3
	ui->Xin_xi_luru_label_3 = lv_label_create(ui->Xin_xi_luru_tileview_1_tile_1);
	lv_obj_set_pos(ui->Xin_xi_luru_label_3, 18, 128);
	lv_obj_set_size(ui->Xin_xi_luru_label_3, 138, 32);
	lv_obj_set_scrollbar_mode(ui->Xin_xi_luru_label_3, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->Xin_xi_luru_label_3, "体重/kg：");
	lv_label_set_long_mode(ui->Xin_xi_luru_label_3, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_xin_xi_luru_label_3_main_main_default
	static lv_style_t style_xin_xi_luru_label_3_main_main_default;
	if (style_xin_xi_luru_label_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_xin_xi_luru_label_3_main_main_default);
	else
		lv_style_init(&style_xin_xi_luru_label_3_main_main_default);
	lv_style_set_radius(&style_xin_xi_luru_label_3_main_main_default, 0);
	lv_style_set_bg_color(&style_xin_xi_luru_label_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_xin_xi_luru_label_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_xin_xi_luru_label_3_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_xin_xi_luru_label_3_main_main_default, 115);
	lv_style_set_text_color(&style_xin_xi_luru_label_3_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_xin_xi_luru_label_3_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_xin_xi_luru_label_3_main_main_default, 2);
	lv_style_set_text_line_space(&style_xin_xi_luru_label_3_main_main_default, 0);
	lv_style_set_text_align(&style_xin_xi_luru_label_3_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_xin_xi_luru_label_3_main_main_default, 0);
	lv_style_set_pad_right(&style_xin_xi_luru_label_3_main_main_default, 0);
	lv_style_set_pad_top(&style_xin_xi_luru_label_3_main_main_default, 8);
	lv_style_set_pad_bottom(&style_xin_xi_luru_label_3_main_main_default, 0);
	lv_obj_add_style(ui->Xin_xi_luru_label_3, &style_xin_xi_luru_label_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Xin_xi_luru_label_5
	ui->Xin_xi_luru_label_5 = lv_label_create(ui->Xin_xi_luru_tileview_1_tile_1);
	lv_obj_set_pos(ui->Xin_xi_luru_label_5, 197, 27);
	lv_obj_set_size(ui->Xin_xi_luru_label_5, 129, 32);
	lv_obj_set_scrollbar_mode(ui->Xin_xi_luru_label_5, LV_SCROLLBAR_MODE_OFF);
	//lv_label_set_text(ui->Xin_xi_luru_label_5, "xxxxxx");
	lv_label_set_text_fmt(ui->Xin_xi_luru_label_5,"%d",ear_id_n);
	lv_label_set_long_mode(ui->Xin_xi_luru_label_5, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_xin_xi_luru_label_5_main_main_default
	static lv_style_t style_xin_xi_luru_label_5_main_main_default;
	if (style_xin_xi_luru_label_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_xin_xi_luru_label_5_main_main_default);
	else
		lv_style_init(&style_xin_xi_luru_label_5_main_main_default);
	lv_style_set_radius(&style_xin_xi_luru_label_5_main_main_default, 0);
	lv_style_set_bg_color(&style_xin_xi_luru_label_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_xin_xi_luru_label_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_xin_xi_luru_label_5_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_xin_xi_luru_label_5_main_main_default, 255);
	lv_style_set_text_color(&style_xin_xi_luru_label_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_xin_xi_luru_label_5_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_xin_xi_luru_label_5_main_main_default, 2);
	lv_style_set_text_line_space(&style_xin_xi_luru_label_5_main_main_default, 0);
	lv_style_set_text_align(&style_xin_xi_luru_label_5_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_xin_xi_luru_label_5_main_main_default, 0);
	lv_style_set_pad_right(&style_xin_xi_luru_label_5_main_main_default, 0);
	lv_style_set_pad_top(&style_xin_xi_luru_label_5_main_main_default, 8);
	lv_style_set_pad_bottom(&style_xin_xi_luru_label_5_main_main_default, 0);
	lv_obj_add_style(ui->Xin_xi_luru_label_5, &style_xin_xi_luru_label_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Xin_xi_luru_ta_1
	ui->Xin_xi_luru_ta_1 = lv_textarea_create(ui->Xin_xi_luru_tileview_1_tile_1);
	lv_obj_set_pos(ui->Xin_xi_luru_ta_1, 198, 75);
	lv_obj_set_size(ui->Xin_xi_luru_ta_1, 132, 30);
	lv_obj_set_scrollbar_mode(ui->Xin_xi_luru_ta_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_xin_xi_luru_ta_1_main_main_default
	static lv_style_t style_xin_xi_luru_ta_1_main_main_default;
	if (style_xin_xi_luru_ta_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_xin_xi_luru_ta_1_main_main_default);
	else
		lv_style_init(&style_xin_xi_luru_ta_1_main_main_default);
	lv_style_set_radius(&style_xin_xi_luru_ta_1_main_main_default, 4);
	lv_style_set_bg_color(&style_xin_xi_luru_ta_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_xin_xi_luru_ta_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_xin_xi_luru_ta_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_xin_xi_luru_ta_1_main_main_default, 255);
	lv_style_set_border_color(&style_xin_xi_luru_ta_1_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_border_width(&style_xin_xi_luru_ta_1_main_main_default, 2);
	lv_style_set_border_opa(&style_xin_xi_luru_ta_1_main_main_default, 255);
	lv_style_set_text_color(&style_xin_xi_luru_ta_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_xin_xi_luru_ta_1_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_xin_xi_luru_ta_1_main_main_default, 2);
	lv_style_set_text_align(&style_xin_xi_luru_ta_1_main_main_default, LV_TEXT_ALIGN_LEFT);
	lv_style_set_pad_left(&style_xin_xi_luru_ta_1_main_main_default, 4);
	lv_style_set_pad_right(&style_xin_xi_luru_ta_1_main_main_default, 4);
	lv_style_set_pad_top(&style_xin_xi_luru_ta_1_main_main_default, 4);
	lv_style_set_pad_bottom(&style_xin_xi_luru_ta_1_main_main_default, 4);
	lv_obj_add_style(ui->Xin_xi_luru_ta_1, &style_xin_xi_luru_ta_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_xin_xi_luru_ta_1_main_scrollbar_default
	static lv_style_t style_xin_xi_luru_ta_1_main_scrollbar_default;
	if (style_xin_xi_luru_ta_1_main_scrollbar_default.prop_cnt > 1)
		lv_style_reset(&style_xin_xi_luru_ta_1_main_scrollbar_default);
	else
		lv_style_init(&style_xin_xi_luru_ta_1_main_scrollbar_default);
	lv_style_set_radius(&style_xin_xi_luru_ta_1_main_scrollbar_default, 0);
	lv_style_set_bg_color(&style_xin_xi_luru_ta_1_main_scrollbar_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_xin_xi_luru_ta_1_main_scrollbar_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_xin_xi_luru_ta_1_main_scrollbar_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_xin_xi_luru_ta_1_main_scrollbar_default, 255);
	lv_obj_add_style(ui->Xin_xi_luru_ta_1, &style_xin_xi_luru_ta_1_main_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_textarea_set_text(ui->Xin_xi_luru_ta_1,"6");
	g_kb = lv_keyboard_create(ui->Xin_xi_luru_tileview_1_tile_1);
	lv_obj_add_event_cb(g_kb, kb_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_add_flag(g_kb, LV_OBJ_FLAG_HIDDEN);
	lv_keyboard_set_textarea(g_kb, ui->Xin_xi_luru_ta_1);
	lv_obj_add_event_cb(ui->Xin_xi_luru_ta_1, ta_event_cb, LV_EVENT_ALL, g_kb);

	//Write codes Xin_xi_luru_ta_2
	ui->Xin_xi_luru_ta_2 = lv_textarea_create(ui->Xin_xi_luru_tileview_1_tile_1);
	lv_obj_set_pos(ui->Xin_xi_luru_ta_2, 199, 130);
	lv_obj_set_size(ui->Xin_xi_luru_ta_2, 133, 30);
	lv_obj_set_scrollbar_mode(ui->Xin_xi_luru_ta_2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_xin_xi_luru_ta_2_main_main_default
	static lv_style_t style_xin_xi_luru_ta_2_main_main_default;
	if (style_xin_xi_luru_ta_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_xin_xi_luru_ta_2_main_main_default);
	else
		lv_style_init(&style_xin_xi_luru_ta_2_main_main_default);
	lv_style_set_radius(&style_xin_xi_luru_ta_2_main_main_default, 4);
	lv_style_set_bg_color(&style_xin_xi_luru_ta_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_xin_xi_luru_ta_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_xin_xi_luru_ta_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_xin_xi_luru_ta_2_main_main_default, 255);
	lv_style_set_border_color(&style_xin_xi_luru_ta_2_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_border_width(&style_xin_xi_luru_ta_2_main_main_default, 2);
	lv_style_set_border_opa(&style_xin_xi_luru_ta_2_main_main_default, 255);
	lv_style_set_text_color(&style_xin_xi_luru_ta_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_xin_xi_luru_ta_2_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_xin_xi_luru_ta_2_main_main_default, 2);
	lv_style_set_text_align(&style_xin_xi_luru_ta_2_main_main_default, LV_TEXT_ALIGN_LEFT);
	lv_style_set_pad_left(&style_xin_xi_luru_ta_2_main_main_default, 4);
	lv_style_set_pad_right(&style_xin_xi_luru_ta_2_main_main_default, 4);
	lv_style_set_pad_top(&style_xin_xi_luru_ta_2_main_main_default, 4);
	lv_style_set_pad_bottom(&style_xin_xi_luru_ta_2_main_main_default, 4);
	lv_obj_add_style(ui->Xin_xi_luru_ta_2, &style_xin_xi_luru_ta_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_xin_xi_luru_ta_2_main_scrollbar_default
	static lv_style_t style_xin_xi_luru_ta_2_main_scrollbar_default;
	if (style_xin_xi_luru_ta_2_main_scrollbar_default.prop_cnt > 1)
		lv_style_reset(&style_xin_xi_luru_ta_2_main_scrollbar_default);
	else
		lv_style_init(&style_xin_xi_luru_ta_2_main_scrollbar_default);
	lv_style_set_radius(&style_xin_xi_luru_ta_2_main_scrollbar_default, 0);
	lv_style_set_bg_color(&style_xin_xi_luru_ta_2_main_scrollbar_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_xin_xi_luru_ta_2_main_scrollbar_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_xin_xi_luru_ta_2_main_scrollbar_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_xin_xi_luru_ta_2_main_scrollbar_default, 255);
	lv_obj_add_style(ui->Xin_xi_luru_ta_2, &style_xin_xi_luru_ta_2_main_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_textarea_set_text(ui->Xin_xi_luru_ta_2,"48");
	g_kb = lv_keyboard_create(ui->Xin_xi_luru_tileview_1_tile_1);
	lv_obj_add_event_cb(g_kb, kb_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_add_flag(g_kb, LV_OBJ_FLAG_HIDDEN);
	lv_keyboard_set_textarea(g_kb, ui->Xin_xi_luru_ta_2);
	lv_obj_add_event_cb(ui->Xin_xi_luru_ta_2, ta_event_cb2, LV_EVENT_ALL, g_kb);

	//Write codes Xin_xi_luru_label_8
	ui->Xin_xi_luru_label_8 = lv_label_create(ui->Xin_xi_luru_tileview_1_tile_1);
	lv_obj_set_pos(ui->Xin_xi_luru_label_8, 18, 184);
	lv_obj_set_size(ui->Xin_xi_luru_label_8, 138, 32);
	lv_obj_set_scrollbar_mode(ui->Xin_xi_luru_label_8, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->Xin_xi_luru_label_8, "养殖地信息：");
	lv_label_set_long_mode(ui->Xin_xi_luru_label_8, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_xin_xi_luru_label_8_main_main_default
	static lv_style_t style_xin_xi_luru_label_8_main_main_default;
	if (style_xin_xi_luru_label_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_xin_xi_luru_label_8_main_main_default);
	else
		lv_style_init(&style_xin_xi_luru_label_8_main_main_default);
	lv_style_set_radius(&style_xin_xi_luru_label_8_main_main_default, 0);
	lv_style_set_bg_color(&style_xin_xi_luru_label_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_xin_xi_luru_label_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_xin_xi_luru_label_8_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_xin_xi_luru_label_8_main_main_default, 115);
	lv_style_set_text_color(&style_xin_xi_luru_label_8_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_xin_xi_luru_label_8_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_xin_xi_luru_label_8_main_main_default, 2);
	lv_style_set_text_line_space(&style_xin_xi_luru_label_8_main_main_default, 0);
	lv_style_set_text_align(&style_xin_xi_luru_label_8_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_xin_xi_luru_label_8_main_main_default, 0);
	lv_style_set_pad_right(&style_xin_xi_luru_label_8_main_main_default, 0);
	lv_style_set_pad_top(&style_xin_xi_luru_label_8_main_main_default, 8);
	lv_style_set_pad_bottom(&style_xin_xi_luru_label_8_main_main_default, 0);
	lv_obj_add_style(ui->Xin_xi_luru_label_8, &style_xin_xi_luru_label_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Xin_xi_luru_ta_3
	ui->Xin_xi_luru_ta_3 = lv_textarea_create(ui->Xin_xi_luru_tileview_1_tile_1);
	lv_obj_set_pos(ui->Xin_xi_luru_ta_3, 199, 184);
	lv_obj_set_size(ui->Xin_xi_luru_ta_3, 134, 30);
	lv_obj_set_scrollbar_mode(ui->Xin_xi_luru_ta_3, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_xin_xi_luru_ta_3_main_main_default
	static lv_style_t style_xin_xi_luru_ta_3_main_main_default;
	if (style_xin_xi_luru_ta_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_xin_xi_luru_ta_3_main_main_default);
	else
		lv_style_init(&style_xin_xi_luru_ta_3_main_main_default);
	lv_style_set_radius(&style_xin_xi_luru_ta_3_main_main_default, 4);
	lv_style_set_bg_color(&style_xin_xi_luru_ta_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_xin_xi_luru_ta_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_xin_xi_luru_ta_3_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_xin_xi_luru_ta_3_main_main_default, 255);
	lv_style_set_border_color(&style_xin_xi_luru_ta_3_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_border_width(&style_xin_xi_luru_ta_3_main_main_default, 2);
	lv_style_set_border_opa(&style_xin_xi_luru_ta_3_main_main_default, 255);
	lv_style_set_text_color(&style_xin_xi_luru_ta_3_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_xin_xi_luru_ta_3_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_xin_xi_luru_ta_3_main_main_default, 2);
	lv_style_set_text_align(&style_xin_xi_luru_ta_3_main_main_default, LV_TEXT_ALIGN_LEFT);
	lv_style_set_pad_left(&style_xin_xi_luru_ta_3_main_main_default, 4);
	lv_style_set_pad_right(&style_xin_xi_luru_ta_3_main_main_default, 4);
	lv_style_set_pad_top(&style_xin_xi_luru_ta_3_main_main_default, 4);
	lv_style_set_pad_bottom(&style_xin_xi_luru_ta_3_main_main_default, 4);
	lv_obj_add_style(ui->Xin_xi_luru_ta_3, &style_xin_xi_luru_ta_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_xin_xi_luru_ta_3_main_scrollbar_default
	static lv_style_t style_xin_xi_luru_ta_3_main_scrollbar_default;
	if (style_xin_xi_luru_ta_3_main_scrollbar_default.prop_cnt > 1)
		lv_style_reset(&style_xin_xi_luru_ta_3_main_scrollbar_default);
	else
		lv_style_init(&style_xin_xi_luru_ta_3_main_scrollbar_default);
	lv_style_set_radius(&style_xin_xi_luru_ta_3_main_scrollbar_default, 0);
	lv_style_set_bg_color(&style_xin_xi_luru_ta_3_main_scrollbar_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_xin_xi_luru_ta_3_main_scrollbar_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_xin_xi_luru_ta_3_main_scrollbar_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_xin_xi_luru_ta_3_main_scrollbar_default, 255);
	lv_obj_add_style(ui->Xin_xi_luru_ta_3, &style_xin_xi_luru_ta_3_main_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_textarea_set_text(ui->Xin_xi_luru_ta_3,"EXU绵羊养殖基地");
	g_kb = lv_keyboard_create(ui->Xin_xi_luru_tileview_1_tile_1);
	lv_obj_add_event_cb(g_kb, kb_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_add_flag(g_kb, LV_OBJ_FLAG_HIDDEN);
	lv_keyboard_set_textarea(g_kb, ui->Xin_xi_luru_ta_3);
	lv_obj_add_event_cb(ui->Xin_xi_luru_ta_3, ta_event_cb, LV_EVENT_ALL, g_kb);

	//Write codes Xin_xi_luru_btn_1
	ui->Xin_xi_luru_btn_1 = lv_btn_create(ui->Xin_xi_luru);
	lv_obj_set_pos(ui->Xin_xi_luru_btn_1, 299, 9);
	lv_obj_set_size(ui->Xin_xi_luru_btn_1, 72, 32);
	lv_obj_set_scrollbar_mode(ui->Xin_xi_luru_btn_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_xin_xi_luru_btn_1_main_main_default
	static lv_style_t style_xin_xi_luru_btn_1_main_main_default;
	if (style_xin_xi_luru_btn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_xin_xi_luru_btn_1_main_main_default);
	else
		lv_style_init(&style_xin_xi_luru_btn_1_main_main_default);
	lv_style_set_radius(&style_xin_xi_luru_btn_1_main_main_default, 5);
	lv_style_set_bg_color(&style_xin_xi_luru_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_xin_xi_luru_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_xin_xi_luru_btn_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_xin_xi_luru_btn_1_main_main_default, 255);
	lv_style_set_border_color(&style_xin_xi_luru_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_xin_xi_luru_btn_1_main_main_default, 0);
	lv_style_set_border_opa(&style_xin_xi_luru_btn_1_main_main_default, 255);
	lv_style_set_text_color(&style_xin_xi_luru_btn_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_xin_xi_luru_btn_1_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_align(&style_xin_xi_luru_btn_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->Xin_xi_luru_btn_1, &style_xin_xi_luru_btn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->Xin_xi_luru_btn_1_label = lv_label_create(ui->Xin_xi_luru_btn_1);
	lv_label_set_text(ui->Xin_xi_luru_btn_1_label, "取消");
	lv_obj_set_style_pad_all(ui->Xin_xi_luru_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->Xin_xi_luru_btn_1_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes Xin_xi_luru_btn_2
	ui->Xin_xi_luru_btn_2 = lv_btn_create(ui->Xin_xi_luru);
	lv_obj_set_pos(ui->Xin_xi_luru_btn_2, 388, 8);
	lv_obj_set_size(ui->Xin_xi_luru_btn_2, 72, 32);
	lv_obj_set_scrollbar_mode(ui->Xin_xi_luru_btn_2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_xin_xi_luru_btn_2_main_main_default
	static lv_style_t style_xin_xi_luru_btn_2_main_main_default;
	if (style_xin_xi_luru_btn_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_xin_xi_luru_btn_2_main_main_default);
	else
		lv_style_init(&style_xin_xi_luru_btn_2_main_main_default);
	lv_style_set_radius(&style_xin_xi_luru_btn_2_main_main_default, 5);
	lv_style_set_bg_color(&style_xin_xi_luru_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_xin_xi_luru_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_xin_xi_luru_btn_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_xin_xi_luru_btn_2_main_main_default, 255);
	lv_style_set_border_color(&style_xin_xi_luru_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_xin_xi_luru_btn_2_main_main_default, 0);
	lv_style_set_border_opa(&style_xin_xi_luru_btn_2_main_main_default, 255);
	lv_style_set_text_color(&style_xin_xi_luru_btn_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_xin_xi_luru_btn_2_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_align(&style_xin_xi_luru_btn_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->Xin_xi_luru_btn_2, &style_xin_xi_luru_btn_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->Xin_xi_luru_btn_2_label = lv_label_create(ui->Xin_xi_luru_btn_2);
	lv_label_set_text(ui->Xin_xi_luru_btn_2_label, "确定");
	lv_obj_set_style_pad_all(ui->Xin_xi_luru_btn_2, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->Xin_xi_luru_btn_2_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes Xin_xi_luru_imgbtn_1
	ui->Xin_xi_luru_imgbtn_1 = lv_imgbtn_create(ui->Xin_xi_luru);
	lv_obj_set_pos(ui->Xin_xi_luru_imgbtn_1, 1, 1);
	lv_obj_set_size(ui->Xin_xi_luru_imgbtn_1, 32, 32);
	lv_obj_set_scrollbar_mode(ui->Xin_xi_luru_imgbtn_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_xin_xi_luru_imgbtn_1_main_main_default
	static lv_style_t style_xin_xi_luru_imgbtn_1_main_main_default;
	if (style_xin_xi_luru_imgbtn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_xin_xi_luru_imgbtn_1_main_main_default);
	else
		lv_style_init(&style_xin_xi_luru_imgbtn_1_main_main_default);
	lv_style_set_text_color(&style_xin_xi_luru_imgbtn_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_xin_xi_luru_imgbtn_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_xin_xi_luru_imgbtn_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_xin_xi_luru_imgbtn_1_main_main_default, 0);
	lv_style_set_img_opa(&style_xin_xi_luru_imgbtn_1_main_main_default, 255);
	lv_obj_add_style(ui->Xin_xi_luru_imgbtn_1, &style_xin_xi_luru_imgbtn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_xin_xi_luru_imgbtn_1_main_main_pressed
	static lv_style_t style_xin_xi_luru_imgbtn_1_main_main_pressed;
	if (style_xin_xi_luru_imgbtn_1_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_xin_xi_luru_imgbtn_1_main_main_pressed);
	else
		lv_style_init(&style_xin_xi_luru_imgbtn_1_main_main_pressed);
	lv_style_set_text_color(&style_xin_xi_luru_imgbtn_1_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_xin_xi_luru_imgbtn_1_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_xin_xi_luru_imgbtn_1_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_xin_xi_luru_imgbtn_1_main_main_pressed, 0);
	lv_style_set_img_opa(&style_xin_xi_luru_imgbtn_1_main_main_pressed, 255);
	lv_obj_add_style(ui->Xin_xi_luru_imgbtn_1, &style_xin_xi_luru_imgbtn_1_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_xin_xi_luru_imgbtn_1_main_main_checked
	static lv_style_t style_xin_xi_luru_imgbtn_1_main_main_checked;
	if (style_xin_xi_luru_imgbtn_1_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_xin_xi_luru_imgbtn_1_main_main_checked);
	else
		lv_style_init(&style_xin_xi_luru_imgbtn_1_main_main_checked);
	lv_style_set_text_color(&style_xin_xi_luru_imgbtn_1_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_xin_xi_luru_imgbtn_1_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_xin_xi_luru_imgbtn_1_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_xin_xi_luru_imgbtn_1_main_main_checked, 0);
	lv_style_set_img_opa(&style_xin_xi_luru_imgbtn_1_main_main_checked, 255);
	lv_obj_add_style(ui->Xin_xi_luru_imgbtn_1, &style_xin_xi_luru_imgbtn_1_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->Xin_xi_luru_imgbtn_1, LV_IMGBTN_STATE_RELEASED, NULL, &_fanhui2_alpha_32x32, NULL);
	lv_imgbtn_set_src(ui->Xin_xi_luru_imgbtn_1, LV_IMGBTN_STATE_PRESSED, NULL, &_fanhui2_alpha_32x32, NULL);
	lv_obj_add_flag(ui->Xin_xi_luru_imgbtn_1, LV_OBJ_FLAG_CHECKABLE);

	//Write codes Xin_xi_luru_btn_3
	ui->Xin_xi_luru_btn_3 = lv_btn_create(ui->Xin_xi_luru);
	lv_obj_set_pos(ui->Xin_xi_luru_btn_3, 205, 8);
	lv_obj_set_size(ui->Xin_xi_luru_btn_3, 72, 32);
	lv_obj_set_scrollbar_mode(ui->Xin_xi_luru_btn_3, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_xin_xi_luru_btn_3_main_main_default
	static lv_style_t style_xin_xi_luru_btn_3_main_main_default;
	if (style_xin_xi_luru_btn_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_xin_xi_luru_btn_3_main_main_default);
	else
		lv_style_init(&style_xin_xi_luru_btn_3_main_main_default);
	lv_style_set_radius(&style_xin_xi_luru_btn_3_main_main_default, 5);
	lv_style_set_bg_color(&style_xin_xi_luru_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_xin_xi_luru_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_xin_xi_luru_btn_3_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_xin_xi_luru_btn_3_main_main_default, 255);
	lv_style_set_border_color(&style_xin_xi_luru_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_xin_xi_luru_btn_3_main_main_default, 0);
	lv_style_set_border_opa(&style_xin_xi_luru_btn_3_main_main_default, 255);
	lv_style_set_text_color(&style_xin_xi_luru_btn_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_xin_xi_luru_btn_3_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_align(&style_xin_xi_luru_btn_3_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->Xin_xi_luru_btn_3, &style_xin_xi_luru_btn_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->Xin_xi_luru_btn_3_label = lv_label_create(ui->Xin_xi_luru_btn_3);
	lv_label_set_text(ui->Xin_xi_luru_btn_3_label, "刷新");
	lv_obj_set_style_pad_all(ui->Xin_xi_luru_btn_3, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->Xin_xi_luru_btn_3_label, LV_ALIGN_CENTER, 0, 0);

	//Init events for screen
	events_init_Xin_xi_luru(ui);
}