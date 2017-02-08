#ifndef NETWORK_HPP
#define NETWORK_HPP

#include "../../../MonitorModule.hpp"
#include "../../../../back/Network.hpp"
#include <QApplication>
#include <QTimer>
#include <QLabel>
#include <QGridLayout>
#include <QWidget>

class Network : public QWidget, public MonitorModule
{
Q_OBJECT
    public slots:
        void    updateNet();
    public:
        Network();
        virtual ~Network();
    private:
        QGridLayout*        _layout;
        QLabel*             NetworkLabel;
        Metrics::Network*   net;
};

#endif // NETWORK_HPP
