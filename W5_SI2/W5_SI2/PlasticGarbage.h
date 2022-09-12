#pragma once
#include "Garbage.h"
#include "PlasticGarbage.cpp"
#include <string>

class PlasticGarbage : public Garbage {

private:
	bool isClean;

public:
	PlasticGarbage(): isClean { false }{
	}
	void clean();
	bool getIsClean();

};
