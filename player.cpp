//file with player attacks
#include "./sprites.h"

int damage_basic(Hrac hrac,int damage){
  hrac.HP_current -= damage;
  return damage;
}
