//
//  CPU.cpp
//  cpp_gkrellm
//
//  Created by Valentin Pichard on 21/01/2017.
//

#ifndef SWEGTOP_NETWORK_HPP
#define SWEGTOP_NETWORK_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <exception>

#ifndef PROCDIR
#define PROCDIR "/proc"
#endif

#ifndef PROCNETFILE
#define PROCNETFILE PROCDIR "/net/dev"
#endif

namespace Metrics {

class Network {
public:
    static std::string getNetworkFile();
};

};

#endif //SWEGTOP_NETWORK_HPP
