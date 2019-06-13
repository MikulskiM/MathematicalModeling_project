#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QButtonGroup>
#include <string>
#include <QString>
#include <QDebug>
#include "chart.h"
#include "math.h"


#define startPoint 10

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    double a_0 = startPoint;
    double a_1 = startPoint;
    double a_2 = startPoint;
    double b_0 = startPoint;
    double b_1 = startPoint;
    double b_2 = startPoint;
    double b_3 = startPoint;
    int Tinput = 10;
    double max_time = 100;
    double maksimumY=2;

    double minimum = 0;
    double maksimum = 0;

    bool check_stability();

    void prepareButtons();

private slots:

    void on_update_model_stanowy_pressed();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    QButtonGroup signalsButton;
    Math math;
    Chart *chart;
    Chart *chartW;

};

#endif // MAINWINDOW_H
