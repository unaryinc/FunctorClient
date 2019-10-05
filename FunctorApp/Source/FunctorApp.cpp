#include "FunctorApp.hpp"

bool FunctorApp::Running = true;

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
}

void FunctorApp::TrayOpen(tray_menu *item)
{
	std::cout << "Opening the app" << std::endl;
}

void FunctorApp::TrayQuit(tray_menu* item)
{
	Running = false;
}

void FunctorApp::Run()
{

	int i = 0;

	while (Running)
	{
		tray_loop(0);
		std::cout << i << std::endl;
		++i;
	}

	//ServerPtr->bind("test", )

	/*
	auto app = App::Create();
	auto window = Window::Create(app->main_monitor(), 300, 300, false, kWindowFlags_Titled);

	window->SetTitle("Tutorial 2 - Basic App");
	app->set_window(window);

	auto overlay = Overlay::Create(window, window->width(), window->height(), 0, 0);
	overlay->view()->LoadHTML("<center>Hello World!</center>");

	app->Run();
	*/
}