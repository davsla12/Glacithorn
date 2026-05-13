#include "screen.h"
#include "menu.h"
#include "./sprites.h"
#include "./Log.h"
#include "./player.h"
#include "./board.h"

#include <iostream>

int volba = -1;
bool potvrzeni = false;
int screen_h;
int screen_w;

Hrac player;
Enemy nepriteltmp;

int main(){
  screen_init();
  getmaxyx(stdscr,screen_h,screen_w);
  WINDOW* menu = subwin(stdscr,screen_h-10,screen_w,10,0);
  WINDOW* log = subwin(stdscr,10,screen_w,0,0);
  SLog_init(log);
  menu_init(menu);

  do{
    volba = menu_quick(2,2,{
      {"Bojovnik",{
        "HP: 50",
        "MANA: 25"}},

      {"Paladin",{
        "HP: 70",
        "MANA: 20"}},

      {"Mag",{
        "HP: 40",
        "MANA: 40"}}
    });

  switch(volba){

    case 0:
      player.name = "Bojovnik";
      player.HP_max = 50;
      player.MANA_max = 25;
      break;
    case 1:
      player.name = "Paladin";
      player.HP_max = 70;
      player.MANA_max = 20;
      break;
    case 2:
      player.name = "Mag";
      player.HP_max = 40;
      player.MANA_max = 40;

  }

  Log("Tvoje volba %s",player.name.c_str());

  potvrzeni = menu_quick(2,2,{
      {"Ano",{"Hura do bitvy"}},
      {"Ne",{"Co bude lepsi"}}
    });
  }while(potvrzeni);

  player.HP_current = player.HP_max;
  player.MANA_current = player.MANA_max;
  player.attack = attack;

  nepriteltmp.HP_current = 25;

  if(!Boj(player,nepriteltmp))Log("Zemrel jsi");

  menu_quick(2,2,{
      {"Konec"}
    });

  screen_delete();
  std::cout << volba << std::endl;
}
