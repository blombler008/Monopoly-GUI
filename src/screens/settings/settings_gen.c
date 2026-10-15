/**
 * @file settings_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "settings_gen.h"
#include "../../Monopoly.h"

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

lv_obj_t * settings_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if MONOPOLY_CHECK_COMPILE_TARGET(MONOPOLY_TARGET_ALL)
    if (Monopoly_check_target(MONOPOLY_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "settings_#");

        header_create(lv_obj_0, "settings");

        lv_obj_t * content_0 = content_create(lv_obj_0);
        playerSettingsCard_create(content_0);

        lv_obj_t * row_0 = row_create(content_0);
        lv_obj_set_style_pad_column(row_0, UNIT_XL, 0);
        lv_obj_t * button_0 = button_create(row_0, "back", 2);
        lv_obj_add_screen_create_event(button_0, LV_EVENT_CLICKED, welcome_create, LV_SCREEN_LOAD_ANIM_NONE, 0, 0);

        lv_obj_t * button_1 = button_create(row_0, "about", 2);
        lv_obj_add_screen_create_event(button_1, LV_EVENT_CLICKED, about_create, LV_SCREEN_LOAD_ANIM_NONE, 0, 0);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

