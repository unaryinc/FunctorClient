#pragma once

#if defined (_WIN32) || defined (_WIN64)
	#define FUNCTOR_WINAPI 1
#elif defined (__linux__) || defined (linux) || defined (__linux)
	#define FUNCTOR_WINAPI 1
#elif defined (__APPLE__) || defined (__MACH__)
	#define FUNCTOR_WINAPI 1
#endif

#ifdef _WIN32
	#define FUNCTOR_API  __declspec( dllexport )
#else
	#define FUNCTOR_API
#endif
