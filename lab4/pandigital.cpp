// Extra Credit 1: Project Euler #41
//	pandigital.cpp
// Name: Allen Duong
//		We shall say that an n-digit number is pandigital if it makes use of all 
//		the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.
//		What is the largest n - digit pandigital prime that exists ?
//
//		Pre-Coding Logic:
//			Fact: A number is divisible by 3 if and only if the digit sum of the number is divisible by 3
//			Extrapolated, if we perform this test on pandigital numbers of order 1 through 9, all are divisible
//			3 except pandigitals of 4 and 7. Thus the largest pandigital prime must be a pandigital of 7th order.
//
//			Therefore, starting with 7654321 we check each decreasing odd number for being pandigital and prime. 
//			The first number meeting both these conditions is our solution.
//
//			We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; 
//			for example, the 5-digit number, 15234, is 1 through 5 pandigital.
//			

#include<cmath>
#include<iomanip>
#include<iostream>

using namespace std;

// Function Prototypes 
bool checkPand(long int n);
bool checkPrime(long int number);

int main(){

	long int i;

	for (i = 7654321; i >= 1234; i--){

		if (i == 1234567){  // If i reached the smallest 7-digit Pandigital, then skip to largest 4
			i = 4321;		// This is done, just to save CPU resources. Not essential to the solution
		}	

		if (checkPand(i) && checkPrime(i)) { // If the value is Prime AND Pandigital
			cout << "The Largest Pandigital Prime Number is: " << i << endl << endl;
			break; // Break loop since first one that meets this is the largest
		}
	}

	return 0;
}

// Check if a Number is a Pandigital Number 
//		1. Maps each digit to an array to checks for repeated values
//		2. Only works for values up to 9th Place Pandigital (No zeroes)

bool checkPand(long int n){

		bool digiStore[] = { true, true, true, true, true, true, true, true, true };

		int digit, i = 0;

		while (n != 0){

			digit = n % 10;
			if (digit == 0){ // If number is perfectly divisible by 10, then not pandigital
				return false;
			}

			else {
				digiStore[digit - 1] = false; // Sets Indexing Array value to False
			}

			n /= 10;
			i++;
		}

		for (i = i - 1; i >= 0; i--){
			if (digiStore[i] != false) { // If any of the digits repeat (true) then value is not Pandigital
				return false;
			}
		}
	return true;
}




// Check if a Number is Prime
//		1. Checks if Divisible by 2
//		2. Checks odd consecutive numbers for divisibility

bool checkPrime(long int number){

	int i = 0;

	if (number % 2 == 0){ // Checks if even
		return false;
	}

	int sRoot = sqrt((double)number); // Sets the maximum for checking in for loop ; Also type casts it to a double

	for (i = 3; i <= sRoot; i += 2){
		if (number % i == 0){ 
			return false; 
		}
	}

	return true;
}

