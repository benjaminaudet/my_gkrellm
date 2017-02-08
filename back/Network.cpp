//
//  CPU.cpp
//  cpp_gkrellm
//
//  Created by Valentin Pichard on 21/01/2017.
//

#include "Network.hpp"

std::string Metrics::Network::getNetworkFile() {
    std::string file;

    std::ifstream net_proc(PROCNETFILE);
    if (!net_proc.is_open()) {
        throw std::exception();
    }
    file.assign(std::istreambuf_iterator<char>(net_proc.rdbuf()),
               std::istreambuf_iterator<char>());
    return file;
}
