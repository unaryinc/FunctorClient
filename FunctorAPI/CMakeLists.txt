project(FunctorAPI VERSION 1.0.0 DESCRIPTION "Functor API" LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 17)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

include_directories (${RPCLIB_ROOT_DIR}/include)

file(GLOB_RECURSE SOURCES Source/*.cpp)
file(GLOB_RECURSE HEADERS Source/*.hpp)

add_library(FunctorAPI SHARED ${SOURCES} ${HEADERS})

target_link_libraries(FunctorAPI rpc)