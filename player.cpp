//file with player attacks
#include "./sprites.h"
#include "menu.h"
#include <string>

int attack(Hrac& player){
  int volba = menu_quick(2,2,{
  {"Utok"},
  {"Mana",{"Mana" + std::to_string(player.MANA_current)}}
  });


  switch(volba){
  case 0:
    return 2;

  }
  if(player.MANA_current > 2){
    player.MANA_current -= 2;
    return 1;
    }
  player.MANA_current++;
  return 0;
}
