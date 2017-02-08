#ifndef TIME_HPP_
 #define TIME_HPP_

#include <ncurses.h>
#include "../../../../back/SysInfo.hpp"

class Time : public Metrics::SysInfo
{
protected:

public:
  Time();
  virtual ~Time();

  void display();
  virtual bool initialize(); //___ to chose each module
};

#endif
