#include "Board.h"

using namespace std;

// Constructor.
Board::Board(int x, int y)
{
	// Populate member variables.
	xSize = x;
	ySize = y;

	// Allocate memory for 2d-array 'moves'.
	moves = new int* [xSize];
	for (int i = 0; i < xSize; i++)
		moves[i] = new int[ySize];

	// Fill 2d-array 'moves' with 0's.
	for (int x = 0; x < xSize; x++)
		for (int y = 0; y < ySize; y++)
			moves[x][y] = 0;
}

// Desctructor.
Board::~Board()
{
	// Deallocate memory of 2d-array 'moves'.
	for (int i = 0; i < xSize; ++i)
		delete[] moves[i];
	delete[] moves;
}

// Function to output the board.
void Board::output()
{
	// Output first-row.
	cout << ' ';

	for (int i = 1; i <= xSize; i++)
	{
		if (i - 1 >= 10)
			cout << "  ";
		else
			cout << "   ";

		cout << i;
	}

	cout << endl;

	// Output top-border.
	cout << "  ";

	for (int i = 0; i < ((xSize * 4) + 1); i++)
		cout << '-';

	cout << endl;

	// Output board-body.
	for (int y = 0; y < ySize; y++)
	{
		// Output dynamic-spacer.
		for (int i = 0; i < ((2 * (y + 1)) - 2); i++)
			cout << ' ';

		// Output row-number.
		cout << y + 1;

		if (y + 1 >= 10)
			cout << "|";
		else
			cout << " |";

		// Output board-moves.
		for (int x = 0; x < xSize; x++)
		{
			cout << ' ';

			// Output move (if exists).
			switch (moves[x][y])
			{
			case 0:
				cout << ' ';
				break;
			case -1:
				cout << 'R';
				break;
			case 1:
				cout << 'B';
			}

			cout << " |";
		}

		cout << endl;
	}

	cout << endl;
}

