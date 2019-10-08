#pragma once

#include "Config.hpp"

#include <string>
#include <rpc/server.h>

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <functional>
#include <thread>

#ifdef _WIN32
	#define TRAY_WINAPI 1
#endif

#include <tray.h>

class FunctorApp
{

	private:

		bool Running = true;

		std::unique_ptr<rpc::server> ServerPtr;

		tray Tray;

		tray_menu TrayMenu[4] =
		{
			{"Open client", 0, 0, std::bind(&FunctorApp::TrayOpen, this, std::placeholders::_1), NULL},
			{"-", 0, 0, NULL, NULL},
			{"Quit", 0, 0, std::bind(&FunctorApp::TrayQuit, this, std::placeholders::_1), NULL},
			{NULL, 0, 0, NULL, NULL}
		};

		void TrayOpen(tray_menu* item);
		void TrayQuit(tray_menu* item);

	public:

		FunctorApp();
		~FunctorApp();

		void Run();
};
