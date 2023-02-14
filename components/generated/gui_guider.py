# Copyright 2022 NXP
# SPDX-License-Identifier: MIT
# The auto-generated can only be used on NXP devices

import SDL
import utime as time
import usys as sys
import lvgl as lv
import lodepng as png
import ustruct

lv.init()
SDL.init(w=480,h=320)

# Register SDL display driver.
disp_buf1 = lv.disp_draw_buf_t()
buf1_1 = bytearray(480*10)
disp_buf1.init(buf1_1, None, len(buf1_1)//4)
disp_drv = lv.disp_drv_t()
disp_drv.init()
disp_drv.draw_buf = disp_buf1
disp_drv.flush_cb = SDL.monitor_flush
disp_drv.hor_res = 480
disp_drv.ver_res = 320
disp_drv.register()

# Regsiter SDL mouse driver
indev_drv = lv.indev_drv_t()
indev_drv.init() 
indev_drv.type = lv.INDEV_TYPE.POINTER
indev_drv.read_cb = SDL.mouse_read
indev_drv.register()

# Below: Taken from https://github.com/lvgl/lv_binding_micropython/blob/master/driver/js/imagetools.py#L22-L94

COLOR_SIZE = lv.color_t.__SIZE__
COLOR_IS_SWAPPED = hasattr(lv.color_t().ch,'green_h')

class lodepng_error(RuntimeError):
    def __init__(self, err):
        if type(err) is int:
            super().__init__(png.error_text(err))
        else:
            super().__init__(err)

# Parse PNG file header
# Taken from https://github.com/shibukawa/imagesize_py/blob/ffef30c1a4715c5acf90e8945ceb77f4a2ed2d45/imagesize.py#L63-L85

def get_png_info(decoder, src, header):
    # Only handle variable image types

    if lv.img.src_get_type(src) != lv.img.SRC.VARIABLE:
        return lv.RES.INV

    data = lv.img_dsc_t.__cast__(src).data
    if data == None:
        return lv.RES.INV

    png_header = bytes(data.__dereference__(24))

    if png_header.startswith(b'\211PNG\r\n\032\n'):
        if png_header[12:16] == b'IHDR':
            start = 16
        # Maybe this is for an older PNG version.
        else:
            start = 8
        try:
            width, height = ustruct.unpack(">LL", png_header[start:start+8])
        except ustruct.error:
            return lv.RES.INV
    else:
        return lv.RES.INV

    header.always_zero = 0
    header.w = width
    header.h = height
    header.cf = lv.img.CF.TRUE_COLOR_ALPHA

    return lv.RES.OK

def convert_rgba8888_to_bgra8888(img_view):
    for i in range(0, len(img_view), lv.color_t.__SIZE__):
        ch = lv.color_t.__cast__(img_view[i:i]).ch
        ch.red, ch.blue = ch.blue, ch.red

# Read and parse PNG file

def open_png(decoder, dsc):
    img_dsc = lv.img_dsc_t.__cast__(dsc.src)
    png_data = img_dsc.data
    png_size = img_dsc.data_size
    png_decoded = png.C_Pointer()
    png_width = png.C_Pointer()
    png_height = png.C_Pointer()
    error = png.decode32(png_decoded, png_width, png_height, png_data, png_size)
    if error:
        raise lodepng_error(error)
    img_size = png_width.int_val * png_height.int_val * 4
    img_data = png_decoded.ptr_val
    img_view = img_data.__dereference__(img_size)

    if COLOR_SIZE == 4:
        convert_rgba8888_to_bgra8888(img_view)
    else:
        raise lodepng_error("Error: Color mode not supported yet!")

    dsc.img_data = img_data
    return lv.RES.OK

# Above: Taken from https://github.com/lvgl/lv_binding_micropython/blob/master/driver/js/imagetools.py#L22-L94

decoder = lv.img.decoder_create()
decoder.info_cb = get_png_info
decoder.open_cb = open_png

def anim_x_cb(obj, v):
    obj.set_x(v)

def anim_y_cb(obj, v):
    obj.set_y(v)

def ta_event_cb(e,kb):
    code = e.get_code()
    ta = e.get_target()
    if code == lv.EVENT.FOCUSED:
        kb.set_textarea(ta)
        kb.move_foreground()
        kb.clear_flag(lv.obj.FLAG.HIDDEN)

    if code == lv.EVENT.DEFOCUSED:
        kb.set_textarea(None)
        kb.move_background()
        kb.add_flag(lv.obj.FLAG.HIDDEN)


mainscan = lv.obj()
mainscan.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_mainscan_main_main_default
style_mainscan_main_main_default = lv.style_t()
style_mainscan_main_main_default.init()
style_mainscan_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_mainscan_main_main_default.set_bg_opa(122)

# add style for mainscan
mainscan.add_style(style_mainscan_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

mainscan_btn_1 = lv.btn(mainscan)
mainscan_btn_1.set_pos(int(56),int(76))
mainscan_btn_1.set_size(160,80)
mainscan_btn_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
mainscan_btn_1_label = lv.label(mainscan_btn_1)
mainscan_btn_1_label.set_text("耳标管理")
mainscan_btn_1.set_style_pad_all(0, lv.STATE.DEFAULT)
mainscan_btn_1_label.align(lv.ALIGN.CENTER,0,0)
# create style style_mainscan_btn_1_main_main_default
style_mainscan_btn_1_main_main_default = lv.style_t()
style_mainscan_btn_1_main_main_default.init()
style_mainscan_btn_1_main_main_default.set_radius(5)
style_mainscan_btn_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_mainscan_btn_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_mainscan_btn_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_mainscan_btn_1_main_main_default.set_bg_opa(255)
style_mainscan_btn_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_mainscan_btn_1_main_main_default.set_border_width(0)
style_mainscan_btn_1_main_main_default.set_border_opa(255)
style_mainscan_btn_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_mainscan_btn_1_main_main_default.set_text_font(lv.font_simsun_18)
except AttributeError:
    try:
        style_mainscan_btn_1_main_main_default.set_text_font(lv.font_montserrat_18)
    except AttributeError:
        style_mainscan_btn_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_mainscan_btn_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for mainscan_btn_1
mainscan_btn_1.add_style(style_mainscan_btn_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

mainscan_btn_2 = lv.btn(mainscan)
mainscan_btn_2.set_pos(int(265),int(76))
mainscan_btn_2.set_size(160,80)
mainscan_btn_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
mainscan_btn_2_label = lv.label(mainscan_btn_2)
mainscan_btn_2_label.set_text("耳标录入")
mainscan_btn_2.set_style_pad_all(0, lv.STATE.DEFAULT)
mainscan_btn_2_label.align(lv.ALIGN.CENTER,0,0)
# create style style_mainscan_btn_2_main_main_default
style_mainscan_btn_2_main_main_default = lv.style_t()
style_mainscan_btn_2_main_main_default.init()
style_mainscan_btn_2_main_main_default.set_radius(5)
style_mainscan_btn_2_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_mainscan_btn_2_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_mainscan_btn_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_mainscan_btn_2_main_main_default.set_bg_opa(255)
style_mainscan_btn_2_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_mainscan_btn_2_main_main_default.set_border_width(0)
style_mainscan_btn_2_main_main_default.set_border_opa(255)
style_mainscan_btn_2_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_mainscan_btn_2_main_main_default.set_text_font(lv.font_simsun_18)
except AttributeError:
    try:
        style_mainscan_btn_2_main_main_default.set_text_font(lv.font_montserrat_18)
    except AttributeError:
        style_mainscan_btn_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_mainscan_btn_2_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for mainscan_btn_2
mainscan_btn_2.add_style(style_mainscan_btn_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

mainscan_btn_3 = lv.btn(mainscan)
mainscan_btn_3.set_pos(int(56),int(190))
mainscan_btn_3.set_size(160,80)
mainscan_btn_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
mainscan_btn_3_label = lv.label(mainscan_btn_3)
mainscan_btn_3_label.set_text("来源追溯")
mainscan_btn_3.set_style_pad_all(0, lv.STATE.DEFAULT)
mainscan_btn_3_label.align(lv.ALIGN.CENTER,0,0)
# create style style_mainscan_btn_3_main_main_default
style_mainscan_btn_3_main_main_default = lv.style_t()
style_mainscan_btn_3_main_main_default.init()
style_mainscan_btn_3_main_main_default.set_radius(5)
style_mainscan_btn_3_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_mainscan_btn_3_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_mainscan_btn_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_mainscan_btn_3_main_main_default.set_bg_opa(255)
style_mainscan_btn_3_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_mainscan_btn_3_main_main_default.set_border_width(0)
style_mainscan_btn_3_main_main_default.set_border_opa(255)
style_mainscan_btn_3_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_mainscan_btn_3_main_main_default.set_text_font(lv.font_simsun_18)
except AttributeError:
    try:
        style_mainscan_btn_3_main_main_default.set_text_font(lv.font_montserrat_18)
    except AttributeError:
        style_mainscan_btn_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_mainscan_btn_3_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for mainscan_btn_3
mainscan_btn_3.add_style(style_mainscan_btn_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

mainscan_btn_4 = lv.btn(mainscan)
mainscan_btn_4.set_pos(int(264),int(190))
mainscan_btn_4.set_size(160,80)
mainscan_btn_4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
mainscan_btn_4_label = lv.label(mainscan_btn_4)
mainscan_btn_4_label.set_text("系统设置")
mainscan_btn_4.set_style_pad_all(0, lv.STATE.DEFAULT)
mainscan_btn_4_label.align(lv.ALIGN.CENTER,0,0)
# create style style_mainscan_btn_4_main_main_default
style_mainscan_btn_4_main_main_default = lv.style_t()
style_mainscan_btn_4_main_main_default.init()
style_mainscan_btn_4_main_main_default.set_radius(5)
style_mainscan_btn_4_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_mainscan_btn_4_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_mainscan_btn_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_mainscan_btn_4_main_main_default.set_bg_opa(255)
style_mainscan_btn_4_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_mainscan_btn_4_main_main_default.set_border_width(0)
style_mainscan_btn_4_main_main_default.set_border_opa(255)
style_mainscan_btn_4_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_mainscan_btn_4_main_main_default.set_text_font(lv.font_simsun_18)
except AttributeError:
    try:
        style_mainscan_btn_4_main_main_default.set_text_font(lv.font_montserrat_18)
    except AttributeError:
        style_mainscan_btn_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_mainscan_btn_4_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for mainscan_btn_4
mainscan_btn_4.add_style(style_mainscan_btn_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


mainscan_digital_clock_1 = lv.dclock(mainscan, "11:25:50 AM")
mainscan_digital_clock_1.set_text("11:25:50 AM")



class mainscan_digital_clock_1_timerClass():
    def __init__(self):
        self.hour = 11
        self.minute = 25
        self.second = 50
        self.meridiem = "AM"
  
    def count_24(self, timer):
        self.second += 1
        if self.second == 60:
            self.second = 0
            self.minute += 1
	
        if self.minute == 60:
            self.minute = 0
            self.hour +=1
            
        if self.hour == 24:
            self.hour = 0

        mainscan_digital_clock_1.set_text("%02d:%02d:%02d" %(self.hour, self.minute, self.second))

    def count_12(self, timer):
        self.second += 1
        if self.second == 60:
            self.second = 0
            self.minute += 1
        if self.minute == 60:
            self.minute = 0
            if self.hour < 12:
                self.hour += 1
            else:
                self.hour += 1
                self.hour = self.hour % 12
        if (self.hour == 12 and self.second == 0 and self.minute == 0):
            if(self.meridiem == "PM"):
                self.meridiem = "AM"
            else:
                self.meridiem = "PM"
		
        mainscan_digital_clock_1.set_text("%02d:%02d:%02d %s" %(self.hour, self.minute, self.second, self.meridiem))

mainscan_digital_clock_1_timerInstance = mainscan_digital_clock_1_timerClass()

mainscan_digital_clock_1_timer = lv.timer_create_basic()
mainscan_digital_clock_1_timer.set_period(1000)

mainscan_digital_clock_1_timer.set_cb(lambda src: mainscan_digital_clock_1_timerInstance.count_12(mainscan_digital_clock_1_timer))
lv.dclock.set_style_text_align(mainscan_digital_clock_1, lv.TEXT_ALIGN.CENTER, 0);

mainscan_digital_clock_1.set_pos(int(9),int(2))
mainscan_digital_clock_1.set_size(92,33)
mainscan_digital_clock_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_mainscan_digital_clock_1_main_main_default
style_mainscan_digital_clock_1_main_main_default = lv.style_t()
style_mainscan_digital_clock_1_main_main_default.init()
style_mainscan_digital_clock_1_main_main_default.set_radius(0)
style_mainscan_digital_clock_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_mainscan_digital_clock_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_mainscan_digital_clock_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_mainscan_digital_clock_1_main_main_default.set_bg_opa(0)
style_mainscan_digital_clock_1_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_mainscan_digital_clock_1_main_main_default.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_mainscan_digital_clock_1_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_mainscan_digital_clock_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_mainscan_digital_clock_1_main_main_default.set_text_letter_space(0)
style_mainscan_digital_clock_1_main_main_default.set_pad_left(0)
style_mainscan_digital_clock_1_main_main_default.set_pad_right(0)
style_mainscan_digital_clock_1_main_main_default.set_pad_top(7)
style_mainscan_digital_clock_1_main_main_default.set_pad_bottom(0)

# add style for mainscan_digital_clock_1
mainscan_digital_clock_1.add_style(style_mainscan_digital_clock_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

mainscan_img_1 = lv.img(mainscan)
mainscan_img_1.set_pos(int(442),int(1))
mainscan_img_1.set_size(31,35)
mainscan_img_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
mainscan_img_1.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('H:\\lv\\lvgl_s\\generated\\mPythonImages\\mp-1935416437.png','rb') as f:
        mainscan_img_1_img_data = f.read()
except:
    print('Could not open H:\\lv\\lvgl_s\\generated\\mPythonImages\\mp-1935416437.png')
    sys.exit()

mainscan_img_1_img = lv.img_dsc_t({
  'data_size': len(mainscan_img_1_img_data),
  'header': {'always_zero': 0, 'w': 31, 'h': 35, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': mainscan_img_1_img_data
})

mainscan_img_1.set_src(mainscan_img_1_img)
mainscan_img_1.set_pivot(50,50)
mainscan_img_1.set_angle(0)
# create style style_mainscan_img_1_main_main_default
style_mainscan_img_1_main_main_default = lv.style_t()
style_mainscan_img_1_main_main_default.init()
style_mainscan_img_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_mainscan_img_1_main_main_default.set_img_recolor_opa(0)
style_mainscan_img_1_main_main_default.set_img_opa(255)

# add style for mainscan_img_1
mainscan_img_1.add_style(style_mainscan_img_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

mainscan_label_1 = lv.label(mainscan)
mainscan_label_1.set_pos(int(104.5),int(288))
mainscan_label_1.set_size(271,21)
mainscan_label_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
mainscan_label_1.set_text("欢迎使用绵羊耳标管理系统.")
mainscan_label_1.set_long_mode(lv.label.LONG.WRAP)
# create style style_mainscan_label_1_main_main_default
style_mainscan_label_1_main_main_default = lv.style_t()
style_mainscan_label_1_main_main_default.init()
style_mainscan_label_1_main_main_default.set_radius(0)
style_mainscan_label_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_mainscan_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_mainscan_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_mainscan_label_1_main_main_default.set_bg_opa(0)
style_mainscan_label_1_main_main_default.set_text_color(lv.color_make(0x0a,0x0a,0x0a))
try:
    style_mainscan_label_1_main_main_default.set_text_font(lv.font_simsun_10)
except AttributeError:
    try:
        style_mainscan_label_1_main_main_default.set_text_font(lv.font_montserrat_10)
    except AttributeError:
        style_mainscan_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_mainscan_label_1_main_main_default.set_text_letter_space(2)
style_mainscan_label_1_main_main_default.set_text_line_space(0)
style_mainscan_label_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_mainscan_label_1_main_main_default.set_pad_left(0)
style_mainscan_label_1_main_main_default.set_pad_right(0)
style_mainscan_label_1_main_main_default.set_pad_top(8)
style_mainscan_label_1_main_main_default.set_pad_bottom(0)

# add style for mainscan_label_1
mainscan_label_1.add_style(style_mainscan_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

er_trace = lv.obj()
er_trace.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_er_trace_main_main_default
style_er_trace_main_main_default = lv.style_t()
style_er_trace_main_main_default.init()
style_er_trace_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_er_trace_main_main_default.set_bg_opa(0)

# add style for er_trace
er_trace.add_style(style_er_trace_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

er_trace_table_1 = lv.table(er_trace)
er_trace_table_1.set_pos(int(36),int(50))
er_trace_table_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
er_trace_table_1.set_col_cnt(3)
er_trace_table_1.set_row_cnt(8)
er_trace_table_1.set_cell_value(0, 0, "Name")
er_trace_table_1.set_cell_value(0+1, 0, "Apple")
er_trace_table_1.set_cell_value(1+1, 0, "Banana")
er_trace_table_1.set_cell_value(2+1, 0, "Citron")
er_trace_table_1.set_cell_value(3+1, 0, "Name")
er_trace_table_1.set_cell_value(4+1, 0, "Name")
er_trace_table_1.set_cell_value(5+1, 0, "Name")
er_trace_table_1.set_cell_value(6+1, 0, "Name")
er_trace_table_1.set_cell_value(0, 1, "Price")
er_trace_table_1.set_cell_value(0+1, 1, "$1")
er_trace_table_1.set_cell_value(1+1, 1, "$2")
er_trace_table_1.set_cell_value(2+1, 1, "$3")
er_trace_table_1.set_cell_value(3+1, 1, "Price")
er_trace_table_1.set_cell_value(4+1, 1, "Price")
er_trace_table_1.set_cell_value(5+1, 1, "Price")
er_trace_table_1.set_cell_value(6+1, 1, "Price")
er_trace_table_1.set_cell_value(0, 2, "title")
er_trace_table_1.set_cell_value(0+1, 2, "0")
er_trace_table_1.set_cell_value(1+1, 2, "0")
er_trace_table_1.set_cell_value(2+1, 2, "0")
er_trace_table_1.set_cell_value(3+1, 2, "0")
er_trace_table_1.set_cell_value(4+1, 2, "0")
er_trace_table_1.set_cell_value(5+1, 2, "0")
er_trace_table_1.set_cell_value(6+1, 2, "0")
er_trace_table_1.set_style_pad_left(10, lv.PART.ITEMS | lv.STATE.DEFAULT)
er_trace_table_1.set_style_pad_right(10, lv.PART.ITEMS | lv.STATE.DEFAULT)
er_trace_table_1.set_style_pad_top(10, lv.PART.ITEMS | lv.STATE.DEFAULT)
er_trace_table_1.set_style_pad_bottom(10, lv.PART.ITEMS | lv.STATE.DEFAULT)
# create style style_er_trace_table_1_main_main_default
style_er_trace_table_1_main_main_default = lv.style_t()
style_er_trace_table_1_main_main_default.init()
style_er_trace_table_1_main_main_default.set_radius(1)
style_er_trace_table_1_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_er_trace_table_1_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_er_trace_table_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_er_trace_table_1_main_main_default.set_bg_opa(255)
style_er_trace_table_1_main_main_default.set_border_color(lv.color_make(0xd5,0xde,0xe6))
style_er_trace_table_1_main_main_default.set_border_width(0)
style_er_trace_table_1_main_main_default.set_border_opa(255)
style_er_trace_table_1_main_main_default.set_pad_left(0)
style_er_trace_table_1_main_main_default.set_pad_right(0)
style_er_trace_table_1_main_main_default.set_pad_top(0)
style_er_trace_table_1_main_main_default.set_pad_bottom(0)

# add style for er_trace_table_1
er_trace_table_1.add_style(style_er_trace_table_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_er_trace_table_1_main_items_default
style_er_trace_table_1_main_items_default = lv.style_t()
style_er_trace_table_1_main_items_default.init()
style_er_trace_table_1_main_items_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_er_trace_table_1_main_items_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_er_trace_table_1_main_items_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_er_trace_table_1_main_items_default.set_bg_opa(0)
style_er_trace_table_1_main_items_default.set_border_color(lv.color_make(0xd5,0xde,0xe6))
style_er_trace_table_1_main_items_default.set_border_width(3)
style_er_trace_table_1_main_items_default.set_border_opa(255)
style_er_trace_table_1_main_items_default.set_text_color(lv.color_make(0x39,0x3c,0x41))
try:
    style_er_trace_table_1_main_items_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_er_trace_table_1_main_items_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_er_trace_table_1_main_items_default.set_text_font(lv.font_montserrat_16)
style_er_trace_table_1_main_items_default.set_text_decor(lv.TEXT_DECOR.NONE)

# add style for er_trace_table_1
er_trace_table_1.add_style(style_er_trace_table_1_main_items_default, lv.PART.ITEMS|lv.STATE.DEFAULT)

er_trace_imgbtn_1 = lv.imgbtn(er_trace)
er_trace_imgbtn_1.set_pos(int(-1),int(0))
er_trace_imgbtn_1.set_size(37,34)
er_trace_imgbtn_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('H:\\lv\\lvgl_s\\generated\\mPythonImages\\mp-30085128.png','rb') as f:
        er_trace_imgbtn_1_imgReleased_data = f.read()
except:
    print('Could not open H:\\lv\\lvgl_s\\generated\\mPythonImages\\mp-30085128.png')
    sys.exit()

er_trace_imgbtn_1_imgReleased = lv.img_dsc_t({
  'data_size': len(er_trace_imgbtn_1_imgReleased_data),
  'header': {'always_zero': 0, 'w': 37, 'h': 34, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': er_trace_imgbtn_1_imgReleased_data
})
er_trace_imgbtn_1.set_src(lv.imgbtn.STATE.RELEASED, None, er_trace_imgbtn_1_imgReleased, None)

try:
    with open('H:\\lv\\lvgl_s\\generated\\mPythonImages\\mp-30085128.png','rb') as f:
        er_trace_imgbtn_1_imgPressed_data = f.read()
except:
    print('Could not open H:\\lv\\lvgl_s\\generated\\mPythonImages\\mp-30085128.png')
    sys.exit()

er_trace_imgbtn_1_imgPressed = lv.img_dsc_t({
  'data_size': len(er_trace_imgbtn_1_imgPressed_data),
  'header': {'always_zero': 0, 'w': 37, 'h': 34, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': er_trace_imgbtn_1_imgPressed_data
})
er_trace_imgbtn_1.set_src(lv.imgbtn.STATE.PRESSED, None, er_trace_imgbtn_1_imgPressed, None)




er_trace_imgbtn_1.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_er_trace_imgbtn_1_main_main_default
style_er_trace_imgbtn_1_main_main_default = lv.style_t()
style_er_trace_imgbtn_1_main_main_default.init()
style_er_trace_imgbtn_1_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_er_trace_imgbtn_1_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_er_trace_imgbtn_1_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_er_trace_imgbtn_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_er_trace_imgbtn_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_er_trace_imgbtn_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_er_trace_imgbtn_1_main_main_default.set_img_recolor_opa(0)
style_er_trace_imgbtn_1_main_main_default.set_img_opa(255)

# add style for er_trace_imgbtn_1
er_trace_imgbtn_1.add_style(style_er_trace_imgbtn_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_er_trace_imgbtn_1_main_main_pressed
style_er_trace_imgbtn_1_main_main_pressed = lv.style_t()
style_er_trace_imgbtn_1_main_main_pressed.init()
style_er_trace_imgbtn_1_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_er_trace_imgbtn_1_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_er_trace_imgbtn_1_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_er_trace_imgbtn_1_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_er_trace_imgbtn_1_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_er_trace_imgbtn_1_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_er_trace_imgbtn_1_main_main_pressed.set_img_recolor_opa(0)
style_er_trace_imgbtn_1_main_main_pressed.set_img_opa(255)

# add style for er_trace_imgbtn_1
er_trace_imgbtn_1.add_style(style_er_trace_imgbtn_1_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_er_trace_imgbtn_1_main_main_checked
style_er_trace_imgbtn_1_main_main_checked = lv.style_t()
style_er_trace_imgbtn_1_main_main_checked.init()
style_er_trace_imgbtn_1_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_er_trace_imgbtn_1_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_er_trace_imgbtn_1_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_er_trace_imgbtn_1_main_main_checked.set_text_font(lv.font_montserrat_16)
style_er_trace_imgbtn_1_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_er_trace_imgbtn_1_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_er_trace_imgbtn_1_main_main_checked.set_img_recolor_opa(0)
style_er_trace_imgbtn_1_main_main_checked.set_img_opa(255)

# add style for er_trace_imgbtn_1
er_trace_imgbtn_1.add_style(style_er_trace_imgbtn_1_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

Xin_xi_luru = lv.obj()
Xin_xi_luru.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_xin_xi_luru_main_main_default
style_xin_xi_luru_main_main_default = lv.style_t()
style_xin_xi_luru_main_main_default.init()
style_xin_xi_luru_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_xin_xi_luru_main_main_default.set_bg_opa(0)

# add style for Xin_xi_luru
Xin_xi_luru.add_style(style_xin_xi_luru_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Xin_xi_luru_tileview_1 = lv.tileview(Xin_xi_luru)
Xin_xi_luru_tileview_1.set_pos(int(8),int(37))
Xin_xi_luru_tileview_1.set_size(464,276)
Xin_xi_luru_tileview_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.ON)
Xin_xi_luru_tileview_1_tile_2 = Xin_xi_luru_tileview_1.add_tile(0 , 1, lv.DIR.TOP)
Xin_xi_luru_label_6 = lv.label(Xin_xi_luru_tileview_1_tile_2)
Xin_xi_luru_label_6.set_pos(int(34),int(20))
Xin_xi_luru_label_6.set_size(144,32)
Xin_xi_luru_label_6.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
Xin_xi_luru_label_6.set_text("体重/Kg：")
Xin_xi_luru_label_6.set_long_mode(lv.label.LONG.WRAP)
# create style style_xin_xi_luru_label_6_main_main_default
style_xin_xi_luru_label_6_main_main_default = lv.style_t()
style_xin_xi_luru_label_6_main_main_default.init()
style_xin_xi_luru_label_6_main_main_default.set_radius(0)
style_xin_xi_luru_label_6_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_xin_xi_luru_label_6_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_xin_xi_luru_label_6_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_xin_xi_luru_label_6_main_main_default.set_bg_opa(115)
style_xin_xi_luru_label_6_main_main_default.set_text_color(lv.color_make(0x08,0x08,0x08))
try:
    style_xin_xi_luru_label_6_main_main_default.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_xin_xi_luru_label_6_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_xin_xi_luru_label_6_main_main_default.set_text_font(lv.font_montserrat_16)
style_xin_xi_luru_label_6_main_main_default.set_text_letter_space(2)
style_xin_xi_luru_label_6_main_main_default.set_text_line_space(0)
style_xin_xi_luru_label_6_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_xin_xi_luru_label_6_main_main_default.set_pad_left(0)
style_xin_xi_luru_label_6_main_main_default.set_pad_right(0)
style_xin_xi_luru_label_6_main_main_default.set_pad_top(8)
style_xin_xi_luru_label_6_main_main_default.set_pad_bottom(0)

# add style for Xin_xi_luru_label_6
Xin_xi_luru_label_6.add_style(style_xin_xi_luru_label_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Xin_xi_luru_ta_2 = lv.textarea(Xin_xi_luru_tileview_1_tile_2)
Xin_xi_luru_ta_2.set_pos(int(223),int(20))
Xin_xi_luru_ta_2.set_size(125,37)
Xin_xi_luru_ta_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
Xin_xi_luru_ta_2.set_text("input")


try:
    Xin_xi_luru_tileview_1_tile_2_kb
except NameError:
    Xin_xi_luru_tileview_1_tile_2_kb = lv.keyboard(Xin_xi_luru_tileview_1_tile_2,)

Xin_xi_luru_tileview_1_tile_2_kb.add_flag(lv.obj.FLAG.HIDDEN)
Xin_xi_luru_tileview_1_tile_2_kb.set_textarea(Xin_xi_luru_ta_2)
Xin_xi_luru_ta_2.add_event_cb(lambda e: ta_event_cb(e,Xin_xi_luru_tileview_1_tile_2_kb), lv.EVENT.ALL, None)
# create style style_xin_xi_luru_ta_2_main_main_default
style_xin_xi_luru_ta_2_main_main_default = lv.style_t()
style_xin_xi_luru_ta_2_main_main_default.init()
style_xin_xi_luru_ta_2_main_main_default.set_radius(4)
style_xin_xi_luru_ta_2_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_xin_xi_luru_ta_2_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_xin_xi_luru_ta_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_xin_xi_luru_ta_2_main_main_default.set_bg_opa(255)
style_xin_xi_luru_ta_2_main_main_default.set_border_color(lv.color_make(0xe6,0xe6,0xe6))
style_xin_xi_luru_ta_2_main_main_default.set_border_width(2)
style_xin_xi_luru_ta_2_main_main_default.set_border_opa(255)
style_xin_xi_luru_ta_2_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_xin_xi_luru_ta_2_main_main_default.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_xin_xi_luru_ta_2_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_xin_xi_luru_ta_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_xin_xi_luru_ta_2_main_main_default.set_text_letter_space(2)
style_xin_xi_luru_ta_2_main_main_default.set_text_align(lv.TEXT_ALIGN.LEFT)
style_xin_xi_luru_ta_2_main_main_default.set_pad_left(4)
style_xin_xi_luru_ta_2_main_main_default.set_pad_right(4)
style_xin_xi_luru_ta_2_main_main_default.set_pad_top(4)
style_xin_xi_luru_ta_2_main_main_default.set_pad_bottom(4)

# add style for Xin_xi_luru_ta_2
Xin_xi_luru_ta_2.add_style(style_xin_xi_luru_ta_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_xin_xi_luru_ta_2_main_scrollbar_default
style_xin_xi_luru_ta_2_main_scrollbar_default = lv.style_t()
style_xin_xi_luru_ta_2_main_scrollbar_default.init()
style_xin_xi_luru_ta_2_main_scrollbar_default.set_radius(0)
style_xin_xi_luru_ta_2_main_scrollbar_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_xin_xi_luru_ta_2_main_scrollbar_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_xin_xi_luru_ta_2_main_scrollbar_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_xin_xi_luru_ta_2_main_scrollbar_default.set_bg_opa(255)

# add style for Xin_xi_luru_ta_2
Xin_xi_luru_ta_2.add_style(style_xin_xi_luru_ta_2_main_scrollbar_default, lv.PART.SCROLLBAR|lv.STATE.DEFAULT)

Xin_xi_luru_label_9 = lv.label(Xin_xi_luru_tileview_1_tile_2)
Xin_xi_luru_label_9.set_pos(int(34),int(74))
Xin_xi_luru_label_9.set_size(144,32)
Xin_xi_luru_label_9.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
Xin_xi_luru_label_9.set_text("疾病信息档案：")
Xin_xi_luru_label_9.set_long_mode(lv.label.LONG.WRAP)
# create style style_xin_xi_luru_label_9_main_main_default
style_xin_xi_luru_label_9_main_main_default = lv.style_t()
style_xin_xi_luru_label_9_main_main_default.init()
style_xin_xi_luru_label_9_main_main_default.set_radius(0)
style_xin_xi_luru_label_9_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_xin_xi_luru_label_9_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_xin_xi_luru_label_9_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_xin_xi_luru_label_9_main_main_default.set_bg_opa(117)
style_xin_xi_luru_label_9_main_main_default.set_text_color(lv.color_make(0x05,0x05,0x05))
try:
    style_xin_xi_luru_label_9_main_main_default.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_xin_xi_luru_label_9_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_xin_xi_luru_label_9_main_main_default.set_text_font(lv.font_montserrat_16)
style_xin_xi_luru_label_9_main_main_default.set_text_letter_space(2)
style_xin_xi_luru_label_9_main_main_default.set_text_line_space(0)
style_xin_xi_luru_label_9_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_xin_xi_luru_label_9_main_main_default.set_pad_left(0)
style_xin_xi_luru_label_9_main_main_default.set_pad_right(0)
style_xin_xi_luru_label_9_main_main_default.set_pad_top(8)
style_xin_xi_luru_label_9_main_main_default.set_pad_bottom(0)

# add style for Xin_xi_luru_label_9
Xin_xi_luru_label_9.add_style(style_xin_xi_luru_label_9_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Xin_xi_luru_ddlist_5 = lv.dropdown(Xin_xi_luru_tileview_1_tile_2)
Xin_xi_luru_ddlist_5.set_pos(int(224),int(77))
Xin_xi_luru_ddlist_5.set_size(122,30)
Xin_xi_luru_ddlist_5.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
Xin_xi_luru_ddlist_5.set_options("无\n是")

Xin_xi_luru_ddlist_5_list = Xin_xi_luru_ddlist_5.get_list()
# create style style_xin_xi_luru_ddlist_5_extra_list_selected_checked
style_xin_xi_luru_ddlist_5_extra_list_selected_checked = lv.style_t()
style_xin_xi_luru_ddlist_5_extra_list_selected_checked.init()
style_xin_xi_luru_ddlist_5_extra_list_selected_checked.set_radius(3)
style_xin_xi_luru_ddlist_5_extra_list_selected_checked.set_bg_color(lv.color_make(0x00,0xa1,0xb5))
style_xin_xi_luru_ddlist_5_extra_list_selected_checked.set_bg_grad_color(lv.color_make(0x00,0xa1,0xb5))
style_xin_xi_luru_ddlist_5_extra_list_selected_checked.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_xin_xi_luru_ddlist_5_extra_list_selected_checked.set_bg_opa(255)
style_xin_xi_luru_ddlist_5_extra_list_selected_checked.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_xin_xi_luru_ddlist_5_extra_list_selected_checked.set_border_width(1)
style_xin_xi_luru_ddlist_5_extra_list_selected_checked.set_border_opa(255)
style_xin_xi_luru_ddlist_5_extra_list_selected_checked.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_xin_xi_luru_ddlist_5_extra_list_selected_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_xin_xi_luru_ddlist_5_extra_list_selected_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_xin_xi_luru_ddlist_5_extra_list_selected_checked.set_text_font(lv.font_montserrat_16)

# add style for Xin_xi_luru_ddlist_5_list
Xin_xi_luru_ddlist_5_list.add_style(style_xin_xi_luru_ddlist_5_extra_list_selected_checked, lv.PART.SELECTED|lv.STATE.CHECKED)

# create style style_xin_xi_luru_ddlist_5_extra_list_main_default
style_xin_xi_luru_ddlist_5_extra_list_main_default = lv.style_t()
style_xin_xi_luru_ddlist_5_extra_list_main_default.init()
style_xin_xi_luru_ddlist_5_extra_list_main_default.set_radius(3)
style_xin_xi_luru_ddlist_5_extra_list_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_xin_xi_luru_ddlist_5_extra_list_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_xin_xi_luru_ddlist_5_extra_list_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_xin_xi_luru_ddlist_5_extra_list_main_default.set_bg_opa(255)
style_xin_xi_luru_ddlist_5_extra_list_main_default.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_xin_xi_luru_ddlist_5_extra_list_main_default.set_border_width(1)
style_xin_xi_luru_ddlist_5_extra_list_main_default.set_border_opa(255)
style_xin_xi_luru_ddlist_5_extra_list_main_default.set_text_color(lv.color_make(0x0D,0x30,0x55))
try:
    style_xin_xi_luru_ddlist_5_extra_list_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_xin_xi_luru_ddlist_5_extra_list_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_xin_xi_luru_ddlist_5_extra_list_main_default.set_text_font(lv.font_montserrat_16)
style_xin_xi_luru_ddlist_5_extra_list_main_default.set_max_height(90)

# add style for Xin_xi_luru_ddlist_5_list
Xin_xi_luru_ddlist_5_list.add_style(style_xin_xi_luru_ddlist_5_extra_list_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_xin_xi_luru_ddlist_5_extra_list_scrollbar_default
style_xin_xi_luru_ddlist_5_extra_list_scrollbar_default = lv.style_t()
style_xin_xi_luru_ddlist_5_extra_list_scrollbar_default.init()
style_xin_xi_luru_ddlist_5_extra_list_scrollbar_default.set_radius(3)
style_xin_xi_luru_ddlist_5_extra_list_scrollbar_default.set_bg_color(lv.color_make(0x00,0xff,0x00))
style_xin_xi_luru_ddlist_5_extra_list_scrollbar_default.set_bg_opa(255)

# add style for Xin_xi_luru_ddlist_5_list
Xin_xi_luru_ddlist_5_list.add_style(style_xin_xi_luru_ddlist_5_extra_list_scrollbar_default, lv.PART.SCROLLBAR|lv.STATE.DEFAULT)

# create style style_xin_xi_luru_ddlist_5_main_main_default
style_xin_xi_luru_ddlist_5_main_main_default = lv.style_t()
style_xin_xi_luru_ddlist_5_main_main_default.init()
style_xin_xi_luru_ddlist_5_main_main_default.set_radius(3)
style_xin_xi_luru_ddlist_5_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_xin_xi_luru_ddlist_5_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_xin_xi_luru_ddlist_5_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_xin_xi_luru_ddlist_5_main_main_default.set_bg_opa(255)
style_xin_xi_luru_ddlist_5_main_main_default.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_xin_xi_luru_ddlist_5_main_main_default.set_border_width(1)
style_xin_xi_luru_ddlist_5_main_main_default.set_border_opa(255)
style_xin_xi_luru_ddlist_5_main_main_default.set_text_color(lv.color_make(0x0D,0x30,0x55))
try:
    style_xin_xi_luru_ddlist_5_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_xin_xi_luru_ddlist_5_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_xin_xi_luru_ddlist_5_main_main_default.set_text_font(lv.font_montserrat_16)
style_xin_xi_luru_ddlist_5_main_main_default.set_pad_left(6)
style_xin_xi_luru_ddlist_5_main_main_default.set_pad_right(6)
style_xin_xi_luru_ddlist_5_main_main_default.set_pad_top(8)

# add style for Xin_xi_luru_ddlist_5
Xin_xi_luru_ddlist_5.add_style(style_xin_xi_luru_ddlist_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Xin_xi_luru_tileview_1_tile_1 = Xin_xi_luru_tileview_1.add_tile(0, 0, lv.DIR.BOTTOM)
Xin_xi_luru_label_1 = lv.label(Xin_xi_luru_tileview_1_tile_1)
Xin_xi_luru_label_1.set_pos(int(34),int(19))
Xin_xi_luru_label_1.set_size(144,32)
Xin_xi_luru_label_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
Xin_xi_luru_label_1.set_text("耳标:\n")
Xin_xi_luru_label_1.set_long_mode(lv.label.LONG.WRAP)
# create style style_xin_xi_luru_label_1_main_main_default
style_xin_xi_luru_label_1_main_main_default = lv.style_t()
style_xin_xi_luru_label_1_main_main_default.init()
style_xin_xi_luru_label_1_main_main_default.set_radius(0)
style_xin_xi_luru_label_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_xin_xi_luru_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_xin_xi_luru_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_xin_xi_luru_label_1_main_main_default.set_bg_opa(115)
style_xin_xi_luru_label_1_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_xin_xi_luru_label_1_main_main_default.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_xin_xi_luru_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_xin_xi_luru_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_xin_xi_luru_label_1_main_main_default.set_text_letter_space(2)
style_xin_xi_luru_label_1_main_main_default.set_text_line_space(0)
style_xin_xi_luru_label_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_xin_xi_luru_label_1_main_main_default.set_pad_left(0)
style_xin_xi_luru_label_1_main_main_default.set_pad_right(0)
style_xin_xi_luru_label_1_main_main_default.set_pad_top(8)
style_xin_xi_luru_label_1_main_main_default.set_pad_bottom(0)

# add style for Xin_xi_luru_label_1
Xin_xi_luru_label_1.add_style(style_xin_xi_luru_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Xin_xi_luru_label_2 = lv.label(Xin_xi_luru_tileview_1_tile_1)
Xin_xi_luru_label_2.set_pos(int(34),int(65))
Xin_xi_luru_label_2.set_size(144,32)
Xin_xi_luru_label_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
Xin_xi_luru_label_2.set_text("公/母羊：")
Xin_xi_luru_label_2.set_long_mode(lv.label.LONG.WRAP)
# create style style_xin_xi_luru_label_2_main_main_default
style_xin_xi_luru_label_2_main_main_default = lv.style_t()
style_xin_xi_luru_label_2_main_main_default.init()
style_xin_xi_luru_label_2_main_main_default.set_radius(0)
style_xin_xi_luru_label_2_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_xin_xi_luru_label_2_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_xin_xi_luru_label_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_xin_xi_luru_label_2_main_main_default.set_bg_opa(115)
style_xin_xi_luru_label_2_main_main_default.set_text_color(lv.color_make(0x08,0x08,0x08))
try:
    style_xin_xi_luru_label_2_main_main_default.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_xin_xi_luru_label_2_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_xin_xi_luru_label_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_xin_xi_luru_label_2_main_main_default.set_text_letter_space(2)
style_xin_xi_luru_label_2_main_main_default.set_text_line_space(0)
style_xin_xi_luru_label_2_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_xin_xi_luru_label_2_main_main_default.set_pad_left(0)
style_xin_xi_luru_label_2_main_main_default.set_pad_right(0)
style_xin_xi_luru_label_2_main_main_default.set_pad_top(8)
style_xin_xi_luru_label_2_main_main_default.set_pad_bottom(0)

# add style for Xin_xi_luru_label_2
Xin_xi_luru_label_2.add_style(style_xin_xi_luru_label_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Xin_xi_luru_label_3 = lv.label(Xin_xi_luru_tileview_1_tile_1)
Xin_xi_luru_label_3.set_pos(int(34),int(115))
Xin_xi_luru_label_3.set_size(144,32)
Xin_xi_luru_label_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
Xin_xi_luru_label_3.set_text("羊龄：")
Xin_xi_luru_label_3.set_long_mode(lv.label.LONG.WRAP)
# create style style_xin_xi_luru_label_3_main_main_default
style_xin_xi_luru_label_3_main_main_default = lv.style_t()
style_xin_xi_luru_label_3_main_main_default.init()
style_xin_xi_luru_label_3_main_main_default.set_radius(0)
style_xin_xi_luru_label_3_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_xin_xi_luru_label_3_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_xin_xi_luru_label_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_xin_xi_luru_label_3_main_main_default.set_bg_opa(115)
style_xin_xi_luru_label_3_main_main_default.set_text_color(lv.color_make(0x05,0x05,0x05))
try:
    style_xin_xi_luru_label_3_main_main_default.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_xin_xi_luru_label_3_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_xin_xi_luru_label_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_xin_xi_luru_label_3_main_main_default.set_text_letter_space(2)
style_xin_xi_luru_label_3_main_main_default.set_text_line_space(0)
style_xin_xi_luru_label_3_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_xin_xi_luru_label_3_main_main_default.set_pad_left(0)
style_xin_xi_luru_label_3_main_main_default.set_pad_right(0)
style_xin_xi_luru_label_3_main_main_default.set_pad_top(8)
style_xin_xi_luru_label_3_main_main_default.set_pad_bottom(0)

# add style for Xin_xi_luru_label_3
Xin_xi_luru_label_3.add_style(style_xin_xi_luru_label_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Xin_xi_luru_label_4 = lv.label(Xin_xi_luru_tileview_1_tile_1)
Xin_xi_luru_label_4.set_pos(int(34),int(168))
Xin_xi_luru_label_4.set_size(144,32)
Xin_xi_luru_label_4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
Xin_xi_luru_label_4.set_text("品种：")
Xin_xi_luru_label_4.set_long_mode(lv.label.LONG.WRAP)
# create style style_xin_xi_luru_label_4_main_main_default
style_xin_xi_luru_label_4_main_main_default = lv.style_t()
style_xin_xi_luru_label_4_main_main_default.init()
style_xin_xi_luru_label_4_main_main_default.set_radius(0)
style_xin_xi_luru_label_4_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_xin_xi_luru_label_4_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_xin_xi_luru_label_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_xin_xi_luru_label_4_main_main_default.set_bg_opa(115)
style_xin_xi_luru_label_4_main_main_default.set_text_color(lv.color_make(0x03,0x03,0x03))
try:
    style_xin_xi_luru_label_4_main_main_default.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_xin_xi_luru_label_4_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_xin_xi_luru_label_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_xin_xi_luru_label_4_main_main_default.set_text_letter_space(2)
style_xin_xi_luru_label_4_main_main_default.set_text_line_space(0)
style_xin_xi_luru_label_4_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_xin_xi_luru_label_4_main_main_default.set_pad_left(0)
style_xin_xi_luru_label_4_main_main_default.set_pad_right(0)
style_xin_xi_luru_label_4_main_main_default.set_pad_top(8)
style_xin_xi_luru_label_4_main_main_default.set_pad_bottom(0)

# add style for Xin_xi_luru_label_4
Xin_xi_luru_label_4.add_style(style_xin_xi_luru_label_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Xin_xi_luru_label_5 = lv.label(Xin_xi_luru_tileview_1_tile_1)
Xin_xi_luru_label_5.set_pos(int(34),int(222))
Xin_xi_luru_label_5.set_size(144,32)
Xin_xi_luru_label_5.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
Xin_xi_luru_label_5.set_text("疫苗接种次数：\n")
Xin_xi_luru_label_5.set_long_mode(lv.label.LONG.WRAP)
# create style style_xin_xi_luru_label_5_main_main_default
style_xin_xi_luru_label_5_main_main_default = lv.style_t()
style_xin_xi_luru_label_5_main_main_default.init()
style_xin_xi_luru_label_5_main_main_default.set_radius(0)
style_xin_xi_luru_label_5_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_xin_xi_luru_label_5_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_xin_xi_luru_label_5_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_xin_xi_luru_label_5_main_main_default.set_bg_opa(115)
style_xin_xi_luru_label_5_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_xin_xi_luru_label_5_main_main_default.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_xin_xi_luru_label_5_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_xin_xi_luru_label_5_main_main_default.set_text_font(lv.font_montserrat_16)
style_xin_xi_luru_label_5_main_main_default.set_text_letter_space(2)
style_xin_xi_luru_label_5_main_main_default.set_text_line_space(0)
style_xin_xi_luru_label_5_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_xin_xi_luru_label_5_main_main_default.set_pad_left(0)
style_xin_xi_luru_label_5_main_main_default.set_pad_right(0)
style_xin_xi_luru_label_5_main_main_default.set_pad_top(8)
style_xin_xi_luru_label_5_main_main_default.set_pad_bottom(0)

# add style for Xin_xi_luru_label_5
Xin_xi_luru_label_5.add_style(style_xin_xi_luru_label_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Xin_xi_luru_ddlist_1 = lv.dropdown(Xin_xi_luru_tileview_1_tile_1)
Xin_xi_luru_ddlist_1.set_pos(int(222),int(68))
Xin_xi_luru_ddlist_1.set_size(130,30)
Xin_xi_luru_ddlist_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
Xin_xi_luru_ddlist_1.set_options("公\n母")

Xin_xi_luru_ddlist_1_list = Xin_xi_luru_ddlist_1.get_list()
# create style style_xin_xi_luru_ddlist_1_extra_list_selected_checked
style_xin_xi_luru_ddlist_1_extra_list_selected_checked = lv.style_t()
style_xin_xi_luru_ddlist_1_extra_list_selected_checked.init()
style_xin_xi_luru_ddlist_1_extra_list_selected_checked.set_radius(3)
style_xin_xi_luru_ddlist_1_extra_list_selected_checked.set_bg_color(lv.color_make(0x00,0xa1,0xb5))
style_xin_xi_luru_ddlist_1_extra_list_selected_checked.set_bg_grad_color(lv.color_make(0x00,0xa1,0xb5))
style_xin_xi_luru_ddlist_1_extra_list_selected_checked.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_xin_xi_luru_ddlist_1_extra_list_selected_checked.set_bg_opa(255)
style_xin_xi_luru_ddlist_1_extra_list_selected_checked.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_xin_xi_luru_ddlist_1_extra_list_selected_checked.set_border_width(1)
style_xin_xi_luru_ddlist_1_extra_list_selected_checked.set_border_opa(255)
style_xin_xi_luru_ddlist_1_extra_list_selected_checked.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_xin_xi_luru_ddlist_1_extra_list_selected_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_xin_xi_luru_ddlist_1_extra_list_selected_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_xin_xi_luru_ddlist_1_extra_list_selected_checked.set_text_font(lv.font_montserrat_16)

# add style for Xin_xi_luru_ddlist_1_list
Xin_xi_luru_ddlist_1_list.add_style(style_xin_xi_luru_ddlist_1_extra_list_selected_checked, lv.PART.SELECTED|lv.STATE.CHECKED)

# create style style_xin_xi_luru_ddlist_1_extra_list_main_default
style_xin_xi_luru_ddlist_1_extra_list_main_default = lv.style_t()
style_xin_xi_luru_ddlist_1_extra_list_main_default.init()
style_xin_xi_luru_ddlist_1_extra_list_main_default.set_radius(3)
style_xin_xi_luru_ddlist_1_extra_list_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_xin_xi_luru_ddlist_1_extra_list_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_xin_xi_luru_ddlist_1_extra_list_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_xin_xi_luru_ddlist_1_extra_list_main_default.set_bg_opa(255)
style_xin_xi_luru_ddlist_1_extra_list_main_default.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_xin_xi_luru_ddlist_1_extra_list_main_default.set_border_width(1)
style_xin_xi_luru_ddlist_1_extra_list_main_default.set_border_opa(255)
style_xin_xi_luru_ddlist_1_extra_list_main_default.set_text_color(lv.color_make(0x0D,0x30,0x55))
try:
    style_xin_xi_luru_ddlist_1_extra_list_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_xin_xi_luru_ddlist_1_extra_list_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_xin_xi_luru_ddlist_1_extra_list_main_default.set_text_font(lv.font_montserrat_16)
style_xin_xi_luru_ddlist_1_extra_list_main_default.set_max_height(90)

# add style for Xin_xi_luru_ddlist_1_list
Xin_xi_luru_ddlist_1_list.add_style(style_xin_xi_luru_ddlist_1_extra_list_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_xin_xi_luru_ddlist_1_extra_list_scrollbar_default
style_xin_xi_luru_ddlist_1_extra_list_scrollbar_default = lv.style_t()
style_xin_xi_luru_ddlist_1_extra_list_scrollbar_default.init()
style_xin_xi_luru_ddlist_1_extra_list_scrollbar_default.set_radius(3)
style_xin_xi_luru_ddlist_1_extra_list_scrollbar_default.set_bg_color(lv.color_make(0x00,0xff,0x00))
style_xin_xi_luru_ddlist_1_extra_list_scrollbar_default.set_bg_opa(255)

# add style for Xin_xi_luru_ddlist_1_list
Xin_xi_luru_ddlist_1_list.add_style(style_xin_xi_luru_ddlist_1_extra_list_scrollbar_default, lv.PART.SCROLLBAR|lv.STATE.DEFAULT)

# create style style_xin_xi_luru_ddlist_1_main_main_default
style_xin_xi_luru_ddlist_1_main_main_default = lv.style_t()
style_xin_xi_luru_ddlist_1_main_main_default.init()
style_xin_xi_luru_ddlist_1_main_main_default.set_radius(3)
style_xin_xi_luru_ddlist_1_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_xin_xi_luru_ddlist_1_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_xin_xi_luru_ddlist_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_xin_xi_luru_ddlist_1_main_main_default.set_bg_opa(255)
style_xin_xi_luru_ddlist_1_main_main_default.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_xin_xi_luru_ddlist_1_main_main_default.set_border_width(1)
style_xin_xi_luru_ddlist_1_main_main_default.set_border_opa(255)
style_xin_xi_luru_ddlist_1_main_main_default.set_text_color(lv.color_make(0x0D,0x30,0x55))
try:
    style_xin_xi_luru_ddlist_1_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_xin_xi_luru_ddlist_1_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_xin_xi_luru_ddlist_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_xin_xi_luru_ddlist_1_main_main_default.set_pad_left(6)
style_xin_xi_luru_ddlist_1_main_main_default.set_pad_right(6)
style_xin_xi_luru_ddlist_1_main_main_default.set_pad_top(8)

# add style for Xin_xi_luru_ddlist_1
Xin_xi_luru_ddlist_1.add_style(style_xin_xi_luru_ddlist_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Xin_xi_luru_ddlist_3 = lv.dropdown(Xin_xi_luru_tileview_1_tile_1)
Xin_xi_luru_ddlist_3.set_pos(int(223),int(172))
Xin_xi_luru_ddlist_3.set_size(130,30)
Xin_xi_luru_ddlist_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
Xin_xi_luru_ddlist_3.set_options("绵羊\n山羊\n黄羊\n羚羊\n青羊\n盘羊\n岩羊")

Xin_xi_luru_ddlist_3_list = Xin_xi_luru_ddlist_3.get_list()
# create style style_xin_xi_luru_ddlist_3_extra_list_selected_checked
style_xin_xi_luru_ddlist_3_extra_list_selected_checked = lv.style_t()
style_xin_xi_luru_ddlist_3_extra_list_selected_checked.init()
style_xin_xi_luru_ddlist_3_extra_list_selected_checked.set_radius(3)
style_xin_xi_luru_ddlist_3_extra_list_selected_checked.set_bg_color(lv.color_make(0x00,0xa1,0xb5))
style_xin_xi_luru_ddlist_3_extra_list_selected_checked.set_bg_grad_color(lv.color_make(0x00,0xa1,0xb5))
style_xin_xi_luru_ddlist_3_extra_list_selected_checked.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_xin_xi_luru_ddlist_3_extra_list_selected_checked.set_bg_opa(255)
style_xin_xi_luru_ddlist_3_extra_list_selected_checked.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_xin_xi_luru_ddlist_3_extra_list_selected_checked.set_border_width(1)
style_xin_xi_luru_ddlist_3_extra_list_selected_checked.set_border_opa(255)
style_xin_xi_luru_ddlist_3_extra_list_selected_checked.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_xin_xi_luru_ddlist_3_extra_list_selected_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_xin_xi_luru_ddlist_3_extra_list_selected_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_xin_xi_luru_ddlist_3_extra_list_selected_checked.set_text_font(lv.font_montserrat_16)

# add style for Xin_xi_luru_ddlist_3_list
Xin_xi_luru_ddlist_3_list.add_style(style_xin_xi_luru_ddlist_3_extra_list_selected_checked, lv.PART.SELECTED|lv.STATE.CHECKED)

# create style style_xin_xi_luru_ddlist_3_extra_list_main_default
style_xin_xi_luru_ddlist_3_extra_list_main_default = lv.style_t()
style_xin_xi_luru_ddlist_3_extra_list_main_default.init()
style_xin_xi_luru_ddlist_3_extra_list_main_default.set_radius(3)
style_xin_xi_luru_ddlist_3_extra_list_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_xin_xi_luru_ddlist_3_extra_list_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_xin_xi_luru_ddlist_3_extra_list_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_xin_xi_luru_ddlist_3_extra_list_main_default.set_bg_opa(255)
style_xin_xi_luru_ddlist_3_extra_list_main_default.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_xin_xi_luru_ddlist_3_extra_list_main_default.set_border_width(1)
style_xin_xi_luru_ddlist_3_extra_list_main_default.set_border_opa(255)
style_xin_xi_luru_ddlist_3_extra_list_main_default.set_text_color(lv.color_make(0x0D,0x30,0x55))
try:
    style_xin_xi_luru_ddlist_3_extra_list_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_xin_xi_luru_ddlist_3_extra_list_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_xin_xi_luru_ddlist_3_extra_list_main_default.set_text_font(lv.font_montserrat_16)
style_xin_xi_luru_ddlist_3_extra_list_main_default.set_max_height(90)

# add style for Xin_xi_luru_ddlist_3_list
Xin_xi_luru_ddlist_3_list.add_style(style_xin_xi_luru_ddlist_3_extra_list_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_xin_xi_luru_ddlist_3_extra_list_scrollbar_default
style_xin_xi_luru_ddlist_3_extra_list_scrollbar_default = lv.style_t()
style_xin_xi_luru_ddlist_3_extra_list_scrollbar_default.init()
style_xin_xi_luru_ddlist_3_extra_list_scrollbar_default.set_radius(3)
style_xin_xi_luru_ddlist_3_extra_list_scrollbar_default.set_bg_color(lv.color_make(0x00,0xff,0x00))
style_xin_xi_luru_ddlist_3_extra_list_scrollbar_default.set_bg_opa(255)

# add style for Xin_xi_luru_ddlist_3_list
Xin_xi_luru_ddlist_3_list.add_style(style_xin_xi_luru_ddlist_3_extra_list_scrollbar_default, lv.PART.SCROLLBAR|lv.STATE.DEFAULT)

# create style style_xin_xi_luru_ddlist_3_main_main_default
style_xin_xi_luru_ddlist_3_main_main_default = lv.style_t()
style_xin_xi_luru_ddlist_3_main_main_default.init()
style_xin_xi_luru_ddlist_3_main_main_default.set_radius(3)
style_xin_xi_luru_ddlist_3_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_xin_xi_luru_ddlist_3_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_xin_xi_luru_ddlist_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_xin_xi_luru_ddlist_3_main_main_default.set_bg_opa(255)
style_xin_xi_luru_ddlist_3_main_main_default.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_xin_xi_luru_ddlist_3_main_main_default.set_border_width(1)
style_xin_xi_luru_ddlist_3_main_main_default.set_border_opa(255)
style_xin_xi_luru_ddlist_3_main_main_default.set_text_color(lv.color_make(0x0D,0x30,0x55))
try:
    style_xin_xi_luru_ddlist_3_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_xin_xi_luru_ddlist_3_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_xin_xi_luru_ddlist_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_xin_xi_luru_ddlist_3_main_main_default.set_pad_left(6)
style_xin_xi_luru_ddlist_3_main_main_default.set_pad_right(6)
style_xin_xi_luru_ddlist_3_main_main_default.set_pad_top(8)

# add style for Xin_xi_luru_ddlist_3
Xin_xi_luru_ddlist_3.add_style(style_xin_xi_luru_ddlist_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Xin_xi_luru_ddlist_4 = lv.dropdown(Xin_xi_luru_tileview_1_tile_1)
Xin_xi_luru_ddlist_4.set_pos(int(223),int(221))
Xin_xi_luru_ddlist_4.set_size(130,30)
Xin_xi_luru_ddlist_4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
Xin_xi_luru_ddlist_4.set_options("0\n1\n2\n3\n4\n5\n6\n7")

Xin_xi_luru_ddlist_4_list = Xin_xi_luru_ddlist_4.get_list()
# create style style_xin_xi_luru_ddlist_4_extra_list_selected_checked
style_xin_xi_luru_ddlist_4_extra_list_selected_checked = lv.style_t()
style_xin_xi_luru_ddlist_4_extra_list_selected_checked.init()
style_xin_xi_luru_ddlist_4_extra_list_selected_checked.set_radius(3)
style_xin_xi_luru_ddlist_4_extra_list_selected_checked.set_bg_color(lv.color_make(0x00,0xa1,0xb5))
style_xin_xi_luru_ddlist_4_extra_list_selected_checked.set_bg_grad_color(lv.color_make(0x00,0xa1,0xb5))
style_xin_xi_luru_ddlist_4_extra_list_selected_checked.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_xin_xi_luru_ddlist_4_extra_list_selected_checked.set_bg_opa(255)
style_xin_xi_luru_ddlist_4_extra_list_selected_checked.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_xin_xi_luru_ddlist_4_extra_list_selected_checked.set_border_width(1)
style_xin_xi_luru_ddlist_4_extra_list_selected_checked.set_border_opa(255)
style_xin_xi_luru_ddlist_4_extra_list_selected_checked.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_xin_xi_luru_ddlist_4_extra_list_selected_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_xin_xi_luru_ddlist_4_extra_list_selected_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_xin_xi_luru_ddlist_4_extra_list_selected_checked.set_text_font(lv.font_montserrat_16)

# add style for Xin_xi_luru_ddlist_4_list
Xin_xi_luru_ddlist_4_list.add_style(style_xin_xi_luru_ddlist_4_extra_list_selected_checked, lv.PART.SELECTED|lv.STATE.CHECKED)

# create style style_xin_xi_luru_ddlist_4_extra_list_main_default
style_xin_xi_luru_ddlist_4_extra_list_main_default = lv.style_t()
style_xin_xi_luru_ddlist_4_extra_list_main_default.init()
style_xin_xi_luru_ddlist_4_extra_list_main_default.set_radius(3)
style_xin_xi_luru_ddlist_4_extra_list_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_xin_xi_luru_ddlist_4_extra_list_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_xin_xi_luru_ddlist_4_extra_list_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_xin_xi_luru_ddlist_4_extra_list_main_default.set_bg_opa(255)
style_xin_xi_luru_ddlist_4_extra_list_main_default.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_xin_xi_luru_ddlist_4_extra_list_main_default.set_border_width(1)
style_xin_xi_luru_ddlist_4_extra_list_main_default.set_border_opa(255)
style_xin_xi_luru_ddlist_4_extra_list_main_default.set_text_color(lv.color_make(0x0D,0x30,0x55))
try:
    style_xin_xi_luru_ddlist_4_extra_list_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_xin_xi_luru_ddlist_4_extra_list_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_xin_xi_luru_ddlist_4_extra_list_main_default.set_text_font(lv.font_montserrat_16)
style_xin_xi_luru_ddlist_4_extra_list_main_default.set_max_height(90)

# add style for Xin_xi_luru_ddlist_4_list
Xin_xi_luru_ddlist_4_list.add_style(style_xin_xi_luru_ddlist_4_extra_list_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_xin_xi_luru_ddlist_4_extra_list_scrollbar_default
style_xin_xi_luru_ddlist_4_extra_list_scrollbar_default = lv.style_t()
style_xin_xi_luru_ddlist_4_extra_list_scrollbar_default.init()
style_xin_xi_luru_ddlist_4_extra_list_scrollbar_default.set_radius(3)
style_xin_xi_luru_ddlist_4_extra_list_scrollbar_default.set_bg_color(lv.color_make(0x00,0xff,0x00))
style_xin_xi_luru_ddlist_4_extra_list_scrollbar_default.set_bg_opa(255)

# add style for Xin_xi_luru_ddlist_4_list
Xin_xi_luru_ddlist_4_list.add_style(style_xin_xi_luru_ddlist_4_extra_list_scrollbar_default, lv.PART.SCROLLBAR|lv.STATE.DEFAULT)

# create style style_xin_xi_luru_ddlist_4_main_main_default
style_xin_xi_luru_ddlist_4_main_main_default = lv.style_t()
style_xin_xi_luru_ddlist_4_main_main_default.init()
style_xin_xi_luru_ddlist_4_main_main_default.set_radius(3)
style_xin_xi_luru_ddlist_4_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_xin_xi_luru_ddlist_4_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_xin_xi_luru_ddlist_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_xin_xi_luru_ddlist_4_main_main_default.set_bg_opa(255)
style_xin_xi_luru_ddlist_4_main_main_default.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_xin_xi_luru_ddlist_4_main_main_default.set_border_width(1)
style_xin_xi_luru_ddlist_4_main_main_default.set_border_opa(255)
style_xin_xi_luru_ddlist_4_main_main_default.set_text_color(lv.color_make(0x0D,0x30,0x55))
try:
    style_xin_xi_luru_ddlist_4_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_xin_xi_luru_ddlist_4_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_xin_xi_luru_ddlist_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_xin_xi_luru_ddlist_4_main_main_default.set_pad_left(6)
style_xin_xi_luru_ddlist_4_main_main_default.set_pad_right(6)
style_xin_xi_luru_ddlist_4_main_main_default.set_pad_top(8)

# add style for Xin_xi_luru_ddlist_4
Xin_xi_luru_ddlist_4.add_style(style_xin_xi_luru_ddlist_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Xin_xi_luru_label_8 = lv.label(Xin_xi_luru_tileview_1_tile_1)
Xin_xi_luru_label_8.set_pos(int(223),int(22))
Xin_xi_luru_label_8.set_size(130,32)
Xin_xi_luru_label_8.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
Xin_xi_luru_label_8.set_text("Label")
Xin_xi_luru_label_8.set_long_mode(lv.label.LONG.WRAP)
# create style style_xin_xi_luru_label_8_main_main_default
style_xin_xi_luru_label_8_main_main_default = lv.style_t()
style_xin_xi_luru_label_8_main_main_default.init()
style_xin_xi_luru_label_8_main_main_default.set_radius(0)
style_xin_xi_luru_label_8_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_xin_xi_luru_label_8_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_xin_xi_luru_label_8_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_xin_xi_luru_label_8_main_main_default.set_bg_opa(115)
style_xin_xi_luru_label_8_main_main_default.set_text_color(lv.color_make(0x0a,0x0a,0x0a))
try:
    style_xin_xi_luru_label_8_main_main_default.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_xin_xi_luru_label_8_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_xin_xi_luru_label_8_main_main_default.set_text_font(lv.font_montserrat_16)
style_xin_xi_luru_label_8_main_main_default.set_text_letter_space(2)
style_xin_xi_luru_label_8_main_main_default.set_text_line_space(0)
style_xin_xi_luru_label_8_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_xin_xi_luru_label_8_main_main_default.set_pad_left(0)
style_xin_xi_luru_label_8_main_main_default.set_pad_right(0)
style_xin_xi_luru_label_8_main_main_default.set_pad_top(8)
style_xin_xi_luru_label_8_main_main_default.set_pad_bottom(0)

# add style for Xin_xi_luru_label_8
Xin_xi_luru_label_8.add_style(style_xin_xi_luru_label_8_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Xin_xi_luru_ta_1 = lv.textarea(Xin_xi_luru_tileview_1_tile_1)
Xin_xi_luru_ta_1.set_pos(int(222),int(115))
Xin_xi_luru_ta_1.set_size(128,35)
Xin_xi_luru_ta_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
Xin_xi_luru_ta_1.set_text("inpurt")


try:
    Xin_xi_luru_tileview_1_tile_1_kb
except NameError:
    Xin_xi_luru_tileview_1_tile_1_kb = lv.keyboard(Xin_xi_luru_tileview_1_tile_1,)

Xin_xi_luru_tileview_1_tile_1_kb.add_flag(lv.obj.FLAG.HIDDEN)
Xin_xi_luru_tileview_1_tile_1_kb.set_textarea(Xin_xi_luru_ta_1)
Xin_xi_luru_ta_1.add_event_cb(lambda e: ta_event_cb(e,Xin_xi_luru_tileview_1_tile_1_kb), lv.EVENT.ALL, None)
# create style style_xin_xi_luru_ta_1_main_main_default
style_xin_xi_luru_ta_1_main_main_default = lv.style_t()
style_xin_xi_luru_ta_1_main_main_default.init()
style_xin_xi_luru_ta_1_main_main_default.set_radius(4)
style_xin_xi_luru_ta_1_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_xin_xi_luru_ta_1_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_xin_xi_luru_ta_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_xin_xi_luru_ta_1_main_main_default.set_bg_opa(255)
style_xin_xi_luru_ta_1_main_main_default.set_border_color(lv.color_make(0xe6,0xe6,0xe6))
style_xin_xi_luru_ta_1_main_main_default.set_border_width(2)
style_xin_xi_luru_ta_1_main_main_default.set_border_opa(255)
style_xin_xi_luru_ta_1_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_xin_xi_luru_ta_1_main_main_default.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_xin_xi_luru_ta_1_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_xin_xi_luru_ta_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_xin_xi_luru_ta_1_main_main_default.set_text_letter_space(2)
style_xin_xi_luru_ta_1_main_main_default.set_text_align(lv.TEXT_ALIGN.LEFT)
style_xin_xi_luru_ta_1_main_main_default.set_pad_left(4)
style_xin_xi_luru_ta_1_main_main_default.set_pad_right(4)
style_xin_xi_luru_ta_1_main_main_default.set_pad_top(4)
style_xin_xi_luru_ta_1_main_main_default.set_pad_bottom(4)

# add style for Xin_xi_luru_ta_1
Xin_xi_luru_ta_1.add_style(style_xin_xi_luru_ta_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_xin_xi_luru_ta_1_main_scrollbar_default
style_xin_xi_luru_ta_1_main_scrollbar_default = lv.style_t()
style_xin_xi_luru_ta_1_main_scrollbar_default.init()
style_xin_xi_luru_ta_1_main_scrollbar_default.set_radius(0)
style_xin_xi_luru_ta_1_main_scrollbar_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_xin_xi_luru_ta_1_main_scrollbar_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_xin_xi_luru_ta_1_main_scrollbar_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_xin_xi_luru_ta_1_main_scrollbar_default.set_bg_opa(255)

# add style for Xin_xi_luru_ta_1
Xin_xi_luru_ta_1.add_style(style_xin_xi_luru_ta_1_main_scrollbar_default, lv.PART.SCROLLBAR|lv.STATE.DEFAULT)

# create style style_xin_xi_luru_tileview_1_main_main_default
style_xin_xi_luru_tileview_1_main_main_default = lv.style_t()
style_xin_xi_luru_tileview_1_main_main_default.init()
style_xin_xi_luru_tileview_1_main_main_default.set_radius(0)
style_xin_xi_luru_tileview_1_main_main_default.set_bg_color(lv.color_make(0xf6,0xf6,0xf6))
style_xin_xi_luru_tileview_1_main_main_default.set_bg_grad_color(lv.color_make(0xf6,0xf6,0xf6))
style_xin_xi_luru_tileview_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_xin_xi_luru_tileview_1_main_main_default.set_bg_opa(255)

# add style for Xin_xi_luru_tileview_1
Xin_xi_luru_tileview_1.add_style(style_xin_xi_luru_tileview_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_xin_xi_luru_tileview_1_main_scrollbar_default
style_xin_xi_luru_tileview_1_main_scrollbar_default = lv.style_t()
style_xin_xi_luru_tileview_1_main_scrollbar_default.init()
style_xin_xi_luru_tileview_1_main_scrollbar_default.set_radius(0)
style_xin_xi_luru_tileview_1_main_scrollbar_default.set_bg_color(lv.color_make(0xea,0xef,0xf3))
style_xin_xi_luru_tileview_1_main_scrollbar_default.set_bg_opa(255)

# add style for Xin_xi_luru_tileview_1
Xin_xi_luru_tileview_1.add_style(style_xin_xi_luru_tileview_1_main_scrollbar_default, lv.PART.SCROLLBAR|lv.STATE.DEFAULT)

Xin_xi_luru_btn_1 = lv.btn(Xin_xi_luru)
Xin_xi_luru_btn_1.set_pos(int(304),int(1))
Xin_xi_luru_btn_1.set_size(72,32)
Xin_xi_luru_btn_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
Xin_xi_luru_btn_1_label = lv.label(Xin_xi_luru_btn_1)
Xin_xi_luru_btn_1_label.set_text("取消")
Xin_xi_luru_btn_1.set_style_pad_all(0, lv.STATE.DEFAULT)
Xin_xi_luru_btn_1_label.align(lv.ALIGN.CENTER,0,0)
# create style style_xin_xi_luru_btn_1_main_main_default
style_xin_xi_luru_btn_1_main_main_default = lv.style_t()
style_xin_xi_luru_btn_1_main_main_default.init()
style_xin_xi_luru_btn_1_main_main_default.set_radius(5)
style_xin_xi_luru_btn_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_xin_xi_luru_btn_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_xin_xi_luru_btn_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_xin_xi_luru_btn_1_main_main_default.set_bg_opa(255)
style_xin_xi_luru_btn_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_xin_xi_luru_btn_1_main_main_default.set_border_width(0)
style_xin_xi_luru_btn_1_main_main_default.set_border_opa(255)
style_xin_xi_luru_btn_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_xin_xi_luru_btn_1_main_main_default.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_xin_xi_luru_btn_1_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_xin_xi_luru_btn_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_xin_xi_luru_btn_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for Xin_xi_luru_btn_1
Xin_xi_luru_btn_1.add_style(style_xin_xi_luru_btn_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Xin_xi_luru_btn_2 = lv.btn(Xin_xi_luru)
Xin_xi_luru_btn_2.set_pos(int(391),int(2))
Xin_xi_luru_btn_2.set_size(72,32)
Xin_xi_luru_btn_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
Xin_xi_luru_btn_2_label = lv.label(Xin_xi_luru_btn_2)
Xin_xi_luru_btn_2_label.set_text("确定")
Xin_xi_luru_btn_2.set_style_pad_all(0, lv.STATE.DEFAULT)
Xin_xi_luru_btn_2_label.align(lv.ALIGN.CENTER,0,0)
# create style style_xin_xi_luru_btn_2_main_main_default
style_xin_xi_luru_btn_2_main_main_default = lv.style_t()
style_xin_xi_luru_btn_2_main_main_default.init()
style_xin_xi_luru_btn_2_main_main_default.set_radius(5)
style_xin_xi_luru_btn_2_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_xin_xi_luru_btn_2_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_xin_xi_luru_btn_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_xin_xi_luru_btn_2_main_main_default.set_bg_opa(255)
style_xin_xi_luru_btn_2_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_xin_xi_luru_btn_2_main_main_default.set_border_width(0)
style_xin_xi_luru_btn_2_main_main_default.set_border_opa(255)
style_xin_xi_luru_btn_2_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_xin_xi_luru_btn_2_main_main_default.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_xin_xi_luru_btn_2_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_xin_xi_luru_btn_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_xin_xi_luru_btn_2_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for Xin_xi_luru_btn_2
Xin_xi_luru_btn_2.add_style(style_xin_xi_luru_btn_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Xin_xi_luru_imgbtn_1 = lv.imgbtn(Xin_xi_luru)
Xin_xi_luru_imgbtn_1.set_pos(int(8),int(7))
Xin_xi_luru_imgbtn_1.set_size(32,30)
Xin_xi_luru_imgbtn_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('H:\\lv\\lvgl_s\\generated\\mPythonImages\\mp-1220964561.png','rb') as f:
        Xin_xi_luru_imgbtn_1_imgReleased_data = f.read()
except:
    print('Could not open H:\\lv\\lvgl_s\\generated\\mPythonImages\\mp-1220964561.png')
    sys.exit()

Xin_xi_luru_imgbtn_1_imgReleased = lv.img_dsc_t({
  'data_size': len(Xin_xi_luru_imgbtn_1_imgReleased_data),
  'header': {'always_zero': 0, 'w': 32, 'h': 30, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': Xin_xi_luru_imgbtn_1_imgReleased_data
})
Xin_xi_luru_imgbtn_1.set_src(lv.imgbtn.STATE.RELEASED, None, Xin_xi_luru_imgbtn_1_imgReleased, None)





Xin_xi_luru_imgbtn_1.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_xin_xi_luru_imgbtn_1_main_main_default
style_xin_xi_luru_imgbtn_1_main_main_default = lv.style_t()
style_xin_xi_luru_imgbtn_1_main_main_default.init()
style_xin_xi_luru_imgbtn_1_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_xin_xi_luru_imgbtn_1_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_xin_xi_luru_imgbtn_1_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_xin_xi_luru_imgbtn_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_xin_xi_luru_imgbtn_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_xin_xi_luru_imgbtn_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_xin_xi_luru_imgbtn_1_main_main_default.set_img_recolor_opa(0)
style_xin_xi_luru_imgbtn_1_main_main_default.set_img_opa(255)

# add style for Xin_xi_luru_imgbtn_1
Xin_xi_luru_imgbtn_1.add_style(style_xin_xi_luru_imgbtn_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_xin_xi_luru_imgbtn_1_main_main_pressed
style_xin_xi_luru_imgbtn_1_main_main_pressed = lv.style_t()
style_xin_xi_luru_imgbtn_1_main_main_pressed.init()
style_xin_xi_luru_imgbtn_1_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_xin_xi_luru_imgbtn_1_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_xin_xi_luru_imgbtn_1_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_xin_xi_luru_imgbtn_1_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_xin_xi_luru_imgbtn_1_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_xin_xi_luru_imgbtn_1_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_xin_xi_luru_imgbtn_1_main_main_pressed.set_img_recolor_opa(0)
style_xin_xi_luru_imgbtn_1_main_main_pressed.set_img_opa(255)

# add style for Xin_xi_luru_imgbtn_1
Xin_xi_luru_imgbtn_1.add_style(style_xin_xi_luru_imgbtn_1_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_xin_xi_luru_imgbtn_1_main_main_checked
style_xin_xi_luru_imgbtn_1_main_main_checked = lv.style_t()
style_xin_xi_luru_imgbtn_1_main_main_checked.init()
style_xin_xi_luru_imgbtn_1_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_xin_xi_luru_imgbtn_1_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_xin_xi_luru_imgbtn_1_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_xin_xi_luru_imgbtn_1_main_main_checked.set_text_font(lv.font_montserrat_16)
style_xin_xi_luru_imgbtn_1_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_xin_xi_luru_imgbtn_1_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_xin_xi_luru_imgbtn_1_main_main_checked.set_img_recolor_opa(0)
style_xin_xi_luru_imgbtn_1_main_main_checked.set_img_opa(255)

# add style for Xin_xi_luru_imgbtn_1
Xin_xi_luru_imgbtn_1.add_style(style_xin_xi_luru_imgbtn_1_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

screen_1 = lv.obj()
screen_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_screen_1_main_main_default
style_screen_1_main_main_default = lv.style_t()
style_screen_1_main_main_default.init()
style_screen_1_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_screen_1_main_main_default.set_bg_opa(0)

# add style for screen_1
screen_1.add_style(style_screen_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_1_table_1 = lv.table(screen_1)
screen_1_table_1.set_pos(int(74),int(72))
screen_1_table_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_1_table_1.set_col_cnt(2)
screen_1_table_1.set_row_cnt(4)
screen_1_table_1.set_cell_value(0, 0, "Name")
screen_1_table_1.set_cell_value(0+1, 0, "Apple")
screen_1_table_1.set_cell_value(1+1, 0, "Banana")
screen_1_table_1.set_cell_value(2+1, 0, "Citron")
screen_1_table_1.set_cell_value(0, 1, "Price")
screen_1_table_1.set_cell_value(0+1, 1, "$1")
screen_1_table_1.set_cell_value(1+1, 1, "$2")
screen_1_table_1.set_cell_value(2+1, 1, "$3")
screen_1_table_1.set_style_pad_left(10, lv.PART.ITEMS | lv.STATE.DEFAULT)
screen_1_table_1.set_style_pad_right(10, lv.PART.ITEMS | lv.STATE.DEFAULT)
screen_1_table_1.set_style_pad_top(10, lv.PART.ITEMS | lv.STATE.DEFAULT)
screen_1_table_1.set_style_pad_bottom(10, lv.PART.ITEMS | lv.STATE.DEFAULT)
# create style style_screen_1_table_1_main_main_default
style_screen_1_table_1_main_main_default = lv.style_t()
style_screen_1_table_1_main_main_default.init()
style_screen_1_table_1_main_main_default.set_radius(0)
style_screen_1_table_1_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_screen_1_table_1_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_screen_1_table_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_screen_1_table_1_main_main_default.set_bg_opa(255)
style_screen_1_table_1_main_main_default.set_border_color(lv.color_make(0xd5,0xde,0xe6))
style_screen_1_table_1_main_main_default.set_border_width(2)
style_screen_1_table_1_main_main_default.set_border_opa(255)
style_screen_1_table_1_main_main_default.set_pad_left(0)
style_screen_1_table_1_main_main_default.set_pad_right(0)
style_screen_1_table_1_main_main_default.set_pad_top(0)
style_screen_1_table_1_main_main_default.set_pad_bottom(0)

# add style for screen_1_table_1
screen_1_table_1.add_style(style_screen_1_table_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_screen_1_table_1_main_items_default
style_screen_1_table_1_main_items_default = lv.style_t()
style_screen_1_table_1_main_items_default.init()
style_screen_1_table_1_main_items_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_screen_1_table_1_main_items_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_screen_1_table_1_main_items_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_screen_1_table_1_main_items_default.set_bg_opa(0)
style_screen_1_table_1_main_items_default.set_border_color(lv.color_make(0xd5,0xde,0xe6))
style_screen_1_table_1_main_items_default.set_border_width(3)
style_screen_1_table_1_main_items_default.set_border_opa(255)
style_screen_1_table_1_main_items_default.set_text_color(lv.color_make(0x39,0x3c,0x41))
try:
    style_screen_1_table_1_main_items_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_screen_1_table_1_main_items_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_screen_1_table_1_main_items_default.set_text_font(lv.font_montserrat_16)
style_screen_1_table_1_main_items_default.set_text_decor(lv.TEXT_DECOR.NONE)

# add style for screen_1_table_1
screen_1_table_1.add_style(style_screen_1_table_1_main_items_default, lv.PART.ITEMS|lv.STATE.DEFAULT)

screen_1_ta_1 = lv.textarea(screen_1)
screen_1_ta_1.set_pos(int(74),int(224))
screen_1_ta_1.set_size(200,60)
screen_1_ta_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_1_ta_1.set_text("Hello World")


try:
    screen_1_kb
except NameError:
    screen_1_kb = lv.keyboard(screen_1,)

screen_1_kb.add_flag(lv.obj.FLAG.HIDDEN)
screen_1_kb.set_textarea(screen_1_ta_1)
screen_1_ta_1.add_event_cb(lambda e: ta_event_cb(e,screen_1_kb), lv.EVENT.ALL, None)
# create style style_screen_1_ta_1_main_main_default
style_screen_1_ta_1_main_main_default = lv.style_t()
style_screen_1_ta_1_main_main_default.init()
style_screen_1_ta_1_main_main_default.set_radius(4)
style_screen_1_ta_1_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_screen_1_ta_1_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_screen_1_ta_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_screen_1_ta_1_main_main_default.set_bg_opa(255)
style_screen_1_ta_1_main_main_default.set_border_color(lv.color_make(0xe6,0xe6,0xe6))
style_screen_1_ta_1_main_main_default.set_border_width(2)
style_screen_1_ta_1_main_main_default.set_border_opa(255)
style_screen_1_ta_1_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_screen_1_ta_1_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_screen_1_ta_1_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_screen_1_ta_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_1_ta_1_main_main_default.set_text_letter_space(2)
style_screen_1_ta_1_main_main_default.set_text_align(lv.TEXT_ALIGN.LEFT)
style_screen_1_ta_1_main_main_default.set_pad_left(4)
style_screen_1_ta_1_main_main_default.set_pad_right(4)
style_screen_1_ta_1_main_main_default.set_pad_top(4)
style_screen_1_ta_1_main_main_default.set_pad_bottom(4)

# add style for screen_1_ta_1
screen_1_ta_1.add_style(style_screen_1_ta_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_screen_1_ta_1_main_scrollbar_default
style_screen_1_ta_1_main_scrollbar_default = lv.style_t()
style_screen_1_ta_1_main_scrollbar_default.init()
style_screen_1_ta_1_main_scrollbar_default.set_radius(0)
style_screen_1_ta_1_main_scrollbar_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_1_ta_1_main_scrollbar_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_1_ta_1_main_scrollbar_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_screen_1_ta_1_main_scrollbar_default.set_bg_opa(255)

# add style for screen_1_ta_1
screen_1_ta_1.add_style(style_screen_1_ta_1_main_scrollbar_default, lv.PART.SCROLLBAR|lv.STATE.DEFAULT)

Ear_management = lv.obj()
Ear_management.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_ear_management_main_main_default
style_ear_management_main_main_default = lv.style_t()
style_ear_management_main_main_default.init()
style_ear_management_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_ear_management_main_main_default.set_bg_opa(0)

# add style for Ear_management
Ear_management.add_style(style_ear_management_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Ear_management_imgbtn_1 = lv.imgbtn(Ear_management)
Ear_management_imgbtn_1.set_pos(int(6),int(7))
Ear_management_imgbtn_1.set_size(36,32)
Ear_management_imgbtn_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('H:\\lv\\lvgl_s\\generated\\mPythonImages\\mp-1892232651.png','rb') as f:
        Ear_management_imgbtn_1_imgReleased_data = f.read()
except:
    print('Could not open H:\\lv\\lvgl_s\\generated\\mPythonImages\\mp-1892232651.png')
    sys.exit()

Ear_management_imgbtn_1_imgReleased = lv.img_dsc_t({
  'data_size': len(Ear_management_imgbtn_1_imgReleased_data),
  'header': {'always_zero': 0, 'w': 36, 'h': 32, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': Ear_management_imgbtn_1_imgReleased_data
})
Ear_management_imgbtn_1.set_src(lv.imgbtn.STATE.RELEASED, None, Ear_management_imgbtn_1_imgReleased, None)





Ear_management_imgbtn_1.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_ear_management_imgbtn_1_main_main_default
style_ear_management_imgbtn_1_main_main_default = lv.style_t()
style_ear_management_imgbtn_1_main_main_default.init()
style_ear_management_imgbtn_1_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_ear_management_imgbtn_1_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_ear_management_imgbtn_1_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_ear_management_imgbtn_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_ear_management_imgbtn_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_ear_management_imgbtn_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_ear_management_imgbtn_1_main_main_default.set_img_recolor_opa(0)
style_ear_management_imgbtn_1_main_main_default.set_img_opa(255)

# add style for Ear_management_imgbtn_1
Ear_management_imgbtn_1.add_style(style_ear_management_imgbtn_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_ear_management_imgbtn_1_main_main_pressed
style_ear_management_imgbtn_1_main_main_pressed = lv.style_t()
style_ear_management_imgbtn_1_main_main_pressed.init()
style_ear_management_imgbtn_1_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_ear_management_imgbtn_1_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_ear_management_imgbtn_1_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_ear_management_imgbtn_1_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_ear_management_imgbtn_1_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_ear_management_imgbtn_1_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_ear_management_imgbtn_1_main_main_pressed.set_img_recolor_opa(0)
style_ear_management_imgbtn_1_main_main_pressed.set_img_opa(255)

# add style for Ear_management_imgbtn_1
Ear_management_imgbtn_1.add_style(style_ear_management_imgbtn_1_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_ear_management_imgbtn_1_main_main_checked
style_ear_management_imgbtn_1_main_main_checked = lv.style_t()
style_ear_management_imgbtn_1_main_main_checked.init()
style_ear_management_imgbtn_1_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_ear_management_imgbtn_1_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_ear_management_imgbtn_1_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_ear_management_imgbtn_1_main_main_checked.set_text_font(lv.font_montserrat_16)
style_ear_management_imgbtn_1_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_ear_management_imgbtn_1_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_ear_management_imgbtn_1_main_main_checked.set_img_recolor_opa(0)
style_ear_management_imgbtn_1_main_main_checked.set_img_opa(255)

# add style for Ear_management_imgbtn_1
Ear_management_imgbtn_1.add_style(style_ear_management_imgbtn_1_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

Ear_management_btn_1 = lv.btn(Ear_management)
Ear_management_btn_1.set_pos(int(78),int(90))
Ear_management_btn_1.set_size(120,60)
Ear_management_btn_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
Ear_management_btn_1_label = lv.label(Ear_management_btn_1)
Ear_management_btn_1_label.set_text("疫苗接种")
Ear_management_btn_1.set_style_pad_all(0, lv.STATE.DEFAULT)
Ear_management_btn_1_label.align(lv.ALIGN.CENTER,0,0)
# create style style_ear_management_btn_1_main_main_default
style_ear_management_btn_1_main_main_default = lv.style_t()
style_ear_management_btn_1_main_main_default.init()
style_ear_management_btn_1_main_main_default.set_radius(5)
style_ear_management_btn_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_ear_management_btn_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ear_management_btn_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ear_management_btn_1_main_main_default.set_bg_opa(255)
style_ear_management_btn_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_ear_management_btn_1_main_main_default.set_border_width(0)
style_ear_management_btn_1_main_main_default.set_border_opa(255)
style_ear_management_btn_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_ear_management_btn_1_main_main_default.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_ear_management_btn_1_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_ear_management_btn_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_ear_management_btn_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for Ear_management_btn_1
Ear_management_btn_1.add_style(style_ear_management_btn_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Ear_management_btn_2 = lv.btn(Ear_management)
Ear_management_btn_2.set_pos(int(260),int(90))
Ear_management_btn_2.set_size(120,60)
Ear_management_btn_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
Ear_management_btn_2_label = lv.label(Ear_management_btn_2)
Ear_management_btn_2_label.set_text("信息查询")
Ear_management_btn_2.set_style_pad_all(0, lv.STATE.DEFAULT)
Ear_management_btn_2_label.align(lv.ALIGN.CENTER,0,0)
# create style style_ear_management_btn_2_main_main_default
style_ear_management_btn_2_main_main_default = lv.style_t()
style_ear_management_btn_2_main_main_default.init()
style_ear_management_btn_2_main_main_default.set_radius(5)
style_ear_management_btn_2_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_ear_management_btn_2_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ear_management_btn_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ear_management_btn_2_main_main_default.set_bg_opa(255)
style_ear_management_btn_2_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_ear_management_btn_2_main_main_default.set_border_width(0)
style_ear_management_btn_2_main_main_default.set_border_opa(255)
style_ear_management_btn_2_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_ear_management_btn_2_main_main_default.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_ear_management_btn_2_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_ear_management_btn_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_ear_management_btn_2_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for Ear_management_btn_2
Ear_management_btn_2.add_style(style_ear_management_btn_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Ear_management_btn_3 = lv.btn(Ear_management)
Ear_management_btn_3.set_pos(int(78),int(173))
Ear_management_btn_3.set_size(120,60)
Ear_management_btn_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
Ear_management_btn_3_label = lv.label(Ear_management_btn_3)
Ear_management_btn_3_label.set_text("Button")
Ear_management_btn_3.set_style_pad_all(0, lv.STATE.DEFAULT)
Ear_management_btn_3_label.align(lv.ALIGN.CENTER,0,0)
# create style style_ear_management_btn_3_main_main_default
style_ear_management_btn_3_main_main_default = lv.style_t()
style_ear_management_btn_3_main_main_default.init()
style_ear_management_btn_3_main_main_default.set_radius(5)
style_ear_management_btn_3_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_ear_management_btn_3_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ear_management_btn_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ear_management_btn_3_main_main_default.set_bg_opa(255)
style_ear_management_btn_3_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_ear_management_btn_3_main_main_default.set_border_width(0)
style_ear_management_btn_3_main_main_default.set_border_opa(255)
style_ear_management_btn_3_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_ear_management_btn_3_main_main_default.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_ear_management_btn_3_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_ear_management_btn_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_ear_management_btn_3_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for Ear_management_btn_3
Ear_management_btn_3.add_style(style_ear_management_btn_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Ear_management_btn_4 = lv.btn(Ear_management)
Ear_management_btn_4.set_pos(int(260),int(173))
Ear_management_btn_4.set_size(120,60)
Ear_management_btn_4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
Ear_management_btn_4_label = lv.label(Ear_management_btn_4)
Ear_management_btn_4_label.set_text("Button")
Ear_management_btn_4.set_style_pad_all(0, lv.STATE.DEFAULT)
Ear_management_btn_4_label.align(lv.ALIGN.CENTER,0,0)
# create style style_ear_management_btn_4_main_main_default
style_ear_management_btn_4_main_main_default = lv.style_t()
style_ear_management_btn_4_main_main_default.init()
style_ear_management_btn_4_main_main_default.set_radius(5)
style_ear_management_btn_4_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_ear_management_btn_4_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ear_management_btn_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ear_management_btn_4_main_main_default.set_bg_opa(255)
style_ear_management_btn_4_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_ear_management_btn_4_main_main_default.set_border_width(0)
style_ear_management_btn_4_main_main_default.set_border_opa(255)
style_ear_management_btn_4_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_ear_management_btn_4_main_main_default.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_ear_management_btn_4_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_ear_management_btn_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_ear_management_btn_4_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for Ear_management_btn_4
Ear_management_btn_4.add_style(style_ear_management_btn_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

yimiao = lv.obj()
yimiao.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_yimiao_main_main_default
style_yimiao_main_main_default = lv.style_t()
style_yimiao_main_main_default.init()
style_yimiao_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_yimiao_main_main_default.set_bg_opa(0)

# add style for yimiao
yimiao.add_style(style_yimiao_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

yimiao_imgbtn_1 = lv.imgbtn(yimiao)
yimiao_imgbtn_1.set_pos(int(0),int(5))
yimiao_imgbtn_1.set_size(45,33)
yimiao_imgbtn_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('H:\\lv\\lvgl_s\\generated\\mPythonImages\\mp-103275308.png','rb') as f:
        yimiao_imgbtn_1_imgReleased_data = f.read()
except:
    print('Could not open H:\\lv\\lvgl_s\\generated\\mPythonImages\\mp-103275308.png')
    sys.exit()

yimiao_imgbtn_1_imgReleased = lv.img_dsc_t({
  'data_size': len(yimiao_imgbtn_1_imgReleased_data),
  'header': {'always_zero': 0, 'w': 45, 'h': 33, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': yimiao_imgbtn_1_imgReleased_data
})
yimiao_imgbtn_1.set_src(lv.imgbtn.STATE.RELEASED, None, yimiao_imgbtn_1_imgReleased, None)

try:
    with open('H:\\lv\\lvgl_s\\generated\\mPythonImages\\mp-103275308.png','rb') as f:
        yimiao_imgbtn_1_imgPressed_data = f.read()
except:
    print('Could not open H:\\lv\\lvgl_s\\generated\\mPythonImages\\mp-103275308.png')
    sys.exit()

yimiao_imgbtn_1_imgPressed = lv.img_dsc_t({
  'data_size': len(yimiao_imgbtn_1_imgPressed_data),
  'header': {'always_zero': 0, 'w': 45, 'h': 33, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': yimiao_imgbtn_1_imgPressed_data
})
yimiao_imgbtn_1.set_src(lv.imgbtn.STATE.PRESSED, None, yimiao_imgbtn_1_imgPressed, None)




yimiao_imgbtn_1.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_yimiao_imgbtn_1_main_main_default
style_yimiao_imgbtn_1_main_main_default = lv.style_t()
style_yimiao_imgbtn_1_main_main_default.init()
style_yimiao_imgbtn_1_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_yimiao_imgbtn_1_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_yimiao_imgbtn_1_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_yimiao_imgbtn_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_yimiao_imgbtn_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_yimiao_imgbtn_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_yimiao_imgbtn_1_main_main_default.set_img_recolor_opa(0)
style_yimiao_imgbtn_1_main_main_default.set_img_opa(255)

# add style for yimiao_imgbtn_1
yimiao_imgbtn_1.add_style(style_yimiao_imgbtn_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_yimiao_imgbtn_1_main_main_pressed
style_yimiao_imgbtn_1_main_main_pressed = lv.style_t()
style_yimiao_imgbtn_1_main_main_pressed.init()
style_yimiao_imgbtn_1_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_yimiao_imgbtn_1_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_yimiao_imgbtn_1_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_yimiao_imgbtn_1_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_yimiao_imgbtn_1_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_yimiao_imgbtn_1_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_yimiao_imgbtn_1_main_main_pressed.set_img_recolor_opa(0)
style_yimiao_imgbtn_1_main_main_pressed.set_img_opa(255)

# add style for yimiao_imgbtn_1
yimiao_imgbtn_1.add_style(style_yimiao_imgbtn_1_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_yimiao_imgbtn_1_main_main_checked
style_yimiao_imgbtn_1_main_main_checked = lv.style_t()
style_yimiao_imgbtn_1_main_main_checked.init()
style_yimiao_imgbtn_1_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_yimiao_imgbtn_1_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_yimiao_imgbtn_1_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_yimiao_imgbtn_1_main_main_checked.set_text_font(lv.font_montserrat_16)
style_yimiao_imgbtn_1_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_yimiao_imgbtn_1_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_yimiao_imgbtn_1_main_main_checked.set_img_recolor_opa(0)
style_yimiao_imgbtn_1_main_main_checked.set_img_opa(255)

# add style for yimiao_imgbtn_1
yimiao_imgbtn_1.add_style(style_yimiao_imgbtn_1_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

yimiao_label_1 = lv.label(yimiao)
yimiao_label_1.set_pos(int(59),int(6))
yimiao_label_1.set_size(163,32)
yimiao_label_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
yimiao_label_1.set_text("疫苗接种记录管理")
yimiao_label_1.set_long_mode(lv.label.LONG.WRAP)
# create style style_yimiao_label_1_main_main_default
style_yimiao_label_1_main_main_default = lv.style_t()
style_yimiao_label_1_main_main_default.init()
style_yimiao_label_1_main_main_default.set_radius(0)
style_yimiao_label_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_yimiao_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_yimiao_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_yimiao_label_1_main_main_default.set_bg_opa(255)
style_yimiao_label_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_yimiao_label_1_main_main_default.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_yimiao_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_yimiao_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_yimiao_label_1_main_main_default.set_text_letter_space(2)
style_yimiao_label_1_main_main_default.set_text_line_space(0)
style_yimiao_label_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_yimiao_label_1_main_main_default.set_pad_left(0)
style_yimiao_label_1_main_main_default.set_pad_right(0)
style_yimiao_label_1_main_main_default.set_pad_top(8)
style_yimiao_label_1_main_main_default.set_pad_bottom(0)

# add style for yimiao_label_1
yimiao_label_1.add_style(style_yimiao_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

yimiao_cont_1 = lv.obj(yimiao)
yimiao_cont_1.set_pos(int(7),int(48))
yimiao_cont_1.set_size(466,263)
yimiao_cont_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
yimiao_cb_1 = lv.checkbox(yimiao_cont_1)
yimiao_cb_1.set_pos(int(16),int(12))
yimiao_cb_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
yimiao_cb_1.set_text("羊四联苗")
# create style style_yimiao_cb_1_main_main_default
style_yimiao_cb_1_main_main_default = lv.style_t()
style_yimiao_cb_1_main_main_default.init()
style_yimiao_cb_1_main_main_default.set_radius(6)
style_yimiao_cb_1_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_yimiao_cb_1_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_yimiao_cb_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_yimiao_cb_1_main_main_default.set_bg_opa(255)
style_yimiao_cb_1_main_main_default.set_text_color(lv.color_make(0x0D,0x30,0x55))
try:
    style_yimiao_cb_1_main_main_default.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_yimiao_cb_1_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_yimiao_cb_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_yimiao_cb_1_main_main_default.set_text_letter_space(2)

# add style for yimiao_cb_1
yimiao_cb_1.add_style(style_yimiao_cb_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_yimiao_cb_1_main_indicator_default
style_yimiao_cb_1_main_indicator_default = lv.style_t()
style_yimiao_cb_1_main_indicator_default.init()
style_yimiao_cb_1_main_indicator_default.set_radius(6)
style_yimiao_cb_1_main_indicator_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_yimiao_cb_1_main_indicator_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_yimiao_cb_1_main_indicator_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_yimiao_cb_1_main_indicator_default.set_bg_opa(255)
style_yimiao_cb_1_main_indicator_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_yimiao_cb_1_main_indicator_default.set_border_width(2)
style_yimiao_cb_1_main_indicator_default.set_border_opa(255)

# add style for yimiao_cb_1
yimiao_cb_1.add_style(style_yimiao_cb_1_main_indicator_default, lv.PART.INDICATOR|lv.STATE.DEFAULT)

yimiao_cb_2 = lv.checkbox(yimiao_cont_1)
yimiao_cb_2.set_pos(int(16),int(46))
yimiao_cb_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
yimiao_cb_2.set_text("羊五联苗")
# create style style_yimiao_cb_2_main_main_default
style_yimiao_cb_2_main_main_default = lv.style_t()
style_yimiao_cb_2_main_main_default.init()
style_yimiao_cb_2_main_main_default.set_radius(6)
style_yimiao_cb_2_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_yimiao_cb_2_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_yimiao_cb_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_yimiao_cb_2_main_main_default.set_bg_opa(255)
style_yimiao_cb_2_main_main_default.set_text_color(lv.color_make(0x0D,0x30,0x55))
try:
    style_yimiao_cb_2_main_main_default.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_yimiao_cb_2_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_yimiao_cb_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_yimiao_cb_2_main_main_default.set_text_letter_space(2)

# add style for yimiao_cb_2
yimiao_cb_2.add_style(style_yimiao_cb_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_yimiao_cb_2_main_indicator_default
style_yimiao_cb_2_main_indicator_default = lv.style_t()
style_yimiao_cb_2_main_indicator_default.init()
style_yimiao_cb_2_main_indicator_default.set_radius(6)
style_yimiao_cb_2_main_indicator_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_yimiao_cb_2_main_indicator_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_yimiao_cb_2_main_indicator_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_yimiao_cb_2_main_indicator_default.set_bg_opa(255)
style_yimiao_cb_2_main_indicator_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_yimiao_cb_2_main_indicator_default.set_border_width(2)
style_yimiao_cb_2_main_indicator_default.set_border_opa(255)

# add style for yimiao_cb_2
yimiao_cb_2.add_style(style_yimiao_cb_2_main_indicator_default, lv.PART.INDICATOR|lv.STATE.DEFAULT)

yimiao_cb_3 = lv.checkbox(yimiao_cont_1)
yimiao_cb_3.set_pos(int(16),int(85))
yimiao_cb_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
yimiao_cb_3.set_text("破伤风类毒素")
# create style style_yimiao_cb_3_main_main_default
style_yimiao_cb_3_main_main_default = lv.style_t()
style_yimiao_cb_3_main_main_default.init()
style_yimiao_cb_3_main_main_default.set_radius(6)
style_yimiao_cb_3_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_yimiao_cb_3_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_yimiao_cb_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_yimiao_cb_3_main_main_default.set_bg_opa(255)
style_yimiao_cb_3_main_main_default.set_text_color(lv.color_make(0x0D,0x30,0x55))
try:
    style_yimiao_cb_3_main_main_default.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_yimiao_cb_3_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_yimiao_cb_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_yimiao_cb_3_main_main_default.set_text_letter_space(2)

# add style for yimiao_cb_3
yimiao_cb_3.add_style(style_yimiao_cb_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_yimiao_cb_3_main_indicator_default
style_yimiao_cb_3_main_indicator_default = lv.style_t()
style_yimiao_cb_3_main_indicator_default.init()
style_yimiao_cb_3_main_indicator_default.set_radius(6)
style_yimiao_cb_3_main_indicator_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_yimiao_cb_3_main_indicator_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_yimiao_cb_3_main_indicator_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_yimiao_cb_3_main_indicator_default.set_bg_opa(255)
style_yimiao_cb_3_main_indicator_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_yimiao_cb_3_main_indicator_default.set_border_width(2)
style_yimiao_cb_3_main_indicator_default.set_border_opa(255)

# add style for yimiao_cb_3
yimiao_cb_3.add_style(style_yimiao_cb_3_main_indicator_default, lv.PART.INDICATOR|lv.STATE.DEFAULT)

yimiao_cb_4 = lv.checkbox(yimiao_cont_1)
yimiao_cb_4.set_pos(int(16),int(127))
yimiao_cb_4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
yimiao_cb_4.set_text("第Ⅱ号炭疽菌苗")
# create style style_yimiao_cb_4_main_main_default
style_yimiao_cb_4_main_main_default = lv.style_t()
style_yimiao_cb_4_main_main_default.init()
style_yimiao_cb_4_main_main_default.set_radius(6)
style_yimiao_cb_4_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_yimiao_cb_4_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_yimiao_cb_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_yimiao_cb_4_main_main_default.set_bg_opa(255)
style_yimiao_cb_4_main_main_default.set_text_color(lv.color_make(0x0D,0x30,0x55))
try:
    style_yimiao_cb_4_main_main_default.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_yimiao_cb_4_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_yimiao_cb_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_yimiao_cb_4_main_main_default.set_text_letter_space(2)

# add style for yimiao_cb_4
yimiao_cb_4.add_style(style_yimiao_cb_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_yimiao_cb_4_main_indicator_default
style_yimiao_cb_4_main_indicator_default = lv.style_t()
style_yimiao_cb_4_main_indicator_default.init()
style_yimiao_cb_4_main_indicator_default.set_radius(6)
style_yimiao_cb_4_main_indicator_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_yimiao_cb_4_main_indicator_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_yimiao_cb_4_main_indicator_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_yimiao_cb_4_main_indicator_default.set_bg_opa(255)
style_yimiao_cb_4_main_indicator_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_yimiao_cb_4_main_indicator_default.set_border_width(2)
style_yimiao_cb_4_main_indicator_default.set_border_opa(255)

# add style for yimiao_cb_4
yimiao_cb_4.add_style(style_yimiao_cb_4_main_indicator_default, lv.PART.INDICATOR|lv.STATE.DEFAULT)

yimiao_cb_5 = lv.checkbox(yimiao_cont_1)
yimiao_cb_5.set_pos(int(16),int(168))
yimiao_cb_5.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
yimiao_cb_5.set_text("羔羊大肠杆菌疫苗")
# create style style_yimiao_cb_5_main_main_default
style_yimiao_cb_5_main_main_default = lv.style_t()
style_yimiao_cb_5_main_main_default.init()
style_yimiao_cb_5_main_main_default.set_radius(6)
style_yimiao_cb_5_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_yimiao_cb_5_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_yimiao_cb_5_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_yimiao_cb_5_main_main_default.set_bg_opa(255)
style_yimiao_cb_5_main_main_default.set_text_color(lv.color_make(0x0D,0x30,0x55))
try:
    style_yimiao_cb_5_main_main_default.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_yimiao_cb_5_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_yimiao_cb_5_main_main_default.set_text_font(lv.font_montserrat_16)
style_yimiao_cb_5_main_main_default.set_text_letter_space(2)

# add style for yimiao_cb_5
yimiao_cb_5.add_style(style_yimiao_cb_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_yimiao_cb_5_main_indicator_default
style_yimiao_cb_5_main_indicator_default = lv.style_t()
style_yimiao_cb_5_main_indicator_default.init()
style_yimiao_cb_5_main_indicator_default.set_radius(6)
style_yimiao_cb_5_main_indicator_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_yimiao_cb_5_main_indicator_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_yimiao_cb_5_main_indicator_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_yimiao_cb_5_main_indicator_default.set_bg_opa(255)
style_yimiao_cb_5_main_indicator_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_yimiao_cb_5_main_indicator_default.set_border_width(2)
style_yimiao_cb_5_main_indicator_default.set_border_opa(255)

# add style for yimiao_cb_5
yimiao_cb_5.add_style(style_yimiao_cb_5_main_indicator_default, lv.PART.INDICATOR|lv.STATE.DEFAULT)

yimiao_cb_6 = lv.checkbox(yimiao_cont_1)
yimiao_cb_6.set_pos(int(17),int(206))
yimiao_cb_6.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
yimiao_cb_6.set_text("口疮弱毒细胞冻干苗")
# create style style_yimiao_cb_6_main_main_default
style_yimiao_cb_6_main_main_default = lv.style_t()
style_yimiao_cb_6_main_main_default.init()
style_yimiao_cb_6_main_main_default.set_radius(6)
style_yimiao_cb_6_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_yimiao_cb_6_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_yimiao_cb_6_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_yimiao_cb_6_main_main_default.set_bg_opa(255)
style_yimiao_cb_6_main_main_default.set_text_color(lv.color_make(0x0D,0x30,0x55))
try:
    style_yimiao_cb_6_main_main_default.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_yimiao_cb_6_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_yimiao_cb_6_main_main_default.set_text_font(lv.font_montserrat_16)
style_yimiao_cb_6_main_main_default.set_text_letter_space(2)

# add style for yimiao_cb_6
yimiao_cb_6.add_style(style_yimiao_cb_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_yimiao_cb_6_main_indicator_default
style_yimiao_cb_6_main_indicator_default = lv.style_t()
style_yimiao_cb_6_main_indicator_default.init()
style_yimiao_cb_6_main_indicator_default.set_radius(6)
style_yimiao_cb_6_main_indicator_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_yimiao_cb_6_main_indicator_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_yimiao_cb_6_main_indicator_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_yimiao_cb_6_main_indicator_default.set_bg_opa(255)
style_yimiao_cb_6_main_indicator_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_yimiao_cb_6_main_indicator_default.set_border_width(2)
style_yimiao_cb_6_main_indicator_default.set_border_opa(255)

# add style for yimiao_cb_6
yimiao_cb_6.add_style(style_yimiao_cb_6_main_indicator_default, lv.PART.INDICATOR|lv.STATE.DEFAULT)

yimiao_cb_7 = lv.checkbox(yimiao_cont_1)
yimiao_cb_7.set_pos(int(247),int(4))
yimiao_cb_7.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
yimiao_cb_7.set_text("羊链球菌氢氧化铝菌苗")
# create style style_yimiao_cb_7_main_main_default
style_yimiao_cb_7_main_main_default = lv.style_t()
style_yimiao_cb_7_main_main_default.init()
style_yimiao_cb_7_main_main_default.set_radius(6)
style_yimiao_cb_7_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_yimiao_cb_7_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_yimiao_cb_7_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_yimiao_cb_7_main_main_default.set_bg_opa(255)
style_yimiao_cb_7_main_main_default.set_text_color(lv.color_make(0x0D,0x30,0x55))
try:
    style_yimiao_cb_7_main_main_default.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_yimiao_cb_7_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_yimiao_cb_7_main_main_default.set_text_font(lv.font_montserrat_16)
style_yimiao_cb_7_main_main_default.set_text_letter_space(2)

# add style for yimiao_cb_7
yimiao_cb_7.add_style(style_yimiao_cb_7_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_yimiao_cb_7_main_indicator_default
style_yimiao_cb_7_main_indicator_default = lv.style_t()
style_yimiao_cb_7_main_indicator_default.init()
style_yimiao_cb_7_main_indicator_default.set_radius(6)
style_yimiao_cb_7_main_indicator_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_yimiao_cb_7_main_indicator_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_yimiao_cb_7_main_indicator_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_yimiao_cb_7_main_indicator_default.set_bg_opa(255)
style_yimiao_cb_7_main_indicator_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_yimiao_cb_7_main_indicator_default.set_border_width(2)
style_yimiao_cb_7_main_indicator_default.set_border_opa(255)

# add style for yimiao_cb_7
yimiao_cb_7.add_style(style_yimiao_cb_7_main_indicator_default, lv.PART.INDICATOR|lv.STATE.DEFAULT)

yimiao_cb_8 = lv.checkbox(yimiao_cont_1)
yimiao_cb_8.set_pos(int(247),int(39))
yimiao_cb_8.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
yimiao_cb_8.set_text("羊黑疫菌苗")
# create style style_yimiao_cb_8_main_main_default
style_yimiao_cb_8_main_main_default = lv.style_t()
style_yimiao_cb_8_main_main_default.init()
style_yimiao_cb_8_main_main_default.set_radius(6)
style_yimiao_cb_8_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_yimiao_cb_8_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_yimiao_cb_8_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_yimiao_cb_8_main_main_default.set_bg_opa(255)
style_yimiao_cb_8_main_main_default.set_text_color(lv.color_make(0x0D,0x30,0x55))
try:
    style_yimiao_cb_8_main_main_default.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_yimiao_cb_8_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_yimiao_cb_8_main_main_default.set_text_font(lv.font_montserrat_16)
style_yimiao_cb_8_main_main_default.set_text_letter_space(2)

# add style for yimiao_cb_8
yimiao_cb_8.add_style(style_yimiao_cb_8_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_yimiao_cb_8_main_indicator_default
style_yimiao_cb_8_main_indicator_default = lv.style_t()
style_yimiao_cb_8_main_indicator_default.init()
style_yimiao_cb_8_main_indicator_default.set_radius(6)
style_yimiao_cb_8_main_indicator_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_yimiao_cb_8_main_indicator_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_yimiao_cb_8_main_indicator_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_yimiao_cb_8_main_indicator_default.set_bg_opa(255)
style_yimiao_cb_8_main_indicator_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_yimiao_cb_8_main_indicator_default.set_border_width(2)
style_yimiao_cb_8_main_indicator_default.set_border_opa(255)

# add style for yimiao_cb_8
yimiao_cb_8.add_style(style_yimiao_cb_8_main_indicator_default, lv.PART.INDICATOR|lv.STATE.DEFAULT)

yimiao_cb_9 = lv.checkbox(yimiao_cont_1)
yimiao_cb_9.set_pos(int(247),int(73))
yimiao_cb_9.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
yimiao_cb_9.set_text("山羊痘灭活苗")
# create style style_yimiao_cb_9_main_main_default
style_yimiao_cb_9_main_main_default = lv.style_t()
style_yimiao_cb_9_main_main_default.init()
style_yimiao_cb_9_main_main_default.set_radius(6)
style_yimiao_cb_9_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_yimiao_cb_9_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_yimiao_cb_9_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_yimiao_cb_9_main_main_default.set_bg_opa(255)
style_yimiao_cb_9_main_main_default.set_text_color(lv.color_make(0x0D,0x30,0x55))
try:
    style_yimiao_cb_9_main_main_default.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_yimiao_cb_9_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_yimiao_cb_9_main_main_default.set_text_font(lv.font_montserrat_16)
style_yimiao_cb_9_main_main_default.set_text_letter_space(2)

# add style for yimiao_cb_9
yimiao_cb_9.add_style(style_yimiao_cb_9_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_yimiao_cb_9_main_indicator_default
style_yimiao_cb_9_main_indicator_default = lv.style_t()
style_yimiao_cb_9_main_indicator_default.init()
style_yimiao_cb_9_main_indicator_default.set_radius(6)
style_yimiao_cb_9_main_indicator_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_yimiao_cb_9_main_indicator_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_yimiao_cb_9_main_indicator_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_yimiao_cb_9_main_indicator_default.set_bg_opa(255)
style_yimiao_cb_9_main_indicator_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_yimiao_cb_9_main_indicator_default.set_border_width(2)
style_yimiao_cb_9_main_indicator_default.set_border_opa(255)

# add style for yimiao_cb_9
yimiao_cb_9.add_style(style_yimiao_cb_9_main_indicator_default, lv.PART.INDICATOR|lv.STATE.DEFAULT)

# create style style_yimiao_cont_1_main_main_default
style_yimiao_cont_1_main_main_default = lv.style_t()
style_yimiao_cont_1_main_main_default.init()
style_yimiao_cont_1_main_main_default.set_radius(0)
style_yimiao_cont_1_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_yimiao_cont_1_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_yimiao_cont_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_yimiao_cont_1_main_main_default.set_bg_opa(255)
style_yimiao_cont_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_yimiao_cont_1_main_main_default.set_border_width(2)
style_yimiao_cont_1_main_main_default.set_border_opa(255)
style_yimiao_cont_1_main_main_default.set_pad_left(0)
style_yimiao_cont_1_main_main_default.set_pad_right(0)
style_yimiao_cont_1_main_main_default.set_pad_top(0)
style_yimiao_cont_1_main_main_default.set_pad_bottom(0)

# add style for yimiao_cont_1
yimiao_cont_1.add_style(style_yimiao_cont_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)



def mainscan_btn_1_clicked_1_event_cb(e,Ear_management):
    src = e.get_target()
    code = e.get_code()
    lv.scr_load_anim(Ear_management, lv.SCR_LOAD_ANIM.MOVE_RIGHT, 100, 100, False)
mainscan_btn_1.add_event_cb(lambda e: mainscan_btn_1_clicked_1_event_cb(e,Ear_management), lv.EVENT.CLICKED, None)


def mainscan_btn_3_clicked_1_event_cb(e,er_trace):
    src = e.get_target()
    code = e.get_code()
    lv.scr_load_anim(er_trace, lv.SCR_LOAD_ANIM.OVER_RIGHT, 100, 100, False)
mainscan_btn_3.add_event_cb(lambda e: mainscan_btn_3_clicked_1_event_cb(e,er_trace), lv.EVENT.CLICKED, None)


def mainscan_btn_2_clicked_1_event_cb(e,Xin_xi_luru):
    src = e.get_target()
    code = e.get_code()
    lv.scr_load_anim(Xin_xi_luru, lv.SCR_LOAD_ANIM.MOVE_RIGHT, 100, 100, False)
mainscan_btn_2.add_event_cb(lambda e: mainscan_btn_2_clicked_1_event_cb(e,Xin_xi_luru), lv.EVENT.CLICKED, None)


def Ear_management_btn_1_clicked_1_event_cb(e,yimiao):
    src = e.get_target()
    code = e.get_code()
    lv.scr_load_anim(yimiao, lv.SCR_LOAD_ANIM.OVER_BOTTOM, 100, 100, False)
Ear_management_btn_1.add_event_cb(lambda e: Ear_management_btn_1_clicked_1_event_cb(e,yimiao), lv.EVENT.CLICKED, None)


def er_trace_imgbtn_1_released_1_event_cb(e,mainscan):
    src = e.get_target()
    code = e.get_code()
    lv.scr_load_anim(mainscan, lv.SCR_LOAD_ANIM.MOVE_RIGHT, 100, 100, False)
er_trace_imgbtn_1.add_event_cb(lambda e: er_trace_imgbtn_1_released_1_event_cb(e,mainscan), lv.EVENT.RELEASED, None)


def yimiao_imgbtn_1_released_1_event_cb(e,Ear_management):
    src = e.get_target()
    code = e.get_code()
    lv.scr_load_anim(Ear_management, lv.SCR_LOAD_ANIM.MOVE_RIGHT, 100, 100, False)
yimiao_imgbtn_1.add_event_cb(lambda e: yimiao_imgbtn_1_released_1_event_cb(e,Ear_management), lv.EVENT.RELEASED, None)


def Ear_management_imgbtn_1_released_1_event_cb(e,mainscan):
    src = e.get_target()
    code = e.get_code()
    lv.scr_load_anim(mainscan, lv.SCR_LOAD_ANIM.MOVE_RIGHT, 100, 100, False)
Ear_management_imgbtn_1.add_event_cb(lambda e: Ear_management_imgbtn_1_released_1_event_cb(e,mainscan), lv.EVENT.RELEASED, None)


def Xin_xi_luru_imgbtn_1_released_1_event_cb(e,mainscan):
    src = e.get_target()
    code = e.get_code()
    lv.scr_load_anim(mainscan, lv.SCR_LOAD_ANIM.MOVE_RIGHT, 100, 100, False)
Xin_xi_luru_imgbtn_1.add_event_cb(lambda e: Xin_xi_luru_imgbtn_1_released_1_event_cb(e,mainscan), lv.EVENT.RELEASED, None)



# content from custom.py

# Load the default screen
lv.scr_load(mainscan)

while SDL.check():
    time.sleep_ms(5)
