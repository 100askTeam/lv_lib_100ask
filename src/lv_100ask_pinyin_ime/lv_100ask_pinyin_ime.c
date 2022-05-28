/**
 * @file lv_100ask_pinyin_ime.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "lv_100ask_pinyin_ime.h"

#if LV_USE_100ASK_PINYIN_IME != 0

#include <stdio.h>
#include "cJSON.h"  

/*********************
 *      DEFINES
 *********************/
#define MY_CLASS    &lv_100ask_pinyin_ime_class

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void lv_100ask_pinyin_ime_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void lv_100ask_pinyin_ime_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void lv_100ask_pinyin_ime_event(lv_event_t * e);

static void select_font_event_cb(lv_event_t * e);
static void parse_match_dict(lv_obj_t * obj, lv_obj_t * kb);

/**********************
 *  STATIC VARIABLES
 **********************/
const lv_obj_class_t lv_100ask_pinyin_ime_class = {
    .constructor_cb = lv_100ask_pinyin_ime_constructor,
    .destructor_cb  = lv_100ask_pinyin_ime_destructor,
    .width_def      = LV_PCT(100),
    .height_def     = LV_PCT(50),
    .group_def      = LV_OBJ_CLASS_GROUP_DEF_TRUE,
    .instance_size  = sizeof(lv_100ask_pinyin_ime_t),
    .base_class     = &lv_obj_class
};

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
lv_obj_t * lv_100ask_pinyin_ime_create(lv_obj_t * parent)
{
    LV_LOG_INFO("begin");
    lv_obj_t * obj = lv_obj_class_create_obj(MY_CLASS, parent);
    lv_obj_class_init_obj(obj);
    return obj;
}


/*=====================
 * Setter functions
 *====================*/

void lv_100ask_pinyin_ime_set_dict(lv_obj_t * obj, const char * dict)
{
    LV_ASSERT_OBJ(obj, MY_CLASS);

    lv_100ask_pinyin_ime_t * pinyin_ime = (lv_100ask_pinyin_ime_t *)obj;

    pinyin_ime->dict = dict;
}

/*=====================
 * Getter functions
 *====================*/
lv_obj_t * lv_100ask_pinyin_ime_get_kb(lv_obj_t * obj)
{
    LV_ASSERT_OBJ(obj, MY_CLASS);

    lv_100ask_pinyin_ime_t * pinyin_ime = (lv_100ask_pinyin_ime_t *)obj;

    return pinyin_ime->kb;
}


const char * lv_100ask_pinyin_ime_get_dict(lv_obj_t * obj)
{
    LV_ASSERT_OBJ(obj, MY_CLASS);

    lv_100ask_pinyin_ime_t * pinyin_ime = (lv_100ask_pinyin_ime_t *)obj;

    return pinyin_ime->dict;
}

/*=====================
 * Other functions
 *====================*/

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void lv_100ask_pinyin_ime_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);
    LV_TRACE_OBJ_CREATE("begin");
    
    lv_100ask_pinyin_ime_t * pinyin_ime = (lv_100ask_pinyin_ime_t *)obj;

    pinyin_ime->dict = zh_cn_pinyin_dict;
    pinyin_ime->ta_count = 0;
    lv_memset_00(pinyin_ime->input_char, sizeof(pinyin_ime->input_char));

    lv_obj_set_size(obj, LV_PCT(100), LV_PCT(55));
    lv_obj_align(obj, LV_ALIGN_BOTTOM_MID, 0, 0);

    pinyin_ime->kb = lv_keyboard_create(lv_scr_act());
    lv_obj_align_to(pinyin_ime->kb, obj, LV_ALIGN_BOTTOM_MID, 0, 0);

    pinyin_ime->font_panel = lv_obj_create(obj);
    lv_obj_set_size(pinyin_ime->font_panel, LV_PCT(100), LV_PCT(10));
    lv_obj_set_flex_flow(pinyin_ime->font_panel, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(pinyin_ime->font_panel, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_align_to(pinyin_ime->font_panel, obj, LV_ALIGN_TOP_MID, 0, 0);

    lv_obj_set_style_bg_opa(pinyin_ime->font_panel, 0, 0);
	lv_obj_set_style_border_opa(pinyin_ime->font_panel, 0, 0);
	lv_obj_set_style_radius(pinyin_ime->font_panel, 0, 0);
	lv_obj_set_style_pad_all(pinyin_ime->font_panel, 0, 0);

    lv_obj_add_event_cb(pinyin_ime->kb, lv_100ask_pinyin_ime_event, LV_EVENT_VALUE_CHANGED, obj);
  
}


static void lv_100ask_pinyin_ime_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);

    lv_100ask_pinyin_ime_t * pinyin_ime = (lv_100ask_pinyin_ime_t *)obj;

    if (pinyin_ime->kb)
    {
        lv_obj_del(pinyin_ime->kb);
    }
}



