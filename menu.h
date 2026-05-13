#ifndef MENU_H
#define MENU_H

#include <ncurses.h>

#include <string>
#include <vector>

struct menu_data_t {
    std::string key;
    std::vector<std::string> values;
};

int menu_quick(int y,int x,std::vector<menu_data_t> options);
void menu_init(WINDOW* okno);

#endif
