project(tray VERSION 1.0.0 DESCRIPTION "tray CMake wrapper" LANGUAGES C)

add_library(tray INTERFACE)
target_sources(tray INTERFACE "${PROJECT_SOURCE_DIR}/tray.h")