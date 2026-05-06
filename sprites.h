#ifndef SPRITES_H
#define SPRITES_H

#include <string>

struct Hrac{
  std::string name;
  int HP_max;
  int HP_current;
  int MANA_max;
  int MANA_current;
  int money = 0;
  float level = 0;
  float experience = 0;
  int (*damage)(Hrac hrac,int damage);
};

struct Enemy{
  std::string name;
  int HP_max;
  int HP_current;
  int MANA_max;
  int MANA_current;
  float level = 0;
  int (*damage)(Enemy boss,int damage);
  int (*money_drop)(Enemy boss);
  float (*xp_drop)(Enemy boss);
};

#endif
