#ifndef I_MONITOR_MODULE_HPP
#define I_MONITOR_MODULE_HPP

#include <string>

class IMonitorModule
{
	public:
		virtual std::string 	getTitle() const = 0;
		virtual void		    setTitle(const std::string title) = 0;
		virtual ~IMonitorModule() {};
};

#endif // I_MONITOR_MODULE_HPP
