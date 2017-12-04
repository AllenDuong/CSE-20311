// rationalmain.cpp
// Name: Allen Duong
//
// A Driver to Test All the Methods of rational.h
//

#include <iostream>
#include "rational.h"

using namespace std;

int main(){

	Rational a(28, 4), b(96, 12), c, d(1,0);

	cout << "The Following Rationals Have Been Declared:" << endl;
	cout << "A = ";
	a.print();
	cout << "B = ";
	b.print();
	cout << "C = ";
	c.print();
	cout << "C was declared without parameters" << endl;
	cout << "D = ";
	d.print();
	cout << "D is 1 over 0" << endl;

	cout << "***************************************" << endl;
	cout << "The Numerators for A, B, and C are: " <<
		a.getNumer() << ", " <<
		b.getNumer() << ", " <<
		c.getNumer() << endl;

	cout << "***************************************" << endl;
	cout << "The Denomerators for A, B, and C are: " <<
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


	cout << "***************************************" << endl;
	cout << "The Simplification of A is :";
	a.simplify();
	a.print();

	cout << "The Simplification of B is :";
	a.simplify();
	b.print();

	cout << "***************************************" << endl;
	cout << "Operations With Overloaded Operators:" << endl;
	cout << "And Overloaded Input/Output:" << endl;

	cout << "The Addition of A + B is :";
	Add = a + b;
	cout << Add << endl;
	cout << "The Subtraction of A - B is :";
	Sub = a - b;
	cout << Sub << endl;
	cout << "The Multiplication of A * B is :";
	Mul = a * b;
	cout << Mul << endl;
	cout << "The Division of A / B is :";
	Div = a / b;
	cout << Div << endl;

	cout << "***************************************" << endl;
	cout << "The Simplification of All of These Are:" << endl;
	cout << "The Addition of A + B is :";
	Add.simplify();
	cout << Add << endl;
	cout << "The Subtraction of A - B is :";
	Sub.simplify();
	cout << Sub << endl;
	cout << "The Multiplication of A * B is :";
	Mul.simplify();
	cout << Mul << endl;
	cout << "The Division of A / B is :";
	Div.simplify();
	cout << Div << endl;

	return 0;
}
