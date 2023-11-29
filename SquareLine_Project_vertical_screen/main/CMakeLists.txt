#Add sources from ui directory
file(GLOB_RECURSE SRC_UI ${CMAKE_SOURCE_DIR} "ui/*.c")

idf_component_register(SRCS "main.c" ${SRC_UI} ${SRC_CHIP}
                    INCLUDE_DIRS "." "ui"
                    )

