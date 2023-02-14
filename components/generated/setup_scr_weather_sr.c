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





extern u_int8_t air_temp;
extern u_int8_t air_humidity;
extern u_int16_t air_pressure;
extern u_int8_t air_api;
extern u_int8_t air_rain;
extern u_int8_t air_cloud;



void setup_scr_weather_sr(lv_ui *ui){

	//Write codes weather_sr
	ui->weather_sr = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->weather_sr, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_weather_sr_main_main_default
	static lv_style_t style_weather_sr_main_main_default;
	if (style_weather_sr_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_weather_sr_main_main_default);
	else
		lv_style_init(&style_weather_sr_main_main_default);
	lv_style_set_bg_color(&style_weather_sr_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_weather_sr_main_main_default, 0);
	lv_obj_add_style(ui->weather_sr, &style_weather_sr_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_sr_imgbtn_1
	ui->weather_sr_imgbtn_1 = lv_imgbtn_create(ui->weather_sr);
	lv_obj_set_pos(ui->weather_sr_imgbtn_1, 1, 1);
	lv_obj_set_size(ui->weather_sr_imgbtn_1, 32, 32);
	lv_obj_set_scrollbar_mode(ui->weather_sr_imgbtn_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_weather_sr_imgbtn_1_main_main_default
	static lv_style_t style_weather_sr_imgbtn_1_main_main_default;
	if (style_weather_sr_imgbtn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_weather_sr_imgbtn_1_main_main_default);
	else
		lv_style_init(&style_weather_sr_imgbtn_1_main_main_default);
	lv_style_set_text_color(&style_weather_sr_imgbtn_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_weather_sr_imgbtn_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_weather_sr_imgbtn_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_weather_sr_imgbtn_1_main_main_default, 0);
	lv_style_set_img_opa(&style_weather_sr_imgbtn_1_main_main_default, 255);
	lv_obj_add_style(ui->weather_sr_imgbtn_1, &style_weather_sr_imgbtn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_weather_sr_imgbtn_1_main_main_pressed
	static lv_style_t style_weather_sr_imgbtn_1_main_main_pressed;
	if (style_weather_sr_imgbtn_1_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_weather_sr_imgbtn_1_main_main_pressed);
	else
		lv_style_init(&style_weather_sr_imgbtn_1_main_main_pressed);
	lv_style_set_text_color(&style_weather_sr_imgbtn_1_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_weather_sr_imgbtn_1_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_weather_sr_imgbtn_1_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_weather_sr_imgbtn_1_main_main_pressed, 0);
	lv_style_set_img_opa(&style_weather_sr_imgbtn_1_main_main_pressed, 255);
	lv_obj_add_style(ui->weather_sr_imgbtn_1, &style_weather_sr_imgbtn_1_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_weather_sr_imgbtn_1_main_main_checked
	static lv_style_t style_weather_sr_imgbtn_1_main_main_checked;
	if (style_weather_sr_imgbtn_1_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_weather_sr_imgbtn_1_main_main_checked);
	else
		lv_style_init(&style_weather_sr_imgbtn_1_main_main_checked);
	lv_style_set_text_color(&style_weather_sr_imgbtn_1_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_weather_sr_imgbtn_1_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_weather_sr_imgbtn_1_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_weather_sr_imgbtn_1_main_main_checked, 0);
	lv_style_set_img_opa(&style_weather_sr_imgbtn_1_main_main_checked, 255);
	lv_obj_add_style(ui->weather_sr_imgbtn_1, &style_weather_sr_imgbtn_1_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->weather_sr_imgbtn_1, LV_IMGBTN_STATE_RELEASED, NULL, &_fanhui2_alpha_32x32, NULL);
	lv_imgbtn_set_src(ui->weather_sr_imgbtn_1, LV_IMGBTN_STATE_PRESSED, NULL, &_fanhui2_alpha_32x32, NULL);
	lv_obj_add_flag(ui->weather_sr_imgbtn_1, LV_OBJ_FLAG_CHECKABLE);


    //////////////////////////////////////////////////////////////////
	/*
	//Write codes weather_sr_label_1
	ui->weather_sr_label_1 = lv_label_create(ui->weather_sr);
	lv_obj_set_pos(ui->weather_sr_label_1, 54, 1);
	lv_obj_set_size(ui->weather_sr_label_1, 97, 32);
	lv_obj_set_scrollbar_mode(ui->weather_sr_label_1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->weather_sr_label_1, "当前地区：");
	lv_label_set_long_mode(ui->weather_sr_label_1, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_weather_sr_label_1_main_main_default
	static lv_style_t style_weather_sr_label_1_main_main_default;
	if (style_weather_sr_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_weather_sr_label_1_main_main_default);
	else
		lv_style_init(&style_weather_sr_label_1_main_main_default);
	lv_style_set_radius(&style_weather_sr_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_weather_sr_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_weather_sr_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_weather_sr_label_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_weather_sr_label_1_main_main_default, 255);
	lv_style_set_text_color(&style_weather_sr_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_weather_sr_label_1_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_weather_sr_label_1_main_main_default, 2);
	lv_style_set_text_line_space(&style_weather_sr_label_1_main_main_default, 0);
	lv_style_set_text_align(&style_weather_sr_label_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_weather_sr_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_weather_sr_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_weather_sr_label_1_main_main_default, 8);
	lv_style_set_pad_bottom(&style_weather_sr_label_1_main_main_default, 0);
	lv_obj_add_style(ui->weather_sr_label_1, &style_weather_sr_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_sr_label_2
	ui->weather_sr_label_2 = lv_label_create(ui->weather_sr);
	lv_obj_set_pos(ui->weather_sr_label_2, 151, 1);
	lv_obj_set_size(ui->weather_sr_label_2, 100, 32);
	lv_obj_set_scrollbar_mode(ui->weather_sr_label_2, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->weather_sr_label_2, "商丘");
	lv_label_set_long_mode(ui->weather_sr_label_2, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_weather_sr_label_2_main_main_default
	static lv_style_t style_weather_sr_label_2_main_main_default;
	if (style_weather_sr_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_weather_sr_label_2_main_main_default);
	else
		lv_style_init(&style_weather_sr_label_2_main_main_default);
	lv_style_set_radius(&style_weather_sr_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_weather_sr_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_weather_sr_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_weather_sr_label_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_weather_sr_label_2_main_main_default, 255);
	lv_style_set_text_color(&style_weather_sr_label_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_weather_sr_label_2_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_weather_sr_label_2_main_main_default, 2);
	lv_style_set_text_line_space(&style_weather_sr_label_2_main_main_default, 0);
	lv_style_set_text_align(&style_weather_sr_label_2_main_main_default, LV_TEXT_ALIGN_LEFT);
	lv_style_set_pad_left(&style_weather_sr_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_weather_sr_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_weather_sr_label_2_main_main_default, 8);
	lv_style_set_pad_bottom(&style_weather_sr_label_2_main_main_default, 0);
	lv_obj_add_style(ui->weather_sr_label_2, &style_weather_sr_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    */
	//Write codes weather_sr_bar_1
	ui->weather_sr_bar_1 = lv_bar_create(ui->weather_sr);
	lv_obj_set_pos(ui->weather_sr_bar_1, 56, 100);
	lv_obj_set_size(ui->weather_sr_bar_1, 102, 16);
	lv_obj_set_scrollbar_mode(ui->weather_sr_bar_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_weather_sr_bar_1_main_main_default
	static lv_style_t style_weather_sr_bar_1_main_main_default;
	if (style_weather_sr_bar_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_weather_sr_bar_1_main_main_default);
	else
		lv_style_init(&style_weather_sr_bar_1_main_main_default);
	lv_style_set_radius(&style_weather_sr_bar_1_main_main_default, 10);
	lv_style_set_bg_color(&style_weather_sr_bar_1_main_main_default, lv_color_make(0x42, 0x88, 0xc2));
	lv_style_set_bg_grad_color(&style_weather_sr_bar_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_weather_sr_bar_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_weather_sr_bar_1_main_main_default, 85);
	lv_obj_add_style(ui->weather_sr_bar_1, &style_weather_sr_bar_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_weather_sr_bar_1_main_indicator_default
	static lv_style_t style_weather_sr_bar_1_main_indicator_default;
	if (style_weather_sr_bar_1_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_weather_sr_bar_1_main_indicator_default);
	else
		lv_style_init(&style_weather_sr_bar_1_main_indicator_default);
	lv_style_set_radius(&style_weather_sr_bar_1_main_indicator_default, 10);
	lv_style_set_bg_color(&style_weather_sr_bar_1_main_indicator_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_weather_sr_bar_1_main_indicator_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_weather_sr_bar_1_main_indicator_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_weather_sr_bar_1_main_indicator_default, 255);
	lv_obj_add_style(ui->weather_sr_bar_1, &style_weather_sr_bar_1_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_anim_time(ui->weather_sr_bar_1, 1000, 0);
	lv_bar_set_mode(ui->weather_sr_bar_1, LV_BAR_MODE_NORMAL);
	lv_bar_set_value(ui->weather_sr_bar_1, 34, LV_ANIM_OFF);

	//Write codes weather_sr_label_3
	ui->weather_sr_label_3 = lv_label_create(ui->weather_sr);
	lv_obj_set_pos(ui->weather_sr_label_3, 343, 63);
	lv_obj_set_size(ui->weather_sr_label_3, 100, 32);
	lv_obj_set_scrollbar_mode(ui->weather_sr_label_3, LV_SCROLLBAR_MODE_OFF);
	//lv_label_set_text(ui->weather_sr_label_3, "压强：");
	lv_label_set_text_fmt(ui->weather_sr_label_3,"AP:%d",air_pressure);
	lv_label_set_long_mode(ui->weather_sr_label_3, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_weather_sr_label_3_main_main_default
	static lv_style_t style_weather_sr_label_3_main_main_default;
	if (style_weather_sr_label_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_weather_sr_label_3_main_main_default);
	else
		lv_style_init(&style_weather_sr_label_3_main_main_default);
	lv_style_set_radius(&style_weather_sr_label_3_main_main_default, 0);
	lv_style_set_bg_color(&style_weather_sr_label_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_weather_sr_label_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_weather_sr_label_3_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_weather_sr_label_3_main_main_default, 255);
	lv_style_set_text_color(&style_weather_sr_label_3_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_weather_sr_label_3_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_weather_sr_label_3_main_main_default, 2);
	lv_style_set_text_line_space(&style_weather_sr_label_3_main_main_default, 0);
	lv_style_set_text_align(&style_weather_sr_label_3_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_weather_sr_label_3_main_main_default, 0);
	lv_style_set_pad_right(&style_weather_sr_label_3_main_main_default, 0);
	lv_style_set_pad_top(&style_weather_sr_label_3_main_main_default, 8);
	lv_style_set_pad_bottom(&style_weather_sr_label_3_main_main_default, 0);
	lv_obj_add_style(ui->weather_sr_label_3, &style_weather_sr_label_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_sr_label_4
	ui->weather_sr_label_4 = lv_label_create(ui->weather_sr);
	lv_obj_set_pos(ui->weather_sr_label_4, 52, 2);
	lv_obj_set_size(ui->weather_sr_label_4, 100, 32);
	lv_obj_set_scrollbar_mode(ui->weather_sr_label_4, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->weather_sr_label_4, "PSDU");
	lv_label_set_long_mode(ui->weather_sr_label_4, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_weather_sr_label_4_main_main_default
	static lv_style_t style_weather_sr_label_4_main_main_default;
	if (style_weather_sr_label_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_weather_sr_label_4_main_main_default);
	else
		lv_style_init(&style_weather_sr_label_4_main_main_default);
	lv_style_set_radius(&style_weather_sr_label_4_main_main_default, 0);
	lv_style_set_bg_color(&style_weather_sr_label_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_weather_sr_label_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_weather_sr_label_4_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_weather_sr_label_4_main_main_default, 255);
	lv_style_set_text_color(&style_weather_sr_label_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_weather_sr_label_4_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_weather_sr_label_4_main_main_default, 2);
	lv_style_set_text_line_space(&style_weather_sr_label_4_main_main_default, 0);
	lv_style_set_text_align(&style_weather_sr_label_4_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_weather_sr_label_4_main_main_default, 0);
	lv_style_set_pad_right(&style_weather_sr_label_4_main_main_default, 0);
	lv_style_set_pad_top(&style_weather_sr_label_4_main_main_default, 8);
	lv_style_set_pad_bottom(&style_weather_sr_label_4_main_main_default, 0);
	lv_obj_add_style(ui->weather_sr_label_4, &style_weather_sr_label_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_sr_bar_2
	ui->weather_sr_bar_2 = lv_bar_create(ui->weather_sr);
	lv_obj_set_pos(ui->weather_sr_bar_2, 197, 100);
	lv_obj_set_size(ui->weather_sr_bar_2, 102, 16);
	lv_obj_set_scrollbar_mode(ui->weather_sr_bar_2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_weather_sr_bar_2_main_main_default
	static lv_style_t style_weather_sr_bar_2_main_main_default;
	if (style_weather_sr_bar_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_weather_sr_bar_2_main_main_default);
	else
		lv_style_init(&style_weather_sr_bar_2_main_main_default);
	lv_style_set_radius(&style_weather_sr_bar_2_main_main_default, 10);
	lv_style_set_bg_color(&style_weather_sr_bar_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_weather_sr_bar_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_weather_sr_bar_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_weather_sr_bar_2_main_main_default, 60);
	lv_obj_add_style(ui->weather_sr_bar_2, &style_weather_sr_bar_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_weather_sr_bar_2_main_indicator_default
	static lv_style_t style_weather_sr_bar_2_main_indicator_default;
	if (style_weather_sr_bar_2_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_weather_sr_bar_2_main_indicator_default);
	else
		lv_style_init(&style_weather_sr_bar_2_main_indicator_default);
	lv_style_set_radius(&style_weather_sr_bar_2_main_indicator_default, 10);
	lv_style_set_bg_color(&style_weather_sr_bar_2_main_indicator_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_weather_sr_bar_2_main_indicator_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_weather_sr_bar_2_main_indicator_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_weather_sr_bar_2_main_indicator_default, 255);
	lv_obj_add_style(ui->weather_sr_bar_2, &style_weather_sr_bar_2_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_anim_time(ui->weather_sr_bar_2, 1000, 0);
	lv_bar_set_mode(ui->weather_sr_bar_2, LV_BAR_MODE_NORMAL);
	lv_bar_set_value(ui->weather_sr_bar_2, 80, LV_ANIM_OFF);

	//Write codes weather_sr_label_5
	ui->weather_sr_label_5 = lv_label_create(ui->weather_sr);
	lv_obj_set_pos(ui->weather_sr_label_5, 195, 63);
	lv_obj_set_size(ui->weather_sr_label_5, 102, 32);
	lv_obj_set_scrollbar_mode(ui->weather_sr_label_5, LV_SCROLLBAR_MODE_OFF);
	//lv_label_set_text(ui->weather_sr_label_5, "湿度:");
	lv_label_set_text_fmt(ui->weather_sr_label_5, "humi: %d",air_humidity);
	lv_label_set_long_mode(ui->weather_sr_label_5, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_weather_sr_label_5_main_main_default
	static lv_style_t style_weather_sr_label_5_main_main_default;
	if (style_weather_sr_label_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_weather_sr_label_5_main_main_default);
	else
		lv_style_init(&style_weather_sr_label_5_main_main_default);
	lv_style_set_radius(&style_weather_sr_label_5_main_main_default, 0);
	lv_style_set_bg_color(&style_weather_sr_label_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_weather_sr_label_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_weather_sr_label_5_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_weather_sr_label_5_main_main_default, 255);
	lv_style_set_text_color(&style_weather_sr_label_5_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_weather_sr_label_5_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_weather_sr_label_5_main_main_default, 2);
	lv_style_set_text_line_space(&style_weather_sr_label_5_main_main_default, 0);
	lv_style_set_text_align(&style_weather_sr_label_5_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_weather_sr_label_5_main_main_default, 0);
	lv_style_set_pad_right(&style_weather_sr_label_5_main_main_default, 0);
	lv_style_set_pad_top(&style_weather_sr_label_5_main_main_default, 8);
	lv_style_set_pad_bottom(&style_weather_sr_label_5_main_main_default, 0);
	lv_obj_add_style(ui->weather_sr_label_5, &style_weather_sr_label_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_sr_label_6
	ui->weather_sr_label_6 = lv_label_create(ui->weather_sr);
	lv_obj_set_pos(ui->weather_sr_label_6, 56, 63);
	lv_obj_set_size(ui->weather_sr_label_6, 102, 32);
	lv_obj_set_scrollbar_mode(ui->weather_sr_label_6, LV_SCROLLBAR_MODE_OFF);
	//lv_label_set_text(ui->weather_sr_label_6, "温度:");
	lv_label_set_text_fmt(ui->weather_sr_label_6,"temp: %d",air_temp);
	lv_label_set_long_mode(ui->weather_sr_label_6, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_weather_sr_label_6_main_main_default
	static lv_style_t style_weather_sr_label_6_main_main_default;
	if (style_weather_sr_label_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_weather_sr_label_6_main_main_default);
	else
		lv_style_init(&style_weather_sr_label_6_main_main_default);
	lv_style_set_radius(&style_weather_sr_label_6_main_main_default, 0);
	lv_style_set_bg_color(&style_weather_sr_label_6_main_main_default, lv_color_make(0x25, 0x97, 0xf4));
	lv_style_set_bg_grad_color(&style_weather_sr_label_6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_weather_sr_label_6_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_weather_sr_label_6_main_main_default, 255);
	lv_style_set_text_color(&style_weather_sr_label_6_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_weather_sr_label_6_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_weather_sr_label_6_main_main_default, 2);
	lv_style_set_text_line_space(&style_weather_sr_label_6_main_main_default, 0);
	lv_style_set_text_align(&style_weather_sr_label_6_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_weather_sr_label_6_main_main_default, 0);
	lv_style_set_pad_right(&style_weather_sr_label_6_main_main_default, 0);
	lv_style_set_pad_top(&style_weather_sr_label_6_main_main_default, 8);
	lv_style_set_pad_bottom(&style_weather_sr_label_6_main_main_default, 0);
	lv_obj_add_style(ui->weather_sr_label_6, &style_weather_sr_label_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_sr_label_7
	ui->weather_sr_label_7 = lv_label_create(ui->weather_sr);
	lv_obj_set_pos(ui->weather_sr_label_7, 56, 160);
	lv_obj_set_size(ui->weather_sr_label_7, 102, 32);
	lv_obj_set_scrollbar_mode(ui->weather_sr_label_7, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->weather_sr_label_7, "Air_Q");
	lv_label_set_long_mode(ui->weather_sr_label_7, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_weather_sr_label_7_main_main_default
	static lv_style_t style_weather_sr_label_7_main_main_default;
	if (style_weather_sr_label_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_weather_sr_label_7_main_main_default);
	else
		lv_style_init(&style_weather_sr_label_7_main_main_default);
	lv_style_set_radius(&style_weather_sr_label_7_main_main_default, 0);
	lv_style_set_bg_color(&style_weather_sr_label_7_main_main_default, lv_color_make(0x27, 0x7f, 0x91));
	lv_style_set_bg_grad_color(&style_weather_sr_label_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_weather_sr_label_7_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_weather_sr_label_7_main_main_default, 128);
	lv_style_set_text_color(&style_weather_sr_label_7_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_weather_sr_label_7_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_weather_sr_label_7_main_main_default, 2);
	lv_style_set_text_line_space(&style_weather_sr_label_7_main_main_default, 0);
	lv_style_set_text_align(&style_weather_sr_label_7_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_weather_sr_label_7_main_main_default, 0);
	lv_style_set_pad_right(&style_weather_sr_label_7_main_main_default, 0);
	lv_style_set_pad_top(&style_weather_sr_label_7_main_main_default, 8);
	lv_style_set_pad_bottom(&style_weather_sr_label_7_main_main_default, 0);
	lv_obj_add_style(ui->weather_sr_label_7, &style_weather_sr_label_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_sr_label_8
	ui->weather_sr_label_8 = lv_label_create(ui->weather_sr);
	lv_obj_set_pos(ui->weather_sr_label_8, 56, 214);
	lv_obj_set_size(ui->weather_sr_label_8, 101, 32);
	lv_obj_set_scrollbar_mode(ui->weather_sr_label_8, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->weather_sr_label_8, "Rain");
	lv_label_set_long_mode(ui->weather_sr_label_8, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_weather_sr_label_8_main_main_default
	static lv_style_t style_weather_sr_label_8_main_main_default;
	if (style_weather_sr_label_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_weather_sr_label_8_main_main_default);
	else
		lv_style_init(&style_weather_sr_label_8_main_main_default);
	lv_style_set_radius(&style_weather_sr_label_8_main_main_default, 0);
	lv_style_set_bg_color(&style_weather_sr_label_8_main_main_default, lv_color_make(0x34, 0x7f, 0x8d));
	lv_style_set_bg_grad_color(&style_weather_sr_label_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_weather_sr_label_8_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_weather_sr_label_8_main_main_default, 154);
	lv_style_set_text_color(&style_weather_sr_label_8_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_weather_sr_label_8_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_weather_sr_label_8_main_main_default, 2);
	lv_style_set_text_line_space(&style_weather_sr_label_8_main_main_default, 0);
	lv_style_set_text_align(&style_weather_sr_label_8_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_weather_sr_label_8_main_main_default, 0);
	lv_style_set_pad_right(&style_weather_sr_label_8_main_main_default, 0);
	lv_style_set_pad_top(&style_weather_sr_label_8_main_main_default, 8);
	lv_style_set_pad_bottom(&style_weather_sr_label_8_main_main_default, 0);
	lv_obj_add_style(ui->weather_sr_label_8, &style_weather_sr_label_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_sr_bar_3
	ui->weather_sr_bar_3 = lv_bar_create(ui->weather_sr);
	lv_obj_set_pos(ui->weather_sr_bar_3, 343, 100);
	lv_obj_set_size(ui->weather_sr_bar_3, 102, 16);
	lv_obj_set_scrollbar_mode(ui->weather_sr_bar_3, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_weather_sr_bar_3_main_main_default
	static lv_style_t style_weather_sr_bar_3_main_main_default;
	if (style_weather_sr_bar_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_weather_sr_bar_3_main_main_default);
	else
		lv_style_init(&style_weather_sr_bar_3_main_main_default);
	lv_style_set_radius(&style_weather_sr_bar_3_main_main_default, 10);
	lv_style_set_bg_color(&style_weather_sr_bar_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_weather_sr_bar_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_weather_sr_bar_3_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_weather_sr_bar_3_main_main_default, 60);
	lv_obj_add_style(ui->weather_sr_bar_3, &style_weather_sr_bar_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_weather_sr_bar_3_main_indicator_default
	static lv_style_t style_weather_sr_bar_3_main_indicator_default;
	if (style_weather_sr_bar_3_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_weather_sr_bar_3_main_indicator_default);
	else
		lv_style_init(&style_weather_sr_bar_3_main_indicator_default);
	lv_style_set_radius(&style_weather_sr_bar_3_main_indicator_default, 10);
	lv_style_set_bg_color(&style_weather_sr_bar_3_main_indicator_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_weather_sr_bar_3_main_indicator_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_weather_sr_bar_3_main_indicator_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_weather_sr_bar_3_main_indicator_default, 255);
	lv_obj_add_style(ui->weather_sr_bar_3, &style_weather_sr_bar_3_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_anim_time(ui->weather_sr_bar_3, 1000, 0);
	lv_bar_set_mode(ui->weather_sr_bar_3, LV_BAR_MODE_NORMAL);
	lv_bar_set_value(ui->weather_sr_bar_3, 50, LV_ANIM_OFF);

	//Write codes weather_sr_label_9
	ui->weather_sr_label_9 = lv_label_create(ui->weather_sr);
	lv_obj_set_pos(ui->weather_sr_label_9, 56, 268);
	lv_obj_set_size(ui->weather_sr_label_9, 102, 32);
	lv_obj_set_scrollbar_mode(ui->weather_sr_label_9, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->weather_sr_label_9, "Cloud");
	lv_label_set_long_mode(ui->weather_sr_label_9, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_weather_sr_label_9_main_main_default
	static lv_style_t style_weather_sr_label_9_main_main_default;
	if (style_weather_sr_label_9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_weather_sr_label_9_main_main_default);
	else
		lv_style_init(&style_weather_sr_label_9_main_main_default);
	lv_style_set_radius(&style_weather_sr_label_9_main_main_default, 0);
	lv_style_set_bg_color(&style_weather_sr_label_9_main_main_default, lv_color_make(0x34, 0x7f, 0x8d));
	lv_style_set_bg_grad_color(&style_weather_sr_label_9_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_weather_sr_label_9_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_weather_sr_label_9_main_main_default, 154);
	lv_style_set_text_color(&style_weather_sr_label_9_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_weather_sr_label_9_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_weather_sr_label_9_main_main_default, 2);
	lv_style_set_text_line_space(&style_weather_sr_label_9_main_main_default, 0);
	lv_style_set_text_align(&style_weather_sr_label_9_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_weather_sr_label_9_main_main_default, 0);
	lv_style_set_pad_right(&style_weather_sr_label_9_main_main_default, 0);
	lv_style_set_pad_top(&style_weather_sr_label_9_main_main_default, 8);
	lv_style_set_pad_bottom(&style_weather_sr_label_9_main_main_default, 0);
	lv_obj_add_style(ui->weather_sr_label_9, &style_weather_sr_label_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_sr_label_10
	ui->weather_sr_label_10 = lv_label_create(ui->weather_sr);
	lv_obj_set_pos(ui->weather_sr_label_10, 154, 160);
	lv_obj_set_size(ui->weather_sr_label_10, 139, 32);
	lv_obj_set_scrollbar_mode(ui->weather_sr_label_10, LV_SCROLLBAR_MODE_OFF);
	//lv_label_set_text(ui->weather_sr_label_10, air_api);
	lv_label_set_text_fmt(ui->weather_sr_label_10, "%d",air_api);
	lv_label_set_long_mode(ui->weather_sr_label_10, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_weather_sr_label_10_main_main_default
	static lv_style_t style_weather_sr_label_10_main_main_default;
	if (style_weather_sr_label_10_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_weather_sr_label_10_main_main_default);
	else
		lv_style_init(&style_weather_sr_label_10_main_main_default);
	lv_style_set_radius(&style_weather_sr_label_10_main_main_default, 0);
	lv_style_set_bg_color(&style_weather_sr_label_10_main_main_default, lv_color_make(0x4e, 0xcd, 0xc4));
	lv_style_set_bg_grad_color(&style_weather_sr_label_10_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_weather_sr_label_10_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_weather_sr_label_10_main_main_default, 81);
	lv_style_set_text_color(&style_weather_sr_label_10_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_weather_sr_label_10_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_weather_sr_label_10_main_main_default, 2);
	lv_style_set_text_line_space(&style_weather_sr_label_10_main_main_default, 0);
	lv_style_set_text_align(&style_weather_sr_label_10_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_weather_sr_label_10_main_main_default, 0);
	lv_style_set_pad_right(&style_weather_sr_label_10_main_main_default, 0);
	lv_style_set_pad_top(&style_weather_sr_label_10_main_main_default, 8);
	lv_style_set_pad_bottom(&style_weather_sr_label_10_main_main_default, 0);
	lv_obj_add_style(ui->weather_sr_label_10, &style_weather_sr_label_10_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_sr_label_11
	ui->weather_sr_label_11 = lv_label_create(ui->weather_sr);
	lv_obj_set_pos(ui->weather_sr_label_11, 154, 214);
	lv_obj_set_size(ui->weather_sr_label_11, 137, 32);
	lv_obj_set_scrollbar_mode(ui->weather_sr_label_11, LV_SCROLLBAR_MODE_OFF);
	//lv_label_set_text(ui->weather_sr_label_11, air_rain);
	lv_label_set_text_fmt(ui->weather_sr_label_11,"%d", air_rain);
	lv_label_set_long_mode(ui->weather_sr_label_11, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_weather_sr_label_11_main_main_default
	static lv_style_t style_weather_sr_label_11_main_main_default;
	if (style_weather_sr_label_11_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_weather_sr_label_11_main_main_default);
	else
		lv_style_init(&style_weather_sr_label_11_main_main_default);
	lv_style_set_radius(&style_weather_sr_label_11_main_main_default, 0);
	lv_style_set_bg_color(&style_weather_sr_label_11_main_main_default, lv_color_make(0x4e, 0xcd, 0xc4));
	lv_style_set_bg_grad_color(&style_weather_sr_label_11_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_weather_sr_label_11_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_weather_sr_label_11_main_main_default, 81);
	lv_style_set_text_color(&style_weather_sr_label_11_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_weather_sr_label_11_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_weather_sr_label_11_main_main_default, 2);
	lv_style_set_text_line_space(&style_weather_sr_label_11_main_main_default, 0);
	lv_style_set_text_align(&style_weather_sr_label_11_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_weather_sr_label_11_main_main_default, 0);
	lv_style_set_pad_right(&style_weather_sr_label_11_main_main_default, 0);
	lv_style_set_pad_top(&style_weather_sr_label_11_main_main_default, 8);
	lv_style_set_pad_bottom(&style_weather_sr_label_11_main_main_default, 0);
	lv_obj_add_style(ui->weather_sr_label_11, &style_weather_sr_label_11_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_sr_label_12
	ui->weather_sr_label_12 = lv_label_create(ui->weather_sr);
	lv_obj_set_pos(ui->weather_sr_label_12, 155, 268);
	lv_obj_set_size(ui->weather_sr_label_12, 138, 32);
	lv_obj_set_scrollbar_mode(ui->weather_sr_label_12, LV_SCROLLBAR_MODE_OFF);
	//lv_label_set_text(ui->weather_sr_label_12, air_cloud);
	lv_label_set_text_fmt(ui->weather_sr_label_12,"%d", air_cloud);
	lv_label_set_long_mode(ui->weather_sr_label_12, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_weather_sr_label_12_main_main_default
	static lv_style_t style_weather_sr_label_12_main_main_default;
	if (style_weather_sr_label_12_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_weather_sr_label_12_main_main_default);
	else
		lv_style_init(&style_weather_sr_label_12_main_main_default);
	lv_style_set_radius(&style_weather_sr_label_12_main_main_default, 0);
	lv_style_set_bg_color(&style_weather_sr_label_12_main_main_default, lv_color_make(0x4e, 0xcd, 0xc4));
	lv_style_set_bg_grad_color(&style_weather_sr_label_12_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_weather_sr_label_12_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_weather_sr_label_12_main_main_default, 76);
	lv_style_set_text_color(&style_weather_sr_label_12_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_weather_sr_label_12_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_weather_sr_label_12_main_main_default, 2);
	lv_style_set_text_line_space(&style_weather_sr_label_12_main_main_default, 0);
	lv_style_set_text_align(&style_weather_sr_label_12_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_weather_sr_label_12_main_main_default, 0);
	lv_style_set_pad_right(&style_weather_sr_label_12_main_main_default, 0);
	lv_style_set_pad_top(&style_weather_sr_label_12_main_main_default, 8);
	lv_style_set_pad_bottom(&style_weather_sr_label_12_main_main_default, 0);
	lv_obj_add_style(ui->weather_sr_label_12, &style_weather_sr_label_12_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);   
	//Init events for screen
	events_init_weather_sr(ui);
}