/**
 * @file player_list_item_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "player_list_item_gen.h"
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

lv_obj_t * player_list_item_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t icon_button_style;
    static lv_style_t row_style;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&icon_button_style);
        lv_style_init(&row_style);

        lv_style_set_width(&icon_button_style, 32);
        lv_style_set_height(&icon_button_style, 32);
        lv_style_set_bg_opa(&icon_button_style, 0);
        lv_style_set_width(&row_style, lv_pct(100));
        lv_style_set_height(&row_style, LV_SIZE_CONTENT);
        lv_style_set_pad_all(&row_style, 4);
        lv_style_set_layout(&row_style, LV_LAYOUT_FLEX);
        lv_style_set_flex_flow(&row_style, LV_FLEX_FLOW_ROW);
        lv_style_set_flex_main_place(&row_style, LV_FLEX_ALIGN_SPACE_BETWEEN);
        lv_style_set_flex_cross_place(&row_style, LV_FLEX_ALIGN_CENTER);

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if MONOPOLY_CHECK_COMPILE_TARGET(MONOPOLY_TARGET_ALL)
    if (Monopoly_check_target(MONOPOLY_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(parent);
        lv_obj_set_name_static(lv_obj_0, "player_list_item_#");

        lv_obj_remove_style_all(lv_obj_0);
        lv_obj_add_style(lv_obj_0, &row_style, 0);
        lv_obj_t * player_name_label = label_create(lv_obj_0, "");
        lv_obj_set_name(player_name_label, "player_name_label");
        lv_label_set_text(player_name_label, "player_name");
        lv_obj_set_width(player_name_label, 140);

        lv_obj_t * player_settings_btn = button_create(lv_obj_0, " ", 2);
        lv_obj_set_name(player_settings_btn, "player_settings_btn");
        lv_obj_add_style(player_settings_btn, &icon_button_style, 0);
        lv_obj_t * lv_image_0 = lv_image_create(player_settings_btn);
        lv_image_set_src(lv_image_0, icon_settings);
        lv_obj_set_align(lv_image_0, LV_ALIGN_CENTER);

        lv_obj_t * player_delete_btn = button_create(lv_obj_0, " ", 2);
        lv_obj_set_name(player_delete_btn, "player_delete_btn");
        lv_obj_add_style(player_delete_btn, &icon_button_style, 0);
        lv_obj_t * lv_image_1 = lv_image_create(player_delete_btn);
        lv_image_set_src(lv_image_1, icon_delete);
        lv_obj_set_align(lv_image_1, LV_ALIGN_CENTER);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

