#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <qcustomplot.h>
#include <iostream>
#include "Application.hpp"

#include <string>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Application* window = new Application;





    window->setFixedSize(1000, 600);
    window->show();



    
    // QCustomPlot* customPlot = new QCustomPlot();

    // // set locale to english, so we get english month names:
    // customPlot->setLocale(QLocale(QLocale::French, QLocale::France));
    // // seconds of current time, we'll use it as starting point in time for data:
    // srand(8); // set the random seed, so we always get the same random data
    // // create multiple graphs:
    //   customPlot->addGraph();
    //   QColor color(20+200/4.0*0,70*(1.6-0/4.0), 150, 150);
    //   customPlot->graph()->setLineStyle(QCPGraph::lsLine);
    //   customPlot->graph()->setPen(QPen(color.lighter(200)));
    //   customPlot->graph()->setBrush(QBrush(color));
    //   // generate random walk data:
    //   QVector<QCPGraphData> timeData(250);
    //   customPlot->graph()->data()->set(timeData);
    // // configure bottom axis to show date instead of number:
    // QSharedPointer<QCPAxisTickerTime> dateTicker(new QCPAxisTickerTime);
    // dateTicker->setTimeFormat("%d");
    // customPlot->xAxis->setTickLength(1);
    // customPlot->xAxis->setTicks(true);
    // // configure left axis text labels:
    // // set a more compact font size for bottom and left axis tick labels:
    // // set axis labels:
    // // make top and right axes visible but without ticks and labels:
    // customPlot->xAxis2->setVisible(true);
    // customPlot->yAxis2->setVisible(true);
    // customPlot->xAxis2->setTicks(false);
    // customPlot->yAxis2->setTicks(false);
    // customPlot->xAxis2->setTickLabels(false);
    // customPlot->yAxis2->setTickLabels(false);
    // // set axis ranges to show all data:
    // customPlot->xAxis->setRange(100, 0);
    // customPlot->yAxis->setRange(0, 60);
    // // show legend with slightly transparent background brush:
    // customPlot->legend->setVisible(false);
    // customPlot->legend->setBrush(QColor(255, 255, 255, 150));
    // layout->addWidget(customPlot, 0, 0);
    // layout->addWidget(bouton1, 1, 0);
    // timeData[0].key = 55;
    // timeData[0].value = 55;
    // customPlot->graph()->data()->set(timeData);
    // customPlot->replot();
    // QObject::connect(bouton1, SIGNAL(clicked()), customPlot, SLOT(replot()));


    return app.exec();
}