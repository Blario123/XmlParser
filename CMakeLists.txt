cmake_minimum_required(VERSION 3.5)

project(XmlParser LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(PkgConfig REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Core)

pkg_check_modules(LIBXMLXX REQUIRED IMPORTED_TARGET libxml++-5.0)

include_directories("/usr/include/libxml++-5.0")

qt_add_resources(resources resources.qrc)

add_executable(XmlParser main.cpp ${resources})

target_link_libraries(XmlParser PkgConfig::LIBXMLXX Qt::Core)
