cmake_minimum_required(VERSION 3.21)
project(Task3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/home/mixail/Qt")

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Task3 main.cpp GeometryEngine.cpp GeometryEngine.hpp MainWindow.cpp MainWindow.hpp
        phong_vshader.glsl phong_fshader.glsl
        InputController.cpp InputController.hpp)
target_link_libraries(Task3
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

