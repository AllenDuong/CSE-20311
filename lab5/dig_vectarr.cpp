// dig_vect2.cpp
// Name: Allen Duong
//
//	Both digits and freq are still objects of the C++ <vector> class. 
//	But use iterators to access their contents. Do not use indexing. 

#include <iostream>
#include<vector>
using namespace std;

void findfreq(vector<int>, vector<int> &);
void results(vector<int>, vector<int>);

int main()
{
  // array with random digits
  vector<int> digits = {4,3,6,5,7,8,9,4,6,3,1,3,5,7,6,3,6,
                  5,6,7,0,2,9,7,1,3,2,1,6,7,4,6,2,8,
                  1,4,5,6,0,2,7,6,4,5,6,8,3,5,7,1,5};

  vector<int> freq = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};    // array to tally the frequency of digits

  findfreq(digits, freq); // compute digits' frequencies
  results(digits, freq);  // display frequencies for each digit

  return 0;
}

void findfreq(vector<int> a, vector<int> & freq)
{
	for (vector<int>::iterator it = a.begin(); it != a.end(); ++it)

		freq.at(*it)++;
}

void results(vector<int> a, vector<int> freq)
{
  for (int n = 0; n <= 9; n++) 
    cout <<  "digit " << n << " occurs " << freq[n] << " times" << endl;
}

