#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <thread>

using namespace std;

const int BOARD_SIZE = 8;
const int width = 40;

char board[BOARD_SIZE][BOARD_SIZE];

typedef struct player {
    char sympol;
    void (*movefunc)(player);
}player;

int choice;
int levels;

/**init_board function to initialize the game board
 *takes no parameters 
 *
 */
void init_board()
{
	for (int i = 0; i < BOARD_SIZE; i++) 
	{
        	for (int j = 0; j < BOARD_SIZE; j++) 
		{
            		board[i][j] = ' ';  
        	}
	}

}

/**print_board function to print the game board
 *takes no parameters
 *
 */
void print_board()
{
	system ("clear");
	int i,j;
	
	for (int nums = 1; nums < BOARD_SIZE + 1; nums++)
	{
		cout<< " " << nums <<"  ";
	}
	cout << "\n";

    for (i=0; i<BOARD_SIZE; i++) 
    {
        for (j=0; j<BOARD_SIZE; j++)
            cout << " " <<board[i][j] <<" |";
        cout << "\n";
    }

}
/**human_move function takes the users choice
 * takes player parameter
 *
 */
void human_move(player player)
{
	int choice;
	
	cout <<"player " << player.sympol << " enter your choice : ";
	cin >> choice;
	int col = choice - 1;

	for (int rows = BOARD_SIZE - 1; rows >= 0; rows--)
	{
		if (board[rows][col] == ' ')
		{
			board[rows][col] = player.sympol;
			break;
		}
		else 
			continue;
		
	}
}
/**rand_move function to make the computer move
 *takes no parameters
 */
void rand_move(player player)
{
	srand(time(NULL));
	int choice = rand() % BOARD_SIZE;
	int col = choice; 
	for (int rows = BOARD_SIZE - 1; rows >= 0; rows--)
	{
		if (board[rows][col] == ' ')
		{
			board[rows][col] = player.sympol;
			break;
		}
		else
			continue;

	}
}
/**animate_move function to delay the move
 *takes no paramaters
 */
void animate_move()
{
	this_thread::sleep_for(chrono::milliseconds(200));
}
/**get winner function checks for the winner
 *takes no parameter
 *returns : char of the winner on success / '-' if fails
 */
char get_winner()
{
	//check rows
	
	for (int rows = 0; rows < BOARD_SIZE; rows++)
	{
		for(int col = 0; col < 5; col++)
		{
			if (board[rows][col] != ' ' && board[rows][col] == board[rows][col + 1] && board[rows][col] == board[rows][col+2]
					&& board[rows][col] == board[rows][col + 3])
			return (board[rows][col]);
		}
	}
	//check columns 
	
	for (int col = 0; col < BOARD_SIZE; col++)
	{
		for (int rows = 0; rows < 5; rows++)
		{
			if (board[rows][col] != ' ' && board[rows][col] == board[rows + 1][col] && board[rows][col] == board[rows + 2][col]
					&& board[rows][col] == board[rows + 3][col])
				return (board[col][rows]);
		}
	}
	//check diagnol
	
	for (int rows = 0, i = 0, j = 5, col = 0; i < BOARD_SIZE - 3; i++, rows++, j--)
	{
		rows = 0 + i;
		col = 0;
		j = 5 - i;
		for (; j > 0; j--, rows++, col++)
		{
			if (board[rows][col] != ' ' && board[rows][col] == board[rows + 1][col + 1] && board[rows][col] == 
					board[rows + 2][col + 2]&& board[rows][col] == board[rows + 3][col + 3])
				return board[rows][col];

		}
	}	
		for (int rows = 0, j = 4, i = 0, col = 0; i < BOARD_SIZE - 3; col++, j--, i++)
		{
			rows = 0;
			col = 1 + i;
			j = 4 - i;
			for (; j > 0; j--, rows++, col++)
			{
				if (board[rows][col] != ' ' && board[rows][col] == board[rows + 1][col + 1] && board[rows][col] ==
						board[rows + 2][col + 2]&& board[rows][col] == board[rows + 3][col + 3])
					return board[rows][col];

			}
		}
			return ('-');
}
/**play_1player_game function to implement the single player mode
 *takes player parameter
 */
