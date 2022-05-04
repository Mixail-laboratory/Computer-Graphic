cmake_minimum_required(VERSION 3.21)
project(Task4)

set(CMAKE_PREFIX_PATH /home/mixail/Qt)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(OpenGL REQUIRED)

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

add_executable(scene main.cpp MyWidget.hpp MyWidget.cpp SquareWindow.hpp SquareWindow.cpp GLWindow.hpp GLWindow.cpp)
target_link_libraries(scene PRIVATE Qt5::Core Qt5::Widgets OpenGL::GL)

