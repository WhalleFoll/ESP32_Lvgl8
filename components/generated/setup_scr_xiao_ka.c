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
extern u_int8_t xiaoka;

void setup_scr_xiao_ka(lv_ui *ui){

	//Write codes xiao_ka
	ui->xiao_ka = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->xiao_ka, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_xiao_ka_main_main_default
	static lv_style_t style_xiao_ka_main_main_default;
	if (style_xiao_ka_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_xiao_ka_main_main_default);
	else
		lv_style_init(&style_xiao_ka_main_main_default);
	lv_style_set_bg_color(&style_xiao_ka_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_xiao_ka_main_main_default, 0);
	lv_obj_add_style(ui->xiao_ka, &style_xiao_ka_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes xiao_ka_imgbtn_1
	ui->xiao_ka_imgbtn_1 = lv_imgbtn_create(ui->xiao_ka);
	lv_obj_set_pos(ui->xiao_ka_imgbtn_1, 4, 4);
	lv_obj_set_size(ui->xiao_ka_imgbtn_1, 32, 32);
	lv_obj_set_scrollbar_mode(ui->xiao_ka_imgbtn_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_xiao_ka_imgbtn_1_main_main_default
	static lv_style_t style_xiao_ka_imgbtn_1_main_main_default;
	if (style_xiao_ka_imgbtn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_xiao_ka_imgbtn_1_main_main_default);
	else
		lv_style_init(&style_xiao_ka_imgbtn_1_main_main_default);
	lv_style_set_text_color(&style_xiao_ka_imgbtn_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_xiao_ka_imgbtn_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_xiao_ka_imgbtn_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_xiao_ka_imgbtn_1_main_main_default, 0);
	lv_style_set_img_opa(&style_xiao_ka_imgbtn_1_main_main_default, 255);
	lv_obj_add_style(ui->xiao_ka_imgbtn_1, &style_xiao_ka_imgbtn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_xiao_ka_imgbtn_1_main_main_pressed
	static lv_style_t style_xiao_ka_imgbtn_1_main_main_pressed;
	if (style_xiao_ka_imgbtn_1_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_xiao_ka_imgbtn_1_main_main_pressed);
	else
		lv_style_init(&style_xiao_ka_imgbtn_1_main_main_pressed);
	lv_style_set_text_color(&style_xiao_ka_imgbtn_1_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_xiao_ka_imgbtn_1_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_xiao_ka_imgbtn_1_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_xiao_ka_imgbtn_1_main_main_pressed, 0);
	lv_style_set_img_opa(&style_xiao_ka_imgbtn_1_main_main_pressed, 255);
	lv_obj_add_style(ui->xiao_ka_imgbtn_1, &style_xiao_ka_imgbtn_1_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_xiao_ka_imgbtn_1_main_main_checked
	static lv_style_t style_xiao_ka_imgbtn_1_main_main_checked;
	if (style_xiao_ka_imgbtn_1_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_xiao_ka_imgbtn_1_main_main_checked);
	else
		lv_style_init(&style_xiao_ka_imgbtn_1_main_main_checked);
	lv_style_set_text_color(&style_xiao_ka_imgbtn_1_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_xiao_ka_imgbtn_1_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_xiao_ka_imgbtn_1_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_xiao_ka_imgbtn_1_main_main_checked, 0);
	lv_style_set_img_opa(&style_xiao_ka_imgbtn_1_main_main_checked, 255);
	lv_obj_add_style(ui->xiao_ka_imgbtn_1, &style_xiao_ka_imgbtn_1_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->xiao_ka_imgbtn_1, LV_IMGBTN_STATE_RELEASED, NULL, &_fanhui2_alpha_32x32, NULL);
	lv_imgbtn_set_src(ui->xiao_ka_imgbtn_1, LV_IMGBTN_STATE_PRESSED, NULL, &_fanhui2_alpha_32x32, NULL);
	lv_obj_add_flag(ui->xiao_ka_imgbtn_1, LV_OBJ_FLAG_CHECKABLE);

	//Write codes xiao_ka_label_1
	ui->xiao_ka_label_1 = lv_label_create(ui->xiao_ka);
	lv_obj_set_pos(ui->xiao_ka_label_1, 36, 73);
	lv_obj_set_size(ui->xiao_ka_label_1, 119, 32);
	lv_obj_set_scrollbar_mode(ui->xiao_ka_label_1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->xiao_ka_label_1, "当前耳标：");
	lv_label_set_long_mode(ui->xiao_ka_label_1, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_xiao_ka_label_1_main_main_default
	static lv_style_t style_xiao_ka_label_1_main_main_default;
	if (style_xiao_ka_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_xiao_ka_label_1_main_main_default);
	else
		lv_style_init(&style_xiao_ka_label_1_main_main_default);
	lv_style_set_radius(&style_xiao_ka_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_xiao_ka_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_xiao_ka_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_xiao_ka_label_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_xiao_ka_label_1_main_main_default, 255);
	lv_style_set_text_color(&style_xiao_ka_label_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_xiao_ka_label_1_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_xiao_ka_label_1_main_main_default, 2);
	lv_style_set_text_line_space(&style_xiao_ka_label_1_main_main_default, 0);
	lv_style_set_text_align(&style_xiao_ka_label_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_xiao_ka_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_xiao_ka_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_xiao_ka_label_1_main_main_default, 8);
	lv_style_set_pad_bottom(&style_xiao_ka_label_1_main_main_default, 0);
	lv_obj_add_style(ui->xiao_ka_label_1, &style_xiao_ka_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes xiao_ka_label_2
	ui->xiao_ka_label_2 = lv_label_create(ui->xiao_ka);
	lv_obj_set_pos(ui->xiao_ka_label_2, 180, 73);
	lv_obj_set_size(ui->xiao_ka_label_2, 145, 32);
	lv_obj_set_scrollbar_mode(ui->xiao_ka_label_2, LV_SCROLLBAR_MODE_OFF);
	//lv_label_set_text(ui->xiao_ka_label_2, "12345");
	lv_label_set_text_fmt(ui->xiao_ka_label_2,"%d",ear_id_n);
	lv_label_set_long_mode(ui->xiao_ka_label_2, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_xiao_ka_label_2_main_main_default
	static lv_style_t style_xiao_ka_label_2_main_main_default;
	if (style_xiao_ka_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_xiao_ka_label_2_main_main_default);
	else
		lv_style_init(&style_xiao_ka_label_2_main_main_default);
	lv_style_set_radius(&style_xiao_ka_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_xiao_ka_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_xiao_ka_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_xiao_ka_label_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_xiao_ka_label_2_main_main_default, 145);
	lv_style_set_text_color(&style_xiao_ka_label_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_xiao_ka_label_2_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_xiao_ka_label_2_main_main_default, 2);
	lv_style_set_text_line_space(&style_xiao_ka_label_2_main_main_default, 0);
	lv_style_set_text_align(&style_xiao_ka_label_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_xiao_ka_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_xiao_ka_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_xiao_ka_label_2_main_main_default, 8);
	lv_style_set_pad_bottom(&style_xiao_ka_label_2_main_main_default, 0);
	lv_obj_add_style(ui->xiao_ka_label_2, &style_xiao_ka_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes xiao_ka_btn_1
	ui->xiao_ka_btn_1 = lv_btn_create(ui->xiao_ka);
	lv_obj_set_pos(ui->xiao_ka_btn_1, 335, 243);
	lv_obj_set_size(ui->xiao_ka_btn_1, 100, 50);
	lv_obj_set_scrollbar_mode(ui->xiao_ka_btn_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_xiao_ka_btn_1_main_main_default
	static lv_style_t style_xiao_ka_btn_1_main_main_default;
	if (style_xiao_ka_btn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_xiao_ka_btn_1_main_main_default);
	else
		lv_style_init(&style_xiao_ka_btn_1_main_main_default);
	lv_style_set_radius(&style_xiao_ka_btn_1_main_main_default, 5);
	lv_style_set_bg_color(&style_xiao_ka_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_xiao_ka_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_xiao_ka_btn_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_xiao_ka_btn_1_main_main_default, 255);
	lv_style_set_border_color(&style_xiao_ka_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_xiao_ka_btn_1_main_main_default, 0);
	lv_style_set_border_opa(&style_xiao_ka_btn_1_main_main_default, 255);
	lv_style_set_text_color(&style_xiao_ka_btn_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_xiao_ka_btn_1_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_align(&style_xiao_ka_btn_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->xiao_ka_btn_1, &style_xiao_ka_btn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->xiao_ka_btn_1_label = lv_label_create(ui->xiao_ka_btn_1);
	lv_label_set_text(ui->xiao_ka_btn_1_label, "销卡");
	lv_obj_set_style_pad_all(ui->xiao_ka_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->xiao_ka_btn_1_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes xiao_ka_btn_3
	ui->xiao_ka_btn_3 = lv_btn_create(ui->xiao_ka);
	lv_obj_set_pos(ui->xiao_ka_btn_3, 202, 243);
	lv_obj_set_size(ui->xiao_ka_btn_3, 100, 50);
	lv_obj_set_scrollbar_mode(ui->xiao_ka_btn_3, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_xiao_ka_btn_3_main_main_default
	static lv_style_t style_xiao_ka_btn_3_main_main_default;
	if (style_xiao_ka_btn_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_xiao_ka_btn_3_main_main_default);
	else
		lv_style_init(&style_xiao_ka_btn_3_main_main_default);
	lv_style_set_radius(&style_xiao_ka_btn_3_main_main_default, 5);
	lv_style_set_bg_color(&style_xiao_ka_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_xiao_ka_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_xiao_ka_btn_3_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_xiao_ka_btn_3_main_main_default, 255);
	lv_style_set_border_color(&style_xiao_ka_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_xiao_ka_btn_3_main_main_default, 0);
	lv_style_set_border_opa(&style_xiao_ka_btn_3_main_main_default, 255);
	lv_style_set_text_color(&style_xiao_ka_btn_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_xiao_ka_btn_3_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_align(&style_xiao_ka_btn_3_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->xiao_ka_btn_3, &style_xiao_ka_btn_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->xiao_ka_btn_3_label = lv_label_create(ui->xiao_ka_btn_3);
	lv_label_set_text(ui->xiao_ka_btn_3_label, "刷新");
	lv_obj_set_style_pad_all(ui->xiao_ka_btn_3, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->xiao_ka_btn_3_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes xiao_ka_label_3
	ui->xiao_ka_label_3 = lv_label_create(ui->xiao_ka);
	lv_obj_set_pos(ui->xiao_ka_label_3, 36, 125);
	lv_obj_set_size(ui->xiao_ka_label_3, 119, 32);
	lv_obj_set_scrollbar_mode(ui->xiao_ka_label_3, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->xiao_ka_label_3, "状态：");
	lv_label_set_long_mode(ui->xiao_ka_label_3, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_xiao_ka_label_3_main_main_default
	static lv_style_t style_xiao_ka_label_3_main_main_default;
	if (style_xiao_ka_label_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_xiao_ka_label_3_main_main_default);
	else
		lv_style_init(&style_xiao_ka_label_3_main_main_default);
	lv_style_set_radius(&style_xiao_ka_label_3_main_main_default, 0);
	lv_style_set_bg_color(&style_xiao_ka_label_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_xiao_ka_label_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_xiao_ka_label_3_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_xiao_ka_label_3_main_main_default, 255);
	lv_style_set_text_color(&style_xiao_ka_label_3_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_xiao_ka_label_3_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_xiao_ka_label_3_main_main_default, 2);
	lv_style_set_text_line_space(&style_xiao_ka_label_3_main_main_default, 0);
	lv_style_set_text_align(&style_xiao_ka_label_3_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_xiao_ka_label_3_main_main_default, 0);
	lv_style_set_pad_right(&style_xiao_ka_label_3_main_main_default, 0);
	lv_style_set_pad_top(&style_xiao_ka_label_3_main_main_default, 8);
	lv_style_set_pad_bottom(&style_xiao_ka_label_3_main_main_default, 0);
	lv_obj_add_style(ui->xiao_ka_label_3, &style_xiao_ka_label_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes xiao_ka_label_4
	ui->xiao_ka_label_4 = lv_label_create(ui->xiao_ka);
	lv_obj_set_pos(ui->xiao_ka_label_4, 180, 125);
	lv_obj_set_size(ui->xiao_ka_label_4, 145, 32);
	lv_obj_set_scrollbar_mode(ui->xiao_ka_label_4, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->xiao_ka_label_4, "被使用");
	lv_label_set_long_mode(ui->xiao_ka_label_4, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_xiao_ka_label_4_main_main_default
	static lv_style_t style_xiao_ka_label_4_main_main_default;
	if (style_xiao_ka_label_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_xiao_ka_label_4_main_main_default);
	else
		lv_style_init(&style_xiao_ka_label_4_main_main_default);
	lv_style_set_radius(&style_xiao_ka_label_4_main_main_default, 0);
	lv_style_set_bg_color(&style_xiao_ka_label_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_xiao_ka_label_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_xiao_ka_label_4_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_xiao_ka_label_4_main_main_default, 141);
	lv_style_set_text_color(&style_xiao_ka_label_4_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_xiao_ka_label_4_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_xiao_ka_label_4_main_main_default, 2);
	lv_style_set_text_line_space(&style_xiao_ka_label_4_main_main_default, 0);
	lv_style_set_text_align(&style_xiao_ka_label_4_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_xiao_ka_label_4_main_main_default, 0);
	lv_style_set_pad_right(&style_xiao_ka_label_4_main_main_default, 0);
	lv_style_set_pad_top(&style_xiao_ka_label_4_main_main_default, 8);
	lv_style_set_pad_bottom(&style_xiao_ka_label_4_main_main_default, 0);
	lv_obj_add_style(ui->xiao_ka_label_4, &style_xiao_ka_label_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Init events for screen
	events_init_xiao_ka(ui);
}