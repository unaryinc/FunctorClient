cmake_minimum_required(VERSION 3.9)
#=======================================================================#
project(FunctorClient VERSION 1.0.0 DESCRIPTION "Functor client" LANGUAGES CXX)
#=======================================================================#
set(CMAKE_CXX_STANDARD 17)
#=======================================================================#
if("${CMAKE_SIZEOF_VOID_P}" EQUAL "8")
	set(ARCHITECTURE "x64")
else()
	set(ARCHITECTURE "x32")
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
	set(BUILD_VER "d")
else()
	set(BUILD_VER "")
endif()

#=======================================================================#
if(MSVC)
	add_definitions(-D_CRT_SECURE_NO_WARNINGS)
	set(CompilerFlags
			CMAKE_CXX_FLAGS
			CMAKE_CXX_FLAGS_DEBUG
			CMAKE_CXX_FLAGS_RELEASE
			CMAKE_C_FLAGS
			CMAKE_C_FLAGS_DEBUG
			CMAKE_C_FLAGS_RELEASE
			)
	foreach(CompilerFlag ${CompilerFlags})
	  string(REPLACE "/MD" "/MT" ${CompilerFlag} "${${CompilerFlag}}")
	endforeach()
	set(EXECUTABLE ".exe")
	set(RUNTIME ".dll")
	set(OS "Windows")
	set(LIB_PREFIX "")
	set(ICON ".ico")
endif()
#=======================================================================#
set(OUTPUT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Output/${OS}/${ARCHITECTURE}")
#=======================================================================#
set(RPCLIB_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Thirdparty/rpclib-2.2.1")
set(TRAY_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Thirdparty/tray")
set(RAPIDJSON_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Thirdparty/rapidjson")
set(ZLIB_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Thirdparty/zlib")
set(MINIZ_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Thirdparty/miniz")
#========	SET THIS VARIABLE ACCORDING TO YOUR CEF BUILD PATH	========#
set(CEF_ROOT_DIR "C:/cef")
#=======================================================================#
add_subdirectory(${RPCLIB_ROOT_DIR})
add_subdirectory(${TRAY_ROOT_DIR})
add_subdirectory(${ZLIB_ROOT_DIR})
add_subdirectory(${MINIZ_ROOT_DIR})
add_subdirectory(FunctorApp)
add_subdirectory(FunctorAPI)
add_subdirectory(FunctorUpdater)
#=======================================================================#

add_custom_target(Final ALL)
add_dependencies(Final FunctorApp FunctorAPI FunctorUpdater)

add_custom_command(TARGET Final POST_BUILD
	COMMAND ${CMAKE_COMMAND}
	-E copy_if_different
	"${CMAKE_CURRENT_SOURCE_DIR}/build/FunctorAPI/FunctorAPI${RUNTIME}" 
	"${OUTPUT_DIR}/FunctorAPI${ARCHITECTURE}${BUILD_VER}${RUNTIME}"
	COMMAND ${CMAKE_COMMAND}
	-E copy_if_different
	"${CMAKE_CURRENT_SOURCE_DIR}/build/FunctorApp/FunctorApp${EXECUTABLE}" 
	"${OUTPUT_DIR}/FunctorApp${ARCHITECTURE}${BUILD_VER}${EXECUTABLE}"
	COMMAND ${CMAKE_COMMAND}
	-E copy_if_different
	"${CMAKE_CURRENT_SOURCE_DIR}/build/FunctorUpdater/FunctorUpdater${EXECUTABLE}" 
	"${OUTPUT_DIR}/FunctorUpdater${ARCHITECTURE}${BUILD_VER}${EXECUTABLE}"
)