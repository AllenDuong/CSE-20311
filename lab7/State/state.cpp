// Implementation of state.h, the State class
// Name: Allen Duong

#include "state.h"
#include <iostream>

State::State(){ // No arguments
}

State::State(string a, string b, string c, int x, int y, int z){ // Abbreviation, Name, capital, population, year created, and # reps in congress

	abbreviation = a;
	statename = b;
	capital = c;
	population = x;
	year = y;
	congressreps = z;

}

State::~State(){}

void State::setStatename(string a){
	statename = a;
}

void State::setAbbrev(string a){
	abbreviation = a;
}

void State::setCapital(string a){
	capital = a;
}

void State::setPopul(int x){
	population = x;
}

void State::setYear(int x){
	year = x;
}

void State::setCongressreps(int x){
	congressreps = x;
}

string State::getStatename(){
	return statename;
}

string State::getAbbrev(){
	return abbreviation;
}

string State::getCapital(){
	return capital;
}

int State::getPopul(){
	return population;
}

int State::getYear(){
	return year;
}

int State::getCongressreps(){
	return congressreps;
}

void State::dispInfo(){

	cout << endl << "*******************************************" << endl;
	cout << "The Information for " << statename << " (" << abbreviation << ") is:" << endl;
	cout << "Capital: " << capital << endl;
	cout << "Population: " << population << endl;
	cout << "Year Founded: " << year << endl;
	cout << "Numer of Reps in Congress: " << congressreps;
	cout << endl << "*******************************************" << endl;

 }