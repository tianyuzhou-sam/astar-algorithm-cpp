
cmake_minimum_required(VERSION 3.10)
project(astar)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

# set the g++ compiler flags
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# include header directories
include_directories(
   ${CMAKE_SOURCE_DIR}/include)

# find all the header files
file(GLOB HEADER_FILES include/*.h)

# add the main file as executable
# add_executable(test src/findpath_main.cpp ${HEADER_FILES})
add_executable(main src/main.cpp src/find_path.cpp ${HEADER_FILES})
