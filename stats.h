#ifndef STATS_H
#define STATS_H

#include "sprites.h"

#include <ncurses.h>

int Stats_init(WINDOW* window);
void Stats_update();
int Stats_roundGet();//returns round
void Stats_roundAdd();//adds 1
void Stats_roundSet();//resets to 0

int Stats_addEnemy(Enemy* nepritel);
void Stats_clrEnemy();
bool Stats_remEnemy(int id);

void Stats_setPlayer(Hrac* hrac);

#endif
