#ifndef MONITOR_DISPLAY_HPP
#define MONITOR_DISPLAY_HPP

class MonitorDisplay
{
    public:
        enum typesDisplay {
            NCURSES,
            QT
        };
        enum themes {
            DARK,
            LIGHT
        };
        typesDisplay    getDisplayType() const;
        themes          getDisplayTheme() const;
        unsigned int    getWidth() const;
        unsigned int    getHeight() const;
        void            setDisplayType(const typesDisplay type);
        void            setDisplayTheme(const themes theme);
        void            setHeight(const unsigned int height);
        void            setWidth(const unsigned int width);
        MonitorDisplay();
        virtual ~MonitorDisplay();
    protected:
        typesDisplay  _displayType;
        themes        _displayTheme;
        unsigned int  _width;
        unsigned int  _height;

};

#endif // MONITOR_DISPLAY_HPP
