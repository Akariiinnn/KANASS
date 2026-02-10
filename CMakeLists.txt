cmake_minimum_required(VERSION 3.26)
project(KANASS)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(FLTK REQUIRED)

add_executable(KANASS
        main.cpp
        kana.cpp
        kana.h
        KanaGame.cpp
        KanaGame.h
)

target_link_libraries(KANASS PRIVATE ${FLTK_LIBRARIES})

target_include_directories(KANASS PRIVATE ${FLTK_INCLUDE_DIR})

if(WIN32)
    set_target_properties(KANASS PROPERTIES
            WIN32_EXECUTABLE TRUE
    )
endif()