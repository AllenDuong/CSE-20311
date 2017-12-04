// Part 1: A Simple Array and Input Redirection
// grades.cpp
// Name: Allen Duong
//		Reads integer grade values from a data file into an array,
//		then compares their average and their standard deviation
//		Must use unix input redirection to read data at the time of running
//
//	Ran using the command /grades < number.txt >> output.txt

#include<iostream>
#include<cmath>

using namespace std;

int readArray(int grades[], int length);
double calcAverage(int grades[], int numGrades);
double calcStdDev(int grades[], int numGrades, double average);

int main(){

	int grades[50];
	int numGrades = 0;
	double average = 0;
	double standardDeviation = 0;

	numGrades = readArray(grades, 50);
	average = calcAverage(grades, numGrades);
	standardDeviation = calcStdDev(grades, numGrades, average);

	cout << "The Average of the Grades is: " << average << endl;
	cout << "The Standard Deviation of the Grades is: " << standardDeviation << endl;


	return 0;
}

// Read Array
int readArray(int grades[], int length){
	int numGrades = 0;

	for (int i = 0; i < length; i++){
		
		cin >> grades[i];

		if (grades[i] == -1){
			break;
		}

		numGrades++;
	}
	
	return numGrades;
}

// Calculate Average
double calcAverage(int grades[], int numGrades){

	double average = 0;
	double sum = 0;

	for (int i = 0; i < numGrades; i++){

		sum = sum + grades[i];
	}

	average = sum / numGrades;

	return average;
}

//Calculate Standard Deviation
double calcStdDev(int grades[], int numGrades, double average){

	double standardDeviation = 0;
	 

	for (int i = 0; i < numGrades; i++){
		standardDeviation = standardDeviation + pow((average - grades[i]),2);
	}

	standardDeviation = standardDeviation / (numGrades - 1);
	standardDeviation = sqrt(standardDeviation);

	return standardDeviation;
}
 
