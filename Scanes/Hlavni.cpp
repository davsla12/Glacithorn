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
    else if(key == KEY_DOWN) menu_current->pos++;
    return;
}

void SHlavni_render(){
    menu_render(*menu_current,SHlavni);
}

int SHlavni_init(){
    CreateWin(&SHlavni,20,40,0,0);
    SHlavni.input = SHlavni_input;

    menu_create(&intro);
    intro.options = {"Ahoj","test"};
    menu_current = &intro;

    AddScane(&SHlavni);
    return 0;
}
