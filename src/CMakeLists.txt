cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

project(server LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# hack for buggy CMake's FindwxWidgets script
if(DEFINED ENV_WX_CONFIG)
    set(ENV{WX_CONFIG} ${ENV_WX_CONFIG})
endif()

set(wxWidgets_USE_STATIC 1)

find_package(wxWidgets REQUIRED)

set(OpenCV_DIR C:/opencv/build)
find_package(OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )

set(SRCS server.cpp)

include(${wxWidgets_USE_FILE})

if(APPLE)
    # create bundle on apple compiles
    add_executable(server MACOSX_BUNDLE ${SRCS})

    # Set a custom plist file for the app bundle - needed for Mac OS Retina display
    set_target_properties(server PROPERTIES MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/Info.plist)
else()
    # the WIN32 is needed for Windows in order for it to look for WinMain
    # instead of the main function. This is ignored on other systems,
    # so it works on all platforms
    add_executable(server WIN32 ${SRCS} main.exe.manifest)
endif()

target_link_libraries(server PRIVATE ${wxWidgets_LIBRARIES} ${OpenCV_LIBS} ws2_32)


#.......................................................


project(client LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# hack for buggy CMake's FindwxWidgets script
if(DEFINED ENV_WX_CONFIG)
    set(ENV{WX_CONFIG} ${ENV_WX_CONFIG})
endif()

set(wxWidgets_USE_STATIC 1)

find_package(wxWidgets REQUIRED)

set(SRCS client.cpp)

include(${wxWidgets_USE_FILE})

if(APPLE)
    # create bundle on apple compiles
    add_executable(client MACOSX_BUNDLE ${SRCS})

    # Set a custom plist file for the app bundle - needed for Mac OS Retina display
    set_target_properties(client PROPERTIES MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/Info.plist)
else()
    # the WIN32 is needed for Windows in order for it to look for WinMain
    # instead of the main function. This is ignored on other systems,
    # so it works on all platforms
    add_executable(client WIN32 ${SRCS} main.exe.manifest)
endif()

target_link_libraries(client PRIVATE ${wxWidgets_LIBRARIES})
