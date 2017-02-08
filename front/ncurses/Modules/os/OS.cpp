#include "OS.hpp"

OS::OS()
{

}

OS::~OS()
{

}

void	OS::display()
{
  Metrics::SysInfo info = Metrics::SysInfo();
  WINDOW *window;

  initscr();
  printw("\nSystem Name : %s\nKernel Version: %s\nArch: %s\n",
	 info.getSystemName().c_str(), info.getKernelVersion().c_str(),
	 info.getArch().c_str());
  wrefresh(window);
}

bool OS::initialize()
{
  return (true);
}
