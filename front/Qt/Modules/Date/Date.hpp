#ifndef DATE_HPP
#define DATE_HPP

#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QProgressBar>
#include "../../../../back/SysInfo.hpp"
#include "../../../MonitorModule.hpp"

class Date : public QWidget, public MonitorModule
{
Q_OBJECT
    public slots:
        void            updateTime();
    public:
        std::string     getDateTime() const;
        void            setDateTime(const std::string dateTime);
        Date(const Metrics::SysInfo* sysInfo);
        ~Date();
    private:
        std::string     _dateTime;
        QGridLayout*    _layout;
        QLabel*         _timeLabel;
        const Metrics::SysInfo* _sysInfo;
};

#endif // DATE_HPP
