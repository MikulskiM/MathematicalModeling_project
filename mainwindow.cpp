#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <QTextStream>
//#include <qlineedit.h>
//#include <string.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



//    QDoubleValidator *validator = new QDoubleValidator();
//    validator->setLocale(QLocale::English);

//    ui->a0_box->setValidator(validator);
//    ui->a1_edit_box->setValidator(validator);




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_update_model_stanowy_pressed()
{
    QString a_0_string = ui->a0_box->text();
    bool convertOK;
    this->a_0 = a_0_string.toDouble(&convertOK);
    a_0 = -a_0;
    a_0_string = "-"+a_0_string;
    ui->label_a0->setText(a_0_string);

    QString a_1_string = ui->a1_edit_box->text();
//    bool convertOK;
    this->a_1 = a_1_string.toDouble(&convertOK);
    a_1 = -a_1;
    a_1_string = "-"+a_1_string;
    ui->label_a1->setText(a_1_string);

    QString a_2_string = ui->a2_edit_box->text();
//    bool convertOK;
    this->a_2 = a_2_string.toDouble(&convertOK);
    a_2 = -a_2;
    a_2_string = "-"+a_2_string;
    ui->label_a2->setText(a_2_string);

    QString b_0_string = ui->b0_edit_box->text();
//    bool convertOK;
    this->b_0 = b_0_string.toDouble(&convertOK);
    ui->label_b0->setText(b_0_string);

    QString b_1_string = ui->b1_edit_box->text();
//    bool convertOK;
    this->b_1 = b_1_string.toDouble(&convertOK);
    ui->label_b1->setText(b_1_string);

    QString b_2_string = ui->b2_edit_box->text();
//    bool convertOK;
    this->b_2 = b_2_string.toDouble(&convertOK);
    ui->label_b2->setText(b_2_string);

    QString b_3_string = ui->b3_edit_box->text();
//    bool convertOK;
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
}


