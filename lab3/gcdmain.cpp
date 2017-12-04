// gcdmain.cpp
// asks the user to enter two integer numbers and finds and
// displays the greatest common divisor between them

#include<iostream>

using namespace std;

int getgcd(int valueOne, int valueTwo); // Prototype GCD Function

int main(){

	// Declare and Assign Variables

	int inputOne = 0;
	int inputTwo = 0;
	int greatestCD = 0;

	// Get Input
	cout << endl << "--GCD CALCULATOR--" << endl;
	cout << "Enter Two Integer Values:" << endl;
	cin >> inputOne >> inputTwo;

	// Determine if Input is Valid and Output GCD
	if ((inputOne != inputTwo) && (inputOne > 0) && (inputTwo > 0)){
		greatestCD = getgcd(inputOne, inputTwo);
		cout << endl << "The GCD was: " << greatestCD << endl;
	}
	else{
		cout << endl << "Your Input is Invalid, Re-Run the Program!!" << endl;
	}

	return 0;
}

int getgcd(int valueOne, int valueTwo){

	// Runs as long as they are not equal
	// Essentially subtracts one from the other until they are equal
	// GCD of 1 is lowest possible outcome

	while (valueOne != valueTwo)
	{
		if (valueOne > valueTwo)
			valueOne -= valueTwo;
		else
			valueTwo -= valueOne;
	}

	return valueOne;
}