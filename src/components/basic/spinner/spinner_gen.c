/**
 * @file spinner_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "spinner_gen.h"
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

lv_obj_t * spinner_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");

    lv_obj_t * lv_obj_0 = lv_obj_create(parent);
    lv_obj_set_name_static(lv_obj_0, "spinner_#");
    lv_obj_set_height(lv_obj_0, 100);
    lv_obj_set_width(lv_obj_0, 100);

    lv_obj_remove_style_all(lv_obj_0);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

