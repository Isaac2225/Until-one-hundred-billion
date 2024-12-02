#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define BLACK	        0
#define BLUE	        1
#define GREEN	        2
#define CYAN	        3
#define RED	            4
#define MAGENTA	        5
#define BROWN	        6
#define LIGHTGRAY	    7
#define DARKGRAY	    8
#define LIGHTBLUE	    9
#define LIGHTGREEN	    10
#define LIGHTCYAN	    11
#define LIGHTRED	    12
#define LIGHTMAGENTA	13
#define YELLOW	        14
#define WHITE	        15


#define MIDDLE_X        30
#define MIDDLE_Y        10


void maximitzarFinestra()
{
    keybd_event(VK_MENU,0x38,0,0);
    keybd_event(VK_SPACE,0x39,0,0);
    keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
    keybd_event(VK_SPACE,0x39,KEYEVENTF_KEYUP,0);
    keybd_event(0x58,0x47,0,0);
    keybd_event(0x58,0x47,KEYEVENTF_KEYUP,0);
}

void SetColor(int ForgC, int BackC)
{
    WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
    return;
}

void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = FALSE;
	cursor.dwSize = sizeof(cursor);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &cursor);
}

void gotoxy(int x,int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
}

void textcolor (int color)
{
    static int __BACKGROUND;

    HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;


    GetConsoleScreenBufferInfo(h, &csbiInfo);

    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
                             color + (__BACKGROUND << 4));
}

void clrscr (){
    printf("\033[2J\033[0;0f");
}