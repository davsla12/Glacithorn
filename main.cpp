#include <iostream>
#include "MF/screen.h"

#include "Scanes/Scanes.h"

using namespace std;

int main(){
    screen_init();
    SHlavni_init();
    atexit(screen_delete);
    while(Run()){
        SInput();
        screen_update();
        SMain();
    }
    return 0;
}
