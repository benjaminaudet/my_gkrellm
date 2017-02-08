#ifndef NAME_HPP
#define NAME_HPP

#include "../../../../back/SysInfo.hpp"
#include "../../../MonitorModule.hpp"
#include <QApplication>
#include <QWidget>
#include <QGridLayout>

class Name : public QWidget, public MonitorModule
{
    public:
        std::string     getMachineName() const;
        void            setMachineName(const std::string machineName);
        std::string     getUserName() const;
        void            setUserName(const std::string userName);
        Name(const Metrics::SysInfo* sysInfo);
        virtual ~Name();
    private:
        std::string     _machineName;
        std::string     _userName;
        QGridLayout*    _layout;
};

#endif // NAME_HPP
