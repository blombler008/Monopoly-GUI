/**
 * @file game_start_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "game_start_gen.h"
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

lv_obj_t * game_start_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static bool screen_created = false;
    if (screen_created) {
        LV_LOG_WARN("`game_start` is already initialized as a permanent screen. Returning with no change.");
        return game_start;
    }


    lv_obj_t * the_root = NULL;

    #if MONOPOLY_CHECK_COMPILE_TARGET(MONOPOLY_TARGET_ALL)
    if (Monopoly_check_target(MONOPOLY_TARGET_ALL)) {
        game_start = lv_obj_create(NULL);
        lv_obj_t * lv_obj_0 = game_start;
        lv_obj_set_name_static(lv_obj_0, "game_start_#");
        lv_obj_set_style_bg_color(lv_obj_0, BG_PRIMARY_DARK, 0);

        lv_obj_t * header_1 = header_create(lv_obj_0, "banking");
        lv_obj_set_name(header_1, "header_1");

        lv_obj_t * content_1 = content_create(lv_obj_0);
        lv_obj_set_name(content_1, "content_1");
        lv_obj_t * deposit_card = card_create(content_1);
        lv_obj_set_name(deposit_card, "deposit_card");
        label_create(deposit_card, "deposit");

        lv_obj_t * withdraw_card = card_create(content_1);
        lv_obj_set_name(withdraw_card, "withdraw_card");
        label_create(withdraw_card, "withdraw");

        lv_obj_t * transfer_card = card_create(content_1);
        lv_obj_set_name(transfer_card, "transfer_card");
        label_create(transfer_card, "transfer");

        the_root = lv_obj_0;
    }
    #endif

    if (the_root) screen_created = true;

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

