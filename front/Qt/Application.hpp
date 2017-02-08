#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "module.hpp"
#include <QMainWindow>

class Application : public QMainWindow {
    public:
        QWidget*    getCentralZone() const;
        Application();
        ~Application();
    private:
        QWidget*     _centralZone;
    
};

#endif // APPLICATION_HPP
