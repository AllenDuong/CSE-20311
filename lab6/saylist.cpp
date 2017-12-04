// saylist.cpp
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
//	UPDATE 10/9/17: 
//		Added:
//			-the "display all sayings" feature should display a number to each saying's left (the numbers should however not be part of the database)
//			-the sayings should be stored alphabetically(sorted) once a startup file is loaded
//			-to facilitate the above, you will use a list as your container
//			-when a new saying is added, the database should still be in sorted order
//			-a new option should be added to allow the user the delete a saying
//
//		Added EXTRA CREDIT********
//			DONE - the user can opt to not load a startup file by just hitting Enter/Return when prompted for one 
//			DONE - the program must allow uppercase letters; comparisons however must be insensitive to case
//			DONE - when reading in sayings, empty lines(if a user hits Enter / Return at the menu prompt) or even blank lines must be disregarded, and not added to the database
//			DONE - write this program without using list's sort function. Therefore, when loading a startup file, as the program inserts the sayings one by one, 
//					it will need to know where to fit that saying into the list; similarly for the option to add a new saying. The insert() method will be very useful here.
//
// 

#include<iostream>
#include<fstream> // Used for file IO
#include<string>
#include<vector>
#include<list>

using namespace std;

void dispAll(list<string>); 
void enterNew(list<string> &);
void findSubStr(list<string>);
void saveFile(list<string>);
void alphabeticalOrder(list<string> &);
void delPhrase(list<string> &);



int main(){
	system("clear"); // Linux console clear; ("cls") for windows

	// Declare Variables
	int choice = 0;
	string filename (" ");
	string line (" ");
	list<string> sayings = {};

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

		else if (filename.empty()){ // 
			break;
		}

		else{
			cout << "Unable to open file" << endl << endl;
			validFile = false;
		}
	}

	// Display Menu 

	while ((choice < 1) || (choice > 6)){ // Repeats Prompt until Quit

		// sayings.sort();

		alphabeticalOrder(sayings); // Sort the Doubly Linked List constantly w User Defined Function

		cout << endl;
		cout << "--------------FAVORITE SAYINGS ARCHIVE--------------" << endl;
		cout << "Enter the Corresponding Number for an Option : " << endl;
		cout << "	1 - Display All Sayings Currently in Database" << endl;
		cout << "	2 - Enter a New Saying Into The Database" << endl;
		cout << "	3 - List Sayings That Contain a Given Substring Entered By The User " << endl;
		cout << "	4 - Save All Sayings In a New Text File" << endl;
		cout << "	5 - Delete a Saying from the Database" << endl;
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
			enterNew(sayings);
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
			delPhrase(sayings);
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
void dispAll(list<string> sayings){
	int i = 1;

	cout << "Current Sayings - (Saved and Unsaved):" << endl;
	
	for (auto it = sayings.begin(); it != sayings.end(); ++it){

		cout << "	" << i << " - " << *it << endl;
		i++;
	}

}

// 2: Enter a new saying into the database
void enterNew(list<string> &sayings){
	
	string newString;

	// Ask for New String
	cout << "Enter a New String: " << endl;
	getline(cin, newString);

	if (newString.empty()){
		//Literally nothing.
	}
	else{
		sayings.push_back(newString);
	}
	

}

// 3: List sayings that contain a given substring entered by the user

void findSubStr(list<string> sayings){
	string subString = " ";

	// Get Sub String from Input
	cout << "Enter a Substring to Search For: ";
	getline(cin, subString);
	


	for (auto it = sayings.begin(); it != sayings.end(); ++it){

		string curSaying = *it;

		size_t pos = curSaying.find(subString);      // position of subString in a saying

		if (pos != string::npos){ // If position isnt the last one in the string (ie word not found)
			cout << "	" << curSaying << endl;
		}
	}
}




// 4: Save all sayings in a new text file
void saveFile(list<string> sayings){

	string filename;

	// Ask for New Filename
	cout << "Enter a desired output file in the form: \"filename.txt\" WITHOUT quotes: " << endl;
	cin >> filename;
	cin.ignore(); // Flush input stream


	ofstream sayingFile(filename);

	for (auto it = sayings.begin(); it != sayings.end(); ++it){

		sayingFile << *it << endl;
	}
	sayingFile.close();
}

// 5: Delete a Saying from the Database
void delPhrase(list<string> &sayings){
	int choice;
	
	dispAll(sayings); // Display all Phrases (Passing a pointer works because dispAll uses iterators)

	cout << "Select a Phrase to Delete:" << endl;
	cin >> choice;
	cin.ignore();

	auto it = sayings.begin();
	advance(it, (choice - 1));

	sayings.erase(it);
}


void alphabeticalOrder(list<string> &sayings){ 
	

	// Convert List to Vector to allow Indexing
	vector<string> temp;
	vector<string> tempLower; //Lowercases

	for (auto it = sayings.begin(); it != sayings.end(); ++it){

		temp.push_back(*it);
		tempLower.push_back(*it);

	}
	
	for (auto itLw = tempLower.begin(); itLw != tempLower.end(); ++itLw){ // For each string in Vector, Iterate through all characters in string
			
		string tempString = *itLw;

		for (int i = 0; i < tempString.length(); i++){

			tempString[i] = tolower(tempString[i]);
		}

		*itLw = tempString;

	}

	int size = temp.size();
	
	bool flag;

	do
	{
		flag = 0;
		for (int count = 0; count < (size - 1); count++)
		{
			if (tempLower[count] > tempLower[count + 1]) //compare with lowercase vector
			{
				tempLower[count].swap(tempLower[count + 1]); 
				temp[count].swap(temp[count + 1]); // Swap within normal case vector to be returned

				flag = 1;

			}

		}

	} while (flag == 1);
	
	sayings.erase(sayings.begin(), sayings.end()); // Clear List

	// Return Data to List Format
	for (auto it = temp.begin(); it != temp.end(); ++it){

		sayings.push_back(*it);
	}

}


