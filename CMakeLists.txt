# CompressETCTexture cmake file
# cmake -GXcode
# by dannyhe ver 0.0.1

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(CompressETCTexture)

SET(SRC_LIST main.cpp ETCCompress.cpp)

ADD_EXECUTABLE(CompressETCTexture ${SRC_LIST})

IF(WIN32)  
    MESSAGE(STATUS "Use ZLIB 1.2.5 in zlib_win32")
    INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/zlib_win32/include)
	TARGET_LINK_LIBRARIES(CompressETCTexture ${PROJECT_SOURCE_DIR}/zlib_win32/prebuilt/libzlib) 
	add_custom_command(TARGET CompressETCTexture POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different "${PROJECT_SOURCE_DIR}/zlib_win32/prebuilt/zlib1.dll" "${CMAKE_CURRENT_BINARY_DIR}")
ELSE(WIN32) 
FIND_PACKAGE(zlib)
IF(ZLIB_FOUND)  
	INCLUDE_DIRECTORIES(${ZLIB_INCLUDE_DIRS})
	TARGET_LINK_LIBRARIES(CompressETCTexture ${ZLIB_LIBRARIES}) 
ELSE(ZLIB_FOUND)  
	MESSAGE(FATAL_ERROR "ZLIB library not found")  
ENDIF(ZLIB_FOUND)  	
ENDIF(WIN32)