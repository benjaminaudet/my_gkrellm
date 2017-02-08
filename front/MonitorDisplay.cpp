#include "MonitorDisplay.hpp"

MonitorDisplay::MonitorDisplay() {

}

MonitorDisplay::~MonitorDisplay() {

}

MonitorDisplay::typesDisplay    MonitorDisplay::getDisplayType() const {
    return this->_displayType;
}

MonitorDisplay::themes    MonitorDisplay::getDisplayTheme() const {
    return this->_displayTheme;
}

unsigned int    MonitorDisplay::getWidth() const {
    return this->_width;
}

unsigned int    MonitorDisplay::getHeight() const {
    return this->_height;
}

void            MonitorDisplay::setDisplayType(const typesDisplay type) {
    this->_displayType = type;
}

void            MonitorDisplay::setDisplayTheme(const themes theme) {
    this->_displayTheme = theme;

}

void            MonitorDisplay::setHeight(const unsigned int height) {
    this->_height = height;

}

void            MonitorDisplay::setWidth(const unsigned int width) {
    this->_width = width;

}
