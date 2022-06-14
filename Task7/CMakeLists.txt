cmake_minimum_required(VERSION 3.21)
project(Task7)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/home/mixail/qt")
add_definitions(-DGL_SILENCE_DEPRECATION)

find_package(OpenGL REQUIRED)

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)
find_package(glm REQUIRED)

add_executable(Task7 main.cpp cubesettingswindow.cpp cubesettingswindow.h  CubeWindow.cpp CubeWindow.h
        mainwindow.cpp mainwindow.h openglwindow.cpp openglwindow.h Params.h parser.cpp parser.h
        sphere.cpp sphere.h SphereWindow.cpp SphereWindow.h)
target_link_libraries(Task7 PRIVATE
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        OpenGL::GL
        glm::glm)

