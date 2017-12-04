// cwBoard.cpp; Class Implementation
//  Name: Allen Duong
//

// Header Files
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include "cwBoard.h"

using namespace std;

// Functions

void placeVert(word a, int xCoord, int yCoord, char board[gridSize][gridSize], int index){ // Only places words DOWN or ACROSS;

	int letter = 0;

	for (int i = yCoord - index; i != yCoord - index + (a.phrase).size(); i++, letter++){

		board[i][xCoord] = (a.phrase).at(letter);
	}
}


void placeHoriz(word a, int xCoord, int yCoord, char board[gridSize][gridSize], int index){ // Only places words DOWN or ACROSS;

	int letter = 0;

	for (int i = xCoord - index; i != xCoord - index + (a.phrase).size(); i++, letter++){

		board[yCoord][i] = (a.phrase).at(letter);
	}
}


bool checkVert(word a, int xCoord, int yCoord, int index, char board[gridSize][gridSize]){

	string curPhrase = a.phrase;

	if ((board[yCoord + 1][xCoord] != '.') && (board[yCoord - 1][xCoord] != '.')){ // Test Point for space above and below
		return false;
	}
	if ((yCoord < index) || (yCoord - index + curPhrase.size() > 15)){ // Test if Word Goes Over Edge of Board
		return false;
	}

	if (yCoord - index == 0){ // If word will start at upper edge of board
		for (int i = 0; i != yCoord + curPhrase.size() - index + 1; i++){ // Runs til one unit after the word ends
			if (i == yCoord){ // Exclude the Intersection Point
				i++;
			}
			if (board[i][xCoord] != '.'){ // Returns false if where word would be placed is not blank
				return false;
			}
			if ((board[i][xCoord + 1] != '.') || (board[i][xCoord - 1] != '.')){ // Exclude the Intersection Point
				return false;
			}
		}
	}

	else if (yCoord + curPhrase.size() - index == 0){ // If word will end at lower edge of board
		for (int i = yCoord - index - 1; i != yCoord + curPhrase.size() - index; i++){ // Runs from one unit before the word starts
			if (i == yCoord){ // Exclude the Intersection Point
				i++;
			}
			if (board[i][xCoord] != '.'){ // Returns false if where word would be placed is not blank
				return false;
			}
			if ((board[i][xCoord + 1] != '.') || (board[i][xCoord - 1] != '.')){
				return false;
			}
		}
	}

	else {//(yCoord + curPhrase.size() - index == 0){ // If word will not touch any border
		for (int i = yCoord - index - 1; i != yCoord + curPhrase.size() - index + 1; i++){ // Runs from one unit before the word starts to one unit after it ends
			if (i == yCoord){ // Exclude the Intersection Point
				i++;
			}
			if (board[i][xCoord] != '.'){ // Returns false if where word would be placed is not blank
				return false;
			}
			if ((board[i][xCoord + 1] != '.') || (board[i][xCoord - 1] != '.')){
				return false;
			}
		}
	}

	return true; // True if all the spaces required are available

}

bool checkHoriz(word a, int xCoord, int yCoord, int index, char board[gridSize][gridSize]){

	string curPhrase = a.phrase;

	if ((board[yCoord][xCoord + 1] != '.') && (board[yCoord][xCoord - 1] != '.')){ // Test Point for space on left and right
		return false;
	}
	if ((xCoord < index) || (xCoord - index + curPhrase.size() > 15)){ // Test if Word Goes Over Edge of Board
		return false;
	}

	if (xCoord - index == 0){ // If word will start at upper edge of board
		for (int i = 0; i != xCoord + curPhrase.size() - index + 1; i++){ // Runs til one unit after the word ends
			if (i == xCoord){ // Exclude the Intersection Point
				i++;
			}
			if (board[yCoord][i] != '.'){ // Returns false if where word would be placed is not blank
				return false;
			}
			if ((board[yCoord + 1][i] != '.') || (board[yCoord - 1][i] != '.')){ // Exclude the Intersection Point
				return false;
			}
		}
	}

	else if (xCoord + curPhrase.size() - index == 0){ // If word will end at lower edge of board
		for (int i = xCoord - index - 1; i != xCoord + curPhrase.size() - index; i++){ // Runs from one unit before the word starts
			if (i == xCoord){ // Exclude the Intersection Point
				i++;
			}
			if (board[yCoord][i] != '.'){ // Returns false if where word would be placed is not blank
				return false;
			}
			if ((board[yCoord + 1][i] != '.') || (board[yCoord - 1][i] != '.')){ // Exclude the Intersection Point
				return false;
			}
		}
	}

	else{ // If word will not touch any border
		for (int i = xCoord - index - 1; i != xCoord + curPhrase.size() - index + 1; i++){ // Runs from one unit before the word starts to one unit after it ends
			if (i == xCoord){ // Exclude the Intersection Point
				i++;
			}
			if (board[yCoord][i] != '.'){ // Returns false if where word would be placed is not blank
				return false;
			}
			if ((board[yCoord + 1][i] != '.') || (board[yCoord - 1][i] != '.')){ // Exclude the Intersection Point
				return false;
			}
		}
	}

	return true; // True if all the spaces required are available

}


