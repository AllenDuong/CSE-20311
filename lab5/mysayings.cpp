// mysayings.cpp
// Name: Allen Duong
//
//	store and manage many of your favorite sayings
//	Your program should first ask the user for a "startup" data file, one that will contain some of your initial favorite sayings.
//	The program will then display a menu of options for the user; the options must at least contain the following:
//
//		- display all sayings currently in the database
//		- enter a new saying into the database
//		- list sayings that contain a given substring entered by the user
//		- save all sayings in a new text file
//		- quit the program
//
//	assumptions: we will only use lowercase letters for now; no saying will exceed 256 characters in length; 
//	the startup file will always be a valid one; and each line of the file will consist of only one saying. 
//	Of course, you need to verify that the file exists!	
//

#include<iostream>
#include<sstream> // Used for string IO
#include<fstream> // Used for file IO
#include<string>
#include<vector>
#include<cstdlib> // Used for RNG
#include<ctime>

using namespace std;

void dispAll(vector<string>); 
void enterNew(vector<string> &, string);
void findSubStr(vector<string>);
void saveFile(vector<string>);
void genRandStr(vector<string>);
vector<string> splitWords(string);


int main(){

	// Declare Variables
	int choice = 0;
	string filename (" ");
	string line (" ");
	vector<string> sayings;

	// Open and Read Initial File From User Input

	bool validFile = false;

	while (!validFile){

		cout << "Enter a desired input file in the form: \"filename.txt\" WITHOUT quotes: " << endl;
		getline(cin,filename);
		

		ifstream sayingFile(filename);
	
		if (sayingFile.is_open())
		{
			validFile = true;

			while (getline(sayingFile, line))
			{
				sayings.push_back(line);
			}

			sayingFile.close();
			
		}
		else{
			cout << "Unable to open file" << endl << endl;
			validFile = false;
		}
	}

	// Display Menu 

	while ((choice < 1) || (choice > 6)){ // Repeats Prompt until Quit

		cout << endl;
		cout << "--------------FAVORITE SAYINGS ARCHIVE--------------" << endl;
		cout << "Enter the Corresponding Number for an Option : " << endl;
		cout << "	1 - Display All Sayings Currently in Database" << endl;
		cout << "	2 - Enter a New Saying Into The Database" << endl;
		cout << "	3 - List Sayings That Contain a Given Substring Entered By The User " << endl;
		cout << "	4 - Save All Sayings In a New Text File" << endl;
		cout << "	5 - Generate a Random Phrase from Words of Current Phrases" << endl;
		cout << "	6 - Quit" << endl;

		cout << "Your Choice: ";
		cin >> choice;
		cin.ignore(); // Flush input stream
		cout << endl;

		// Call Function Corresponding to Choice and Set Choice back to 0
		if (choice == 1){
			dispAll(sayings);
			choice = 0;
		}
		else if (choice == 2){
			enterNew(sayings, filename);
			choice = 0;
		}
		else if (choice == 3){
			findSubStr(sayings);
			choice = 0;
		}
		else if (choice == 4){
			saveFile(sayings);
			choice = 0;
		}
		else if (choice == 5){
			genRandStr(sayings);
			choice = 0;
		}
		else if (choice == 6){ // Exit Program
			cout << "Goodbye!..." << endl;
			break;
		}
	}
	return 0;
}

// 1: Display all sayings currently in database
void dispAll(vector<string> sayings){

	cout << "Current Sayings - (Saved and Unsaved):" << endl;
	
	for (int i = 0; i < sayings.size(); ++i){

		cout << "	" << sayings[i] << endl;
	}

}

// 2: Enter a new saying into the database
void enterNew(vector<string> &sayings, string filename){
	
	string newString;

	// Ask for New String
	cout << "Enter a New String: " << endl;
	getline(cin, newString);

	sayings.push_back(newString);


	ofstream sayingFile(filename);

	for (int i = 0; i < sayings.size(); ++i){

		sayingFile << sayings[i] << endl;
	}
	sayingFile.close();
}

// 3: List sayings that contain a given substring entered by the user

void findSubStr(vector<string> sayings){
	string subString = " ";

	// Get Sub String from Input
	cout << "Enter a Substring to Search For: ";
	getline(cin, subString);
	


	for (int i = 0; i < sayings.size(); ++i){

		string curSaying = sayings[i];
		size_t pos = curSaying.find(subString);      // position of subString in a saying

		if (pos != string::npos){ // If position isnt the last one in the string (ie word not found)
			cout << "	" << curSaying << endl;
		}
	}
}




// 4: Save all sayings in a new text file
void saveFile(vector<string> sayings){

	string filename;

	// Ask for New Filename
	cout << "Enter a desired output file in the form: \"filename.txt\" WITHOUT quotes: " << endl;
	cin >> filename;
	cin.ignore(); // Flush input stream


	ofstream sayingFile(filename);

	for (int i = 0; i < sayings.size(); ++i){

		sayingFile << sayings[i] << endl;
	}
	sayingFile.close();
}

// 5: Function to Generate Random String of Length n from words of present files
void genRandStr(vector<string> sayings){

	string newString = "";
	string currString = " ";
	vector<string> words;
	int n = 0;
	int q = 0;
	int pos = 0;

	cout << "Enter a Desired Length for this Phrase: ";
	cin >> n;
	cin.ignore(); //Flush input stream

	// Intialize the random number generator; use the current time as the seed 
	srand(time(NULL));
	

	cout << "	New Original Phrase: ";

	for (int i = 0; i < n; i++){

		q = rand() % sayings.size();
		words = splitWords(sayings[q]);
		pos = rand() % words.size();

		cout << words[pos] << " ";
	}
	cout << endl;
}

vector<string> splitWords(string s) // Function to break a string into words and return the words as a vector
{
	istringstream iss(s);
	vector<string> v;
	while (iss >> s)
	{
		v.push_back(s);
	}
	return v;
}
