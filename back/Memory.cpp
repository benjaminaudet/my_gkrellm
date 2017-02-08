//
// Created by antoine on 21/01/17.
//

#include "Memory.hpp"

Metrics::Memory::memory Metrics::Memory::getMemory() {
  long long int memTotal = 0;
  long long int memFree = 0;
  long long int buffers = 0;
  long long int cached = 0;
  long long int swapTotal = 0;
  long long int swapFree = 0;
  long long int shmem = 0;
  long long int sreclaimable = 0;

  std::ifstream file("/proc/meminfo");
  if (!file.is_open()) {
    std::cerr << "Cannot open meminfo" << std::endl;
    throw std::exception();
  }

#define readLabel(label, variable) buffer.find(label) == 0 && file >> variable
  std::string buffer;
  while (file >> buffer) {
    if (readLabel("MemTotal:", (memTotal)));
    else if (readLabel("MemFree:", memFree));
    else if (readLabel("Buffers:", buffers));
    else if (readLabel("Cached:", cached));
    else if (readLabel("SReclaimable:", sreclaimable));
    else if (readLabel("Shmem:", shmem));
    else if (readLabel("SwapTotal:", swapTotal));
    else if (readLabel("SwapFree:", swapFree)) {}
  }

  return (memory) {
      total: memTotal,
      totalUsed: memTotal - memFree,
      nonCacheBufferUsed: memTotal - memFree - (buffers + cached),
      buffers: buffers,
      cached: cached,
      swapUsed: swapTotal - swapFree,
      swapFree: swapFree,
      swapTotal: swapTotal
  };
}
