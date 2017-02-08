#include "Cpu.hpp"

Cpu::Cpu()
{

}

Cpu::~Cpu()
{

}

void	Cpu::display()
{
  Metrics::CPU info;
  int counter = info.getCPUNumber();
  double cores[info.getCPUNumber() + 1];
  double *cpycores;
  WINDOW *window;

  initscr();
  start_color();

  init_pair(1, COLOR_BLACK, COLOR_WHITE);
  init_pair(3, COLOR_BLUE, COLOR_BLACK);
  window = subwin(stdscr, 80, 8, 0, 0);
  wbkgd(window, COLOR_PAIR(1));
  attron(A_BOLD | COLOR_PAIR(1));
  printw("STEP 2 : \n");
  attroff(A_BOLD | COLOR_PAIR(1));
  printw("Number of CPU(s) : %d\n", info.Metrics::CPU::getCPUNumber());
  cpycores = info.getCPUPercent(cores);
  for (int i = 0; i != info.getCPUNumber(); i++)
    {
      printw("CPU(s) : %2.2f %\n", cpycores[i]);
    }
  printw("Load average : %2.2f", getLoadAverage()[0]);
  attron(A_BOLD | COLOR_PAIR(3));
  printw(" %2.2f", getLoadAverage()[1]);
  attroff(A_BOLD | COLOR_PAIR(3));
  printw(" %2.2f\n", getLoadAverage()[2]);
  wrefresh(window);
}

bool Cpu::initialize()
{
  return (true);
}
