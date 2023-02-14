/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"
#include "guider_fonts.h"

typedef struct
{
	lv_obj_t *mainscan;
	bool mainscan_del;
	lv_obj_t *mainscan_btn_1;
	lv_obj_t *mainscan_btn_1_label;
	lv_obj_t *mainscan_btn_2;
	lv_obj_t *mainscan_btn_2_label;
	lv_obj_t *mainscan_btn_3;
	lv_obj_t *mainscan_btn_3_label;
	lv_obj_t *mainscan_btn_4;
	lv_obj_t *mainscan_btn_4_label;
	lv_obj_t *mainscan_label_1;
	lv_obj_t *mainscan_imgbtn_1;
	lv_obj_t *mainscan_imgbtn_1_label;
	lv_obj_t *mainscan_imgbtn_2;
	lv_obj_t *mainscan_imgbtn_2_label;
	lv_obj_t *mainscan_animimg_1;
	lv_obj_t *mainscan_label_2;
	lv_obj_t *mainscan_label_3;
	lv_obj_t *mainscan_label_4;
	lv_obj_t *mainscan_label_5;
	lv_obj_t *mainscan_label_6;
	lv_obj_t *mainscan_label_7;
	lv_obj_t *mainscan_imgbtn_3;
	lv_obj_t *mainscan_imgbtn_3_label;
	lv_obj_t *mainscan_imgbtn_4;
	lv_obj_t *mainscan_imgbtn_4_label;
	lv_obj_t *mainscan_label_8;
	lv_obj_t *mainscan_label_9;
	lv_obj_t *help_sc;
	bool help_sc_del;
	lv_obj_t *help_sc_imgbtn_1;
	lv_obj_t *help_sc_imgbtn_1_label;
	lv_obj_t *help_sc_spangroup_1;

	//lv_obj_t *weather_sr;
	//bool weather_sr_del;
	//lv_obj_t *weather_sr_imgbtn_1;
	//lv_obj_t *weather_sr_imgbtn_1_label;
	//lv_obj_t *weather_sr_label_1;
	//lv_obj_t *weather_sr_label_2;

	lv_obj_t *weather_sr;
	bool weather_sr_del;
	lv_obj_t *weather_sr_imgbtn_1;
	lv_obj_t *weather_sr_imgbtn_1_label;
	lv_obj_t *weather_sr_bar_1;
	lv_obj_t *weather_sr_label_3;
	lv_obj_t *weather_sr_label_4;
	lv_obj_t *weather_sr_bar_2;
	lv_obj_t *weather_sr_label_5;
	lv_obj_t *weather_sr_label_6;
	lv_obj_t *weather_sr_label_7;
	lv_obj_t *weather_sr_label_8;
	lv_obj_t *weather_sr_bar_3;
	lv_obj_t *weather_sr_label_9;
	lv_obj_t *weather_sr_label_10;
	lv_obj_t *weather_sr_label_11;
	lv_obj_t *weather_sr_label_12;

	lv_obj_t *set_sys;
	bool set_sys_del;
	lv_obj_t *set_sys_imgbtn_1;
	lv_obj_t *set_sys_imgbtn_1_label;
	lv_obj_t *wifi_sr;
	bool wifi_sr_del;
	lv_obj_t *wifi_sr_imgbtn_1;
	lv_obj_t *wifi_sr_imgbtn_1_label;
	lv_obj_t *wifi_sr_label_1;
	lv_obj_t *wifi_sr_label_2;
	lv_obj_t *wifi_sr_label_3;
	lv_obj_t *wifi_sr_label_4;
	lv_obj_t *wifi_sr_label_5;
	lv_obj_t *wifi_sr_label_6;
	lv_obj_t *wifi_sr_label_7;
	lv_obj_t *wifi_sr_label_8;
	lv_obj_t *wifi_sr_label_9;
	lv_obj_t *wifi_sr_label_10;
	lv_obj_t *jibing_s;
	bool jibing_s_del;
	lv_obj_t *jibing_s_tileview_1;
	lv_obj_t *jibing_s_tileview_1_tile_2;
	lv_obj_t *jibing_s_spangroup_1;
	lv_obj_t *jibing_s_label_2;
	lv_obj_t *jibing_s_imgbtn_2;
	lv_obj_t *jibing_s_imgbtn_2_label;
	lv_obj_t *jibing_s_img_2;
	lv_obj_t *jibing_s_tileview_1_tile_1;
	lv_obj_t *jibing_s_imgbtn_1;
	lv_obj_t *jibing_s_imgbtn_1_label;
	lv_obj_t *jibing_s_spangroup_2;
	lv_obj_t *jibing_s_label_1;
	lv_obj_t *jibing_s_img_1;
	lv_obj_t *er_trace;
	bool er_trace_del;
	lv_obj_t *er_trace_table_1;
	lv_obj_t *er_trace_imgbtn_1;
	lv_obj_t *er_trace_imgbtn_1_label;
	lv_obj_t *er_trace_ta_1;
	lv_obj_t *er_trace_btn_1;
	lv_obj_t *er_trace_btn_1_label;
	lv_obj_t *er_trace_btn_2;
	lv_obj_t *er_trace_btn_2_label;
	lv_obj_t *er_trace_label_1;
	lv_obj_t *er_trace_btn_3;
	lv_obj_t *er_trace_btn_3_label;
	lv_obj_t *Xin_xi_luru;
	bool Xin_xi_luru_del;
	lv_obj_t *Xin_xi_luru_tileview_1;
	lv_obj_t *Xin_xi_luru_tileview_1_tile_2;
	lv_obj_t *Xin_xi_luru_label_9;
	lv_obj_t *Xin_xi_luru_cb_1;
	lv_obj_t *Xin_xi_luru_cb_2;
	lv_obj_t *Xin_xi_luru_cb_3;
	lv_obj_t *Xin_xi_luru_cb_4;
	lv_obj_t *Xin_xi_luru_cb_5;
	lv_obj_t *Xin_xi_luru_cb_6;
	lv_obj_t *Xin_xi_luru_cb_7;
	lv_obj_t *Xin_xi_luru_cb_8;
	lv_obj_t *Xin_xi_luru_cb_9;
	lv_obj_t *Xin_xi_luru_tileview_1_tile_1;
	lv_obj_t *Xin_xi_luru_label_1;
	lv_obj_t *Xin_xi_luru_label_2;
	lv_obj_t *Xin_xi_luru_label_3;
	lv_obj_t *Xin_xi_luru_label_5;
	lv_obj_t *Xin_xi_luru_ta_1;
	lv_obj_t *Xin_xi_luru_ta_2;
	lv_obj_t *Xin_xi_luru_label_8;
	lv_obj_t *Xin_xi_luru_ta_3;
	lv_obj_t *Xin_xi_luru_btn_1;
	lv_obj_t *Xin_xi_luru_btn_1_label;
	lv_obj_t *Xin_xi_luru_btn_2;
	lv_obj_t *Xin_xi_luru_btn_2_label;
	lv_obj_t *Xin_xi_luru_imgbtn_1;
	lv_obj_t *Xin_xi_luru_imgbtn_1_label;
	lv_obj_t *Xin_xi_luru_btn_3;
	lv_obj_t *Xin_xi_luru_btn_3_label;
	lv_obj_t *yangzhi_sc;
	bool yangzhi_sc_del;
	lv_obj_t *yangzhi_sc_imgbtn_1;
	lv_obj_t *yangzhi_sc_imgbtn_1_label;
	lv_obj_t *yangzhi_sc_btn_1;
	lv_obj_t *yangzhi_sc_btn_1_label;
	lv_obj_t *yangzhi_sc_btn_2;
	lv_obj_t *yangzhi_sc_btn_2_label;
	lv_obj_t *yangzhi_sc_btn_3;
	lv_obj_t *yangzhi_sc_btn_3_label;
	lv_obj_t *yangzhi_sc_btn_4;
	lv_obj_t *yangzhi_sc_btn_4_label;
	lv_obj_t *yangzhi_sc_label_1;
	lv_obj_t *er_trace2;
	bool er_trace2_del;
	lv_obj_t *er_trace2_btn_1;
	lv_obj_t *er_trace2_btn_1_label;
	lv_obj_t *er_trace2_table_1;
	lv_obj_t *xiao_ka;
	bool xiao_ka_del;
	lv_obj_t *xiao_ka_imgbtn_1;
	lv_obj_t *xiao_ka_imgbtn_1_label;
	lv_obj_t *xiao_ka_label_1;
	lv_obj_t *xiao_ka_label_2;
	lv_obj_t *xiao_ka_btn_1;
	lv_obj_t *xiao_ka_btn_1_label;
	lv_obj_t *xiao_ka_btn_3;
	lv_obj_t *xiao_ka_btn_3_label;
	lv_obj_t *xiao_ka_label_3;
	lv_obj_t *xiao_ka_label_4;
	lv_obj_t *yimiao;
	bool yimiao_del;
	lv_obj_t *yimiao_imgbtn_1;
	lv_obj_t *yimiao_imgbtn_1_label;
	lv_obj_t *yimiao_label_1;
	lv_obj_t *yimiao_cont_1;
	lv_obj_t *yimiao_cb_1;
	lv_obj_t *yimiao_cb_2;
	lv_obj_t *yimiao_cb_3;
	lv_obj_t *yimiao_cb_4;
	lv_obj_t *yimiao_cb_5;
	lv_obj_t *yimiao_cb_6;
	lv_obj_t *yimiao_cb_7;
	lv_obj_t *yimiao_cb_8;
	lv_obj_t *yimiao_cb_9;
	lv_obj_t *yimiao_label_2;
}lv_ui;

