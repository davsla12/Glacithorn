#include <ncurses.h>
#include <vector>
#include <string>

#include "menu.h"

static WINDOW* window;

int menu_quick(int y,int x,std::vector<menu_data_t> options){
  bool selected = false;
  int pos = 0;
  size_t offsetX = 0;
  for(int i = 0;i<options.size();i++){
    offsetX = std::max(options[i].key.size(),offsetX);
  }
  while(!selected){
    wclear(window);
    for(int i = 0;i < options.size();i++){
      if(i==pos)wattron(window,A_REVERSE);
      mvwprintw(window,y+i,x,"%s",options[i].key.c_str());
      if(i==pos)wattroff(window,A_REVERSE);
      if(i==pos && options[i].values.size()){
        for(size_t ii = 0;ii < options[i].values.size();ii++)
          mvwprintw(window,y+ii,x + offsetX + 2,"%s",options[i].values[ii].c_str());
      }
    wrefresh(window);
    }
    int key = getch();

    if(key == KEY_UP && pos)pos--;
    else if(key == KEY_DOWN && pos+1 < options.size())pos++;
    else if(key == '\n') selected = true;
  }
  return pos;
}

void menu_init(WINDOW* okno){
window = okno;
}