// Function to check surrounding board locations for a piece.
void Board::checkForSurroundingPieces(int id)
{
	// Check if there are surround pieces (anti-clockwise).


	// Position 1:

	// If not the first column.
	if (currentPosition[0] != 0)
	{
		// If there is a red-piece in position one.
		if (moves[currentPosition[0] - 1][currentPosition[1]] == id)
		{
			// If the given move is not a burnt move.
			for (int i = 0; i < indexBurnt; i++)
			{
				if (burntPositions[i][0] == currentPosition[0] - 1 && burntPositions[i][1] == currentPosition[1])
				{
					alreadyTraversed = true;
					break;
				}
			}

			// If the given position has already been made (already added to the stack).
			for (int i = 0; i < index; i++)
			{
				if (stack[i][0] == currentPosition[0] - 1 && stack[i][1] == currentPosition[1])
				{
					alreadyTraversed = true;
					break;
				}
			}

			// If move has not already been made.
			if (!alreadyTraversed)
			{
				// Store that a branch is found.
				branchFound = true;

				// Store the branch position.
				stack[index][0] = currentPosition[0] - 1;
				stack[index][1] = currentPosition[1];

				// Increment stacks index.
				index++;
			}
			else
			{
				// Reset alreadyTraversed variable.
				alreadyTraversed = false;
			}
		}
	}

	// Position 2:

	// If not the first column.
	if (currentPosition[0] != 0)
	{
		// If not the last row.
		if (currentPosition[1] != ySize - 1)
		{
			// If there is a red-piece in position two.
			if (moves[currentPosition[0] - 1][currentPosition[1] + 1] == id)
			{
				// If the given move is not a burnt move.
				for (int i = 0; i < indexBurnt; i++)
				{
					if (burntPositions[i][0] == currentPosition[0] - 1 && burntPositions[i][1] == currentPosition[1] + 1)
					{
						alreadyTraversed = true;
						break;
					}
				}

				// Check if this move has already been made (added to the stack).
				for (int i = 0; i < index; i++)
				{
					if (stack[i][0] == currentPosition[0] - 1 && stack[i][1] == currentPosition[1] + 1)
					{
						alreadyTraversed = true;
						break;
					}
				}

				// If move has not already been made.
				if (!alreadyTraversed)
				{
					// Store that a branch is found.
					branchFound = true;

					// Store the branch position.
					stack[index][0] = currentPosition[0] - 1;
					stack[index][1] = currentPosition[1] + 1;

					// Increment stacks index.
					index++;
				}
				else
				{
					// Reset alreadyTraversed variable.
					alreadyTraversed = false;
				}
			}
		}
	}

	// Position 3:

	// If not the last row.
	if (currentPosition[1] != ySize - 1)
	{
		// If there is a red-piece in position three.
		if (moves[currentPosition[0]][currentPosition[1] + 1] == id)
		{
			// If the given move is not a burnt move.
			for (int i = 0; i < indexBurnt; i++)
			{
				if (burntPositions[i][0] == currentPosition[0] && burntPositions[i][1] == currentPosition[1] + 1)
				{
					alreadyTraversed = true;
					break;
				}
			}

			// Check if this move has already been made (added to the stack).
			for (int i = 0; i < index; i++)
			{
				if (stack[i][0] == currentPosition[0] && stack[i][1] == currentPosition[1] + 1)
				{
					alreadyTraversed = true;
					break;
				}
			}

			// If move has not already been made.
			if (!alreadyTraversed)
			{
				// Store that a branch is found.
				branchFound = true;

				// Store the branch position.
				stack[index][0] = currentPosition[0];
				stack[index][1] = currentPosition[1] + 1;

				// Increment stacks index.
				index++;
			}
			else
			{
				// Reset alreadyTraversed variable.
				alreadyTraversed = false;
			}
		}
	}

	// Position 4:

	// If not the last column.
	if (currentPosition[0] != xSize - 1)
	{
		// If there is a red-piece in position four.
		if (moves[currentPosition[0] + 1][currentPosition[1]] == id)
		{
			// If the given move is not a burnt move.
			for (int i = 0; i < indexBurnt; i++)
			{
				if (burntPositions[i][0] == currentPosition[0] + 1 && burntPositions[i][1] == currentPosition[1])
				{
					alreadyTraversed = true;
					break;
				}
			}

			// Check if this move has already been made (added to the stack).
			for (int i = 0; i < index; i++)
			{
				if (stack[i][0] == currentPosition[0] + 1 && stack[i][1] == currentPosition[1])
				{
					alreadyTraversed = true;
					break;
				}
			}

			// If move has not already been made.
			if (!alreadyTraversed)
			{
				// Store that a branch is found.
				branchFound = true;

				// Store the branch position.
				stack[index][0] = currentPosition[0] + 1;
				stack[index][1] = currentPosition[1];

				// Increment stacks index.
				index++;
			}
			else
			{
				// Reset alreadyTraversed variable.
				alreadyTraversed = false;
			}
		}
	}

	// Position 5:

	// If not the first row.
	if (currentPosition[1] != 0)
	{
		// If not the last column.
		if (currentPosition[0] != xSize - 1)
		{
			// If there is a red-piece in position five.
			if (moves[currentPosition[0] + 1][currentPosition[1] - 1] == id)
			{
				// If the given move is not a burnt move.
				for (int i = 0; i < indexBurnt; i++)
				{
					if (burntPositions[i][0] == currentPosition[0] + 1 && burntPositions[i][1] == currentPosition[1] - 1)
					{
						alreadyTraversed = true;
						break;
					}
				}

				// Check if this move has already been made (added to the stack).
				for (int i = 0; i < index; i++)
				{
					if (stack[i][0] == currentPosition[0] + 1 && stack[i][1] == currentPosition[1] - 1)
					{
						alreadyTraversed = true;
						break;
					}
				}

				// If move has not already been made.
				if (!alreadyTraversed)
				{
					// Store that a branch is found.
					branchFound = true;

					// Store the branch position.
					stack[index][0] = currentPosition[0] + 1;
					stack[index][1] = currentPosition[1] - 1;

					// Increment stacks index.
					index++;
				}
				else
				{
					// Reset alreadyTraversed variable.
					alreadyTraversed = false;
				}
			}
		}
	}

	// Position 6:

	// If not the first row.
	if (currentPosition[1] != 0)
	{
		// If there is a red-piece in position five.
		if (moves[currentPosition[0]][currentPosition[1] - 1] == id)
		{
			// If the given move is not a burnt move.
			for (int i = 0; i < indexBurnt; i++)
			{
				if (burntPositions[i][0] == currentPosition[0] && burntPositions[i][1] == currentPosition[1] - 1)
				{
					alreadyTraversed = true;
					break;
				}
			}

			// Check if this move has already been made (added to the stack).
			for (int i = 0; i < index; i++)
			{
				if (stack[i][0] == currentPosition[0] && stack[i][1] == currentPosition[1] - 1)
				{
					alreadyTraversed = true;
					break;
				}
			}

			// If move has not already been made.
			if (!alreadyTraversed)
			{
				// Store that a branch is found.
				branchFound = true;

				// Store the branch position.
				stack[index][0] = currentPosition[0];
				stack[index][1] = currentPosition[1] - 1;

				// Increment stacks index.
				index++;
			}
			else
			{
				// Reset alreadyTraversed variable.
				alreadyTraversed = false;
			}
		}
	}
}

