// rational.cpp; Class Implementation
//  Name: Allen Duong
//

// Header Files
#include "lifeboard.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Global Variables
const int boardSize = 40; 

// Functions

void copyBoard(bool boardOne[boardSize+3][boardSize+3], bool boardTwo[boardSize+3][boardSize+3]){
	for (int i = 0; i < boardSize+3; i++)
	{
		for (int j = 0; j < boardSize+3; j++)
		{
			boardTwo[i][j] = boardOne[i][j];
		}
	}
}

// Methods
Lifeboard::Lifeboard(){
	for (int i = 0; i < boardSize+3; i++){

		for (int j = 0; j < boardSize+3; j++){
			board[i][j] = false;
		}
	}
}

Lifeboard::~Lifeboard(){
}

bool Lifeboard::getCell(int a, int b){
	return board[b][a];
}

void Lifeboard::killCell(int a, int b){
	board[b][a] = false;
}

void Lifeboard::reviveCell(int a, int b){
	board[b][a] = true;
}

void Lifeboard::update(){ // This method holds the rules for how the board works
	//	1. Any live cell with fewer than two live neighbours dies, as if caused by underpopulation.
	//	2. Any live cell with two or three live neighbours lives on to the next generation.
	//	3. Any live cell with more than three live neighbours dies, as if by overpopulation.
	//	4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
	// Analysis done on BoardTwo and Modifications done on BoardOne

	bool boardTwo[boardSize+3][boardSize+3] = { false };
	copyBoard(board, boardTwo);

	for (int i = 1; i < boardSize+1; i++) // These nested loops check neighbors
	{
		for (int j = 1; j < boardSize+1; j++)
		{
			int alive = 0; // Index variable for number of neighbors alive


			for (int k = -1; k < 2; k++)
			{
				for (int l = -1; l < 2; l++)
				{
					if (!(k == 0 && l == 0)) // This makes sure we don't consider the selected pos as a neighbor
					{
						if (boardTwo[i + k][j + l])
						{
							++alive;
						}
					}
				}
			}
			if (alive < 2) // Rule ONE (1)
			{
				board[i][j] = false;
			}
			else if (alive == 3) // Rule TWO (2)
			{
				board[i][j] = true;
			}
			else if (alive > 3) // Rule THREE (3)
			{
				board[i][j] = false;
			}
		}
	}
	
}

void Lifeboard::display(){

	for (int i = 1; i < boardSize+1; i++){	

		cout << setw(3) << i; // Y Axis Labels

		for (int j = 1; j < boardSize+1; j++)
		{

			if (board[i][j] == true)
			{
				cout << setw(3) << "X";
			}
			else
			{
				cout << setw(3) << " ";
			}
			if (j == (boardSize))
			{
				cout << endl;
			}
		}
	}

	// X Axis Labels
	cout << "   ";

	 for (int k = 1; k < boardSize + 1; k++){
		 cout << setw(3) << k;
	}

	cout << endl;
}