void play_1player_game(player human_player, player computer_player)
{
	bool re_play = true;
	int choice;

while (re_play)
{
	int max_moves = BOARD_SIZE * BOARD_SIZE, count = 0;
	char winner ;
	init_board();
	while (count < max_moves)
	{
		print_board();
		human_player.movefunc(human_player);
		animate_move();
		count++;

		if (winner = get_winner() != '-')
		{
			print_board();
			cout << "player X wins\n";
			break;
		}
		print_board();
		computer_player.movefunc(computer_player);
		animate_move();
		count++;

		if (winner = get_winner() != '-')
		{
			print_board();
			cout << "player O wins\n";
			break;
		}
	}
	if (count == max_moves)
	{
		cout<<"it's a tie\n";
	}

	cout << "\n" << "\n" << setw(12) << "1- Re_play\n";
	cout << setw(12) << "2- Exit \n";
	cout << "Enter your chioce : ";
	cin >> choice;

	if (choice == 1)
		re_play = true;
	else 
		re_play = false;

}
}
/**play_2player_game to implement multi player mode
 *takes player parameter
 */
void play_2player_game(player player1 , player player2)
{
	bool re_play = true;
	int choice;

while (re_play)
{
	int max_moves = BOARD_SIZE * BOARD_SIZE, count = 0;
	char winner ;
	init_board();
	while (count < max_moves)
	{
		print_board();
		player1.movefunc(player1);
		animate_move();
		count++;

		if (winner = get_winner() != '-')
		{
			print_board();
			cout << "player X wins\n";
			break;
		}
		print_board();
		player2.movefunc(player2);
		animate_move();
		count++;

		if (winner = get_winner() != '-')
		{
			print_board();
			cout << "player O wins\n";
			break;
		}
	}
	if (count == max_moves)
	{
		cout<<"it's a tie\n";
	}

	cout << "\n" << "\n" << setw(12) << "1- Re_play\n";
	cout << setw(12) << "2- Exit \n";
	cout << "Enter your chioce : ";
	cin >> choice;

	if (choice == 1)
		re_play = true;
	else 
		re_play = false;

}
}
/**loading screen function to simulate the loading page
 *takes no parameters
 */
void loading_screen() 
{
	system("clear");
    cout << "Loading Connect 4...\n";
    	this_thread::sleep_for(chrono::milliseconds(1500));
    
}
/*menu function to display the menu
 *takes no parameters
 */
void menu()
{
	system("clear");
	string s[] = {"CONNECT4", "1- SINGLE PLAYER", " 2- MULTi_PLAYER", "3- EXIT", "1- EASY", "2- MEDIUM", "3- HARD"};

	cout<<setw(width + s[0].length() / 2) <<right << s[0] <<"\n" << "\n" <<"\n" << "\n";
	cout<<setw(width + s[1].length() / 2) <<right << s[1] <<"\n";
	cout<<setw(width + s[2].length() / 2) <<right << s[2] <<"\n";
	cout<<setw(width + s[3].length() / 2) <<right << s[3] <<"\n";
	
	cout <<"enter your choice : ";
	cin >> choice;
	if (choice == 1) 
        {
		system("clear");
	        cout<<setw(width + s[4].length() / 2) <<right << s[4] <<"\n";
		cout<<setw(width + s[5].length() / 2) <<right << s[5] <<"\n";
		cout<<setw(width + s[6].length() / 2) <<right << s[6] <<"\n";
		
		cout << "enter your choice : ";
		cin>> levels;
            player human_player = {'X', human_move};
            player computer_player = {'O', rand_move};
            play_1player_game(human_player, computer_player);
        }
        
    
	else if (choice == 2)
	{
            player player1 = {'X', human_move};
            player player2 = {'O', human_move};
            play_2player_game(player1, player2);
        }
        
	
	else if (choice == 3)
	{
		exit(0);
	}
	else
		cout <<"invalid option please choose number from 1 to 3\n";
}
int main()
{
    loading_screen();
    menu();
    return 0;
}
