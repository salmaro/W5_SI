#pragma once
#include "Bacterium.h"
#include "Coccus.h"
#include "Spirillum.h"
#include "Bacillus.h"
#include <vector>
#include <iostream>
#include <memory>

class PetriDish
{
private:

	std::vector<std::vector<std::shared_ptr<Bacterium>>> dish;
public:
	PetriDish(int size);
	void displayDish();
	void initializeBoard();
	void howManyBacterial();
	void isBacteriaAlive();
	bool isInRange(int x, int y);
	
};

