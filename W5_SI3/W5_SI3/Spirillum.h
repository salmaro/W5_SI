#pragma once
#include "Bacterium.h"
#include <iostream>
class Spirillum :
    public Bacterium
{
public:
    Spirillum() { distance = 2; signOfBacteria = 'S';}
    virtual ~Spirillum() = default;
    virtual char getBacteriumSign() override;
    virtual void setPosition(int x, int y) override;
    virtual bool getIsAlive() override;
    virtual void setIsAlive(bool x);
  
};

