
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
    lv_canvas_fill_bg(sketchpad, lv_palette_lighten(LV_PALETTE_GREY, 3), LV_OPA_COVER);

}


/*=====================
 * Other functions
 *====================*/

/**********************
 *   STATIC FUNCTIONS
 **********************/


#endif  /*SIMPLE_TEST*/
