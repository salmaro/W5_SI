#pragma once
#include "Dustbin.h"
#include "MetalGarbage.h"

class Dustbin9000 : public Dustbin
{
private:
	std::vector<MetalGarbage> plasticContent;
};

