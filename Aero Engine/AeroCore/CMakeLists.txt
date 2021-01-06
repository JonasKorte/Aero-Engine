cmake_minimum_required(VERSION 3.8)

project("Aero Engine")

add_library(libcore SHARED core.cpp)

set(PUBLIC_HEADERS
    core.h
)

install(TARGETS libcore DESTINATION "${CMAKE_SOURCE_DIR}/out/bin/win64")
install(FILES ${PUBLIC_HEADERS} DESTINATION "${CMAKE_SOURCE_DIR}/out/include")