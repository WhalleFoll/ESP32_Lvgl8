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


void setup_scr_yangzhi_sc(lv_ui *ui){

	//Write codes yangzhi_sc
	ui->yangzhi_sc = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->yangzhi_sc, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_yangzhi_sc_main_main_default
	static lv_style_t style_yangzhi_sc_main_main_default;
	if (style_yangzhi_sc_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_yangzhi_sc_main_main_default);
	else
		lv_style_init(&style_yangzhi_sc_main_main_default);
	lv_style_set_bg_color(&style_yangzhi_sc_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_yangzhi_sc_main_main_default, 0);
	lv_obj_add_style(ui->yangzhi_sc, &style_yangzhi_sc_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes yangzhi_sc_imgbtn_1
	ui->yangzhi_sc_imgbtn_1 = lv_imgbtn_create(ui->yangzhi_sc);
	lv_obj_set_pos(ui->yangzhi_sc_imgbtn_1, 6, 7);
	lv_obj_set_size(ui->yangzhi_sc_imgbtn_1, 36, 32);
	lv_obj_set_scrollbar_mode(ui->yangzhi_sc_imgbtn_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_yangzhi_sc_imgbtn_1_main_main_default
	static lv_style_t style_yangzhi_sc_imgbtn_1_main_main_default;
	if (style_yangzhi_sc_imgbtn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_yangzhi_sc_imgbtn_1_main_main_default);
	else
		lv_style_init(&style_yangzhi_sc_imgbtn_1_main_main_default);
	lv_style_set_text_color(&style_yangzhi_sc_imgbtn_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_yangzhi_sc_imgbtn_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_yangzhi_sc_imgbtn_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_yangzhi_sc_imgbtn_1_main_main_default, 0);
	lv_style_set_img_opa(&style_yangzhi_sc_imgbtn_1_main_main_default, 255);
	lv_obj_add_style(ui->yangzhi_sc_imgbtn_1, &style_yangzhi_sc_imgbtn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_yangzhi_sc_imgbtn_1_main_main_pressed
	static lv_style_t style_yangzhi_sc_imgbtn_1_main_main_pressed;
	if (style_yangzhi_sc_imgbtn_1_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_yangzhi_sc_imgbtn_1_main_main_pressed);
	else
		lv_style_init(&style_yangzhi_sc_imgbtn_1_main_main_pressed);
	lv_style_set_text_color(&style_yangzhi_sc_imgbtn_1_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_yangzhi_sc_imgbtn_1_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_yangzhi_sc_imgbtn_1_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_yangzhi_sc_imgbtn_1_main_main_pressed, 0);
	lv_style_set_img_opa(&style_yangzhi_sc_imgbtn_1_main_main_pressed, 255);
	lv_obj_add_style(ui->yangzhi_sc_imgbtn_1, &style_yangzhi_sc_imgbtn_1_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_yangzhi_sc_imgbtn_1_main_main_checked
	static lv_style_t style_yangzhi_sc_imgbtn_1_main_main_checked;
	if (style_yangzhi_sc_imgbtn_1_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_yangzhi_sc_imgbtn_1_main_main_checked);
	else
		lv_style_init(&style_yangzhi_sc_imgbtn_1_main_main_checked);
	lv_style_set_text_color(&style_yangzhi_sc_imgbtn_1_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_yangzhi_sc_imgbtn_1_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_yangzhi_sc_imgbtn_1_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_yangzhi_sc_imgbtn_1_main_main_checked, 0);
	lv_style_set_img_opa(&style_yangzhi_sc_imgbtn_1_main_main_checked, 255);
	lv_obj_add_style(ui->yangzhi_sc_imgbtn_1, &style_yangzhi_sc_imgbtn_1_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->yangzhi_sc_imgbtn_1, LV_IMGBTN_STATE_RELEASED, NULL, &_fanhui2_alpha_36x32, NULL);
	lv_obj_add_flag(ui->yangzhi_sc_imgbtn_1, LV_OBJ_FLAG_CHECKABLE);

	//Write codes yangzhi_sc_btn_1
	ui->yangzhi_sc_btn_1 = lv_btn_create(ui->yangzhi_sc);
	lv_obj_set_pos(ui->yangzhi_sc_btn_1, 58, 95);
	lv_obj_set_size(ui->yangzhi_sc_btn_1, 64, 132);
	lv_obj_set_scrollbar_mode(ui->yangzhi_sc_btn_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_yangzhi_sc_btn_1_main_main_default
	static lv_style_t style_yangzhi_sc_btn_1_main_main_default;
	if (style_yangzhi_sc_btn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_yangzhi_sc_btn_1_main_main_default);
	else
		lv_style_init(&style_yangzhi_sc_btn_1_main_main_default);
	lv_style_set_radius(&style_yangzhi_sc_btn_1_main_main_default, 5);
	lv_style_set_bg_color(&style_yangzhi_sc_btn_1_main_main_default, lv_color_make(0x5b, 0xa8, 0xbd));
	lv_style_set_bg_grad_color(&style_yangzhi_sc_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_yangzhi_sc_btn_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_yangzhi_sc_btn_1_main_main_default, 255);
	lv_style_set_border_color(&style_yangzhi_sc_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_yangzhi_sc_btn_1_main_main_default, 0);
	lv_style_set_border_opa(&style_yangzhi_sc_btn_1_main_main_default, 255);
	lv_style_set_text_color(&style_yangzhi_sc_btn_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_yangzhi_sc_btn_1_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_align(&style_yangzhi_sc_btn_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->yangzhi_sc_btn_1, &style_yangzhi_sc_btn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->yangzhi_sc_btn_1_label = lv_label_create(ui->yangzhi_sc_btn_1);
	lv_label_set_text(ui->yangzhi_sc_btn_1_label, "疫\n苗\n接\n种");
	lv_obj_set_style_pad_all(ui->yangzhi_sc_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->yangzhi_sc_btn_1_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes yangzhi_sc_btn_2
	ui->yangzhi_sc_btn_2 = lv_btn_create(ui->yangzhi_sc);
	lv_obj_set_pos(ui->yangzhi_sc_btn_2, 166, 94);
	lv_obj_set_size(ui->yangzhi_sc_btn_2, 64, 132);
	lv_obj_set_scrollbar_mode(ui->yangzhi_sc_btn_2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_yangzhi_sc_btn_2_main_main_default
	static lv_style_t style_yangzhi_sc_btn_2_main_main_default;
	if (style_yangzhi_sc_btn_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_yangzhi_sc_btn_2_main_main_default);
	else
		lv_style_init(&style_yangzhi_sc_btn_2_main_main_default);
	lv_style_set_radius(&style_yangzhi_sc_btn_2_main_main_default, 5);
	lv_style_set_bg_color(&style_yangzhi_sc_btn_2_main_main_default, lv_color_make(0x5b, 0xa8, 0xb4));
	lv_style_set_bg_grad_color(&style_yangzhi_sc_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_yangzhi_sc_btn_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_yangzhi_sc_btn_2_main_main_default, 255);
	lv_style_set_border_color(&style_yangzhi_sc_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_yangzhi_sc_btn_2_main_main_default, 0);
	lv_style_set_border_opa(&style_yangzhi_sc_btn_2_main_main_default, 255);
	lv_style_set_text_color(&style_yangzhi_sc_btn_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_yangzhi_sc_btn_2_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_align(&style_yangzhi_sc_btn_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->yangzhi_sc_btn_2, &style_yangzhi_sc_btn_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->yangzhi_sc_btn_2_label = lv_label_create(ui->yangzhi_sc_btn_2);
	lv_label_set_text(ui->yangzhi_sc_btn_2_label, "疾\n病\n信\n息");
	lv_obj_set_style_pad_all(ui->yangzhi_sc_btn_2, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->yangzhi_sc_btn_2_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes yangzhi_sc_btn_3
	ui->yangzhi_sc_btn_3 = lv_btn_create(ui->yangzhi_sc);
	lv_obj_set_pos(ui->yangzhi_sc_btn_3, 276, 94);
	lv_obj_set_size(ui->yangzhi_sc_btn_3, 64, 132);
	lv_obj_set_scrollbar_mode(ui->yangzhi_sc_btn_3, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_yangzhi_sc_btn_3_main_main_default
	static lv_style_t style_yangzhi_sc_btn_3_main_main_default;
	if (style_yangzhi_sc_btn_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_yangzhi_sc_btn_3_main_main_default);
	else
		lv_style_init(&style_yangzhi_sc_btn_3_main_main_default);
	lv_style_set_radius(&style_yangzhi_sc_btn_3_main_main_default, 5);
	lv_style_set_bg_color(&style_yangzhi_sc_btn_3_main_main_default, lv_color_make(0x5b, 0xa8, 0xb4));
	lv_style_set_bg_grad_color(&style_yangzhi_sc_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_yangzhi_sc_btn_3_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_yangzhi_sc_btn_3_main_main_default, 255);
	lv_style_set_border_color(&style_yangzhi_sc_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_yangzhi_sc_btn_3_main_main_default, 0);
	lv_style_set_border_opa(&style_yangzhi_sc_btn_3_main_main_default, 255);
	lv_style_set_text_color(&style_yangzhi_sc_btn_3_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_yangzhi_sc_btn_3_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_align(&style_yangzhi_sc_btn_3_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->yangzhi_sc_btn_3, &style_yangzhi_sc_btn_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->yangzhi_sc_btn_3_label = lv_label_create(ui->yangzhi_sc_btn_3);
	lv_label_set_text(ui->yangzhi_sc_btn_3_label, "育\n种\n管\n理");
	lv_obj_set_style_pad_all(ui->yangzhi_sc_btn_3, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->yangzhi_sc_btn_3_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes yangzhi_sc_btn_4
	ui->yangzhi_sc_btn_4 = lv_btn_create(ui->yangzhi_sc);
	lv_obj_set_pos(ui->yangzhi_sc_btn_4, 381, 94);
	lv_obj_set_size(ui->yangzhi_sc_btn_4, 64, 132);
	lv_obj_set_scrollbar_mode(ui->yangzhi_sc_btn_4, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_yangzhi_sc_btn_4_main_main_default
	static lv_style_t style_yangzhi_sc_btn_4_main_main_default;
	if (style_yangzhi_sc_btn_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_yangzhi_sc_btn_4_main_main_default);
	else
		lv_style_init(&style_yangzhi_sc_btn_4_main_main_default);
	lv_style_set_radius(&style_yangzhi_sc_btn_4_main_main_default, 5);
	lv_style_set_bg_color(&style_yangzhi_sc_btn_4_main_main_default, lv_color_make(0x0a, 0xa8, 0xb4));
	lv_style_set_bg_grad_color(&style_yangzhi_sc_btn_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_yangzhi_sc_btn_4_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_yangzhi_sc_btn_4_main_main_default, 255);
	lv_style_set_border_color(&style_yangzhi_sc_btn_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_yangzhi_sc_btn_4_main_main_default, 0);
	lv_style_set_border_opa(&style_yangzhi_sc_btn_4_main_main_default, 255);
	lv_style_set_text_color(&style_yangzhi_sc_btn_4_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_yangzhi_sc_btn_4_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_align(&style_yangzhi_sc_btn_4_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->yangzhi_sc_btn_4, &style_yangzhi_sc_btn_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->yangzhi_sc_btn_4_label = lv_label_create(ui->yangzhi_sc_btn_4);
	//lv_label_set_text(ui->yangzhi_sc_btn_4_label, "其\n他");
	lv_label_set_text(ui->yangzhi_sc_btn_4_label, "圈\n舍\n管\n理");
	lv_obj_set_style_pad_all(ui->yangzhi_sc_btn_4, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->yangzhi_sc_btn_4_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes yangzhi_sc_label_1
	ui->yangzhi_sc_label_1 = lv_label_create(ui->yangzhi_sc);
	lv_obj_set_pos(ui->yangzhi_sc_label_1, 132, 280);
	lv_obj_set_size(ui->yangzhi_sc_label_1, 239, 32);
	lv_obj_set_scrollbar_mode(ui->yangzhi_sc_label_1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->yangzhi_sc_label_1, "欢迎使用：请正确使用读卡器。");
	lv_label_set_long_mode(ui->yangzhi_sc_label_1, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_yangzhi_sc_label_1_main_main_default
	static lv_style_t style_yangzhi_sc_label_1_main_main_default;
	if (style_yangzhi_sc_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_yangzhi_sc_label_1_main_main_default);
	else
		lv_style_init(&style_yangzhi_sc_label_1_main_main_default);
	lv_style_set_radius(&style_yangzhi_sc_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_yangzhi_sc_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_yangzhi_sc_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_yangzhi_sc_label_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_yangzhi_sc_label_1_main_main_default, 0);
	lv_style_set_text_color(&style_yangzhi_sc_label_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_yangzhi_sc_label_1_main_main_default, &lv_font_simsun_14);
	lv_style_set_text_letter_space(&style_yangzhi_sc_label_1_main_main_default, 2);
	lv_style_set_text_line_space(&style_yangzhi_sc_label_1_main_main_default, 0);
	lv_style_set_text_align(&style_yangzhi_sc_label_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_yangzhi_sc_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_yangzhi_sc_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_yangzhi_sc_label_1_main_main_default, 8);
	lv_style_set_pad_bottom(&style_yangzhi_sc_label_1_main_main_default, 0);
	lv_obj_add_style(ui->yangzhi_sc_label_1, &style_yangzhi_sc_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Init events for screen
	events_init_yangzhi_sc(ui);
}