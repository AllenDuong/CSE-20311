// Pythagoream Theorem Calc
// Takes user input for two sides of 
// a right triangle and outputs the third

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	// Decalre and Assign all Variables to 0
	int choice = 0;
	double sideOne = 0;
	double sideTwo = 0;
	double  missingSide = 0;
	
	//Get Choice from User
	cout << "Enter the Corresponding Number:" << endl;
	cout << "Which Side of the Triangle are you missing?" << endl;
	cout << "1 - Hypotenuse" << endl;
	cout << "2 - Base" << endl;
	cin >> choice;
	
	switch(choice)// Calculate Missing Side based on choice
	{
		
		case 1:
			
			cout << "Enter the First Base: ";
			cin >> sideOne;
			cout << endl << "Enter the Second Base: ";
			cin >> sideTwo;

			if ((sideOne < 0) || (sideTwo < 0)) // Safety Measure
			{
				cout << "Your Input is Invalid!!" << endl;
				cout << "RERUN PROGRAM" << endl;
				break;
			}
			
			missingSide = pow(sideOne,2) + pow(sideTwo,2);
			missingSide = sqrt(missingSide);
			//Output missing length
			cout << "The Missing Side has a length of " << missingSide << " units" << endl;
			break;
			 
			
		case 2:
		
			cout << "Enter the Base Length: ";
			cin >> sideOne;
			cout << endl << "Enter the Hypotenuse Length: ";
			cin >> sideTwo;

			if ((sideOne < 0) || (sideTwo < 0)) //Safety Check
			{
				cout << "Your Input is Invalid!!" << endl;
				cout << "RERUN PROGRAM" << endl;
				break;
			}
			
			//Make sure hypotenuse is larger than base
			if ( sideOne > sideTwo) {
			 	cout << "This is not a Right Triangle" << endl; 
			 	cout << "Leaving Program..." << endl;
			 	break;
			}
			
			missingSide = pow(sideTwo,2) - pow(sideOne,2);
			missingSide = sqrt(missingSide);
			//Output missing length
			cout << "The Missing Side has a length of " << missingSide << " units" << endl;
	
	}
	

	return 0;
}

