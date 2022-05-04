cmake_minimum_required(VERSION 3.21)
project(Task5)

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

add_executable(Task5 main.cpp GeometryEngine.hpp GeometryEngine.cpp InputController.hpp InputController.cpp
        MainWindow.hpp MainWindow.cpp Window.hpp Window.cpp)
target_link_libraries(Task5
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

