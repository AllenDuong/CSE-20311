// statemain.cpp
//
//	use your State class; it will read the data from the csv file (prompt the user for the file name),
//	and will store the data into a data structure of your choice. The program will then prompt the user with 
//	a menu containing a few choices on getting some information from the data. It is up to you what features 
//	your program will have. Think of this program as one to inform a user on basic information on US states.
//

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "state.h"

using namespace std;

// Prototypes
void showInfo(vector<State> &);
void showOverPop(vector<State> &);
void showOverCongress(vector<State> &);
void stateMod(vector<State> &);

int main(){
	system("clear"); //Clear Linux screen

	// Declare Variables
	string filename(" ");
	string line(" ");
	vector<State> states;
	ifstream ifs;
	string abbr, statename, capital, popS, yearS, congrepS;
	int pop, year, congrep;
	State currentState;

	// Open and Read Initial File From User Input
	
	cout << "Enter a desired input file in the form: \"filename.csv\" WITHOUT quotes: " << endl;
	cin >> filename;
	ifs.open(filename);

	if (!ifs) {
		cout << "Bad File Name: " << filename << endl;
		return 1; // End the Program
	}

	while (ifs.peek() != EOF) { // While file has not ended
		getline(ifs, abbr, ',');
		getline(ifs, statename, ',');
		getline(ifs, capital, ',');
		getline(ifs, popS, ',');
		getline(ifs, yearS, ',');
		getline(ifs, congrepS, '\n');

		pop = stoi(popS);
		year = stoi(yearS);
		congrep = stoi(congrepS);
		
		currentState = State(abbr, statename, capital, pop, year, congrep);
		states.push_back(currentState);
	}

	// Display Menu 
	int choice = 0;

	while ((choice < 1) || (choice > 5)){ // Repeats Prompt until Quit

		cout << endl;
		cout << "--------------STATE INFORMATION ARCHIVE--------------" << endl;
		cout << "Enter the Corresponding Number for an Option : " << endl;
		cout << "	1 - Display a State's Information" << endl;
		cout << "	2 - See All The States With Over A Specific Population" << endl;
		cout << "	3 - See All The States With Over A Specific Number of Congress Reps" << endl;
		cout << "	4 - Modify a Trait of a State" << endl;
		cout << "	5 - Quit" << endl;

		cout << "Your Choice: ";
		cin >> choice;
		cin.ignore(); // Flush input stream
		cout << endl;

		// Call Function Corresponding to Choice and Set Choice back to 0
		if (choice == 1){
			showInfo(states);
			choice = 0;
		}
		else if (choice == 2){
			showOverPop(states);
			choice = 0;
		}
		else if (choice == 3){
			showOverCongress(states);
			choice = 0;
		}
		else if (choice == 4){
			stateMod(states);
			choice = 0;
		}
		else if (choice == 5){ // Exit Program
			cout << "Goodbye!..." << endl;
			system("clear"); //Clear Linux screen
			break;
		}
	}
	return 0;
}


// Display A State's Information
void showInfo(vector<State> &states){
	system("clear"); //Clear Linux screen

	string stateName = "";
	bool valid = false;

	cout << "Enter a Desired State Name (With a Capital first Letter): ";
	cin >> stateName;
	cin.ignore(); // Flush input stream	

	for (auto itr = states.begin(); itr != states.end(); itr++){

		State temp = *itr;

		if (stateName == temp.getStatename()){
			temp.dispInfo();
			valid = true;
			break;
		}
	}

	if (valid == false){
		cout << "No State with That Name Exists!" << endl;
	}
}


// See All The States With Over A Specific Population (Range:)
void showOverPop(vector<State> &states){
	system("clear"); // Clear Linux screen

	int minPop = 0;
	bool valid = false;

	cout << "Enter a Desired Minimum Population: ";
	cin >> minPop;
	cin.ignore(); // Flush input stream	

	cout << "***** The States with Over " << minPop << " People are *****" << endl;

	for (auto itr = states.begin(); itr != states.end(); itr++){

		State temp = *itr;

		if (minPop <= temp.getPopul()){
			cout << "	" << temp.getStatename() << endl;
			valid = true;
		}
	}

	if (valid == false){
		cout << "No State Exists with That Many People!" << endl;
	}
}

// See All The States With Over A Specific Number of Congress Reps
void showOverCongress(vector<State> &states){
	system("clear"); // Clear Linux screen

	int minReps = 0;
	bool valid = false;

	cout << "Enter a Desired Minimum Population: ";
	cin >> minReps;
	cin.ignore(); // Flush input stream	

	cout << "***** The States with Over " << minReps << " Representatives are *****" << endl;

	for (auto itr = states.begin(); itr != states.end(); itr++){

		State temp = *itr;

		if (minReps <= temp.getCongressreps()){
			cout << "	" << temp.getStatename() << endl;
			valid = true;

		}
	}

	if (valid == false){
		cout << "No State Exists with That Many Representatives!" << endl;
	}
}

// Modify a Trait of a State
void stateMod(vector<State> &states){
	system("clear"); //Clear Linux screen

	string stateName = "";
	int choice = 0;
	bool valid = false;
	int index = -1;
	State temp;

	cout << "Enter a Desired State Name (With a Capital first Letter): ";
	cin >> stateName;
	cin.ignore(); // Flush input stream	

	for (auto itr = states.begin(); itr != states.end(); itr++){

		temp = *itr;
		index++;

		if (stateName == temp.getStatename()){
			valid = true;
			break;
		}

	}

	if (valid == false){
		cout << "No State with That Name Exists!" << endl;
	}
	else{

		cout << "Which Value Would You Like to Modify?" << endl;
		cout << "Enter the Corresponding Number for an Option : " << endl;
		cout << "	1 - State Name" << endl;
		cout << "	2 - Abbreviation" << endl;
		cout << "	3 - Capital" << endl;
		cout << "	4 - Population" << endl;
		cout << "	5 - Year Established" << endl;
		cout << "	6 - Nomber of Congress Representatives" << endl;

		cout << "Your Choice: ";
		cin >> choice;
		cin.ignore(); // Flush input stream
		cout << endl;

		string tempString;


		switch (choice){
			case 1:

				cout << "Enter a New State Name for " << stateName << " : ";
				getline(cin, tempString);
				temp.setStatename(tempString);
				states[index] = temp;
				break;

			case 2:

				cout << "Enter a New State Abbreviation for " << stateName << " : ";
				getline(cin, tempString);
				temp.setAbbrev(tempString);
				states[index] = temp;
				break;

			case 3:

				cout << "Enter a New State Capital for " << stateName << " : ";
				getline(cin, tempString);
				temp.setCapital(tempString);
				states[index] = temp;
				break;

			case 4:
				
				cout << "Enter a New State Population for " << stateName << " : ";
				getline(cin, tempString);
				temp.setPopul(stoi(tempString));
				states[index] = temp;
				break;

			case 5:
				
				cout << "Enter a New Year Established for " << stateName << " : ";
				getline(cin, tempString);
				temp.setYear(stoi(tempString));
				states[index] = temp;
				break;

			case 6:
				
				cout << "Enter a New Congress Representative for " << stateName << " : ";
				getline(cin, tempString);
				temp.setCongressreps(stoi(tempString));
				states[index] = temp;
				break;

			default:
				cout << "Invalid Choice" << endl;
				break;



		}

	}


}