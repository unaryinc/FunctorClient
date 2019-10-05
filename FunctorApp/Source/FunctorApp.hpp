#pragma once

#include "Config.hpp"

#include <string>
#include <rpc/server.h>

#include <Ultralight/Ultralight.h>
#include <AppCore/App.h>
#include <AppCore/Window.h>
#include <AppCore/Overlay.h>

#include <stdio.h>
#include <string.h>
#include <iostream>

#ifdef _WIN32
	#define TRAY_WINAPI 1
#endif

#include <tray.h>


class FunctorApp
{
	private:

		static bool Running;

		std::unique_ptr<rpc::server> ServerPtr;

		tray Tray;

		tray_menu TrayMenu[4] =
		{
			{"Open client", 0, 0, &FunctorApp::TrayOpen, NULL},
			{"-", 0, 0, NULL, NULL},
			{"Quit", 0, 0, &FunctorApp::TrayQuit, NULL},
			{NULL, 0, 0, NULL, NULL}
		};

		static void TrayOpen(tray_menu *item);
		static void TrayQuit(tray_menu *item);

	public:

		FunctorApp();
		~FunctorApp();

		void Run();
};