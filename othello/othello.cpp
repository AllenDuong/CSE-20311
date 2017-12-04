// othello.cpp
// Main Driver for OBoard.h and OBoard class

#include <iostream>
#include <iomanip>
#include "OBoard.h"

using namespace std;

int main(){

	// Create Board

	OBoard game;

	// Loop while game is not complete
	bool go = true;
	while (go){
	
		// X's Turn
		int xMoveX = 0;
		int xMoveY = 0;

		system("clear");
		game.display();
		cout << "Player X Moves (X-Coord *space* Y-Coord):";
		cin >> xMoveX >> xMoveY;
		system("clear");

		game.move(xMoveX, xMoveY, 'X');
		game.update(xMoveX, xMoveY, 'X');
		game.update(xMoveX, xMoveY, 'X');
		game.display();

		// if (game.getStatus()){
		//	break;
		//}

		// O's Turn
		int oMoveX = 0;
		int oMoveY = 0;

		system("clear");
		game.display();
		cout << "Player O Moves (X-Coord *space* Y-Coord):";
		cin >> oMoveX >> oMoveY;
		system("clear");

		game.move(oMoveX, oMoveY, 'O');
		game.update(oMoveX, oMoveY, 'O');
		game.update(oMoveX, oMoveY, 'O');
		game.display();

		go = !(game.getStatus());

	}

	// Declare Winner

	char winner = game.declareWinner();

	if (winner = 'X'){
		cout << "The Winner Was X!!" << endl;
	}
	else if (winner = 'O'){
		cout << "The Winner Was O!!" << endl;
	}
	else if (winner = 'T'){
		cout << "The Result was a Tie!!" << endl;
	}

	return 0;
}