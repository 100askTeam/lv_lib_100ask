
/**
 * @file simple_test.c
 *
 */



/*********************
 *      INCLUDES
 *********************/
#include "simple_test.h"

#if LV_100ASK_PAGE_MANAGER_SIMPLE_TEST != 0

/*********************
 *      DEFINES
 *********************/


/**********************
 *      TYPEDEFS
 **********************/



/**********************
 *  STATIC PROTOTYPES
 **********************/
static void init_main_page(lv_obj_t * page);
static void init_page1(lv_obj_t * page);
static void init_page2(lv_obj_t * page);
static void init_page3(lv_obj_t * page);
static void init_page4(lv_obj_t * page);
static void init_page5(lv_obj_t * page);
static void init_page6(lv_obj_t * page);
static void open_page_anim(lv_obj_t * obj);
static void close_page_anim(lv_obj_t * obj);
/**********************
 *  STATIC VARIABLES
 **********************/


/**********************
 *      MACROS
 **********************/


/**********************
 *   GLOBAL FUNCTIONS
 **********************/


void lv_100ask_page_manager_simple_test(void)
{
    lv_obj_t * page_manager = lv_100ask_page_manager_create(lv_scr_act());

    lv_obj_t * main_page = lv_100ask_page_manager_page_create(page_manager, "main_page");
    lv_obj_t * page1 = lv_100ask_page_manager_page_create(page_manager, "Page1");
    lv_obj_t * page2 = lv_100ask_page_manager_page_create(page_manager, "Page2");
    lv_obj_t * page3 = lv_100ask_page_manager_page_create(page_manager, "Page3");
    lv_obj_t * page4 = lv_100ask_page_manager_page_create(page_manager, "Page4");
    lv_obj_t * page5 = lv_100ask_page_manager_page_create(page_manager, "Page5");
    lv_obj_t * page6 = lv_100ask_page_manager_page_create(page_manager, "Page6");

    lv_100ask_page_manager_set_page_init(main_page, init_main_page);
    lv_100ask_page_manager_set_page_init(page1, init_page1);
    lv_100ask_page_manager_set_page_init(page2, init_page2);
    lv_100ask_page_manager_set_page_init(page3, init_page3);
    lv_100ask_page_manager_set_page_init(page4, init_page4);
    lv_100ask_page_manager_set_page_init(page5, init_page5);
    lv_100ask_page_manager_set_page_init(page6, init_page6);

    lv_100ask_page_manager_set_open_page_anim(main_page, open_page_anim);
    lv_100ask_page_manager_set_close_page_anim(main_page, close_page_anim);
    lv_100ask_page_manager_set_open_page_anim(page1, open_page_anim);
    lv_100ask_page_manager_set_close_page_anim(page1, close_page_anim);
    lv_100ask_page_manager_set_open_page_anim(page2, open_page_anim);
    lv_100ask_page_manager_set_close_page_anim(page2, close_page_anim);
    lv_100ask_page_manager_set_open_page_anim(page3, open_page_anim);
    lv_100ask_page_manager_set_close_page_anim(page3, close_page_anim);
    lv_100ask_page_manager_set_open_page_anim(page4, open_page_anim);
    lv_100ask_page_manager_set_close_page_anim(page4, close_page_anim);
    lv_100ask_page_manager_set_open_page_anim(page5, open_page_anim);
    lv_100ask_page_manager_set_close_page_anim(page5, close_page_anim);
    lv_100ask_page_manager_set_open_page_anim(page6, open_page_anim);
    lv_100ask_page_manager_set_close_page_anim(page6, close_page_anim);

    lv_100ask_page_manager_set_main_page(page_manager, main_page);
    lv_100ask_page_manager_set_open_page(NULL, "Page6");
}


/*=====================
 * Other functions
 *====================*/

/**********************
 *   STATIC FUNCTIONS
 **********************/

