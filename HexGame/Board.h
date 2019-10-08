#pragma once
#include <iostream>

class Board
{
private:
	// Member-variables.
	int currentPosition[2], stack[100][2], index = 0, burntPositions[25][2], indexBurnt = 0;
	bool branchFound = false, alreadyTraversed = false;
public:
	// Member-variables.
	int xSize, ySize, ** moves;

	// Constructor.
	Board(int x, int y);

	// Desctructor.
	~Board();

	// Function to output board to console.
	void output();

	// Function to check surrounding board locations for a piece.
	void checkForSurroundingPieces(int id);

	// Function to determine whether a player has won.
	bool hasPlayerWon(int id);

	// Function to reset variables used in the previous two functions.
	void resetVariables();

	// Function to determine if a position is already occupied.
	bool isMoveTaken(int x, int y);
};

