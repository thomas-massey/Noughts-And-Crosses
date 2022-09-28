// This is a program that plays noughts and crosses. It is a two player game. The first player is X and the second player is O. The first player to get three in a row wins. The game is played on a 3x3 grid. The grid is numbered as follows:
// It will make use of OOP

#include <iostream>

class Game {
	public:
		// Create a board attribute
		char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
};
	
int main()
{
	// Ask the user in the terminal if they want to play with a GUI or a terminal
	bool no_valid_choice = true;
	bool GUI;
	while (no_valid_choice) {
		std::cout << "Do you want to play with a GUI or a terminal? (G/T)" << std::endl;
		char choice;
		std::cin >> choice;
		if (choice == 'G' || choice == 'g') {
			// Run the GUI version
			no_valid_choice = false;
			GUI = true;
		}
		else if (choice == 'T' || choice == 't') {
			// Run the terminal version
			no_valid_choice = false;
			GUI = false;
		}
		else {
			std::cout << "Invalid choice, please enter either 'G' or 'T'." << std::endl;
		}
	}
	// Now instantiate a Game.
	Game game;
	// Now go diffrent paths dependent on wether the user wants to play with a GUI or a terminal
	if (not GUI) {
		// Print out the board
		std::cout << "The board is as follows:" << std::endl;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				std::cout << game.board[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
}