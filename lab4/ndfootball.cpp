// Part 3: ND football
// ndfootball.cpp
//		store the wins and losses data into arrays
//		will then provide a user with a menu of questions on the data
//	Examples: display the record for a given year; display years with a losing record; display years with a given minimum number of wins; or losses
// Name: Allen Duong

#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

// Declare and Initialize Win and Loss Array
const int wins[] =
		{ 6, 8, 6, 8, 5, 5, 6, 6, 8, 7, 4,
		  6, 7, 7, 6, 7, 8, 6, 3, 9, 9, 10,
		  8, 9, 10, 7, 9, 7, 5, 9, 10, 6, 6,
		  3, 6, 7, 6, 6, 8, 7, 7, 8, 7, 9,
		  8, 7, 8, 9, 9, 10, 4, 7, 7, 9, 9,
		  8, 2, 7, 6, 5, 2, 5, 5, 2, 9, 7,
		  9, 8, 7, 8, 10, 8, 8, 11, 10, 8, 9,
		  11, 9, 7, 9, 5, 6, 7, 7, 5, 5, 8,
		  12, 12, 9, 10, 10, 11, 6, 9, 8, 7, 9,
		  5, 9, 5, 10, 5, 6, 9, 10, 3, 7, 6,
		  8, 8, 12, 9, 8, 10, 4 };

const int losses[] =
	  { 3, 1, 2, 0, 3, 4, 1, 0, 1, 0, 1,
		0, 0, 0, 2, 1, 1, 1, 1, 0, 0, 1,
		1, 1, 0, 2, 1, 1, 4, 0, 0, 2, 2,
		5, 3, 1, 2, 2, 1, 2, 2, 0, 2, 1,
		2, 2, 0, 0, 0, 0, 4, 2, 2, 0, 1,
		2, 8, 3, 4, 5, 8, 5, 5, 7, 1, 2,
		0, 2, 2, 2, 1, 2, 3, 0, 2, 3, 3,
		1, 3, 4, 2, 6, 4, 5, 5, 6, 6, 4,
		0, 1, 3, 3, 1, 1, 5, 3, 3, 6, 3,
		7, 3, 6, 3, 7, 6, 3, 3, 9, 6, 6,
		5, 5, 1, 4, 5, 3, 8 };

const int numYears = 1899 + (sizeof(wins) / sizeof(int));

// Prototype Functions
void dispRecord();
void dispLosing();
void dispWinning();
void dispMinWins();
void dispMinLoss();
void dispAvgWL();
void dispSpecificRecord();


int main(){

	int choice = 0;

	while ((choice < 1) || (choice > 8)){ // Repeats Calculator Prompt until Quit

		cout << endl << endl << endl;
		cout << "--------------ND FOOTBALL RECORD ANALYSIS--------------" << endl;
		cout << "Works for the years 1900 to " << numYears << endl;
		cout << "Enter the Corresponding Number for an Option : " << endl;
		cout << "		1 - Display Record for a Given Year" << endl;
		cout << "		2 - Display Years with Losing Record" << endl;
		cout << "		3 - Display Years with Winning Record" << endl;
		cout << "		4 - Display Years with Minimum # of Wins" << endl;
		cout << "		5 - Display Years with Minimum # of Losses" << endl;
		cout << "		6 - Display Average Win/Loss Record Between Two Years" << endl;
		cout << "		7 - Display A Year with a Specific Win/Loss Record" << endl;
		cout << "		8 - Quit" << endl;

		cout << "Your Choice: ";
		cin >> choice;
		cout << endl;

		// Call Function Corresponding to Choice and Set Choice back to 0
		if (choice == 1){
			dispRecord();
			choice = 0;
		}
		else if (choice == 2){
			dispLosing();
			choice = 0;
		}
		else if (choice == 3){
			dispWinning();
			choice = 0;
		}
		else if (choice == 4){
			dispMinWins();
			choice = 0;
		}
		else if (choice == 5){
			dispMinLoss();
			choice = 0;
		}
		else if (choice == 6){
			dispAvgWL();
			choice = 0;
		}
		else if (choice == 7){
			dispSpecificRecord();
			choice = 0;
		}
		else if (choice == 8){ // Exit Program
			cout << "Goodbye!..." << endl;
			break;
		}
	}

	return 0;
}

// 1: Display Record for a Given Year
void dispRecord(){
	int choice = 0;
	int indexChoice = 0;

	// Makes sure input is Valid

	while ((choice < 1900) || (choice > numYears)){

		cout << "Enter The Desired Year: ";
		cin >> choice;

	}

	indexChoice = choice - 1900;

	cout << "The record for " << choice << " is " << wins[indexChoice] << "-" << losses[indexChoice] << endl;

}

