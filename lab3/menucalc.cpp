// Part 3: Text Menu Calculator
// menucalc.cpp
//
// Text menu driven basic calculator for the four simple arithmetic operations: 
// add, subtract, multiply, divide
// prompt the user to enter a choice, after which the user will be prompted to enter 2 numbers; the program will then compute and display the result.

#include<cmath> //Used for Calculations
#include<iostream> // Used for Input and Output

using namespace std;

// Prototype Functions
void addFunc();
void subFunc();
void mulFunc();
void divFunc();

int main(){
	int choice = 0;
	 
	while ((choice < 1) || (choice > 5)){ // Repeats Calculator Prompt until Quit

		cout << "--------------TEXT MENU CALCULTOR--------------" << endl;
		cout << "Enter the Corresponding Number for an Option : " << endl;
		cout << "		1 - Addition" << endl;
		cout << "		2 - Subtraction" << endl;
		cout << "		3 - Multiplication" << endl;
		cout << "		4 - Division" << endl;
		cout << "		5 - Quit" << endl;

		cout << "Your Choice: ";
		cin >> choice;
		cout << endl;

		// Call Function Corresponding to Choice and Set Choice back to 0
		if (choice == 1){
			addFunc();
			choice = 0;
		}
		else if (choice == 2){
			subFunc();
			choice = 0;
		}
		else if (choice == 3){
			mulFunc();
			choice = 0;
		}
		else if (choice == 4){
			divFunc();
			choice = 0;
		}
		else if (choice == 5){ // Exit Program
			cout << "Goodbye!.." << endl;
			break;
		}
	}

	return 0;
}

// Addition Function, Gets Input and Outputs Results
void addFunc(){
	double numOne = 0;
	double numTwo = 0;
	double answer = 0;

	cout << "Enter Your Two Values:" << endl;
	cin >> numOne >> numTwo;

	answer = numOne + numTwo;

	cout << "(" << numOne << ") + (" << numTwo << ") = " << answer << endl;
}

// Subtraction Function, Gets Input and Outputs Results
void subFunc(){
	double numOne = 0;
	double numTwo = 0;
	double answer = 0;

	cout << "Enter Your Two Values:" << endl;
	cin >> numOne >> numTwo;

	answer = numOne - numTwo;

	cout << "(" << numOne << ") - (" << numTwo << ") = " << answer << endl;

}

// Multiplication Function, Gets Input and Outputs Results
void mulFunc(){
	double numOne = 0;
	double numTwo = 0;
	double answer = 0;

	cout << "Enter Your Two Values:" << endl;
	cin >> numOne >> numTwo;

	answer = numOne * numTwo;

	cout << "(" << numOne << ") * (" << numTwo << ") = " << answer << endl;
}

// Division Function, Gets Input and Outputs Results
void divFunc(){
	double numOne = 0;
	double numTwo = 0;
	double answer = 0;

	cout << "Enter Your Two Values:" << endl;
	cin >> numOne >> numTwo;

	answer = numOne / numTwo;

	cout << "(" << numOne << ") / (" << numTwo << ") = " << answer << endl;

}

