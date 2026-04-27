#ifndef MENU_H
#define MENU_H

#include <ncurses.h>

#include <string>
#include <vector>

int menu_quick(WINDOW* window,int y,int x,std::vector<std::string> options);

#endif
