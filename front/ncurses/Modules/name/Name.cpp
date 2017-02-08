#include "Name.hpp"

Name::Name()
{

}

Name::~Name()
{

}

void	Name::display()
{
  Metrics::SysInfo info = Metrics::SysInfo();
  WINDOW *window;

  initscr();
  start_color();

  init_pair(3, COLOR_BLACK, COLOR_WHITE);
  window = subwin(stdscr, 80, 7, 0, 0);

  wbkgd(window, COLOR_PAIR(3));
  attron(A_BOLD | COLOR_PAIR(1));
  printw("STEP 1 : \n");
  attroff(A_BOLD | COLOR_PAIR(1));
  printw("Machine Name / Hostname : %s\nUsername : %s\n",
	 info.getHostName().c_str(), info.getUsername().c_str());
  wrefresh(window);
}

bool Name::initialize()
{
  return (true);
}
