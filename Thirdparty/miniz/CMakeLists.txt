project(miniz VERSION 1.0.0 DESCRIPTION "miniz CMake wrapper" LANGUAGES C)

file(GLOB_RECURSE SOURCES *.c)
file(GLOB_RECURSE HEADERS *.h)

add_library(miniz ${SOURCES} ${HEADERS})