// letterfreq.cpp
//	Name: Allen Duong
//
//	The program should prompt the user for the text file's name, and as it reads all the characters from that file, ]
//	it will tally the frequency for each letter of the alphabet (case-insensitive).
//
//	Output: 
//	The program should output the frequency values for each letter, followed by : the total number of letters; the total number of characters;
//	and the "space percentage" (which indicates the amount of white space in the file), to 1 decimal value.Follow a format somewhat similar to 
//	the output examples shown below; but feel free to change the look to your liking.
//

#include<string>
#include<array>
#include<vector>
#include<cctype>
#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;

void countChars(vector<char>);

int main(){

	system("clear"); // Linux console clear; ("cls") for windows

	// Declare Variables
	string filename(" ");
	char curChar(' ');
	vector<char> characters = {};

	// Open and Read Initial File From User Input

	bool validFile = false;

	while (!validFile){

		cout << "Enter a desired input file in the form: \"filename.txt\" WITHOUT quotes: " << endl;
		getline(cin, filename);


		ifstream inputFile(filename);

		if (inputFile.is_open())
		{
			validFile = true;

			while (inputFile.get(curChar))
			{
				characters.push_back(curChar);
			}

			inputFile.close();

		}

		else{
			cout << "Unable to open file" << endl << endl;
			validFile = false;
		}
	}

	// Make String Vector Lowercase

	for (int i = 0; i < characters.size(); i++){

		characters[i] = tolower(characters[i]);
	}

	// Call Function
	countChars(characters);

	return 0;
}

void countChars(vector<char> characters){

	array<int, 26> letterFreq = {};
	int letterNum = 0;
	int spaceNum = 0;

	for (auto it = characters.begin(); it != characters.end(); it++){
		char curChar = *it;

		if (ispunct(curChar)){}
		else if (isspace(curChar)){ spaceNum++; }
		else if (isalpha(curChar)){

			letterFreq[curChar - 97]++; // Ascii Dec code for 'a' is 97
			letterNum++;
		}

	}


	cout << "The Character Frequencies Are:" << endl;
	cout << "-------------------------------" << endl;
	for (int i = 0; i < letterFreq.size(); i++){

		cout << char('A' + i) << ": " << letterFreq[i] << endl;

	}

	double whitePercent = (double(spaceNum) / double(characters.size())) * 100; // Calculate White Space Percentage

	cout << "There were: " << letterNum << " letters" << endl;
	cout << "There were: " << characters.size() << " total characters" << endl;
	cout << "There were: " << spaceNum << " white space characters" << endl;
	cout << setprecision(1) << fixed; // Single Decimal Point
	cout << "Space Percentage: " << whitePercent << "%" << endl;

}