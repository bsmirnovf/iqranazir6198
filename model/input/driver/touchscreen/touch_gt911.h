/*
 * Copyright (c) 2020-2021 Huawei Device Co., Ltd.
 *
 * HDF is dual licensed: you can use it either under the terms of
 * the GPL, or the BSD license, at your option.
 * See the LICENSE file in the root of this repository for complete details.
 */

#ifndef TOUCH_GT911_H
#define TOUCH_GT911_H

/* the macro defines of GT911 */
#define MAX_SUPPORT_POINT     5
#define ONE_BYTE_MASK         0xFF
#define ONE_BYTE_OFFSET       8
#define GT_EVENT_UP           0x80
#define GT_EVENT_INVALID      0

#define GT_POINT_SIZE         8
#define GT_TRACK_ID           0
#define GT_X_LOW              1
#define GT_X_HIGH             2
#define GT_Y_LOW              3
#define GT_Y_HIGH             4
#define GT_ADDR_LEN           2
#define GT_BUF_STATE_ADDR     0x814E
#define GT_X_LOW_BYTE_BASE    0x814F
#define GT_FINGER_NUM_MASK    0x0F
#define GT_CLEAN_DATA_LEN     3
#define GT_REG_HIGH_POS       0
#define GT_REG_LOW_POS        1
#define GT_CLEAN_POS          2
#define GT_CLEAN_FLAG         0x0
/* Config info macro of GT911 */
#define GT_CFG_INFO_ADDR      0x8140
#define GT_CFG_INFO_LEN       10
#define GT_PROD_ID_1ST        0
#define GT_PROD_ID_2ND        1
#define GT_PROD_ID_3RD        2
#define GT_PROD_ID_4TH        3
#define GT_FW_VER_LOW         4
#define GT_FW_VER_HIGH        5
#define GT_SOLU_X_LOW         6
#define GT_SOLU_X_HIGH        7
#define GT_SOLU_Y_LOW         8
#define GT_SOLU_Y_HIGH        9
#if defined(CONFIG_ARCH_ROCKCHIP)
#define FIRMWARE_LEN          241
#define GTP_REG_CONFIG_DATA         0x8050
#else
#define FIRMWARE_LEN          188
#endif
#if defined(CONFIG_ARCH_ROCKCHIP)
uint8_t firmWareParm[FIRMWARE_LEN] = {
    0x80,0x50,0x64,0xD0,0x02,0x00,0x05,0x05,0x05,0x00,0x01,0x00,  /* 0x8050 is reg, GTP_REG_CONFIG_DATA */
	0x00,0x0F,0x46,0x2D,0x53,0x11,0x00,0x00,0x50,0x11,
	0x14,0x14,0x14,0x20,0x0A,0x04,0x00,0x00,0x00,0x00,
	0x00,0x00,0x53,0x00,0x14,0x00,0x00,0x00,0x00,0x00,
	0x3C,0x00,0x14,0x64,0x1E,0x28,0x8C,0x0C,0x0E,0x37,
	0x39,0x09,0x06,0x20,0x37,0x20,0x12,0x03,0x24,0x00,
	0x00,0x19,0x6E,0x80,0x14,0x02,0x00,0x00,0x54,0xB2,
	0x27,0x84,0x35,0x6A,0x43,0x59,0x51,0x4E,0x5F,0x4E,
	0x00,0x00,0x00,0x10,0x28,0x48,0x00,0xF0,0x4A,0x3A,
	0xFF,0xF0,0x27,0x05,0x00,0x00,0x00,0x00,0x00,0x03,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x32,0x20,0x50,0x3C,0x3C,0x00,0x00,0x00,0x00,0x00,
	0x0D,0x06,0x0C,0x05,0x0B,0x04,0x0A,0x03,0x09,0x02,
	0x08,0x01,0x07,0x00,0x00,0x01,0x02,0x03,0x04,0x05,
	0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,
	0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x3C,0x00,0x05,0x1E,0x00,0x02,
	0x2A,0x1E,0x19,0x14,0x02,0x00,0x03,0x0A,0x05,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x04,
	0x22,0x03,0x00,0x00,0x33,0x00,0x0F,0x00,0x00,0x28,
	0x50,0x3C,0x50,0x00,0x00,0x05,0x5F,0xEB,0x01
};
#else
uint8_t firmWareParm[FIRMWARE_LEN] = {
    0x80, 0x47, 0x45, 0xC0, 0x03, 0xE0, 0x01, 0x05, 0x3D, 0x00, 0x01, 0x08, 0x28, 0x0F,
    0x50, 0x32, 0x03, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x1A, 0x1E,
    0x14, 0x86, 0x26, 0x08, 0x55, 0x57, 0xB2, 0x04, 0x00, 0x00, 0x00, 0x42, 0x02, 0x11,
    0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3C, 0x78, 0x94,
    0xD5, 0x02, 0x07, 0x00, 0x00, 0x04, 0x97, 0x40, 0x00, 0x8A, 0x4A, 0x00, 0x80, 0x55,
    0x00, 0x77, 0x61, 0x00, 0x6F, 0x70, 0x00, 0x6F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x10, 0x0E, 0x0C, 0x0A, 0x08, 0x06, 0x04, 0x02, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x22, 0x21, 0x20, 0x1F, 0x1E, 0x1D, 0x00, 0x02, 0x04, 0x06,
    0x08, 0x0A, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x5C, 0x01
};
#endif
#endif