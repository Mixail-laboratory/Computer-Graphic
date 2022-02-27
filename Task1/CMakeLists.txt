cmake_minimum_required(VERSION 3.21)
project(Task1)

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

add_executable(Task1 main.cpp GeometryEngine.cpp GeometryEngine.h MainWindow.h MainWindow.cpp
        Shaders/vshader.glsl Shaders/fshader.glsl)
target_link_libraries(Task1
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

