#pragma once
#include "Bacterium.h"
#include <iostream>
class Bacillus :
	public Bacterium
{
	
public: 
	Bacillus() { distance = 3; signOfBacteria = 'B'; };
	virtual ~Bacillus() = default;
	virtual char getBacteriumSign() override;
	bool checkNearby();
	virtual void setPosition(int x, int y) override;
	virtual bool getIsAlive() override;
	virtual void setIsAlive(bool x) override;
};

