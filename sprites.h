#ifndef SPRITES_H
#define SPRITES_H

struct Hrac{

std::string name;
int HP_max;
int HP_current;
int MANA_max;
int MANA_current;
int money;
float level;
float experience;
int (*attack)(Boss* boss);
int (*damage)(int dmg);
};

#endif
