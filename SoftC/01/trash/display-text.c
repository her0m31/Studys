/* display-text.c */
#include <stdio.h>
#include <*****.h>

#define STRINGS "Hello, world."

int main()
{
  char *str;
  int  x = 10, y = 10;

  initscr();
  str = STRINGS;

  while( *str != '\0' ){
    mvaddch(y, x++, *str++);
    sleep(1);
    refresh();
  }
  endwin();

  return 0;
}
