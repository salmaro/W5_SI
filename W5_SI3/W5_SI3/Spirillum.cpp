#include "Spirillum.h"

char Spirillum::getBacteriumSign()
{
	return signOfBacteria;
}

void Spirillum::setPosition(int x, int y)
{
	xPosition = x;
	yPosition = y;
}

bool Spirillum::getIsAlive()
{
	return isAlive;
}

void Spirillum::setIsAlive(bool x)
{
	isAlive = x;
}
