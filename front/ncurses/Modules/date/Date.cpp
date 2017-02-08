#include "Date.hpp"

Date::Date()
{

}

Date::~Date()
{

}

void	Date::display()
{
  Metrics::SysInfo info = Metrics::SysInfo();
  WINDOW *window;

  initscr();
  printw("\nDate : %s", info.getDate().c_str());
  wrefresh(window);
}

bool Date::initialize()
{
  return (true);
}
