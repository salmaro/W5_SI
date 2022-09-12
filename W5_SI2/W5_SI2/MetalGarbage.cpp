#include "MetalGarbage.h"

MetalGarbage::MetalGarbage() : isPinkCap{ false }
{
}

bool MetalGarbage::getIsPinkCap()
{
	return isPinkCap;
}

void MetalGarbage::throwOutMetalGarbage(MetalGarbage metalGarbage)
{
	if (!metalGarbage.getIsPinkCap())
		std::cout << "DustbinContentError" << std::endl;
	else
		metalContent.push_back(metalGarbage);

}
