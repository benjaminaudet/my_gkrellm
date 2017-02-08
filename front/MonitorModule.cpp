#include "MonitorModule.hpp"

MonitorModule::MonitorModule() {

}

MonitorModule::~MonitorModule() {
    
}

std::string     MonitorModule::getTitle() const {
    return this->_title;
}

void            MonitorModule::setTitle(const std::string title) {
    this->_title = title;
}