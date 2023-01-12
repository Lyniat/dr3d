cmake_minimum_required(VERSION 3.24)

project(dr3d LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

include_directories(
        ../include
        third-party
)

set(ENGINE_SRC
        app/ext.cpp
        app/renderer.h
        app/renderer.cpp
        app/api.h
        app/api.cpp
)

add_library(dr3d SHARED ${ENGINE_SRC})

set_target_properties(dr3d
        PROPERTIES PREFIX ""
        OUTPUT_NAME "ext"
        )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

# copy file to directory
if (APPLE)
    add_custom_command(TARGET dr3d
            POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:dr3d> ../native/macos)
endif()