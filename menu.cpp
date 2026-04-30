#include <ncurses.h>
#include <vector>
#include <string>

#include "menu.h"

int menu_quick(WINDOW* window,int y,int x,std::vector<menu_data_t> options){
  bool selected = false;
  int pos = 0;
  size_t offsetX = 0;
  for(int i = 0;i<options.size();i++){
    offsetX = std::max(options[i].key.size(),offsetX);
  }
  while(!selected){
    wclear(window);
    wrefresh(window);
    for(int i = 0;i < options.size();i++){
      if(i==pos)wattron(window,A_REVERSE);
      mvwprintw(window,y+i,x,"%s",options[i].key.c_str());
      if(i==pos)wattroff(window,A_REVERSE);
      if(i==pos && options[i].values.size()){
        mvwprintw(window,y,x + offsetX + 2,"%s",options[i].values[0].c_str());
      }
    }
    int key = getch();

    if(key == KEY_UP && pos)pos--;
    else if(key == KEY_DOWN && pos+1 < options.size())pos++;
    else if(key == '\n') selected = true;
  }
  return pos;
}
