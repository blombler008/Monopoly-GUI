/**
 * @file generalSettingsCard_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "generalSettingsCard_gen.h"
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

lv_obj_t * generalSettingsCard_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_main);

        lv_style_set_width(&style_main, LV_SIZE_CONTENT);
        lv_style_set_height(&style_main, LV_SIZE_CONTENT);

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if MONOPOLY_CHECK_COMPILE_TARGET(MONOPOLY_TARGET_ALL)
    if (Monopoly_check_target(MONOPOLY_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(parent);
        lv_obj_set_name_static(lv_obj_0, "generalSettingsCard_#");

        lv_obj_remove_style(lv_obj_0, NULL, 0);
        lv_obj_add_style(lv_obj_0, &style_main, 0);
        lv_obj_t * card_0 = card_create(lv_obj_0);
        lv_obj_t * row_0 = row_create(card_0);
        lv_obj_t * label_0 = label_create(row_0, "");
        lv_label_set_translation_tag(label_0, "general_settings");

        lv_obj_t * row_1 = row_create(card_0);
        lv_obj_set_width(row_1, lv_pct(100));
        lv_obj_set_style_layout(row_1, LV_LAYOUT_NONE, 0);
        lv_obj_t * label_1 = label_create(row_1, "");
        lv_label_set_translation_tag(label_1, "language");
        lv_obj_set_align(label_1, LV_ALIGN_LEFT_MID);

        lv_obj_t * div_0 = div_create(row_1);
        lv_obj_set_width(div_0, 100);
        lv_obj_set_align(div_0, LV_ALIGN_RIGHT_MID);
        lv_obj_set_style_layout(div_0, LV_LAYOUT_FLEX, 0);
        lv_obj_set_flex_flow(div_0, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_flex_main_place(div_0, LV_FLEX_ALIGN_SPACE_BETWEEN, 0);
        lv_obj_set_style_pad_hor(div_0, 8, 0);
        lv_obj_t * button_0 = button_create(div_0, "EN", 1);
        lv_obj_add_subject_set_int_event(button_0, &language, LV_EVENT_CLICKED, 0);

        lv_obj_t * button_1 = button_create(div_0, "DE", 1);
        lv_obj_add_subject_set_int_event(button_1, &language, LV_EVENT_CLICKED, 1);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

