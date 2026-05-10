#ifndef S_LOG
#define S_LOG

#include <ncurses.h>

int SLog_init(WINDOW* okno);
void Log(const char *fmt, ...);
#endif
