/**
 * @file Monopoly_gen.h
 */

#ifndef MONOPOLY_GEN_H
#define MONOPOLY_GEN_H

#ifndef UI_SUBJECT_STRING_LENGTH
#define UI_SUBJECT_STRING_LENGTH 256
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif



/*********************
 *      DEFINES
 *********************/

#define UNIT_SM 6

#define UNIT_MD 12

#define UNIT_LG 18

#define UNIT_XL 24

#define OPA_MUTED lv_pct(20)

#define TEXT_COLOR lv_color_hex(0xdddddd)

#define TEXT_COLOR_DARK lv_color_hex(0x0e0e0e)

#define LIGHT lv_color_hex(0xffffff)

#define DARK lv_color_hex(0x0e0e0e)

#define SURFACE_PRIMARY_LIGHT lv_color_hex(0x0e0e0e)

#define TEXT_ON_SURFACE_PRIMARY_LIGHT lv_color_hex(0xffffff)

#define SURFACE_PRIMARY_DARK lv_color_hex(0xffffff)

#define TEXT_ON_SURFACE_PRIMARY_DARK lv_color_hex(0x0e0e0e)

#define BG_PRIMARY_LIGHT lv_color_hex(0xffffff)

#define BG_PRIMARY_DARK lv_color_hex(0x0e0e0e)

#define BG_SECONDARY_LIGHT lv_color_hex(0xf0f0f0)

#define BG_SECONDARY_DARK lv_color_hex(0x373130)

#define BG_TERTIARY_LIGHT lv_color_hex(0xf0f0f0)

#define BG_TERTIARY_DARK lv_color_hex(0x373130)

#define ACCENT1_LIGHT lv_color_hex(0xAF4ADE)

#define ACCENT1_DARK lv_color_hex(0xAF4ADE)

#define ACCENT1_50_LIGHT lv_color_hex(0xD2B1F6)

#define ACCENT1_50_DARK lv_color_hex(0x7E4CB7)

#define ACCENT2_LIGHT lv_color_hex(0xe9deaf)

#define ACCENT2_DARK lv_color_hex(0x887A3D)

#define ACCENT2_50_LIGHT lv_color_hex(0xf3f0e7)

#define ACCENT2_50_DARK lv_color_hex(0x4A473E)

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL VARIABLES
 **********************/

/*-------------------
 * Permanent screens
 *------------------*/

extern lv_obj_t * game_start;
extern lv_obj_t * settings;
extern lv_obj_t * welcome;

/*----------------
 * Global styles
 *----------------*/

extern lv_style_t style_text;
extern lv_style_t style_text_dark;

/*----------------
 * Fonts
 *----------------*/

extern lv_font_t * Roboto_16;

extern lv_font_t * Roboto_24;

extern lv_font_t * RobotoB_16;

extern lv_font_t * RobotoB_24;

/*----------------
 * Images
 *----------------*/

extern const void * bluetooth;
extern const void * wifi;
extern const void * nfc;

/*----------------
 * Subjects
 *----------------*/

extern lv_subject_t start_cash;
extern lv_subject_t player_count;
extern lv_subject_t bluetooth_on;
extern lv_subject_t wifi_on;
extern lv_subject_t nfc_on;
extern lv_subject_t battery_level;
extern lv_subject_t time_minutes;
extern lv_subject_t time_hours;
extern lv_subject_t button_sec;
extern lv_subject_t button_pri;
extern lv_subject_t button_invis;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/*----------------
 * Event Callbacks
 *----------------*/

/**
 * Initialize the component library
 */

void Monopoly_init_gen(const char * asset_path);

/**********************
 *      MACROS
 **********************/

/**********************
 *   POST INCLUDES
 **********************/

/*Include all the widgets, components and screens of this library*/
#include "components/basic/button/button_gen.h"
#include "components/basic/card/card_gen.h"
#include "components/basic/column/column_gen.h"
#include "components/basic/content/content_gen.h"
#include "components/basic/div/div_gen.h"
#include "components/basic/header/header_gen.h"
#include "components/basic/label/label_gen.h"
#include "components/basic/row/row_gen.h"
#include "components/basic/spin_box/spin_box_gen.h"
#include "components/basic/spin_label/spin_label_gen.h"
#include "components/basic/timehead/timehead_gen.h"
#include "components/cards/audioSettingsCard/audioSettingsCard_gen.h"
#include "components/cards/connectionSettingsCard/connectionSettingsCard_gen.h"
#include "components/cards/gameSettingsCard/gameSettingsCard_gen.h"
#include "components/cards/playerSettingsCard/playerSettingsCard_gen.h"
#include "screens/about/about_gen.h"
#include "screens/add_card/add_card_gen.h"
#include "screens/game_start/game_start_gen.h"
#include "screens/settings/settings_gen.h"
#include "screens/welcome/welcome_gen.h"

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*MONOPOLY_GEN_H*/