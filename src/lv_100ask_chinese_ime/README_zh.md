
<h1 align="center"> lv_100ask_chinese_ime</h1>

<p align="center">
<img src="./lv_100ask_chinese_ime.gif">
</p>
<p align="center">
lv_100ask_chinese_ime 是在 lv_keyboard 的基础上编写的一个自定义部件，它和 lv_keyboard没有什么区别，只是增加了支持中文输入法(拼音)的功能。
</p>


[English](README.md) | **中文** |


# 前言
`lv_100ask_chinese_ime` 是在 lv_keyboard 的基础上编写的一个自定义部件（创建接口为：  `lv_100ask_chinese_ime_create(lv_obj_t *parent));` ），它和 [lv_keyboard](https://docs.lvgl.io/master/widgets/extra/keyboard.html) 没有什么区别，只是增加了支持中文输入法(拼音)的功能。

所以我们将其称为：**支持中文输入法的LVGL键盘(lv_keyboard)部件增强插件**。

正常来说，只要是lvgl能运行的环境 `lv_100ask_chinese_ime` 也能够运行！影响因素主要有两点：使用的字库文件大小和使用的词库大小。

`lv_100ask_chinese_ime` 使用起来非常简单，后续自定义拓展功能也很方便，更多功能敬请期待。

![](./lv_100ask_chinese_ime.gif)


# 使用方法
参考 **lv_lib_100ask/test/lv_100ask_chinese_ime_test** 的示例。


# 注意事项
- 在项目中只能同时存在一个 `lv_100ask_chinese_ime` 。
- 不需要 `lv_100ask_chinese_ime` 的时候，请使用 `lv_100ask_chinese_ime_del` 将其删除。
- 在正常删除 `lv_100ask_chinese_ime` 之后可以通过[上面](#使用方法)的使用示例重新创建使用。


# 关于我们
这是一个开源的项目，非常欢迎大家参与改进lv_100ask_chinese_ime 项目！
作者联系邮箱: smilezyb@163.com