// 2: Display Years with Losing Record
void dispLosing(){

	int counter = 0;

	cout << "The Years with Losing Records are:" << endl;

	for (int i = 0; i < ((sizeof(wins) / sizeof(int))); i++){

		if (losses[i] > wins[i]){ // Checks if we had more losses than wins that year
			cout << setw(6) << (i + 1900) << ", " << setw(6);
			counter++;
		}

		if (counter == 3){ // Makes rows of 3
			cout << endl;
			counter = 0;
		}
	}

}

// 3: Display Years with Winning Record
void dispWinning(){

	int counter = 0;

	cout << "The Years with Winning Records are:" << endl;

	for (int i = 0; i < ((sizeof(wins) / sizeof(int))); i++){

		if (wins[i] > losses[i]){ // Checks if we had more wins than losses that year
			cout << setw(6) << (i + 1900) << ", " << setw(6);
			counter++;
		}

		if (counter == 3){ // Makes rows of 3
			cout << endl;
			counter = 0;
		}
	}

}

// 4: Display Years with Minimum # of Wins
void dispMinWins(){

	int counter = 0;
	int choice = 0;
	
	cout << "Enter the Desired Minimum Number of Wins:";
	cin >> choice;

	cout << "The Years with at least " << choice << " wins are:" << endl;

	for (int i = 0; i < ((sizeof(wins) / sizeof(int))); i++){

		if (wins[i] >= choice){ // Checks wins per year in array
			cout << setw(6) << (i + 1900) << ", " << setw(6);
			counter++;
		}

		if (counter == 3){ // Makes rows of 3
			cout << endl;
			counter = 0;
		}
	}

}

// 5: Display Years with Minimum # of Losses
void dispMinLoss(){

	int counter = 0;
	int choice = 0;

	cout << "Enter the Desired Minimum Number of Losses:";
	cin >> choice;

	cout << "The Years with at least " << choice << " losses are:" << endl;

	for (int i = 0; i < ((sizeof(wins) / sizeof(int))); i++){

		if (losses[i] >= choice){ // Check losses array
			cout << setw(6) << (i + 1900) << ", " << setw(6);
			counter++;
		}

		if (counter == 3){ // Makes rows of 3
			cout << endl;
			counter = 0;
		}
	}

}

// 6: Display Average Win/Loss Record Between Two Years
void dispAvgWL(){
	int choice1 = 0;
	int choice2 = 0;
	double avgWins = 0;
	double avgLosses = 0;

	// Get User Input and Makes sure it is Valid

	while (((choice1 < 1900) || (choice1 > numYears)) && ((choice2 < 1900) || (choice2 > numYears))){

		cout << "Enter The Desired Begining Year: ";
		cin >> choice1;
		cout << "Enter The Desired Ending Year: ";
		cin >> choice2;
	}

	// Take Average values for Wins and Losses

	for (int i = choice1; i <= choice2; i++){
		avgWins = avgWins + wins[i - 1900];
		avgLosses = avgLosses + losses[i - 1900];
	}

	avgWins = avgWins / (choice2 - choice1);
	avgLosses = avgLosses / (choice2 - choice1);

	// Output 

	cout << endl << "The average record from " << choice1 << " to " << choice2;
	cout << fixed << setprecision(2);
	cout << " is " << avgWins << " - " << avgLosses << endl;
}

// 7: Display A Year with a Specific Win/Loss Record
void dispSpecificRecord(){

	int counter = 0;
	int winChoice = -1;
	int lossChoice = -1;
	int resultExists = 0;

	// Get Input and Check Validity

	while (((winChoice < 0) || (winChoice > 13)) && ((lossChoice < 0) || (lossChoice > 13))){
		cout << "Enter The Desired Win #: ";
		cin >> winChoice;
		cout << "Enter The Desired Loss #: ";
		cin >> lossChoice;
	}

	cout << "The Years with the Specific Record of " << winChoice << " - " << lossChoice << " are:" << endl;

	// Loops through both Arrays and checks Values w conditional

	for (int i = 0; i < ((sizeof(wins) / sizeof(int))); i++){

		if ((losses[i] == lossChoice) && (wins[i] == winChoice)){
			cout << setw(6) << (i + 1900) << ", " << setw(6);
			counter++;
			resultExists = 1;
		}

		if (counter == 3){ // Makes rows of 3
			cout << endl;
			counter = 0;
		}
	}

	if (resultExists == 0){
		cout << "No Results Exist!!";
	}
}