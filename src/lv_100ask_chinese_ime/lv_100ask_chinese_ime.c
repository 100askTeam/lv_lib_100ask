/**
 * @file lv_100ask_chinese_ime.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "lv_100ask_chinese_ime.h"

#if LV_100ASK_CHINESE_IME != 0

#include <stdio.h>
#include "cJSON.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void lv_chinese_ime_constructor(lv_obj_t * obj);
static void lv_chinese_ime_def_event_cb(lv_event_t * e);
static void parse_match_dict(lv_obj_t * keyboard);
static void select_font_event_cb(lv_event_t * e);
static void lv_chinese_ime_destruct(void);

/**********************
 *  STATIC VARIABLES
 **********************/
static lv_chinese_ime_pt  lv_chinese_ime;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

/**
 * Create a keyboard objects
 * @param par pointer to an object, it will be the parent of the new keyboard
 * @return pointer to the created keyboard
 */
lv_obj_t * lv_100ask_chinese_ime_create(lv_obj_t * parent)
{
    LV_LOG_INFO("begin");
    lv_obj_t * obj = lv_keyboard_create(parent);
    lv_chinese_ime_constructor(obj);
    return obj;
}

/**
 * This is the inheritance and customization of "lv_obj_del".
 * @param obj       pointer to an object
 */
void lv_100ask_chinese_ime_del(lv_obj_t * obj)
{
    lv_chinese_ime_destruct();
    lv_obj_del(obj);
}


/**
 * Set dict of input method
 * @param obj       pointer to an dict
 */
void lv_100ask_chinese_ime_set_dict(const char * dict)
{
    lv_chinese_ime->dict = dict;
}

/**
 * Similar to "lv_obj_set_style_text_font"
 * @param value       pointer to a font
 * @param selector    selector
 */
void lv_100ask_chinese_ime_set_text_font(const lv_font_t * value, lv_style_selector_t selector)
{
    lv_obj_set_style_text_font(lv_chinese_ime->font_panel, value, selector);
}

/*=====================
 * Other functions
 *====================*/

/**********************
 *   STATIC FUNCTIONS
 **********************/

/**
 * This is the inheritance and customization of "lv_keyboard_def_event_cb".
 * @param kb pointer to a keyboard
 * @param event the triggering event
 */
static void lv_chinese_ime_def_event_cb(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);

    uint16_t btn_id   = lv_btnmatrix_get_selected_btn(obj);
    if(btn_id == LV_BTNMATRIX_BTN_NONE) return;

    const char * txt = lv_btnmatrix_get_btn_text(obj, lv_btnmatrix_get_selected_btn(obj));
    if(txt == NULL) return;

    if(strcmp(txt, "Enter") == 0 || strcmp(txt, LV_SYMBOL_NEW_LINE) == 0) {
        lv_obj_clean(lv_chinese_ime->font_panel);
        lv_chinese_ime->ta_count = 0;
        lv_memset_00(lv_chinese_ime->input_char, sizeof(lv_chinese_ime->input_char));
    }
    else if(strcmp(txt, LV_SYMBOL_BACKSPACE) == 0) {
        // del input char
        for (int i = strlen(lv_chinese_ime->input_char) - 1; i >= 0; i--){
            if (lv_chinese_ime->input_char[i] != '\0'){
                lv_chinese_ime->input_char[i] = '\0';
                break;
            }
        }
        parse_match_dict(obj);
        lv_chinese_ime->ta_count--;
    }
    else if ((txt[0] >= 'a' && txt[0] <= 'z') || (txt[0] >= 'A' && txt[0] <= 'Z')){
        strcat(lv_chinese_ime->input_char, txt);
        parse_match_dict(obj);
        lv_chinese_ime->ta_count++;
    }
}


/**
 * Triggered when a font is selected.
 * @param kb pointer to a keyboard
 * @param event the triggering event
 */
