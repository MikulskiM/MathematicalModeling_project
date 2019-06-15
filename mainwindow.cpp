#include "mainwindow.h"
#include "math.h"
#include "ui_mainwindow.h"
//#include <QTextStream>
//#include <qlineedit.h>
//#include <string.h>
#include <qvalidator.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    // ------------------------------------------------------ tworzę validator który nie pozwoli wpisać do naszych okienek nic poza cyframi i , i .
    QDoubleValidator *validator = new QDoubleValidator();
    validator->setLocale(QLocale::English);

    ui->a0_box->setValidator(validator);        // ustawiam validator dla każdego okienka
    ui->a1_edit_box->setValidator(validator);
    ui->a2_edit_box->setValidator(validator);
    ui->b0_edit_box->setValidator(validator);
    ui->b1_edit_box->setValidator(validator);
    ui->b2_edit_box->setValidator(validator);
    ui->b3_edit_box->setValidator(validator);


    chart = new Chart(WEJSCIE);
    ui->graphicsView->setChart(chart);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::prepareButtons()
{
    ui->pushButton->setCheckable(true);
    ui->pushButton_2->setCheckable(true);
    ui->pushButton_3->setCheckable(true);
    signalsButton.addButton(ui->pushButton);
    signalsButton.addButton(ui->pushButton_2);
    signalsButton.addButton(ui->pushButton_3);

    signalsButton.setExclusive(true);

    ui->pushButton->setChecked(true);

}

bool MainWindow::check_stability(){ //  ------- funkcja sprawdzająca stabilność naszego układu

    if((a_1*a_2>a_0)&&a_0>0&&a_1>0&&a_2>0)
        return true;
    return false;

}

void MainWindow::on_update_model_stanowy_pressed()
{

    // -------------------------------------------------- obsługa wpisywania danych do macierzy

    QString a_0_string = ui->a0_box->text();    // a0
    bool convertOK;
    this->a_0 = a_0_string.toDouble(&convertOK);
    a_0 = -a_0;
    a_0_string = QString::number(a_0, 'g', 15);
    ui->label_a0->setText(a_0_string);

    QString a_1_string = ui->a1_edit_box->text();   // a1
    this->a_1 = a_1_string.toDouble(&convertOK);
    a_1 = -a_1;
    a_1_string = QString::number(a_1, 'g', 15);
    ui->label_a1->setText(a_1_string);

    QString a_2_string = ui->a2_edit_box->text();   // a2
    this->a_2 = a_2_string.toDouble(&convertOK);
    a_2 = -a_2;
    a_2_string = QString::number(a_2, 'g', 15);
    ui->label_a2->setText(a_2_string);

    QString b_0_string = ui->b0_edit_box->text();   // b0
    this->b_0 = b_0_string.toDouble(&convertOK);
    ui->label_b0->setText(b_0_string);

    QString b_1_string = ui->b1_edit_box->text();   // b1
    this->b_1 = b_1_string.toDouble(&convertOK);
    ui->label_b1->setText(b_1_string);

    QString b_2_string = ui->b2_edit_box->text();   // b2
    this->b_2 = b_2_string.toDouble(&convertOK);
    ui->label_b2->setText(b_2_string);

    QString b_3_string = ui->b3_edit_box->text();   // b3
    this->b_3 = b_3_string.toDouble(&convertOK);
    ui->label_b3->setText(b_3_string);

    double a0b3 = a_0*b_3;
    QString a0b3_string = QString::number(a0b3, 'g', 15);
    ui->label_a0b3->setText(a0b3_string);

    double a1b3 = a_1*b_3;
    QString a1b3_string = QString::number(a1b3, 'g', 15);
    ui->label_a1b3->setText(a1b3_string);

    double a2b3 = a_2*b_3;
    QString a2b3_string = QString::number(a2b3, 'g', 15);
    ui->label_a2b3->setText(a2b3_string);

    // ------------------------------------------------------ Sprawdzam stabilność
    if(check_stability()==true){
        ui->label_stabilny->setVisible(true);
    }else {
        ui->label_stabilny->setVisible(false);

    }

}

