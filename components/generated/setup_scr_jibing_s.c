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


void setup_scr_jibing_s(lv_ui *ui){

	//Write codes jibing_s
	ui->jibing_s = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->jibing_s, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_jibing_s_main_main_default
	static lv_style_t style_jibing_s_main_main_default;
	if (style_jibing_s_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_jibing_s_main_main_default);
	else
		lv_style_init(&style_jibing_s_main_main_default);
	lv_style_set_bg_color(&style_jibing_s_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_jibing_s_main_main_default, 0);
	lv_obj_add_style(ui->jibing_s, &style_jibing_s_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes jibing_s_tileview_1
	ui->jibing_s_tileview_1 = lv_tileview_create(ui->jibing_s);
	lv_obj_set_pos(ui->jibing_s_tileview_1, 0, 0);
	lv_obj_set_size(ui->jibing_s_tileview_1, 480, 320);
	lv_obj_set_scrollbar_mode(ui->jibing_s_tileview_1, LV_SCROLLBAR_MODE_ON);

	//Write style state: LV_STATE_DEFAULT for style_jibing_s_tileview_1_main_main_default
	static lv_style_t style_jibing_s_tileview_1_main_main_default;
	if (style_jibing_s_tileview_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_jibing_s_tileview_1_main_main_default);
	else
		lv_style_init(&style_jibing_s_tileview_1_main_main_default);
	lv_style_set_radius(&style_jibing_s_tileview_1_main_main_default, 0);
	lv_style_set_bg_color(&style_jibing_s_tileview_1_main_main_default, lv_color_make(0xc7, 0xc7, 0xc7));
	lv_style_set_bg_grad_color(&style_jibing_s_tileview_1_main_main_default, lv_color_make(0xf6, 0xf6, 0xf6));
	lv_style_set_bg_grad_dir(&style_jibing_s_tileview_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_jibing_s_tileview_1_main_main_default, 255);
	lv_obj_add_style(ui->jibing_s_tileview_1, &style_jibing_s_tileview_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_jibing_s_tileview_1_main_scrollbar_default
	static lv_style_t style_jibing_s_tileview_1_main_scrollbar_default;
	if (style_jibing_s_tileview_1_main_scrollbar_default.prop_cnt > 1)
		lv_style_reset(&style_jibing_s_tileview_1_main_scrollbar_default);
	else
		lv_style_init(&style_jibing_s_tileview_1_main_scrollbar_default);
	lv_style_set_radius(&style_jibing_s_tileview_1_main_scrollbar_default, 0);
	lv_style_set_bg_color(&style_jibing_s_tileview_1_main_scrollbar_default, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_opa(&style_jibing_s_tileview_1_main_scrollbar_default, 255);
	lv_obj_add_style(ui->jibing_s_tileview_1, &style_jibing_s_tileview_1_main_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//add new tile jibing_s_tileview_1_tile_2
	ui->jibing_s_tileview_1_tile_2 = lv_tileview_add_tile(ui->jibing_s_tileview_1, 1 , 0, LV_DIR_LEFT);

	//Write codes jibing_s_spangroup_1
	ui->jibing_s_spangroup_1 = lv_spangroup_create(ui->jibing_s_tileview_1_tile_2);
	lv_obj_set_pos(ui->jibing_s_spangroup_1, 8, 46);
	lv_obj_set_size(ui->jibing_s_spangroup_1, 261, 172);
	lv_obj_set_scrollbar_mode(ui->jibing_s_spangroup_1, LV_SCROLLBAR_MODE_OFF);
	lv_spangroup_set_align(ui->jibing_s_spangroup_1, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->jibing_s_spangroup_1, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->jibing_s_spangroup_1, LV_SPAN_MODE_BREAK);

	//Write style state: LV_STATE_DEFAULT for style_jibing_s_spangroup_1_main_main_default
	static lv_style_t style_jibing_s_spangroup_1_main_main_default;
	if (style_jibing_s_spangroup_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_jibing_s_spangroup_1_main_main_default);
	else
		lv_style_init(&style_jibing_s_spangroup_1_main_main_default);
	lv_style_set_radius(&style_jibing_s_spangroup_1_main_main_default, 0);
	lv_style_set_bg_color(&style_jibing_s_spangroup_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_jibing_s_spangroup_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_jibing_s_spangroup_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_jibing_s_spangroup_1_main_main_default, 0);
	lv_style_set_border_color(&style_jibing_s_spangroup_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_jibing_s_spangroup_1_main_main_default, 0);
	lv_style_set_border_opa(&style_jibing_s_spangroup_1_main_main_default, 255);
	lv_style_set_pad_left(&style_jibing_s_spangroup_1_main_main_default, 0);
	lv_style_set_pad_right(&style_jibing_s_spangroup_1_main_main_default, 0);
	lv_style_set_pad_top(&style_jibing_s_spangroup_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_jibing_s_spangroup_1_main_main_default, 0);
	lv_obj_add_style(ui->jibing_s_spangroup_1, &style_jibing_s_spangroup_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//create spans
	lv_span_t *jibing_s_spangroup_1_span;

	//create a new span
	jibing_s_spangroup_1_span = lv_spangroup_new_span(ui->jibing_s_spangroup_1);
	lv_span_set_text(jibing_s_spangroup_1_span, "    该病以羊日渐消瘦，光吃草料不长膘为主要特征。\n    \n    治疗方法：抗蠕敏20毫升／千克体重，钙片0.4片/千克体重，鱼肝油0.4粒／千克体重，复合维生素B0.4片／千克体重，1日1次，连用5天。同时要加强饲养管理，适当增加精饲料的饲喂量，供给充足清洁的饮水。");
	lv_style_set_text_color(&jibing_s_spangroup_1_span->style, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_decor(&jibing_s_spangroup_1_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&jibing_s_spangroup_1_span->style, &lv_font_simsun_14);
	lv_spangroup_refr_mode(ui->jibing_s_spangroup_1);

	//Write codes jibing_s_label_2
	ui->jibing_s_label_2 = lv_label_create(ui->jibing_s_tileview_1_tile_2);
	lv_obj_set_pos(ui->jibing_s_label_2, 40, 5);
	lv_obj_set_size(ui->jibing_s_label_2, 100, 32);
	lv_obj_set_scrollbar_mode(ui->jibing_s_label_2, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->jibing_s_label_2, "干瘦病");
	lv_label_set_long_mode(ui->jibing_s_label_2, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_jibing_s_label_2_main_main_default
	static lv_style_t style_jibing_s_label_2_main_main_default;
	if (style_jibing_s_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_jibing_s_label_2_main_main_default);
	else
		lv_style_init(&style_jibing_s_label_2_main_main_default);
	lv_style_set_radius(&style_jibing_s_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_jibing_s_label_2_main_main_default, lv_color_make(0x0a, 0x06, 0x06));
	lv_style_set_bg_grad_color(&style_jibing_s_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_jibing_s_label_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_jibing_s_label_2_main_main_default, 25);
	lv_style_set_text_color(&style_jibing_s_label_2_main_main_default, lv_color_make(0x70, 0x05, 0x05));
	lv_style_set_text_font(&style_jibing_s_label_2_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_jibing_s_label_2_main_main_default, 2);
	lv_style_set_text_line_space(&style_jibing_s_label_2_main_main_default, 0);
	lv_style_set_text_align(&style_jibing_s_label_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_jibing_s_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_jibing_s_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_jibing_s_label_2_main_main_default, 8);
	lv_style_set_pad_bottom(&style_jibing_s_label_2_main_main_default, 0);
	lv_obj_add_style(ui->jibing_s_label_2, &style_jibing_s_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes jibing_s_imgbtn_2
	ui->jibing_s_imgbtn_2 = lv_imgbtn_create(ui->jibing_s_tileview_1_tile_2);
	lv_obj_set_pos(ui->jibing_s_imgbtn_2, 2, 5);
	lv_obj_set_size(ui->jibing_s_imgbtn_2, 32, 32);
	lv_obj_set_scrollbar_mode(ui->jibing_s_imgbtn_2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_jibing_s_imgbtn_2_main_main_default
	static lv_style_t style_jibing_s_imgbtn_2_main_main_default;
	if (style_jibing_s_imgbtn_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_jibing_s_imgbtn_2_main_main_default);
	else
		lv_style_init(&style_jibing_s_imgbtn_2_main_main_default);
	lv_style_set_text_color(&style_jibing_s_imgbtn_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_jibing_s_imgbtn_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_jibing_s_imgbtn_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_jibing_s_imgbtn_2_main_main_default, 0);
	lv_style_set_img_opa(&style_jibing_s_imgbtn_2_main_main_default, 255);
	lv_obj_add_style(ui->jibing_s_imgbtn_2, &style_jibing_s_imgbtn_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_jibing_s_imgbtn_2_main_main_pressed
	static lv_style_t style_jibing_s_imgbtn_2_main_main_pressed;
	if (style_jibing_s_imgbtn_2_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_jibing_s_imgbtn_2_main_main_pressed);
	else
		lv_style_init(&style_jibing_s_imgbtn_2_main_main_pressed);
	lv_style_set_text_color(&style_jibing_s_imgbtn_2_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_jibing_s_imgbtn_2_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_jibing_s_imgbtn_2_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_jibing_s_imgbtn_2_main_main_pressed, 0);
	lv_style_set_img_opa(&style_jibing_s_imgbtn_2_main_main_pressed, 255);
	lv_obj_add_style(ui->jibing_s_imgbtn_2, &style_jibing_s_imgbtn_2_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_jibing_s_imgbtn_2_main_main_checked
	static lv_style_t style_jibing_s_imgbtn_2_main_main_checked;
	if (style_jibing_s_imgbtn_2_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_jibing_s_imgbtn_2_main_main_checked);
	else
		lv_style_init(&style_jibing_s_imgbtn_2_main_main_checked);
	lv_style_set_text_color(&style_jibing_s_imgbtn_2_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_jibing_s_imgbtn_2_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_jibing_s_imgbtn_2_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_jibing_s_imgbtn_2_main_main_checked, 0);
	lv_style_set_img_opa(&style_jibing_s_imgbtn_2_main_main_checked, 255);
	lv_obj_add_style(ui->jibing_s_imgbtn_2, &style_jibing_s_imgbtn_2_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->jibing_s_imgbtn_2, LV_IMGBTN_STATE_RELEASED, NULL, &_fanhui2_alpha_32x32, NULL);
	lv_imgbtn_set_src(ui->jibing_s_imgbtn_2, LV_IMGBTN_STATE_PRESSED, NULL, &_fanhui2_alpha_32x32, NULL);
	lv_obj_add_flag(ui->jibing_s_imgbtn_2, LV_OBJ_FLAG_CHECKABLE);

	//Write codes jibing_s_img_2
	ui->jibing_s_img_2 = lv_img_create(ui->jibing_s_tileview_1_tile_2);
	lv_obj_set_pos(ui->jibing_s_img_2, 290, 49);
	lv_obj_set_size(ui->jibing_s_img_2, 165, 107);
	lv_obj_set_scrollbar_mode(ui->jibing_s_img_2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_jibing_s_img_2_main_main_default
	static lv_style_t style_jibing_s_img_2_main_main_default;
	if (style_jibing_s_img_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_jibing_s_img_2_main_main_default);
	else
		lv_style_init(&style_jibing_s_img_2_main_main_default);
	lv_style_set_img_recolor(&style_jibing_s_img_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_jibing_s_img_2_main_main_default, 0);
	lv_style_set_img_opa(&style_jibing_s_img_2_main_main_default, 255);
	lv_obj_add_style(ui->jibing_s_img_2, &style_jibing_s_img_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->jibing_s_img_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->jibing_s_img_2,&_sheep2_165x107);
	lv_img_set_pivot(ui->jibing_s_img_2, 50,50);
	lv_img_set_angle(ui->jibing_s_img_2, 0);

	//add new tile jibing_s_tileview_1_tile_1
	ui->jibing_s_tileview_1_tile_1 = lv_tileview_add_tile(ui->jibing_s_tileview_1, 0, 0, LV_DIR_RIGHT);

	//Write codes jibing_s_imgbtn_1
	ui->jibing_s_imgbtn_1 = lv_imgbtn_create(ui->jibing_s_tileview_1_tile_1);
	lv_obj_set_pos(ui->jibing_s_imgbtn_1, 0, 0);
	lv_obj_set_size(ui->jibing_s_imgbtn_1, 32, 32);
	lv_obj_set_scrollbar_mode(ui->jibing_s_imgbtn_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_jibing_s_imgbtn_1_main_main_default
	static lv_style_t style_jibing_s_imgbtn_1_main_main_default;
	if (style_jibing_s_imgbtn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_jibing_s_imgbtn_1_main_main_default);
	else
		lv_style_init(&style_jibing_s_imgbtn_1_main_main_default);
	lv_style_set_text_color(&style_jibing_s_imgbtn_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_jibing_s_imgbtn_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_jibing_s_imgbtn_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_jibing_s_imgbtn_1_main_main_default, 0);
	lv_style_set_img_opa(&style_jibing_s_imgbtn_1_main_main_default, 255);
	lv_obj_add_style(ui->jibing_s_imgbtn_1, &style_jibing_s_imgbtn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_jibing_s_imgbtn_1_main_main_pressed
	static lv_style_t style_jibing_s_imgbtn_1_main_main_pressed;
	if (style_jibing_s_imgbtn_1_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_jibing_s_imgbtn_1_main_main_pressed);
	else
		lv_style_init(&style_jibing_s_imgbtn_1_main_main_pressed);
	lv_style_set_text_color(&style_jibing_s_imgbtn_1_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_jibing_s_imgbtn_1_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_jibing_s_imgbtn_1_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_jibing_s_imgbtn_1_main_main_pressed, 0);
	lv_style_set_img_opa(&style_jibing_s_imgbtn_1_main_main_pressed, 255);
	lv_obj_add_style(ui->jibing_s_imgbtn_1, &style_jibing_s_imgbtn_1_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_jibing_s_imgbtn_1_main_main_checked
	static lv_style_t style_jibing_s_imgbtn_1_main_main_checked;
	if (style_jibing_s_imgbtn_1_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_jibing_s_imgbtn_1_main_main_checked);
	else
		lv_style_init(&style_jibing_s_imgbtn_1_main_main_checked);
	lv_style_set_text_color(&style_jibing_s_imgbtn_1_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_jibing_s_imgbtn_1_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_jibing_s_imgbtn_1_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_jibing_s_imgbtn_1_main_main_checked, 0);
	lv_style_set_img_opa(&style_jibing_s_imgbtn_1_main_main_checked, 255);
	lv_obj_add_style(ui->jibing_s_imgbtn_1, &style_jibing_s_imgbtn_1_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->jibing_s_imgbtn_1, LV_IMGBTN_STATE_RELEASED, NULL, &_fanhui2_alpha_32x32, NULL);
	lv_imgbtn_set_src(ui->jibing_s_imgbtn_1, LV_IMGBTN_STATE_PRESSED, NULL, &_fanhui2_alpha_32x32, NULL);
	lv_obj_add_flag(ui->jibing_s_imgbtn_1, LV_OBJ_FLAG_CHECKABLE);

	//Write codes jibing_s_spangroup_2
	ui->jibing_s_spangroup_2 = lv_spangroup_create(ui->jibing_s_tileview_1_tile_1);
	lv_obj_set_pos(ui->jibing_s_spangroup_2, 9, 47);
	lv_obj_set_size(ui->jibing_s_spangroup_2, 263, 214);
	lv_obj_set_scrollbar_mode(ui->jibing_s_spangroup_2, LV_SCROLLBAR_MODE_OFF);
	lv_spangroup_set_align(ui->jibing_s_spangroup_2, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->jibing_s_spangroup_2, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->jibing_s_spangroup_2, LV_SPAN_MODE_BREAK);

	//Write style state: LV_STATE_DEFAULT for style_jibing_s_spangroup_2_main_main_default
	static lv_style_t style_jibing_s_spangroup_2_main_main_default;
	if (style_jibing_s_spangroup_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_jibing_s_spangroup_2_main_main_default);
	else
		lv_style_init(&style_jibing_s_spangroup_2_main_main_default);
	lv_style_set_radius(&style_jibing_s_spangroup_2_main_main_default, 0);
	lv_style_set_bg_color(&style_jibing_s_spangroup_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_jibing_s_spangroup_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_jibing_s_spangroup_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_jibing_s_spangroup_2_main_main_default, 0);
	lv_style_set_border_color(&style_jibing_s_spangroup_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_jibing_s_spangroup_2_main_main_default, 0);
	lv_style_set_border_opa(&style_jibing_s_spangroup_2_main_main_default, 255);
	lv_style_set_pad_left(&style_jibing_s_spangroup_2_main_main_default, 0);
	lv_style_set_pad_right(&style_jibing_s_spangroup_2_main_main_default, 0);
	lv_style_set_pad_top(&style_jibing_s_spangroup_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_jibing_s_spangroup_2_main_main_default, 0);
	lv_obj_add_style(ui->jibing_s_spangroup_2, &style_jibing_s_spangroup_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//create spans
	lv_span_t *jibing_s_spangroup_2_span;

	//create a new span
	jibing_s_spangroup_2_span = lv_spangroup_new_span(ui->jibing_s_spangroup_2);
	lv_span_set_text(jibing_s_spangroup_2_span, "   羊腹泻通常在羔羊群体中较为常见，羊腹泻主要与羊的小肠疾病相关，羔羊刚出生时各项机体功能发育不成熟，特别是小羔羊的肠系黏膜发育不全，胃酸浓度较低，酸酶的活性小，如果饲养不到位或者护理不细心很容易引发腹泻。\n   防病方法：如果是单纯性腹泻，建议可禁食一天，只给予少量饲料，根据羊的体质恢复情况逐渐添加田间饲料，直到羊慢慢恢复正常。但如果是细菌病毒引起的中毒性腹泻建议选择解毒药剂。针对常见腹泻也可以选择蒲公英、马齿笕及茜草捣烂服用，每天2次，药物成本低、收效明显，而且没有任何毒副作用。");
	lv_style_set_text_color(&jibing_s_spangroup_2_span->style, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_decor(&jibing_s_spangroup_2_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&jibing_s_spangroup_2_span->style, &lv_font_simsun_14);
	lv_spangroup_refr_mode(ui->jibing_s_spangroup_2);

	//Write codes jibing_s_label_1
	ui->jibing_s_label_1 = lv_label_create(ui->jibing_s_tileview_1_tile_1);
	lv_obj_set_pos(ui->jibing_s_label_1, 41, 4);
	lv_obj_set_size(ui->jibing_s_label_1, 68, 28);
	lv_obj_set_scrollbar_mode(ui->jibing_s_label_1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->jibing_s_label_1, "羊腹泻");
	lv_label_set_long_mode(ui->jibing_s_label_1, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_jibing_s_label_1_main_main_default
	static lv_style_t style_jibing_s_label_1_main_main_default;
	if (style_jibing_s_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_jibing_s_label_1_main_main_default);
	else
		lv_style_init(&style_jibing_s_label_1_main_main_default);
	lv_style_set_radius(&style_jibing_s_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_jibing_s_label_1_main_main_default, lv_color_make(0x0b, 0x04, 0x04));
	lv_style_set_bg_grad_color(&style_jibing_s_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_jibing_s_label_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_jibing_s_label_1_main_main_default, 21);
	lv_style_set_text_color(&style_jibing_s_label_1_main_main_default, lv_color_make(0x70, 0x05, 0x05));
	lv_style_set_text_font(&style_jibing_s_label_1_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_jibing_s_label_1_main_main_default, 2);
	lv_style_set_text_line_space(&style_jibing_s_label_1_main_main_default, 0);
	lv_style_set_text_align(&style_jibing_s_label_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_jibing_s_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_jibing_s_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_jibing_s_label_1_main_main_default, 8);
	lv_style_set_pad_bottom(&style_jibing_s_label_1_main_main_default, 0);
	lv_obj_add_style(ui->jibing_s_label_1, &style_jibing_s_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes jibing_s_img_1
	ui->jibing_s_img_1 = lv_img_create(ui->jibing_s_tileview_1_tile_1);
	lv_obj_set_pos(ui->jibing_s_img_1, 290, 46);
	lv_obj_set_size(ui->jibing_s_img_1, 161, 96);
	lv_obj_set_scrollbar_mode(ui->jibing_s_img_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_jibing_s_img_1_main_main_default
	static lv_style_t style_jibing_s_img_1_main_main_default;
	if (style_jibing_s_img_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_jibing_s_img_1_main_main_default);
	else
		lv_style_init(&style_jibing_s_img_1_main_main_default);
	lv_style_set_img_recolor(&style_jibing_s_img_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_jibing_s_img_1_main_main_default, 0);
	lv_style_set_img_opa(&style_jibing_s_img_1_main_main_default, 255);
	lv_obj_add_style(ui->jibing_s_img_1, &style_jibing_s_img_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->jibing_s_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->jibing_s_img_1,&_sheep3_161x96);
	lv_img_set_pivot(ui->jibing_s_img_1, 50,50);
	lv_img_set_angle(ui->jibing_s_img_1, 0);

	//Init events for screen
	events_init_jibing_s(ui);
}