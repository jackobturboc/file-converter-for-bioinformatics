cmake_minimum_required(VERSION 3.29)
project(projectFMQT)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-fPIC -Wall  -Wextra -pedantic -static-libgcc -static-libstdc++")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if (WIN32)
    set(CMAKE_PREFIX_PATH "C:/Qt/5.15.2/mingw81_64")
endif(WIN32)

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

message(STATUS "TEST STRING   " ${CMAKE_SOURCE_DIR})

include_directories(${Qt5Widgets_INCLUDE_DIRS})
include_directories("${CMAKE_SOURCE_DIR}/sourceFiles")
add_subdirectory(sourceFiles)

add_executable(projectFMQT main.cpp
        sourceFiles/qtgeneralwindows.cpp
)

target_link_libraries(projectFMQT
        PRIVATE
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        MainLib
)

if (WIN32)
    target_compile_options(projectFMQT PRIVATE -static-libstdc++ -static-libgcc)
endif(WIN32)

if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt5${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()