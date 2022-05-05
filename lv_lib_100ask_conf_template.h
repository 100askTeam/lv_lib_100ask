/**
 * @file lv_lib_100ask_conf.h
 * Configuration file for v8.2.0
 *
 */
/*
 * COPY THIS FILE AS lv_lib_100ask_conf.h
 */

/* clang-format off */
#if 0 /*Set it to "1" to enable the content*/

#ifndef LV_LIB_100ASK_CONF_H
#define LV_LIB_100ASK_CONF_H

#include "lv_conf.h"

/*******************
 * GENERAL SETTING
 *******************/

/*********************
 * USAGE
 *********************/

/* Simplified Chinese input method */
#if LV_USE_KEYBOARD
    /* Requires LV_USE_KEYBOARD = 1 */
    #define LV_100ASK_CHINESE_IME                          0
#endif

#if LV_100ASK_CHINESE_IME
    #define LV_100ASK_CHINESE_IME_ZH_CN_PIN_YIN_DICT   1

    /*test*/
    #define LV_100ASK_CHINESE_IME_SIMPLE_TEST          1
#endif


/* Page manager */
#define LV_100ASK_PAGE_MANAGER                              0
#if LV_100ASK_PAGE_MANAGER
    /*Switch pages and delete old pages at the same time. */
    /*1: DELETE , 0:DELETE NO*/
    #define LV_100ASK_PAGE_MANAGER_SW_DEL_PAGE          0
        
	/* Page switcher snapshot*/
	#if LV_USE_SNAPSHOT
        /* Requires LV_USE_SNAPSHOT = 1 */
        #define PAGE_SWITCHER_SNAPSHOT                  0 // TODO
    #endif

    #define LV_100ASK_PAGE_MANAGER_BACK_BTN_SIZE        (LV_DPI_DEF/2)

    /*test*/
    #define LV_100ASK_PAGE_MANAGER_SIMPLE_TEST          1
#endif


/* sketchpad */
#if LV_USE_CANVAS
    /* Requires LV_USE_CANVAS = 1 */
    #define LV_100ASK_SKETCHPAD                             0
#endif
#if LV_100ASK_SKETCHPAD
    /* set sketchpad default size */
    #define SKETCHPAD_DEFAULT_WIDTH                     1024    //LV_HOR_RES
    #define SKETCHPAD_DEFAULT_HEIGHT                    600     //LV_VER_RES

    /*test*/
    #define LV_100ASK_SKETCHPAD_SIMPLE_TEST             1
#endif


/*Calculator*/
#define LV_100ASK_CALC                                      1
#if LV_100ASK_CALC
    /*Calculation expression*/
    #define LV_100ASK_CALC_EXPR_LEN                      (128) // Maximum allowed length of expression
    #define LV_100ASK_CALC_MAX_NUM_LEN                   (5)   // Maximum length of operands allowed

    /*test*/
    #define LV_100ASK_CALC_SIMPLE_TEST                  1
#endif

/*GAME*/
/*Memory game*/
#define LV_100ASK_MEMORY_GAME                               1
#if LV_100ASK_MEMORY_GAME
    /*Initial values of rows and columns.*/
    /*Recommended row == column*/
    #define  LV_100ASK_MEMORY_GAME_DEFAULT_ROW          4
    #define  LV_100ASK_MEMORY_GAME_DEFAULT_COL          4

    /*test*/
    #define  LV_100ASK_MEMORY_GAME_SIMPLE_TEST          1
#endif   

#endif /*LV_LIB_100ASK_H*/

#endif /*End of "Content enable"*/

