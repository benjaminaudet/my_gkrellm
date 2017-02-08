#ifndef RAM_HPP
#define RAM_HPP

#include "../../../../back/Memory.hpp"
#include "../../../MonitorModule.hpp"
#include <QApplication>
#include <QProgressBar>
#include <QGridLayout>
#include <QWidget>
#include <QTimer>
#include <QLabel>
#include <sstream>

class Ram : public QWidget, public MonitorModule
{
Q_OBJECT
    public slots:
        void    updateRam();
    public:
        Ram();
        virtual ~Ram();
    private:
        QGridLayout*            _layout;
        QProgressBar*           _pgBar;
        Metrics::Memory*        _ram;
        std::stringstream       _total;
        std::stringstream       _free;
        std::stringstream       _used;
        QLabel*                 _totalLabel;
        QLabel*                 _usedLabel;
        QLabel*                 _freeLabel;
};


#endif // RAM_HPP
