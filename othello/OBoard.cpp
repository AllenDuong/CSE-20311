// OBoard.h.cpp; Class Implementation
//  Name: Allen Duong
//

// Header Files
#include <iostream>
#include <iomanip>
#include "OBoard.h"

using namespace std;

// Function to check if a position is sandwiched
bool checkSurrounding(int xCoord, int yCoord, char player, char board[boardSize][boardSize]){ //True to swap

	if ((yCoord == 0) && (xCoord == 0)){ // If  Upper left corner

		return false;

	}

	else if ((yCoord == 0) && (xCoord == (boardSize - 1))){  // If  Upper right corner

		return false;

	}

	else if ((yCoord == (boardSize - 1)) && (xCoord == 0)){  // If  lower left corner

		return false;

	}

	else if ((yCoord == (boardSize - 1)) && (xCoord == (boardSize - 1))){ // If  lower right corner

		return false;

	}

	else if ((yCoord == 0) && ((xCoord != 0) || (xCoord != (boardSize - 1)))){ // If upper edge


		if ((board[yCoord][xCoord + 1] == player) && (board[yCoord][xCoord - 1] == player)){
			return true;
		}
	}

	else if ((yCoord == (boardSize - 1)) && ((xCoord != 0) || (xCoord != (boardSize - 1)))){ // If lower edge


		if ((board[yCoord][xCoord + 1] == player) && (board[yCoord][xCoord - 1] == player)){
			return true;
		}

	}

	else if ((xCoord == (boardSize - 1)) && ((yCoord != 0) || (yCoord != (boardSize - 1)))){  // If right edge


		if ((board[yCoord + 1][xCoord] == player) && (board[yCoord - 1][xCoord] == player)){
			return true;
		}

	}

	else if ((xCoord == 0) && ((yCoord != 0) || (yCoord != (boardSize - 1)))){  // If left edge


		if ((board[yCoord + 1][xCoord] == player) && (board[yCoord - 1][xCoord] == player)){
			return true;
		}

	}

	else{ // If not touching any edge



		if ((board[yCoord + 1][xCoord] == player) && (board[yCoord - 1][xCoord] == player)){
			return true;
		}
		else if ((board[yCoord][xCoord + 1] == player) && (board[yCoord][xCoord - 1] == player)){
			return true;
		}
		else if ((board[yCoord + 1][xCoord + 1] == player) && (board[yCoord - 1][xCoord - 1] == player)){
			return true;
		}
		else if ((board[yCoord + 1][xCoord - 1] == player) && (board[yCoord - 1][xCoord + 1] == player)){
			return true;
		}


	}

	return false;

}

// Methods

OBoard::OBoard(){

	gameStatus = false;

	// Create Blank Board

	for (int i = 0; i < boardSize; i++){
		for (int j = 0; j < boardSize; j++){
			board[i][j] = '.';
		}
	}

	// Place Starting Pieces

	int posStart = (boardSize / 2) - 1; // Minus 1 because indexing starts at 0
	board[posStart][posStart] = 'X';
	board[posStart + 1][posStart] = 'O';
	board[posStart][posStart + 1] = 'O';
	board[posStart + 1][posStart + 1] = 'X';

}


OBoard::~OBoard(){}


void OBoard::move(int xCoord, int yCoord, char player){ // The third value passed is the Player who made the move


	// Place Piece

	board[yCoord][xCoord] = player; // Player is either 'X' or 'O'

}

void OBoard::update(int xCoord, int yCoord, char player){

	// Update Board
	int openSpace = 0;

	for (int yCoord = 0; yCoord < boardSize; yCoord++){

		for (int xCoord = 0; xCoord < boardSize; xCoord++){

			if (board[yCoord][xCoord] != '.'){

				// If a position can remain it will remain. Otherwise it will be flipped

				if (checkSurrounding(xCoord, yCoord, player, board)){ // If true then swap piece

					board[yCoord][xCoord] = player;

				}
			}
			else{
				openSpace++;
			}
		}
	}

	if (openSpace == 0){

		gameStatus = true;
	}
}

void OBoard::display(){

	for (int i = 0; i < boardSize; i++){

		cout << setw(3) << i; // Y Axis Labels

		for (int j = 0; j < boardSize; j++)
		{

			cout << setw(3) << (board[i][j]);

			if (j == (boardSize - 1))
			{
				cout << endl;
			}
		}
	}

	// X Axis Labels
	cout << "   ";

	for (int k = 0; k < boardSize; k++){
		cout << setw(3) << k;
	}

	cout << endl;

}

bool OBoard::getStatus(){
	return gameStatus;
}

char OBoard::declareWinner(){

	int oScore = 0;
	int xScore = 0;

	for (int yCoord = 0; yCoord < boardSize; yCoord++){

		for (int xCoord = 0; xCoord < boardSize; xCoord++){

			if (board[yCoord][xCoord] == 'X'){

				xScore++;

			}
			else{
				oScore++;
			}
		}
	}

	if (xScore > oScore){
		return 'X';
	}
	else if (oScore > xScore){
		return 'O';
	}
	else{
		return 'T';
	}
}

