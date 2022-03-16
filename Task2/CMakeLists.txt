cmake_minimum_required(VERSION 3.21)
project(Task2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/home/mixail/Qt/")

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Task2 main.cpp Shaders/vshader.glsl Shaders/fshader.glsl GeometryEngine.cpp GeometryEngine.h
        GLWindow.cpp GLWindow.h Window.cpp Window.hpp SlidersGroup.cpp SlidersGroup.hpp)
target_link_libraries(Task2
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

