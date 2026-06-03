#include "stats.h"
#include "sprites.h"
#include "Log.h"

#include <vector>

static WINDOW* window;
static int IDs = 0;
static int tah = 0;

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

void Stats_update(){
  wclear(window);
  mvwprintw(window,0,0,"Tah: %d",tah);
  mvwprintw(window,1,0,"Zlaťáky: %d",player->money);
  mvwprintw(window,2,0,"Level: %f",player->level);
  for(size_t i = 0;i<nepritele.size();i++){
    mvwprintw(window, i+4, 0, "[%s]%d",nepritele[i]->name.c_str(), nepritele[i]->HP_current);
    progreshow(i+4,snprintf(NULL,0,"[%s]%d",nepritele[i]->name.c_str(), nepritele[i]->HP_current),nepritele[i]->HP_current,nepritele[i]->HP_max);
  }
  wrefresh(window);
}
