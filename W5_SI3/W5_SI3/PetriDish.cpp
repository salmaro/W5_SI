#include "PetriDish.h"

PetriDish::PetriDish(int size) : dish(size, std::vector<std::shared_ptr<Bacterium>>(size))
{
}

void PetriDish::displayDish()
{
	std::cout << "\n\n\n\n";
	for (auto e : dish) {
		for (auto k : e) {
			if (k->getIsAlive() == true)
				std::cout << " " << k->getBacteriumSign() << " ";
			else if (k->getIsAlive() == false)
				std::cout << " " << '.' << " ";
		}
		std::cout << std::endl;
	}
	bacillus = 0;
	coccus = 0;
	spirillum = 0;
	bacterium = 0;
	counterBacterial();
	printNumberOfBactirum();
}


void PetriDish::initializeBoard()
{
	srand(time(0));
	int xPos{ 0 }, yPos{ 0 };
	for (auto& e : dish) {
		for (auto& k : e) {
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

			//COCCUS
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
					dish[xDish][yDish + 1]->getBacteriumSign() != '.')
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

			//SPIRILLUM
			if (dish[xDish][yDish]->getBacteriumSign() == 'S') {
				for (int i{ 1 }; i <= 2; i++) {
					// sprawdzamy na lewo
					if (isInRange(xDish - i, yDish) &&
						dish[xDish - i][yDish]->getBacteriumSign() == 'B') {
						dish[xDish][yDish]->setIsAlive(false);
					}
					//sprawdzamy w prawo
					if (isInRange(xDish + i, yDish) &&
						dish[xDish + i][yDish]->getBacteriumSign() == 'B') {
						dish[xDish][yDish]->setIsAlive(false);
					}
					//sprawedzamy dol
					if (isInRange(xDish, yDish + i) &&
						dish[xDish][yDish + i]->getBacteriumSign() == 'B') {
						dish[xDish][yDish]->setIsAlive(false);
					}
					//sprawedzamy gora
					if (isInRange(xDish, yDish - i) &&
						dish[xDish][yDish - i]->getBacteriumSign() == 'B') {
						dish[xDish][yDish]->setIsAlive(false);
					}
				}
				//przekatna lewa-dol
				if (isInRange(xDish - 1, yDish + 1) &&
					dish[xDish - 1][yDish + 1]->getBacteriumSign() == 'B') {
					dish[xDish][yDish]->setIsAlive(false);
				}
				//przekatna prawa-dol
				if (isInRange(xDish + 1, yDish + 1) &&
					dish[xDish + 1][yDish + 1]->getBacteriumSign() == 'B') {
					dish[xDish][yDish]->setIsAlive(false);
				}
				//przekatna prawa-gora
				if (isInRange(xDish + 1, yDish - 1) &&
					dish[xDish + 1][yDish - 1]->getBacteriumSign() == 'B') {
					dish[xDish][yDish]->setIsAlive(false);
				}
				//przekatna lewa-gora
				if (isInRange(xDish - 1, yDish - 1) &&
					dish[xDish - 1][yDish - 1]->getBacteriumSign() == 'B') {
					dish[xDish][yDish]->setIsAlive(false);
				}
			}

			//BACILLUS
			if (dish[xDish][yDish]->getBacteriumSign() == 'B') {
				for (int i{ 1 }; i <= 3; i++) {
					if (isInRange(xDish - i, yDish) &&
						dish[xDish - i][yDish]->getBacteriumSign() == 'C') {
						dish[xDish][yDish]->setIsAlive(true);
					}
					else {
						dish[xDish][yDish]->setIsAlive(false);
					}
					//sprawdzamy w prawo
					if (isInRange(xDish + i, yDish) &&
						dish[xDish + i][yDish]->getBacteriumSign() == 'C') {
						dish[xDish][yDish]->setIsAlive(true);
					}
					else {
						dish[xDish][yDish]->setIsAlive(false);
					}
					//sprawedzamy dol
					if (isInRange(xDish, yDish + i) &&
						dish[xDish][yDish + i]->getBacteriumSign() == 'C') {
						dish[xDish][yDish]->setIsAlive(true);
					}
					else {
						dish[xDish][yDish]->setIsAlive(false);
					}
					//sprawedzamy gora
					if (isInRange(xDish, yDish - i) &&
						dish[xDish][yDish - i]->getBacteriumSign() == 'C') {
						dish[xDish][yDish]->setIsAlive(true);
					}
					else {
						dish[xDish][yDish]->setIsAlive(false);
					}
				}

				for (int i{ 1 }; i <= 2; i++) {

					//przekatna lewa-dol
					if (isInRange(xDish - i, yDish + i) &&
						dish[xDish - i][yDish + i]->getBacteriumSign() == 'C') {
						dish[xDish][yDish]->setIsAlive(true);
					}
					else {
						dish[xDish][yDish]->setIsAlive(false);
					}
					//przekatna prawa-dol
					if (isInRange(xDish + i, yDish + i) &&
						dish[xDish + i][yDish + i]->getBacteriumSign() == 'C') {
						dish[xDish][yDish]->setIsAlive(true);
					}
					else {
						dish[xDish][yDish]->setIsAlive(false);
					}
					//przekatna prawa-gora
					if (isInRange(xDish + i, yDish - i) &&
						dish[xDish + i][yDish - i]->getBacteriumSign() == 'C') {
						dish[xDish][yDish]->setIsAlive(true);
					}
					else {
						dish[xDish][yDish]->setIsAlive(false);
					}
					//przekatna lewa-gora
					if (isInRange(xDish - i, yDish - i) &&
						dish[xDish - i][yDish - i]->getBacteriumSign() == 'C') {
						dish[xDish][yDish]->setIsAlive(true);
					}
					else {
						dish[xDish][yDish]->setIsAlive(false);
					}
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

void PetriDish::clearDish()
{
	for (auto& k : dish) {
		for (auto& e : k) {
			if (e->getIsAlive() == false)
				e = std::make_shared<Bacterium>();
		}
	}
}

void PetriDish::counterBacterial()
{
	for (auto& k : dish) {
		for (auto& e : k) {
			if (e->getBacteriumSign() == 'C')
				coccus++;
			else if (e->getBacteriumSign() == 'B')
				bacillus++;
			else if (e->getBacteriumSign() == 'S')
				spirillum++;
			else if (e->getBacteriumSign() == '.')
				bacterium++;

		}
	}
}

void PetriDish::printNumberOfBactirum() {
	std::cout << "Bacillus: " << bacillus << std::endl;
	std::cout << "Coccus: " << coccus << std::endl;
	std::cout << "Spirillum: " << spirillum << std::endl;
	std::cout << "Empty spaces: " << bacterium << std::endl;
}

void PetriDish::bacteriaPovielations() {
	for (size_t xDish{ 0 }; xDish < dish.size(); xDish++) {
		for (size_t yDish{ 0 }; yDish < dish.size(); yDish++) {

			if (dish[xDish][yDish]->getBacteriumSign() != '.' && dish[xDish][yDish]->getIsAlive() == true) {
				std::vector<std::pair<int, int>> freeCoordinates;
				if (isInRange(xDish - 1, yDish) &&
					dish[xDish - 1][yDish]->getBacteriumSign() == '.')
					freeCoordinates.push_back(std::make_pair(xDish - 1, yDish));
				if (isInRange(xDish + 1, yDish) &&
					dish[xDish + 1][yDish]->getBacteriumSign() == '.')
					freeCoordinates.push_back(std::make_pair(xDish + 1, yDish));
				if (isInRange(xDish, yDish + 1) &&
					dish[xDish][yDish + 1]->getBacteriumSign() == '.')
					freeCoordinates.push_back(std::make_pair(xDish, yDish + 1));
				if (isInRange(xDish, yDish - 1) &&
					dish[xDish][yDish - 1]->getBacteriumSign() == '.')
					freeCoordinates.push_back(std::make_pair(xDish, yDish - 1));

				if (freeCoordinates.size() != 0) {
					std::pair<int, int> choosenCoordinates = freeCoordinates[randonPositionNumber(freeCoordinates.size())];

					if (dish[xDish][yDish]->getBacteriumSign() == 'C') {
						dish[choosenCoordinates.first][choosenCoordinates.second] = std::make_shared<Coccus>();
						dish[choosenCoordinates.first][choosenCoordinates.second]->setIsAlive(false);
					}
					else if (dish[xDish][yDish]->getBacteriumSign() == 'B') {
						dish[choosenCoordinates.first][choosenCoordinates.second] = std::make_shared<Bacillus>();
						dish[choosenCoordinates.first][choosenCoordinates.second]->setIsAlive(false);
					}
					else if (dish[xDish][yDish]->getBacteriumSign() == 'S') {
						dish[choosenCoordinates.first][choosenCoordinates.second] = std::make_shared<Spirillum>();
						dish[choosenCoordinates.first][choosenCoordinates.second]->setIsAlive(false);
					}
				}
			}
		}
	}

}

int PetriDish::randonPositionNumber(size_t sizeOfVectorPairs)
{
	srand(time(0));
	return rand() % sizeOfVectorPairs;
}

void PetriDish::frankenstein() {
	for (size_t xDish{ 0 }; xDish < dish.size(); xDish++) {
		for (size_t yDish{ 0 }; yDish < dish.size(); yDish++) {

			if (dish[xDish][yDish]->getIsAlive() == false) {
				dish[xDish][yDish]->setIsAlive(true);
			}
		}
	}
}