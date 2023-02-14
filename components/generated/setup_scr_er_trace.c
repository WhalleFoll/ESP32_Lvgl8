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

extern u_int32_t gui_id;
extern char *gui_species;
extern char *gui_sex;
extern char *gui_weight;
extern char *gui_sheep_age;
extern char *gui_use_value;
extern char *gui_place_of_production;
extern char *gui_vaccine;
extern char *gui_health;

u_int16_t tr_time_year;
u_int8_t tr_time_month;
u_int8_t tr_time_day;

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
	lv_obj_t *kb = lv_event_get_user_data(e);
	if (code == LV_EVENT_FOCUSED)
	{
		lv_keyboard_set_textarea(kb, ta);
		lv_obj_move_foreground(kb);
		lv_obj_clear_flag(kb, LV_OBJ_FLAG_HIDDEN);
	}
	if (code == LV_EVENT_DEFOCUSED)
	{
		lv_keyboard_set_textarea(kb, NULL);
		lv_obj_move_background(kb);
		lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
	}
}

/* static void ta_event_cb2(lv_event_t *e)
{

	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t *ta = lv_event_get_target(e);
    lv_obj_t *nn = lv_event_get_target(e);
	LV_UNUSED(nn);
	lv_obj_t *kb = lv_event_get_user_data(e);

	if (code == LV_EVENT_FOCUSED)
	{
		lv_keyboard_set_textarea(kb, ta);
		lv_obj_move_foreground(kb);
		lv_obj_clear_flag(kb, LV_OBJ_FLAG_HIDDEN);
	}
	if (code == LV_EVENT_DEFOCUSED)
	{   
		gui_weight = lv_textarea_get_text(nn);
	    printf("ti zhong is %s \n",gui_weight);
		lv_keyboard_set_textarea(kb, NULL);
		lv_obj_move_background(kb);
		lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
	}
} */

