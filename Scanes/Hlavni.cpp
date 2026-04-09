#include <MF/screen.h>
Scane SHlavni;

int SHlavni_init(){
    CreateWin(&SHlavni,20,40,0,0);
    AddScane(&SHlavni);
    return 0;
}
