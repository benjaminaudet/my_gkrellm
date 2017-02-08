//
// Created by antoine on 21/01/17.
//

#include <iostream>
#include <Memory.hpp>
#include <CPU.hpp>
#include "SysInfo.hpp"
#include <unistd.h>
#include "Network.hpp"

int main() {
    for (;; sleep(1)) {
        system("clear");
        std::cout << std::string( 100, '\n' );
        std::cout << "* ==== SYSINFO ==== *\n\n";

        Metrics::SysInfo info = Metrics::SysInfo();
        std::cout << "System Name: " << info.getSystemName() << std::endl;
        std::cout << "Kernel Version: " << info.getKernelVersion() << std::endl;
        std::cout << "Hostname: " << info.getHostName() << std::endl;
        std::cout << "Arch: " << info.getArch() << std::endl;
        std::cout << "Username: " << info.getUsername() << std::endl;
        std::cout << "Date: " << info.getDate() << std::endl;
        std::cout << "Time: " << info.getTime() << std::endl;
        std::cout << "Uptime: " << info.getUptime() << std::endl;

        std::cout << "\n\n* ==== MEMORY ==== *\n\n";

        Metrics::Memory::memory mem = Metrics::Memory::getMemory();
        /*
        * http://stackoverflow.com/questions/41224738/how-to-calculate-memory-usage-from-proc-meminfo-like-htop
        */
        std::cout << "total: " << mem.total / 1024 << "M" << std::endl;
        std::cout << "totalUsed: " << mem.totalUsed / 1024 << "M" << std::endl;
        std::cout << "nonCacheBufferUsed: " << mem.nonCacheBufferUsed / 1024 << "M" << std::endl;
        std::cout << "buffers: " << mem.buffers / 1024 << "M" << std::endl;
        std::cout << "cached: " << mem.cached / 1024 << "M" << std::endl;
        std::cout << "swapUsed: " << mem.swapUsed / 1024 << "M" << std::endl;
        std::cout << "swapFree: " << mem.swapFree / 1024 << "M" << std::endl;
        std::cout << "swapTotal: " << mem.swapTotal / 1024 << "M" << std::endl;

        std::cout << "\n\n* ==== CPU ==== *\n\n";

        Metrics::CPU cpu;
        std::cout << "CPU numbers: " << cpu.getCPUNumber() << "\n\n";
        double cores[cpu.getCPUNumber() + 1];
        double *cpycores;

        cpycores = cpu.getCPUPercent(cores);
        for (int i = 0; i != cpu.getCPUNumber(); i++) {
            std::cout << cpycores[i] << "%" << std::endl;
        }

        std::cout << "\n\n* ==== NETWORK ==== *\n\n";

        std::cout << Metrics::Network::getNetworkFile() << std::endl;
  }
}
