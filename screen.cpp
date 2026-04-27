#include <ncurses.h>
#include <cstdlib>
#include "screen.h"

void screen_delete(){
  endwin();
}

int screen_init(){
  initscr();
  //atexit(screen_delete);
  noecho();
  curs_set(0);
  keypad(stdscr,TRUE);
  //nodelay(stdscr,TRUE);

  start_color();

  return 0;
}
