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
#elif defined(ESP_PLATFORM)
#include "lv_lib_100ask_conf_internal.h"
#elif defined(LV_LIB_100ASK_CONF_INCLUDE_SIMPLE)
#include "lv_lib_100ask_conf.h"
#else
#include "../lv_lib_100ask_conf.h"
#endif

/*lv_100ask_page_manager*/
#include "src/lv_100ask_page_manager/lv_100ask_page_manager.h"
#include "examples/lv_100ask_page_manager/lv_100ask_example_page_manager.h"
/*lv_100ask_pinyin_ime*/
#include "src/lv_100ask_pinyin_ime/lv_100ask_pinyin_ime.h"
#include "examples/lv_100ask_pinyin_ime/lv_100ask_example_pinyin_ime.h"
/*lv_100ask_screenshot*/
#include "src/lv_100ask_screenshot/lv_100ask_screenshot.h"
#include "examples/lv_100ask_screenshot/lv_100ask_example_screenshot.h"
/*lv_100ask_sketchpad*/
#include "src/lv_100ask_sketchpad/lv_100ask_sketchpad.h"
#include "examples/lv_100ask_sketchpad/lv_100ask_example_sketchpad.h"
/*lv_100ask_calc*/
#include "src/lv_100ask_calc/lv_100ask_calc.h"
#include "examples/lv_100ask_calc/lv_100ask_example_calc.h"
/*lv_100ask_memory_game*/
#include "src/lv_100ask_memory_game/lv_100ask_memory_game.h"
#include "examples/lv_100ask_memory_game/lv_100ask_example_memory_game.h"
/*lv_100ask_2048*/
#include "src/lv_100ask_2048/lv_100ask_2048.h"
#include "examples/lv_100ask_2048/lv_100ask_example_2048.h"
/*lv_100ask_file_explorer*/
#include "src/lv_100ask_file_explorer/lv_100ask_file_explorer.h"
#include "examples/lv_100ask_file_explorer/lv_100ask_example_file_explorer.h"

/*Game simulator*/
/*lv_100ask_nes*/
#include "src/lv_100ask_nes/lv_100ask_nes.h"
#include "examples/lv_100ask_nes/lv_100ask_example_nes.h"

/*********************
 *      DEFINES
 *********************/
/*Test  lvgl version*/
#if (LV_VERSION_CHECK(9, 1, 0) == 0) || (LV_VERSION_CHECK(9, 1, 1) == 0)
#warning "lv_lib_100ask: Wrong lvgl version"
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
