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

	int num = gcd(numer, denom);

	numer = (numer / num);
	denom = (denom / num);

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

	int num = gcd(numer, denom);

	numer = (numer / num);
	denom = (denom / num);
}


void Rational::setDenom(int b){
	denom = b;

	int num = gcd(numer, denom);

	numer = (numer / num);
	denom = (denom / num);

}

void Rational::setRational(int a, int b){
	numer = a;
	denom = b;

	int num = gcd(numer, denom);

	numer = (numer / num);
	denom = (denom / num);
}


void Rational::print(){

	if (denom == numer){
		std::cout << "+(1)" << std::endl;
	}
	else if ((denom == (numer * -1)) || ((denom * -1) == numer)){
		std::cout << "-(1)" << std::endl;
	}

	else if ((numer > 0) && (denom > 0)){

		std::cout << "+(" << numer << "/" << denom << ")" << std::endl;
	}
	else if ((numer < 0) && (denom < 0)){
		
		std::cout << "+(" << (numer * -1) << "/" << (denom * -1) << ")" << std::endl;
	}

	else if ((numer < 0) && (denom > 0)){

		std::cout << "-(" << (numer * -1) << "/" << denom << ")" << std::endl;
	}
	else if ((numer > 0) && (denom < 0)){

		std::cout << "-(" << numer << "/" << (denom * -1) << ")" << std::endl;
	}
	else if ((numer == 0) && (denom != 0)){
		std::cout << "0" << std::endl;
	}
	else if (denom == 0){
		std::cout << "Invalid. Divided by Zero!" << std::endl;
	}
	
}


Rational Rational::add(Rational x){
	Rational temp;

	int a = numer * x.getDenom();
	int b = denom * x.getNumer();

	temp.setNumer(a + b);
	temp.setDenom(denom * x.getDenom());
	temp.simplify();
	return temp;
}


Rational Rational::subtract(Rational x){
	Rational temp;

	int a = numer * x.getDenom();
	int b = denom * x.getNumer();

	temp.setNumer(a - b);
	temp.setDenom(denom * x.getDenom());
	temp.simplify();
	return temp;
}


Rational Rational::multiply(Rational x){
	Rational temp;

	temp.setNumer(numer * x.getNumer());
	temp.setDenom(denom * x.getDenom());
	temp.simplify();
	return temp;
}


Rational Rational::divide(Rational x){
	Rational temp;

	temp.setNumer(numer * x.getDenom());
	temp.setDenom(denom * x.getNumer());
	temp.simplify();
	return temp;
}

void Rational::simplify(){

	int num = gcd(numer, denom);

	numer = (numer / num);
	denom = (denom / num);

}

Rational Rational::operator+(Rational x){
	
	Rational temp;

	int a = numer * x.getDenom();
	int b = denom * x.getNumer();

	temp.setNumer(a + b);
	temp.setDenom(denom * x.getDenom());

	return temp;
}

Rational Rational::operator-(Rational x){

	Rational temp;

	int a = numer * x.getDenom();
	int b = denom * x.getNumer();

	temp.setNumer(a - b);
	temp.setDenom(denom * x.getDenom());

	return temp;
}

Rational Rational::operator*(Rational x){

	Rational temp;

	temp.setNumer(numer * x.getNumer());
	temp.setDenom(denom * x.getDenom());

	return temp;
}

Rational Rational::operator/(Rational x){

	Rational temp;

	temp.setNumer(numer * x.getDenom());
	temp.setDenom(denom * x.getNumer());

	return temp;
}

std::ostream & operator<<(std::ostream &output, const Rational &R){

	if (R.denom == R.numer){
		output << "+(1)";
	}
	else if ((R.denom == (R.numer * -1)) || ((R.denom * -1) == R.numer)){
		output << "-(1)";
	}

	else if ((R.numer > 0) && (R.denom > 0)){

		output << "+(" << R.numer << "/" << R.denom << ")";
	}
	else if ((R.numer < 0) && (R.denom < 0)){

		output << "+(" << (R.numer * -1) << "/" << (R.denom * -1) << ")";
	}

	else if ((R.numer < 0) && (R.denom > 0)){

		output << "-(" << (R.numer * -1) << "/" << R.denom << ")";
	}
	else if ((R.numer > 0) && (R.denom < 0)){

		output << "-(" << R.numer << "/" << (R.denom * -1) << ")";
	}
	else if ((R.numer == 0) && (R.denom != 0)){
		output << "0" << std::endl;
	}
	else if (R.denom == 0){
		output << "Invalid. Divided by Zero!";
	}

	return output;

}

std::istream & operator>>(std::istream &input, Rational &R){
	std::cout << "Enter Numerator:";
	input >> R.numer;
	std::cout << "Enter Denominator:";
	input >> R.denom;
	return input;
}
