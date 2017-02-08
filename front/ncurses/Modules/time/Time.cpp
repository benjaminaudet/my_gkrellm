#include "Time.hpp"

Time::Time()
{

}

Time::~Time()
{

}

void	Time::display()
{
  Metrics::SysInfo info = Metrics::SysInfo();
  WINDOW *window;

  initscr();
  printw("\nTime : %s\nUptime : %s\n\n",
	  info.getTime().c_str(), info.getUptime().c_str());
  wrefresh(window);
}

bool Time::initialize()
{
  return (true);
}