/*open page anim*/
static void open_page_anim(lv_obj_t * obj)
{
    /*Do something with LVGL*/
    LV_LOG_USER("open page anim.");
}

/*close page anim*/
static void close_page_anim(lv_obj_t * obj)
{
    /*Do something with LVGL*/
    LV_LOG_USER("close page anim.");
}

/* main page */
static void init_main_page(lv_obj_t * page)
{
    static lv_style_t style;
    lv_style_init(&style);
    lv_style_set_flex_flow(&style, LV_FLEX_FLOW_ROW_WRAP);
    lv_style_set_flex_main_place(&style, LV_FLEX_ALIGN_SPACE_EVENLY);
    lv_style_set_layout(&style, LV_LAYOUT_FLEX);

    lv_obj_t * cont = lv_obj_create(page);
    lv_obj_set_size(cont, LV_PCT(95), LV_PCT(20));
    lv_obj_center(cont);
    lv_obj_add_style(cont, &style, 0);

    uint32_t i;
    for(i = 0; i < 6; i++) {
        lv_obj_t * obj = lv_obj_create(cont);
        lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_PCT(100));
        lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);

        lv_obj_t * label = lv_label_create(obj);
        lv_label_set_text_fmt(label, "Page%d", i+1);
        lv_obj_center(label);

        lv_100ask_page_manager_set_load_page_event(obj, NULL, lv_label_get_text(label));
    }
}



/* page 1 */
static lv_obj_t * create_slider(lv_color_t color, lv_obj_t * page);
static void slider_event_cb(lv_event_t * e);

static lv_obj_t * red_slider, * green_slider, * blue_slider, * intense_slider;
static lv_obj_t * img1;

// Demonstrate runtime image re-coloring

static void init_page1(lv_obj_t * page)
{
    /*Create 4 sliders to adjust RGB color and re-color intensity*/
    red_slider = create_slider(lv_palette_main(LV_PALETTE_RED), page);
    green_slider = create_slider(lv_palette_main(LV_PALETTE_GREEN), page);
    blue_slider = create_slider(lv_palette_main(LV_PALETTE_BLUE), page);
    intense_slider = create_slider(lv_palette_main(LV_PALETTE_GREY), page);

    lv_slider_set_value(red_slider, LV_OPA_20, LV_ANIM_OFF);
    lv_slider_set_value(green_slider, LV_OPA_90, LV_ANIM_OFF);
    lv_slider_set_value(blue_slider, LV_OPA_60, LV_ANIM_OFF);
    lv_slider_set_value(intense_slider, LV_OPA_50, LV_ANIM_OFF);

    lv_obj_align(red_slider, LV_ALIGN_LEFT_MID, 25, 0);
    lv_obj_align_to(green_slider, red_slider, LV_ALIGN_OUT_RIGHT_MID, 25, 0);
    lv_obj_align_to(blue_slider, green_slider, LV_ALIGN_OUT_RIGHT_MID, 25, 0);
    lv_obj_align_to(intense_slider, blue_slider, LV_ALIGN_OUT_RIGHT_MID, 25, 0);

    /*Now create the actual image*/
    LV_IMG_DECLARE(img_cogwheel_argb)
    img1 = lv_img_create(page);
    lv_img_set_src(img1, &img_cogwheel_argb);
    lv_obj_align(img1, LV_ALIGN_RIGHT_MID, -20, 0);

    lv_event_send(intense_slider, LV_EVENT_VALUE_CHANGED, NULL);
}

static void slider_event_cb(lv_event_t * e)
{
    LV_UNUSED(e);

    /*Recolor the image based on the sliders' values*/
    lv_color_t color  = lv_color_make(lv_slider_get_value(red_slider), lv_slider_get_value(green_slider), lv_slider_get_value(blue_slider));
    lv_opa_t intense = lv_slider_get_value(intense_slider);
    lv_obj_set_style_img_recolor_opa(img1, intense, 0);
    lv_obj_set_style_img_recolor(img1, color, 0);
}

