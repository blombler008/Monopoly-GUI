/**
 * @file floating_back_button_gen.h
 */

#ifndef LVGL_PRO_FLOATING_BACK_BUTTON_GEN_H
#define LVGL_PRO_FLOATING_BACK_BUTTON_GEN_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
    #include "lvgl_private.h"
#else
    #include "lvgl/lvgl.h"
    #include "lvgl/lvgl_private.h"
#endif

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

lv_obj_t * floating_back_button_create(lv_obj_t * parent, const char * tag, int32_t button_type);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LVGL_PRO_FLOATING_BACK_BUTTON_GEN_H*/