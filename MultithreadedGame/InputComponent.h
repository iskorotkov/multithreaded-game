#pragma once
#include <string>
#include <functional>
#include <map>

using OnKeyPressed = std::function<void()>;

class InputComponent
{
public:
	void ProcessInput() const;
	void AddBinding(std::string key, OnKeyPressed onKeyPressed);

private:
	std::map<std::string, OnKeyPressed> _bindings;

	void TryToExecute(const std::string& key, int times = 1) const;
	static int GetKey(int& ct);
};
