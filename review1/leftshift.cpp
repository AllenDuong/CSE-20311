#include <iostream>
using namespace std;

void display(int[], int);
void leftshift(int[], int);

int main()
{
	int arr[] = { 4, 9, 2, 8, 4, 3, 8, 7, 6 };
	int size = sizeof(arr) / sizeof(int);

	cout << "original array order: ";
	display(arr, size);

	leftshift(arr, size);
	cout << "after 1st left shift: ";
	display(arr, size);

	leftshift(arr, size);
	cout << "after 2nd left shift: ";
	display(arr, size);

	return 0;
}

void display(int a[], int sz)
{
	for (int i = 0; i < sz; i++)
		cout << a[i] << " ";
	cout << endl;
}

// a circular left shift
void leftshift(int a[], int sz)
{
	int temp[sz] = { 0 };

	for (int i = 0; i < sz; i++){ // Shift everything over to left

		temp[i] = a[i + 1];
	}

	temp[(sz - 1)] = a[0]; // Assign First value of old array to first of last

	for (int j = 0; j < sz; j++){ // Write new array to the passed array

		a[j] = temp[j];
	}


}