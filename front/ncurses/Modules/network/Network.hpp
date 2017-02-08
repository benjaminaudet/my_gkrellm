#ifndef NETWORK_HPP_
 #define NETWORK_HPP_

#include <ncurses.h>
#include "../../../../back/Network.hpp"

class Network : public Metrics::Network
{
protected:

public:
  Network();
  virtual ~Network();

  void display();
  virtual bool initialize(); //___ to chose each module
};

#endif
