#include "InputComponent.h"
#include "Windows.h"

void InputComponent::ProcessInput() const
{
	int counter;
	// ReSharper disable once CppDefaultCaseNotHandledInSwitchStatement
	switch (GetKey(counter))
	{
		case VK_SPACE:
			TryToExecute("space");
			break;
		case VK_LEFT:
			TryToExecute("left", counter);
			break;
		case VK_RIGHT:
			TryToExecute("right", counter);
			break;
	}
}

void InputComponent::AddBinding(std::string key, OnKeyPressed onKeyPressed)
{
	_bindings.emplace(std::move(key), std::move(onKeyPressed));
}

void InputComponent::TryToExecute(const std::string& key, int times) const
{
	if (const auto func = _bindings.find(key); func != _bindings.end())
	{
		func->second();
	}
}

int InputComponent::GetKey(int& ct)
{
	INPUT_RECORD input;
	DWORD res;
	while (true)
	{
		ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &input, 1, &res);

		if (input.EventType != KEY_EVENT)
			continue;

		if (!input.Event.KeyEvent.bKeyDown)
			continue;

		ct = input.Event.KeyEvent.wRepeatCount;
		return input.Event.KeyEvent.wVirtualKeyCode;
	}
}
