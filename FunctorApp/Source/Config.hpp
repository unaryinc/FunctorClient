#pragma once

#if defined (_WIN32) || defined (_WIN64)
	#define FUNCTOR_WINDOWS 1
#elif defined (__linux__) || defined (linux) || defined (__linux)
	#define FUNCTOR_LINUX 1
#elif defined (__APPLE__) || defined (__MACH__)
	#define FUNCTOR_MAC 1
#endif

#if FUNCTOR_LINUX
	#define TRAY_ICON1 "Functor"
	#define TRAY_ICON2 "Functor"
#elif FUNCTOR_MAC
	#define TRAY_ICON1 "Functor.png"
	#define TRAY_ICON2 "Functor.png"
#elif FUNCTOR_WINDOWS
	#define TRAY_ICON1 "Functor.ico"
	#define TRAY_ICON2 "Functor.ico"
#endif