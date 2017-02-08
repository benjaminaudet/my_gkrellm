#include "Time.hpp"
#include <QLabel>
#include <iostream>

Time::Time(const Metrics::SysInfo* sysInfo):
_time(sysInfo->getTime()), _layout(new QGridLayout) {
    QFont* font = new QFont("Roboto", 12);
    this->setFont(*font);

    QLabel *TimeLabel = new QLabel();

    QString time("Time : \n");

    TimeLabel->setText(time + this->getTime().c_str());

    TimeLabel->setAlignment(Qt::AlignTop);
    TimeLabel->setIndent(20);

    this->_layout->addWidget(TimeLabel, 0, 0);
    this->setLayout(this->_layout);
}

Time::~Time() {

}

std::string     Time::getTime() const {
    return this->_time;
}

void            Time::setTime(const std::string time) {
    this->_time = time;
}

