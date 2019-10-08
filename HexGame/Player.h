#include <iostream>
#include <string>
#include "Board.h"

class Player
{
public:
	// Member-variables.
	int playerID, lastMove[2];
	bool isComputer, firstMovePlayed;

	// Constructor.
	Player(int id, bool isComp);

	// Function to ask given-player for a move.
	void promptForMove(int& x, int& y, int xSize, int ySize, Board& board);

	// Function to determine AI's next move.
	void getComputerMove(Board& board, int& x, int& y);
};

