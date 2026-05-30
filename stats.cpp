#include "stats.h"
#include "sprites.h"
#include "Log.h"

#include <vector>

static WINDOW* window;

std::vector<Enemy*> nepritele;
static Hrac player;

int Stats_init(WINDOW* okno){
window = okno;
return 0;
}

void Stats_setPlayer(Hrac hr){

}

void Stats_addEnemy(Enemy* nepritel){
nepritele.push_back(nepritel);
}

void Stats_update(){
  wclear(window);
  for(size_t i = 0;i<nepritele.size();i++){
    int maxx = getmaxx(window);
    for(int ii = 0;ii<maxx-4;ii++){
      mvwprintw(window, i, 0, "%.2f%%", ((float)nepritele[i]->HP_current / nepritele[i]->HP_max) * 100);
      wattron(window,A_REVERSE);
      mvwprintw(window,i,ii+4," ");
      wattroff(window,A_REVERSE);
    }
  }
  wrefresh(window);
}
