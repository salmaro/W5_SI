#pragma once
#include "Garbage.h"
#include <iostream>
#include <vector>

class MetalGarbage : public Garbage
{
	bool isPinkCap;
	std::vector<MetalGarbage> metalContent;

public:
	MetalGarbage();
	bool getIsPinkCap();
	void throwOutMetalGarbage(MetalGarbage metalGarbage);
};

