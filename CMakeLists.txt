cmake_minimum_required(VERSION 3.20)
project(BasicQtApp LANGUAGES CXX)

# The compiler will be set by environment variables

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(BasicQtApp main.cpp)
target_link_libraries(BasicQtApp PRIVATE Qt5::Widgets)
