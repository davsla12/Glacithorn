#include "../MF/screen.h"
#include "../MF/sprites.h"
#include "../MF/Menu.h"

Scane SHlavni;

Menu* menu_current;
Menu intro;

bool running = true;

bool Run(){
    return running;
}

void SHlavni_input(int key){
    if(key == 'q')running = false;
    else menu_input(menu_current,key);
    return;
}

void SHlavni_render(){
    menu_render(*menu_current,SHlavni);
}

int SHlavni_main(){
    if(menu_current->selected&&menu_current->options[menu_current->pos] == "Quit")
        exit(0);
    return 0;
}

int SHlavni_init(){
    CreateWin(&SHlavni,20,40,0,0);
    SHlavni.input = SHlavni_input;
    SHlavni.render = SHlavni_render;
    SHlavni.main = SHlavni_main;

    menu_create(&intro);
    intro.y = 2;
    intro.x = 1;

    intro.options = {"Ahoj","test","Quit"};
    menu_current = &intro;

    AddScane(&SHlavni);
    return 0;
}
