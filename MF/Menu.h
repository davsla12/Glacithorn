#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>

struct Menu{
int ID = -1;
std::vector<std::string> options;
int pos = 0;
bool selected = false;
int y;
int x;
};

void menu_create(Menu*);
void menu_render(Menu menu,Scane scane);
void menu_input(Menu* menu,int key);
#endif
