project(FunctorApp VERSION 1.0.0 DESCRIPTION "Functor App" LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 17)

include_directories (${RPCLIB_ROOT_DIR}/include)
include_directories (${TRAY_ROOT_DIR})

file(GLOB_RECURSE SOURCES Source/*.cpp)
file(GLOB_RECURSE HEADERS Source/*.hpp)

add_executable(FunctorApp ${SOURCES} ${HEADERS} Resource.rc)

target_link_libraries(FunctorApp rpc)