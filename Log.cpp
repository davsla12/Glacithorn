#include <stdarg.h>
#include <ncurses.h>
#include <vector>
#include <string>
#include "Log.h"

WINDOW* window;
std::vector<std::string> log_buffer;

void SLog_render(){
  wclear(window);
  int screen_y = getmaxy(window)-2;
  for(int y = log_buffer.size()-1;y >= 0;y--){
    mvwprintw(window,(screen_y-log_buffer.size())+y+1,1,"%s",log_buffer[y].c_str());
  }
  wrefresh(window);
}

void Log(const char *fmt, ...) {
    int screen_y = getmaxy(window)-2;
    char buf[1024];

    va_list args;
    va_start(args, fmt);

    vsnprintf(buf, sizeof(buf), fmt, args);
    va_end(args);

    log_buffer.push_back(buf);
    if(log_buffer.size()>screen_y)log_buffer.erase(log_buffer.begin());

    SLog_render();
}

int SLog_init(WINDOW* okno){
  window = okno;
  scrollok(window,TRUE);
  return 0;
}
