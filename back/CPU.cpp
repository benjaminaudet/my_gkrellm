//
//  CPU.cpp
//  cpp_gkrellm
//
//  Created by Valentin Pichard on 21/01/2017.
//


#include "CPU.hpp"

// ====== Const && Dest ===== //
Metrics::CPU::CPU() {
  t_CPUPercent tmp;
  tmp.previdle = 0;
  tmp.prevtotal = 0;
  for (int i = 0; i < getCPUNumber(); i++) {
    this->prev.push_back(tmp);
  }
}

Metrics::CPU::~CPU() {}

// ====== Static funcs ===== //

int Metrics::CPU::getCPUNumber() {
  return sysconf(_SC_NPROCESSORS_ONLN);
}

// ====== Member funcs ===== //

// Return all CPUStat but nonformated
std::vector<Metrics::CPU::t_CPUData> Metrics::CPU::getCPUStat(std::vector<std::size_t> &idle_time, std::vector<std::size_t>  &total_time) {
  (void) AVAL;

  std::ifstream proc_stat(PROCSTATFILE);
  if (!proc_stat.is_open()) { throw std::exception(); }
  int cpus = getCPUNumber();
  if (cpus <= 0) { throw std::exception(); }

  for (int i = 0; i < cpus + 1; i++) {
    unsigned long long int usertime, nicetime, systemtime, idletime, ioWait, irq, softIrq, steal, guest, guestnice;

    std::string cpu;
    (void) cpu;

    proc_stat >> cpu;
    proc_stat >> usertime;
    proc_stat >> nicetime;
    proc_stat >> systemtime;
    proc_stat >> idletime;
    proc_stat >> ioWait;
    proc_stat >> irq;
    proc_stat >> softIrq;
    proc_stat >> steal;
    proc_stat >> guest;
    proc_stat >> guestnice;

    usertime = usertime - guest;
    nicetime = nicetime - guestnice;

    std::size_t idlealltime = idletime + ioWait;
    std::size_t systemalltime = systemtime + irq + softIrq;
    std::size_t virtalltime = guest + guestnice;

    idle_time.push_back(idletime);
    total_time.push_back(usertime + nicetime + systemalltime + idlealltime + steal + virtalltime);

    dcpu.push_back((t_CPUData) {
        usertime,
        nicetime,
        systemtime,
        systemalltime,
        idlealltime,
        idletime,
        ioWait,
        irq,
        softIrq,
        steal,
        virtalltime,
        total_time[i]
    });
  }
  proc_stat.close();
  return this->dcpu;
}

double *Metrics::CPU::getCPUPercent(double* util) {
    for (int i = 0; i != getCPUNumber(); i++) {
        std::vector<std::size_t> idle_time, total_time;
        getCPUStat(idle_time, total_time);

        const float idle_time_delta = idle_time[i] - this->prev[i].previdle;
        const float total_time_delta = total_time[i] - this->prev[i].prevtotal;
        util[i] = 100.0 * (1.0 - idle_time_delta / total_time_delta);

        this->prev[i].previdle = idle_time[i];
        this->prev[i].prevtotal = total_time[i];
    }

    return util;
}

double *Metrics::CPU::getLoadAverage() {
  if (getloadavg(this->_load, 3) != -1)
    return this->_load;
  else
    throw std::exception();
}
