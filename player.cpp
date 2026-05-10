//file with player attacks
#include "./sprites.h"

int attack(Hrac& player){
  if(player.MANA_current > 2){
    player.MANA_current -= 2;
    return 10;
    }
  return 0;
}
