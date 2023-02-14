#include "lvgl/lvgl.h"

/*******************************************************************************
 * Size: 11 px
 * Bpp: 4
 * Opts: 
 ******************************************************************************/

#ifndef LV_CUSTOMER_FONT_SIMSUN_11
#define LV_CUSTOMER_FONT_SIMSUN_11 1
#endif

#if LV_CUSTOMER_FONT_SIMSUN_11

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t gylph_bitmap[] = {
    /* U+6807 "标" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9, 0x0,
    0x0, 0x0, 0x20, 0x0, 0x90, 0x4, 0x44, 0x44,
    0x1, 0x3b, 0x63, 0x0, 0x0, 0x0, 0x0, 0xb0,
    0x34, 0x44, 0x47, 0x30, 0x2e, 0x60, 0x0, 0xa0,
    0x0, 0x7, 0xa5, 0x29, 0x1a, 0x40, 0x0, 0x69,
    0x2, 0x80, 0xa3, 0x70, 0x30, 0x90, 0x70, 0xa,
    0xc, 0x10, 0xa, 0x22, 0x0, 0xa0, 0x30, 0x0,
    0x90, 0x1, 0xa5, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    /* U+8033 "耳" */
    0x3, 0x44, 0x44, 0x44, 0x48, 0x10, 0x0, 0xa0,
    0x0, 0xa0, 0x0, 0x0, 0xb, 0x44, 0x4b, 0x0,
    0x0, 0x0, 0xa0, 0x0, 0xa0, 0x0, 0x0, 0xa,
    0x0, 0xa, 0x0, 0x0, 0x0, 0xb4, 0x44, 0xb0,
    0x0, 0x0, 0xa, 0x0, 0xa, 0x15, 0x40, 0x44,
    0x74, 0x44, 0xb2, 0x10, 0x0, 0x0, 0x0, 0xa,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x90, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+F001 "" */
    0x0, 0x0, 0x0, 0x0, 0x59, 0xb0, 0x0, 0x2,
    0x7b, 0xff, 0xff, 0x0, 0x1d, 0xff, 0xff, 0xff,
    0xf0, 0x4, 0xff, 0xff, 0xc7, 0x8f, 0x0, 0x4f,
    0xa5, 0x10, 0x6, 0xf0, 0x4, 0xf2, 0x0, 0x0,
    0x6f, 0x0, 0x4f, 0x20, 0x0, 0x6, 0xf0, 0x4,
    0xf2, 0x0, 0x8e, 0xff, 0x28, 0xaf, 0x20, 0xf,
    0xff, 0xfe, 0xff, 0xf1, 0x0, 0x5b, 0xb4, 0x9f,
    0xfb, 0x0, 0x0, 0x0, 0x0, 0x11, 0x0, 0x0,
    0x0, 0x0,

    /* U+F008 "" */
    0x10, 0x34, 0x44, 0x44, 0x30, 0x1d, 0x9f, 0xdc,
    0xcc, 0xdf, 0x9d, 0xb2, 0xf1, 0x0, 0x1, 0xf2,
    0xcd, 0x8f, 0x10, 0x0, 0x1f, 0x8d, 0xc3, 0xfb,
    0xaa, 0xab, 0xf3, 0xcd, 0x7f, 0x76, 0x66, 0x7f,
    0x7d, 0xc4, 0xf1, 0x0, 0x1, 0xf4, 0xcd, 0x6f,
    0x20, 0x0, 0x2f, 0x6d, 0xb5, 0xff, 0xff, 0xff,
    0xf5, 0xb0,

    /* U+F00B "" */
    0xef, 0xe3, 0xef, 0xff, 0xff, 0xdf, 0xff, 0x5f,
    0xff, 0xff, 0xff, 0xbc, 0xc2, 0xcc, 0xcc, 0xcc,
    0xb7, 0x87, 0x7, 0x88, 0x88, 0x86, 0xff, 0xf5,
    0xff, 0xff, 0xff, 0xff, 0xff, 0x4f, 0xff, 0xff,
    0xff, 0x35, 0x40, 0x45, 0x55, 0x55, 0x3f, 0xff,
    0x3f, 0xff, 0xff, 0xff, 0xff, 0xf5, 0xff, 0xff,
    0xff, 0xfa, 0xba, 0x1a, 0xbb, 0xbb, 0xba,

    /* U+F00C "" */
    0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0,
    0x0, 0x4, 0xf9, 0x0, 0x0, 0x0, 0x4, 0xff,
    0xc1, 0x50, 0x0, 0x4, 0xff, 0xc0, 0xcf, 0x80,
    0x4, 0xff, 0xc0, 0x8, 0xff, 0x84, 0xff, 0xc0,
    0x0, 0x9, 0xff, 0xff, 0xc0, 0x0, 0x0, 0x9,
    0xff, 0xc0, 0x0, 0x0, 0x0, 0x8, 0xb0, 0x0,
    0x0, 0x0,

    /* U+F00D "" */
    0x7b, 0x0, 0x4, 0xc2, 0xdf, 0xc0, 0x4f, 0xf6,
    0x2e, 0xfd, 0xff, 0x90, 0x2, 0xef, 0xf9, 0x0,
    0x4, 0xff, 0xfc, 0x0, 0x5f, 0xfa, 0xef, 0xc0,
    0xef, 0x90, 0x2e, 0xf7, 0x47, 0x0, 0x2, 0x81,

    /* U+F011 "" */
    0x0, 0x0, 0x1d, 0x60, 0x0, 0x0, 0x0, 0x71,
    0x2f, 0x90, 0x62, 0x0, 0x9, 0xf7, 0x2f, 0x90,
    0xfe, 0x20, 0x3f, 0xb0, 0x2f, 0x90, 0x5f, 0xb0,
    0xaf, 0x20, 0x2f, 0x90, 0xb, 0xf1, 0xce, 0x0,
    0x2f, 0x90, 0x7, 0xf3, 0xbf, 0x0, 0x5, 0x20,
    0x8, 0xf3, 0x8f, 0x50, 0x0, 0x0, 0xe, 0xf0,
    0x1e, 0xf4, 0x0, 0x1, 0xbf, 0x70, 0x4, 0xff,
    0xc9, 0xaf, 0xfa, 0x0, 0x0, 0x2a, 0xff, 0xfd,
    0x60, 0x0, 0x0, 0x0, 0x1, 0x10, 0x0, 0x0,

    /* U+F013 "" */
    0x0, 0x0, 0x46, 0x40, 0x0, 0x0, 0x0, 0xe,
    0xfe, 0x0, 0x0, 0x8, 0x7a, 0xff, 0xfa, 0x78,
    0x3, 0xff, 0xff, 0xff, 0xff, 0xf3, 0x5f, 0xff,
    0x83, 0x9f, 0xff, 0x50, 0x9f, 0xd0, 0x0, 0xdf,
    0x90, 0xa, 0xfe, 0x0, 0xe, 0xfa, 0x7, 0xff,
    0xfc, 0x7c, 0xff, 0xf7, 0x2f, 0xff, 0xff, 0xff,
    0xff, 0x20, 0x43, 0x6f, 0xff, 0x63, 0x40, 0x0,
    0x0, 0xdf, 0xd0, 0x0, 0x0, 0x0, 0x1, 0x21,
    0x0, 0x0,

    /* U+F015 "" */
    0x0, 0x0, 0xa, 0xd3, 0x3f, 0x70, 0x0, 0x0,
    0x2d, 0xec, 0xf9, 0xf7, 0x0, 0x0, 0x4e, 0xd4,
    0x59, 0xff, 0x70, 0x0, 0x6f, 0xb4, 0xef, 0x86,
    0xfb, 0x0, 0x9f, 0x96, 0xff, 0xff, 0xa5, 0xed,
    0x19, 0x68, 0xff, 0xff, 0xff, 0xd3, 0xb1, 0x0,
    0xff, 0xff, 0xef, 0xff, 0x50, 0x0, 0xf, 0xff,
    0x20, 0xcf, 0xf5, 0x0, 0x0, 0xff, 0xf2, 0xc,
    0xff, 0x50, 0x0, 0x9, 0xaa, 0x10, 0x7a, 0xa2,
    0x0,

    /* U+F019 "" */
    0x0, 0x0, 0x7, 0x96, 0x0, 0x0, 0x0, 0x0,
    0xe, 0xfd, 0x0, 0x0, 0x0, 0x0, 0xe, 0xfd,
    0x0, 0x0, 0x0, 0x0, 0xe, 0xfd, 0x0, 0x0,
    0x0, 0x17, 0x7f, 0xfe, 0x77, 0x0, 0x0, 0xc,
    0xff, 0xff, 0xfb, 0x0, 0x0, 0x1, 0xdf, 0xff,
    0xc0, 0x0, 0x0, 0x0, 0x1d, 0xfc, 0x10, 0x0,
    0xf, 0xff, 0xe4, 0x94, 0xff, 0xfe, 0xf, 0xff,
    0xfe, 0x8e, 0xff, 0xff, 0xf, 0xff, 0xff, 0xff,
    0x8b, 0x7f, 0x8, 0x99, 0x99, 0x99, 0x99, 0x97,

    /* U+F01C "" */
    0x0, 0x3, 0x44, 0x44, 0x41, 0x0, 0x0, 0xb,
    0xff, 0xff, 0xff, 0xf2, 0x0, 0x6, 0xf4, 0x22,
    0x22, 0x2d, 0xc0, 0x2, 0xf9, 0x0, 0x0, 0x0,
    0x3f, 0x70, 0xbe, 0x22, 0x0, 0x0, 0x12, 0xaf,
    0x2f, 0xff, 0xf9, 0x0, 0x3f, 0xff, 0xf5, 0xff,
    0xff, 0xfc, 0xce, 0xff, 0xff, 0x6f, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xf5, 0xcf, 0xff, 0xff, 0xff,
    0xff, 0xff, 0x30,

    /* U+F021 "" */
    0x0, 0x1, 0x56, 0x40, 0x4, 0x90, 0x8, 0xff,
    0xff, 0xe6, 0x7f, 0x9, 0xfc, 0x42, 0x4c, 0xfe,
    0xf3, 0xfa, 0x0, 0x4, 0x4c, 0xff, 0xaf, 0x10,
    0x0, 0xcf, 0xff, 0xf1, 0x20, 0x0, 0x2, 0x33,
    0x32, 0x67, 0x77, 0x50, 0x0, 0x5, 0x4f, 0xff,
    0xfc, 0x0, 0x2, 0xf8, 0xff, 0xc2, 0x0, 0x1,
    0xdf, 0x2f, 0xcf, 0xf9, 0x79, 0xff, 0x50, 0xf7,
    0x2a, 0xff, 0xfb, 0x30, 0x5, 0x20, 0x0, 0x10,
    0x0, 0x0,

    /* U+F026 "" */
    0x0, 0x0, 0x10, 0x0, 0x1, 0xd7, 0x12, 0x3d,
    0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xf8, 0xff,
    0xff, 0xf8, 0xef, 0xff, 0xf8, 0x0, 0xb, 0xf8,
    0x0, 0x0, 0xb7, 0x0, 0x0, 0x0,

    /* U+F027 "" */
    0x0, 0x0, 0x10, 0x0, 0x0, 0x0, 0x1d, 0x70,
    0x0, 0x12, 0x3d, 0xf8, 0x0, 0xf, 0xff, 0xff,
    0x85, 0x80, 0xff, 0xff, 0xf8, 0x1e, 0x2f, 0xff,
    0xff, 0x82, 0xe1, 0xef, 0xff, 0xf8, 0x34, 0x0,
    0x0, 0xbf, 0x80, 0x0, 0x0, 0x0, 0xb7, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+F028 "" */
    0x0, 0x0, 0x0, 0x0, 0x2, 0x0, 0x0, 0x0,
    0x1, 0x0, 0x2, 0xe5, 0x0, 0x0, 0x1, 0xd7,
    0x2, 0x52, 0xe3, 0x1, 0x23, 0xdf, 0x80, 0x1d,
    0x76, 0xb0, 0xff, 0xff, 0xf8, 0x58, 0x2f, 0x1f,
    0x1f, 0xff, 0xff, 0x80, 0xe2, 0xd3, 0xd3, 0xff,
    0xff, 0xf8, 0x2e, 0x1e, 0x2d, 0x3e, 0xff, 0xff,
    0x83, 0x45, 0xe1, 0xf0, 0x0, 0xb, 0xf8, 0x3,
    0xe4, 0x9a, 0x0, 0x0, 0xb, 0x70, 0x2, 0x6e,
    0x10, 0x0, 0x0, 0x0, 0x0, 0x2d, 0x20, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+F03E "" */
    0x13, 0x44, 0x44, 0x44, 0x43, 0x1e, 0xff, 0xff,
    0xff, 0xff, 0xfe, 0xf7, 0xa, 0xff, 0xff, 0xff,
    0xff, 0x40, 0x7f, 0xff, 0x6e, 0xff, 0xfe, 0xbf,
    0xff, 0x40, 0x2e, 0xff, 0xf7, 0x4e, 0x40, 0x0,
    0x6f, 0xf8, 0x0, 0x10, 0x0, 0x6, 0xff, 0x96,
    0x66, 0x66, 0x66, 0x9f, 0xcf, 0xff, 0xff, 0xff,
    0xff, 0xc0,

    /* U+F048 "" */
    0x0, 0x0, 0x0, 0x0, 0x9d, 0x0, 0x3, 0xd2,
    0xae, 0x0, 0x4f, 0xf4, 0xae, 0x6, 0xff, 0xf4,
    0xae, 0x7f, 0xff, 0xf4, 0xaf, 0xff, 0xff, 0xf4,
    0xaf, 0xff, 0xff, 0xf4, 0xae, 0x3e, 0xff, 0xf4,
    0xae, 0x2, 0xef, 0xf4, 0xae, 0x0, 0x1d, 0xf3,
    0x69, 0x0, 0x1, 0x91,

    /* U+F04B "" */
    0x67, 0x0, 0x0, 0x0, 0x0, 0xff, 0xd5, 0x0,
    0x0, 0x0, 0xff, 0xff, 0xb2, 0x0, 0x0, 0xff,
    0xff, 0xff, 0x80, 0x0, 0xff, 0xff, 0xff, 0xfe,
    0x50, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xff, 0xff,
    0xff, 0xff, 0xf5, 0xff, 0xff, 0xff, 0xfb, 0x20,
    0xff, 0xff, 0xfd, 0x40, 0x0, 0xff, 0xff, 0x70,
    0x0, 0x0, 0xff, 0xa1, 0x0, 0x0, 0x0, 0x23,
    0x0, 0x0, 0x0, 0x0,

    /* U+F04C "" */
    0xbf, 0xfc, 0x1, 0xdf, 0xf9, 0xff, 0xff, 0x14,
    0xff, 0xfd, 0xff, 0xff, 0x24, 0xff, 0xfd, 0xff,
    0xff, 0x24, 0xff, 0xfd, 0xff, 0xff, 0x24, 0xff,
    0xfd, 0xff, 0xff, 0x24, 0xff, 0xfd, 0xff, 0xff,
    0x24, 0xff, 0xfd, 0xff, 0xff, 0x24, 0xff, 0xfd,
    0xff, 0xff, 0x14, 0xff, 0xfd, 0x7a, 0xa8, 0x0,
    0x9a, 0xa5,

    /* U+F04D "" */
    0xbf, 0xff, 0xff, 0xff, 0xf5, 0xff, 0xff, 0xff,
    0xff, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xfa, 0xff,
    0xff, 0xff, 0xff, 0xfa, 0xff, 0xff, 0xff, 0xff,
    0xfa, 0xff, 0xff, 0xff, 0xff, 0xfa, 0xff, 0xff,
    0xff, 0xff, 0xfa, 0xff, 0xff, 0xff, 0xff, 0xfa,
    0xff, 0xff, 0xff, 0xff, 0xf9, 0x7a, 0xaa, 0xaa,
    0xaa, 0xa3,

    /* U+F051 "" */
    0x0, 0x0, 0x0, 0x0, 0xa9, 0x0, 0x6, 0xf0,
    0xcf, 0xb0, 0x7, 0xf1, 0xcf, 0xfc, 0x17, 0xf1,
    0xcf, 0xff, 0xd9, 0xf1, 0xcf, 0xff, 0xff, 0xf1,
    0xcf, 0xff, 0xfe, 0xf1, 0xcf, 0xff, 0x97, 0xf1,
    0xcf, 0xf8, 0x7, 0xf1, 0xcf, 0x60, 0x7, 0xf1,
    0x65, 0x0, 0x4, 0xa0,

    /* U+F052 "" */
    0x0, 0x0, 0x1c, 0x90, 0x0, 0x0, 0x0, 0x1d,
    0xff, 0x80, 0x0, 0x0, 0xc, 0xff, 0xff, 0x70,
    0x0, 0xb, 0xff, 0xff, 0xff, 0x60, 0xa, 0xff,
    0xff, 0xff, 0xff, 0x40, 0xef, 0xff, 0xff, 0xff,
    0xf8, 0x1, 0x45, 0x55, 0x55, 0x54, 0x0, 0xef,
    0xff, 0xff, 0xff, 0xf8, 0xf, 0xff, 0xff, 0xff,
    0xff, 0xa0, 0x9b, 0xbb, 0xbb, 0xbb, 0xb4,

    /* U+F053 "" */
    0x0, 0x0, 0x4b, 0x0, 0x0, 0x4f, 0xe1, 0x0,
    0x4f, 0xe3, 0x0, 0x4f, 0xe3, 0x0, 0x3f, 0xf3,
    0x0, 0x1, 0xdf, 0x70, 0x0, 0x1, 0xdf, 0x70,
    0x0, 0x1, 0xdf, 0x70, 0x0, 0x1, 0xdf, 0x20,
    0x0, 0x1, 0x50,

    /* U+F054 "" */
    0x1b, 0x30, 0x0, 0x3, 0xff, 0x30, 0x0, 0x4,
    0xff, 0x30, 0x0, 0x4, 0xff, 0x30, 0x0, 0x4,
    0xff, 0x20, 0x0, 0x9f, 0xc0, 0x0, 0x9f, 0xc0,
    0x0, 0x9f, 0xc0, 0x0, 0x4f, 0xc0, 0x0, 0x0,
    0x60, 0x0, 0x0,

    /* U+F067 "" */
    0x0, 0x1, 0xea, 0x0, 0x0, 0x0, 0x3, 0xfd,
    0x0, 0x0, 0x0, 0x3, 0xfd, 0x0, 0x0, 0x12,
    0x25, 0xfd, 0x22, 0x20, 0xff, 0xff, 0xff, 0xff,
    0xf9, 0xce, 0xee, 0xff, 0xee, 0xe6, 0x0, 0x3,
    0xfd, 0x0, 0x0, 0x0, 0x3, 0xfd, 0x0, 0x0,
    0x0, 0x3, 0xfd, 0x0, 0x0, 0x0, 0x0, 0xa7,
    0x0, 0x0,

    /* U+F068 "" */
    0x1, 0x11, 0x11, 0x11, 0x10, 0xef, 0xff, 0xff,
    0xff, 0xf8, 0xdf, 0xff, 0xff, 0xff, 0xf7,

    /* U+F06E "" */
    0x0, 0x0, 0x1, 0x20, 0x0, 0x0, 0x0, 0x1,
    0x9f, 0xfe, 0xfb, 0x40, 0x0, 0x4, 0xef, 0x60,
    0x13, 0xdf, 0x80, 0x3, 0xff, 0x70, 0x3f, 0xa2,
    0xff, 0x70, 0xdf, 0xf2, 0x7c, 0xff, 0x2d, 0xff,
    0x2c, 0xff, 0x3b, 0xff, 0xf1, 0xef, 0xf1, 0x2e,
    0xf9, 0x2c, 0xd6, 0x4f, 0xf5, 0x0, 0x2d, 0xf9,
    0x21, 0x6e, 0xf5, 0x0, 0x0, 0x6, 0xcf, 0xfd,
    0x92, 0x0, 0x0,

    /* U+F070 "" */
    0x52, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xce,
    0x40, 0x0, 0x21, 0x0, 0x0, 0x0, 0xa, 0xf9,
    0xaf, 0xef, 0xf9, 0x20, 0x0, 0x0, 0x6f, 0xf5,
    0x11, 0x5f, 0xf4, 0x0, 0x5, 0x3, 0xee, 0xcf,
    0x56, 0xff, 0x30, 0x2f, 0xd2, 0x1b, 0xff, 0xd1,
    0xff, 0xe0, 0x1e, 0xfd, 0x0, 0x7f, 0xe3, 0xff,
    0xc0, 0x5, 0xff, 0x40, 0x4, 0xef, 0xfe, 0x20,
    0x0, 0x5f, 0xe6, 0x10, 0x1c, 0xf8, 0x0, 0x0,
    0x1, 0x8d, 0xfd, 0x20, 0x9f, 0xa0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x5, 0xf9, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x21,

    /* U+F071 "" */
    0x0, 0x0, 0x0, 0x69, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x2, 0xff, 0x80, 0x0, 0x0, 0x0, 0x0,
    0xb, 0xff, 0xf1, 0x0, 0x0, 0x0, 0x0, 0x4f,
    0xff, 0xfa, 0x0, 0x0, 0x0, 0x0, 0xdf, 0x50,
    0xef, 0x30, 0x0, 0x0, 0x6, 0xff, 0x50, 0xef,
    0xc0, 0x0, 0x0, 0x1e, 0xff, 0x50, 0xff, 0xf5,
    0x0, 0x0, 0x9f, 0xff, 0xa6, 0xff, 0xfe, 0x0,
    0x2, 0xff, 0xff, 0x61, 0xff, 0xff, 0x80, 0xb,
    0xff, 0xff, 0x72, 0xff, 0xff, 0xf1, 0xe, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xf4, 0x2, 0x55, 0x55,
    0x55, 0x55, 0x55, 0x40,

    /* U+F074 "" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xb, 0x80, 0xaa, 0xa1, 0x0, 0x4a, 0xef,
    0x8f, 0xff, 0xc0, 0x4f, 0xff, 0xfc, 0x0, 0x8d,
    0x4f, 0xe3, 0xcd, 0x10, 0x0, 0x4f, 0xf3, 0x3,
    0x10, 0x0, 0x2e, 0xf5, 0x80, 0xa7, 0x9, 0xae,
    0xf4, 0x7f, 0xce, 0xf7, 0xff, 0xf5, 0x0, 0xaf,
    0xff, 0xd1, 0x11, 0x0, 0x0, 0x1c, 0xd1, 0x0,
    0x0, 0x0, 0x0, 0x41, 0x0,

    /* U+F077 "" */
    0x0, 0x1, 0xc7, 0x0, 0x0, 0x0, 0x1c, 0xff,
    0x70, 0x0, 0x1, 0xcf, 0x9d, 0xf7, 0x0, 0x1c,
    0xf8, 0x1, 0xdf, 0x70, 0xbf, 0x80, 0x0, 0x1d,
    0xf5, 0x47, 0x0, 0x0, 0x1, 0x91,

    /* U+F078 "" */
    0x8b, 0x0, 0x0, 0x3, 0xd3, 0x9f, 0xc0, 0x0,
    0x3f, 0xf3, 0x9, 0xfc, 0x3, 0xff, 0x40, 0x0,
    0x9f, 0xcf, 0xf4, 0x0, 0x0, 0x9, 0xff, 0x40,
    0x0, 0x0, 0x0, 0x84, 0x0, 0x0,

    /* U+F079 "" */
    0x0, 0x20, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4,
    0xfb, 0x4, 0x66, 0x66, 0x61, 0x0, 0x4f, 0xff,
    0xb8, 0xff, 0xff, 0xf7, 0x0, 0xdb, 0xfb, 0xf5,
    0x0, 0x0, 0xe7, 0x0, 0x10, 0xf7, 0x10, 0x0,
    0x0, 0xe7, 0x0, 0x0, 0xf7, 0x0, 0x0, 0x20,
    0xe7, 0x20, 0x0, 0xf7, 0x11, 0x10, 0xcc, 0xec,
    0xf5, 0x0, 0xef, 0xff, 0xff, 0x5e, 0xff, 0xa0,
    0x0, 0x35, 0x55, 0x54, 0x3, 0xea, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x10, 0x0,

    /* U+F07B "" */
    0x13, 0x44, 0x20, 0x0, 0x0, 0xe, 0xff, 0xff,
    0x40, 0x0, 0x0, 0xff, 0xff, 0xff, 0xee, 0xed,
    0xaf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xcf, 0xff, 0xff, 0xff,
    0xff, 0xc0,

    /* U+F093 "" */
    0x0, 0x0, 0x7, 0x0, 0x0, 0x0, 0x0, 0xb,
    0xfb, 0x0, 0x0, 0x0, 0xb, 0xff, 0xfb, 0x0,
    0x0, 0xb, 0xff, 0xff, 0xfb, 0x0, 0x0, 0x88,
    0xff, 0xf8, 0x80, 0x0, 0x0, 0xe, 0xfe, 0x0,
    0x0, 0x0, 0x0, 0xef, 0xe0, 0x0, 0x0, 0x0,
    0xe, 0xfe, 0x0, 0x0, 0xff, 0xf8, 0x9b, 0x98,
    0xff, 0xff, 0xff, 0xf8, 0x78, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xf9, 0xb6, 0xf8, 0x99, 0x99, 0x99,
    0x99, 0x98,

    /* U+F095 "" */
    0x0, 0x0, 0x0, 0x0, 0x18, 0x51, 0x0, 0x0,
    0x0, 0x0, 0x9f, 0xff, 0x0, 0x0, 0x0, 0x0,
    0xff, 0xfe, 0x0, 0x0, 0x0, 0x2, 0xff, 0xfc,
    0x0, 0x0, 0x0, 0x0, 0x3f, 0xf7, 0x0, 0x0,
    0x0, 0x0, 0x3f, 0xf2, 0x0, 0x0, 0x0, 0x1,
    0xef, 0x90, 0x0, 0x5c, 0x70, 0x2d, 0xfd, 0x0,
    0xd, 0xff, 0xfa, 0xff, 0xd1, 0x0, 0xc, 0xff,
    0xff, 0xfb, 0x10, 0x0, 0x9, 0xff, 0xfb, 0x40,
    0x0, 0x0, 0x1, 0x53, 0x10, 0x0, 0x0, 0x0,

    /* U+F0C4 "" */
    0x3c, 0xd4, 0x0, 0x5, 0x82, 0xdc, 0xbf, 0x0,
    0x9f, 0xf5, 0xea, 0x8f, 0x9, 0xff, 0x60, 0x6f,
    0xff, 0xdf, 0xf6, 0x0, 0x1, 0x6f, 0xff, 0x60,
    0x0, 0x4, 0xaf, 0xff, 0x70, 0x0, 0x9f, 0xff,
    0x9f, 0xf7, 0x0, 0xf8, 0x6f, 0x16, 0xff, 0x70,
    0xcd, 0xce, 0x0, 0x6f, 0xf6, 0x2b, 0xc3, 0x0,
    0x4, 0x71,

    /* U+F0C5 "" */
    0x0, 0x1d, 0xdd, 0xd3, 0x70, 0x0, 0x3f, 0xff,
    0xf4, 0xf7, 0x79, 0x4f, 0xff, 0xf2, 0x32, 0xff,
    0x4f, 0xff, 0xfe, 0xeb, 0xff, 0x4f, 0xff, 0xff,
    0xfd, 0xff, 0x4f, 0xff, 0xff, 0xfd, 0xff, 0x4f,
    0xff, 0xff, 0xfd, 0xff, 0x4f, 0xff, 0xff, 0xfd,
    0xff, 0x4f, 0xff, 0xff, 0xfd, 0xff, 0x64, 0x55,
    0x55, 0x53, 0xff, 0xff, 0xff, 0xf0, 0x0, 0x46,
    0x66, 0x66, 0x50, 0x0,

    /* U+F0C7 "" */
    0xbf, 0xff, 0xff, 0xfa, 0x0, 0xfa, 0x66, 0x66,
    0x8f, 0xa0, 0xf6, 0x0, 0x0, 0x1f, 0xf8, 0xf6,
    0x0, 0x0, 0x1f, 0xfa, 0xff, 0xff, 0xff, 0xff,
    0xfa, 0xff, 0xff, 0x8a, 0xff, 0xfa, 0xff, 0xf8,
    0x0, 0xdf, 0xfa, 0xff, 0xf9, 0x0, 0xef, 0xfa,
    0xff, 0xff, 0x9b, 0xff, 0xfa, 0xae, 0xee, 0xee,
    0xee, 0xe6,

    /* U+F0E7 "" */
    0x3, 0xdd, 0xd9, 0x0, 0x6, 0xff, 0xf9, 0x0,
    0x9, 0xff, 0xf3, 0x0, 0xb, 0xff, 0xf6, 0x64,
    0xd, 0xff, 0xff, 0xfb, 0xf, 0xff, 0xff, 0xf2,
    0x4, 0x55, 0xff, 0x90, 0x0, 0x3, 0xfe, 0x10,
    0x0, 0x7, 0xf6, 0x0, 0x0, 0xa, 0xd0, 0x0,
    0x0, 0xd, 0x40, 0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+F0EA "" */
    0x1, 0x5b, 0x41, 0x0, 0x0, 0xff, 0xf4, 0xff,
    0xf0, 0x0, 0xff, 0xff, 0xff, 0xf1, 0x0, 0xff,
    0xe4, 0x55, 0x51, 0x10, 0xff, 0xc8, 0xff, 0xf4,
    0xd1, 0xff, 0xc8, 0xff, 0xf3, 0xa7, 0xff, 0xc8,
    0xff, 0xfb, 0xa8, 0xff, 0xc8, 0xff, 0xff, 0xfd,
    0xff, 0xc8, 0xff, 0xff, 0xfd, 0x1, 0x18, 0xff,
    0xff, 0xfd, 0x0, 0x8, 0xff, 0xff, 0xfd, 0x0,
    0x0, 0x22, 0x22, 0x21,

    /* U+F0F3 "" */
    0x0, 0x0, 0x62, 0x0, 0x0, 0x0, 0x4, 0xeb,
    0x20, 0x0, 0x0, 0x9f, 0xff, 0xf4, 0x0, 0x5,
    0xff, 0xff, 0xfe, 0x0, 0x9, 0xff, 0xff, 0xff,
    0x30, 0xb, 0xff, 0xff, 0xff, 0x50, 0xd, 0xff,
    0xff, 0xff, 0x70, 0x4f, 0xff, 0xff, 0xff, 0xd0,
    0xef, 0xff, 0xff, 0xff, 0xf8, 0x35, 0x55, 0x55,
    0x55, 0x41, 0x0, 0x6, 0xff, 0x10, 0x0, 0x0,
    0x0, 0x42, 0x0, 0x0,

    /* U+F11C "" */
    0x13, 0x44, 0x44, 0x44, 0x44, 0x43, 0xe, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xf4, 0xf7, 0x2b, 0x2c,
    0x2c, 0x2c, 0x2f, 0x6f, 0xdb, 0xeb, 0xeb, 0xeb,
    0xeb, 0xf6, 0xff, 0x60, 0xb0, 0xa0, 0xb0, 0xff,
    0x6f, 0xfd, 0xae, 0xae, 0xae, 0xaf, 0xf6, 0xf6,
    0x1a, 0x0, 0x0, 0xb, 0xf, 0x6f, 0xa6, 0xc6,
    0x66, 0x66, 0xd6, 0xf5, 0xcf, 0xff, 0xff, 0xff,
    0xff, 0xff, 0x30,

    /* U+F124 "" */
    0x0, 0x0, 0x0, 0x0, 0x1, 0x75, 0x0, 0x0,
    0x0, 0x0, 0x29, 0xff, 0xe0, 0x0, 0x0, 0x3,
    0xaf, 0xff, 0xf9, 0x0, 0x0, 0x4c, 0xff, 0xff,
    0xff, 0x20, 0x5, 0xdf, 0xff, 0xff, 0xff, 0xa0,
    0x0, 0xff, 0xff, 0xff, 0xff, 0xf3, 0x0, 0x5,
    0x89, 0x9a, 0xff, 0xfc, 0x0, 0x0, 0x0, 0x0,
    0x3f, 0xff, 0x40, 0x0, 0x0, 0x0, 0x3, 0xff,
    0xd0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xf6, 0x0,
    0x0, 0x0, 0x0, 0x1, 0xfe, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x3, 0x20, 0x0, 0x0,

    /* U+F15B "" */
    0x67, 0x77, 0x63, 0x0, 0xf, 0xff, 0xfd, 0x8c,
    0x0, 0xff, 0xff, 0xd8, 0xfc, 0xf, 0xff, 0xfd,
    0x35, 0x51, 0xff, 0xff, 0xff, 0xff, 0x4f, 0xff,
    0xff, 0xff, 0xf4, 0xff, 0xff, 0xff, 0xff, 0x4f,
    0xff, 0xff, 0xff, 0xf4, 0xff, 0xff, 0xff, 0xff,
    0x4f, 0xff, 0xff, 0xff, 0xf4, 0xff, 0xff, 0xff,
    0xff, 0x47, 0x88, 0x88, 0x88, 0x81,

    /* U+F1EB "" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x6, 0xbe, 0xff, 0xea, 0x50, 0x0, 0x6, 0xff,
    0xfd, 0xbc, 0xef, 0xfd, 0x40, 0xaf, 0xe6, 0x10,
    0x0, 0x2, 0x8f, 0xf6, 0x7b, 0x10, 0x26, 0x88,
    0x51, 0x2, 0xc4, 0x0, 0x1a, 0xff, 0xff, 0xff,
    0x70, 0x0, 0x0, 0x6f, 0xc5, 0x23, 0x6e, 0xf2,
    0x0, 0x0, 0x4, 0x0, 0x0, 0x0, 0x30, 0x0,
    0x0, 0x0, 0x3, 0xfd, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x7, 0xff, 0x30, 0x0, 0x0, 0x0, 0x0,
    0x1, 0x97, 0x0, 0x0, 0x0,

    /* U+F240 "" */
    0x36, 0x66, 0x66, 0x66, 0x66, 0x66, 0x40, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf2, 0xf6, 0x67,
    0x77, 0x77, 0x77, 0x73, 0xfe, 0xf6, 0xef, 0xff,
    0xff, 0xff, 0xf3, 0xae, 0xf6, 0xef, 0xff, 0xff,
    0xff, 0xf3, 0xbe, 0xf6, 0x45, 0x55, 0x55, 0x55,
    0x53, 0xfc, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xf0, 0x24, 0x55, 0x55, 0x55, 0x55, 0x55, 0x20,

    /* U+F241 "" */
    0x36, 0x66, 0x66, 0x66, 0x66, 0x66, 0x40, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf2, 0xf6, 0x67,
    0x77, 0x77, 0x70, 0x2, 0xfe, 0xf6, 0xef, 0xff,
    0xff, 0xf1, 0x0, 0xae, 0xf6, 0xef, 0xff, 0xff,
    0xf1, 0x0, 0xbe, 0xf6, 0x45, 0x55, 0x55, 0x51,
    0x13, 0xfc, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xf0, 0x24, 0x55, 0x55, 0x55, 0x55, 0x55, 0x20,

    /* U+F242 "" */
    0x36, 0x66, 0x66, 0x66, 0x66, 0x66, 0x40, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf2, 0xf6, 0x67,
    0x77, 0x60, 0x0, 0x2, 0xfe, 0xf6, 0xef, 0xff,
    0xf0, 0x0, 0x0, 0xae, 0xf6, 0xef, 0xff, 0xf0,
    0x0, 0x0, 0xbe, 0xf6, 0x45, 0x55, 0x41, 0x11,
    0x13, 0xfc, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xf0, 0x24, 0x55, 0x55, 0x55, 0x55, 0x55, 0x20,

    /* U+F243 "" */
    0x36, 0x66, 0x66, 0x66, 0x66, 0x66, 0x40, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf2, 0xf6, 0x67,
    0x60, 0x0, 0x0, 0x2, 0xfe, 0xf6, 0xef, 0xe0,
    0x0, 0x0, 0x0, 0xae, 0xf6, 0xef, 0xe0, 0x0,
    0x0, 0x0, 0xbe, 0xf6, 0x45, 0x41, 0x11, 0x11,
    0x13, 0xfc, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xf0, 0x24, 0x55, 0x55, 0x55, 0x55, 0x55, 0x20,

    /* U+F244 "" */
    0x36, 0x66, 0x66, 0x66, 0x66, 0x66, 0x40, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf6, 0x0,
    0x0, 0x0, 0x0, 0x2, 0xfd, 0xf6, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xae, 0xf6, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xbe, 0xf6, 0x11, 0x11, 0x11, 0x11,
    0x13, 0xfc, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xf0, 0x24, 0x55, 0x55, 0x55, 0x55, 0x55, 0x20,

    /* U+F287 "" */
    0x0, 0x0, 0x0, 0x2, 0x20, 0x0, 0x0, 0x0,
    0x0, 0x3, 0x8f, 0xf1, 0x0, 0x0, 0x0, 0x0,
    0x1c, 0x3b, 0xc0, 0x0, 0x0, 0x6d, 0x70, 0x93,
    0x0, 0x0, 0x5, 0x30, 0xff, 0xfb, 0xfb, 0xbb,
    0xbb, 0xbe, 0xf7, 0xaf, 0xb0, 0x5, 0x90, 0x0,
    0x8, 0x80, 0x2, 0x0, 0x0, 0xc0, 0x13, 0x20,
    0x0, 0x0, 0x0, 0x0, 0x4a, 0xcf, 0xb0, 0x0,
    0x0, 0x0, 0x0, 0x3, 0xbf, 0xb0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x1, 0x0, 0x0,

    /* U+F293 "" */
    0x0, 0x19, 0xcd, 0xa3, 0x0, 0x1, 0xef, 0xca,
    0xff, 0x30, 0x9, 0xff, 0xc0, 0xbf, 0xb0, 0xe,
    0xd8, 0xc5, 0x4d, 0xf0, 0xf, 0xf6, 0x43, 0x4f,
    0xf1, 0x1f, 0xff, 0x40, 0xef, 0xf2, 0xf, 0xfc,
    0x10, 0x8f, 0xf1, 0xf, 0xd2, 0xa6, 0x3b, 0xf0,
    0xb, 0xfe, 0xc2, 0x5f, 0xd0, 0x4, 0xff, 0xc5,
    0xff, 0x60, 0x0, 0x6e, 0xff, 0xf8, 0x0, 0x0,
    0x0, 0x12, 0x0, 0x0,

    /* U+F2ED "" */
    0x0, 0x8, 0xaa, 0x40, 0x0, 0xef, 0xff, 0xff,
    0xff, 0xf9, 0x56, 0x66, 0x66, 0x66, 0x63, 0x4f,
    0xff, 0xff, 0xff, 0xe0, 0x5f, 0xbf, 0xbe, 0xce,
    0xf0, 0x5f, 0x6e, 0x7d, 0x8c, 0xf0, 0x5f, 0x6e,
    0x7d, 0x8c, 0xf0, 0x5f, 0x6e, 0x7d, 0x8c, 0xf0,
    0x5f, 0x6e, 0x7d, 0x8c, 0xf0, 0x5f, 0x7e, 0x8d,
    0x9c, 0xf0, 0x4f, 0xff, 0xff, 0xff, 0xe0, 0x4,
    0x66, 0x66, 0x65, 0x20,

    /* U+F304 "" */
    0x0, 0x0, 0x0, 0x0, 0x18, 0x30, 0x0, 0x0,
    0x0, 0x0, 0xcf, 0xf4, 0x0, 0x0, 0x0, 0x15,
    0xaf, 0xfe, 0x0, 0x0, 0x1, 0xcf, 0x6a, 0xf9,
    0x0, 0x0, 0x1c, 0xff, 0xf6, 0x60, 0x0, 0x1,
    0xcf, 0xff, 0xf9, 0x0, 0x0, 0x1c, 0xff, 0xff,
    0x90, 0x0, 0x1, 0xcf, 0xff, 0xf9, 0x0, 0x0,
    0xa, 0xff, 0xff, 0x90, 0x0, 0x0, 0xd, 0xff,
    0xf9, 0x0, 0x0, 0x0, 0xf, 0xff, 0x90, 0x0,
    0x0, 0x0, 0x4, 0x42, 0x0, 0x0, 0x0, 0x0,

    /* U+F55A "" */
    0x0, 0x0, 0x34, 0x44, 0x44, 0x44, 0x30, 0x0,
    0x1d, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x1, 0xdf,
    0xff, 0xaf, 0xfb, 0xef, 0xfb, 0x1d, 0xff, 0xff,
    0x13, 0x90, 0x8f, 0xfc, 0xcf, 0xff, 0xff, 0xd1,
    0x6, 0xff, 0xfc, 0xaf, 0xff, 0xff, 0xa0, 0x3,
    0xff, 0xfc, 0xa, 0xff, 0xff, 0x6, 0xd1, 0x7f,
    0xfc, 0x0, 0xaf, 0xff, 0xdf, 0xfe, 0xff, 0xfb,
    0x0, 0x9, 0xff, 0xff, 0xff, 0xff, 0xf5,

    /* U+F7C2 "" */
    0x0, 0x36, 0x66, 0x63, 0x0, 0x4e, 0xff, 0xff,
    0xf2, 0x4f, 0x6b, 0xb, 0x2f, 0x4f, 0xf6, 0xb0,
    0xb2, 0xf4, 0xff, 0xff, 0xff, 0xff, 0x4f, 0xff,
    0xff, 0xff, 0xf4, 0xff, 0xff, 0xff, 0xff, 0x4f,
    0xff, 0xff, 0xff, 0xf4, 0xff, 0xff, 0xff, 0xff,
    0x4f, 0xff, 0xff, 0xff, 0xf4, 0xef, 0xff, 0xff,
    0xff, 0x22, 0x88, 0x88, 0x88, 0x40,

    /* U+F8A2 "" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x20, 0x0, 0x0,
    0x0, 0x0, 0x3, 0xf0, 0x0, 0xb6, 0x0, 0x0,
    0xa, 0xf0, 0xc, 0xf8, 0x11, 0x11, 0x1b, 0xf0,
    0xcf, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x6f, 0xfd,
    0xaa, 0xaa, 0xaa, 0x90, 0x5, 0xf7, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x43, 0x0, 0x0, 0x0, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 176, .box_w = 11, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 66, .adv_w = 176, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 127, .adv_w = 176, .box_w = 11, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 193, .adv_w = 176, .box_w = 11, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 243, .adv_w = 176, .box_w = 11, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 298, .adv_w = 176, .box_w = 11, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 348, .adv_w = 121, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 380, .adv_w = 176, .box_w = 12, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 452, .adv_w = 176, .box_w = 11, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 518, .adv_w = 198, .box_w = 13, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 583, .adv_w = 176, .box_w = 12, .box_h = 12, .ofs_x = -1, .ofs_y = -2},
    {.bitmap_index = 655, .adv_w = 198, .box_w = 13, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 714, .adv_w = 176, .box_w = 11, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 780, .adv_w = 88, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 810, .adv_w = 132, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 855, .adv_w = 198, .box_w = 13, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 933, .adv_w = 176, .box_w = 11, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 983, .adv_w = 154, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1027, .adv_w = 154, .box_w = 10, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1087, .adv_w = 154, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1137, .adv_w = 154, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1187, .adv_w = 154, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1231, .adv_w = 154, .box_w = 11, .box_h = 10, .ofs_x = -1, .ofs_y = -1},
    {.bitmap_index = 1286, .adv_w = 110, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1321, .adv_w = 110, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1356, .adv_w = 154, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1406, .adv_w = 154, .box_w = 10, .box_h = 3, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 1421, .adv_w = 198, .box_w = 13, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1480, .adv_w = 220, .box_w = 14, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1564, .adv_w = 198, .box_w = 14, .box_h = 12, .ofs_x = -1, .ofs_y = -2},
    {.bitmap_index = 1648, .adv_w = 176, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1709, .adv_w = 154, .box_w = 10, .box_h = 6, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 1739, .adv_w = 154, .box_w = 10, .box_h = 6, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 1769, .adv_w = 220, .box_w = 14, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1839, .adv_w = 176, .box_w = 11, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1889, .adv_w = 176, .box_w = 11, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1955, .adv_w = 176, .box_w = 12, .box_h = 12, .ofs_x = -1, .ofs_y = -2},
    {.bitmap_index = 2027, .adv_w = 154, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2077, .adv_w = 154, .box_w = 10, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 2137, .adv_w = 154, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2187, .adv_w = 110, .box_w = 8, .box_h = 12, .ofs_x = -1, .ofs_y = -2},
    {.bitmap_index = 2235, .adv_w = 154, .box_w = 10, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 2295, .adv_w = 154, .box_w = 10, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 2355, .adv_w = 198, .box_w = 13, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2414, .adv_w = 176, .box_w = 13, .box_h = 12, .ofs_x = -1, .ofs_y = -2},
    {.bitmap_index = 2492, .adv_w = 132, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 2546, .adv_w = 220, .box_w = 14, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2623, .adv_w = 220, .box_w = 14, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2679, .adv_w = 220, .box_w = 14, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2735, .adv_w = 220, .box_w = 14, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2791, .adv_w = 220, .box_w = 14, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2847, .adv_w = 220, .box_w = 14, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2903, .adv_w = 220, .box_w = 14, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2973, .adv_w = 154, .box_w = 10, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 3033, .adv_w = 154, .box_w = 10, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 3093, .adv_w = 176, .box_w = 12, .box_h = 12, .ofs_x = -1, .ofs_y = -2},
    {.bitmap_index = 3165, .adv_w = 220, .box_w = 14, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 3228, .adv_w = 132, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 3282, .adv_w = 177, .box_w = 12, .box_h = 8, .ofs_x = 0, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0x182c, 0x87fa, 0x8801, 0x8804, 0x8805, 0x8806, 0x880a,
    0x880c, 0x880e, 0x8812, 0x8815, 0x881a, 0x881f, 0x8820, 0x8821,
    0x8837, 0x8841, 0x8844, 0x8845, 0x8846, 0x884a, 0x884b, 0x884c,
    0x884d, 0x8860, 0x8861, 0x8867, 0x8869, 0x886a, 0x886d, 0x8870,
    0x8871, 0x8872, 0x8874, 0x888c, 0x888e, 0x88bd, 0x88be, 0x88c0,
    0x88e0, 0x88e3, 0x88ec, 0x8915, 0x891d, 0x8954, 0x89e4, 0x8a39,
    0x8a3a, 0x8a3b, 0x8a3c, 0x8a3d, 0x8a80, 0x8a8c, 0x8ae6, 0x8afd,
    0x8d53, 0x8fbb, 0x909b
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 26631, .range_length = 37020, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 59, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

/*Store all the custom data of the font*/
static lv_font_fmt_txt_dsc_t font_dsc = {
    .glyph_bitmap = gylph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 4,
    .kern_classes = 0,
    .bitmap_format = 0
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
lv_font_t lv_customer_font_simsun_11 = {
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 12,          /*The maximum line height required by the font*/
    .base_line = 2,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0)
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if LV_CUSTOMER_FONT_SIMSUN_11*/
