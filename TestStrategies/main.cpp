#include "../modWindow/Window.h"

class UserHandler
{

public:
	void onCreate()
	{
		std::cout << "create" << std::endl;
	}

};

int main()
{
	UserHandler handler;

	Window<UserHandler, NormalCreatePolicy> window(handler);
	window.handleMessage(57);

	return 0;
}