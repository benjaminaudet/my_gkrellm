#include "Network.hpp"

Network::Network()
{

}

Network::~Network()
{

}

void	Network::display()
{
  WINDOW *window;

  initscr();
  start_color();

  init_pair(1, COLOR_BLACK, COLOR_WHITE);
  window = subwin(stdscr, 80, 20, 0, 0);

  wbkgd(window, COLOR_PAIR(3));
  attron(A_BOLD | COLOR_PAIR(1));
  printw("STEP 3 : \n");
  attroff(A_BOLD | COLOR_PAIR(1));
  printw("\nNetwork : %s\n", Metrics::Network::getNetworkFile().c_str());
  wrefresh(window);
}

bool Network::initialize()
{
  return (true);
}
