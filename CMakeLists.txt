cmake_minimum_required(VERSION 3.20)

# ИСПРАВЛЕНИЕ: Подключаем тулчейн Raspberry Pi ТОЛЬКО если мы НЕ на Windows
if (NOT WIN32)
    set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/rpi5.toolchain.cmake")
endif()

project(projectFMQT)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-fPIC -Wall -Wextra -pedantic -static-libgcc -static-libstdc++")

# Глобально включаем генераторы кода Qt для ВСЕХ таргетов и подпапок
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if (WIN32)
    set(CMAKE_PREFIX_PATH "C:/Qt/5.15.2/mingw81_64")
endif(WIN32)

# Находим пакеты ОДИН раз на глобальном уровне
find_package(Qt5 COMPONENTS Core Gui Widgets WebSockets REQUIRED)

message(STATUS "TEST STRING   " ${CMAKE_SOURCE_DIR})

include_directories("${CMAKE_SOURCE_DIR}/sourceFiles")
include_directories("${CMAKE_SOURCE_DIR}/QTSourceFiles")
# Сначала подключаем поддиректорию, чтобы MainLib была видна основному файлу
add_subdirectory(sourceFiles)
add_subdirectory(QTSourceFiles)

# Исполняемый файл собирает ТОЛЬКО корневые файлы! Никаких sourceFiles/ внутри него!
add_executable(projectFMQT
        main.cpp
        QTSourceFiles/qtgeneralwindows.cpp
)

# Линкуем все вместе (MainLib передаст свои 21+ файлов сюда)
target_link_libraries(projectFMQT
        PRIVATE
#        MainLib
        QTlib
)

#if (WIN32)
 #   target_compile_options(projectFMQT PRIVATE -static-libstdc++ -static-libgcc)
#endif(WIN32)

if (WIN32 AND NOT EXISTS "${CMAKE_TOOLCHAIN_FILE}")
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
    foreach (QT_LIB Core Gui Widgets WebSockets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt5${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()