void init_scr_del_flag(lv_ui *ui);
void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;
void setup_scr_mainscan(lv_ui *ui);

#include "extra/widgets/animimg/lv_animimg.h"
LV_IMG_DECLARE(mainscan_animimg_1sheep_4_00)
LV_IMG_DECLARE(mainscan_animimg_1sheep_4_01)
LV_IMG_DECLARE(mainscan_animimg_1sheep_4_02)
LV_IMG_DECLARE(mainscan_animimg_1sheep_4_03)
LV_IMG_DECLARE(mainscan_animimg_1sheep_4_04)
void setup_scr_help_sc(lv_ui *ui);
void setup_scr_weather_sr(lv_ui *ui);
void setup_scr_set_sys(lv_ui *ui);
void setup_scr_wifi_sr(lv_ui *ui);
void setup_scr_jibing_s(lv_ui *ui);
void setup_scr_er_trace(lv_ui *ui);
void setup_scr_Xin_xi_luru(lv_ui *ui);
void setup_scr_yangzhi_sc(lv_ui *ui);
void setup_scr_er_trace2(lv_ui *ui);
void setup_scr_xiao_ka(lv_ui *ui);
void setup_scr_yimiao(lv_ui *ui);
LV_IMG_DECLARE(_wifi_alpha_32x32);
LV_IMG_DECLARE(_help_alpha_32x32);
LV_IMG_DECLARE(_fanhui2_alpha_37x34);
LV_IMG_DECLARE(_fanhui2_alpha_36x32);
LV_IMG_DECLARE(_set_u_alpha_32x32);
LV_IMG_DECLARE(_sheep3_161x96);
LV_IMG_DECLARE(_sheep2_165x107);
LV_IMG_DECLARE(_tianqi2_alpha_32x32);
LV_IMG_DECLARE(_fanhui2_alpha_45x33);
LV_IMG_DECLARE(_fanhui2_alpha_32x32);

#ifdef __cplusplus
}
#endif
#endif