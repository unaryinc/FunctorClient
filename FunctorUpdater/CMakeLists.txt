project(FunctorUpdater VERSION 1.0.0 DESCRIPTION "Functor Updater" LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 17)

include_directories (${RAPIDJSON_ROOT_DIR})

file(GLOB_RECURSE SOURCES Source/*.cpp)
file(GLOB_RECURSE HEADERS Source/*.hpp)

add_executable(FunctorUpdater ${SOURCES} ${HEADERS})

target_link_libraries(FunctorUpdater zlibstatic)