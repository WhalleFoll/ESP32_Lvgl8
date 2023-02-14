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


void setup_scr_wifi_sr(lv_ui *ui){

	//Write codes wifi_sr
	ui->wifi_sr = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->wifi_sr, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_wifi_sr_main_main_default
	static lv_style_t style_wifi_sr_main_main_default;
	if (style_wifi_sr_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_wifi_sr_main_main_default);
	else
		lv_style_init(&style_wifi_sr_main_main_default);
	lv_style_set_bg_color(&style_wifi_sr_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_wifi_sr_main_main_default, 0);
	lv_obj_add_style(ui->wifi_sr, &style_wifi_sr_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes wifi_sr_imgbtn_1
	ui->wifi_sr_imgbtn_1 = lv_imgbtn_create(ui->wifi_sr);
	lv_obj_set_pos(ui->wifi_sr_imgbtn_1, 1, 1);
	lv_obj_set_size(ui->wifi_sr_imgbtn_1, 32, 32);
	lv_obj_set_scrollbar_mode(ui->wifi_sr_imgbtn_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_wifi_sr_imgbtn_1_main_main_default
	static lv_style_t style_wifi_sr_imgbtn_1_main_main_default;
	if (style_wifi_sr_imgbtn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_wifi_sr_imgbtn_1_main_main_default);
	else
		lv_style_init(&style_wifi_sr_imgbtn_1_main_main_default);
	lv_style_set_text_color(&style_wifi_sr_imgbtn_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_wifi_sr_imgbtn_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_wifi_sr_imgbtn_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_wifi_sr_imgbtn_1_main_main_default, 0);
	lv_style_set_img_opa(&style_wifi_sr_imgbtn_1_main_main_default, 255);
	lv_obj_add_style(ui->wifi_sr_imgbtn_1, &style_wifi_sr_imgbtn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_wifi_sr_imgbtn_1_main_main_pressed
	static lv_style_t style_wifi_sr_imgbtn_1_main_main_pressed;
	if (style_wifi_sr_imgbtn_1_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_wifi_sr_imgbtn_1_main_main_pressed);
	else
		lv_style_init(&style_wifi_sr_imgbtn_1_main_main_pressed);
	lv_style_set_text_color(&style_wifi_sr_imgbtn_1_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_wifi_sr_imgbtn_1_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_wifi_sr_imgbtn_1_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_wifi_sr_imgbtn_1_main_main_pressed, 0);
	lv_style_set_img_opa(&style_wifi_sr_imgbtn_1_main_main_pressed, 255);
	lv_obj_add_style(ui->wifi_sr_imgbtn_1, &style_wifi_sr_imgbtn_1_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_wifi_sr_imgbtn_1_main_main_checked
	static lv_style_t style_wifi_sr_imgbtn_1_main_main_checked;
	if (style_wifi_sr_imgbtn_1_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_wifi_sr_imgbtn_1_main_main_checked);
	else
		lv_style_init(&style_wifi_sr_imgbtn_1_main_main_checked);
	lv_style_set_text_color(&style_wifi_sr_imgbtn_1_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_wifi_sr_imgbtn_1_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_wifi_sr_imgbtn_1_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_wifi_sr_imgbtn_1_main_main_checked, 0);
	lv_style_set_img_opa(&style_wifi_sr_imgbtn_1_main_main_checked, 255);
	lv_obj_add_style(ui->wifi_sr_imgbtn_1, &style_wifi_sr_imgbtn_1_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->wifi_sr_imgbtn_1, LV_IMGBTN_STATE_RELEASED, NULL, &_fanhui2_alpha_32x32, NULL);
	lv_imgbtn_set_src(ui->wifi_sr_imgbtn_1, LV_IMGBTN_STATE_PRESSED, NULL, &_fanhui2_alpha_32x32, NULL);
	lv_obj_add_flag(ui->wifi_sr_imgbtn_1, LV_OBJ_FLAG_CHECKABLE);

	//Write codes wifi_sr_label_1
	ui->wifi_sr_label_1 = lv_label_create(ui->wifi_sr);
	lv_obj_set_pos(ui->wifi_sr_label_1, 59, 46);
	lv_obj_set_size(ui->wifi_sr_label_1, 100, 32);
	lv_obj_set_scrollbar_mode(ui->wifi_sr_label_1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->wifi_sr_label_1, "当前WIFI:");
	lv_label_set_long_mode(ui->wifi_sr_label_1, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_wifi_sr_label_1_main_main_default
	static lv_style_t style_wifi_sr_label_1_main_main_default;
	if (style_wifi_sr_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_wifi_sr_label_1_main_main_default);
	else
		lv_style_init(&style_wifi_sr_label_1_main_main_default);
	lv_style_set_radius(&style_wifi_sr_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_wifi_sr_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_wifi_sr_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_wifi_sr_label_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_wifi_sr_label_1_main_main_default, 255);
	lv_style_set_text_color(&style_wifi_sr_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_wifi_sr_label_1_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_wifi_sr_label_1_main_main_default, 2);
	lv_style_set_text_line_space(&style_wifi_sr_label_1_main_main_default, 0);
	lv_style_set_text_align(&style_wifi_sr_label_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_wifi_sr_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_wifi_sr_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_wifi_sr_label_1_main_main_default, 8);
	lv_style_set_pad_bottom(&style_wifi_sr_label_1_main_main_default, 0);
	lv_obj_add_style(ui->wifi_sr_label_1, &style_wifi_sr_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes wifi_sr_label_2
	ui->wifi_sr_label_2 = lv_label_create(ui->wifi_sr);
	lv_obj_set_pos(ui->wifi_sr_label_2, 59, 97);
	lv_obj_set_size(ui->wifi_sr_label_2, 100, 32);
	lv_obj_set_scrollbar_mode(ui->wifi_sr_label_2, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->wifi_sr_label_2, "IP地址");
	lv_label_set_long_mode(ui->wifi_sr_label_2, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_wifi_sr_label_2_main_main_default
	static lv_style_t style_wifi_sr_label_2_main_main_default;
	if (style_wifi_sr_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_wifi_sr_label_2_main_main_default);
	else
		lv_style_init(&style_wifi_sr_label_2_main_main_default);
	lv_style_set_radius(&style_wifi_sr_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_wifi_sr_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_wifi_sr_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_wifi_sr_label_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_wifi_sr_label_2_main_main_default, 255);
	lv_style_set_text_color(&style_wifi_sr_label_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_wifi_sr_label_2_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_wifi_sr_label_2_main_main_default, 2);
	lv_style_set_text_line_space(&style_wifi_sr_label_2_main_main_default, 0);
	lv_style_set_text_align(&style_wifi_sr_label_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_wifi_sr_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_wifi_sr_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_wifi_sr_label_2_main_main_default, 8);
	lv_style_set_pad_bottom(&style_wifi_sr_label_2_main_main_default, 0);
	lv_obj_add_style(ui->wifi_sr_label_2, &style_wifi_sr_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes wifi_sr_label_3
	ui->wifi_sr_label_3 = lv_label_create(ui->wifi_sr);
	lv_obj_set_pos(ui->wifi_sr_label_3, 59, 144);
	lv_obj_set_size(ui->wifi_sr_label_3, 100, 32);
	lv_obj_set_scrollbar_mode(ui->wifi_sr_label_3, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->wifi_sr_label_3, "网关：");
	lv_label_set_long_mode(ui->wifi_sr_label_3, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_wifi_sr_label_3_main_main_default
	static lv_style_t style_wifi_sr_label_3_main_main_default;
	if (style_wifi_sr_label_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_wifi_sr_label_3_main_main_default);
	else
		lv_style_init(&style_wifi_sr_label_3_main_main_default);
	lv_style_set_radius(&style_wifi_sr_label_3_main_main_default, 0);
	lv_style_set_bg_color(&style_wifi_sr_label_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_wifi_sr_label_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_wifi_sr_label_3_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_wifi_sr_label_3_main_main_default, 255);
	lv_style_set_text_color(&style_wifi_sr_label_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_wifi_sr_label_3_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_wifi_sr_label_3_main_main_default, 2);
	lv_style_set_text_line_space(&style_wifi_sr_label_3_main_main_default, 0);
	lv_style_set_text_align(&style_wifi_sr_label_3_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_wifi_sr_label_3_main_main_default, 0);
	lv_style_set_pad_right(&style_wifi_sr_label_3_main_main_default, 0);
	lv_style_set_pad_top(&style_wifi_sr_label_3_main_main_default, 8);
	lv_style_set_pad_bottom(&style_wifi_sr_label_3_main_main_default, 0);
	lv_obj_add_style(ui->wifi_sr_label_3, &style_wifi_sr_label_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes wifi_sr_label_4
	ui->wifi_sr_label_4 = lv_label_create(ui->wifi_sr);
	lv_obj_set_pos(ui->wifi_sr_label_4, 59, 196);
	lv_obj_set_size(ui->wifi_sr_label_4, 100, 32);
	lv_obj_set_scrollbar_mode(ui->wifi_sr_label_4, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->wifi_sr_label_4, "MQTT：");
	lv_label_set_long_mode(ui->wifi_sr_label_4, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_wifi_sr_label_4_main_main_default
	static lv_style_t style_wifi_sr_label_4_main_main_default;
	if (style_wifi_sr_label_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_wifi_sr_label_4_main_main_default);
	else
		lv_style_init(&style_wifi_sr_label_4_main_main_default);
	lv_style_set_radius(&style_wifi_sr_label_4_main_main_default, 0);
	lv_style_set_bg_color(&style_wifi_sr_label_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_wifi_sr_label_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_wifi_sr_label_4_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_wifi_sr_label_4_main_main_default, 255);
	lv_style_set_text_color(&style_wifi_sr_label_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_wifi_sr_label_4_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_wifi_sr_label_4_main_main_default, 2);
	lv_style_set_text_line_space(&style_wifi_sr_label_4_main_main_default, 0);
	lv_style_set_text_align(&style_wifi_sr_label_4_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_wifi_sr_label_4_main_main_default, 0);
	lv_style_set_pad_right(&style_wifi_sr_label_4_main_main_default, 0);
	lv_style_set_pad_top(&style_wifi_sr_label_4_main_main_default, 8);
	lv_style_set_pad_bottom(&style_wifi_sr_label_4_main_main_default, 0);
	lv_obj_add_style(ui->wifi_sr_label_4, &style_wifi_sr_label_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes wifi_sr_label_5
	ui->wifi_sr_label_5 = lv_label_create(ui->wifi_sr);
	lv_obj_set_pos(ui->wifi_sr_label_5, 59, 245);
	lv_obj_set_size(ui->wifi_sr_label_5, 100, 32);
	lv_obj_set_scrollbar_mode(ui->wifi_sr_label_5, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->wifi_sr_label_5, "端口:");
	lv_label_set_long_mode(ui->wifi_sr_label_5, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_wifi_sr_label_5_main_main_default
	static lv_style_t style_wifi_sr_label_5_main_main_default;
	if (style_wifi_sr_label_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_wifi_sr_label_5_main_main_default);
	else
		lv_style_init(&style_wifi_sr_label_5_main_main_default);
	lv_style_set_radius(&style_wifi_sr_label_5_main_main_default, 0);
	lv_style_set_bg_color(&style_wifi_sr_label_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_wifi_sr_label_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_wifi_sr_label_5_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_wifi_sr_label_5_main_main_default, 255);
	lv_style_set_text_color(&style_wifi_sr_label_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_wifi_sr_label_5_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_wifi_sr_label_5_main_main_default, 2);
	lv_style_set_text_line_space(&style_wifi_sr_label_5_main_main_default, 0);
	lv_style_set_text_align(&style_wifi_sr_label_5_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_wifi_sr_label_5_main_main_default, 0);
	lv_style_set_pad_right(&style_wifi_sr_label_5_main_main_default, 0);
	lv_style_set_pad_top(&style_wifi_sr_label_5_main_main_default, 8);
	lv_style_set_pad_bottom(&style_wifi_sr_label_5_main_main_default, 0);
	lv_obj_add_style(ui->wifi_sr_label_5, &style_wifi_sr_label_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes wifi_sr_label_6
	ui->wifi_sr_label_6 = lv_label_create(ui->wifi_sr);
	lv_obj_set_pos(ui->wifi_sr_label_6, 190, 46);
	lv_obj_set_size(ui->wifi_sr_label_6, 176, 32);
	lv_obj_set_scrollbar_mode(ui->wifi_sr_label_6, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->wifi_sr_label_6, "JtyLHLD3");
	lv_label_set_long_mode(ui->wifi_sr_label_6, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_wifi_sr_label_6_main_main_default
	static lv_style_t style_wifi_sr_label_6_main_main_default;
	if (style_wifi_sr_label_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_wifi_sr_label_6_main_main_default);
	else
		lv_style_init(&style_wifi_sr_label_6_main_main_default);
	lv_style_set_radius(&style_wifi_sr_label_6_main_main_default, 0);
	lv_style_set_bg_color(&style_wifi_sr_label_6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_wifi_sr_label_6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_wifi_sr_label_6_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_wifi_sr_label_6_main_main_default, 119);
	lv_style_set_text_color(&style_wifi_sr_label_6_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_wifi_sr_label_6_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_wifi_sr_label_6_main_main_default, 2);
	lv_style_set_text_line_space(&style_wifi_sr_label_6_main_main_default, 0);
	lv_style_set_text_align(&style_wifi_sr_label_6_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_wifi_sr_label_6_main_main_default, 0);
	lv_style_set_pad_right(&style_wifi_sr_label_6_main_main_default, 0);
	lv_style_set_pad_top(&style_wifi_sr_label_6_main_main_default, 8);
	lv_style_set_pad_bottom(&style_wifi_sr_label_6_main_main_default, 0);
	lv_obj_add_style(ui->wifi_sr_label_6, &style_wifi_sr_label_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes wifi_sr_label_7
	ui->wifi_sr_label_7 = lv_label_create(ui->wifi_sr);
	lv_obj_set_pos(ui->wifi_sr_label_7, 190, 97);
	lv_obj_set_size(ui->wifi_sr_label_7, 176, 32);
	lv_obj_set_scrollbar_mode(ui->wifi_sr_label_7, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->wifi_sr_label_7, "192.168.1.10");
	lv_label_set_long_mode(ui->wifi_sr_label_7, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_wifi_sr_label_7_main_main_default
	static lv_style_t style_wifi_sr_label_7_main_main_default;
	if (style_wifi_sr_label_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_wifi_sr_label_7_main_main_default);
	else
		lv_style_init(&style_wifi_sr_label_7_main_main_default);
	lv_style_set_radius(&style_wifi_sr_label_7_main_main_default, 0);
	lv_style_set_bg_color(&style_wifi_sr_label_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_wifi_sr_label_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_wifi_sr_label_7_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_wifi_sr_label_7_main_main_default, 115);
	lv_style_set_text_color(&style_wifi_sr_label_7_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_wifi_sr_label_7_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_wifi_sr_label_7_main_main_default, 2);
	lv_style_set_text_line_space(&style_wifi_sr_label_7_main_main_default, 0);
	lv_style_set_text_align(&style_wifi_sr_label_7_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_wifi_sr_label_7_main_main_default, 0);
	lv_style_set_pad_right(&style_wifi_sr_label_7_main_main_default, 0);
	lv_style_set_pad_top(&style_wifi_sr_label_7_main_main_default, 8);
	lv_style_set_pad_bottom(&style_wifi_sr_label_7_main_main_default, 0);
	lv_obj_add_style(ui->wifi_sr_label_7, &style_wifi_sr_label_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes wifi_sr_label_8
	ui->wifi_sr_label_8 = lv_label_create(ui->wifi_sr);
	lv_obj_set_pos(ui->wifi_sr_label_8, 190, 144);
	lv_obj_set_size(ui->wifi_sr_label_8, 176, 32);
	lv_obj_set_scrollbar_mode(ui->wifi_sr_label_8, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->wifi_sr_label_8, "255.255.255.245");
	lv_label_set_long_mode(ui->wifi_sr_label_8, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_wifi_sr_label_8_main_main_default
	static lv_style_t style_wifi_sr_label_8_main_main_default;
	if (style_wifi_sr_label_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_wifi_sr_label_8_main_main_default);
	else
		lv_style_init(&style_wifi_sr_label_8_main_main_default);
	lv_style_set_radius(&style_wifi_sr_label_8_main_main_default, 0);
	lv_style_set_bg_color(&style_wifi_sr_label_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_wifi_sr_label_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_wifi_sr_label_8_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_wifi_sr_label_8_main_main_default, 115);
	lv_style_set_text_color(&style_wifi_sr_label_8_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_wifi_sr_label_8_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_wifi_sr_label_8_main_main_default, 2);
	lv_style_set_text_line_space(&style_wifi_sr_label_8_main_main_default, 0);
	lv_style_set_text_align(&style_wifi_sr_label_8_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_wifi_sr_label_8_main_main_default, 0);
	lv_style_set_pad_right(&style_wifi_sr_label_8_main_main_default, 0);
	lv_style_set_pad_top(&style_wifi_sr_label_8_main_main_default, 8);
	lv_style_set_pad_bottom(&style_wifi_sr_label_8_main_main_default, 0);
	lv_obj_add_style(ui->wifi_sr_label_8, &style_wifi_sr_label_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes wifi_sr_label_9
	ui->wifi_sr_label_9 = lv_label_create(ui->wifi_sr);
	lv_obj_set_pos(ui->wifi_sr_label_9, 190, 196);
	lv_obj_set_size(ui->wifi_sr_label_9, 176, 32);
	lv_obj_set_scrollbar_mode(ui->wifi_sr_label_9, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->wifi_sr_label_9, "47.92.23.144");
	lv_label_set_long_mode(ui->wifi_sr_label_9, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_wifi_sr_label_9_main_main_default
	static lv_style_t style_wifi_sr_label_9_main_main_default;
	if (style_wifi_sr_label_9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_wifi_sr_label_9_main_main_default);
	else
		lv_style_init(&style_wifi_sr_label_9_main_main_default);
	lv_style_set_radius(&style_wifi_sr_label_9_main_main_default, 0);
	lv_style_set_bg_color(&style_wifi_sr_label_9_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_wifi_sr_label_9_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_wifi_sr_label_9_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_wifi_sr_label_9_main_main_default, 115);
	lv_style_set_text_color(&style_wifi_sr_label_9_main_main_default, lv_color_make(0x03, 0x02, 0x02));
	lv_style_set_text_font(&style_wifi_sr_label_9_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_wifi_sr_label_9_main_main_default, 2);
	lv_style_set_text_line_space(&style_wifi_sr_label_9_main_main_default, 0);
	lv_style_set_text_align(&style_wifi_sr_label_9_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_wifi_sr_label_9_main_main_default, 0);
	lv_style_set_pad_right(&style_wifi_sr_label_9_main_main_default, 0);
	lv_style_set_pad_top(&style_wifi_sr_label_9_main_main_default, 8);
	lv_style_set_pad_bottom(&style_wifi_sr_label_9_main_main_default, 0);
	lv_obj_add_style(ui->wifi_sr_label_9, &style_wifi_sr_label_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes wifi_sr_label_10
	ui->wifi_sr_label_10 = lv_label_create(ui->wifi_sr);
	lv_obj_set_pos(ui->wifi_sr_label_10, 190, 245);
	lv_obj_set_size(ui->wifi_sr_label_10, 176, 32);
	lv_obj_set_scrollbar_mode(ui->wifi_sr_label_10, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->wifi_sr_label_10, "1883");
	lv_label_set_long_mode(ui->wifi_sr_label_10, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_wifi_sr_label_10_main_main_default
	static lv_style_t style_wifi_sr_label_10_main_main_default;
	if (style_wifi_sr_label_10_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_wifi_sr_label_10_main_main_default);
	else
		lv_style_init(&style_wifi_sr_label_10_main_main_default);
	lv_style_set_radius(&style_wifi_sr_label_10_main_main_default, 0);
	lv_style_set_bg_color(&style_wifi_sr_label_10_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_wifi_sr_label_10_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_wifi_sr_label_10_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_wifi_sr_label_10_main_main_default, 111);
	lv_style_set_text_color(&style_wifi_sr_label_10_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_wifi_sr_label_10_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_wifi_sr_label_10_main_main_default, 2);
	lv_style_set_text_line_space(&style_wifi_sr_label_10_main_main_default, 0);
	lv_style_set_text_align(&style_wifi_sr_label_10_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_wifi_sr_label_10_main_main_default, 0);
	lv_style_set_pad_right(&style_wifi_sr_label_10_main_main_default, 0);
	lv_style_set_pad_top(&style_wifi_sr_label_10_main_main_default, 8);
	lv_style_set_pad_bottom(&style_wifi_sr_label_10_main_main_default, 0);
	lv_obj_add_style(ui->wifi_sr_label_10, &style_wifi_sr_label_10_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Init events for screen
	events_init_wifi_sr(ui);
}