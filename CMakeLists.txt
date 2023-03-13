cmake_minimum_required(VERSION 3.15)
project(JSON)

add_executable(Test Json.c JsonTest.c main.c)

if(MSVC)
    target_compile_options(Test PRIVATE /W4 /WX)
else()
    target_compile_options(Test PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()

add_definitions(-D_CRT_SECURE_NO_WARNINGS) # disable MSVC warnings for unsafe functions, e.g. sscanf
