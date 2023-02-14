/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"

extern u_int8_t zhuce;
extern u_int8_t xiaoka;
extern u_int8_t yi_miao;    
extern u_int8_t ear_trace;  //耳标追溯页面 刷新
extern u_int8_t main_trace;
void events_init(lv_ui *ui)
{
}

static void mainscan_btn_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
		{
			if (guider_ui.yangzhi_sc_del == true)
				setup_scr_yangzhi_sc(&guider_ui);
			lv_scr_load_anim(guider_ui.yangzhi_sc, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 100, 100, true);
		}
		guider_ui.mainscan_del = true;
	}
		break;
	default:
		break;
	}
}

static void mainscan_btn_2_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
		{
			if (guider_ui.Xin_xi_luru_del == true)
				setup_scr_Xin_xi_luru(&guider_ui);
			lv_scr_load_anim(guider_ui.Xin_xi_luru, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 100, 100, true);
		}
		guider_ui.mainscan_del = true;
	}
		break;
	default:
		break;
	}
}

static void mainscan_btn_3_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		main_trace=1;
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
		{
			if (guider_ui.er_trace_del == true)
				setup_scr_er_trace(&guider_ui);
			lv_scr_load_anim(guider_ui.er_trace, LV_SCR_LOAD_ANIM_OVER_RIGHT, 100, 100, true);
		}
		guider_ui.mainscan_del = true;
	}
		break;
	default:
		break;
	}
}

static void mainscan_btn_4_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
		{
			if (guider_ui.xiao_ka_del == true)
				setup_scr_xiao_ka(&guider_ui);
			lv_scr_load_anim(guider_ui.xiao_ka, LV_SCR_LOAD_ANIM_OVER_TOP, 0, 0, true);
		}
		guider_ui.mainscan_del = true;
	}
		break;
	default:
		break;
	}
}

static void mainscan_imgbtn_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
		{
			if (guider_ui.set_sys_del == true)
				setup_scr_set_sys(&guider_ui);
			lv_scr_load_anim(guider_ui.set_sys, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 100, 100, true);
		}
		guider_ui.mainscan_del = true;
	}
		break;
	default:
		break;
	}
}

static void mainscan_imgbtn_2_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
		{
			if (guider_ui.help_sc_del == true)
				setup_scr_help_sc(&guider_ui);
			lv_scr_load_anim(guider_ui.help_sc, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 100, 100, true);
		}
		guider_ui.mainscan_del = true;
	}
		break;
	default:
		break;
	}
}

static void mainscan_imgbtn_3_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
		{
			if (guider_ui.weather_sr_del == true)
				setup_scr_weather_sr(&guider_ui);
			lv_scr_load_anim(guider_ui.weather_sr, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 100, 100, true);
		}
		guider_ui.mainscan_del = true;
	}
		break;
	default:
		break;
	}
}

static void mainscan_imgbtn_4_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
		{
			if (guider_ui.wifi_sr_del == true)
				setup_scr_wifi_sr(&guider_ui);
			lv_scr_load_anim(guider_ui.wifi_sr, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 100, 100, true);
		}
		guider_ui.mainscan_del = true;
	}
		break;
	default:
		break;
	}
}

void events_init_mainscan(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->mainscan_btn_1, mainscan_btn_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->mainscan_btn_2, mainscan_btn_2_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->mainscan_btn_3, mainscan_btn_3_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->mainscan_btn_4, mainscan_btn_4_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->mainscan_imgbtn_1, mainscan_imgbtn_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->mainscan_imgbtn_2, mainscan_imgbtn_2_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->mainscan_imgbtn_3, mainscan_imgbtn_3_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->mainscan_imgbtn_4, mainscan_imgbtn_4_event_handler, LV_EVENT_ALL, NULL);
}

static void help_sc_imgbtn_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
		{
			if (guider_ui.mainscan_del == true)
				setup_scr_mainscan(&guider_ui);
			lv_scr_load_anim(guider_ui.mainscan, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 100, 100, true);
		}
		guider_ui.help_sc_del = true;
	}
		break;
	default:
		break;
	}
}

void events_init_help_sc(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->help_sc_imgbtn_1, help_sc_imgbtn_1_event_handler, LV_EVENT_ALL, NULL);
}

static void weather_sr_imgbtn_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
		{
			if (guider_ui.mainscan_del == true)
				setup_scr_mainscan(&guider_ui);
			lv_scr_load_anim(guider_ui.mainscan, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 100, 100, true);
		}
		guider_ui.weather_sr_del = true;
	}
		break;
	default:
		break;
	}
}

