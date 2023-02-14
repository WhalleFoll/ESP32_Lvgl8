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


extern u_int8_t sheep_s1;
extern u_int8_t sheep_s2;
extern u_int8_t sheep_s3;
extern u_int8_t sheep_s4;
extern u_int8_t sheep_s5;
extern u_int8_t sheep_s6;
extern u_int8_t sheep_s7;
extern u_int8_t sheep_s8;
extern u_int8_t sheep_s9;

void setup_scr_er_trace2(lv_ui *ui){

	//Write codes er_trace2
	ui->er_trace2 = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->er_trace2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_er_trace2_main_main_default
	static lv_style_t style_er_trace2_main_main_default;
	if (style_er_trace2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_er_trace2_main_main_default);
	else
		lv_style_init(&style_er_trace2_main_main_default);
	lv_style_set_bg_color(&style_er_trace2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_er_trace2_main_main_default, 0);
	lv_obj_add_style(ui->er_trace2, &style_er_trace2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes er_trace2_btn_1
	ui->er_trace2_btn_1 = lv_btn_create(ui->er_trace2);
	lv_obj_set_pos(ui->er_trace2_btn_1, 438, 148);
	lv_obj_set_size(ui->er_trace2_btn_1, 36, 36);
	lv_obj_set_scrollbar_mode(ui->er_trace2_btn_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_er_trace2_btn_1_main_main_default
	static lv_style_t style_er_trace2_btn_1_main_main_default;
	if (style_er_trace2_btn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_er_trace2_btn_1_main_main_default);
	else
		lv_style_init(&style_er_trace2_btn_1_main_main_default);
	lv_style_set_radius(&style_er_trace2_btn_1_main_main_default, 5);
	lv_style_set_bg_color(&style_er_trace2_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_er_trace2_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_er_trace2_btn_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_er_trace2_btn_1_main_main_default, 255);
	lv_style_set_border_color(&style_er_trace2_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_er_trace2_btn_1_main_main_default, 0);
	lv_style_set_border_opa(&style_er_trace2_btn_1_main_main_default, 255);
	lv_style_set_text_color(&style_er_trace2_btn_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_er_trace2_btn_1_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_align(&style_er_trace2_btn_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->er_trace2_btn_1, &style_er_trace2_btn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->er_trace2_btn_1_label = lv_label_create(ui->er_trace2_btn_1);
	lv_label_set_text(ui->er_trace2_btn_1_label, "<<");
	lv_obj_set_style_pad_all(ui->er_trace2_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->er_trace2_btn_1_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes er_trace2_table_1
	ui->er_trace2_table_1 = lv_table_create(ui->er_trace2);
	lv_obj_set_pos(ui->er_trace2_table_1, 16, 17);
	lv_obj_set_scrollbar_mode(ui->er_trace2_table_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_er_trace2_table_1_main_main_default
	static lv_style_t style_er_trace2_table_1_main_main_default;
	if (style_er_trace2_table_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_er_trace2_table_1_main_main_default);
	else
		lv_style_init(&style_er_trace2_table_1_main_main_default);
	lv_style_set_radius(&style_er_trace2_table_1_main_main_default, 0);
	lv_style_set_bg_color(&style_er_trace2_table_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_er_trace2_table_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_er_trace2_table_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_er_trace2_table_1_main_main_default, 255);
	lv_style_set_border_color(&style_er_trace2_table_1_main_main_default, lv_color_make(0xd5, 0xde, 0xe6));
	lv_style_set_border_width(&style_er_trace2_table_1_main_main_default, 2);
	lv_style_set_border_opa(&style_er_trace2_table_1_main_main_default, 255);
	lv_style_set_pad_left(&style_er_trace2_table_1_main_main_default, 0);
	lv_style_set_pad_right(&style_er_trace2_table_1_main_main_default, 0);
	lv_style_set_pad_top(&style_er_trace2_table_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_er_trace2_table_1_main_main_default, 0);
	lv_obj_add_style(ui->er_trace2_table_1, &style_er_trace2_table_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_er_trace2_table_1_main_items_default
	static lv_style_t style_er_trace2_table_1_main_items_default;
	if (style_er_trace2_table_1_main_items_default.prop_cnt > 1)
		lv_style_reset(&style_er_trace2_table_1_main_items_default);
	else
		lv_style_init(&style_er_trace2_table_1_main_items_default);
	lv_style_set_bg_color(&style_er_trace2_table_1_main_items_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_er_trace2_table_1_main_items_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_er_trace2_table_1_main_items_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_er_trace2_table_1_main_items_default, 0);
	lv_style_set_border_color(&style_er_trace2_table_1_main_items_default, lv_color_make(0xd5, 0xde, 0xe6));
	lv_style_set_border_width(&style_er_trace2_table_1_main_items_default, 3);
	lv_style_set_border_opa(&style_er_trace2_table_1_main_items_default, 255);
	lv_style_set_text_color(&style_er_trace2_table_1_main_items_default, lv_color_make(0x39, 0x3c, 0x41));
	lv_style_set_text_font(&style_er_trace2_table_1_main_items_default, &lv_font_simsun_12);
	lv_style_set_text_decor(&style_er_trace2_table_1_main_items_default, LV_TEXT_DECOR_NONE);
	lv_obj_add_style(ui->er_trace2_table_1, &style_er_trace2_table_1_main_items_default, LV_PART_ITEMS|LV_STATE_DEFAULT);
	lv_table_set_col_cnt(ui->er_trace2_table_1,2);
	lv_table_set_row_cnt(ui->er_trace2_table_1,9);
	lv_table_set_cell_value(ui->er_trace2_table_1,0,0,"羊四联苗");
	lv_table_set_cell_value(ui->er_trace2_table_1,1,0,"羊五联苗");
	lv_table_set_cell_value(ui->er_trace2_table_1,2,0,"破伤风类毒素");
	lv_table_set_cell_value(ui->er_trace2_table_1,3,0,"第2号炭疽苗");
	lv_table_set_cell_value(ui->er_trace2_table_1,4,0,"羔羊大肠杆菌疫苗");
	lv_table_set_cell_value(ui->er_trace2_table_1,5,0,"口疮弱毒细胞");
	lv_table_set_cell_value(ui->er_trace2_table_1,6,0,"羊链球菌疫苗");
	lv_table_set_cell_value(ui->er_trace2_table_1,7,0,"羊黑疫菌苗");
	lv_table_set_cell_value(ui->er_trace2_table_1,8,0,"山羊痘灭火苗");

	
	lv_table_set_cell_value_fmt(ui->er_trace2_table_1,0,1,"%d",sheep_s1);
	lv_table_set_cell_value_fmt(ui->er_trace2_table_1,1,1,"%d",sheep_s2);
	lv_table_set_cell_value_fmt(ui->er_trace2_table_1,2,1,"%d",sheep_s3);
	//lv_table_set_cell_value(ui->er_trace2_table_1,0,1,"已接种");
	//lv_table_set_cell_value(ui->er_trace2_table_1,1,1,"已接种");
	//lv_table_set_cell_value(ui->er_trace2_table_1,2,1,"未接种");

	lv_table_set_cell_value_fmt(ui->er_trace2_table_1,3,1,"%d",sheep_s4);
	lv_table_set_cell_value_fmt(ui->er_trace2_table_1,4,1,"%d",sheep_s5);
	lv_table_set_cell_value_fmt(ui->er_trace2_table_1,5,1,"%d",sheep_s6);
	//lv_table_set_cell_value(ui->er_trace2_table_1,3,1,"已接种");
	//lv_table_set_cell_value(ui->er_trace2_table_1,4,1,"已接种");
	//lv_table_set_cell_value(ui->er_trace2_table_1,5,1,"未接种");

	lv_table_set_cell_value_fmt(ui->er_trace2_table_1,6,1,"%d",sheep_s7);
	lv_table_set_cell_value_fmt(ui->er_trace2_table_1,7,1,"%d",sheep_s8);
	lv_table_set_cell_value_fmt(ui->er_trace2_table_1,8,1,"%d",sheep_s9);
	//lv_table_set_cell_value(ui->er_trace2_table_1,6,1,"已接种");
	//lv_table_set_cell_value(ui->er_trace2_table_1,7,1,"未接种");
	//lv_table_set_cell_value(ui->er_trace2_table_1,8,1,"已接种");
	lv_obj_set_style_pad_left(ui->er_trace2_table_1, 10, LV_PART_ITEMS|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->er_trace2_table_1, 10, LV_PART_ITEMS|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->er_trace2_table_1, 10, LV_PART_ITEMS|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->er_trace2_table_1, 10, LV_PART_ITEMS|LV_STATE_DEFAULT);

	//Init events for screen
	events_init_er_trace2(ui);
}