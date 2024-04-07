
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
#if 0
    static lv_color_t cbuf[LV_CANVAS_BUF_SIZE_TRUE_COLOR(SKETCHPAD_DEFAULT_WIDTH, SKETCHPAD_DEFAULT_HEIGHT)];
	lv_obj_t * sketchpad = lv_100ask_sketchpad_create(lv_screen_active());

	lv_canvas_set_buffer(sketchpad, cbuf, SKETCHPAD_DEFAULT_WIDTH, SKETCHPAD_DEFAULT_HEIGHT, LV_IMG_CF_TRUE_COLOR);
    lv_obj_center(sketchpad);
    lv_canvas_fill_bg(sketchpad, lv_palette_lighten(LV_PALETTE_GREY, 3), LV_OPA_COVER);
#endif
    LV_DRAW_BUF_DEFINE(draw_buf, SKETCHPAD_DEFAULT_WIDTH, SKETCHPAD_DEFAULT_HEIGHT, LV_COLOR_FORMAT_ARGB8888);
	lv_obj_t * sketchpad = lv_100ask_sketchpad_create(lv_screen_active());

	lv_canvas_set_draw_buf(sketchpad, &draw_buf);
    lv_obj_center(sketchpad);
    lv_canvas_fill_bg(sketchpad, lv_palette_lighten(LV_PALETTE_GREY, 3), LV_OPA_COVER);
#if 0
    lv_layer_t layer;
    lv_canvas_init_layer(sketchpad, &layer);

    lv_draw_line_dsc_t dsc;
    lv_draw_line_dsc_init(&dsc);
    dsc.color = lv_palette_main(LV_PALETTE_RED);
    dsc.width = 4;
    dsc.round_end = 1;
    dsc.round_start = 1;
    dsc.p1.x = 15;
    dsc.p1.y = 15;
    dsc.p2.x = 35;
    dsc.p2.y = 10;
    lv_draw_line(&layer, &dsc);

    lv_canvas_finish_layer(sketchpad, &layer);
#endif

}


/*=====================
 * Other functions
 *====================*/

/**********************
 *   STATIC FUNCTIONS
 **********************/


#endif  /*SIMPLE_TEST*/
