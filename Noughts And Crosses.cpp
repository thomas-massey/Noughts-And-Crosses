// This is a program that plays noughts and crosses. It is a two player game. The first player is X and the second player is O. The first player to get three in a row wins. The game is played on a 3x3 grid. The grid is numbered as follows:
// It will make use of OOP

#include <iostream>

class Game {
public:
	// Create a board attribute
	char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };

	// Winning scenarios
	int winning_positions[8][3][3] = {
		{{1,1,1},
		{0,0,0},
		{0,0,0}},

		{{0,0,0},
		{1,1,1},
		{0,0,0}},

		{{0,0,0},
		{0,0,0},
		{1,1,1}},

		{{1,0,0},
		{1,0,0},
		{1,0,0}},

		{{0,1,0},
		{0,1,0},
		{0,1,0}},

		{{0,0,1},
		{0,0,1},
		{0,0,1}},

		{{1,0,0},
		{0,1,0},
		{0,0,1}},

		{{0,0,1},
		{0,1,0},
		{1,0,0}}

	};

	// Players turn
	bool player_1_turn;

	// Current winner
	bool player_1_has_won;

	// Create a method to print the board
	void show_board() {
		std::cout << "-------------" << std::endl;
		for (int i = 0; i < 3; i++) {
			std::cout << "| " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << " |" << std::endl;
			std::cout << "-------------" << std::endl;
		}
	};

	// Create a method to check if the game is over
	void check_for_win() {
		for (int i = 0; i < 8; i++) {
			int xsum = 0;
			int osum = 0;
			// Now compare the board to the current board
			for (int j = 0; j < 9; j++) {
				if ((winning_positions[i][(j / 3)][j % 3] == 1) and (board[(j / 3)][j % 3] == 'X')) {
					xsum += 1;
				}
				else if ((winning_positions[i][(j / 3)][j % 3] == 1) and (board[(j / 3)][j % 3] == 'O')) {
					osum += 1;
				}
			}
			if (xsum == 3) {
				bool player_1_has_won = true;
				std::cout << "Player 1 has won!" << std::endl;
				system("pause");
			}
			else if (osum == 3) {
				bool player_1_has_won = false;
				std::cout << "Player 2 has won!" << std::endl;
				system("pause");
			}
		}
	}
};
		
// Make Terminal a subclass of Game
class Terminal : public Game {
public:
	void register_player_move() {
		if (player_1_turn) {
			// Show the board to the player
			show_board();
			// Ask where they want to place their X
			bool no_valid_choice = true;
			while (no_valid_choice) {
				std::cout << "Where do you want to place your X?" << std::endl;
				char choice;
				std::cin >> choice;
				// Check if the choice is in range and the square isnt occupied by comparing it to its number in the cell
				if ((choice >= '1' && choice <= '9') and (choice == board[(choice - '1') / 3][(choice - '1') % 3])) {
					// Place the X in the top left
					// Get the array position from the square number
					int row = (choice - '1') / 3;
					int column = (choice - '1') % 3;
					board[row][column] = 'X';
					no_valid_choice = false;
				}
				else {
					std::cout << "Invalid choice, please enter a number between 1 and 9 and then pick an availiable square." << std::endl;
				}
			}
			player_1_turn = false;
			system("cls");
			
		}
		else {
			// AI will pick random square
			bool no_valid_choice = true;
			int move, row, column;
			while (no_valid_choice) {
				move = rand() % 9;
				row = move / 3;
				column = move % 3;
				if (board[row][column] == (move + '1')) {
					board[row][column] = 'O';
					no_valid_choice = false;
					std::cout << "The AI has placed an O in square " << move + 1 << std::endl << std::endl << std::endl;
					player_1_turn = true;
				}
			}
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
		no_valid_choice = true;
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
		
		game.player_1_turn = player_1_first;
		
		// Clear the screen
		system("cls");

		// Now do the first move details
		game.register_player_move();
		
		while (not game_over) {
			
			// Use the terminal subclass of Game to do the rest of the game
			game.register_player_move();
			
			game.check_for_win();

			
		}
	}
}