#include "./board.h"
#include "./Log.h"

int round = 0;
bool playerisonhalfround = true;

bool Boj(Hrac &player,Enemy nepritel){
  round = 0;
  Log("vitej %s ted se utkas proti %s",player.name.c_str(),nepritel.name.c_str());
  do{
    int dmg = player.attack(player);
    nepritel.HP_current -= dmg;
    if(nepritel.HP_current > 0){
      Log("Aktualni HP nepritele: %d",nepritel.HP_current);
      dmg = nepritel.attack(nepritel,round);
      player.HP_current -= dmg;
      Log("Nepritel uderil %dhp",dmg);
    }

    round++;
  }while(player.HP_current >= 0 && nepritel.HP_current > 0);
  if(player.HP_current > 0){
    Log("Nepritel zneskodnen na %d tahu",round);
    int money = nepritel.money_drop();
    player.money += money;
    Log("%s dropnul %d penez",nepritel.name.c_str(),money);
    return true;
  }
  return false;
}