void MainWindow::on_pushButton_clicked()
{
    math.typ_wejscia = 'p';               //INPUT PROSTOKĄTNA
    QLineSeries *dane =new QLineSeries();
    math.wypelnianie_macierzy();
    double xfirst = -1*max_time/100;
    dane->append(xfirst, 0);
    dane->append(0, 0);
    for (int i=0; i<math.numberOfPoints; i++)
    {
        double j=i*math.step;
        dane->append(j, math.wybor(j,'p'));
    }

    chart->setData(WEJSCIE,dane);
    chart->ustawPrzedzialyWykresu(WEJSCIE,xfirst,max_time,-1.5, 1.5);
}

void MainWindow::on_pushButton_2_clicked()      //INPUT SKOK
{
    math.typ_wejscia = 'h';
    QLineSeries *dane =new QLineSeries();
    math.wypelnianie_macierzy();
    double xfirst = -1*max_time/100;
    dane->append(xfirst, 0);
    dane->append(0, 0);
    for (int i=0; i<math.numberOfPoints; i++)
    {
       // double j=i/max_time;
        double j=i*math.step;
        dane->append(j, math.wybor(j,'h'));
    }
    chart->setData(WEJSCIE,dane);
    chart->ustawPrzedzialyWykresu(WEJSCIE,xfirst,max_time,-1.5, 1.5);

}

void MainWindow::on_pushButton_3_clicked()
{
    math.typ_wejscia = 's';           //INPUT SINUS
    QLineSeries *dane =new QLineSeries();
    math.wypelnianie_macierzy();
    double xfirst = -1*max_time/100;
    dane->append(xfirst, 0);
    dane->append(0, 0);
    for (int i=0; i<math.numberOfPoints; i++)
    {
        double j=i*math.step;
        dane->append(j, math.wybor(j,'s'));
    }

    chart->setData(WEJSCIE,dane);
    chart->ustawPrzedzialyWykresu(WEJSCIE,xfirst,max_time,-1.5, 1.5);


}
void MainWindow::on_pushButton_4_clicked()
{

    math.wypelnianie_macierzy();         //OUTPUT
    math.TransformataOdwrotna();

   // qDebug()<<"maksy = "<<maksimumY;

    chartW = new Chart(WYJSCIE);
    QLineSeries *nowe =new QLineSeries();
    double xfirst = -1*max_time/100;
    nowe->append(xfirst, 0);
    for (int i=0; i< math.numberOfPoints; i++)       // to samo dla numberOfPoints i max_time...
    {
        double j= i*math.step;
        nowe->append(j, math.outputData[i]);

    }
    maksimum = math.checkMaksimum()*1.1;
    minimum = math.checkMinimum()*1.1;

    chartW->setData(WYJSCIE,nowe);
    chartW->ustawPrzedzialyWykresu( WYJSCIE, xfirst, max_time,minimum, maksimum );
    ui->graphicsView_2->setChart(chartW);
    //qDebug()<<matematyka.outputData[0]<<matematyka.outputData[1]<<matematyka.outputData[2];

}

void MainWindow::on_pushButton_charakterystyka_amplitudowa_clicked()
{
    chartW = new Chart(AMPLITUDOWY);
    QLineSeries *nowe = new QLineSeries();


    math.charakterystyka_amplitudowa();
    nowe = math.obliczaneDane;

    chartW->setData(AMPLITUDOWY,nowe);
    chartW->ustawPrzedzialyWykresu(AMPLITUDOWY,0.1,10000,math.minimumRange*2,math.maksimumRange*2); // ----------- TU UWAGA, pomnożyłem razy 2 bo ładniej wygląda

    int range = int(((abs(math.maksimumRange)+abs(math.minimumRange)))/20);
    chartW->axisY->setTickCount(range+1);

    ui->graphicsView_2->setChart(chartW);

}
