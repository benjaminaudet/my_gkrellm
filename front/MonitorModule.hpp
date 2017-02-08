#ifndef MONITOR_MODULE_HPP
#define MONITOR_MODULE_HPP

#include "IMonitorModule.hpp"

class MonitorModule : public IMonitorModule
{
    public:
        virtual std::string         getTitle() const;
        virtual void                setTitle(const std::string title);
        MonitorModule();
        virtual ~MonitorModule();
    protected:
        std::string         _title;
};

#endif // MONITOR_MODULE_HPP
