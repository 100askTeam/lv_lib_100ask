/**
 * @file lv_lib_100ask.h
 *
 */

#ifndef LV_LIB_100ASK_H
#define LV_LIB_100ASK_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
#include "lvgl.h"
#else
#include "../lvgl/lvgl.h"
#endif

#if defined(LV_LIB_100ASK_CONF_PATH)
#define __LV_TO_STR_AUX(x) #x
#define __LV_TO_STR(x) __LV_TO_STR_AUX(x)
#include __LV_TO_STR(LV_LIB_100ASK_CONF_PATH)
#undef __LV_TO_STR_AUX
#undef __LV_TO_STR
#elif defined(LV_LIB_100ASK_CONF_INCLUDE_SIMPLE)
#include "lv_lib_100ask_conf.h"
#else
#include "../lv_lib_100ask_conf.h"
#endif

/*lv_100ask_page_manager*/
#include "src/lv_100ask_page_manager/lv_100ask_page_manager.h"
#include "test/lv_100ask_page_manager_test/simple_test.h"
/*lv_100ask_chinese_ime*/
#include "src/lv_100ask_chinese_ime/lv_100ask_chinese_ime.h"
#include "test/lv_100ask_chinese_ime_test/simple_test.h"
/*lv_100ask_sketchpad*/
#include "src/lv_100ask_sketchpad/lv_100ask_sketchpad.h"
#include "test/lv_100ask_sketchpad_test/simple_test.h"



/*********************
 *      DEFINES
 *********************/
/*Test  lvgl version*/
#if LV_VERSION_CHECK(8, 2, 0) == 0
#error "lv_lib_100ask: Wrong lvgl version"
#endif

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/


/**********************
 *      MACROS
 **********************/


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*LV_LIB_100ASK_H*/
