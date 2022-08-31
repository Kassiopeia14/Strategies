#pragma once

#include <iostream>

template <class Handler>
class NoMouseClickPolicy
{
public:

	NoMouseClickPolicy(Handler& handler) :
		handler_(handler)
	{
	}

	void onMouseClick()
	{
		;
	}

private:

	Handler& handler_;

};

template <class Handler>
class NormalMouseClickPolicy
{
public:

	NormalMouseClickPolicy(Handler& handler) :
		handler_(handler)
	{
	}

	void onMouseClick()
	{
		handler_.onMouseClick();
	}

private:

	Handler& handler_;

};

template <class Handler>
class NoCreatePolicy
{
public:

	NoCreatePolicy(Handler& handler) :
		handler_(handler)
	{
	}

	void onCreate()
	{
		;
	}

private:

	Handler& handler_;

};

template <class Handler>
class NormalCreatePolicy
{
public:

	NormalCreatePolicy(Handler& handler) :
		handler_(handler)
	{
	}

	void onCreate()
	{
		handler_.onCreate();
	}

private:

	Handler& handler_;

};

template <
	class Handler,
	template <class> class CreatePolicy = NoCreatePolicy,
	template <class> class MouseClickPolicy = NoMouseClickPolicy>

class Window : public CreatePolicy<Handler>, public MouseClickPolicy<Handler>
{
public:

	Window(Handler& handler) :
		CreatePolicy<Handler> (handler),
		MouseClickPolicy<Handler> (handler)
	{

	}

	void handleMessage(int messageCode)
	{

		MouseClickPolicy<Handler>& mouseClickPolicy = (MouseClickPolicy<Handler>&) *this;
		CreatePolicy<Handler>& createPolicy = (CreatePolicy<Handler>&) * this;

		switch (messageCode)
		{
		case 57:
			createPolicy.onCreate();
			break;
		case 43:
			mouseClickPolicy.onMouseClick();
			break;

		default:
			break;
		}
	}

private:
	/*
	void create()
	{
		handler_.onCreate();
		std::cout << "create" << std::endl;
	}

	void mouseClick()
	{
		handler_.onMouseClick();
		std::cout << "mouseClick" << std::endl;
	}*/
};
