#include "Name.hpp"
#include <QLabel>
#include <iostream>

Name::Name(const Metrics::SysInfo* sysInfo):
_machineName(sysInfo->getHostName()), _userName(sysInfo->getUsername()), _layout(new QGridLayout) {
    QFont* font = new QFont("Roboto", 12);
    this->setFont(*font);

    QLabel *HostNameLabel = new QLabel();
    QLabel *UserNameLabel = new QLabel();

    QString hostname("HostName : \n");
    QString username("UserName : \n");

    HostNameLabel->setText(hostname + this->getMachineName().c_str());
    UserNameLabel->setText(username + this->getUserName().c_str());

    HostNameLabel->setAlignment(Qt::AlignTop);
    HostNameLabel->setIndent(20);
    UserNameLabel->setAlignment(Qt::AlignTop);
    UserNameLabel->setIndent(20);

    this->_layout->setVerticalSpacing(0);
    this->_layout->addWidget(HostNameLabel, 0, 0);
    this->_layout->addWidget(UserNameLabel, 0, 1);
    this->setLayout(this->_layout);
}

Name::~Name() {

}

std::string     Name::getMachineName() const {
    return this->_machineName;
}

void            Name::setMachineName(const std::string machineName) {
    this->_machineName = machineName;
}

std::string     Name::getUserName() const {
    return this->_userName;
}

void            Name::setUserName(const std::string userName) {
    this->_userName = userName;
}