void setup_scr_er_trace(lv_ui *ui){

	//Write codes er_trace
	ui->er_trace = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->er_trace, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_er_trace_main_main_default
	static lv_style_t style_er_trace_main_main_default;
	if (style_er_trace_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_er_trace_main_main_default);
	else
		lv_style_init(&style_er_trace_main_main_default);
	lv_style_set_bg_color(&style_er_trace_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_er_trace_main_main_default, 0);
	lv_obj_add_style(ui->er_trace, &style_er_trace_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes er_trace_table_1
	ui->er_trace_table_1 = lv_table_create(ui->er_trace);
	lv_obj_set_pos(ui->er_trace_table_1, 12, 50);
	lv_obj_set_scrollbar_mode(ui->er_trace_table_1, LV_SCROLLBAR_MODE_ON);

	//Write style state: LV_STATE_DEFAULT for style_er_trace_table_1_main_main_default
	static lv_style_t style_er_trace_table_1_main_main_default;
	if (style_er_trace_table_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_er_trace_table_1_main_main_default);
	else
		lv_style_init(&style_er_trace_table_1_main_main_default);
	lv_style_set_radius(&style_er_trace_table_1_main_main_default, 1);
	lv_style_set_bg_color(&style_er_trace_table_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_er_trace_table_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_er_trace_table_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_er_trace_table_1_main_main_default, 255);
	lv_style_set_border_color(&style_er_trace_table_1_main_main_default, lv_color_make(0xd5, 0xde, 0xe6));
	lv_style_set_border_width(&style_er_trace_table_1_main_main_default, 0);
	lv_style_set_border_opa(&style_er_trace_table_1_main_main_default, 255);
	lv_style_set_pad_left(&style_er_trace_table_1_main_main_default, 0);
	lv_style_set_pad_right(&style_er_trace_table_1_main_main_default, 0);
	lv_style_set_pad_top(&style_er_trace_table_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_er_trace_table_1_main_main_default, 0);
	lv_obj_add_style(ui->er_trace_table_1, &style_er_trace_table_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_er_trace_table_1_main_items_default
	static lv_style_t style_er_trace_table_1_main_items_default;
	if (style_er_trace_table_1_main_items_default.prop_cnt > 1)
		lv_style_reset(&style_er_trace_table_1_main_items_default);
	else
		lv_style_init(&style_er_trace_table_1_main_items_default);
	lv_style_set_bg_color(&style_er_trace_table_1_main_items_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_er_trace_table_1_main_items_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_er_trace_table_1_main_items_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_er_trace_table_1_main_items_default, 0);
	lv_style_set_border_color(&style_er_trace_table_1_main_items_default, lv_color_make(0xd5, 0xde, 0xe6));
	lv_style_set_border_width(&style_er_trace_table_1_main_items_default, 3);
	lv_style_set_border_opa(&style_er_trace_table_1_main_items_default, 255);
	lv_style_set_text_color(&style_er_trace_table_1_main_items_default, lv_color_make(0x39, 0x3c, 0x41));
	lv_style_set_text_font(&style_er_trace_table_1_main_items_default, &lv_font_simsun_12);
	lv_style_set_text_decor(&style_er_trace_table_1_main_items_default, LV_TEXT_DECOR_NONE);
	lv_obj_add_style(ui->er_trace_table_1, &style_er_trace_table_1_main_items_default, LV_PART_ITEMS|LV_STATE_DEFAULT);
	lv_table_set_col_cnt(ui->er_trace_table_1,2);
	lv_table_set_row_cnt(ui->er_trace_table_1,8);
	lv_table_set_cell_value(ui->er_trace_table_1,0,0,"耳标");
	lv_table_set_cell_value(ui->er_trace_table_1,1,0,"品种");
	lv_table_set_cell_value(ui->er_trace_table_1,2,0,"公/母");
	lv_table_set_cell_value(ui->er_trace_table_1,3,0,"生产地");
	lv_table_set_cell_value(ui->er_trace_table_1,4,0,"疫苗接种次数");
	lv_table_set_cell_value(ui->er_trace_table_1,5,0,"健康状况");
	lv_table_set_cell_value(ui->er_trace_table_1,6,0,"日期");
	lv_table_set_cell_value(ui->er_trace_table_1,7,0,"养殖周期");

	//lv_table_set_cell_value(ui->er_trace_table_1,0,1,"1234567");
	lv_table_set_cell_value_fmt(ui->er_trace_table_1,0,1,"%d",gui_id);
	lv_table_set_cell_value(ui->er_trace_table_1,1,1,gui_species);
	lv_table_set_cell_value(ui->er_trace_table_1,2,1,gui_sex);
	lv_table_set_cell_value(ui->er_trace_table_1,3,1,gui_place_of_production);
	lv_table_set_cell_value(ui->er_trace_table_1,4,1,gui_vaccine);
	lv_table_set_cell_value(ui->er_trace_table_1,5,1,gui_health);
	//lv_table_set_cell_value(ui->er_trace_table_1,6,1,gui_sheep_age);
	//lv_table_set_cell_value(ui->er_trace_table_1,7,1,gui_weight);
	lv_table_set_cell_value_fmt(ui->er_trace_table_1,6,1,"%d-%d-%d",tr_time_year,tr_time_month,tr_time_day);
	lv_table_set_cell_value(ui->er_trace_table_1,7,1,"无");


	lv_obj_set_style_pad_left(ui->er_trace_table_1, 10, LV_PART_ITEMS|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->er_trace_table_1, 10, LV_PART_ITEMS|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->er_trace_table_1, 10, LV_PART_ITEMS|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->er_trace_table_1, 10, LV_PART_ITEMS|LV_STATE_DEFAULT);

	//Write codes er_trace_imgbtn_1
	ui->er_trace_imgbtn_1 = lv_imgbtn_create(ui->er_trace);
	lv_obj_set_pos(ui->er_trace_imgbtn_1, 2, 2);
	lv_obj_set_size(ui->er_trace_imgbtn_1, 37, 34);
	lv_obj_set_scrollbar_mode(ui->er_trace_imgbtn_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_er_trace_imgbtn_1_main_main_default
	static lv_style_t style_er_trace_imgbtn_1_main_main_default;
	if (style_er_trace_imgbtn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_er_trace_imgbtn_1_main_main_default);
	else
		lv_style_init(&style_er_trace_imgbtn_1_main_main_default);
	lv_style_set_text_color(&style_er_trace_imgbtn_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_er_trace_imgbtn_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_er_trace_imgbtn_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_er_trace_imgbtn_1_main_main_default, 0);
	lv_style_set_img_opa(&style_er_trace_imgbtn_1_main_main_default, 255);
	lv_obj_add_style(ui->er_trace_imgbtn_1, &style_er_trace_imgbtn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_er_trace_imgbtn_1_main_main_pressed
	static lv_style_t style_er_trace_imgbtn_1_main_main_pressed;
	if (style_er_trace_imgbtn_1_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_er_trace_imgbtn_1_main_main_pressed);
	else
		lv_style_init(&style_er_trace_imgbtn_1_main_main_pressed);
	lv_style_set_text_color(&style_er_trace_imgbtn_1_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_er_trace_imgbtn_1_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_er_trace_imgbtn_1_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_er_trace_imgbtn_1_main_main_pressed, 0);
	lv_style_set_img_opa(&style_er_trace_imgbtn_1_main_main_pressed, 255);
	lv_obj_add_style(ui->er_trace_imgbtn_1, &style_er_trace_imgbtn_1_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_er_trace_imgbtn_1_main_main_checked
	static lv_style_t style_er_trace_imgbtn_1_main_main_checked;
	if (style_er_trace_imgbtn_1_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_er_trace_imgbtn_1_main_main_checked);
	else
		lv_style_init(&style_er_trace_imgbtn_1_main_main_checked);
	lv_style_set_text_color(&style_er_trace_imgbtn_1_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_er_trace_imgbtn_1_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_er_trace_imgbtn_1_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_er_trace_imgbtn_1_main_main_checked, 0);
	lv_style_set_img_opa(&style_er_trace_imgbtn_1_main_main_checked, 255);
	lv_obj_add_style(ui->er_trace_imgbtn_1, &style_er_trace_imgbtn_1_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->er_trace_imgbtn_1, LV_IMGBTN_STATE_RELEASED, NULL, &_fanhui2_alpha_37x34, NULL);
	lv_imgbtn_set_src(ui->er_trace_imgbtn_1, LV_IMGBTN_STATE_PRESSED, NULL, &_fanhui2_alpha_37x34, NULL);
	lv_obj_add_flag(ui->er_trace_imgbtn_1, LV_OBJ_FLAG_CHECKABLE);

	//Write codes er_trace_ta_1
	ui->er_trace_ta_1 = lv_textarea_create(ui->er_trace);
	lv_obj_set_pos(ui->er_trace_ta_1, 295, 50);
	lv_obj_set_size(ui->er_trace_ta_1, 111, 29);
	lv_obj_set_scrollbar_mode(ui->er_trace_ta_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_er_trace_ta_1_main_main_default
	static lv_style_t style_er_trace_ta_1_main_main_default;
	if (style_er_trace_ta_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_er_trace_ta_1_main_main_default);
	else
		lv_style_init(&style_er_trace_ta_1_main_main_default);
	lv_style_set_radius(&style_er_trace_ta_1_main_main_default, 4);
	lv_style_set_bg_color(&style_er_trace_ta_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_er_trace_ta_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_er_trace_ta_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_er_trace_ta_1_main_main_default, 255);
	lv_style_set_border_color(&style_er_trace_ta_1_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_border_width(&style_er_trace_ta_1_main_main_default, 2);
	lv_style_set_border_opa(&style_er_trace_ta_1_main_main_default, 255);
	lv_style_set_text_color(&style_er_trace_ta_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_er_trace_ta_1_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_er_trace_ta_1_main_main_default, 2);
	lv_style_set_text_align(&style_er_trace_ta_1_main_main_default, LV_TEXT_ALIGN_LEFT);
	lv_style_set_pad_left(&style_er_trace_ta_1_main_main_default, 4);
	lv_style_set_pad_right(&style_er_trace_ta_1_main_main_default, 4);
	lv_style_set_pad_top(&style_er_trace_ta_1_main_main_default, 4);
	lv_style_set_pad_bottom(&style_er_trace_ta_1_main_main_default, 4);
	lv_obj_add_style(ui->er_trace_ta_1, &style_er_trace_ta_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_er_trace_ta_1_main_scrollbar_default
	static lv_style_t style_er_trace_ta_1_main_scrollbar_default;
	if (style_er_trace_ta_1_main_scrollbar_default.prop_cnt > 1)
		lv_style_reset(&style_er_trace_ta_1_main_scrollbar_default);
	else
		lv_style_init(&style_er_trace_ta_1_main_scrollbar_default);
	lv_style_set_radius(&style_er_trace_ta_1_main_scrollbar_default, 0);
	lv_style_set_bg_color(&style_er_trace_ta_1_main_scrollbar_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_er_trace_ta_1_main_scrollbar_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_er_trace_ta_1_main_scrollbar_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_er_trace_ta_1_main_scrollbar_default, 255);
	lv_obj_add_style(ui->er_trace_ta_1, &style_er_trace_ta_1_main_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_textarea_set_text(ui->er_trace_ta_1,"请输入耳标号");
	g_kb = lv_keyboard_create(ui->er_trace);
	lv_obj_add_event_cb(g_kb, kb_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_add_flag(g_kb, LV_OBJ_FLAG_HIDDEN);
	lv_keyboard_set_textarea(g_kb, ui->er_trace_ta_1);
	lv_obj_add_event_cb(ui->er_trace_ta_1, ta_event_cb, LV_EVENT_ALL, g_kb);

	//Write codes er_trace_btn_1
	ui->er_trace_btn_1 = lv_btn_create(ui->er_trace);
	lv_obj_set_pos(ui->er_trace_btn_1, 417, 50);
	lv_obj_set_size(ui->er_trace_btn_1, 40, 29);
	lv_obj_set_scrollbar_mode(ui->er_trace_btn_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_er_trace_btn_1_main_main_default
	static lv_style_t style_er_trace_btn_1_main_main_default;
	if (style_er_trace_btn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_er_trace_btn_1_main_main_default);
	else
		lv_style_init(&style_er_trace_btn_1_main_main_default);
	lv_style_set_radius(&style_er_trace_btn_1_main_main_default, 5);
	lv_style_set_bg_color(&style_er_trace_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_er_trace_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_er_trace_btn_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_er_trace_btn_1_main_main_default, 255);
	lv_style_set_border_color(&style_er_trace_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_er_trace_btn_1_main_main_default, 0);
	lv_style_set_border_opa(&style_er_trace_btn_1_main_main_default, 255);
	lv_style_set_text_color(&style_er_trace_btn_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_er_trace_btn_1_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_align(&style_er_trace_btn_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->er_trace_btn_1, &style_er_trace_btn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->er_trace_btn_1_label = lv_label_create(ui->er_trace_btn_1);
	lv_label_set_text(ui->er_trace_btn_1_label, "查询");
	lv_obj_set_style_pad_all(ui->er_trace_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->er_trace_btn_1_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes er_trace_btn_2
	ui->er_trace_btn_2 = lv_btn_create(ui->er_trace);
	lv_obj_set_pos(ui->er_trace_btn_2, 417, 96);
	lv_obj_set_size(ui->er_trace_btn_2, 40, 29);
	lv_obj_set_scrollbar_mode(ui->er_trace_btn_2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_er_trace_btn_2_main_main_default
	static lv_style_t style_er_trace_btn_2_main_main_default;
	if (style_er_trace_btn_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_er_trace_btn_2_main_main_default);
	else
		lv_style_init(&style_er_trace_btn_2_main_main_default);
	lv_style_set_radius(&style_er_trace_btn_2_main_main_default, 5);
	lv_style_set_bg_color(&style_er_trace_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_er_trace_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_er_trace_btn_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_er_trace_btn_2_main_main_default, 255);
	lv_style_set_border_color(&style_er_trace_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_er_trace_btn_2_main_main_default, 0);
	lv_style_set_border_opa(&style_er_trace_btn_2_main_main_default, 255);
	lv_style_set_text_color(&style_er_trace_btn_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_er_trace_btn_2_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_align(&style_er_trace_btn_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->er_trace_btn_2, &style_er_trace_btn_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->er_trace_btn_2_label = lv_label_create(ui->er_trace_btn_2);
	lv_label_set_text(ui->er_trace_btn_2_label, "刷卡");
	lv_obj_set_style_pad_all(ui->er_trace_btn_2, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->er_trace_btn_2_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes er_trace_label_1
	ui->er_trace_label_1 = lv_label_create(ui->er_trace);
	lv_obj_set_pos(ui->er_trace_label_1, 35, 7);
	lv_obj_set_size(ui->er_trace_label_1, 175, 32);
	lv_obj_set_scrollbar_mode(ui->er_trace_label_1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->er_trace_label_1, "请选择-查询/刷卡-");
	lv_label_set_long_mode(ui->er_trace_label_1, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_er_trace_label_1_main_main_default
	static lv_style_t style_er_trace_label_1_main_main_default;
	if (style_er_trace_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_er_trace_label_1_main_main_default);
	else
		lv_style_init(&style_er_trace_label_1_main_main_default);
	lv_style_set_radius(&style_er_trace_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_er_trace_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_er_trace_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_er_trace_label_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_er_trace_label_1_main_main_default, 0);
	lv_style_set_text_color(&style_er_trace_label_1_main_main_default, lv_color_make(0x05, 0x05, 0x05));
	lv_style_set_text_font(&style_er_trace_label_1_main_main_default, &lv_font_simsun_14);
	lv_style_set_text_letter_space(&style_er_trace_label_1_main_main_default, 2);
	lv_style_set_text_line_space(&style_er_trace_label_1_main_main_default, 0);
	lv_style_set_text_align(&style_er_trace_label_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_er_trace_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_er_trace_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_er_trace_label_1_main_main_default, 8);
	lv_style_set_pad_bottom(&style_er_trace_label_1_main_main_default, 0);
	lv_obj_add_style(ui->er_trace_label_1, &style_er_trace_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes er_trace_btn_3
	ui->er_trace_btn_3 = lv_btn_create(ui->er_trace);
	lv_obj_set_pos(ui->er_trace_btn_3, 440, 156);
	lv_obj_set_size(ui->er_trace_btn_3, 36, 36);
	lv_obj_set_scrollbar_mode(ui->er_trace_btn_3, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_er_trace_btn_3_main_main_default
	static lv_style_t style_er_trace_btn_3_main_main_default;
	if (style_er_trace_btn_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_er_trace_btn_3_main_main_default);
	else
		lv_style_init(&style_er_trace_btn_3_main_main_default);
	lv_style_set_radius(&style_er_trace_btn_3_main_main_default, 5);
	lv_style_set_bg_color(&style_er_trace_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_er_trace_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_er_trace_btn_3_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_er_trace_btn_3_main_main_default, 255);
	lv_style_set_border_color(&style_er_trace_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_er_trace_btn_3_main_main_default, 0);
	lv_style_set_border_opa(&style_er_trace_btn_3_main_main_default, 255);
	lv_style_set_text_color(&style_er_trace_btn_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_er_trace_btn_3_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_align(&style_er_trace_btn_3_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->er_trace_btn_3, &style_er_trace_btn_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->er_trace_btn_3_label = lv_label_create(ui->er_trace_btn_3);
	lv_label_set_text(ui->er_trace_btn_3_label, ">>");
	lv_obj_set_style_pad_all(ui->er_trace_btn_3, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->er_trace_btn_3_label, LV_ALIGN_CENTER, 0, 0);

	//Init events for screen
	events_init_er_trace(ui);
}