// dig_vectarr.cpp
// Name: Allen Duong
//
//	In this version, digits will be a <vector> and freq will be an <array>. 
//	Use either indexing or iterators for the two containers, your choice 
//	(note that this version may seem to make more sense, since digits has a 
//	dynamic nature to it, whereas freq is static in nature; 
//	it is suggested that you use iterators for digits, and indexing for freq).

#include <iostream>
#include<vector>
#include<array>

using namespace std;

void findfreq(vector<int>, array<int,10> &);
void results(vector<int>, array<int>);

int main()
{
  // array with random digits
  vector<int> digits = {4,3,6,5,7,8,9,4,6,3,1,3,5,7,6,3,6,
                  5,6,7,0,2,9,7,1,3,2,1,6,7,4,6,2,8,
                  1,4,5,6,0,2,7,6,4,5,6,8,3,5,7,1,5};

  array<int, 10> freq = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};    // array to tally the frequency of digits

  findfreq(digits, freq); // compute digits' frequencies
  results(digits, freq);  // display frequencies for each digit

  return 0;
}

void findfreq(vector<int> a, array<int,10> & freq)
{
	for (vector<int>::iterator it = a.begin(); it != a.end(); ++it)

		freq[(*it)]++;
}

void results(vector<int> a, array<int,10> freq)
{
  for (int n = 0; n <= 9; n++) 
    cout <<  "digit " << n << " occurs " << freq[n] << " times" << endl;
}

