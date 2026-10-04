/**
 * @file welcome_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "welcome_gen.h"
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

lv_obj_t * welcome_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static bool screen_created = false;
    if (screen_created) {
        LV_LOG_WARN("`welcome` is already initialized as a permanent screen. Returning with no change.");
        return welcome;
    }


    lv_obj_t * the_root = NULL;

    #if MONOPOLY_CHECK_COMPILE_TARGET(MONOPOLY_TARGET_ALL)
    if (Monopoly_check_target(MONOPOLY_TARGET_ALL)) {
        welcome = lv_obj_create(NULL);
        lv_obj_t * lv_obj_0 = welcome;
        lv_obj_set_name_static(lv_obj_0, "welcome_#");

        header_create(lv_obj_0, "title");

        lv_obj_t * content_0 = content_create(lv_obj_0);
        lv_obj_t * card_0 = card_create(content_0);
        lv_obj_t * label_0 = label_create(card_0, "text_welcome");
        lv_obj_set_width(label_0, lv_pct(100));
        lv_obj_set_style_text_align(label_0, LV_TEXT_ALIGN_CENTER, 0);
        lv_obj_set_style_text_font(label_0, RobotoB_24, 0);
        lv_obj_set_style_text_letter_space(label_0, 2, 0);

        lv_obj_t * label_1 = label_create(card_0, "text_welcome_info");
        lv_obj_set_width(label_1, lv_pct(100));
        lv_obj_set_style_text_align(label_1, LV_TEXT_ALIGN_CENTER, 0);

        lv_obj_t * button_0 = button_create(content_0, "game_start", 1);
        lv_obj_add_screen_load_event(button_0, LV_EVENT_CLICKED, game_start, LV_SCREEN_LOAD_ANIM_NONE, 0, 0);

        lv_obj_t * card_1 = card_create(content_0);
        lv_obj_t * row_0 = row_create(card_1);
        lv_obj_set_width(row_0, lv_pct(100));
        lv_obj_set_style_layout(row_0, LV_LAYOUT_NONE, 0);
        lv_obj_t * label_2 = label_create(row_0, "gameinfo_display");
        lv_obj_set_align(label_2, LV_ALIGN_LEFT_MID);

        lv_obj_t * button_1 = button_create(row_0, "settings", 0);
        lv_obj_set_align(button_1, LV_ALIGN_RIGHT_MID);
        lv_obj_add_screen_load_event(button_1, LV_EVENT_CLICKED, settings, LV_SCREEN_LOAD_ANIM_NONE, 0, 0);

        lv_obj_t * row_1 = row_create(card_1);
        lv_obj_set_width(row_1, lv_pct(100));
        lv_obj_set_style_layout(row_1, LV_LAYOUT_NONE, 0);
        lv_obj_t * label_3 = label_create(row_1, "players");
        lv_obj_set_align(label_3, LV_ALIGN_LEFT_MID);

        lv_obj_t * label_4 = label_create(row_1, "");
        lv_label_bind_text(label_4, &player_count, NULL);
        lv_obj_set_align(label_4, LV_ALIGN_RIGHT_MID);

        lv_obj_t * row_2 = row_create(card_1);
        lv_obj_set_width(row_2, lv_pct(100));
        lv_obj_set_style_layout(row_2, LV_LAYOUT_NONE, 0);
        label_create(row_2, "start_cash");

        lv_obj_t * lv_label_0 = lv_label_create(row_2);
        lv_label_bind_text(lv_label_0, &start_cash, "M %d");
        lv_obj_set_align(lv_label_0, LV_ALIGN_RIGHT_MID);
        lv_obj_add_style(lv_label_0, &style_text, 0);

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

