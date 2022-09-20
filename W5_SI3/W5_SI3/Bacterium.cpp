#include "Bacterium.h"

void Bacterium::setPosition(int x, int y)
{
    xPosition = x;
    yPosition = y;
}

char Bacterium::getBacteriumSign()
{
    return signOfBacteria;
}

bool Bacterium::checkNearby()
{
    return false;
}

bool Bacterium::getIsAlive()
{
    return isAlive;
}

void Bacterium::setIsAlive(bool x)
{
    isAlive = x;
}