void events_init_weather_sr(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->weather_sr_imgbtn_1, weather_sr_imgbtn_1_event_handler, LV_EVENT_ALL, NULL);
}

static void set_sys_imgbtn_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
		{
			if (guider_ui.mainscan_del == true)
				setup_scr_mainscan(&guider_ui);
			lv_scr_load_anim(guider_ui.mainscan, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 100, 100, true);
		}
		guider_ui.set_sys_del = true;
	}
		break;
	default:
		break;
	}
}

void events_init_set_sys(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->set_sys_imgbtn_1, set_sys_imgbtn_1_event_handler, LV_EVENT_ALL, NULL);
}

static void wifi_sr_imgbtn_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
		{
			if (guider_ui.mainscan_del == true)
				setup_scr_mainscan(&guider_ui);
			lv_scr_load_anim(guider_ui.mainscan, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 100, 100, true);
		}
		guider_ui.wifi_sr_del = true;
	}
		break;
	default:
		break;
	}
}

void events_init_wifi_sr(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->wifi_sr_imgbtn_1, wifi_sr_imgbtn_1_event_handler, LV_EVENT_ALL, NULL);
}

static void jibing_s_imgbtn_2_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
		{
			if (guider_ui.yangzhi_sc_del == true)
				setup_scr_yangzhi_sc(&guider_ui);
			lv_scr_load_anim(guider_ui.yangzhi_sc, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 100, 100, true);
		}
		guider_ui.jibing_s_del = true;
	}
		break;
	default:
		break;
	}
}

static void jibing_s_imgbtn_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
		{
			if (guider_ui.yangzhi_sc_del == true)
				setup_scr_yangzhi_sc(&guider_ui);
			lv_scr_load_anim(guider_ui.yangzhi_sc, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 100, 100, true);
		}
		guider_ui.jibing_s_del = true;
	}
		break;
	default:
		break;
	}
}

void events_init_jibing_s(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->jibing_s_imgbtn_2, jibing_s_imgbtn_2_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->jibing_s_imgbtn_1, jibing_s_imgbtn_1_event_handler, LV_EVENT_ALL, NULL);
}

static void er_trace_imgbtn_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
		{
			if (guider_ui.mainscan_del == true)
				setup_scr_mainscan(&guider_ui);
			lv_scr_load_anim(guider_ui.mainscan, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 100, 100, true);
		}
		guider_ui.er_trace_del = true;
	}
		break;
	default:
		break;
	}
}

static void er_trace_btn_3_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
		{
			if (guider_ui.er_trace2_del == true)
				setup_scr_er_trace2(&guider_ui);
			lv_scr_load_anim(guider_ui.er_trace2, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 100, 100, true);
		}
		guider_ui.er_trace_del = true;
	}
		break;
	default:
		break;
	}
}

// 自定义函数
static void er_trace_btn_2_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		ear_trace=1;
		
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
		{
			if (guider_ui.er_trace_del == true)
				setup_scr_er_trace(&guider_ui);
			lv_scr_load_anim(guider_ui.er_trace, LV_SCR_LOAD_ANIM_OVER_TOP, 0, 0, true);
		}
		guider_ui.er_trace_del = true;
		/*
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
		{
			if (guider_ui.er_trace == true)
				setup_scr_er_trace(&guider_ui);
			lv_scr_load_anim(guider_ui.er_trace, LV_SCR_LOAD_ANIM_OVER_TOP, 0, 0, true);
		}
		guider_ui.er_trace = true;
		*/
	}
		break;
	default:
		break;
	}
}

void events_init_er_trace(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->er_trace_imgbtn_1, er_trace_imgbtn_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->er_trace_btn_3, er_trace_btn_3_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->er_trace_btn_2, er_trace_btn_2_event_handler, LV_EVENT_ALL, NULL);
}

static void Xin_xi_luru_btn_2_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		zhuce=1;
		lv_obj_set_style_bg_color(guider_ui.Xin_xi_luru_btn_2, lv_color_make(0x8b, 0xc2, 0x4c), LV_PART_MAIN);
	}
		break;
	default:
		break;
	}
}

static void Xin_xi_luru_imgbtn_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_RELEASED:
	{
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
		{
			if (guider_ui.mainscan_del == true)
				setup_scr_mainscan(&guider_ui);
			lv_scr_load_anim(guider_ui.mainscan, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 100, 100, true);
		}
		guider_ui.Xin_xi_luru_del = true;
	}
		break;
	default:
		break;
	}
}

