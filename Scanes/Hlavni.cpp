#include <MF/screen.h>
Scane SHlavni;
bool running = true;

bool Run(){
    return running;
}

SHlavni_input(int key){
    if(key == 'q')running = false;
}

int SHlavni_init(){
    CreateWin(&SHlavni,20,40,0,0);
    AddScane(&SHlavni);
    return 0;
}