static void lv_100ask_pinyin_ime_event(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * kb = lv_event_get_target(e);
    lv_obj_t * obj = lv_event_get_user_data(e);

    lv_100ask_pinyin_ime_t * pinyin_ime = (lv_100ask_pinyin_ime_t *)obj;

    if(code == LV_EVENT_VALUE_CHANGED)
    {
        uint16_t btn_id  = lv_btnmatrix_get_selected_btn(kb);
        if(btn_id == LV_BTNMATRIX_BTN_NONE) return;

        const char * txt = lv_btnmatrix_get_btn_text(kb, lv_btnmatrix_get_selected_btn(kb));
        if(txt == NULL) return;

        if(strcmp(txt, "Enter") == 0 || strcmp(txt, LV_SYMBOL_NEW_LINE) == 0) {
            lv_obj_clean(pinyin_ime->font_panel);
            pinyin_ime->ta_count = 0;
            lv_memset_00(pinyin_ime->input_char, sizeof(pinyin_ime->input_char));
        }
        else if(strcmp(txt, LV_SYMBOL_BACKSPACE) == 0) {
            // del input char
            for (int i = strlen(pinyin_ime->input_char) - 1; i >= 0; i--){
                if (pinyin_ime->input_char[i] != '\0'){
                    pinyin_ime->input_char[i] = '\0';
                    break;
                }
            }
            parse_match_dict(obj, kb);
            pinyin_ime->ta_count--;
        }
        else if ((txt[0] >= 'a' && txt[0] <= 'z') || (txt[0] >= 'A' && txt[0] <= 'Z')){
            strcat(pinyin_ime->input_char, txt);
            parse_match_dict(obj, kb);
            pinyin_ime->ta_count++;
        }
    }  
}



static void select_font_event_cb(lv_event_t * e)
{
    lv_obj_t * label = lv_event_get_target(e);
    lv_obj_t * font_panel = lv_obj_get_parent(label);
    lv_obj_t * obj = lv_obj_get_parent(font_panel);

    lv_obj_t * kb = (lv_obj_t *)lv_event_get_user_data(e);
    lv_100ask_pinyin_ime_t * pinyin_ime = (lv_100ask_pinyin_ime_t *)obj;

    lv_obj_t * ta = lv_keyboard_get_textarea(kb);

    for (int i = 0; i < pinyin_ime->ta_count; i++)
    {
        lv_textarea_del_char(ta);
    }

    lv_textarea_add_text(ta, lv_label_get_text(label));

    lv_obj_clean(pinyin_ime->font_panel);
    pinyin_ime->ta_count = 0;
    lv_memset_00(pinyin_ime->input_char, sizeof(pinyin_ime->input_char));
}


static void parse_match_dict(lv_obj_t * obj, lv_obj_t * kb)
{
    lv_100ask_pinyin_ime_t * pinyin_ime = (lv_100ask_pinyin_ime_t *)obj;

    cJSON* cjson_parse_result = NULL;
    cJSON* cjson_skill = NULL;
    cJSON* cjson_skill_item = NULL;
    int    skill_array_size = 0, i = 0;

    /* 解析整段JSON数据 */
    cjson_parse_result = cJSON_Parse(pinyin_ime->dict);
    if(cjson_parse_result == NULL)
    {
        printf("parse fail.\n");
        return;
    }

    /* 解析数组 */
    lv_obj_t * label;
    lv_obj_clean(pinyin_ime->font_panel);
    cjson_skill = cJSON_GetObjectItem(cjson_parse_result, pinyin_ime->input_char);
    skill_array_size = cJSON_GetArraySize(cjson_skill);

    for(i = 0; i < skill_array_size; i++)
    {
        cjson_skill_item = cJSON_GetArrayItem(cjson_skill, i);

        /* 展示匹配结果 */
        label = lv_label_create(pinyin_ime->font_panel);
        lv_label_set_text(label, cjson_skill_item->valuestring);
        lv_obj_add_flag(label, LV_OBJ_FLAG_CLICKABLE);
        lv_obj_add_event_cb(label, select_font_event_cb, LV_EVENT_CLICKED, kb);
    }
    cJSON_Delete(cjson_parse_result);
}

#endif  /*LV_USE_PINYIN_IME*/
