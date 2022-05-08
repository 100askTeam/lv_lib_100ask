if(ESP_PLATFORM)

    file(GLOB_RECURSE SOURCES src/*.c test/*.c)

    idf_build_get_property(LV_MICROPYTHON LV_MICROPYTHON)

    if (LV_MICROPYTHON)
        idf_component_register(SRCS ${SOURCES}
                               INCLUDE_DIRS . src test ../
                               REQUIRES lv_lib_100ask)
    else()
        idf_component_register(SRCS ${SOURCES}
                               INCLUDE_DIRS . src test
                               REQUIRES lv_lib_100ask)
    endif()

    target_compile_definitions(${COMPONENT_LIB} PUBLIC "-DLV_LIB_100ASK_ESP_PLATFORM")

else()

    file(GLOB_RECURSE SOURCES src/*.c test/*.c)
    add_library(lv_lib_100ask STATIC ${SOURCES})

endif()

