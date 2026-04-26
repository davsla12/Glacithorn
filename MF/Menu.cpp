#include <ncurses.h>

#include "screen.h"
#include "Menu.h"
static int IDs = 0;

void menu_render(Menu menu,Scane scane){
    for(int i = 0;i < menu.options.size();i++){
        if(i==menu.pos)wattron(scane.window,A_REVERSE);
        mvwprintw(scane.window,menu.y+i,menu.x,"%s",menu.options[i].c_str());
        if(i==menu.pos)wattroff(scane.window,A_REVERSE);
    }
}

void menu_input(Menu* menu,int key){
    if(!menu || menu->selected)return;

    if(key == KEY_UP && menu->pos)menu->pos--;
    else if(key == KEY_DOWN && menu->pos+1 < menu->options.size())menu->pos++;
    else if(key == '\n') menu->selected = true;
}

void menu_create(Menu* menu){
    menu->ID = IDs++;
}
