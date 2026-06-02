#include "screen.h"
#include "menu.h"
#include "./sprites.h"
#include "./Log.h"
#include "./player.h"
#include "nepritel.h"
#include "./board.h"
#include "village.h"
#include "./Random.h"
#include "stats.h"

#include <iostream>

int volba = -1;
bool potvrzeni = false;
int screen_h;
int screen_w;

Hrac player;
Enemy nepriteltmp;

int main(){
  screen_init();
  init_random();
  getmaxyx(stdscr,screen_h,screen_w);
  WINDOW* menu = subwin(stdscr,10,screen_w/2,screen_h-10,0);
  WINDOW* log = subwin(stdscr,screen_h-10,screen_w,0,0);
  WINDOW* stats = subwin(stdscr,10,screen_w/2,screen_h-10,screen_w/2);
  SLog_init(log);
  menu_init(menu);
  Stats_init(stats);
  Stats_setPlayer(&player);
  Stats_update();

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

  nepriteltmp = GetEnemy(0);
  if(!Boj(player,nepriteltmp)){
    Log("Zemrel jsi");
    goto konec;
  }
  if(!Boj(player,nepriteltmp)){
    Log("Zemrel jsi");
    goto konec;
  }

  Village(player);

  nepriteltmp = GetEnemy(1);
  if(!Boj(player,nepriteltmp)){
    Log("Zemrel jsi");
    goto konec;
  }

  konec:
  menu_quick(2,2,{
      {"Konec"}
    });
  screen_delete();
  std::cout << "tvoje mana " << player.MANA_current << std::endl;
  std::cout << "tvoje money " << player.money << std::endl;
}
