project (FrameWindow)

cmake_minimum_required (VERSION 3.10.2)

file (GLOB FrameWindow_SOURCE "./*.cpp")
file (GLOB example_SOURCE "example/*.cpp")

add_library (FrameWindow STATIC ${FrameWindow_SOURCE})

add_executable (example ${example_SOURCE})

target_link_libraries (example FrameWindow glfw3)

if (CMAKE_SYSTEM_NAME MATCHES "Linux")
	message(STATUS "current platform: Linux ")
    target_link_libraries (example dl GL X11 pthread)
elseif (CMAKE_SYSTEM_NAME MATCHES "Windows")
	message (STATUS "current platform: Windows")
    target_link_libraries (example opengl32)
elseif (CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
	message (STATUS "current platform: FreeBSD")
else ()
	message (STATUS "other platform: ${CMAKE_SYSTEM_NAME}")
endif ()
