#include "village.h"
#include "Log.h"
#include "menu.h"
#include "stats.h"

void Village(Hrac& player){
  Log("");
  Log("vítej ve vesnici %s",player.name.c_str());
  Log("Za tvuj level dostanes od nas %d zlotych",(int)player.level);
  player.money += player.level;
  do{
    Stats_update();
    if(player.MANA_current+10<=player.MANA_max)player.MANA_current+=10;
    int volba = menu_quick(5,5,{
      {"Zivoty +10",{"Heal","Za jeden zloty"}},
      {"Zivoty +20",{"Prida max zivoty","Za dva zloty"}},
      {"Odejit z vesnice"}
    });
    switch(volba){
      case 0:
        if(player.HP_current+player.HP_max/5>player.HP_max){
          Log("Mas dost zivotu");
          break;}
        if(player.money >= 1){
          Log("Chybi ti %d zlotych aby jsi si toto mohl doprat",player.money-1);
          break;
        }
        player.HP_current += player.HP_max/5;
        player.money -= 1;
        Log("Nyni mas %dHP",player.HP_current);
        break;
      case 1:
        if(player.money >= 2){
          Log("Chybi ti %d zlotych aby jsi si toto mohl doprat",player.money-2);
          break;
        }
        player.HP_max += 20;
        player.money -= 2;
        Log("Nyni mas %dHP_max",player.HP_max);
        Log("doporucuju je dobrat at ti nechybi");
        break;
      case 2:
        goto exit;
    }
  }while(player.money);
  exit:
}
