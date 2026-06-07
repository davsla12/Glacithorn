//file with player attacks
#include "./sprites.h"
#include "menu.h"
#include "./Log.h"
#include "stats.h"
#include <string>

int attack(Hrac& player){
  std::vector<menu_data_t> menu = {
    {"Utok",{"-2 MANY"}},
    {"Mana",{"+3 MANY"}}
  };
  if(player.name == "Bojovnik")menu.push_back({"Special",{"-3 MANY"}});
  if(player.name == "Paladin")menu.push_back({"Special",{"-10 MANY","Nesmi ti chybet vic jak 20 MANY"}});
  if(player.name == "Mag")menu.push_back({"Special",{"-5 MANY"}});
  //menu.push_back({"Special",});
  int volba = menu_quick(2,2,menu);


  switch(volba){
  case 0:
    if(player.MANA_current < 2)Log("Nemas dost many");
    else{
      player.MANA_current -= 2;
      return player.dmg*player.level;
    }
    break;
  case 1:
    if(player.MANA_max>=player.MANA_current+3)player.MANA_current += 3;
    else Log("Vzdyt mas dost many");
    return 0;
  case 2:
    if(player.name == "Bojovnik"){
      if(player.MANA_current < 3)Log("Nemas dost many");
      else{
          Stats_adSet(true);
          player.MANA_current -= 3;
          return player.level;
      }
    }

    else if(player.name == "Paladin"){
      if(player.MANA_current < player.MANA_max - 20)Log("Nemas dost many");
      else{
        Stats_adSet(false);
        player.MANA_current -= 10;
        return player.HP_max - player.HP_current;
      }
    }

    else if(player.name == "Mag"){
      if(player.MANA_current < 5)Log("Nemas dost many");
      else{
        Stats_adSet(true);
        player.MANA_current -= 5;
        if(!(player.HP_current/3 > 0))return 0;
        return Stats_roundGet()/(player.HP_current/3)+player.level;
      }
    }
  }
  return 0;
}
