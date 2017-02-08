#ifndef DATE_HPP_
 #define DATE_HPP_

#include <ncurses.h>
#include "../../../../back/SysInfo.hpp"

class Date : public Metrics::SysInfo //___ to modify ?
{
protected:

public:
  Date();
  virtual ~Date();

  void display();
  virtual bool initialize(); //___ to chose each module
};

#endif
