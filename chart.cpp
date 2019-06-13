#include "chart.h"

Chart::Chart(type_of_chart typ_wykresu)
{
    this->legend()->hide();
    daneNaWykresie = new QLineSeries();

    addSeries(daneNaWykresie);


    switch (typ_wykresu) {
    case WEJSCIE:

        linLinAxis();
        this->setTitle("Sygnał wejściowy");
        ustawPrzedzialyWykresu(WEJSCIE, -1,100,-3,3);
        break;

    case WYJSCIE:

        linLinAxis();
        this->setTitle("Sygnał wyjściowy");
        ustawPrzedzialyWykresu(WYJSCIE, -1,100,-0.5,100);
        break;

    }

}

void Chart::setData(type_of_chart typ_wykresu, QLineSeries *danePrzekazane)
{
    removeSeries(daneNaWykresie);
    daneNaWykresie = danePrzekazane;
    this->addSeries(daneNaWykresie);

    if(typ_wykresu == WEJSCIE || typ_wykresu == WYJSCIE){

       daneNaWykresie->attachAxis(axisX);
       daneNaWykresie->attachAxis(axisY);
    }
    else {
        daneNaWykresie->attachAxis(laxisX);
        daneNaWykresie->attachAxis(axisY);
    }
}

void Chart::ustawPrzedzialyWykresu(type_of_chart typ_wykresu, double bottomX, double topX, double bottomY, double topY)
{
    if(typ_wykresu == WEJSCIE || typ_wykresu == WYJSCIE){
        axisX->setRange(bottomX,topX);
        axisY->setRange(bottomY,topY);

    }
    else {
        laxisX->setRange(bottomX,topX);
        axisY->setRange(bottomY,topY);
    }
}

void Chart::linLinAxis()
{
    axisX = new QValueAxis();
    axisY = new QValueAxis();

    axisY->setTitleText("wartość sygnału");
    axisX->setTitleText("czas [s]");

    this->addAxis(axisX, Qt::AlignBottom);
    this->addAxis(axisY, Qt::AlignLeft);
}

void Chart::loglogAxis()
{

    laxisX = new QLogValueAxis();
    laxisY = new QLogValueAxis();

    laxisX->setLabelFormat("%g");
    laxisY->setLabelFormat("%g");

    laxisX->setBase(10.0);
    laxisY->setBase(10.0);

    laxisX->setMinorTickCount(5);
    laxisY->setMinorTickCount(5);

    this->addAxis(laxisX, Qt::AlignBottom);
    this->addAxis(laxisY, Qt::AlignLeft);
}

void Chart::loglinAxis()
{
     laxisX = new QLogValueAxis();
     axisY = new QValueAxis();
     laxisX->setBase(10.0);
     this->addAxis(laxisX, Qt::AlignBottom);
     this->addAxis(axisY, Qt::AlignLeft);
     laxisX->setMinorTickCount(9);
     axisY->setMinorTickCount(2);
  //   axisY->setTickCount(3);

}
