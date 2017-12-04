// crossword.cpp
// Name: Allen Duong
// Driver for cwBoard class
//		
// Goals of this Driver:
// 
//	Begin by prompting the author to enter a list of up to 20 words of up to 15 letters each.
//	Stop when the user enters a period "." instead of a word, or if 20 words have been provided.
//	Create a 15 - by - 15 board that is initially empty.
//	For each of the remaining words in descending order of length, place them on the board in a way that intersects with exactly one identical letter already on the board.All letters of a word must be separated
//		from other words by at least one blank space, except of course where it intersects with another word.
//	Continue until all words have been placed.However, if it is absolutely impossible to place the next word according to the above rules, then indicate 
//		that with an appropriate message, do not place any further words, and continue to the next step.
//	Display the solution to the puzzle, with all the words that have been placed.
//	Display the unsolved puzzle and generate the anagram clues.
//
//	Words may only contain the letters A-Z.
//	Both upper and lower cases are accepted as input, but everything should be converted to upper case when displayed in the generated puzzle.

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <string>
#include "cwBoard.h"

using namespace std;

// Prototypes

void outputMode(vector<string>, string);
void textMode(vector<string>);
void interactiveMode();
bool allAlpha(string);

int main(int argc, char *argv[]){

	system("clear"); //Clear Linux screen

	// Check for Data File from Command Line

	if (argc == 1) {  // User Just Types the Executable, Nothing Else
		interactiveMode();
	}

	else if (argc == 2) {  // User Typed a Text File for Input; 

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

			if ((commands.size() == 20)){
				break;
			}

			if ((temp.size() > 15)){
				// dont take it
			}
			else if (!allAlpha(temp)){
				// also do nothing
			}
			else{
				commands.push_back(temp);
			}
		}
		ifs.close();

		textMode(commands);
	}

	else if (argc == 3) {  // User Typed a Text File for Output; 

		string temp;
		vector<string> commands;
		string filename = argv[1];
		string output = argv[2];
		ifstream ifs;
		ifs.open(filename);

		if (!ifs) {
			cout << "Bad File Name: " << filename << endl;
			return 1; // End the Program
		}

		while (ifs.peek() != EOF) { // While file has not ended

			ifs >> temp;

			if ((commands.size() == 20)){
				break;
			}

			if ((temp.size() > 15)){
				// dont take it
			}
			else if (!allAlpha(temp)){
				// also do nothing
			}
			else{
				commands.push_back(temp);
			}
		}
		ifs.close();

		outputMode(commands, output);
	}
	else{
		cout << "Invalid number of arguments!!";
	}

	return 0;
}

void outputMode(vector<string> input, string output){

	for (auto itLw = input.begin(); itLw != input.end(); ++itLw){ // For each string in Vector, Iterate through all characters in string

		string tempString = *itLw;

		for (int i = 0; i < tempString.length(); i++){

			tempString[i] = toupper(tempString[i]);
		}

		*itLw = tempString;
	}

	cwBoard game(input);
	game.dispAnsBoardF(output);
	cout << endl << endl << endl;
	game.dispGameBoardF(output);
	cout << endl << endl << endl;
	game.dispCluesF(output);

}

void textMode(vector<string> input){

	// MAKE EVERYTHING UPPERCASE
	for (auto itLw = input.begin(); itLw != input.end(); ++itLw){ // For each string in Vector, Iterate through all characters in string

		string tempString = *itLw;

		for (int i = 0; i < tempString.length(); i++){

			tempString[i] = toupper(tempString[i]);
		}

		*itLw = tempString;
	}

	cwBoard game(input);
	game.dispAnsBoard();
	cout << endl << endl << endl;
	game.dispGameBoard();
	cout << endl << endl << endl;
	game.dispClues();


}

void interactiveMode(){

	vector<string> input;
	string temp = "";
	int index = 1;

	cout << "Enter a list of up to 20 words of up to 15 letters each." << endl;
	cout << "To end the list early, enter a enters a period ""."" instead of a word" << endl;

	while (1){
		cout << index << ": ";
		getline(cin, temp);

		if ((input.size() == 20) || (temp == ".")){
			break;
		}


		if ((temp.size() > 15)){
			cout << "		" <<  temp << " was larger then 15 characters!" << endl;
		}
		else if (!allAlpha(temp)){
			cout << "		" << temp << " contained non A-Z characters!" << endl;
		}
		else{
			input.push_back(temp);
			index++;
		}
	}

	for (auto itLw = input.begin(); itLw != input.end(); ++itLw){ // For each string in Vector, Iterate through all characters in string

		string tempString = *itLw;

		for (int i = 0; i < tempString.length(); i++){

			tempString[i] = toupper(tempString[i]);
		}

		*itLw = tempString;
	}

	cwBoard game(input);
	game.dispAnsBoard();
	cout << endl << endl << endl;
	game.dispGameBoard();
	cout << endl << endl << endl;
	game.dispClues();
}

bool allAlpha(string x){

	for (int i = 0; i < x.size(); i++){

		if (!isalpha(x.at(i))) { return false; break; }
	}
	return true;
}