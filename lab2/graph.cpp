//
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
//			jThe first number meeting both these conditions is our solution.
//
//			We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; 
//			for example, the 5-digit number, 15234, is 1 through 5 pandigital.
//			

#include<cmath>
#include<iomanip>
#include<iostream>

using namespace std;

// Function Prototypes 
void genPrime(int returnValues[]);

const int maximumValue = 7654321; // Set Maximum of Prime Values Generated


int main(){

	int primeNumbers[maximumValue] = {};
	int testNum = 0;
	int

		genPrime(primeNumbers); // Create an Array of all Prime Numbers up to 7654321

	for (int i = (maximumValue - 1); i > 0; i--){ // Count the Number of Digits
		testNum = genPrime[i];
		lengthIndex = 0;

		while (testNum > 1) {
			testNum = testNum / 10;
			lengthIndex++;
		}
		//checks if number is pandigital
		if (checkPand(testNum, lengthIndex) == true){
			cout << genPrime[i] << endl;
			break;
		}
	}

	return 0;
}

// Check if a Number is a Pandigital Number 
//		Uses the logic that: 
//			1. A Pandigital numbers (digital product) = (factorial of number length)
//			2. A Pandigital numbers (digital sum) = (summation of consecutive integers to length)

bool checkPand(long number, long length){

	int i = 0;
	int grid[length];
	while (number>0) {
		grid[i] = number % 10;
		number = number / 10;
		i++;
	}
	int summation = 0, factorial = 1;
	int summation1 = 0, factorial1 = 1;
	for (int i = 0; i <= length - 1; i++) {
		factorial = factorial*grid[i];//counts product of digits and factorial of length
		factorial1 = factorial1*(i + 1);
		summation = summation + grid[i];//counts sum of digits and summation of integers to length
		summation1 = summation1 + (i + 1);
	}
	if ((factorial == factorial1) and(summation == summation1) and(factorial != 0)) return true;
	else return false;

	return 0;
}



// Generate Primes up to largest 7th Pandigital
void genPrime(int returnValues[]){

	// Create Boolean Array
	bool tfPrime[maximumValue] = { 0 };

	for (int i = 0; i < maximumValue; ++i){
		tfPrime[i] = true;
	}

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

	// OUTPUT PRIMES TO AN ARRAY
	// Generate array of Values

	int values[maximumValue] = {};

	for (int i = 0; i < maximumValue; i++){
		values[i] = i;
	}

	// Output Primes

	for (int j = 2; j < maximumValue; j++){

		if (tfPrime[j] == false){ // Check if the value is prime or not
			values[j] = 0;
		}
	}


	returnValues = values;
}