static void select_font_event_cb(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);

    lv_obj_t * keyboard = (lv_obj_t *)lv_event_get_user_data(e);
    lv_obj_t * ta = lv_keyboard_get_textarea(keyboard);

    for (int i = 0; i < lv_chinese_ime->ta_count; i++)
    {
        lv_textarea_del_char(ta);
    }

    lv_textarea_add_text(ta, lv_label_get_text(obj));

    lv_obj_clean(lv_chinese_ime->font_panel);
    lv_chinese_ime->ta_count = 0;
    lv_memset_00(lv_chinese_ime->input_char, sizeof(lv_chinese_ime->input_char));
}



/**
 * Parse and match dict (based on cJson)
 * @param text
 * @param label
 */
static void parse_match_dict(lv_obj_t * kb)
{
    cJSON* cjson_parse_result = NULL;
    cJSON* cjson_skill = NULL;
    cJSON* cjson_skill_item = NULL;
    int    skill_array_size = 0, i = 0;

    /* 解析整段JSON数据 */
    cjson_parse_result = cJSON_Parse(lv_chinese_ime->dict);
    if(cjson_parse_result == NULL)
    {
        printf("parse fail.\n");
        return;
    }

    /* 解析数组 */
    lv_obj_t * label;
    lv_obj_clean(lv_chinese_ime->font_panel);
    cjson_skill = cJSON_GetObjectItem(cjson_parse_result, lv_chinese_ime->input_char);
    skill_array_size = cJSON_GetArraySize(cjson_skill);

    for(i = 0; i < skill_array_size; i++)
    {
        cjson_skill_item = cJSON_GetArrayItem(cjson_skill, i);

        /* 展示匹配结果 */
        label = lv_label_create(lv_chinese_ime->font_panel);
        lv_label_set_text(label, cjson_skill_item->valuestring);
        lv_obj_add_flag(label, LV_OBJ_FLAG_CLICKABLE);
        lv_obj_add_event_cb(label, select_font_event_cb, LV_EVENT_CLICKED, kb);
    }
    cJSON_Delete(cjson_parse_result);
}

/**
 * lv_chinese_ime constructor
 * @param obj pointer to a keyboard
 */
static void lv_chinese_ime_constructor(lv_obj_t * obj)
{
	static lv_style_t panel_style;      // 摆放文字展示的面板样式

    /* 申请内存 */
	lv_chinese_ime = (lv_chinese_ime_t *)lv_mem_alloc(sizeof(lv_chinese_ime_t));

	/* 摆放文字展示的面板样式 */
	lv_style_init(&panel_style);
	lv_style_set_bg_opa(&panel_style, 0);
	lv_style_set_border_opa(&panel_style, 0);
	lv_style_set_radius(&panel_style, 0);
	lv_style_set_pad_all(&panel_style, 0);

	lv_chinese_ime->dict = zh_cn_pinyin_dict;
    lv_chinese_ime->ta_count = 0;
    lv_memset_00(lv_chinese_ime->input_char, sizeof(lv_chinese_ime->input_char));

    //lv_chinese_ime->font_panel = lv_obj_create(obj);
    lv_chinese_ime->font_panel = lv_obj_create(lv_scr_act());
    //lv_obj_clear_flag(lv_chinese_ime->font_panel, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_size(lv_chinese_ime->font_panel, LV_PCT(100), LV_PCT(4));
    lv_obj_set_flex_flow(lv_chinese_ime->font_panel, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(lv_chinese_ime->font_panel, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_align_to(lv_chinese_ime->font_panel, obj, LV_ALIGN_OUT_TOP_MID, 0, 0);
    lv_obj_add_style(lv_chinese_ime->font_panel, &panel_style, 0);

    lv_obj_add_event_cb(obj, lv_chinese_ime_def_event_cb, LV_EVENT_VALUE_CHANGED, NULL);
}

/**
 * lv_chinese_ime destruct
 */
static void lv_chinese_ime_destruct(void)
{
    lv_obj_del(lv_chinese_ime->font_panel);
    lv_mem_free(lv_chinese_ime);
}

#endif  /*LV_CHINESE_IME*/
