#include "Bacillus.h"

char Bacillus::getBacteriumSign()
{
    return signOfBacteria;
}

bool Bacillus::checkNearby()
{
   // if (xPosition )
    return false;
}

void Bacillus::setPosition(int x, int y)
{
    xPosition = x;
    yPosition = y;
}

bool Bacillus::getIsAlive()
{
    return isAlive;
}

void Bacillus::setIsAlive(bool x)
{
    isAlive = x;
}
