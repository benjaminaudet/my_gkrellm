#include <QLabel>
#include "Ram.hpp"
#include <QProgressBar>
#include <sstream>
#include <string>
#include <cstdlib>

Ram::Ram():
_layout(new QGridLayout), _pgBar(new QProgressBar), _ram(new Metrics::Memory) {
    this->_totalLabel = new QLabel();
    this->_usedLabel = new QLabel();
    this->_freeLabel = new QLabel();

    QFont* font = new QFont("Roboto", 12);
    this->setFont(*font);
    QTimer* t = new QTimer();
    QObject::connect(t, SIGNAL(timeout()), this, SLOT(updateRam()));
    t->start();

    _total << _ram->getMemory().total;
    _used << _ram->getMemory().totalUsed;
    _free << _ram->getMemory().total - _ram->getMemory().totalUsed;

    QString totalText("Total Ram : ");
    _totalLabel->setText(totalText + _total.str().substr(0, 4).c_str());
    QString usedText("Used Ram : ");
    _usedLabel->setText(usedText + _used.str().substr(0, 4).c_str());
    QString freeText("Free Ram : ");
    _freeLabel->setText(freeText + _free.str().substr(0, 4).c_str());


    _pgBar->setValue(atoi(_used.str().c_str()));
    this->_layout->addWidget(_totalLabel, 0, 0);
    this->_layout->addWidget(_usedLabel, 1, 0);
    this->_layout->addWidget(_freeLabel, 2, 0);
    this->_layout->addWidget(_pgBar, 3, 0);
    this->setLayout(this->_layout);
}

Ram::~Ram() {

}

void            Ram::updateRam() {
    _total << _ram->getMemory().total;
    _used << _ram->getMemory().totalUsed;
    _free << _ram->getMemory().total - _ram->getMemory().totalUsed;

    QString totalText("Total Ram : ");
    _totalLabel->setText(totalText + _total.str().substr(0, 4).c_str());
    QString usedText("Used Ram : ");
    _usedLabel->setText(usedText + _used.str().substr(0, 4).c_str());
    QString freeText("Free Ram : ");
    _freeLabel->setText(freeText + _free.str().substr(0, 4).c_str());
    _pgBar->setValue(atoi(_used.str().substr(0, 4).c_str()) * 100 / atoi(_total.str().substr(0, 4).c_str()));

    this->_layout->addWidget(_totalLabel, 0, 0);
    this->_layout->addWidget(_usedLabel, 1, 0);
    this->_layout->addWidget(_freeLabel, 2, 0);
    this->_layout->addWidget(_pgBar, 3, 0);
}