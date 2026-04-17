#include <iostream>
#include "MF/screen.h"

#include "Scanes/Scanes.h"

using namespace std;

int main(){
    screen_init();
    SHlavni_init();
    while(Run()){
        SInput();
        screen_update();
    }
    screen_delete();
    return 0;
}
