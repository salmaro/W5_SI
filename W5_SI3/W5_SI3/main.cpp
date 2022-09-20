#include "PetriDish.h"
#include "Bacillus.h"
#include "Bacterium.h"
#include "Coccus.h"
#include "Spirillum.h"

#include <ctime>

int main() {


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