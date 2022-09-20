#include "PetriDish.h"

PetriDish::PetriDish(int size) : dish(size, std::vector<std::shared_ptr<Bacterium>>(size))
{
}

void PetriDish::displayDish()
{
	std::cout << "\n\n\n\n";
	for (auto e : dish){
		for (auto k : e) {
			if(k->getIsAlive() == true)
				std::cout << " " << k->getBacteriumSign() << " ";
			else if(k->getIsAlive() == false)
				std::cout << " " << '.' << " ";
		}
	std::cout<<std::endl;
	}
}


void PetriDish::initializeBoard()
{
	int xPos{0}, yPos{0};
	for (auto &e : dish) {
		for (auto &k : e) {
			int r = rand() % 4;
			if (r == 0) {
				k = std::make_shared<Bacterium>();
				//k->setPosition(xPos, yPos);
			}
			else if (r == 1) {
				k = std::make_shared<Spirillum>();
				k->setPosition(xPos, yPos);
			}
			else if (r == 2) {
				k = std::make_shared<Coccus>();
				k->setPosition(xPos, yPos);
			}
			
			else if (r == 3) {
				k = std::make_shared<Bacillus>();
				k->setPosition(xPos, yPos);
			}
			yPos++;
		}
		xPos++;
	}
}

void PetriDish::howManyBacterial()
{
	//std::cout << "Coccus: "		 << coccusPtr.use_count() << std::endl;
	//std::cout << "Spririllum: "	 << spirillumPtr.use_count() << std::endl;
	//std::cout << "Bacillus: "	 << bacillusPtr.use_count() << std::endl;
	//std::cout << "Empty: "		 << bacteriumPtr.use_count() << std::endl;
}

void PetriDish::isBacteriaAlive()
{
	// nearby, xPosotion, yPosition
	for (size_t xDish{ 0 }; xDish < dish.size(); xDish++) {
		for (size_t yDish{ 0 }; yDish < dish.size(); yDish++) {
			if (dish[xDish][yDish]->getBacteriumSign() == 'C') {
				int counter{ 0 };
				if (isInRange(xDish - 1, yDish) &&
					dish[xDish - 1][yDish]->getBacteriumSign() != 'C' &&
					dish[xDish - 1][yDish]->getBacteriumSign() != '.')
					counter++;
				if (isInRange(xDish + 1, yDish) &&
					dish[xDish + 1][yDish]->getBacteriumSign() != 'C' &&
					dish[xDish + 1][yDish]->getBacteriumSign() != '.')
					counter++;
				if (isInRange(xDish, yDish + 1) &&
					dish[xDish][yDish + 1]->getBacteriumSign() != 'C' &&
					dish[xDish][yDish +1]->getBacteriumSign() != '.')
					counter++;
				if (isInRange(xDish, yDish - 1) &&
					dish[xDish][yDish - 1]->getBacteriumSign() != 'C' &&
					dish[xDish][yDish - 1]->getBacteriumSign() != '.')
					counter++;

				if (counter > 1) dish[xDish][yDish]->setIsAlive(true);
				else {
					dish[xDish][yDish]->setIsAlive(false);
				}
				
			}

			// SPIRILLUM
			if (dish[xDish][yDish]->getBacteriumSign() == 'S') {
				for (int i{ 1 }; i <= 2; i++) {
					// sprawdzamy na lewo
					if (isInRange(xDish - i, yDish) &&
						dish[xDish - i][yDish]->getBacteriumSign() == 'B') {
						dish[xDish][yDish]->setIsAlive(false);
						break;
					}
					if (isInRange(xDish + i, yDish) &&
						dish[xDish - i][yDish]->getBacteriumSign() == 'B')
						dish[xDish][yDish]->setIsAlive(false);
				}
			}
		
		}
	}


}

bool PetriDish::isInRange(int x, int y)
{
	if (x >= 0 && y >= 0 && x < dish.size() && y < dish.size()) return true;
	else return false;
}
