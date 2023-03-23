cmake_minimum_required (VERSION 3.8)

project("asciilibur_project_template")

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(libs/asciilibur)

add_executable(asciilibur_project "main.cpp")
target_link_libraries(asciilibur_project asciilibur)

