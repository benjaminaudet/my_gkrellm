#ifndef CPU_HPP
#define CPU_HPP

#include <vector>
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QProgressBar>
#include "../../../MonitorModule.hpp"
#include "../../../../back/CPU.hpp"
#include "../../qcustomplot.h"

class Cpu : public QWidget, public MonitorModule
{
Q_OBJECT
    public slots:
        void    updatePercentage();
    public:
        std::vector<double> getDatas() const;
        void                addData(const double percentage);

        Cpu(size_t id);
        virtual ~Cpu();
    private:
        std::size_t         _cpuid;
        std::vector<double> _datas;
        QGridLayout*        _layout;
        QProgressBar*       _pgBar;
        Metrics::CPU*       _cpu;
        size_t              _id;
    
};

#endif // CPU_HPP
