#include "village.h"
#include "Log.h"
#include "menu.h"

void Village(Hrac& player){
  Log("vítej ve vesnici %s",player.name.c_str());
  int volba = menu_quick(5,5,{
    {"Zivoty +10",{"Základní heal","Zdarma"}},
    {"Zivoty +50",{"Dezinfekce","Za jeden zlatý"}}
  });
  switch(volba){
    case 0:
    break;
  }
}
