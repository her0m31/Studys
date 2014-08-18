/* display-text.c */
#include <stdio.h>
#include <curses.h>

int main()
{
  char str[] = "Welcome! This is the address book management application!";
  int x = 10, y = 10;
  
  initscr();
  
  while(str != '\0') {
    mvaddch(y, x++, str++);
    sleep(1);
    refresh();
  }
  endwin();
  
  return 0;
}
