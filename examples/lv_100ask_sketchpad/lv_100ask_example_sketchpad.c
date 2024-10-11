
/**
 * @file lv_100ask_example_sketchpad.c
 *
 */



/*********************
 *      INCLUDES
 *********************/
#include "lv_100ask_example_sketchpad.h"

#if LV_100ASK_SKETCHPAD_SIMPLE_TEST != 0

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/



/**********************
 *  STATIC PROTOTYPES
 **********************/
static void event_handler(lv_event_t * e);

/**********************
 *  STATIC VARIABLES
 **********************/


/**********************
 *      MACROS
 **********************/


/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lv_100ask_sketchpad_simple_test(void)
{
    LV_DRAW_BUF_DEFINE(draw_buf, SKETCHPAD_DEFAULT_WIDTH, SKETCHPAD_DEFAULT_HEIGHT, LV_COLOR_FORMAT_ARGB8888);
	lv_obj_t * sketchpad = lv_100ask_sketchpad_create(lv_screen_active());

	lv_canvas_set_draw_buf(sketchpad, &draw_buf);
    lv_obj_center(sketchpad);
    lv_canvas_fill_bg(sketchpad, lv_color_white(), LV_OPA_COVER);

    lv_obj_add_event_cb(sketchpad, event_handler, LV_EVENT_VALUE_CHANGED, NULL);

}


/*=====================
 * Other functions
 *====================*/

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void event_handler(lv_event_t * e)
{
    lv_obj_t * sketchpad = lv_event_get_target(e);

    void * canvas_buf = lv_canvas_get_buf(sketchpad);
    lv_draw_buf_t * canvas_draw_buf = lv_canvas_get_draw_buf(sketchpad);

    LV_LOG_USER("LV_EVENT_VALUE_CHANGED");

}


#endif  /*SIMPLE_TEST*/
