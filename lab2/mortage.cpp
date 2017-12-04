// mortage.cpp

#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

int main(){
	// Initialize Variables
	double balance = 0;
	double interestRate = 0;
	double monthlyPayment = 0;
	double totalPayment = 0;

	int month = 1;
	int years = 0;
	double interest = 0;

	bool valid = 0; // Used to repeatedly ask for input 

	// Get Input
	while (valid == 0){
		cout << "Enter the Principal Balance in USD (00.00): ";
		cin >> balance;
		cout << "Enter the Yearly Interest Rate (0.01 = 1%): ";
		cin >> interestRate;
		cout << "Enter the Desired Monthly Payment in USD (00.00) : ";
		cin >> monthlyPayment;
		cout << endl;

		// Checks for invalid input. If valid then leaves loop
		if ((balance * (interestRate / 12)) >= monthlyPayment){
			cout << "Your Input Results in a Balance that grows to Infinity!!" << endl << endl;;
		}
		else if ((balance < 0) || (interestRate < 0) || (monthlyPayment < 0)){
			cout << "Your Input was Negative and Invalid!" << endl << endl;
		}
		else if ((balance > 0) && (interestRate > 0) && (monthlyPayment > 0)){
			valid = 1;
		}
	}
	// Calculations + Display

	cout << setw(10) << "Month" << setw(15) << "Payment" << setw(14) << "Interest" << setw(15) << "Balance" << endl; //Header

	while (balance > 0){

		interest = balance * (interestRate / 12);
		balance = balance + interest;

		// Define cases for the last monthly payment (smaller than normal)
		if ((balance - monthlyPayment) >= 0){
			balance = balance - monthlyPayment;
			totalPayment = totalPayment + monthlyPayment;
		}
		else if ((balance - monthlyPayment) < 0){
			monthlyPayment = balance;
			totalPayment = totalPayment + balance;
			balance = 0;
		}


		// Output Broken into Lines for Easy Readability
		cout << fixed;
		cout << setprecision(2) << setw(10) << month;
		cout << setw(10) << "$" << monthlyPayment;
		cout << setw(10) << "$" << interest;
		cout << setw(10) << "$" << balance << endl;

		month++;
	}

	//Calculate Time in Years
	month = month - 1;

	years = floor((month) / 12);
	month = month % 12;

	cout << "You paid a total of $" << totalPayment << " over " << years << " years and " << month << " months." << endl;

	return 0;
}