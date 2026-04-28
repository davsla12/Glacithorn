#include "screen.h"
#include "menu.h"

#include <iostream>

int volba = -1;

int main(){
  screen_init();

  do{
    volba = menu_quick(stdscr,2,2,{{"Idk",{"Quit"}},{"treti"},{"Idk2"}});
  }while(volba != 0);
  screen_delete();
  std::cout << volba << std::endl;
}
