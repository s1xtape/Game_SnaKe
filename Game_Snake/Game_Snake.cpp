#include "Game_Snake.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

void Game_Snake::Snake()
{
	Menu();
}

void Game_Snake::Setup()//Set the initial value
{
	nTail = 0;
	gameOver = false;
	dir = STOP;
	x = width / 2 - 1;
	y = height / 2 - 1;
	apple_x = 1 + rand() % ((width - 1) - 1);
	apple_y = 1 + rand() % ((height - 1) - 1);
	score = 0;
	field = new char* [height];//Creating an array for the field
	for (int i = 0; i < height; i++) {
		field[i] = new char[width];
	}
}

void Game_Snake::doDrawing()//Drawing objects on the screen
{
	system("cls");
	for (int i = 0; i < height; i++) {//Creating a field for the game
		for (int j = 0; j < width; j++) {
			if (i == 0 || j == 0 || j == width - 1 || i == height - 1) {
				field[i][j] = '#';
			}
			else {
				field[i][j] = ' ';
			}
		}
	}

	field[y][x] = 'O';//Adding a snake head to the field
	field[apple_y][apple_x] = 'A';//Adding fruit to the field
	if (nTail >= 1) {
		for (int k = 1; k <= nTail; k++)//Adding a snake body to the field
		{
			field[tailY[k]][tailX[k]] = 'o';
		}
	}

	for (int i = 0; i < height; i++) {//Rendering the entire field
		cout << endl;
		for (int j = 0; j < width; j++)
			cout << field[i][j];
	}

	cout << endl;
	cout << "Score: " << score << endl;
}
void Game_Snake::Input()//Tracks button clicks
{
	if (_kbhit()) {
		switch (_getch())
		{
		case 'a':
			if (dir != 2)
				dir = LEFT;
			break;
		case 'd':
			if (dir != 1)
				dir = RIGHT;
			break;
		case 'w':
			if (dir != 4)
				dir = UP;
			break;
		case 's':
			if (dir != 3)
				dir = DOWN;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}
}
void Game_Snake::Logic()//Logic game
{
	int prevX = x;
	int prevY = y;//Head coordinates
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	switch (dir)//Snake movement
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	}
	if (x >= width - 1 || x <= 0 || y >= height - 1 || y <= 0)//The end of the game when the snake hits the wall
		gameOver = true;
	if (x == apple_x && y == apple_y)//Apple picking logic
	{
		bool flag;
		score += 10;
		do {
			flag = true;
			apple_x = 1 + rand() % ((width - 1) - 1);
			apple_y = 1 + rand() % ((height - 1) - 1);
			for (int i = 0; i < nTail; i++) {
				if (tailX[i] == apple_x && tailY[i] == apple_y) flag = false;
			}
		} while (!flag);
		nTail++;
	}
	for (int i = 1; i <= nTail; i++)//Movement of the body behind the head
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	if (nTail >= 1) {
		for (int i = 1; i <= nTail; i++)//End of the game when the snake hits the tail
		{
			if (tailX[i] == x && tailY[i] == y)
			{
				gameOver = true;
			}
		}
	}
}
void Game_Snake::Menu() {//Game menu
	int current(0);
	cout << endl << "-> start";
	cout << endl << "   exit";
	while (current != 3) {
		switch (_getch())
		{
		case 72:
			system("cls");
			cout << endl << "-> start";
			cout << endl << "   exit";
			current = 0;
			break;
		case 80:
			system("cls");
			cout << endl << "   start";
			cout << endl << "-> exit";
			current = 1;
			break;
		case 13:
			if (current == 0) {
				Setup();
				while (!gameOver)
				{

					doDrawing();
					Sleep(300);
					Input();
					Logic();
				}
				system("cls");
				cout << "You lose, with score = " << score;
				cout << endl << "Press any button to return menu";
				_getch();
				system("cls");
				cout << endl << "-> start";
				cout << endl << "   exit";
				current = 0;
			}
			else {
				current = 3;
			}
			break;
		}

	}
}
