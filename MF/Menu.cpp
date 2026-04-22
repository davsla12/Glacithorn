#include <ncurses.h>

#include "screen.h"
#include "Menu.h"
static int IDs = 0;

void menu_render(Menu menu,Scane scane){
    for(int i = 0;i < menu.options.size();i++){
        if(i==menu.pos)wattron(scane.window,A_REVERSE);
        mvwprintw(scane.window,menu.y,menu.x,"%s",menu.options[i].c_str());
        if(i==menu.pos)wattroff(scane.window,A_REVERSE);
    }
}

void menu_create(Menu* menu){
    menu->ID = IDs++;
}
