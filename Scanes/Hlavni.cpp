#include "../MF/screen.h"
#include "../MF/sprites.h"
#include "../MF/Menu.h"

Scane SHlavni;

bool running = true;

bool Run(){
    return running;
}

void SHlavni_input(int key){
    if(key == 'q')running = false;
}

int SHlavni_init(){
    CreateWin(&SHlavni,20,40,0,0);

    SHlavni.input = SHlavni_input;

    AddScane(&SHlavni);
    return 0;
}
