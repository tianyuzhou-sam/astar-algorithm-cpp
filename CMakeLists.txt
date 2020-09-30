
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

# add the main file as executable

file(GLOB HEADER_FILES include/*.h)
#add_executable(${PROJECT_NAME} ${SRCFILES})
add_executable(main src/findpath.cpp ${HEADER_FILES})

# add_executable(minpathbucharest ${CMAKE_SOURCE_DIR}/src/min_path_to_Bucharest.cpp)
# add_executable(8puzzle ${CMAKE_SOURCE_DIR}/src/8puzzle.cpp)
# add_executable(tests ${CMAKE_SOURCE_DIR}/src/tests.cpp)