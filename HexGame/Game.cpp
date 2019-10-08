#include <iostream>
#include "Game.h"
#include "Player.h"
#include "Board.h"

using namespace std;

// Constructor.
Game::Game()
{
	// Populate member-variable.
	isGameOver = false;
}

// Function to run the game.
void Game::run()
{
	// Output header.
	cout << "Hex Game!" << endl;
	cout << "By Dhani Kris Frohling" << endl;
	cout << endl;

	// Declare variables.
	int xSize, ySize, activePlayer = -1, move[2];

	// Create player objects.
	Player playerRed(-1, false), playerBlue(1, isVersingComputer());

	// Prompt user for board-size.
	promptForBoardSize(xSize, ySize);

	// Create board object.
	Board board(xSize, ySize);

	// Run game while it's not finished.
	do
	{
		// Output board for players (not computers).
		if (activePlayer == -1)
			board.output();
		else
			if (!playerBlue.isComputer)
				board.output();

		// If red-players turn.
		if (activePlayer == -1)
		{
			// Prompt for move.
			playerRed.promptForMove(move[0], move[1], xSize, ySize, board);

			// Store move to board (as index).
			board.moves[move[0] - 1][move[1] - 1] = -1;
		}
		// Else, blue-players turn.
		else
		{
			// If computer.
			if (playerBlue.isComputer)
			{
				// Retrieve AI move.
				playerBlue.getComputerMove(board, move[0], move[1]);
			}
			// Else, if human.
			else
			{
				// Prompt for move.
				playerBlue.promptForMove(move[0], move[1], xSize, ySize, board);
			}

			// Store move to board (as index).
			board.moves[move[0] - 1][move[1] - 1] = 1;
		}

		// If a player has won.
		if (activePlayer == -1)
		{
			if (board.hasPlayerWon(-1))
			{
				board.output();
				cout << "Red-player has won!" << endl << endl;
				isGameOver = true;
			}
		}
		else
		{

			if (board.hasPlayerWon(1))
			{
				board.output();
				cout << "Blue-player has won!" << endl << endl;
				isGameOver = true;
			}
		}

		// Update active-player.
		if (activePlayer == -1)
			activePlayer = 1;
		else
			activePlayer = -1;

	} while (isGameOver == false);
}

// Function to ask user if they want to verse a computer or human.
bool Game::isVersingComputer()
{
	// Initalise variable.
	char input;

	// Prompt to verse computer or human.
	cout << "Do you want to verse a computer or a human (c/h): ";
	cin >> input;
	cout << endl;

	// Return result.
	if (input == 'c')
		return true;
	else
		return false;
}

// Function to ask user for games board-size.
void Game::promptForBoardSize(int& xSize, int& ySize)
{
	// Prompt for board-width.
	cout << "Input the width of the board (3-15): ";
	cin >> xSize;

	// Validate board-width.
	while (xSize < 3 || xSize > 15)
	{
		cout << endl;
		cout << "Invalid input." << endl;
		cout << "Input the width of the board (3-15): ";
		cin >> xSize;
	}
	
	// Prompt for board-height.
	cout << "Input the height of the board (3-15): ";
	cin >> ySize;

	// Validate board-width.
	while (xSize < 3 || xSize > 15)
	{
		cout << endl;
		cout << "Invalid input." << endl;
		cout << "Input the width of the board (3-15): ";
		cin >> xSize;
	}

	cout << endl;
}