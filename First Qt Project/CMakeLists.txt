cmake_minimum_required(VERSION 3.13)
project(First_Qt_Project)

set(CMAKE_CXX_STANDARD 14)

find_package(Qt5Widgets REQUIRED)
include_directories(${Qt5Widgets_INCLUDE_DIRS})
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")
qt5_generate_moc(main.cpp main.moc)

add_executable(First_Qt_Project main.cpp MainWindow.cpp MainWindow.cpp MainWindow.h)

target_link_libraries(First_Qt_Project Qt5::Widgets)