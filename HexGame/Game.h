class Game
{
public:
	// Member-variable.
	bool isGameOver;

	// Constructor.
	Game();

	// Function to run the game.
	void run();

	// Function to ask user if they want to verse a computer or human.
	bool isVersingComputer();

	// Function to ask user the games board-size.
	void promptForBoardSize(int& xSize, int& ySize);
};

