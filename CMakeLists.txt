cmake_minimum_required(VERSION 3.22)
project(Memory)

set(CMAKE_CXX_STANDARD 14)

add_executable(Memory main.cpp Memory_Commands.cpp Memory_Commands.h Field.cpp Field.h Memory_Viewer.cpp Memory_Viewer.h Memory_Control.cpp Memory_Control.h Gravity_memory.cpp Gravity_memory.h High_score.cpp High_score.h Triple_memory.cpp Triple_memory.h Triple_memory_gravity.cpp Triple_memory_gravity.h)
