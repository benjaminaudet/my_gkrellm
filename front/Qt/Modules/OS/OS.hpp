#ifndef OS_HPP
#define OS_HPP

#include "../../../MonitorModule.hpp"
#include "../../../../back/SysInfo.hpp"
#include <QApplication>
#include <QWidget>
#include <QGridLayout>

class OS : public QWidget, public MonitorModule
{
    public:
        std::string     getOsName() const;
        void            setOsName(const std::string osName);
        std::string     getKernelVersion() const;
        void            setKernelVersion(const std::string kernelVersion);
        OS(const Metrics::SysInfo* sysInfo);
        virtual ~OS();
    private:
        std::string     _osName;
        std::string     _kernelVersion;
        QGridLayout*    _layout;
};

#endif // OS_HPP
