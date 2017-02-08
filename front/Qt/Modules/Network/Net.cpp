#include "Net.hpp"
#include <string>
#include <QGridLayout>
#include "../../../../back/Network.hpp"

Network::Network():
_layout(new QGridLayout), NetworkLabel(new QLabel), net(new Metrics::Network) {
    QFont* font = new QFont("Roboto", 12);
    this->setFont(*font);
    QTimer* t = new QTimer();
    QObject::connect(t, SIGNAL(timeout()), this, SLOT(updateNet()));
    t->start();
    this->setLayout(this->_layout);
}

Network::~Network() {

}

void    Network::updateNet() {
    QString network("Network : \n");
    NetworkLabel->setText(network + this->net->getNetworkFile().c_str());
    this->_layout->addWidget(NetworkLabel, 0, 0);
}