static void Xin_xi_luru_btn_3_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
		{
			if (guider_ui.Xin_xi_luru_del == true)
				setup_scr_Xin_xi_luru(&guider_ui);
			lv_scr_load_anim(guider_ui.Xin_xi_luru, LV_SCR_LOAD_ANIM_OVER_TOP, 0, 0, true);
		}
		guider_ui.Xin_xi_luru_del = true;
	}
		break;
	default:
		break;
	}
}

void events_init_Xin_xi_luru(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->Xin_xi_luru_btn_2, Xin_xi_luru_btn_2_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->Xin_xi_luru_imgbtn_1, Xin_xi_luru_imgbtn_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->Xin_xi_luru_btn_3, Xin_xi_luru_btn_3_event_handler, LV_EVENT_ALL, NULL);
}

static void yangzhi_sc_imgbtn_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_RELEASED:
	{
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
		{
			if (guider_ui.mainscan_del == true)
				setup_scr_mainscan(&guider_ui);
			lv_scr_load_anim(guider_ui.mainscan, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 100, 100, true);
		}
		guider_ui.yangzhi_sc_del = true;
	}
		break;
	default:
		break;
	}
}

static void yangzhi_sc_btn_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
		{
			if (guider_ui.yimiao_del == true)
				setup_scr_yimiao(&guider_ui);
			lv_scr_load_anim(guider_ui.yimiao, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 100, 100, true);
		}
		guider_ui.yangzhi_sc_del = true;
	}
		break;
	default:
		break;
	}
}

static void yangzhi_sc_btn_2_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
		{
			if (guider_ui.jibing_s_del == true)
				setup_scr_jibing_s(&guider_ui);
			lv_scr_load_anim(guider_ui.jibing_s, LV_SCR_LOAD_ANIM_MOVE_LEFT, 100, 100, true);
		}
		guider_ui.yangzhi_sc_del = true;
	}
		break;
	default:
		break;
	}
}

void events_init_yangzhi_sc(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->yangzhi_sc_imgbtn_1, yangzhi_sc_imgbtn_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->yangzhi_sc_btn_1, yangzhi_sc_btn_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->yangzhi_sc_btn_2, yangzhi_sc_btn_2_event_handler, LV_EVENT_ALL, NULL);
}

static void er_trace2_btn_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
		{
			if (guider_ui.er_trace_del == true)
				setup_scr_er_trace(&guider_ui);
			lv_scr_load_anim(guider_ui.er_trace, LV_SCR_LOAD_ANIM_OVER_TOP, 0, 0, true);
		}
		guider_ui.er_trace2_del = true;
	}
		break;
	default:
		break;
	}
}

void events_init_er_trace2(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->er_trace2_btn_1, er_trace2_btn_1_event_handler, LV_EVENT_ALL, NULL);
}

static void xiao_ka_imgbtn_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
		{
			if (guider_ui.mainscan_del == true)
				setup_scr_mainscan(&guider_ui);
			lv_scr_load_anim(guider_ui.mainscan, LV_SCR_LOAD_ANIM_OVER_TOP, 0, 0, true);
		}
		guider_ui.xiao_ka_del = true;
	}
		break;
	default:
		break;
	}
}

static void xiao_ka_btn_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		xiaoka=1;
		lv_obj_set_style_bg_color(guider_ui.xiao_ka_btn_1, lv_color_make(0xa3, 0x00, 0x00), LV_PART_MAIN);
	}
		break;
	default:
		break;
	}
}

static void xiao_ka_btn_3_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
		{
			if (guider_ui.xiao_ka_del == true)
				setup_scr_xiao_ka(&guider_ui);
			lv_scr_load_anim(guider_ui.xiao_ka, LV_SCR_LOAD_ANIM_OVER_TOP, 0, 0, true);
		}
		guider_ui.xiao_ka_del = true;
	}
		break;
	default:
		break;
	}
}

void events_init_xiao_ka(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->xiao_ka_imgbtn_1, xiao_ka_imgbtn_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->xiao_ka_btn_1, xiao_ka_btn_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->xiao_ka_btn_3, xiao_ka_btn_3_event_handler, LV_EVENT_ALL, NULL);
}

static void yimiao_imgbtn_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_RELEASED:
	{
		yi_miao=1;
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
		{
			if (guider_ui.yangzhi_sc_del == true)
				setup_scr_yangzhi_sc(&guider_ui);
			lv_scr_load_anim(guider_ui.yangzhi_sc, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 100, 100, true);
		}
		guider_ui.yimiao_del = true;
	}
		break;
	default:
		break;
	}
}

void events_init_yimiao(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->yimiao_imgbtn_1, yimiao_imgbtn_1_event_handler, LV_EVENT_ALL, NULL);
}