static lv_obj_t * create_slider(lv_color_t color, lv_obj_t * page)
{
    lv_obj_t * slider = lv_slider_create(page);
    lv_slider_set_range(slider, 0, 255);
    lv_obj_set_size(slider, 10, 200);
    lv_obj_set_style_bg_color(slider, color, LV_PART_KNOB);
    lv_obj_set_style_bg_color(slider, lv_color_darken(color, LV_OPA_40), LV_PART_INDICATOR);
    lv_obj_add_event_cb(slider, slider_event_cb, LV_EVENT_VALUE_CHANGED, NULL);
    return slider;
}


/* page 2 */
static void drag_event_handler(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);

    lv_indev_t * indev = lv_indev_get_act();
    if(indev == NULL)  return;

    lv_point_t vect;
    lv_indev_get_vect(indev, &vect);

    lv_coord_t x = lv_obj_get_x(obj) + vect.x;
    lv_coord_t y = lv_obj_get_y(obj) + vect.y;
    lv_obj_set_pos(obj, x, y);
}

static void init_page2(lv_obj_t * page)
{
    lv_obj_t * obj;
    obj = lv_obj_create(page);
    lv_obj_set_pos(obj, (lv_disp_get_hor_res(NULL)/2), (lv_disp_get_ver_res(NULL)/2));
    lv_obj_set_size(obj, 150, 100);
    lv_obj_add_event_cb(obj, drag_event_handler, LV_EVENT_PRESSING, NULL);

    lv_obj_t * label = lv_label_create(obj);
    lv_label_set_text(label, "Drag me");
    lv_obj_center(label);

    lv_obj_t * btn1 = lv_btn_create(page);
    lv_obj_set_size(btn1, 100, 50);
    lv_obj_align_to(btn1, obj, LV_ALIGN_OUT_BOTTOM_MID, 80, 20);

    lv_obj_t * label1 = lv_label_create(btn1);
    lv_label_set_text(label1, "Open Page3");
    lv_obj_center(label1);

    lv_100ask_page_manager_set_load_page_event(btn1, NULL, "Page3");

    lv_obj_t * btn2 = lv_btn_create(page);
    lv_obj_set_size(btn2, 100, 50);
    lv_obj_align_to(btn2, obj, LV_ALIGN_OUT_BOTTOM_MID, -80, 20);

    lv_obj_t * label2 = lv_label_create(btn2);
    lv_label_set_text(label2, "Open Page4");
    lv_obj_center(label2);

    lv_100ask_page_manager_set_load_page_event(btn2, NULL, "Page4");

}


/* page 3*/
static void anim_x_cb(void * var, int32_t v)
{
    lv_obj_set_x(var, v);
}

static void anim_size_cb(void * var, int32_t v)
{
    lv_obj_set_size(var, v, v);
}

