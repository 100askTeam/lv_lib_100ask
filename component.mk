# ESP-IDF component file for make based commands

COMPONENT_SRCDIRS := . \
                  src \
                  src/lv_100ask_calc \
				  src/lv_100ask_chinese_ime \
				  src/lv_100ask_memory_game \
				  src/lv_100ask_page_manager \
				  src/lv_100ask_sketchpad	\
				  test \
                  test/lv_100ask_calc_test \
				  test/lv_100ask_chinese_ime_test \
				  test/lv_100ask_memory_game_test \
				  test/lv_100ask_page_manager_test \
				  test/lv_100ask_sketchpad_test


COMPONENT_ADD_INCLUDEDIRS := $(COMPONENT_SRCDIRS) .