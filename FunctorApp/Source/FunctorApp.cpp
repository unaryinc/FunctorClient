#include "FunctorApp.hpp"

FunctorApp::FunctorApp()
{
	ServerPtr = std::make_unique<rpc::server>(3000);

	Tray.icon = TRAY_ICON1;
	Tray.menu = TrayMenu;
	tray_init(&Tray);

}

FunctorApp::~FunctorApp()
{
	tray_exit();

	std::cout << "~FunctorApp()" << std::endl;
}

void FunctorApp::Run()
{
	while (Running)
	{
		tray_loop(0);
	}
}

void FunctorApp::TrayOpen(tray_menu* item)
{
	std::cout << "Opening the app" << std::endl;
}

void FunctorApp::TrayQuit(tray_menu* item)
{
	Running = false;
}
