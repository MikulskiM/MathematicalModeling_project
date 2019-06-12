#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

    bool check_stability();

private slots:

    void on_update_model_stanowy_pressed();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
