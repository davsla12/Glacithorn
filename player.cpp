//file with player attacks
#include "./sprites.h"
#include "menu.h"
#include "./Log.h"
#include <string>

int attack(Hrac& player){
  int volba = menu_quick(2,2,{
  {"Utok",},
  {"Mana",{"Mana: " + std::to_string(player.MANA_current)}},
  {"Heal",{"HP: " + std::to_string(player.HP_current)}}
  });


  switch(volba){
  case 0:
    if(player.MANA_current < 2)Log("Nemas dost many");
    else{player.MANA_current -= 2;
    return 2;}
    break;
  case 1:
    player.MANA_current += 3;
    return 0;
  case 2:
    if(player.MANA_current < 1)Log("Nemas dost many");
    else{
      player.MANA_current -=1;
      player.HP_current += 2;
    }

  }
  return 0;
}
