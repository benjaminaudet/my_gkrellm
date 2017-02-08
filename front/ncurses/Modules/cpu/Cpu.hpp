#ifndef CPU_HPP_
 #define CPU_HPP_

#include <ncurses.h>
#include "../../../../back/CPU.hpp"

class Cpu : public Metrics::CPU
{
public:
  Cpu();
  virtual ~Cpu();

  void display();
  virtual bool initialize(); //___ to chose each module
};

#endif
