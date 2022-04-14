<h1 align="center"> lv_100ask_chinese_ime</h1>

<p align="center">
<img src="./lv_100ask_chinese_ime.gif">
</p>

<p align="center">
lv_100ask_chinese_ime is a custom component written on the basis of lv_keyboard, it is no different from lv_keyboard, but the function of supporting Chinese input method (Pinyin) is added.
</p>


**English** | [中文](./README_zh.md) |


# Introduction

`lv_100ask_chinese_ime` is a custom component written on the basis of lv_keyboard (the creation interface is: `lv_100ask_chinese_ime_create(lv_obj_t *parent));` ), it is no different from [lv_keyboard](https://docs.lvgl.io/master/widgets/extra/keyboard.html), but the function of supporting Chinese input method (Pinyin) is added.

So we call it: **Support Chinese input method LVGL keyboard (lv_keyboard) widget enhancement plugin**.

Normally, as long as lvgl can run in an environment `lv_100ask_chinese_ime` can also run! There are two main influencing factors: the size of the font file used and the size of the thesaurus used.

`lv_100ask_chinese_ime` is very simple to use, and the subsequent custom expansion functions are also very convenient, so stay tuned for more functions.


# Usage
Refer to the example in **lv_lib_100ask/test/lv_100ask_chinese_ime_test**.

# NOTE
- Only one `lv_100ask_chinese_ime` can exist in a project at the same time.
- When `lv_100ask_chinese_ime` is not needed, please use `lv_100ask_chinese_ime_del` to delete it.
- After deleting `lv_100ask_chinese_ime` normally, you can recreate the usage through the [above](# Usage) usage example..



# About
This is an open project and contribution is very welcome!
Contact us: smilezyb@163.com