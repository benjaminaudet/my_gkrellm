#include "Cpu.hpp"
#include <string>
#include <QProgressBar>
#include <cstdlib>
#include <QLabel>
#include <sstream>

Cpu::Cpu(size_t id):
_cpuid(id), _layout(new QGridLayout), _pgBar(new QProgressBar), _cpu(new Metrics::CPU) {
    this->_id = id;
    this->updatePercentage();
    QTimer* t = new QTimer();
    QObject::connect(t, SIGNAL(timeout()), this, SLOT(updatePercentage()));
    t->start();
    QLabel*         title = new QLabel;
    std::stringstream cpuid;
    std::stringstream percent;

    double cores[_cpu->getCPUNumber() + 1];
    double *cpycores;
    cpycores = _cpu->getCPUPercent(cores);
    percent << cpycores[id];

    cpuid << id;
    QString cpuNbr(cpuid.str().c_str());

    title->setText("CPU" + cpuNbr);
    _pgBar->setValue(atoi(percent.str().c_str()));
    this->_layout->setColumnStretch(1, 100);
    this->_layout->addWidget(title, 0, 0);
    this->_layout->addWidget(_pgBar, 0, 1);
    this->setLayout(this->_layout);
}

Cpu::~Cpu() {

}

std::vector<double> Cpu::getDatas() const {
    return this->_datas;
}

void                Cpu::addData(const double percentage) {
    this->_datas.push_back(percentage);
}

void                Cpu::updatePercentage() {
    std::stringstream percent;

    double cores[_cpu->getCPUNumber() + 1];
    double *cpycores;
    cpycores = _cpu->getCPUPercent(cores);
    ;; usleep(40000);
    percent << cpycores[_id];
    if (percent.str() != "-nan") {
        std::string percentStr = percent.str();
        _pgBar->setValue(atoi(percent.str().c_str()));
        this->_layout->addWidget(_pgBar, 0, 1);
    }
}

