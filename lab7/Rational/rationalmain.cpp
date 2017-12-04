// rationalmain.cpp
// Name: Allen Duong
//
// A Driver to Test All the Methods of rational.h
//

#include <iostream>
#include "rational.h"

using namespace std;

int main(){

	Rational a(1, 4), b(1, 2), c;

	cout << "The Following Rationals Have Been Declared:" << endl;
	cout << "A = ";
	a.print();
	cout << "B = ";
	b.print();
	cout << "C = ";
	c.print();
	cout << "C was declared without parameters" << endl;

	cout << "***************************************" << endl;
	cout << "The Numerators for A, B, and C are:" <<
		a.getNumer() << ", " <<
		b.getNumer() << ", " <<
		c.getNumer() << endl;

	cout << "***************************************" << endl;
	cout << "The Denomerators for A, B, and C are:" <<
		a.getDenom() << ", " <<
		b.getDenom() << ", " <<
		c.getDenom() << endl;
	
	cout << "***************************************" << endl;

	Rational Add;
	Add = a.add(b);
	Rational Sub;
	Sub = a.subtract(b);
	Rational Mul;
	Mul = a.multiply(b);
	Rational Div;
	Div = a.divide(b);

	cout << "The Addition of A + B is :";
	Add.print();
	cout << "The Subtraction of A - B is :";
	Sub.print();
	cout << "The Multiplication of A * B is :";
	Mul.print();
	cout << "The Division of A / B is :";
	Div.print();


	return 0;
}
