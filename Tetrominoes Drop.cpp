// Tetrominoes Drop.cpp : Defines the entry point for the console application.
// Following a tutorial from javidx9's youtube video: youtube.com/watch?v=8OK8_tHeCIA
//
#include "stdafx.h"
using namespace std;


wstring tetromino[7];
int nFieldWidth = 12;
int nFieldHeight = 18;
// Allocated dynamically all of map information stored in one array
unsigned char *pField = nullptr;

int nScreenWidth = 120;		// Console Screen Size X (columns)
int nScreenHeight = 30;		// Console Screen Size Y (rows) 

/*
	Rotation function that takes an indices values and using mathematics to determine
	rotations that find new indice values
	+-----------+		+-----------+
	| 0| 1| 2| 3|		|12| 8| 4| 0|
	| 4| 5| 6| 7|	==>	|13| 9| 5| 1|
	| 8| 9|10|11|	90	|14|10| 6| 2|
	|12|13|14|15|	rot	|15|11| 7| 3|
	+-----------+		+-----------+
*/
int Rotate(int px, int py, int r) {
	switch (r % 4) {
		case 0: return py * 4 + px;			// 0 degrees
		case 1: return 12 + py - (px * 4);	// 90 degrees
		case 2: return 15 - (py * 4) - px;	// 180 degrees
		case 3: return 3 - py + (px * 4);	// 270 degrees
	}
	return 0; // it should never return here
}

int main() {
	// Assets
	tetromino[0].append(L"..X.");
	tetromino[0].append(L"..X.");
	tetromino[0].append(L"..X.");
	tetromino[0].append(L"..X.");

	tetromino[1].append(L"..X.");
	tetromino[1].append(L".XX.");
	tetromino[1].append(L".X..");
	tetromino[1].append(L"....");

	tetromino[2].append(L".X..");
	tetromino[2].append(L".XX.");
	tetromino[2].append(L"..X.");
	tetromino[2].append(L"....");

	tetromino[3].append(L"....");
	tetromino[3].append(L".XX.");
	tetromino[3].append(L".XX.");
	tetromino[3].append(L"....");

	tetromino[4].append(L"..X.");
	tetromino[4].append(L".XX.");
	tetromino[4].append(L"..X.");
	tetromino[4].append(L"....");

	tetromino[5].append(L"....");
	tetromino[5].append(L".XX.");
	tetromino[5].append(L"..X.");
	tetromino[5].append(L"..X.");

	tetromino[6].append(L"....");
	tetromino[6].append(L".XX.");
	tetromino[6].append(L".X..");
	tetromino[6].append(L".X..");

	// Initialize playing field array
	// Create play field array
	pField = new unsigned char[nFieldWidth * nFieldHeight];
	for (int x = 0; x < nFieldWidth; x++) // Board Boundary
		for (int y = 0; y < nFieldHeight; y++)
			pField[y * nFieldWidth + x] = (x == 0 || x == nFieldWidth - 1 || y == nFieldHeight - 1) ? 9 : 0; // Board is set to value 9 all else is 0 to represent empy space

	wchar_t *screen = new wchar_t[nScreenWidth * nScreenHeight];
	for (int i = 0; i < nScreenWidth * nScreenHeight; i++)
		screen[i] = L' ';
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0;

	bool bGameOver = false;

	while (!bGameOver) {
		// Draw Field
		for (int x = 0; x < nFieldWidth; x++)
			for (int y = 0; y < nFieldHeight; y++)
				screen[(y + 2) * nScreenWidth + (x + 2)] = L" ABCDEFG=#"[pField[y * nFieldWidth + x]];
	
		// Display Frame
		WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0, 0 }, &dwBytesWritten);
	}

	// ===================================

	// ===================================

	// ===================================

	// ===================================

	return 0;
}