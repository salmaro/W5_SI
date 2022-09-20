#include "PetriDish.h"
#include "Bacillus.h"
#include "Bacterium.h"
#include "Coccus.h"
#include "Spirillum.h"

#include <ctime>

int main() {

	//Bacterium* ptr1 = new Bacterium();
	//Bacterium* ptr2 = new Bacillus();
	//Bacterium* ptr3 = new Coccus();
	//Bacterium* ptr4 = new Spirillum();

	//delete ptr1;
	//delete ptr2;
	//delete ptr3;
	//delete ptr4;

	PetriDish talerz(50);
	talerz.initializeBoard();
	talerz.displayDish();
	//talerz.howManyBacterial();
	talerz.isBacteriaAlive();
	talerz.displayDish();
	talerz.clearDish();
	talerz.counterBacterial();





	return 0;
}