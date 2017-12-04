// rational.cpp; Class Implementation
//  Name: Allen Duong
//
//	Note that you may not overload any operator (except the constructor).
//	The private attributes are numer and denom. 


// Header Files
#include "rational.h"
#include <iostream>
// Functions

int gcd(int a, int b){ // Used to simplify functions
	int c;
	while (a != 0){
		c = a; a = b%a; b = c;
	}
	return b;
}

// Implementations 

Rational::Rational(){
	numer = 1;
	denom = 1;
}

Rational::Rational(int a, int b){
	numer = a;
	denom = b;
}

Rational::~Rational(){}

int Rational::getNumer(){
	return numer;
}

int Rational::getDenom(){
	return denom;
}

void Rational::setNumer(int a){
	numer = a;
}


void Rational::setDenom(int b){
	denom = b;
}


void Rational::print(){
	std::cout << numer << "/" << denom << std::endl;
}


Rational Rational::add(Rational x){
	Rational temp;

	int a = numer * x.getDenom();
	int b = denom * x.getNumer();

	temp.setNumer(a + b);
	temp.setDenom(denom * x.getDenom());

	return temp;
}


Rational Rational::subtract(Rational x){
	Rational temp;

	int a = numer * x.getDenom();
	int b = denom * x.getNumer();

	temp.setNumer(a - b);
	temp.setDenom(denom * x.getDenom());

	return temp;
}


Rational Rational::multiply(Rational x){
	Rational temp;

	temp.setNumer(numer * x.getNumer());
	temp.setDenom(denom * x.getDenom());

	return temp;
}


Rational Rational::divide(Rational x){
	Rational temp;

	temp.setNumer(numer * x.getDenom());
	temp.setDenom(denom * x.getNumer());

	return temp;
}

Rational Rational::simplify(){
	Rational temp;

	int gcd = gcd(numer, denom);

	temp.setNumer(numer / gcd);
	temp.setDenom(denom / gcd);

	return temp;
}