#include <stdlib.h>
#include<stdio.h>
#include<windows.h>
void gotoxy(int x, int y){

SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}


