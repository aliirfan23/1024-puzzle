#include<iostream>
#include<conio.h>//dev c++ ka liya ye chahia hota lol
#include<ctime>//for using the keys directly without pressing enter after every iteration
#include<iomanip>//this is included for the setting of setw function

using namespace std;
//for arrow kwys to function
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

//up function
void up(int array[4][4])
{
	for (int j = 0; j < 4; j++)
	{//limiting the second loop to three as 3+1 will be out of bound other wise
		for (int i = 0; i < 3; i++)
		{
			if (i < 0)
				continue;

			if (array[i][j] == 0)
			{
				int k = i + 1;
				while (k < 4)
				{
					if (array[k][j] != 0)
					{
						array[i][j] = array[k][j];
						array[k][j] = 0;
						break;
					}

					k++;
				}
				if (k < 4)
					i -= 2;
			}
			else if (array[i][j] == array[i + 1][j])
			{
				array[i][j] *= 2;
				array[i + 1][j] = 0;
			}
		}
	}
}
//down function
void down(int array[4][4])
{
	for (int j = 0; j < 4; j++)
	{
		for (int i = 3; i > 0; i--)
		{
			if (i > 3)
				continue;

			if (array[i][j] == 0)
			{
				int k = i - 1;
				while (k >= 0)
				{
					if (array[k][j] != 0)
					{
						array[i][j] = array[k][j];
						array[k][j] = 0;
						break;
					}
					k--;
				}
				if (k >= 0)
					i += 2;
			}
			else if (array[i][j] == array[i - 1][j])
			{
				array[i][j] *= 2;
				array[i - 1][j] = 0;
			}
		}
	}
}
//left function
void left(int array[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (j < 0)
				continue;

			if (array[i][j] == 0)
			{
				int k = j + 1;
				while (k < 4)
				{
					if (array[i][k] != 0)
					{
						array[i][j] = array[i][k];
						array[i][k] = 0;
						break;
					}

					k++;
				}
				if (k < 4)
					j -= 2;
			}
			else if (array[i][j] == array[i][j + 1])
			{
				array[i][j] *= 2;
				array[i][j + 1] = 0;
			}
		}
	}
}
//right function
void right(int array[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 3; j > 0; j--)
		{
			if (j > 3)
				continue;

			if (array[i][j] == 0)
			{
				int k = j - 1;
				while (k >= 0)
				{
					if (array[i][k] != 0)
					{
						array[i][j] = array[i][k];
						array[i][k] = 0;
						break;
					}
					k--;
				}
				if (k >= 0)
					j += 2;
			}
			else if (array[i][j] == array[i][j - 1])
			{
				array[i][j] *= 2;
				array[i][j - 1] = 0;
			}
		}
	}
}
//function to print the game array
void print_game(int array[4][4])
{
	cout << "_____________________________" << endl;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			cout << "| " << setw(4) << array[i][j] << " ";
		cout << "|" << endl;
		if(i<3)
			cout << "|______|______|______|______|" << endl;
		else if(i==3)
			cout << "|______|______|______|______|" << endl;
	}
	
}
//the function to check 1024 tile for winning condition
bool check_win(int array[4][4])
{
	bool temp = false;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (array[i][j] == 1024)
			{
				return true;

			}
		}
	}

	return temp;
}
//function to check if the game is lost or can further proces and check if any further move is possible
bool check_lose(int array[4][4])
{
	bool temp1=true,temp2=true;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (array[i][j] == 0 )
			{
				temp1=false;
				break;
			}
		}
	}
	for (int k = 0; k < 3; k++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (array[k][j] == array[k+1][j] || array[k][j] == array[k][j+1])
			{
				temp2=false;
				break;
			}
		}
	}
	if (temp1 == false || temp2 == false)
		return false;
	else
		return true;
}
//function to provid the game array with a random number after every iteration or a possible move is made
void input_game(int array[4][4], int locationc, int locationr, int num)
{
	while (true)
	{
		if (array[locationr][locationc] == 0)
		{
			array[locationr][locationc] = num;
			break;
		}

		else
		{
			locationr = (rand() % 4)+1;
			locationc = (rand() % 4)+1;
		}

	}
}

int main()
{
	int score = 0;
	int array[4][4];
	//initilaizing array with all entries 0
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			array[i][j] = 0;
	}

	//array[0][1] = 1;
	array[1][1] = 2;
	array[3][1] = 1;
	//array[0][3] = 512;
	//array[3][3] = 512;
	bool result = false;
	int input_1 = 0;
	srand(time(0));
	int random_locationr;
	int random_locationc;
	random_locationr =( rand() % 4)+1;
	random_locationc = (rand() % 4)+1;
	int moves = 0;
	while (result == false && input_1 != 'q')
	{
		system("cls");
		cout << "                                     Welcome to 1024 Game" << endl;
		
		cout << "             INSTRUCTIONS" << endl;
		cout << "Follow the instruction to play the game " << endl;
		cout << "Merge the tiles to create 1024 tile to win the game" << endl;
		cout << "Enter U for up" << endl;
		cout << "Enter D for down" << endl;
		cout << "Enter L for left" << endl;
		cout << "Enter R for right" << endl;
		cout << "you can press the arrow keys for functions as well" << endl;
		cout << "Enter q to quit" << endl << endl << endl << endl <<"moves = "<<moves << "          score = " << score << endl;
		print_game(array);
		
		cout <<endl<<endl<< "Enter move" << endl;
		//using getch so that the program runs on its on after a input and we donot have to press enter after every move
		input_1 = _getch();
		//getting characterrs input and adding functions to run when they are pressed
		if (input_1 == 'u') {
			moves++;
			up(array);
			score += 10;
		}
		else if (input_1 == 'd') {
			moves++;
			down(array);
			score += 10;
		}
		else if (input_1 == 'l') {
			moves++;
			left(array);
			score += 10;
		}
		else if (input_1 == 'r') {
			moves++;
			right(array);
			score += 10;
		}
		else if (input_1 == 'q')
		{
			cout << "                      You quit the game Game ended" << endl;
			break;
		}
		//adding the arrow keys to work out the directions
		else if (input_1 == KEY_UP) {
			moves++;
			score += 10;
			up(array);
		}
		else if (input_1 == KEY_DOWN) {
			moves++;
			score += 10;
			down(array);
		}
		else if (input_1 == KEY_LEFT) {
			moves++;
			score += 10;
			left(array);
		}
		else if (input_1 == KEY_RIGHT) {
			moves++;
			score += 10;
			right(array);
		}
		//continue statement is used so that the game doesnt work for an invalid input and loop starts again until a valid input is entered
		else
			continue;
		//the win or lose check after every move

		if (check_lose(array) == true)
		{
			cout << "Lost." << endl;
			print_game(array);
			break;
		}

		if (check_win(array) == true)
		{
			cout << "win." << endl;
			print_game(array);
			break;
		}

		//generating a random number at random location to start the game using srand function
		//for random number
		int random_num = rand() % 2 + 1;

		//this check is applied so that a new tile is only generated when there is 0 tile available 
		bool check = true;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (array[i][j] == 0)
				{
					check = false;
					break;
				}
			}
		}
		if (check == false)
		{
			input_game(array, random_locationr, random_locationc, random_num);
		}
	}
	system("pause");
	return 0;
}