cmake_minimum_required(Version 3.10)
project(VISUAL_CamPROG_Proto)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/bin)

#    This include lib, etc .. from SDK
#      --  Checking kernel format  --
if(WIN32)
    include_directories(CameraSDK/windows/SDK/include)
    link_directories(CameraSDK/windows/SDK/lib/win_x64)
    set(PLATFORM_LIBS ws2_32)
else()
    include_directories(CameraSDK/linux/SDK/include)
    link_directories(CameraSDK/linux/SDK/lib/linux_x64)
    set(PLATFORM_LIBS pthread)
endif()

#     PROJECT HEADER
include_directories(include)

#     OPENCV
find_package(OpenCV)
if(OpenCV_FOUND)
    message(STATUS "FOUND OpenCV : ${OpenCV_VERSION}")
    include_directories(${OpenCV_INCLUDE_DIRS})
    link_directories(${OpenCV_LIB_DIR})
    list(APPEND LIBS ${OpenCV_LIBS})
    add_definitions(-DHAS_OPENCV)
endif()

#     SRC [ SOURCE FILE ]

set(SOURCES
    src/main.cpp
      
)

add_executable(VISUAL_CamPROG_Proto ${SOURCES})
target_link_libraries(VISUAL_CamPROG_Proto LxCameraApi LxDataProcess ${PLATFORM_LIBS})
