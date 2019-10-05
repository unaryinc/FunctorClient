#include "API.hpp"

API::API()
{

	ClientPtr = std::make_unique<rpc::client>("localhost", 3000);

	ClientPtr->call("connect").as<bool>();

	std::cout << "API();" << std::endl;
	Test();
}

void API::Test()
{
	std::cout << "This is a function from C++ DLL that writes this line in console" << std::endl;
}

API::~API()
{
	std::cout << "~API();" << std::endl;
}