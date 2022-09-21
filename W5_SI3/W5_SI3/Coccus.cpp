#include "Coccus.h"

char Coccus::getBacteriumSign()
{
    return signOfBacteria;
}

bool Coccus::checkNearby()
{
    return false;
}

void Coccus::setPosition(int x, int y)
{
    xPosition = x;
    yPosition = y; 

}

bool Coccus::getIsAlive()
{
    return isAlive;
}

void Coccus::setIsAlive(bool x)
{
    isAlive = x;
}
