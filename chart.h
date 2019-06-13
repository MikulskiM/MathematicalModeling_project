#ifndef CHART_H
#define CHART_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QDebug>
#include <QtCharts>





enum type_of_chart {WEJSCIE};
enum input_signal {SQUARE, HEAVYSIDE, SINUS};

class Chart : public QChart
{
    Q_OBJECT

public:


    Chart(type_of_chart typ_wykresu);

    void setData(type_of_chart typ_wykresu, QLineSeries *danePrzekazane);

    void ustawPrzedzialyWykresu(type_of_chart typ_wykresu , double bottomX, double topX, double bottomY, double topY);
    void ustawPrzedzialyWykresu2(type_of_chart typ_wykresu , double bottomX, double topX, QString bottomY, QString topY);


    type_of_chart typeOfChart;
    QLineSeries *daneNaWykresie;

    QValueAxis *axisX;
    QValueAxis *axisY;
    QLogValueAxis *laxisX;
    QLogValueAxis *laxisY;

    private:

    void linLinAxis();
    void loglogAxis();
    void loglinAxis();
};


#endif // CHART_H
