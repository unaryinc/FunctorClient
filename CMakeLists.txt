cmake_minimum_required(VERSION 3.9)
#=======================================================================#
project(FunctorClient VERSION 1.0.0 DESCRIPTION "Functor client" LANGUAGES CXX)
#=======================================================================#
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
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

set(FILE_PREFIX ${ARCHITECTURE}${BUILD_VER})
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
	  string(REPLACE "/W3" "/W0" ${CompilerFlag} "${${CompilerFlag}}")
	endforeach()
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
set(ULTRALIGHT_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Thirdparty/ultralight")
set(TRAY_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Thirdparty/tray")
#=======================================================================#
add_subdirectory(${RPCLIB_ROOT_DIR})
add_subdirectory(${TRAY_ROOT_DIR})
add_subdirectory(FunctorApp)
add_subdirectory(FunctorAPI)
#=======================================================================#

add_custom_target(Final ALL)
add_dependencies(Final FunctorApp FunctorAPI)

add_custom_command(TARGET Final POST_BUILD
	COMMAND ${CMAKE_COMMAND} 
	-E remove_directory 
	"${OUTPUT_DIR}"
	COMMAND ${CMAKE_COMMAND} 
	-E make_directory 
	"${OUTPUT_DIR}"
	#Copy files
	COMMAND ${CMAKE_COMMAND}
	-E copy 
	"${CMAKE_CURRENT_SOURCE_DIR}/build/FunctorAPI/FunctorAPI${RUNTIME}" 
	"${OUTPUT_DIR}/FunctorAPI${FILE_PREFIX}${RUNTIME}"
	#Copy files
	COMMAND ${CMAKE_COMMAND}
	-E copy 
	"${CMAKE_CURRENT_SOURCE_DIR}/build/FunctorApp/FunctorApp${EXECUTABLE}" 
	"${OUTPUT_DIR}/FunctorApp${FILE_PREFIX}${EXECUTABLE}"
	COMMAND ${CMAKE_COMMAND}
	-E copy 
	"${CMAKE_CURRENT_SOURCE_DIR}/Thirdparty/ultralight/bin/${OS}/${ARCHITECTURE}/${LIB_PREFIX}AppCore${RUNTIME}" 
	"${OUTPUT_DIR}"
	COMMAND ${CMAKE_COMMAND}
	-E copy 
	"${CMAKE_CURRENT_SOURCE_DIR}/Thirdparty/ultralight/bin/${OS}/${ARCHITECTURE}/${LIB_PREFIX}UltralightCore${RUNTIME}" 
	"${OUTPUT_DIR}"
	COMMAND ${CMAKE_COMMAND}
	-E copy 
	"${CMAKE_CURRENT_SOURCE_DIR}/Thirdparty/ultralight/bin/${OS}/${ARCHITECTURE}/${LIB_PREFIX}Ultralight${RUNTIME}" 
	"${OUTPUT_DIR}"
	COMMAND ${CMAKE_COMMAND}
	-E copy 
	"${CMAKE_CURRENT_SOURCE_DIR}/Thirdparty/ultralight/bin/${OS}/${ARCHITECTURE}/${LIB_PREFIX}WebCore${RUNTIME}" 
	"${OUTPUT_DIR}"
	COMMAND ${CMAKE_COMMAND}
	-E copy 
	"${CMAKE_CURRENT_SOURCE_DIR}/FunctorApp/Functor${ICON}" 
	"${OUTPUT_DIR}"
)