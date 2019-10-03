project(FunctorApp VERSION 1.0.0 DESCRIPTION "Functor App" LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCES Source/*.cpp)
file(GLOB_RECURSE HEADERS Source/*.hpp)

add_executable(FunctorApp ${SOURCES} ${HEADERS})

target_link_libraries(FunctorApp rpc)
