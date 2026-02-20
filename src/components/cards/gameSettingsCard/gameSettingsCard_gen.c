/**
 * @file gameSettingsCard_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "gameSettingsCard_gen.h"
#include "../../../Monopoly.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/***********************
 *  STATIC VARIABLES
 **********************/

/***********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * gameSettingsCard_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_main);
        lv_style_set_width(&style_main, LV_SIZE_CONTENT);
        lv_style_set_height(&style_main, LV_SIZE_CONTENT);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(parent);
    lv_obj_set_name_static(lv_obj_0, "gameSettingsCard_#");

    lv_obj_remove_style(lv_obj_0, NULL, 0);
    lv_obj_add_style(lv_obj_0, &style_main, 0);
    lv_obj_t * card_0 = card_create(lv_obj_0);
    lv_obj_t * row_0 = row_create(card_0);
    lv_obj_t * label_0 = label_create(row_0, " ");
    lv_label_set_translation_tag(label_0, "game_settings");
    
    lv_obj_t * row_1 = row_create(card_0);
    lv_obj_set_width(row_1, lv_pct(100));
    lv_obj_set_style_layout(row_1, LV_LAYOUT_NONE, 0);
    lv_obj_t * label_1 = label_create(row_1, " ");
    lv_label_set_translation_tag(label_1, "player_count");
    lv_obj_set_align(label_1, LV_ALIGN_LEFT_MID);
    
    lv_obj_t * spin_label_0 = spin_label_create(row_1, &player_count, 8, 2);
    lv_obj_set_align(spin_label_0, LV_ALIGN_RIGHT_MID);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

