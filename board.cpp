#include "./board.h"
#include "./Log.h"
#include "stats.h"
#include "menu.h"

#include <vector>

bool playerisonhalfround = true;

bool Boj(Hrac &player,std::vector<Enemy> nepritele){
  for(int i = 0;i<nepritele.size();i++)Stats_addEnemy(&nepritele[i]);
  //int nepritelid = Stats_addEnemy(&nepritel);
  Stats_roundSet();
  Stats_update();
  for(int i = 0;i<nepritele.size();i++)Log("vitej %s ted se utkas proti %s",player.name.c_str(),nepritele[i].name.c_str());
  do{
    Stats_update();
    int volba = 0;
    if(nepritele.size()>1){
      std::vector<menu_data_t> menu;
      for(int i = 0;i < nepritele.size();i++){
        menu.push_back({nepritele[i].name,{std::to_string(nepritele[i].HP_current)}});
      }
      volba = menu_quick(5,5,menu);
    }
    int dmg = player.attack(player);
    nepritele[volba].HP_current -= dmg;

    for(int i = 0;i<nepritele.size();i++){
      if(nepritele[i].HP_current<=0){
        Log("Nepritel %s zneskodnen na %d tahu",nepritele[i].name.c_str(),Stats_roundGet());
        int money = nepritele[i].money_drop();
        player.money += money;
        float xp = nepritele[i].xp_drop(nepritele[i]);
        Log("Za zabiti %s dostavas %fxp",nepritele[i].name.c_str(),xp);//TODO check next level
        player.level += xp;
        Log("%s dropnul %d penez",nepritele[i].name.c_str(),money);
        Stats_clrEnemy();
        nepritele.erase(nepritele.begin()+i);
        for(int i = 0;i<nepritele.size();i++)Stats_addEnemy(&nepritele[i]);
      }
    }

    if(nepritele.size() > 0){
      dmg = 0;
      for(int i = 0;i < nepritele.size();i++)dmg += nepritele[i].attack(nepritele[i]);
      player.HP_current -= dmg;
      Log("Nepritele uderili %dhp",dmg);
    }

    Stats_roundAdd();
  }while(player.HP_current >= 0 && nepritele.size() > 0);
  //Stats_remEnemy(nepritelid);
  Stats_update();
  if(player.HP_current>0)return true;
  return false;
}
