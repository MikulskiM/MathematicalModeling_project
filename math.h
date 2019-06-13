#ifndef MATH_H
#define MATH_H

#include <cmath>
#include <QtCharts>
#include <QDebug>
#include <complex>
#include <QVector>

class Math
{
public:
    Math();

    const double e = 2.72;         // Liczba Eulera
    const double pi = 3.1415;        // Liczba PI
    const static int numberOfPoints = 10000;
    int Tinput = 25;
    double max_time=100;
    double step=max_time/numberOfPoints;

    double ProstokatInput (double i);
    double SkokInput (double i);
    double SinusInput (double i);

    double MatrixX[3][3];       //[3][1]
    double MatrixA[3][3];
    double MatrixB[3][3];       //[3][1]
    double MatrixC[3][3];       //[1][3]
    double MatrixD[3][3];       //[1][1]
    double dxMatrix[3][3];      //[1][3]
    double outputMatrix[3][3];   //
    double inverseMatrixA[3][3];
    double a_0=2;
    double a_1=2;
    double a_2=2;
    double b_0=2;
    double b_1=2;
    double b_2=2;
    double b_3=2;

    double TemporaryMatrix0[3][3];
    double TemporaryMatrix1[3][3];

    double wybor (double t, char wybor_wejscia );

    void wypelnianie_macierzy();

    void MatrixMultiplication (double Matrix1[3][3], double Matrix2[3][3], double outMatrix[3][3]);
    void MatrixAdd(double Matrix1[3][3], double Matrix2[3][3], double outMatrix[3][3]);
    void MatrixTransposition (double inMatrix1[3][3], double outMatrix[3][3]);
    double Wyznacznik (double a, double b, double c, double d);
    void MatrixInverse (double inMatrix[3][3], double outMatrix[3][3]);
    void MatrixConstMult(double inMatrix[3][3], double mnoznik, double outMatrix[3][3]);
    void wypelnijMacierzDX (double t);

    void calkowanie ();
    double wyliczanie_wyjscia (double t);

    char typ_wejscia;

    QtCharts::QLineSeries *obliczaneDane;
};



#endif // MATH_H
