#include "OS.hpp"
#include <QLabel>
#include <iostream>

OS::OS(const Metrics::SysInfo* sysInfo):
_osName(sysInfo->getSystemName()), _kernelVersion(sysInfo->getKernelVersion()), _layout(new QGridLayout) {
    QFont* font = new QFont("Roboto", 12);
    this->setFont(*font);

    QLabel *SystemNameLabel = new QLabel();
    QLabel *KernelVersionLabel = new QLabel();

    QString systemname("SystemName : \n");
    QString kernelversion("KernelVersion : \n");

    SystemNameLabel->setText(systemname + this->getOsName().c_str());
    KernelVersionLabel->setText(kernelversion + this->getKernelVersion().c_str());

    SystemNameLabel->setAlignment(Qt::AlignTop);
    SystemNameLabel->setIndent(20);
    KernelVersionLabel->setAlignment(Qt::AlignTop);
    KernelVersionLabel->setIndent(20);

    this->_layout->setVerticalSpacing(0);
    this->_layout->addWidget(SystemNameLabel, 0, 0);
    this->_layout->addWidget(KernelVersionLabel, 0, 1);
    this->setLayout(this->_layout);
}

OS::~OS() {

}

std::string     OS::getOsName() const {
    return this->_osName;
}

void            OS::setOsName(const std::string osName) {
    this->_osName = osName;
}

std::string     OS::getKernelVersion() const {
    return this->_kernelVersion;
}

void            OS::setKernelVersion(const std::string kernelVersion) {
    this->_kernelVersion = kernelVersion;
}