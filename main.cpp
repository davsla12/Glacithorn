#include <iostream>
#include <MF/screen.h>

#include "Scanes/Scanes.h"

using namespace std;

int main(){
    screen_init();
    SHlavni_init();
    screen_update();
    napms(1000);
    screen_delete();
    return 0;
}
