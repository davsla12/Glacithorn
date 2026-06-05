//file with player attacks
#include "./sprites.h"
#include "menu.h"
#include "./Log.h"
#include "stats.h"
#include <string>

int attack(Hrac& player){
  std::vector<menu_data_t> menu = {
    {"Utok",},
    {"Mana",}
  };
  if(player.name == "Mag")menu.push_back({"Special",});
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
    if(player.MANA_current < 5)Log("Nemas dost many");
    else{
      player.MANA_current -= 3;
      return Stats_roundGet()/(player.HP_current/2);
    }

  }
  return 0;
}
