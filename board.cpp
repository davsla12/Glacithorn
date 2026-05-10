#include "./board.h"
#include "./Log.h"

int round = 0;
bool playerisonhalfround = true;

bool Boj(Hrac &player,Enemy nepritel){
  do{
    int dmg = player.attack(player);
    nepritel.HP_current -= dmg;

    round++;
  }while(player.HP_current > 0 && nepritel.HP_current > 0);
  if(player.HP_current > 0){
    Log("Nepritel zneskodnen na %d tahu",round);
    return true;
  }
  return false;
}
