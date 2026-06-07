#include "stats.h"
#include "sprites.h"
#include "Log.h"

#include <vector>

static WINDOW* window;
static int IDs = 0;
static int tah = 0;

bool AreaDamage = false;

std::vector<Enemy*> nepritele;
static Hrac* player;

void progreshow(int y,int x,int value,int maxvalue){
  int prog = 15*value/maxvalue;
  mvwprintw(window,y,x,"[");
  x++;
  for(int i = 0;i<prog;i++){
    wattron(window,A_REVERSE);
    mvwprintw(window,y,x+i," ");
    wattroff(window,A_REVERSE);
  }
  mvwprintw(window,y,x+15,"]");
}

int Stats_init(WINDOW* okno){
window = okno;
return 0;
}

int Stats_roundGet(){
return tah;
}

void Stats_roundAdd(){
tah++;
}

void Stats_roundSet(){
tah = 0;
}

int Stats_addEnemy(Enemy* nepritel){
nepritel->id = IDs++;
nepritele.push_back(nepritel);
return nepritel->id;
}

void Stats_clrEnemy(){
  nepritele.clear();
}

bool Stats_remEnemy(int id){
  for(int i = 0;i<nepritele.size();i++){
    if(id == nepritele[i]->id){
      nepritele.erase(nepritele.begin()+i);
      return true;
    }
  }
  return false;
}

void Stats_setPlayer(Hrac* hrac){
  player = hrac;
}

Hrac* Stats_getPlayer(){
  return player;
}

void Stats_update(){
  wclear(window);
  mvwprintw(window,0,0,"Tah: %d",tah);
  mvwprintw(window,1,0,"Zlaťáky: %d",player->money);
  mvwprintw(window,2,0,"Level: %.2f",player->level);

  mvwprintw(window, 3, 0, "[Tvoje HP]%d",player->HP_current);
  progreshow(3,snprintf(NULL,0,"[Tvoje HP]%d",player->HP_current),player->HP_current,player->HP_max);

  mvwprintw(window, 4, 0, "[Tvoje MANA]%d",player->MANA_current);
  progreshow(4,snprintf(NULL,0,"[Tvoje MANA]%d",player->MANA_current),player->MANA_current,player->MANA_max);

  for(size_t i = 0;i<nepritele.size();i++){
    mvwprintw(window, i+6, 0, "[%s]%d",nepritele[i]->name.c_str(), nepritele[i]->HP_current);
    progreshow(i+6,snprintf(NULL,0,"[%s]%d",nepritele[i]->name.c_str(), nepritele[i]->HP_current),nepritele[i]->HP_current,nepritele[i]->HP_max);
  }
  wrefresh(window);
}

void Stats_adSet(bool value){
  AreaDamage = value;
  Log("adSet");
}
bool Stats_adGet(){
  return AreaDamage;
}
