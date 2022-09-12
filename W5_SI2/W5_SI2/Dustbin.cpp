#include "Dustbin.h"
#include <iostream>>
using namespace std;

void Dustbin::throwOutGarbage(Garbage inputGarbage)
{
	houseWasteContent.push_back(inputGarbage);
}

void Dustbin::throwOutPaperGarbage(PaperGarbage paperGarbage)
{
	if (!paperGarbage.getIsSqueezed())
		std::cout << "DustbinContentError" << std::endl;
	else
		paperContent.push_back(paperGarbage);

}

void Dustbin::throwOutPlasticGarbage(PlasticGarbage plasticGarbage)
{
	if (!plasticGarbage.getIsClean())
		std::cout << "DustbinContentError" << std::endl;
	else
		plasticContent.push_back(plasticGarbage);
}

void Dustbin::emptyContents()
{
	paperContent.clear();
	plasticContent.clear();
	houseWasteContent.clear();
}

