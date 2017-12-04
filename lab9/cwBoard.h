// cwBoard.h
// Name: Allen Duong

#include <vector>
#include <string>

using namespace std;

// Global Variables
const int gridSize = 15;

// Structures
struct word{

	int xCoord;
	int yCoord;
	string direction;
	string phrase;

};

class cwBoard {

public:
	cwBoard(vector<string>);
	~cwBoard();
	void dispGameBoard();
	void dispAnsBoard();
	void dispClues();
	void dispGameBoardF(string output);
	void dispAnsBoardF(string output);
	void dispCluesF(string output);

private:
	char board[gridSize][gridSize]; // Remember that Coords are [Y][X] and start at 0;
	vector<word> allWords;
};									

