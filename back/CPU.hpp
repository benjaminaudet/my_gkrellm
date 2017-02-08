//
//  CPU.hpp
//  cpp_gkrellm
//
//  Created by Valentin Pichard on 21/01/2017.
//

#ifndef SWEGTOP_CPU_HPP
#define SWEGTOP_CPU_HPP

#include <fstream>
#include <iostream>
#include <numeric>
#include <vector>
#include <unistd.h>
#include <exception>
#include <list>
#include <cstdio>
#include <cstdlib>

#ifndef PROCDIR
#define PROCDIR "/proc"
#endif

#ifndef PROCSTATFILE
#define PROCSTATFILE PROCDIR "/stat"
#endif

namespace Metrics {

static std::vector<std::size_t> AVAL;

class CPU {
public:
    // static funcs
    static int getCPUNumber();

private:

    double _load[3];

    typedef struct      s_CPUData {
        std::size_t totalTime;
        std::size_t userTime;
        std::size_t systemTime;
        std::size_t systemAllTime;
        std::size_t idleAllTime;
        std::size_t idleTime;
        std::size_t niceTime;
        std::size_t ioWaitTime;
        std::size_t irqTime;
        std::size_t softIrqTime;
        std::size_t stealTime;
        std::size_t guestTime;
    }                   t_CPUData;

    typedef struct      s_CPUPercent {
        std::size_t previdle;
        std::size_t prevtotal;
    }                   t_CPUPercent;

   std::vector<t_CPUData>       dcpu;
   std::vector<t_CPUPercent>    prev;

public:
    // Const && dest
    CPU();
    ~CPU();

    // member funcs
    double* getLoadAverage();
    std::vector<t_CPUData> getCPUStat(std::vector<std::size_t> &idle_time = AVAL, std::vector<std::size_t> &total_time = AVAL);
    double *getCPUPercent(double* util);
};

};

#endif //SWEGTOP_CPU_HPP
