#pragma once
#include <string>
#include "PaperGarbage.h"
#include "PlasticGarbage.h"
#include "Garbage.h"
#include "Dustbin.cpp"
#include <vector>


class Dustbin
{
public:
	std::string color = "grey";
	std::vector<PaperGarbage> paperContent;
	std::vector<PlasticGarbage> plasticContent;
	std::vector<Garbage> houseWasteContent;
public:
	Dustbin() = default;
	void throwOutGarbage(Garbage inputGarbage);
	void throwOutPaperGarbage(PaperGarbage paperGarbage);
	void throwOutPlasticGarbage(PlasticGarbage PlasticGarbage);
	void emptyContents();
};
