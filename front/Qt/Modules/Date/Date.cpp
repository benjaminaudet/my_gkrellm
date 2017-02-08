#include "Date.hpp"
#include <QLabel>
#include <QTimer>
#include <iostream>

Date::Date(const Metrics::SysInfo* sysInfo):
QWidget(), _dateTime(sysInfo->getDate()), _layout(new QGridLayout), _timeLabel(new QLabel()) {
    this->updateTime();
    QTimer* t = new QTimer();
    QObject::connect(t, SIGNAL(timeout()), this, SLOT(updateTime()));
    t->start();
    QFont* font = new QFont("Roboto", 12);
    this->setFont(*font);

    QLabel *DateLabel = new QLabel();

    QString date("Date : \n");

    DateLabel->setText(date + this->getDateTime().c_str());

    DateLabel->setAlignment(Qt::AlignTop);
    DateLabel->setIndent(20);

    this->_layout->setVerticalSpacing(0);
    this->_layout->addWidget(DateLabel, 0, 0);
    this->setLayout(this->_layout);
}

Date::~Date() {

}

std::string     Date::getDateTime() const {
    return this->_dateTime;
}

void            Date::setDateTime(const std::string dateTime) {
    this->_dateTime = dateTime;
}

void            Date::updateTime() {
    QString time("Time : \n");
    _timeLabel->setText(time + _sysInfo->getTime().c_str());
    _timeLabel->setIndent(20);
    _timeLabel->setAlignment(Qt::AlignTop);
    this->_layout->addWidget(this->_timeLabel, 0, 1);
}