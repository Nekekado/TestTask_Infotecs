cmake_minimum_required(VERSION 2.8...3.13)

project ("Infotecs")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -finput-charset=UTF-8 -fexec-charset=UTF-8")

# Включите подпроекты.
add_subdirectory ("ProgramTwo")
add_subdirectory ("ProgramOne")
add_subdirectory ("Library")
add_subdirectory("data")
