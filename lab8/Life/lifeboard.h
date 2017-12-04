// lifeboard.h
// Name: Allen Duong

const int gridSize = 40;

class Lifeboard {

  public:
    Lifeboard();
    ~Lifeboard();
	bool getCell(int, int);
	void killCell(int, int);
	void reviveCell(int, int);
	void update();
	void display();

  private:
	  bool board[gridSize+3][gridSize+3]; // Remember that Coords are [Y][X] and start at 0;
};										  // Added a 'Blank' Border on each side to make implementation of neighbor check easier
	
