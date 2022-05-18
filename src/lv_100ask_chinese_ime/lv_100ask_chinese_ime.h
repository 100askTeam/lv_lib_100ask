/**
 * @file lv_100ask_chinese_ime.h
 *
 */
#ifndef LV_100ASK_CHINESE_IME_H
#define LV_100ASK_CHINESE_IME_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include "../../lv_lib_100ask.h"

#if LV_100ASK_CHINESE_IME != 0

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/
/*Data of lv_chinese_ime*/
typedef struct {
    lv_obj_t * font_panel;
    char * dict;
    char input_char[16];
    uint8_t ta_count;
} lv_chinese_ime_t, *lv_chinese_ime_pt;

/***********************
 * GLOBAL VARIABLES
 ***********************/
extern const char * zh_cn_pinyin_dict;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Create lv_100ask_chinese_ime (keyboard objects)
 * @param par pointer to an object, it will be the parent of the new keyboard
 * @return pointer to the created keyboard
 */
lv_obj_t * lv_100ask_chinese_ime_create(lv_obj_t * parent);

/**
 * This is the inheritance and customization of "lv_obj_del".
 * @param obj       pointer to an object
 */
void lv_100ask_chinese_ime_del(lv_obj_t * obj);

/**
 * Set dict of input method
 * @param obj       pointer to an dict
 */
void lv_100ask_chinese_ime_set_dict(const char * dict);

/**
 * Similar to "lv_obj_set_style_text_font"
 * @param value       pointer to a font
 * @param selector    selector
 */
void lv_100ask_chinese_ime_set_text_font(const lv_font_t * value, lv_style_selector_t selector);


/*=====================
 * Setter functions
 *====================*/

/*=====================
 * Getter functions
 *====================*/

/*=====================
 * Other functions
 *====================*/

/**********************
 *      MACROS
 **********************/

#endif  /*LV_CHINESE_IME*/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LV_100ASK_CHINESE_IME*/