// Create a playback animation
static void init_page3(lv_obj_t * page)
{

    lv_obj_t * obj = lv_obj_create(page);
    lv_obj_set_style_bg_color(obj, lv_palette_main(LV_PALETTE_RED), 0);
    lv_obj_set_style_radius(obj, LV_RADIUS_CIRCLE, 0);

    lv_obj_align(obj, LV_ALIGN_CENTER, 10, 0);

    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, obj);
    lv_anim_set_values(&a, 10, 50);
    lv_anim_set_time(&a, 1000);
    lv_anim_set_playback_delay(&a, 100);
    lv_anim_set_playback_time(&a, 300);
    lv_anim_set_repeat_delay(&a, 500);
    lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);
    lv_anim_set_path_cb(&a, lv_anim_path_ease_in_out);

    lv_anim_set_exec_cb(&a, anim_size_cb);
    lv_anim_start(&a);
    lv_anim_set_exec_cb(&a, anim_x_cb);
    lv_anim_set_values(&a, 10, 240);
    lv_anim_start(&a);

    lv_obj_t * btn1 = lv_btn_create(page);
    lv_obj_set_size(btn1, 100, 50);
    lv_obj_align_to(btn1, obj, LV_ALIGN_OUT_BOTTOM_MID, 80, 20);

    lv_obj_t * label1 = lv_label_create(btn1);
    lv_label_set_text(label1, "Open Page5");
    lv_obj_center(label1);

    lv_100ask_page_manager_set_load_page_event(btn1, NULL, "Page5");

    lv_obj_t * btn2 = lv_btn_create(page);
    lv_obj_set_size(btn2, 100, 50);
    lv_obj_align_to(btn2, obj, LV_ALIGN_OUT_BOTTOM_MID, -80, 20);

    lv_obj_t * label2 = lv_label_create(btn2);
    lv_label_set_text(label2, "Open Page6");
    lv_obj_center(label2);

    lv_100ask_page_manager_set_load_page_event(btn2, NULL, "Page6");
}

/* page 4*/
static void set_angle(void * img, int32_t v)
{
    lv_img_set_angle(img, v);
}

static void set_zoom(void * img, int32_t v)
{
    lv_img_set_zoom(img, v);
}

// Show transformations (zoom and rotation) using a pivot point.
static void init_page4(lv_obj_t * page)
{
    LV_IMG_DECLARE(img_cogwheel_argb);

    /*Now create the actual image*/
    lv_obj_t * img = lv_img_create(page);
    lv_img_set_src(img, &img_cogwheel_argb);
    lv_obj_align(img, LV_ALIGN_CENTER, 50, 50);
    lv_img_set_pivot(img, 0, 0);    /*Rotate around the top left corner*/

    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, img);
    lv_anim_set_exec_cb(&a, set_angle);
    lv_anim_set_values(&a, 0, 3600);
    lv_anim_set_time(&a, 5000);
    lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);
    lv_anim_start(&a);

    lv_anim_set_exec_cb(&a, set_zoom);
    lv_anim_set_values(&a, 128, 256);
    lv_anim_set_playback_time(&a, 3000);
    lv_anim_start(&a);

    lv_obj_t * btn1 = lv_btn_create(page);
    lv_obj_set_size(btn1, 100, 50);
    lv_obj_align_to(btn1, img, LV_ALIGN_OUT_BOTTOM_MID, 80, 20);

    lv_obj_t * label1 = lv_label_create(btn1);
    lv_label_set_text(label1, "Open Page2");
    lv_obj_center(label1);

    lv_100ask_page_manager_set_load_page_event(btn1, NULL, "Page2");

    lv_obj_t * btn2 = lv_btn_create(page);
    lv_obj_set_size(btn2, 100, 50);
    lv_obj_align_to(btn2, img, LV_ALIGN_OUT_BOTTOM_MID, -80, 20);

    lv_obj_t * label2 = lv_label_create(btn2);
    lv_label_set_text(label2, "Open Page3");
    lv_obj_center(label2);

    lv_100ask_page_manager_set_load_page_event(btn2, NULL, "Page3");
}

/*page 5*/
LV_IMG_DECLARE(animimg001)
LV_IMG_DECLARE(animimg002)
LV_IMG_DECLARE(animimg003)

static const lv_img_dsc_t* anim_imgs[3] = {
    &animimg001,
    &animimg002,
    &animimg003,
};

