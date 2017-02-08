#include "Application.hpp"
#include <QGridLayout>
#include <QSpacerItem>
#include <QPushButton>
#include <QSizePolicy>
#include "../../back/CPU.hpp"

Application::Application():
_centralZone(new QWidget) {
    QFont* font = new QFont("Roboto", 12);
    this->setFont(*font);
    this->setStyleSheet("QMainWindow {background: #2c3e50;} QLabel {color: #f39c12;} QPushButton {background: #c0392b;} QProgressBar {background: #f39c12;}");
    Metrics::SysInfo* sysInfo = new Metrics::SysInfo;
    setCentralWidget(this->_centralZone);
    // ----- NAME ----- //
    Name* name = new Name(sysInfo);

    // ----- OS ----- //
    OS* os = new OS(sysInfo);

    // ----- DATE ----- //
    Date* date = new Date(sysInfo);

    // ----- TIME ----- //

    // ----- CPU ----- //
    int CPUNumber = Metrics::CPU::getCPUNumber();
    // int CPUNumber = 4;
    Cpu**   cpuGroups = new Cpu*[CPUNumber];
    for (int i = 0; i < CPUNumber; ++i) {
        cpuGroups[i] = new Cpu(i);
    }

    // ----- RAM ----- //
    Ram* ram = new Ram;

    // ----- NETWORK ----- //
    Network* network = new Network;


    QLabel*  cpuUsages = new QLabel("CPUs USAGES");
    // Init Layout
    QPushButton* closeButton = new QPushButton("X", this);
    QGridLayout *layout = new QGridLayout;
    this->getCentralZone()->setLayout(layout);
    // Add Widget to layout
    layout->setColumnStretch(0, 20);
    layout->addWidget(cpuUsages, 3, 0);
    layout->setAlignment(cpuUsages, Qt::AlignCenter);
    layout->addWidget(closeButton, 0, 2);
    layout->setAlignment(closeButton, Qt::AlignTop);
    layout->addWidget(name, 0, 0);
    layout->setAlignment(name, Qt::AlignTop);
    layout->addWidget(os, 1, 0);
    layout->setAlignment(os, Qt::AlignTop);
    layout->addWidget(date, 2, 0);
    layout->setAlignment(date, Qt::AlignTop);
    int i = 0;
    while(i < CPUNumber) {
        layout->addWidget(cpuGroups[i], i + 4, 0);
        layout->setAlignment(cpuGroups[i], Qt::AlignTop);
        i++;
    }
    layout->addWidget(ram, 2, 1);
    layout->setAlignment(ram, Qt::AlignTop);
    layout->addWidget(network, 3, 1);
    layout->setAlignment(network, Qt::AlignTop);
    QObject::connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));
}

Application::~Application() {

}

QWidget*    Application::getCentralZone() const {
    return this->_centralZone;
}