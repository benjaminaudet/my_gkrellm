#include <ncurses.h>
#include "name/Name.hpp"
#include "os/OS.hpp"
#include "date/Date.hpp"
#include "time/Time.hpp"
#include "cpu/Cpu.hpp"
#include "ram/Ram.hpp"
#include "network/Network.hpp"

int main()
{
  Name	name;
  OS	os;
  Date	date;
  Time	mtime;
  Cpu	cpu;
  Ram	ram;
  Network network;
  
  WINDOW *window;
  int row,col; 
  int c;
  
  initscr();
  noecho();
  curs_set(FALSE);
  timeout(2000);
  start_color();
  init_pair(1, COLOR_BLACK, COLOR_WHITE);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  window = subwin(stdscr, 1, 1, 1, 1);
  keypad(window, TRUE);//???????????
  getmaxyx(stdscr, row, col);
  
  
  name.initialize();
  os.initialize();
  date.initialize();
  mtime.initialize();
  cpu.initialize();
  ram.initialize();
  network.initialize();
  
  while (1)
    {
      clear();
      name.display();
      os.display();
      date.display();
      mtime.display();
      attron(A_BOLD | COLOR_PAIR(2));
      printw("================================================================\n");
      attroff(A_BOLD | COLOR_PAIR(2));
      cpu.display();
      ram.display();
      attron(A_BOLD | COLOR_PAIR(2));
      printw("================================================================\n");
      attroff(A_BOLD | COLOR_PAIR(2));
      network.display();

      //mvprintw(row-1,0,"This screen has %d rows and %d columns\n",row,col);
      //printw("Try resizing your window(if possible) and then run this program again");
      mvprintw(row-2,0,"ctrl+c to close");
      refresh();
    }

  delwin(window);
  endwin();
  return (0);
}
