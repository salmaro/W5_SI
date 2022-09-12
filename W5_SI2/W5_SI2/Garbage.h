#pragma once
#include <string>
#include "garbage.cpp"

class Garbage {

	std::string name;

public:
	Garbage() = default;
	Garbage(std::string Name) {
		name = Name;
	}
};
