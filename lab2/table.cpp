// table.cpp
// Displays an integer multiplication table
// Ask the user for the size of the table (2 integers)

#include<iostream>
#include<iomanip>
using namespace std;

int main(){

	// Create Variables
	int rows = 0;
	int columns = 0;
	int output = 0;
	int width = 4;

	// Get Input
	cout << "-----MULTIPLICATION TABLE-----" << endl;
	cout << endl << "How Many Columns?: ";
	cin >> columns; 
	cout << "How Many Rows?: ";
	cin >> rows;
	cout << endl;


	// Loopy Loop + Output
	// Check for combinations of iterative values. If they're a bordering column or row, output border

	for (int i = 0; i <= rows; i++){

		for (int j = 0; j <= columns; j++){
			
			if ((i == 0) && (j == 0)){
				cout << setw(width) << "*" << setw(width);
			}
			else if ((i == 0) && (j != 0)){
				cout << j << setw(width);
			}
			else if ((i != 0) && (j == 0)){
				cout << i << setw(width);
			}
			else {
				cout << (i * j) << setw(width);
			}
		}
		
		cout << endl;
	
	}

	return 0;
}
