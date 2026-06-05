#include "./board.h"
#include "./Log.h"
#include "stats.h"
#include "menu.h"

#include <vector>

bool playerisonhalfround = true;

bool Boj(Hrac &player,std::vector<Enemy> nepritele,bool bossfight){
  int dmg = 0;
  for(int i = 0;i<nepritele.size();i++)Stats_addEnemy(&nepritele[i]);
  //int nepritelid = Stats_addEnemy(&nepritel);
  Stats_roundSet();
  Stats_update();
  for(int i = 0;i<nepritele.size();i++)Log("vitej %s ted se utkas proti %s",player.name.c_str(),nepritele[i].name.c_str());
  do{
    if(bossfight)goto attacknepritel;
    attackplayer:

    {int volba = 0;
    if(nepritele.size()>1){
      std::vector<menu_data_t> menu;
      for(int i = 0;i < nepritele.size();i++){
        menu.push_back({nepritele[i].name,{std::to_string(nepritele[i].HP_current)}});
      }
      volba = menu_quick(5,5,menu);
    }
    dmg = player.attack(player);
    nepritele[volba].HP_current -= dmg;}
    if(bossfight){
      Stats_roundAdd();
      goto attacknepritel;
    }

    for(int i = 0;i<nepritele.size();i++){
      if(nepritele[i].HP_current<=0){
        Log("Nepritel %s zneskodnen na %d tahu",nepritele[i].name.c_str(),Stats_roundGet());
        int money = nepritele[i].money_drop();
        player.money += money;
        float xp = nepritele[i].xp_drop(nepritele[i]);
        Log("Za zabiti %s dostavas %.2fxp",nepritele[i].name.c_str(),xp);
        player.level += xp;
        Log("%s dropnul %d penez",nepritele[i].name.c_str(),money);
        Stats_clrEnemy();
        nepritele.erase(nepritele.begin()+i);
        for(int i = 0;i<nepritele.size();i++)Stats_addEnemy(&nepritele[i]);
      }
    }
    if(player.HP_current < 0 || nepritele.size() == 0)goto exit;

    attacknepritel:
    if(nepritele.size() > 0){
      dmg = 0;
      for(int i = 0;i < nepritele.size();i++)dmg += nepritele[i].attack(nepritele[i]);
      player.HP_current -= dmg;
      Log("Nepritele uderili %dhp",dmg);
      Stats_update();
    }if(bossfight)goto attackplayer;

    if(!bossfight){
      Stats_roundAdd();
      Stats_update();
    }
  }while(player.HP_current > 0 && nepritele.size() > 0);
  exit:
  Stats_update();
  if(player.HP_current>0)return true;
  return false;
}
