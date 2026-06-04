#include "sprites.h"
#include "Random.h"
#include "stats.h"
#include "Log.h"

int Attack0(Enemy& nepritel){
  return 1;
}

int Attack1(Enemy& nepritel){
  return Stats_roundGet()/5+1;
}

float Xp0(Enemy self){
  return (float)randomInt(1,7)/10;
}

float Xp1(Enemy self){
  return (float)self.HP_max/15;
}

int Money0(){
return 1;
}

int Money1(){
return randomInt(1,2);
}

Enemy GetEnemy(int jaka){
  Enemy retval;
  switch(jaka){
    case 0:
      retval.attack = Attack0;
      retval.HP_max = randomInt(20,30);
      retval.name = "Mys";
      retval.xp_drop = Xp0;
      retval.money_drop = Money0;
      break;
    case 1:
      retval.attack = Attack1;
      retval.HP_max = randomInt(40,60);
      retval.name = "Skret";
      retval.xp_drop = Xp1;
      retval.money_drop = Money1;

  }
  retval.HP_current = retval.HP_max;
  return retval;
}
