#ifndef RAM_HPP_
 #define RAM_HPP_

#include <ncurses.h>
#include "../../../../back/Memory.hpp"
#include "../../../../back/SysInfo.hpp"

class Ram : public Metrics::Memory
{
public:
  Ram();
  virtual ~Ram();

  void display();
  virtual bool initialize(); //___ to chose each module
};

#endif
