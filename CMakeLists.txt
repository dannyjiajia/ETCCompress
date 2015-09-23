# CompressETCTexture cmake file
# cmake -GXcode
# by dannyhe ver 0.0.1

cmake_minimum_required(VERSION 2.6)

project(CompressETCTexture)

set(SRC_LIST main.cpp ETCCompress.cpp)

add_executable(CompressETCTexture ${SRC_LIST})

#zlib
find_package(zlib REQUIRED)
include_directories(${ZLIB_INCLUDE_DIRS})
target_link_libraries(CompressETCTexture ${ZLIB_LIBRARIES})