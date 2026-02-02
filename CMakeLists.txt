cmake_minimum_required(VERSION 3.26)
project(KANASS)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find FLTK using the provided module (vcpkg makes this work automatically)
find_package(FLTK REQUIRED)

add_executable(KANASS
        main.cpp
        kana.cpp
        kana.h
        KanaGame.cpp
        KanaGame.h
)

# Link using the variables provided by FindFLTK.cmake
target_link_libraries(KANASS PRIVATE ${FLTK_LIBRARIES})

# Include directories (usually not needed if FLTK is found correctly, but safe)
target_include_directories(KANASS PRIVATE ${FLTK_INCLUDE_DIR})

# Optional: Make it a pure GUI app (no console window pops up on Windows)
if(WIN32)
    # For MSVC
    set_target_properties(KANASS PROPERTIES
            WIN32_EXECUTABLE TRUE
    )
    # Alternative for MinGW if needed: target_link_options(KANASS PRIVATE -mwindows)
endif()

# Optional: If your app uses FLTK's OpenGL features (e.g., Fl_Gl_Window)
# target_link_libraries(KANASS PRIVATE ${FLTK_GL_LIBRARIES})