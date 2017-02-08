#ifndef OS_HPP_
 #define OS_HPP_

#include <ncurses.h>
#include "../../../../back/SysInfo.hpp"

class OS : public Metrics::SysInfo
{
protected:

public:
  OS();
  virtual ~OS();

  void display();
  virtual bool initialize();
};

#endif
