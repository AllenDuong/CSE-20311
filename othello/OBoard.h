// OBoard.h
// Name: Allen Duong

const int boardSize= 64;

class OBoard {

public:
	OBoard();
	~OBoard();
	void move(int, int, char); // The third value passed is the Player who made the move
	void update(int, int, char);
	void display();
	bool getStatus();
	char declareWinner();

private:
	char board[boardSize][boardSize]; // Remember that Coords are [Y][X] and start at 0;
	bool gameStatus; // False means game is not completed yet
};										  