void placeEm(word &a, char board[gridSize][gridSize]){

	for (int yCoord = 0; yCoord < gridSize; yCoord++){

		for (int xCoord = 0; xCoord < gridSize; xCoord++){

			if (board[yCoord][xCoord] != '.'){

				for (int index = 0; index != (a.phrase).size(); index++){

					if (board[yCoord][xCoord] == (a.phrase).at(index)){

						if (checkVert(a, xCoord, yCoord, index, board)){
							placeVert(a, xCoord, yCoord, board, index);

							// Update Aspects of Word
							a.direction = "Down";
							a.xCoord = xCoord;
							a.yCoord = yCoord;

							return;
						}
						else if (checkHoriz(a, xCoord, yCoord, index, board)){
							placeHoriz(a, xCoord, yCoord, board, index);

							// Update Aspects of Word
							a.direction = "Across";
							a.xCoord = xCoord;
							a.yCoord = yCoord;

							return;
						}
					}
				}
			}

		}

	}

	return;

}

// Implementations

cwBoard::cwBoard(vector<string> input){

	// Sort Input Array in Descending Order by Length

	for (int i = 0; i < input.size(); i++){
		for (int comparisonIndex = i + 1; comparisonIndex < input.size(); comparisonIndex++){

			if (input[i].size() < input[comparisonIndex].size()){

				// Swap the Elements (Uses Selection Sort)
				string biggerWord = input[comparisonIndex];
				input[comparisonIndex] = input[i];
				input[i] = biggerWord;
			}
		}
	}

	// Create a Vector of Words (structure) 

	for (int i = 0; i < input.size(); i++){
		word temp;
		temp.xCoord = 0;
		temp.yCoord = 0;
		temp.direction = "Not Placed";
		temp.phrase = input[i];

		allWords.push_back(temp);

	}

	// Create Empty Board

	for (int i = 0; i < gridSize; i++){
		for (int j = 0; j < gridSize; j++){
			board[i][j] = '.';
		}
	}

	// Place First Word

	int halfLen = floor((input[0].size()) / 2);

	for (int i = 0; i < input[0].size(); i++){ // Place Largest Word in Middle (Horizontally) 
		board[8][(8 - halfLen) + i] = input[0].at(i);
	}

	allWords[0].yCoord = 8;
	allWords[0].xCoord = (8 - halfLen);
	allWords[0].direction = "Across";

	// Fill Rest of Board

	for (int i = 1; i < allWords.size(); i++){
		placeEm(allWords[i], board);
	}
}


cwBoard::~cwBoard(){
}

void cwBoard::dispGameBoard(){

	for (int i = 0; i < gridSize; i++){

		cout << setw(3) << i; // Y Axis Labels

		for (int j = 0; j < gridSize; j++)
		{

			if (board[i][j] != '.')
			{
				cout << setw(3) << " ";
			}
			else
			{
				cout << setw(3) << "#";
			}
			if (j == (gridSize - 1))
			{
				cout << endl;
			}
		}
	}

	// X Axis Labels
	cout << "   ";

	for (int k = 0; k < gridSize; k++){
		cout << setw(3) << k;
	}

	cout << endl;

}

void cwBoard::dispAnsBoard(){

	for (int i = 0; i < gridSize; i++){

		cout << setw(3) << i; // Y Axis Labels

		for (int j = 0; j < gridSize; j++)
		{

			cout << setw(3) << (board[i][j]);

			if (j == (gridSize - 1))
			{
				cout << endl;
			}
		}
	}

	// X Axis Labels
	cout << "   ";

	for (int k = 0; k < gridSize; k++){
		cout << setw(3) << k;
	}

	cout << endl;

}

