#include <iostream>
#include <rpc/client.h>

class API
{

	private:

		std::unique_ptr<rpc::client> ClientPtr;

	public:

		API();
		~API();

		void Test();
};