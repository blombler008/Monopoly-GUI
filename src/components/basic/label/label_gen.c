/**
 * @file label_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "label_gen.h"
#include "Monopoly.h"

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

lv_obj_t * label_create(lv_obj_t * parent, const char * tag)
{
    LV_TRACE_OBJ_CREATE("begin");

    lv_obj_t * lv_label_0 = lv_label_create(parent);
    lv_obj_set_name_static(lv_label_0, "label_#");
    lv_label_set_translation_tag(lv_label_0, tag);

    lv_obj_add_style(lv_label_0, &style_text, 0);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_label_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

