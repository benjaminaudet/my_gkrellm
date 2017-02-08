#ifndef I_MONITOR_DISPLAY_HPP
#define I_MONITOR_DISPLAY_HPP

class IMonitorDisplay
{
	public:
		virtual ~IMonitorDisplay() = 0;
        virtual typesDisplay    getDisplayType() const = 0;
        virtual themes          getDisplayTheme() const = 0;
        virtual unsigned int    getWidth() const = 0;
        virtual unsigned int    getHeight() const = 0;
        virtual void            setDisplayType(const typesDisplay type) = 0;
        virtual void            setDisplayTheme(const themes theme) = 0;
        virtual void            setHeight(const unsigned int height) = 0;
        virtual void            setWidth(const unsigned int width) = 0;
	protected:

};

#endif // I_MONITOR_DISPLAY_HPP