static void init_page5(lv_obj_t * page)
{
    lv_obj_t * animimg0 = lv_animimg_create(page);
    lv_obj_center(animimg0);
    lv_animimg_set_src(animimg0, (lv_img_dsc_t**) anim_imgs, 3);
    lv_animimg_set_duration(animimg0, 1000);
    lv_animimg_set_repeat_count(animimg0, LV_ANIM_REPEAT_INFINITE);
    lv_animimg_start(animimg0);

    lv_obj_t * btn1 = lv_btn_create(page);
    lv_obj_set_size(btn1, 100, 50);
    lv_obj_align_to(btn1, animimg0, LV_ALIGN_OUT_BOTTOM_MID, 80, 20);

    lv_obj_t * label1 = lv_label_create(btn1);
    lv_label_set_text(label1, "Open Page6");
    lv_obj_center(label1);

    lv_100ask_page_manager_set_load_page_event(btn1, NULL, "Page6");

    lv_obj_t * btn2 = lv_btn_create(page);
    lv_obj_set_size(btn2, 100, 50);
    lv_obj_align_to(btn2, animimg0, LV_ALIGN_OUT_BOTTOM_MID, -80, 20);

    lv_obj_t * label2 = lv_label_create(btn2);
    lv_label_set_text(label2, "Open Page1");
    lv_obj_center(label2);

    lv_100ask_page_manager_set_load_page_event(btn2, NULL, "Page1");
}

/*page 6*/

static void row_gap_anim(void * obj, int32_t v)
{
    lv_obj_set_style_pad_row(obj, v, 0);
}

static void column_gap_anim(void * obj, int32_t v)
{
    lv_obj_set_style_pad_column(obj, v, 0);
}

//Demonstrate column and row gap
static void init_page6(lv_obj_t * page)
{

    /*60x60 cells*/
    static lv_coord_t col_dsc[] = {60, 60, 60, LV_GRID_TEMPLATE_LAST};
    static lv_coord_t row_dsc[] = {45, 45, 45, LV_GRID_TEMPLATE_LAST};

    /*Create a container with grid*/
    lv_obj_t * cont = lv_obj_create(page);
    lv_obj_set_size(cont, 300, 220);
    lv_obj_center(cont);
    lv_obj_set_grid_dsc_array(cont, col_dsc, row_dsc);

    lv_obj_t * label;
    lv_obj_t * obj;
    uint32_t i;
    for(i = 0; i < 9; i++) {
        uint8_t col = i % 3;
        uint8_t row = i / 3;

        obj = lv_obj_create(cont);
        lv_obj_set_grid_cell(obj, LV_GRID_ALIGN_STRETCH, col, 1,
                                 LV_GRID_ALIGN_STRETCH, row, 1);
        label = lv_label_create(obj);
        lv_label_set_text_fmt(label, "%d,%d", col, row);
        lv_obj_center(label);
    }

    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, cont);
    lv_anim_set_values(&a, 0, 10);
    lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);

    lv_anim_set_exec_cb(&a, row_gap_anim);
    lv_anim_set_time(&a, 500);
    lv_anim_set_playback_time(&a, 500);
    lv_anim_start(&a);

    lv_anim_set_exec_cb(&a, column_gap_anim);
    lv_anim_set_time(&a, 3000);
    lv_anim_set_playback_time(&a, 3000);
    lv_anim_start(&a);

    lv_obj_t * btn1 = lv_btn_create(page);
    lv_obj_set_size(btn1, 100, 50);
    lv_obj_align_to(btn1, cont, LV_ALIGN_OUT_BOTTOM_MID, 80, 20);

    lv_obj_t * label1 = lv_label_create(btn1);
    lv_label_set_text(label1, "Open Page1");
    lv_obj_center(label1);

    lv_100ask_page_manager_set_load_page_event(btn1, NULL, "Page1");

    lv_obj_t * btn2 = lv_btn_create(page);
    lv_obj_set_size(btn2, 100, 50);
    lv_obj_align_to(btn2, cont, LV_ALIGN_OUT_BOTTOM_MID, -80, 20);

    lv_obj_t * label2 = lv_label_create(btn2);
    lv_label_set_text(label2, "Open Page4");
    lv_obj_center(label2);

    lv_100ask_page_manager_set_load_page_event(btn2, NULL, "Page4");
}

#endif  /*SIMPLE_TEST*/
