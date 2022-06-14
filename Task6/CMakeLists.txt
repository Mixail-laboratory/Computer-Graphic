cmake_minimum_required(VERSION 3.21)
project(Task6)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Task6 main.cpp Sphere.cpp Sphere.hpp SphereWindow.cpp SphereWindow.hpp GLWindow.hpp GLWindow.cpp)
target_link_libraries(Task6
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

