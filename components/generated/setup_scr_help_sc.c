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


void setup_scr_help_sc(lv_ui *ui){

	//Write codes help_sc
	ui->help_sc = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->help_sc, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_help_sc_main_main_default
	static lv_style_t style_help_sc_main_main_default;
	if (style_help_sc_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_help_sc_main_main_default);
	else
		lv_style_init(&style_help_sc_main_main_default);
	lv_style_set_bg_color(&style_help_sc_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_help_sc_main_main_default, 0);
	lv_obj_add_style(ui->help_sc, &style_help_sc_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes help_sc_imgbtn_1
	ui->help_sc_imgbtn_1 = lv_imgbtn_create(ui->help_sc);
	lv_obj_set_pos(ui->help_sc_imgbtn_1, 1, 1);
	lv_obj_set_size(ui->help_sc_imgbtn_1, 32, 32);
	lv_obj_set_scrollbar_mode(ui->help_sc_imgbtn_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_help_sc_imgbtn_1_main_main_default
	static lv_style_t style_help_sc_imgbtn_1_main_main_default;
	if (style_help_sc_imgbtn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_help_sc_imgbtn_1_main_main_default);
	else
		lv_style_init(&style_help_sc_imgbtn_1_main_main_default);
	lv_style_set_text_color(&style_help_sc_imgbtn_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_help_sc_imgbtn_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_help_sc_imgbtn_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_help_sc_imgbtn_1_main_main_default, 0);
	lv_style_set_img_opa(&style_help_sc_imgbtn_1_main_main_default, 255);
	lv_obj_add_style(ui->help_sc_imgbtn_1, &style_help_sc_imgbtn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_help_sc_imgbtn_1_main_main_pressed
	static lv_style_t style_help_sc_imgbtn_1_main_main_pressed;
	if (style_help_sc_imgbtn_1_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_help_sc_imgbtn_1_main_main_pressed);
	else
		lv_style_init(&style_help_sc_imgbtn_1_main_main_pressed);
	lv_style_set_text_color(&style_help_sc_imgbtn_1_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_help_sc_imgbtn_1_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_help_sc_imgbtn_1_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_help_sc_imgbtn_1_main_main_pressed, 0);
	lv_style_set_img_opa(&style_help_sc_imgbtn_1_main_main_pressed, 255);
	lv_obj_add_style(ui->help_sc_imgbtn_1, &style_help_sc_imgbtn_1_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_help_sc_imgbtn_1_main_main_checked
	static lv_style_t style_help_sc_imgbtn_1_main_main_checked;
	if (style_help_sc_imgbtn_1_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_help_sc_imgbtn_1_main_main_checked);
	else
		lv_style_init(&style_help_sc_imgbtn_1_main_main_checked);
	lv_style_set_text_color(&style_help_sc_imgbtn_1_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_help_sc_imgbtn_1_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_help_sc_imgbtn_1_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_help_sc_imgbtn_1_main_main_checked, 0);
	lv_style_set_img_opa(&style_help_sc_imgbtn_1_main_main_checked, 255);
	lv_obj_add_style(ui->help_sc_imgbtn_1, &style_help_sc_imgbtn_1_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->help_sc_imgbtn_1, LV_IMGBTN_STATE_RELEASED, NULL, &_fanhui2_alpha_32x32, NULL);
	lv_imgbtn_set_src(ui->help_sc_imgbtn_1, LV_IMGBTN_STATE_PRESSED, NULL, &_fanhui2_alpha_32x32, NULL);
	lv_obj_add_flag(ui->help_sc_imgbtn_1, LV_OBJ_FLAG_CHECKABLE);

	//Write codes help_sc_spangroup_1
	ui->help_sc_spangroup_1 = lv_spangroup_create(ui->help_sc);
	lv_obj_set_pos(ui->help_sc_spangroup_1, 27, 47);
	lv_obj_set_size(ui->help_sc_spangroup_1, 426, 252);
	lv_obj_set_scrollbar_mode(ui->help_sc_spangroup_1, LV_SCROLLBAR_MODE_OFF);
	lv_spangroup_set_align(ui->help_sc_spangroup_1, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->help_sc_spangroup_1, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->help_sc_spangroup_1, LV_SPAN_MODE_BREAK);

	//Write style state: LV_STATE_DEFAULT for style_help_sc_spangroup_1_main_main_default
	static lv_style_t style_help_sc_spangroup_1_main_main_default;
	if (style_help_sc_spangroup_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_help_sc_spangroup_1_main_main_default);
	else
		lv_style_init(&style_help_sc_spangroup_1_main_main_default);
	lv_style_set_radius(&style_help_sc_spangroup_1_main_main_default, 0);
	lv_style_set_bg_color(&style_help_sc_spangroup_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_help_sc_spangroup_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_help_sc_spangroup_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_help_sc_spangroup_1_main_main_default, 0);
	lv_style_set_border_color(&style_help_sc_spangroup_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_help_sc_spangroup_1_main_main_default, 0);
	lv_style_set_border_opa(&style_help_sc_spangroup_1_main_main_default, 255);
	lv_style_set_pad_left(&style_help_sc_spangroup_1_main_main_default, 0);
	lv_style_set_pad_right(&style_help_sc_spangroup_1_main_main_default, 0);
	lv_style_set_pad_top(&style_help_sc_spangroup_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_help_sc_spangroup_1_main_main_default, 0);
	lv_obj_add_style(ui->help_sc_spangroup_1, &style_help_sc_spangroup_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//create spans
	lv_span_t *help_sc_spangroup_1_span;

	//create a new span
	help_sc_spangroup_1_span = lv_spangroup_new_span(ui->help_sc_spangroup_1);
	lv_span_set_text(help_sc_spangroup_1_span, "    ???????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????\n\n    ??????????????????????????????????????????????????????????????????????????????????????????WINCE??????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????;????????????????????????????????????????????????????????????????????????????????????;??????????????????????????????????????????????????????????????????????????????????????????;?????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????");
	lv_style_set_text_color(&help_sc_spangroup_1_span->style, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_decor(&help_sc_spangroup_1_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&help_sc_spangroup_1_span->style, &lv_font_simsun_12);
	lv_spangroup_refr_mode(ui->help_sc_spangroup_1);

	//Init events for screen
	events_init_help_sc(ui);
}