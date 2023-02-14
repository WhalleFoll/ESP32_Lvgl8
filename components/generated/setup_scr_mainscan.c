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


extern u_int16_t time_year;
extern u_int8_t time_month;
extern u_int8_t time_day;

extern char *time_weekend; 


extern u_int8_t sheep_zong;

static const lv_img_dsc_t* mainscan_animimg_1_imgs[5] = {
	&mainscan_animimg_1sheep_4_00,
	&mainscan_animimg_1sheep_4_01,
	&mainscan_animimg_1sheep_4_02,
	&mainscan_animimg_1sheep_4_03,
	&mainscan_animimg_1sheep_4_04
};

void setup_scr_mainscan(lv_ui *ui){

	//Write codes mainscan
	ui->mainscan = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->mainscan, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_mainscan_main_main_default
	static lv_style_t style_mainscan_main_main_default;
	if (style_mainscan_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_mainscan_main_main_default);
	else
		lv_style_init(&style_mainscan_main_main_default);
	lv_style_set_bg_color(&style_mainscan_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_mainscan_main_main_default, 122);
	lv_obj_add_style(ui->mainscan, &style_mainscan_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes mainscan_btn_1
	ui->mainscan_btn_1 = lv_btn_create(ui->mainscan);
	lv_obj_set_pos(ui->mainscan_btn_1, 56, 76);
	lv_obj_set_size(ui->mainscan_btn_1, 160, 80);
	lv_obj_set_scrollbar_mode(ui->mainscan_btn_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_mainscan_btn_1_main_main_default
	static lv_style_t style_mainscan_btn_1_main_main_default;
	if (style_mainscan_btn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_mainscan_btn_1_main_main_default);
	else
		lv_style_init(&style_mainscan_btn_1_main_main_default);
	lv_style_set_radius(&style_mainscan_btn_1_main_main_default, 5);
	lv_style_set_bg_color(&style_mainscan_btn_1_main_main_default, lv_color_make(0x5b, 0xd1, 0xd7));
	lv_style_set_bg_grad_color(&style_mainscan_btn_1_main_main_default, lv_color_make(0x5b, 0xd1, 0xd7));
	lv_style_set_bg_grad_dir(&style_mainscan_btn_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_mainscan_btn_1_main_main_default, 255);
	lv_style_set_border_color(&style_mainscan_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_mainscan_btn_1_main_main_default, 0);
	lv_style_set_border_opa(&style_mainscan_btn_1_main_main_default, 255);
	lv_style_set_text_color(&style_mainscan_btn_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_mainscan_btn_1_main_main_default, &lv_font_simsun_18);
	lv_style_set_text_align(&style_mainscan_btn_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->mainscan_btn_1, &style_mainscan_btn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->mainscan_btn_1_label = lv_label_create(ui->mainscan_btn_1);
	lv_label_set_text(ui->mainscan_btn_1_label, "养殖管理");
	lv_obj_set_style_pad_all(ui->mainscan_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->mainscan_btn_1_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes mainscan_btn_2
	ui->mainscan_btn_2 = lv_btn_create(ui->mainscan);
	lv_obj_set_pos(ui->mainscan_btn_2, 265, 76);
	lv_obj_set_size(ui->mainscan_btn_2, 160, 80);
	lv_obj_set_scrollbar_mode(ui->mainscan_btn_2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_mainscan_btn_2_main_main_default
	static lv_style_t style_mainscan_btn_2_main_main_default;
	if (style_mainscan_btn_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_mainscan_btn_2_main_main_default);
	else
		lv_style_init(&style_mainscan_btn_2_main_main_default);
	lv_style_set_radius(&style_mainscan_btn_2_main_main_default, 5);
	lv_style_set_bg_color(&style_mainscan_btn_2_main_main_default, lv_color_make(0x34, 0x84, 0x98));
	lv_style_set_bg_grad_color(&style_mainscan_btn_2_main_main_default, lv_color_make(0x34, 0x84, 0x98));
	lv_style_set_bg_grad_dir(&style_mainscan_btn_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_mainscan_btn_2_main_main_default, 255);
	lv_style_set_border_color(&style_mainscan_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_mainscan_btn_2_main_main_default, 0);
	lv_style_set_border_opa(&style_mainscan_btn_2_main_main_default, 255);
	lv_style_set_text_color(&style_mainscan_btn_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_mainscan_btn_2_main_main_default, &lv_font_simsun_18);
	lv_style_set_text_align(&style_mainscan_btn_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->mainscan_btn_2, &style_mainscan_btn_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->mainscan_btn_2_label = lv_label_create(ui->mainscan_btn_2);
	lv_label_set_text(ui->mainscan_btn_2_label, "信息注册");
	lv_obj_set_style_pad_all(ui->mainscan_btn_2, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->mainscan_btn_2_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes mainscan_btn_3
	ui->mainscan_btn_3 = lv_btn_create(ui->mainscan);
	lv_obj_set_pos(ui->mainscan_btn_3, 56, 190);
	lv_obj_set_size(ui->mainscan_btn_3, 160, 80);
	lv_obj_set_scrollbar_mode(ui->mainscan_btn_3, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_mainscan_btn_3_main_main_default
	static lv_style_t style_mainscan_btn_3_main_main_default;
	if (style_mainscan_btn_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_mainscan_btn_3_main_main_default);
	else
		lv_style_init(&style_mainscan_btn_3_main_main_default);
	lv_style_set_radius(&style_mainscan_btn_3_main_main_default, 5);
	lv_style_set_bg_color(&style_mainscan_btn_3_main_main_default, lv_color_make(0x00, 0x4d, 0x61));
	lv_style_set_bg_grad_color(&style_mainscan_btn_3_main_main_default, lv_color_make(0x00, 0x4d, 0x61));
	lv_style_set_bg_grad_dir(&style_mainscan_btn_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_mainscan_btn_3_main_main_default, 255);
	lv_style_set_border_color(&style_mainscan_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_mainscan_btn_3_main_main_default, 0);
	lv_style_set_border_opa(&style_mainscan_btn_3_main_main_default, 255);
	lv_style_set_text_color(&style_mainscan_btn_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_mainscan_btn_3_main_main_default, &lv_font_simsun_18);
	lv_style_set_text_align(&style_mainscan_btn_3_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->mainscan_btn_3, &style_mainscan_btn_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->mainscan_btn_3_label = lv_label_create(ui->mainscan_btn_3);
	lv_label_set_text(ui->mainscan_btn_3_label, "来源追溯");
	lv_obj_set_style_pad_all(ui->mainscan_btn_3, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->mainscan_btn_3_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes mainscan_btn_4
	ui->mainscan_btn_4 = lv_btn_create(ui->mainscan);
	lv_obj_set_pos(ui->mainscan_btn_4, 265, 190);
	lv_obj_set_size(ui->mainscan_btn_4, 160, 80);
	lv_obj_set_scrollbar_mode(ui->mainscan_btn_4, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_mainscan_btn_4_main_main_default
	static lv_style_t style_mainscan_btn_4_main_main_default;
	if (style_mainscan_btn_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_mainscan_btn_4_main_main_default);
	else
		lv_style_init(&style_mainscan_btn_4_main_main_default);
	lv_style_set_radius(&style_mainscan_btn_4_main_main_default, 5);
	lv_style_set_bg_color(&style_mainscan_btn_4_main_main_default, lv_color_make(0xff, 0x50, 0x2b));
	lv_style_set_bg_grad_color(&style_mainscan_btn_4_main_main_default, lv_color_make(0xff, 0x50, 0x2b));
	lv_style_set_bg_grad_dir(&style_mainscan_btn_4_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_mainscan_btn_4_main_main_default, 255);
	lv_style_set_border_color(&style_mainscan_btn_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_mainscan_btn_4_main_main_default, 0);
	lv_style_set_border_opa(&style_mainscan_btn_4_main_main_default, 255);
	lv_style_set_text_color(&style_mainscan_btn_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_mainscan_btn_4_main_main_default, &lv_font_simsun_18);
	lv_style_set_text_align(&style_mainscan_btn_4_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->mainscan_btn_4, &style_mainscan_btn_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->mainscan_btn_4_label = lv_label_create(ui->mainscan_btn_4);
	lv_label_set_text(ui->mainscan_btn_4_label, "耳标管理");
	lv_obj_set_style_pad_all(ui->mainscan_btn_4, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->mainscan_btn_4_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes mainscan_label_1
	ui->mainscan_label_1 = lv_label_create(ui->mainscan);
	lv_obj_set_pos(ui->mainscan_label_1, 104.5, 288);
	lv_obj_set_size(ui->mainscan_label_1, 271, 21);
	lv_obj_set_scrollbar_mode(ui->mainscan_label_1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->mainscan_label_1, "欢迎使用绵羊耳标管理系统.");
	lv_label_set_long_mode(ui->mainscan_label_1, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_mainscan_label_1_main_main_default
	static lv_style_t style_mainscan_label_1_main_main_default;
	if (style_mainscan_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_mainscan_label_1_main_main_default);
	else
		lv_style_init(&style_mainscan_label_1_main_main_default);
	lv_style_set_radius(&style_mainscan_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_mainscan_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_mainscan_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_mainscan_label_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_mainscan_label_1_main_main_default, 0);
	lv_style_set_text_color(&style_mainscan_label_1_main_main_default, lv_color_make(0x0a, 0x0a, 0x0a));
	lv_style_set_text_font(&style_mainscan_label_1_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_mainscan_label_1_main_main_default, 2);
	lv_style_set_text_line_space(&style_mainscan_label_1_main_main_default, 0);
	lv_style_set_text_align(&style_mainscan_label_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_mainscan_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_mainscan_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_mainscan_label_1_main_main_default, 8);
	lv_style_set_pad_bottom(&style_mainscan_label_1_main_main_default, 0);
	lv_obj_add_style(ui->mainscan_label_1, &style_mainscan_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes mainscan_imgbtn_1
	ui->mainscan_imgbtn_1 = lv_imgbtn_create(ui->mainscan);
	lv_obj_set_pos(ui->mainscan_imgbtn_1, 374, 1);
	lv_obj_set_size(ui->mainscan_imgbtn_1, 32, 32);
	lv_obj_set_scrollbar_mode(ui->mainscan_imgbtn_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_mainscan_imgbtn_1_main_main_default
	static lv_style_t style_mainscan_imgbtn_1_main_main_default;
	if (style_mainscan_imgbtn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_mainscan_imgbtn_1_main_main_default);
	else
		lv_style_init(&style_mainscan_imgbtn_1_main_main_default);
	lv_style_set_text_color(&style_mainscan_imgbtn_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_mainscan_imgbtn_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_mainscan_imgbtn_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_mainscan_imgbtn_1_main_main_default, 0);
	lv_style_set_img_opa(&style_mainscan_imgbtn_1_main_main_default, 255);
	lv_obj_add_style(ui->mainscan_imgbtn_1, &style_mainscan_imgbtn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_mainscan_imgbtn_1_main_main_pressed
	static lv_style_t style_mainscan_imgbtn_1_main_main_pressed;
	if (style_mainscan_imgbtn_1_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_mainscan_imgbtn_1_main_main_pressed);
	else
		lv_style_init(&style_mainscan_imgbtn_1_main_main_pressed);
	lv_style_set_text_color(&style_mainscan_imgbtn_1_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_mainscan_imgbtn_1_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_mainscan_imgbtn_1_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_mainscan_imgbtn_1_main_main_pressed, 0);
	lv_style_set_img_opa(&style_mainscan_imgbtn_1_main_main_pressed, 255);
	lv_obj_add_style(ui->mainscan_imgbtn_1, &style_mainscan_imgbtn_1_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_mainscan_imgbtn_1_main_main_checked
	static lv_style_t style_mainscan_imgbtn_1_main_main_checked;
	if (style_mainscan_imgbtn_1_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_mainscan_imgbtn_1_main_main_checked);
	else
		lv_style_init(&style_mainscan_imgbtn_1_main_main_checked);
	lv_style_set_text_color(&style_mainscan_imgbtn_1_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_mainscan_imgbtn_1_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_mainscan_imgbtn_1_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_mainscan_imgbtn_1_main_main_checked, 0);
	lv_style_set_img_opa(&style_mainscan_imgbtn_1_main_main_checked, 255);
	lv_obj_add_style(ui->mainscan_imgbtn_1, &style_mainscan_imgbtn_1_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->mainscan_imgbtn_1, LV_IMGBTN_STATE_RELEASED, NULL, &_set_u_alpha_32x32, NULL);
	lv_imgbtn_set_src(ui->mainscan_imgbtn_1, LV_IMGBTN_STATE_PRESSED, NULL, &_set_u_alpha_32x32, NULL);
	lv_obj_add_flag(ui->mainscan_imgbtn_1, LV_OBJ_FLAG_CHECKABLE);

	//Write codes mainscan_imgbtn_2
	ui->mainscan_imgbtn_2 = lv_imgbtn_create(ui->mainscan);
	lv_obj_set_pos(ui->mainscan_imgbtn_2, 340, 1);
	lv_obj_set_size(ui->mainscan_imgbtn_2, 32, 32);
	lv_obj_set_scrollbar_mode(ui->mainscan_imgbtn_2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_mainscan_imgbtn_2_main_main_default
	static lv_style_t style_mainscan_imgbtn_2_main_main_default;
	if (style_mainscan_imgbtn_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_mainscan_imgbtn_2_main_main_default);
	else
		lv_style_init(&style_mainscan_imgbtn_2_main_main_default);
	lv_style_set_text_color(&style_mainscan_imgbtn_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_mainscan_imgbtn_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_mainscan_imgbtn_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_mainscan_imgbtn_2_main_main_default, 0);
	lv_style_set_img_opa(&style_mainscan_imgbtn_2_main_main_default, 255);
	lv_obj_add_style(ui->mainscan_imgbtn_2, &style_mainscan_imgbtn_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_mainscan_imgbtn_2_main_main_pressed
	static lv_style_t style_mainscan_imgbtn_2_main_main_pressed;
	if (style_mainscan_imgbtn_2_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_mainscan_imgbtn_2_main_main_pressed);
	else
		lv_style_init(&style_mainscan_imgbtn_2_main_main_pressed);
	lv_style_set_text_color(&style_mainscan_imgbtn_2_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_mainscan_imgbtn_2_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_mainscan_imgbtn_2_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_mainscan_imgbtn_2_main_main_pressed, 0);
	lv_style_set_img_opa(&style_mainscan_imgbtn_2_main_main_pressed, 255);
	lv_obj_add_style(ui->mainscan_imgbtn_2, &style_mainscan_imgbtn_2_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_mainscan_imgbtn_2_main_main_checked
	static lv_style_t style_mainscan_imgbtn_2_main_main_checked;
	if (style_mainscan_imgbtn_2_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_mainscan_imgbtn_2_main_main_checked);
	else
		lv_style_init(&style_mainscan_imgbtn_2_main_main_checked);
	lv_style_set_text_color(&style_mainscan_imgbtn_2_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_mainscan_imgbtn_2_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_mainscan_imgbtn_2_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_mainscan_imgbtn_2_main_main_checked, 0);
	lv_style_set_img_opa(&style_mainscan_imgbtn_2_main_main_checked, 255);
	lv_obj_add_style(ui->mainscan_imgbtn_2, &style_mainscan_imgbtn_2_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->mainscan_imgbtn_2, LV_IMGBTN_STATE_RELEASED, NULL, &_help_alpha_32x32, NULL);
	lv_imgbtn_set_src(ui->mainscan_imgbtn_2, LV_IMGBTN_STATE_PRESSED, NULL, &_help_alpha_32x32, NULL);
	lv_obj_add_flag(ui->mainscan_imgbtn_2, LV_OBJ_FLAG_CHECKABLE);

	//Write codes mainscan_animimg_1
	ui->mainscan_animimg_1 = lv_animimg_create(ui->mainscan);
	lv_obj_set_pos(ui->mainscan_animimg_1, 419, 262);
	lv_obj_set_size(ui->mainscan_animimg_1, 48, 47);
	lv_obj_set_scrollbar_mode(ui->mainscan_animimg_1, LV_SCROLLBAR_MODE_OFF);
	lv_animimg_set_src(ui->mainscan_animimg_1, (const void **) mainscan_animimg_1_imgs, 5);
	lv_animimg_set_duration(ui->mainscan_animimg_1, 150);
	lv_animimg_set_repeat_count(ui->mainscan_animimg_1, 3000);
	lv_animimg_start(ui->mainscan_animimg_1);

	//Write codes mainscan_label_2
	ui->mainscan_label_2 = lv_label_create(ui->mainscan);
	lv_obj_set_pos(ui->mainscan_label_2, 1, 1);
	lv_obj_set_size(ui->mainscan_label_2, 47, 30);
	lv_obj_set_scrollbar_mode(ui->mainscan_label_2, LV_SCROLLBAR_MODE_OFF);
	//lv_label_set_text(ui->mainscan_label_2, time_year);
	lv_label_set_text_fmt(ui->mainscan_label_2,"%d",time_year);
	lv_label_set_long_mode(ui->mainscan_label_2, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_mainscan_label_2_main_main_default
	static lv_style_t style_mainscan_label_2_main_main_default;
	if (style_mainscan_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_mainscan_label_2_main_main_default);
	else
		lv_style_init(&style_mainscan_label_2_main_main_default);
	lv_style_set_radius(&style_mainscan_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_mainscan_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_mainscan_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_mainscan_label_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_mainscan_label_2_main_main_default, 0);
	lv_style_set_text_color(&style_mainscan_label_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_mainscan_label_2_main_main_default, &lv_font_simsun_14);
	lv_style_set_text_letter_space(&style_mainscan_label_2_main_main_default, 2);
	lv_style_set_text_line_space(&style_mainscan_label_2_main_main_default, 0);
	lv_style_set_text_align(&style_mainscan_label_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_mainscan_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_mainscan_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_mainscan_label_2_main_main_default, 8);
	lv_style_set_pad_bottom(&style_mainscan_label_2_main_main_default, 0);
	lv_obj_add_style(ui->mainscan_label_2, &style_mainscan_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes mainscan_label_3
	ui->mainscan_label_3 = lv_label_create(ui->mainscan);
	lv_obj_set_pos(ui->mainscan_label_3, 51, 1);
	lv_obj_set_size(ui->mainscan_label_3, 26, 30);
	lv_obj_set_scrollbar_mode(ui->mainscan_label_3, LV_SCROLLBAR_MODE_OFF);
	//lv_label_set_text(ui->mainscan_label_3, time_month);
	lv_label_set_text_fmt(ui->mainscan_label_3,"%d",time_month);
	lv_label_set_long_mode(ui->mainscan_label_3, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_mainscan_label_3_main_main_default
	static lv_style_t style_mainscan_label_3_main_main_default;
	if (style_mainscan_label_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_mainscan_label_3_main_main_default);
	else
		lv_style_init(&style_mainscan_label_3_main_main_default);
	lv_style_set_radius(&style_mainscan_label_3_main_main_default, 0);
	lv_style_set_bg_color(&style_mainscan_label_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_mainscan_label_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_mainscan_label_3_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_mainscan_label_3_main_main_default, 0);
	lv_style_set_text_color(&style_mainscan_label_3_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_mainscan_label_3_main_main_default, &lv_font_simsun_14);
	lv_style_set_text_letter_space(&style_mainscan_label_3_main_main_default, 2);
	lv_style_set_text_line_space(&style_mainscan_label_3_main_main_default, 0);
	lv_style_set_text_align(&style_mainscan_label_3_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_mainscan_label_3_main_main_default, 0);
	lv_style_set_pad_right(&style_mainscan_label_3_main_main_default, 0);
	lv_style_set_pad_top(&style_mainscan_label_3_main_main_default, 8);
	lv_style_set_pad_bottom(&style_mainscan_label_3_main_main_default, 0);
	lv_obj_add_style(ui->mainscan_label_3, &style_mainscan_label_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes mainscan_label_4
	ui->mainscan_label_4 = lv_label_create(ui->mainscan);
	lv_obj_set_pos(ui->mainscan_label_4, 81, 1);
	lv_obj_set_size(ui->mainscan_label_4, 26, 30);
	lv_obj_set_scrollbar_mode(ui->mainscan_label_4, LV_SCROLLBAR_MODE_OFF);
	//lv_label_set_text(ui->mainscan_label_4, time_day2);
	lv_label_set_text_fmt(ui->mainscan_label_4,"%d",time_day);
	lv_label_set_long_mode(ui->mainscan_label_4, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_mainscan_label_4_main_main_default
	static lv_style_t style_mainscan_label_4_main_main_default;
	if (style_mainscan_label_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_mainscan_label_4_main_main_default);
	else
		lv_style_init(&style_mainscan_label_4_main_main_default);
	lv_style_set_radius(&style_mainscan_label_4_main_main_default, 0);
	lv_style_set_bg_color(&style_mainscan_label_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_mainscan_label_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_mainscan_label_4_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_mainscan_label_4_main_main_default, 0);
	lv_style_set_text_color(&style_mainscan_label_4_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_mainscan_label_4_main_main_default, &lv_font_simsun_14);
	lv_style_set_text_letter_space(&style_mainscan_label_4_main_main_default, 2);
	lv_style_set_text_line_space(&style_mainscan_label_4_main_main_default, 0);
	lv_style_set_text_align(&style_mainscan_label_4_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_mainscan_label_4_main_main_default, 0);
	lv_style_set_pad_right(&style_mainscan_label_4_main_main_default, 0);
	lv_style_set_pad_top(&style_mainscan_label_4_main_main_default, 8);
	lv_style_set_pad_bottom(&style_mainscan_label_4_main_main_default, 0);
	lv_obj_add_style(ui->mainscan_label_4, &style_mainscan_label_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes mainscan_label_5
	ui->mainscan_label_5 = lv_label_create(ui->mainscan);
	lv_obj_set_pos(ui->mainscan_label_5, 47, 1);
	lv_obj_set_size(ui->mainscan_label_5, 7, 30);
	lv_obj_set_scrollbar_mode(ui->mainscan_label_5, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->mainscan_label_5, "/");
	lv_label_set_long_mode(ui->mainscan_label_5, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_mainscan_label_5_main_main_default
	static lv_style_t style_mainscan_label_5_main_main_default;
	if (style_mainscan_label_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_mainscan_label_5_main_main_default);
	else
		lv_style_init(&style_mainscan_label_5_main_main_default);
	lv_style_set_radius(&style_mainscan_label_5_main_main_default, 0);
	lv_style_set_bg_color(&style_mainscan_label_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_mainscan_label_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_mainscan_label_5_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_mainscan_label_5_main_main_default, 0);
	lv_style_set_text_color(&style_mainscan_label_5_main_main_default, lv_color_make(0x06, 0x04, 0x04));
	lv_style_set_text_font(&style_mainscan_label_5_main_main_default, &lv_font_simsun_14);
	lv_style_set_text_letter_space(&style_mainscan_label_5_main_main_default, 2);
	lv_style_set_text_line_space(&style_mainscan_label_5_main_main_default, 0);
	lv_style_set_text_align(&style_mainscan_label_5_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_mainscan_label_5_main_main_default, 0);
	lv_style_set_pad_right(&style_mainscan_label_5_main_main_default, 0);
	lv_style_set_pad_top(&style_mainscan_label_5_main_main_default, 8);
	lv_style_set_pad_bottom(&style_mainscan_label_5_main_main_default, 0);
	lv_obj_add_style(ui->mainscan_label_5, &style_mainscan_label_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes mainscan_label_6
	ui->mainscan_label_6 = lv_label_create(ui->mainscan);
	lv_obj_set_pos(ui->mainscan_label_6, 76, 1);
	lv_obj_set_size(ui->mainscan_label_6, 8, 30);
	lv_obj_set_scrollbar_mode(ui->mainscan_label_6, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->mainscan_label_6, "/");
	lv_label_set_long_mode(ui->mainscan_label_6, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_mainscan_label_6_main_main_default
	static lv_style_t style_mainscan_label_6_main_main_default;
	if (style_mainscan_label_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_mainscan_label_6_main_main_default);
	else
		lv_style_init(&style_mainscan_label_6_main_main_default);
	lv_style_set_radius(&style_mainscan_label_6_main_main_default, 0);
	lv_style_set_bg_color(&style_mainscan_label_6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_mainscan_label_6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_mainscan_label_6_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_mainscan_label_6_main_main_default, 0);
	lv_style_set_text_color(&style_mainscan_label_6_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_mainscan_label_6_main_main_default, &lv_font_simsun_14);
	lv_style_set_text_letter_space(&style_mainscan_label_6_main_main_default, 2);
	lv_style_set_text_line_space(&style_mainscan_label_6_main_main_default, 0);
	lv_style_set_text_align(&style_mainscan_label_6_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_mainscan_label_6_main_main_default, 0);
	lv_style_set_pad_right(&style_mainscan_label_6_main_main_default, 0);
	lv_style_set_pad_top(&style_mainscan_label_6_main_main_default, 8);
	lv_style_set_pad_bottom(&style_mainscan_label_6_main_main_default, 0);
	lv_obj_add_style(ui->mainscan_label_6, &style_mainscan_label_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes mainscan_label_7
	ui->mainscan_label_7 = lv_label_create(ui->mainscan);
	lv_obj_set_pos(ui->mainscan_label_7, 108, 1);
	lv_obj_set_size(ui->mainscan_label_7, 37, 26);
	lv_obj_set_scrollbar_mode(ui->mainscan_label_7, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->mainscan_label_7, time_weekend);
	lv_label_set_long_mode(ui->mainscan_label_7, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_mainscan_label_7_main_main_default
	static lv_style_t style_mainscan_label_7_main_main_default;
	if (style_mainscan_label_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_mainscan_label_7_main_main_default);
	else
		lv_style_init(&style_mainscan_label_7_main_main_default);
	lv_style_set_radius(&style_mainscan_label_7_main_main_default, 0);
	lv_style_set_bg_color(&style_mainscan_label_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_mainscan_label_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_mainscan_label_7_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_mainscan_label_7_main_main_default, 0);
	lv_style_set_text_color(&style_mainscan_label_7_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_mainscan_label_7_main_main_default, &lv_font_simsun_14);
	lv_style_set_text_letter_space(&style_mainscan_label_7_main_main_default, 2);
	lv_style_set_text_line_space(&style_mainscan_label_7_main_main_default, 0);
	lv_style_set_text_align(&style_mainscan_label_7_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_mainscan_label_7_main_main_default, 0);
	lv_style_set_pad_right(&style_mainscan_label_7_main_main_default, 0);
	lv_style_set_pad_top(&style_mainscan_label_7_main_main_default, 8);
	lv_style_set_pad_bottom(&style_mainscan_label_7_main_main_default, 0);
	lv_obj_add_style(ui->mainscan_label_7, &style_mainscan_label_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes mainscan_imgbtn_3
	ui->mainscan_imgbtn_3 = lv_imgbtn_create(ui->mainscan);
	lv_obj_set_pos(ui->mainscan_imgbtn_3, 410, 1);
	lv_obj_set_size(ui->mainscan_imgbtn_3, 32, 32);
	lv_obj_set_scrollbar_mode(ui->mainscan_imgbtn_3, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_mainscan_imgbtn_3_main_main_default
	static lv_style_t style_mainscan_imgbtn_3_main_main_default;
	if (style_mainscan_imgbtn_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_mainscan_imgbtn_3_main_main_default);
	else
		lv_style_init(&style_mainscan_imgbtn_3_main_main_default);
	lv_style_set_text_color(&style_mainscan_imgbtn_3_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_mainscan_imgbtn_3_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_mainscan_imgbtn_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_mainscan_imgbtn_3_main_main_default, 0);
	lv_style_set_img_opa(&style_mainscan_imgbtn_3_main_main_default, 255);
	lv_obj_add_style(ui->mainscan_imgbtn_3, &style_mainscan_imgbtn_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_mainscan_imgbtn_3_main_main_pressed
	static lv_style_t style_mainscan_imgbtn_3_main_main_pressed;
	if (style_mainscan_imgbtn_3_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_mainscan_imgbtn_3_main_main_pressed);
	else
		lv_style_init(&style_mainscan_imgbtn_3_main_main_pressed);
	lv_style_set_text_color(&style_mainscan_imgbtn_3_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_mainscan_imgbtn_3_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_mainscan_imgbtn_3_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_mainscan_imgbtn_3_main_main_pressed, 0);
	lv_style_set_img_opa(&style_mainscan_imgbtn_3_main_main_pressed, 255);
	lv_obj_add_style(ui->mainscan_imgbtn_3, &style_mainscan_imgbtn_3_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_mainscan_imgbtn_3_main_main_checked
	static lv_style_t style_mainscan_imgbtn_3_main_main_checked;
	if (style_mainscan_imgbtn_3_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_mainscan_imgbtn_3_main_main_checked);
	else
		lv_style_init(&style_mainscan_imgbtn_3_main_main_checked);
	lv_style_set_text_color(&style_mainscan_imgbtn_3_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_mainscan_imgbtn_3_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_mainscan_imgbtn_3_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_mainscan_imgbtn_3_main_main_checked, 0);
	lv_style_set_img_opa(&style_mainscan_imgbtn_3_main_main_checked, 255);
	lv_obj_add_style(ui->mainscan_imgbtn_3, &style_mainscan_imgbtn_3_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->mainscan_imgbtn_3, LV_IMGBTN_STATE_RELEASED, NULL, &_tianqi2_alpha_32x32, NULL);
	lv_imgbtn_set_src(ui->mainscan_imgbtn_3, LV_IMGBTN_STATE_PRESSED, NULL, &_tianqi2_alpha_32x32, NULL);
	lv_obj_add_flag(ui->mainscan_imgbtn_3, LV_OBJ_FLAG_CHECKABLE);

	//Write codes mainscan_imgbtn_4
	ui->mainscan_imgbtn_4 = lv_imgbtn_create(ui->mainscan);
	lv_obj_set_pos(ui->mainscan_imgbtn_4, 444, 1);
	lv_obj_set_size(ui->mainscan_imgbtn_4, 32, 32);
	lv_obj_set_scrollbar_mode(ui->mainscan_imgbtn_4, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_mainscan_imgbtn_4_main_main_default
	static lv_style_t style_mainscan_imgbtn_4_main_main_default;
	if (style_mainscan_imgbtn_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_mainscan_imgbtn_4_main_main_default);
	else
		lv_style_init(&style_mainscan_imgbtn_4_main_main_default);
	lv_style_set_text_color(&style_mainscan_imgbtn_4_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_mainscan_imgbtn_4_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_mainscan_imgbtn_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_mainscan_imgbtn_4_main_main_default, 0);
	lv_style_set_img_opa(&style_mainscan_imgbtn_4_main_main_default, 255);
	lv_obj_add_style(ui->mainscan_imgbtn_4, &style_mainscan_imgbtn_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_mainscan_imgbtn_4_main_main_pressed
	static lv_style_t style_mainscan_imgbtn_4_main_main_pressed;
	if (style_mainscan_imgbtn_4_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_mainscan_imgbtn_4_main_main_pressed);
	else
		lv_style_init(&style_mainscan_imgbtn_4_main_main_pressed);
	lv_style_set_text_color(&style_mainscan_imgbtn_4_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_mainscan_imgbtn_4_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_mainscan_imgbtn_4_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_mainscan_imgbtn_4_main_main_pressed, 0);
	lv_style_set_img_opa(&style_mainscan_imgbtn_4_main_main_pressed, 255);
	lv_obj_add_style(ui->mainscan_imgbtn_4, &style_mainscan_imgbtn_4_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_mainscan_imgbtn_4_main_main_checked
	static lv_style_t style_mainscan_imgbtn_4_main_main_checked;
	if (style_mainscan_imgbtn_4_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_mainscan_imgbtn_4_main_main_checked);
	else
		lv_style_init(&style_mainscan_imgbtn_4_main_main_checked);
	lv_style_set_text_color(&style_mainscan_imgbtn_4_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_mainscan_imgbtn_4_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_mainscan_imgbtn_4_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_mainscan_imgbtn_4_main_main_checked, 0);
	lv_style_set_img_opa(&style_mainscan_imgbtn_4_main_main_checked, 255);
	lv_obj_add_style(ui->mainscan_imgbtn_4, &style_mainscan_imgbtn_4_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->mainscan_imgbtn_4, LV_IMGBTN_STATE_RELEASED, NULL, &_wifi_alpha_32x32, NULL);
	lv_imgbtn_set_src(ui->mainscan_imgbtn_4, LV_IMGBTN_STATE_PRESSED, NULL, &_wifi_alpha_32x32, NULL);
	lv_obj_add_flag(ui->mainscan_imgbtn_4, LV_OBJ_FLAG_CHECKABLE);

	//Write codes mainscan_label_8
	ui->mainscan_label_8 = lv_label_create(ui->mainscan);
	lv_obj_set_pos(ui->mainscan_label_8, 160, 1);
	lv_obj_set_size(ui->mainscan_label_8, 42, 26);
	lv_obj_set_scrollbar_mode(ui->mainscan_label_8, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->mainscan_label_8, "总数:");
	lv_label_set_long_mode(ui->mainscan_label_8, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_mainscan_label_8_main_main_default
	static lv_style_t style_mainscan_label_8_main_main_default;
	if (style_mainscan_label_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_mainscan_label_8_main_main_default);
	else
		lv_style_init(&style_mainscan_label_8_main_main_default);
	lv_style_set_radius(&style_mainscan_label_8_main_main_default, 0);
	lv_style_set_bg_color(&style_mainscan_label_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_mainscan_label_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_mainscan_label_8_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_mainscan_label_8_main_main_default, 0);
	lv_style_set_text_color(&style_mainscan_label_8_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_mainscan_label_8_main_main_default, &lv_font_simsun_14);
	lv_style_set_text_letter_space(&style_mainscan_label_8_main_main_default, 2);
	lv_style_set_text_line_space(&style_mainscan_label_8_main_main_default, 0);
	lv_style_set_text_align(&style_mainscan_label_8_main_main_default, LV_TEXT_ALIGN_LEFT);
	lv_style_set_pad_left(&style_mainscan_label_8_main_main_default, 0);
	lv_style_set_pad_right(&style_mainscan_label_8_main_main_default, 0);
	lv_style_set_pad_top(&style_mainscan_label_8_main_main_default, 8);
	lv_style_set_pad_bottom(&style_mainscan_label_8_main_main_default, 0);
	lv_obj_add_style(ui->mainscan_label_8, &style_mainscan_label_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes mainscan_label_9
	ui->mainscan_label_9 = lv_label_create(ui->mainscan);
	lv_obj_set_pos(ui->mainscan_label_9, 200, 1);
	lv_obj_set_size(ui->mainscan_label_9, 37, 28);
	lv_obj_set_scrollbar_mode(ui->mainscan_label_9, LV_SCROLLBAR_MODE_OFF);
	//lv_label_set_text(ui->mainscan_label_9, "12");
	lv_label_set_text_fmt(ui->mainscan_label_9,"%d",sheep_zong);
	lv_label_set_long_mode(ui->mainscan_label_9, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_mainscan_label_9_main_main_default
	static lv_style_t style_mainscan_label_9_main_main_default;
	if (style_mainscan_label_9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_mainscan_label_9_main_main_default);
	else
		lv_style_init(&style_mainscan_label_9_main_main_default);
	lv_style_set_radius(&style_mainscan_label_9_main_main_default, 0);
	lv_style_set_bg_color(&style_mainscan_label_9_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_mainscan_label_9_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_mainscan_label_9_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_mainscan_label_9_main_main_default, 0);
	lv_style_set_text_color(&style_mainscan_label_9_main_main_default, lv_color_make(0xa5, 0x09, 0x09));
	lv_style_set_text_font(&style_mainscan_label_9_main_main_default, &lv_font_simsun_14);
	lv_style_set_text_letter_space(&style_mainscan_label_9_main_main_default, 2);
	lv_style_set_text_line_space(&style_mainscan_label_9_main_main_default, 0);
	lv_style_set_text_align(&style_mainscan_label_9_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_mainscan_label_9_main_main_default, 0);
	lv_style_set_pad_right(&style_mainscan_label_9_main_main_default, 0);
	lv_style_set_pad_top(&style_mainscan_label_9_main_main_default, 8);
	lv_style_set_pad_bottom(&style_mainscan_label_9_main_main_default, 0);
	lv_obj_add_style(ui->mainscan_label_9, &style_mainscan_label_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Init events for screen
	events_init_mainscan(ui);
}