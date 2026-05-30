#ifndef STATS_H
#define STATS_H

#include "sprites.h"

#include <ncurses.h>

int Stats_init(WINDOW* window);
void Stats_update();
int Stats_roundGet();
void Stats_roundAdd();

void Stats_addEnemy(Enemy* nepritel);

#endif
