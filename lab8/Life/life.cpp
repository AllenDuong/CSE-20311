// life.cpp
//
// Main Driver for the Lifeboard class
//
// Write a program that simulates the playing or animation of the game of Life on a 40-by-40 board, displayed as Xs (live cells) and blank spaces (dead cells).
// two possible modes: interactive and batch; the mode chosen will be determined by how the program is run
//		1. interactive mode: this mode will be triggered when the program is executed with no command line arguments
//		2. batch mode: this mode will be triggered if a data file is present after the executable (the data file will consist of a sequence of commands followed by a "p")
// 
//	If the user enters:
//		a: ask for coordinates where to add a new live cell(no action needed if cell is already alive).
//		r : ask for coordinates where a cell should be removed(no action needed if cell is already dead).
//		n : advance the simulation to the next iteration by applying the rules of the game.
//		q : quit the program.
//		p : play the game continuously(forever, without asking for more input; you can press control - C to stop the program).
//
//

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <unistd.h>
#include <vector>
#include <fstream>
#include <string>
#include "lifeboard.h"

using namespace std;

// Prototypes

void batchMode(vector<string> input);
void interactiveMode();

int main(int argc, char *argv[]){
	
	system("clear"); //Clear Linux screen

	// Check for Data File from Command Line

	if (argc == 1) {  // User Just Types the Executable, Nothing Else
		interactiveMode();
	}

	else {  // User Typed/Imported Commands after the Executable; 

		string temp;
		vector<string> commands;
		string filename = argv[1];
		ifstream ifs;
		ifs.open(filename);

		if (!ifs) {
			cout << "Bad File Name: " << filename << endl;
			return 1; // End the Program
		}

		while (ifs.peek() != EOF) { // While file has not ended

			ifs >> temp;
			commands.push_back(temp);
		}

		batchMode(commands);
	}

	return 0;
}

// Batch Mode Function

void batchMode(vector<string> input){

	// Create Variables/Objects
	Lifeboard gameBoard;
	int a = 0, b = 0, index = 0;

	// Set Up Board

	string choice = " ";

	while (choice != "q"){ // Repeats Prompt until Quit

		choice = input[index];
		
		// Do Things Corresponding to Choice and Set Choice back to Blank Space
		if (choice == "a"){
			index++;

			a = stoi(input[index]);
			index++;
			b = stoi(input[index]);
			index++;

			gameBoard.reviveCell(a, b);
			choice = ' ';
		}

		else if (choice == "r"){
			index++;

			a = stoi(input[index]);
			index++;
			b = stoi(input[index]);
			index++;

			gameBoard.killCell(a, b);
			choice = ' ';
		}

		else if (choice == "n"){
			gameBoard.update();
			choice = ' ';
		}

		else if (choice == "p"){

			while (1 == 1){
				gameBoard.update();
				gameBoard.display();
				usleep(200000);
				system("clear"); //Clear Linux screen

			}
		}

		else if (choice == "q"){ // Exit Program

			system("clear"); //Clear Linux screen
			cout << "Goodbye!..." << endl;
			break;
		}
	}
}

// Interactive Mode Function

void interactiveMode(){

	// Create Variables/Objects 
	Lifeboard gameBoard;
	int a = 0, b = 0;

	// Display Menu 
	char choice = ' ';

	while (choice != 'q'){ // Repeats Prompt until Quit

		gameBoard.display();

		cout << endl;
		cout << "a - Enter Coordinates to Add a New Live Cell" << endl;
		cout << "r - Enter Coordinates to Remove a Cell" << endl;
		cout << "n - Advance the Simulation to the Next Iteration" << endl;
		cout << "q - Quit the Program." << endl;
		cout << "p - Play the Game Continuously Forever (Press CTRL-C to End the Program)" << endl;

		cout << "Your Choice: ";
		cin >> choice;
		cin.ignore(); // Flush input stream
		cout << endl;

		// Do Things Corresponding to Choice and Set Choice back to Blank Space
		if (choice == 'a'){

			cout << "Enter X Coordinates to Add a Live Cell: ";
			cin >> a;
			cout << "Enter Y Coordinates to Add a Live Cell: ";
			cin >> b;

			gameBoard.reviveCell(a, b);
			choice = ' ';
			system("clear"); //Clear Linux screen
		}

		else if (choice == 'r'){
			
			cout << "Enter X Coordinates to Remove a Cell: ";
			cin >> a;
			cout << "Enter Y Coordinates to Remove a Cell: ";
			cin >> b;

			gameBoard.killCell(a, b);
			choice = ' ';
			system("clear"); //Clear Linux screen
		}
		else if (choice == 'n'){
			gameBoard.update();
			choice = ' ';
		}
		else if (choice == 'p'){
			
			while (1 == 1){
				gameBoard.update();
				gameBoard.display();
				usleep(200000);
				system("clear"); //Clear Linux screen

			}
		}
		else if (choice == 'q'){ // Exit Program

			system("clear"); //Clear Linux screen
			cout << "Goodbye!..." << endl;
			break;
		}
	}

}