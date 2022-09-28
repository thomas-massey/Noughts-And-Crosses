// This is a program that plays noughts and crosses. It is a two player game. The first player is X and the second player is O. The first player to get three in a row wins. The game is played on a 3x3 grid. The grid is numbered as follows:
// It will make use of OOP

#include <iostream>

class Game {
public:
	// Create a board attribute
	char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };

	// Create a method to print the board
	void printBoard() {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				std::cout << board[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
};
		
// Make Terminal a subclass of Game
class Terminal : public Game {
public:
	void register_player_move(bool player_1_turn, Game game) {
		if (player_1_turn) {
			// Ask where they want to place their X
			bool no_valid_choice = true;
			while (no_valid_choice) {
				std::cout << "Where do you want to place your X?" << std::endl;
				char choice;
				std::cin >> choice;
				// Check if the choice is in range
				if (choice >= '1' && choice <= '9') {
					// Place the X in the top left
					// Get the array position from the square number
					int row = (choice - '1') / 3;
					int column = (choice - '1') % 3;
					game.board[row][column] = 'X';
					no_valid_choice = false;
				}
				else {
					std::cout << "Invalid choice, please enter a number between 1 and 9." << std::endl;
				}
				player_1_turn = false;
			}
		}
		else {
			// AI will pick random square
			int move = rand() % 9 + 1;
			int row = (move - '1') / 3;
			int column = (move - '1') % 3;
			game.board[row][column] = 'O';
			player_1_turn = true;
		};
	};
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
	// Now go diffrent paths dependent on wether the user wants to play with a GUI or a terminal
	if (not GUI) {
		Terminal game;
		// Now do the pregame variables
		// Ask if it is against player 2 or AI
		bool no_valid_choice = true;
		bool against_AI;
		while (no_valid_choice) {
			std::cout << "Do you want to play against another player or an AI? (P/A)" << std::endl;
			char choice;
			std::cin >> choice;
			if (choice == 'P' || choice == 'p') {
				// Run the player vs player version
				no_valid_choice = false;
				against_AI = false;
			}
			else if (choice == 'A' || choice == 'a') {
				// Run the player vs AI version
				no_valid_choice = false;
				against_AI = true;
			}
			else {
				std::cout << "Invalid choice, please enter either 'P' or 'A'." << std::endl;
			}
		}
		// Now ask if Player 1 goes first
		bool no_valid_choice = true;
		bool player_1_first;
		while (no_valid_choice) {
			std::cout << "Do you want to go first? (Y/N)" << std::endl;
			char choice;
			std::cin >> choice;
			if (choice == 'Y' || choice == 'y') {
				// Run the player vs player version
				no_valid_choice = false;
				player_1_first = true;
			}
			else if (choice == 'N' || choice == 'n') {
				// Run the player vs AI version
				no_valid_choice = false;
				player_1_first = false;
			}
			else {
				std::cout << "Invalid choice, please enter either 'Y' or 'N'." << std::endl;
			}
		}
		// Now start the game loop
		bool game_over = false;

		// Add a turn player_1_turn variable
		bool player_1_turn = player_1_first;

		// Print board state
		game.show_board();

		// Now do the first move details
		if (player_1_first) {
			// Ask where they want to place their X
			bool no_valid_choice = true;
			while (no_valid_choice) {
				std::cout << "Where do you want to place your X?" << std::endl;
				char choice;
				std::cin >> choice;
				// Check if the choice is in range
				if (choice >= '1' && choice <= '9') {
					// Place the X in the top left
					// Get the array position from the square number
					int row = (choice - '1') / 3;
					int column = (choice - '1') % 3;
					game.board[row][column] = 'X';
					no_valid_choice = false;
				} else {
					std::cout << "Invalid choice, please enter a number between 1 and 9." << std::endl;
				}
			}
			player_1_first = false;
		}
		else {
			// AI will pick random square
			int move = rand() % 9 + 1;
			int row = (move - '1') / 3;
			int column = (move - '1') % 3;
			game.board[row][column] = 'O';
			player_1_turn = true;
		}
		
		while (not game_over) {
			

			// Print out the board
			game.printBoard();
			
			// Use the terminal subclass of Game to do the rest of the game
			game.
		}
	}
}