#ifndef TIME_HPP
#define TIME_HPP

#include "../../../MonitorModule.hpp"
#include "../../../../back/SysInfo.hpp"
#include <QGridLayout>
#include <QApplication>
#include <QWidget>

class Time : public QWidget, public MonitorModule
{
    public:
        std::string     getTime() const;
        void            setTime(const std::string time);
        Time(const Metrics::SysInfo* sysInfo);
        virtual ~Time();
    private:
        std::string     _time;
        QGridLayout*    _layout;
        
};

#endif // TIME_HPP
