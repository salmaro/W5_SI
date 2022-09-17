#include "GameHandler.h"
#include <utility>

std::pair<int, int>GameHandler::setBoardSize()
{
	std::pair<int, int> board;
	std::cout << "Enter number of rows(1 - 26): ";
	std::cin >> board.first;
	std::cout << "Enter number of columns(1 - 26): ";
	std::cin >> board.second;

	return board;
}

void GameHandler::runGame()
{
	board.createBoard(setBoardSize());
	player1.setPlayerName();
	player1.setPlayerSign();
	player2.setPlayerName();
	if (player1.sign == 'X') {
		player2.sign = 'O';
	}
	else if (player1.sign == 'O')
		player2.sign = 'X';


	while (true) {
		makePlayerMove(player1);
		makePlayerMove(player2);
	}
}

bool GameHandler::checkIsValidMove(std::pair<int, int> playerMove)
{
	std::pair<int, int> boardSize = board.getBoardSize();
	if ((playerMove.first < 0) || (playerMove.first >= boardSize.first)) {
		std::cout << "Input a proper letter!" << std::endl;
		return false;
	}
	if ((playerMove.second > boardSize.second - 1) || (playerMove.second < 0)) {
		std::cout << "Input a proper number!" << std::endl;
		return false;
	}
	return true;
}

void GameHandler::upadateBoard(std::pair<int, int>playerMove, Player player)
{
	board.markPlayerMove(playerMove, player.sign);
}

bool GameHandler::isOccupied(std::pair<int, int>playerMove)
{
	bool isFree = ((*board.getBoard())[playerMove.first][playerMove.second] == '.');

	return !isFree;
}

void GameHandler::makePlayerMove(Player player)
{
	std::cout << "Turn:    " << player.name << " " << player.sign << std::endl;
	board.printBoard();
	std::pair<int, int> playerMove;
	while (!checkIsValidMove(playerMove = player.inputCoordinate()));
	while (isOccupied(playerMove)) { std::cout << "Field is occupied" << std::endl; break; }
	upadateBoard(playerMove, player);
	if (isHorizontal(playerMove) || isVertical(playerMove)) { std::cout << "wygrales: " << player.name << std::endl; system("pause"); }
	//system("cls");

}

bool GameHandler::isInBoardRange(int x, int y)
{
	if (x >= 0 && x < board.getBoardSize().first && y >= 0 && y < board.getBoardSize().second) {
		return true;
	}
	return false;
}

bool GameHandler::isVertical(std::pair<int, int> playerMove)
{
	auto x = playerMove.first;
	auto y = playerMove.second;
	int xSize = board.getBoardSize().first;
	int ySize = board.getBoardSize().second;
	//vertical
	for (int yPos{ 0 }; yPos < ySize - 4;yPos++) {

		//std::cout << "(*board.getBoard())[xPos][y]: " << (*board.getBoard())[x][yPos] << std::endl;
		//std::cout << "(*board.getBoard())[xPos + 1]:" << (*board.getBoard())[x][yPos +1] << std::endl;
		//std::cout << "(*board.getBoard())[xPos + 2]:" << (*board.getBoard())[x][yPos + 2] << std::endl;
		//std::cout << "(*board.getBoard())[xPos + 3]:" << (*board.getBoard())[x][yPos +3] << std::endl;
		//std::cout << "(*board.getBoard())[xPos + 4]:" << (*board.getBoard())[x][yPos + 4] << std::endl;
		if ((*board.getBoard())[x][y] == (*board.getBoard())[x][yPos] &&
			(*board.getBoard())[x][yPos] == (*board.getBoard())[x][yPos + 1] &&
			(*board.getBoard())[x][yPos + 1] == (*board.getBoard())[x][yPos + 2] &&
			(*board.getBoard())[x][yPos + 2] == (*board.getBoard())[x][yPos + 3] &&
			(*board.getBoard())[x][yPos + 3] == (*board.getBoard())[x][yPos + 4]) {
			return true;
		}
	}
	return false;
}


bool GameHandler::isHorizontal(std::pair<int, int> playerMove)
{
	auto x = playerMove.first;
	auto y = playerMove.second;
	int xSize = board.getBoardSize().first;
	int ySize = board.getBoardSize().second;
	//horizontal
	for (int xPos{ 0 }; xPos < xSize - 4;xPos++) {

		//std::cout << "(*board.getBoard())[xPos][y]: " << (*board.getBoard())[xPos][y]  << std::endl;
		//std::cout << "(*board.getBoard())[xPos + 1]:" << (*board.getBoard())[xPos + 1][y] << std::endl;
		//std::cout << "(*board.getBoard())[xPos + 2]:" << (*board.getBoard())[xPos + 2][y] << std::endl;
		//std::cout << "(*board.getBoard())[xPos + 3]:" << (*board.getBoard())[xPos + 3][y] << std::endl;
		//std::cout << "(*board.getBoard())[xPos + 4]:" << (*board.getBoard())[xPos + 4][y] << std::endl;
		if ((*board.getBoard())[x][y] == (*board.getBoard())[xPos][y] &&
			(*board.getBoard())[xPos][y] == (*board.getBoard())[xPos + 1][y] &&
			(*board.getBoard())[xPos + 1][y] == (*board.getBoard())[xPos + 2][y] &&
			(*board.getBoard())[xPos + 2][y] == (*board.getBoard())[xPos + 3][y] &&
			(*board.getBoard())[xPos + 3][y] == (*board.getBoard())[xPos + 4][y]) {
			return true;
		}
	}
	return false;
}

bool GameHandler::isCross(std::pair<int, int> playerMove)
{
	return false;
}


bool GameHandler::isWin() {
	return 1;
}
