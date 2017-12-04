// state.h
// interface for a State class
// Name: Allen Duong

#include <string>
using namespace std;

class State {
public:

	State(); // No arguments
	State(string, string, string, int, int, int); // Abbreviation, Name, capital, population, year created, and # reps in congress
	~State();
	void setStatename(string);
	void setAbbrev(string);
	void setCapital(string);
	void setPopul(int);
	void setYear(int);
	void setCongressreps(int);
	string getStatename();
	string getAbbrev();
	string getCapital();
	int getPopul();
	int getYear();
	int getCongressreps();

	void dispInfo();
	
private:

	string abbreviation;
	string statename;
	string capital;
	int population;
	int year;
	int congressreps;
};

