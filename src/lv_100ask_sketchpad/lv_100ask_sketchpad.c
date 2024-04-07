/**
 * @file lv_100ask_sketchpad.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "lv_100ask_sketchpad.h"

#if LV_USE_100ASK_SKETCHPAD != 0

/*********************
 *      DEFINES
 *********************/
#define MY_CLASS &lv_100ask_sketchpad_class
/**********************
 *      TYPEDEFS
 **********************/


/**********************
 *  STATIC PROTOTYPES
 **********************/
static void lv_100ask_sketchpad_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void lv_100ask_sketchpad_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void lv_100ask_sketchpad_toolbar_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void lv_100ask_sketchpad_toolbar_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void lv_100ask_sketchpad_event(const lv_obj_class_t * class_p, lv_event_t * e);
static void lv_100ask_sketchpad_toolbar_event(const lv_obj_class_t * class_p, lv_event_t * e);
static void sketchpad_toolbar_event_cb(lv_event_t * e);
static void toolbar_set_event_cb(lv_event_t * e);

/**********************
 *  STATIC VARIABLES
 **********************/
const lv_obj_class_t lv_100ask_sketchpad_class = {
    .constructor_cb = lv_100ask_sketchpad_constructor,
    .destructor_cb = lv_100ask_sketchpad_destructor,
    .event_cb = lv_100ask_sketchpad_event,
    .instance_size = sizeof(lv_100ask_sketchpad_t),
    .base_class = &lv_image_class,
    .name = "sketchpad",
};

const lv_obj_class_t lv_100ask_sketchpad_toolbar_class = {
    .constructor_cb = lv_100ask_sketchpad_toolbar_constructor,
    .destructor_cb = lv_100ask_sketchpad_toolbar_destructor,
    .event_cb = lv_100ask_sketchpad_toolbar_event,
    .width_def = LV_SIZE_CONTENT,
    .height_def = LV_SIZE_CONTENT,
    .base_class = &lv_obj_class,
    .name = "sketchpad_toolbar",
};

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * lv_100ask_sketchpad_create(lv_obj_t * parent)
{
    LV_LOG_INFO("begin");
    lv_obj_t * obj = lv_obj_class_create_obj(MY_CLASS, parent);
    lv_obj_class_init_obj(obj);
    return obj;
}


/*=====================
 * Other functions
 *====================*/

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void lv_100ask_sketchpad_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);
    LV_TRACE_OBJ_CREATE("begin");

    lv_100ask_sketchpad_t * sketchpad = (lv_100ask_sketchpad_t *)obj;

    lv_draw_line_dsc_init(&sketchpad->line_rect_dsc);
    sketchpad->line_rect_dsc.width = 10;
    sketchpad->line_rect_dsc.round_start = true;
    sketchpad->line_rect_dsc.round_end = true;
    sketchpad->line_rect_dsc.color = lv_palette_main(LV_PALETTE_RED);
    //sketchpad->line_rect_dsc.opa = LV_OPA_COVER;

    lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);

    /*toolbar*/
    ///lv_obj_t * toolbar = lv_obj_class_create_obj(&lv_100ask_sketchpad_toolbar_class, obj); TODO
    ///lv_obj_class_init_obj(toolbar);

    LV_TRACE_OBJ_CREATE("finished");
}


static void lv_100ask_sketchpad_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);
    LV_TRACE_OBJ_CREATE("begin");

    lv_canvas_t * canvas = (lv_canvas_t *)obj;
    if(canvas->draw_buf == NULL) return;

    lv_image_cache_drop(&canvas->draw_buf);
}


static void lv_100ask_sketchpad_event(const lv_obj_class_t * class_p, lv_event_t * e)
{
    LV_UNUSED(class_p);

    lv_res_t res;

    /*Call the ancestor's event handler*/
    res = lv_obj_event_base(MY_CLASS, e);
    if(res != LV_RES_OK) return;

    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);
    lv_100ask_sketchpad_t * sketchpad = (lv_100ask_sketchpad_t *)obj;

    static lv_coord_t last_x, last_y = -32768;

    if (code == LV_EVENT_PRESSING)
    {
        lv_indev_t * indev = lv_indev_active();
        if(indev == NULL)  return;

        lv_point_t point;
        lv_point_t vect;

        lv_indev_get_point(indev, &point);

        /*Release or first use*/
        if ((last_x != -32768) || (last_y != -32768))
        {
            lv_canvas_set_px(obj, point.x, point.y, lv_palette_main(LV_PALETTE_RED), LV_OPA_COVER);
        }

        last_x = point.x;
        last_y = point.y;
    }

    /*Loosen the brush*/
    else if(code == LV_EVENT_RELEASED)
    {
        last_x = -32768;
        last_y = -32768;
    }
}



