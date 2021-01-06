cmake_minimum_required (VERSION 3.8)

project ("Aero Engine")

add_subdirectory ("AeroCore")

add_executable(Aero main.cpp)

install(TARGETS Aero DESTINATION "${CMAKE_SOURCE_DIR}/out/bin/win64/")