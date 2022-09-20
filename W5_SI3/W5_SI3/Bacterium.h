#pragma once
#include <iostream>
class Bacterium
{
protected:
	int distance{};
	int xPosition{};
	int yPosition{};
	char signOfBacteria = '.';
	bool isAlive{ true };
public:
	virtual void setPosition(int x, int y);
	virtual ~Bacterium() = default;
	virtual char getBacteriumSign();
	virtual bool checkNearby();
	virtual bool getIsAlive();
	virtual void setIsAlive(bool x);


};

