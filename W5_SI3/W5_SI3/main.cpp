#include "PetriDish.h"
#include "Bacillus.h"
#include "Bacterium.h"
#include "Coccus.h"
#include "Spirillum.h"
#include <windows.h>
#include <ctime>

int main() {
	PetriDish talerz(50);
	talerz.initializeBoard();
	talerz.displayDish();
	Sleep(4000);

	for (int i{ 0 }; i < 10; i++) {
		std::cout << "Turn: " << i << std::endl;
		//talerz.howManyBacterial();
		talerz.isBacteriaAlive();
		talerz.clearDish();
		talerz.displayDish();

		talerz.bacteriaPovielations();
		talerz.frankenstein();
		Sleep(3000);
		system("cls");
	}

	//talerz.displayDish();

	return 0;
}