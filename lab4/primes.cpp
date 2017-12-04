// Part 2: Prime Numbers
// primes.cpp
// Name: Allen Duong
//		Find all prime numbers between 1 and 1,000
//		Dislay Primes 10 per row, with columns lined up


#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

// Prototype Functions
void findPrimes(bool tfPrime[]);
void outputPrimes(bool tfPrime[]);

const int maximumValue = 1000; // Set maximum of values

int main(){
	
	// Create Boolean Array

	bool tfPrime[maximumValue] = { 0 };

	for (int i = 0; i < maximumValue; ++i){
		tfPrime[i] = true;
	}

	// Call Functions

	findPrimes(tfPrime);
	outputPrimes(tfPrime);

	return 0;
}

// Determine Primes
void findPrimes(bool tfPrime[]){
	
	// Determine Prime Values

	for (int j = 2; j < sqrt(maximumValue); j++)
	{
		//Mark Multiples of J as False (Not Prime)
		for (int k = 2; k < maximumValue; k++)
		{
			if ((j*k) > maximumValue){ // Safety Check so index of array doesn't exceed max 
				break;
			}
			tfPrime[j*k] = false; // Set numbers with factors to false
		}
	}

}

// Generate Values and Output Primes
void outputPrimes(bool tfPrime[]){
	
	int count = 0;

	// Generate array of Values

	int values[maximumValue] = {};

	for (int i = 0; i < maximumValue; i++){
		values[i] = i;
	}

	// Output Primes

	for (int j = 2; j < maximumValue; j++){

		if (tfPrime[j] == true){ // Check if the value is prime or not
			cout << setw(6) << values[j] << setw(6);
			count++;
		}

		if (count == 10){ // Makes sure there are 10 columns
			cout << endl;
			count = 0;
		}
	}

	cout << endl << endl; // Creates a clean ending to output
}
