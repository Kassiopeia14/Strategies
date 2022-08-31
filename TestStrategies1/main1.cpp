#include "../modWindow/Window.h"

class UserHandler
{

public:
	void onCreate()
	{
		std::cout << "create1" << std::endl;
	}

	void onMouseClick()
	{
		std::cout << "mouseClick1" << std::endl;
	}

};

int main()
{
	UserHandler handler;

	Window<UserHandler, NormalCreatePolicy, NormalMouseClickPolicy> window(handler);
	window.handleMessage(57);
	window.handleMessage(43);

	return 0;
}