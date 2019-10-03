#include "API.hpp"

API::API()
{
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