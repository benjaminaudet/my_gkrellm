#include "Ram.hpp"

Ram::Ram()
{

}

Ram::~Ram()
{

}

void	Ram::display()
{
  Metrics::Memory::memory mem = Metrics::Memory::getMemory();
  WINDOW *window;

  initscr(); 
  window = subwin(stdscr, 80, 13, 0, 0);

  printw("\nTotal RAM : %uM\n", mem.total / 1024);
  printw("Ram Used : %uM\n", mem.nonCacheBufferUsed / 1024);
  printw("Swap Used : %uM\n", mem.swapUsed / 1024);
  wrefresh(window);
}

bool Ram::initialize()
{
  return (true);
}
