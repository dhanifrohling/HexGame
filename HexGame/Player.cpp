#include "Player.h"

using namespace std;

// Constructor.
Player::Player(int id, bool isComp)
{
	// Populate member-variables.
	playerID = id;
	isComputer = isComp;
	firstMovePlayed = false;
}

// Function to ask given-player for a move.
void Player::promptForMove(int& x, int& y, int xSize, int ySize, Board& board)
{
	// Declare variable.
	string input, moveX, moveY;
	bool firstPromptMade = false;

	// Get move with range-validation.
	do
	{
		// Output invalid move if so.
		if (firstPromptMade == true)
			cout << "Invalid input." << endl;
		else
			firstPromptMade = true;

		// Prompt given player for move.
		if (playerID == -1)
			cout << "Red";
		else
			cout << "Blue";

		cout << " players turn (x,y): ";

		// Store input.
		cin >> input;

		// Convert input to integer ordered-pair.

		// Find position of ','.
		char pos = (char)input.find_first_of(',');

		// Substring coordinates.
		moveX = input.substr(0, pos);
		moveY = input.substr(pos + 1);

		// Convert coordinates to integers.
		x = stoi(moveX);
		y = stoi(moveY);

		cout << endl;
	}
	// Range & already occupied validation.
	while ((x < 1 || x > xSize) || (y < 1 || y > ySize) || board.isMoveTaken(x, y));
}

// Function to determine AI's next move.
void Player::getComputerMove(Board& board, int& x, int& y)
{
	// If first-move.
	if (!firstMovePlayed)
	{
		// Play approximately three-quarters down first-column.
		lastMove[0] = 1;
		lastMove[1] = (int)ceil(0.75 * board.ySize);

		firstMovePlayed = true;
	}
	// Else, second or greater moves.
	else
	{
		// Determine move by what's available & what's closest to other side of board.
		if (board.moves[(lastMove[0] - 1) + 1][lastMove[1] - 1] == 0)
		{
			lastMove[0] = lastMove[0] + 1;
		}
		else if (board.moves[(lastMove[0] - 1) + 1][(lastMove[1] - 1) - 1] == 0)
		{
			lastMove[0] = lastMove[0] + 1;
			lastMove[1] = lastMove[1] - 1;
		}
		else if (board.moves[lastMove[0] - 1][(lastMove[1] - 1) - 1] == 0)
		{
			lastMove[1] = lastMove[1] - 1;
		}
		else if (board.moves[lastMove[0] - 1][(lastMove[1] - 1) + 1] == 0)
		{
			lastMove[1] = lastMove[1] + 1;
		}
		else
		{
			// Error-checking.
			cout << "The A.I. broke.";
		}
	}

	// Return move.
	x = lastMove[0];
	y = lastMove[1];
}