#include <iostream>
#include <cstdio>
#include <string>
#include <ncurses.h>

int main(){
	int row, col, ch, counter;
initscr();
raw();
noecho();
getmaxyx(stdscr, row, col);
wborder(stdscr, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE, ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
mvprintw(1, col - 16, "Col %i Row %i", col, row);
mvprintw(2, col - 16, "Hangman inttest");
mvprintw(row - 2, 2, "[............]");
refresh();
move(row - 2, 2);
counter = 3;
while(counter < 15){
ch = getch();
mvaddch(row - 2, counter, ch);
counter++;
refresh();
}
move(row - 2, counter + 1);
getch();
endwin();
}
