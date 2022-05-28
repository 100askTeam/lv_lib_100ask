/**
 * @file lv_100ask_pinyin_ime.h
 *
 */
#ifndef LV_100ASK_PINYIN_IME_H
#define LV_100ASK_PINYIN_IME_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include "../../lv_lib_100ask.h"

#if LV_USE_100ASK_PINYIN_IME != 0

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/
/*Data of lv_pinyin_ime*/
typedef struct {
    lv_obj_t obj;
    lv_obj_t * kb;
    lv_obj_t * font_panel;
    const char * dict;
    char input_char[16];
    uint8_t ta_count;
} lv_100ask_pinyin_ime_t;

/***********************
 * GLOBAL VARIABLES
 ***********************/
extern const char * zh_cn_pinyin_dict;

/**********************
 * GLOBAL PROTOTYPES
 **********************/
lv_obj_t * lv_100ask_pinyin_ime_create(lv_obj_t * parent);

/*=====================
 * Setter functions
 *====================*/

void lv_100ask_pinyin_ime_set_dict(lv_obj_t * obj, const char * dict);


/*=====================
 * Getter functions
 *====================*/

lv_obj_t * lv_100ask_pinyin_ime_get_kb(lv_obj_t * obj);

const char * lv_100ask_pinyin_ime_get_dict(lv_obj_t * obj);

/*=====================
 * Other functions
 *====================*/

/**********************
 *      MACROS
 **********************/

#endif  /*LV_PINYIN_IME*/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LV_USE_100ASK_PINYIN_IME*/