// Function to determine whether a player has won.
bool Board::hasPlayerWon(int id)
{
	resetVariables();

	// If red-player.
	if (id == -1)
	{
		// For each starting position (top-side).
		for (int x = 0; x < xSize; x++)
		{

			// If the given first-position has a red-piece.
			if (moves[x][0] == -1)
			{
				// Store that a red-piece has been found.
				branchFound = true;

				// Store coordinates of the red-piece.
				currentPosition[0] = x;
				currentPosition[1] = 0;

				stack[0][0] = x;
				stack[0][1] = 0;
				index++;

				// While there are still possible branches.
				while (branchFound)
				{
					// Reset that there's a branch found.
					branchFound = false;

					// Check if there's a piece in surrounding spots.
					checkForSurroundingPieces(id);

					// If one or more branchs were found.
					if (branchFound)
					{
						// Update current position with top of stack.
						currentPosition[0] = stack[index - 1][0];
						currentPosition[1] = stack[index - 1][1];

						// If the new branch-point is the other side of the board (if the player has won).
						if (currentPosition[1] == ySize - 1)
							// Return that game has been won.
							return true;
					}
					else
					{
						// Burn the given position.
						burntPositions[indexBurnt][0] = currentPosition[0];
						burntPositions[indexBurnt][1] = currentPosition[1];

						indexBurnt++;

						// Pop the top of the stack.
						index--;

						// Is there no link for the given starting position?
						if (index < 0)
							return false;

						// Set top of stack as new current position.
						currentPosition[0] = stack[index - 1][0];
						currentPosition[1] = stack[index - 1][1];
					}
				}
			}
		}
	}
	// Else, if blue-player.
	else
	{
		// For each starting position (left-side).
		for (int y = 0; y < ySize; y++)
		{

			// If the given first-position has a blue-piece.
			if (moves[0][y] == 1)
			{
				// Store that a blue-piece has been found.
				branchFound = true;

				// Store coordinates of the blue-piece.
				currentPosition[0] = 0;
				currentPosition[1] = y;

				stack[0][0] = 0;
				stack[0][1] = y;
				index++;

				// While there are still possible branches.
				while (branchFound)
				{
					// Reset that there's a branch found.
					branchFound = false;

					// Check if there's a piece in surrounding spots.
					checkForSurroundingPieces(id);

					// If one or more branchs were found.
					if (branchFound)
					{
						// Update current position with top of stack.
						currentPosition[0] = stack[index - 1][0];
						currentPosition[1] = stack[index - 1][1];

						// If red-player.
						if (id == -1)
						{
							// If the new branch-point is the other side of the board (if the player has won).
							if (currentPosition[1] == ySize - 1)
								// Return that game has been won.
								return true;
						}
						// Else, if blue-player.
						else
						{
							// If the new branch-point is the other side of the board (if the player has won).
							if (currentPosition[0] == xSize - 1)
								// Return that game has been won.
								return true;
						}
					}
					else
					{
						// Burn the given position.
						burntPositions[indexBurnt][0] = currentPosition[0];
						burntPositions[indexBurnt][1] = currentPosition[1];

						indexBurnt++;

						// Pop the top of the stack.
						index--;

						// Is there no link for the given starting position?
						if (index < 0)
							return false;

						// Set top of stack as new current position.
						currentPosition[0] = stack[index - 1][0];
						currentPosition[1] = stack[index - 1][1];
					}
				}
			}
		}
	}

	// Return player has not won.
	return false;
}

// Resets the variables used in the previous two functions.
void Board::resetVariables()
{
	currentPosition[0] = -1;
	currentPosition[1] = -1;

	for (int i = 0; i < 100; i++)
	{
		stack[i][0] = -1;
		stack[i][1] = -1;
	}

	index = 0;

	for (int i = 0; i < 25; i++)
	{
		burntPositions[i][0] = -1;
		burntPositions[i][1] = -1;
	}

	indexBurnt = 0;

	branchFound = false;
	alreadyTraversed = false;
}

// Function to determine if a position is already occupied.
bool Board::isMoveTaken(int x, int y)
{
	if ((moves[x - 1][y - 1] == -1) || (moves[x - 1][y - 1] == 1))
		return true;
	else return false;
}