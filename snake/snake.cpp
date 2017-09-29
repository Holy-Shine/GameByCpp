/*a simple snake game from YouTube*/
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <queue>
using namespace std;
bool gameOver;
const int width = 20;
const int height = 20;
int x, y;
int fruitX, fruitY;
int score;
int tailX[100], tailY[100];
int nTail;
int sleepTime = 100; //ms
enum eDirection {STOP=0,LEFT,RIGHT,UP,DOWN};

eDirection dir;
void Setup() {
	dir = STOP;
	gameOver = false;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
	nTail = 0;
}

// Draw map per sleepTime
void Draw() {
	system("cls");
	for (int i = 0; i < width + 2; ++i)
		cout << "#";
	cout << endl;
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width+2 ; ++j) {
			if (j == 0 || j == width + 1)
				cout << "#";
			else if (j == x&&i == y)
				cout << "0";
			else if (j == fruitX&&i == fruitY)
				cout << "F";
			else {
				bool print = false;
				for(int k=0;k<nTail;++k)
					if (j == tailX[k] && i == tailY[k]) {
						print = true;
						cout << "o";
					}
				if(!print)
					cout << " ";
			}

		}
		cout << endl;
	}
	for (int i = 0; i < width + 2; ++i)
		cout << "#";
	cout << endl;
	cout << "Score:" << score << endl;
}

// solve keyboard input message. "conio.h" is not program blocked
void Input() {
	if (_kbhit()) {
		switch (_getch())
		{
		case 'a':dir = LEFT; break;
		case 'w':dir = UP; break;
		case 'd':dir = RIGHT; break;
		case 's':dir = DOWN; break;
		case 'x':gameOver = true; break;

		}
	}
}

// judge game per sleepTime.
void Logic() {
	for (int i = 0; i < nTail; ++i) {
		if (x == tailX[i] && y == tailY[i])
		{
			gameOver = true;
		}
	}
	int preX = tailX[0];
	int preY = tailY[0];
	int pre2X, pre2Y;
	tailX[0] = x;
	tailY[0] = y;

	// eat fruit and push this point into head of queue
	for (int i = 1; i < nTail; ++i) {
		pre2X = tailX[i];
		pre2Y = tailY[i];
		tailX[i] = preX;
		tailY[i] = preY;
		preX = pre2X;
		preY = pre2Y;
	}
	switch (dir)
	{
	case LEFT:x--; break;
	case RIGHT:x++; break;
	case UP:y--; break;
	case DOWN:y++; break;
	}
	if (x <= 0 || x > width || y < 0 || y >= height)
		gameOver = true;
	if (x == fruitX&&y == fruitY) {
		fruitX = rand() % width;
		fruitY = rand() % height;
		score += 10;
		nTail++;
	}
}
int main() {
	Setup();
	while (!gameOver) {
		Draw();
		Input();
		Logic();
		Sleep(sleepTime);
	}
}