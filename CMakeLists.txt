PROJECT(FrameWindow)

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

FILE(GLOB FrameWindow_SOURCE "./*.cpp")
FILE(GLOB example_SOURCE "example/*.cpp")

ADD_LIBRARY(FrameWindow STATIC ${FrameWindow_SOURCE})

ADD_EXECUTABLE(example ${example_SOURCE})

TARGET_LINK_LIBRARIES(example FrameWindow glfw3)

IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
	MESSAGE(STATUS "current platform: Linux ")
    TARGET_LINK_LIBRARIES(example dl GL X11 pthread)
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Windows")
	MESSAGE(STATUS "current platform: Windows")
    TARGET_LINK_LIBRARIES(example opengl32)
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
	MESSAGE(STATUS "current platform: FreeBSD")
ELSE ()
	MESSAGE(STATUS "other platform: ${CMAKE_SYSTEM_NAME}")
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Linux")
