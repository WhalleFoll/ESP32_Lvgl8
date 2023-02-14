/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"

/* u_int32_t gui_id;
char *gui_species;
char *gui_sex;
char *gui_weight;
char *gui_sheep_age;
char *gui_use_value;
char *gui_place_of_production;
char *gui_vaccine;
char *gui_health;

char *gui_time_year="2023";
char *gui_time_month="1";
char *gui_time_day="15";
char *gui_time_weekend="7";    
char *gui_s1="0",*gui_s2="0",*gui_s3="0",*gui_s4="0",*gui_s5="0",*gui_s6="0",*gui_s7="0",*gui_s8="0",*gui_s9="0"; */



void init_scr_del_flag(lv_ui *ui){
	ui->mainscan_del = true;
	ui->help_sc_del = true;
	ui->weather_sr_del = true;
	ui->set_sys_del = true;
	ui->wifi_sr_del = true;
	ui->jibing_s_del = true;
	ui->er_trace_del = true;
	ui->Xin_xi_luru_del = true;
	ui->yangzhi_sc_del = true;
	ui->er_trace2_del = true;
	ui->xiao_ka_del = true;
	ui->yimiao_del = true;
}

void setup_ui(lv_ui *ui){
	init_scr_del_flag(ui);
	setup_scr_mainscan(ui);
	lv_scr_load(ui->mainscan);
}
