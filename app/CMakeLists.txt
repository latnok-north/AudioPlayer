cmake_minimum_required(VERSION 3.4.1)
set(LIB_DIR ${CMAKE_SOURCE_DIR}/src/main/cpp)


file(GLOB_RECURSE LOCAL_FILE "${LIB_DIR}/*.c" "${LIB_DIR}/*.cpp" "${LIB_DIR}/*.h")
add_library(player-lib
            SHARED
            ${LOCAL_FILE})

include_directories(${LIB_DIR}/)
include_directories(${LIB_DIR}/tools)
include_directories(${LIB_DIR}/player)
include_directories(${LIB_DIR}/j4a)
include_directories(${LIB_DIR}/j4a/player)
include_directories(${LIB_DIR}/utils)
target_link_libraries(player-lib android log)