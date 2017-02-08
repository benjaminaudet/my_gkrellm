//
// Created by antoine on 21/01/17.
//

#ifndef SWEGTOP_MEMORY_HPP
#define SWEGTOP_MEMORY_HPP

#include <fstream>
#include <exception>
#include <iostream>

namespace Metrics {

class Memory {
 public:
  struct memory {
    long long int total;
    long long int totalUsed;
    long long int nonCacheBufferUsed;
    long long int buffers;
    long long int cached;
    long long int swapUsed;
    long long int swapFree;
    long long int swapTotal;
  };

  static struct memory getMemory();
};


};

#endif //SWEGTOP_MEMORY_HPP