void cwBoard::dispClues(){

	cout << "Location" << setw(4) << "|" << setw(12) << "Direction" << setw(2) << "|" << setw(16) << "Anagram" << endl;

	for (int i = 0; i < allWords.size(); i++){
		word temp = allWords[i];
		string x = temp.phrase;

		random_shuffle(x.begin(), x.end());

		if (temp.direction != "Not Placed"){

			if ((temp.xCoord < 10) && (temp.yCoord < 10)){
				cout << setw(7) << temp.xCoord << ", " << temp.yCoord << setw(2) << "|" << setw(12) << temp.direction << setw(2) << "|" << setw(16) << x << endl;
			}
			else if ((temp.xCoord > 9) && (temp.yCoord < 10)){
				cout << setw(7) << temp.xCoord << ", " << temp.yCoord << setw(2) << "|" << setw(12) << temp.direction << setw(2) << "|" << setw(16) << x << endl;
			}
			else if ((temp.yCoord > 9) && (temp.xCoord < 10)){
				cout << setw(7) << temp.xCoord << ", " << temp.yCoord << "|" << setw(12) << temp.direction << setw(2) << "|" << setw(16) << x << endl;
			}
			else if ((temp.xCoord > 9) && (temp.yCoord > 9)){
				cout << setw(7) << temp.xCoord << ", " << temp.yCoord << "|" << setw(12) << temp.direction << setw(2) << "|" << setw(16) << x << endl;
			}
		}
	}

	cout << endl << endl;
	cout << "Words Not Placed on the Board:" << endl;
	for (int i = 0; i < allWords.size(); i++){
		word temp = allWords[i];

		if (temp.direction == "Not Placed"){
			cout << temp.phrase << endl;
		}
	}

}


void cwBoard::dispGameBoardF(string output){

	ofstream ofs;
	ofs.open(output, ios::app);

	for (int i = 0; i < gridSize; i++){

		ofs << setw(3) << i; // Y Axis Labels

		for (int j = 0; j < gridSize; j++)
		{

			if (board[i][j] != '.')
			{
				ofs << setw(3) << " ";
			}
			else
			{
				ofs << setw(3) << "#";
			}
			if (j == (gridSize - 1))
			{
				ofs << endl;
			}
		}
	}

	// X Axis Labels
	ofs << "   ";

	for (int k = 0; k < gridSize; k++){
		ofs << setw(3) << k;
	}

	ofs << endl;
	ofs.close();

}

void cwBoard::dispAnsBoardF(string output){

	ofstream ofs;
	ofs.open(output, ios::app);

	for (int i = 0; i < gridSize; i++){

		ofs << setw(3) << i; // Y Axis Labels

		for (int j = 0; j < gridSize; j++)
		{

			ofs << setw(3) << board[i][j];

			if (j == (gridSize - 1))
			{
				ofs << endl;
			}
		}
	}

	// X Axis Labels
	ofs << "   ";

	for (int k = 0; k < gridSize; k++){
		ofs << setw(3) << k;
	}

	ofs << endl;
	ofs.close();

}

void cwBoard::dispCluesF(string output){

	ofstream ofs;
	ofs.open(output, ios::app);

	ofs << "Location" << setw(4) << "|" << setw(12) << "Direction" << setw(2) << "|" << setw(16) << "Anagram" << endl;

	for (int i = 0; i < allWords.size(); i++){
		word temp = allWords[i];
		string x = temp.phrase;

		random_shuffle(x.begin(), x.end());

		if (temp.direction != "Not Placed"){

			if ((temp.xCoord < 10) && (temp.yCoord < 10)){
				ofs << setw(7) << temp.xCoord << ", " << temp.yCoord << setw(3) << "|" << setw(12) << temp.direction << setw(2) << "|" << setw(16) << x << endl;
			}
			else if (((temp.xCoord > 9) && (temp.yCoord < 10))){
				ofs << setw(7) << temp.xCoord << ", " << temp.yCoord << setw(3) << "|" << setw(12) << temp.direction << setw(2) << "|" << setw(16) << x << endl;
			}
			else if ((temp.yCoord > 9) && (temp.xCoord < 10)){
				ofs << setw(7) << temp.xCoord << ", " << temp.yCoord << "|" << setw(12) << temp.direction << setw(2) << "|" << setw(16) << x << endl;
			}
			else if ((temp.xCoord > 9) && (temp.yCoord > 9)){
				ofs << setw(7) << temp.xCoord << ", " << temp.yCoord << "|" << setw(12) << temp.direction << setw(2) << "|" << setw(16) << x << endl;
			}
		}
	}

	ofs << endl << endl;
	ofs << "Words Not Placed on the Board:" << endl;
	for (int i = 0; i < allWords.size(); i++){
		word temp = allWords[i];

		if (temp.direction == "Not Placed"){
			ofs << temp.phrase << endl;
		}
	}

	ofs.close();

}
