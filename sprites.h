#ifndef SPRITES_H
#define SPRITES_H

struct Hrac{
  std::string name;
  int HP_max;
  int HP_current;
  int MANA_max;
  int MANA_current;
  int money = 0;
  float level = 0;
  float experience = 0;
  int (*damage)(int damage);
};

struct Boss{
  std::string name;
  int HP_max;
  int HP_current;
  int MANA_max;
  int MANA_current;
  float level = 0;
  int (*damage)(int damage);
  int (*money_drop)();
  float (*xp_drop)();
};

#endif