/*toolbar*/
static void lv_100ask_sketchpad_toolbar_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);
    LV_TRACE_OBJ_CREATE("begin");

    lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_align(obj, LV_ALIGN_TOP_MID, 0, 0);
    lv_obj_set_flex_grow(obj, 1);
    lv_obj_set_flex_flow(obj, LV_FLEX_FLOW_ROW);

    static lv_coord_t sketchpad_toolbar_cw = LV_100ASK_SKETCHPAD_TOOLBAR_OPT_CW;
    lv_obj_t * color = lv_label_create(obj);
    lv_label_set_text(color, LV_SYMBOL_EDIT);
    lv_obj_add_flag(color, LV_OBJ_FLAG_CLICKABLE);
    ///lv_obj_add_event_cb(color, sketchpad_toolbar_event_cb, LV_EVENT_ALL, &sketchpad_toolbar_cw); TODO

    static lv_coord_t sketchpad_toolbar_width = LV_100ASK_SKETCHPAD_TOOLBAR_OPT_WIDTH;
    lv_obj_t * size = lv_label_create(obj);
    lv_label_set_text(size, LV_SYMBOL_EJECT);
    lv_obj_add_flag(size, LV_OBJ_FLAG_CLICKABLE);
    ///lv_obj_add_event_cb(size, sketchpad_toolbar_event_cb, LV_EVENT_ALL, &sketchpad_toolbar_width); TODO

    LV_TRACE_OBJ_CREATE("finished");
}


static void lv_100ask_sketchpad_toolbar_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{

}


static void lv_100ask_sketchpad_toolbar_event(const lv_obj_class_t * class_p, lv_event_t * e)
{
    LV_UNUSED(class_p);

    lv_res_t res;

    /*Call the ancestor's event handler*/
    res = lv_obj_event_base(MY_CLASS, e);
    if(res != LV_RES_OK) return;

    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);

    if (code == LV_EVENT_PRESSING)
    {
        lv_indev_t * indev = lv_indev_get_act();
        if(indev == NULL)  return;

        lv_point_t vect;
        lv_indev_get_vect(indev, &vect);

        lv_coord_t x = lv_obj_get_x(obj) + vect.x;
        lv_coord_t y = lv_obj_get_y(obj) + vect.y;
        lv_obj_set_pos(obj, x, y);
    }
}

static void sketchpad_toolbar_event_cb(lv_event_t * e)
{
    lv_coord_t *toolbar_opt = lv_event_get_user_data(e);
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);
    lv_obj_t * toolbar= lv_obj_get_parent(obj);
    lv_obj_t * sketchpad= lv_obj_get_parent(toolbar);
    lv_100ask_sketchpad_t * sketchpad_t = (lv_100ask_sketchpad_t *)sketchpad;


    if (code == LV_EVENT_CLICKED)
    {
        if ((*toolbar_opt) == LV_100ASK_SKETCHPAD_TOOLBAR_OPT_CW)
        {
            static lv_coord_t sketchpad_toolbar_cw = LV_100ASK_SKETCHPAD_TOOLBAR_OPT_CW;
            ///lv_obj_t * cw = lv_colorwheel_create(sketchpad, true); TODO
            ///lv_obj_align_to(cw, obj, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
            ///lv_obj_add_event_cb(cw, toolbar_set_event_cb, LV_EVENT_RELEASED, &sketchpad_toolbar_cw);
        }
        else if((*toolbar_opt) == LV_100ASK_SKETCHPAD_TOOLBAR_OPT_WIDTH)
        {
            static lv_coord_t sketchpad_toolbar_width = LV_100ASK_SKETCHPAD_TOOLBAR_OPT_WIDTH;
            lv_obj_t * slider = lv_slider_create(sketchpad);
            lv_slider_set_value(slider, (int32_t)(sketchpad_t->line_rect_dsc.width), LV_ANIM_OFF);
            lv_obj_align_to(slider, obj, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
            lv_obj_add_event_cb(slider, toolbar_set_event_cb, LV_EVENT_ALL, &sketchpad_toolbar_width);
        }
    }
}

static void toolbar_set_event_cb(lv_event_t * e)
{
	lv_coord_t *toolbar_opt = lv_event_get_user_data(e);
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);
    lv_100ask_sketchpad_t * sketchpad = (lv_100ask_sketchpad_t *)lv_obj_get_parent(obj);

    if (code == LV_EVENT_RELEASED)
    {
        if ((*toolbar_opt) == LV_100ASK_SKETCHPAD_TOOLBAR_OPT_CW)
        {
            ///sketchpad->line_rect_dsc.color = lv_colorwheel_get_rgb(obj);  TODO
            lv_obj_del(obj);
        }
        else if (*(toolbar_opt) == LV_100ASK_SKETCHPAD_TOOLBAR_OPT_WIDTH)
        {
            lv_obj_del(obj);
        }
    }
    else if (code == LV_EVENT_VALUE_CHANGED)
    {
        if((*toolbar_opt) == LV_100ASK_SKETCHPAD_TOOLBAR_OPT_WIDTH)
        {
            sketchpad->line_rect_dsc.width = (lv_coord_t)lv_slider_get_value(obj);
        }
    }
}


#endif  /*LV_USE_100ASK_SKETCHPAD*/
