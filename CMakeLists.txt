cmake_minimum_required(VERSION 2.8.4)
project(swegtop)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -Werror -Wextra -std=c++11")

include_directories(back)

set(SOURCE_FILES
        front/cli/main.cpp
        back/Memory.cpp
        back/Memory.hpp
        back/CPU.cpp
        back/CPU.hpp
        back/SysInfo.cpp
        back/SysInfo.hpp
        back/Network.cpp
        back/Network.hpp
        )

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
