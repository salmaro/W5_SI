#pragma once
#include "Bacterium.h"
#include <iostream>
class Coccus :
    public Bacterium
{
public:
    Coccus() { distance = 1;  signOfBacteria = 'C';}
    virtual ~Coccus() = default;
    virtual char getBacteriumSign() override;
    virtual bool checkNearby() override;
    virtual void setPosition(int x, int y) override;
    virtual bool getIsAlive() override;
    virtual void setIsAlive(bool x) override;
};

