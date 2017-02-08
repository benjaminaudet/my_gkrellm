#ifndef NAME_HPP_
 #define NAME_HPP_

#include <ncurses.h>
#include "../../../../back/SysInfo.hpp"

class Name : public Metrics::SysInfo
{
protected:

public:
  Name();
  virtual ~Name();

  void display();
  virtual bool initialize(); //___ to chose each module
};

#endif
