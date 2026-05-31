#include "./board.h"
#include "./Log.h"
#include "stats.h"

bool playerisonhalfround = true;

bool Boj(Hrac &player,Enemy nepritel){
  int nepritelid = Stats_addEnemy(&nepritel);
  Stats_roundSet();
  Stats_update();
  Log("vitej %s ted se utkas proti %s",player.name.c_str(),nepritel.name.c_str());
  do{
    Stats_update();
    int dmg = player.attack(player);
    nepritel.HP_current -= dmg;
    if(nepritel.HP_current > 0){
      Log("Aktualni HP nepritele: %d",nepritel.HP_current);
      dmg = nepritel.attack(nepritel);
      player.HP_current -= dmg;
      Log("Nepritel uderil %dhp",dmg);
    }

    Stats_roundAdd();
  }while(player.HP_current >= 0 && nepritel.HP_current > 0);
  Stats_remEnemy(nepritelid);
  Stats_update();
  if(player.HP_current > 0){
    Log("Nepritel zneskodnen na %d tahu",Stats_roundGet());
    int money = nepritel.money_drop();
    player.money += money;
    Log("%s dropnul %d penez",nepritel.name.c_str(),money);
    return true;
  }
  return false;
}
