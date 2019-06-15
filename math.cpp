#include "math.h"

Math::Math()
{
wypelnianie_macierzy();

}

double Math::ProstokatInput(double x)
{
    int faza= int(x)%Tinput;
    if(faza<Tinput/2)
    {
        return 1;
    }
    return -1;
}

double Math::SinusInput(double i)
{
    return sin(2*pi*i/Tinput);
}

double Math::SkokInput(double i)
{
    if(i>0)
        return 1;
    return 0;
}

double Math::wybor (double t, char wybor_wejscia)
{
    if(wybor_wejscia=='p')
    {
        return ProstokatInput(t);
    }

    if(wybor_wejscia=='h')
    {
        return SkokInput(t);
    }
    if(wybor_wejscia=='s')
    {
        return SinusInput(t);
    }
    return 1
            ;
}

void Math::wypelnianie_macierzy()
{
    MatrixA[0][0]=0; MatrixA[0][1]=0; MatrixA[0][2]=a_0;
    MatrixA[1][0]=1; MatrixA[1][1]=0; MatrixA[1][2]=a_1;
    MatrixA[2][0]=0; MatrixA[2][1]=1; MatrixA[2][2]=a_2;

    MatrixB[0][0]=b_0; MatrixB[0][1]=a_0*b_3; MatrixB[0][2]=0;
    MatrixB[1][0]=b_1; MatrixB[1][1]=a_1*b_3; MatrixB[1][2]=0;
    MatrixB[2][0]=b_2; MatrixB[2][1]=a_2*b_3; MatrixB[2][2]=0;

    MatrixC[0][0]=0; MatrixC[0][1]=0; MatrixC[0][2]=1;
    MatrixC[1][0]=0; MatrixC[1][1]=0; MatrixC[1][2]=0;
    MatrixC[2][0]=0; MatrixC[2][1]=0; MatrixC[2][2]=0;

    MatrixD[0][0]=b_3; MatrixD[0][1]=0; MatrixD[0][2]=0;
    MatrixD[1][0]=0;   MatrixD[1][1]=0; MatrixD[1][2]=0;
    MatrixD[2][0]=0;   MatrixD[2][1]=0; MatrixD[2][2]=0;

    MatrixX[0][0]=MatrixX[0][1]=MatrixX[0][2]=0;
    MatrixX[1][0]=MatrixX[1][1]=MatrixX[1][2]=0;
    MatrixX[2][0]=MatrixX[2][1]=MatrixX[2][2]=0;

}

void Math:: MatrixMultiplication(double (*Matrix1)[3], double(*Matrix2)[3] , double (*outMatrix)[3])
{

    double s;
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++){
            s=0;
            for(int k=0; k<3; k++)
            {
                s += Matrix1[i][k] * Matrix2[k][j];
                outMatrix[i][j]=s;
            }
        }
    }
}

void Math:: MatrixAdd (double (*Matrix1)[3], double(*Matrix2)[3] , double (*outMatrix)[3])
{
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            outMatrix[i][j]=Matrix1[i][j]+Matrix2[i][j];
        }
    }
}

void Math::MatrixConstMult(double (*inMatrix)[3], double mnoznik, double (*outMatrix)[3])
{
    {
        for (int i=0; i<3; i++)
        {
            for (int j=0; j<3; j++)
            {
                outMatrix[i][j]=mnoznik * inMatrix[i][j];
            }
        }
    }
}

void Math:: MatrixTransposition (double (*inMatrix)[3],  double (*outMatrix)[3])
{

    outMatrix[0][0]=inMatrix[0][0];
    outMatrix[0][1]=inMatrix[1][0];
    outMatrix[0][2]=inMatrix[2][0];

    outMatrix[1][0]=inMatrix[0][1];
    outMatrix[1][1]=inMatrix[1][1];
    outMatrix[1][2]=inMatrix[2][1];

    outMatrix[2][0]=inMatrix[0][2];
    outMatrix[2][1]=inMatrix[1][2];
    outMatrix[2][2]=inMatrix[2][2];

}

double Math::Wyznacznik (double a,double b,double c, double d)
{
    return a*d-b*c;
}

void Math::MatrixInverse (double (*inMatrix)[3],  double (*outMatrix)[3])
{
    double det = inMatrix[0][0]*inMatrix[1][1]*inMatrix[2][2]+inMatrix[1][0]*inMatrix[2][1]*inMatrix[0][2]+inMatrix[2][0]*inMatrix[0][1]*inMatrix[1][2]-inMatrix[2][0]*inMatrix[1][1]*inMatrix[0][2]-inMatrix[2][2]*inMatrix[1][0]*inMatrix[0][1]-inMatrix[0][0]*inMatrix[2][1]*inMatrix[1][2];
    outMatrix[0][0]=1/det*Wyznacznik(inMatrix[1][1],inMatrix[1][2],inMatrix[2][1],inMatrix[2][2]);
    outMatrix[0][1]=-1/det*Wyznacznik(inMatrix[0][1],inMatrix[0][2],inMatrix[2][1],inMatrix[2][2]);
    outMatrix[0][2]=1/det*Wyznacznik(inMatrix[0][1],inMatrix[0][2],inMatrix[1][1],inMatrix[1][2]);
    outMatrix[1][0]=-1/det*Wyznacznik(inMatrix[1][0],inMatrix[1][2],inMatrix[2][0],inMatrix[2][2]);
    outMatrix[1][1]=1/det*Wyznacznik(inMatrix[0][0],inMatrix[0][2],inMatrix[2][0],inMatrix[2][2]);
    outMatrix[1][2]=-1/det*Wyznacznik(inMatrix[0][0],inMatrix[0][2],inMatrix[1][0],inMatrix[1][2]);
    outMatrix[2][0]=1/det*Wyznacznik(inMatrix[1][0],inMatrix[1][1],inMatrix[2][0],inMatrix[2][1]);
    outMatrix[2][1]=-1/det*Wyznacznik(inMatrix[0][0],inMatrix[0][1],inMatrix[2][0],inMatrix[2][1]);
    outMatrix[2][2]=1/det*Wyznacznik(inMatrix[0][0],inMatrix[0][1],inMatrix[1][0],inMatrix[1][1]);
}

void Math::TransformataOdwrotna()
{
    for(int i=0; i<numberOfPoints; i++){
        double t= i*step;
        outputData[i]=wyliczanie_wyjscia(t);
    }
}

double Math::checkMaksimum()
{
    double maksimumY=0;
    for (int i=0; i<numberOfPoints; i++)
    {
        if(outputData[i]>maksimumY)
        {
            maksimumY=outputData[i];
        }
    }
    return maksimumY;
}

double Math::checkMinimum()
{
    double minimum=0;
    for (int i=0; i<numberOfPoints; i++)
    {
        if(outputData[i]<minimum)
        {
            minimum=outputData[i];
        }
    }
    return minimum;
}

 double Math::wyliczanie_wyjscia (double t)
{
    double wyjscie;
    wypelnijMacierzDX(t);
    calkowanie();
    MatrixMultiplication(MatrixC, MatrixX, outputMatrix);
    wyjscie=outputMatrix[0][0];
    return wyjscie;
}

void Math::wypelnijMacierzDX(double t)
{
    MatrixMultiplication(MatrixA, MatrixX, TemporaryMatrix0);
    MatrixConstMult(MatrixB, wybor(t, typ_wejscia), TemporaryMatrix1);
    MatrixAdd(TemporaryMatrix0, TemporaryMatrix1, dxMatrix);
}


void Math::calkowanie()
{
    MatrixConstMult(dxMatrix, 0.01, TemporaryMatrix0);
    MatrixAdd(TemporaryMatrix0, MatrixX, MatrixX);
}

std::complex<double> Math::transmitationFun(double omega) // -------------- funkcja zerżnieta od dziewczyn, używamy jej w charakterystyce amplitudowej
{
    std::complex<double> licznik;
    std::complex<double> mianownik;
    std::complex<double> j(0,1);
    std::complex<double> jeden(1,0);
    std::complex<double> expo(e,0);
    licznik = b_3*j*j*j*omega*omega*omega + b_2*j*j*omega*omega + b_1*j*omega + b_0;  // ------ nasza transmitancja (nie zbyt prosta)
    mianownik = j*j*j*omega*omega*omega + a_2*j*j*omega*omega + a_1*j*omega + a_0;

//    licznik = b_1*j*omega + b_0;                    // -------- najprostrzy przykład transmitancji
//    mianownik = j*j*omega*omega + a_1*j*omega+a_0;

    std::complex<double> G;
    G = (licznik/mianownik);

   return G/(jeden-G);

}

void Math::charakterystyka_amplitudowa()    // ------------------ funkcja licząca charakterystykę aplitudową
{
    maksimumRange = -10000;
    minimumRange = 10000;
    obliczaneDane = new QLineSeries();
       std::complex<double> yValue;
       double amplitude;
       for(double omega = 0.1; omega < 10000 ; omega += 0.1){

               yValue = transmitationFun(omega);
               amplitude = 20*log(abs(yValue));
               obliczaneDane->append(omega,amplitude);
               max_min_charakterystyki(AMPLITUDE, amplitude);

       }
}

void Math::max_min_charakterystyki(int type, double value) // ---------------- ta fukncja sprawdza jakie są min i max charakterystyk
{                                                       //                  wtedy można lepiej dopasować skalę
    if(value < minimumRange){
        minimumRange = value;
    }
    if(value > maksimumRange){
        maksimumRange = value;
        maksimumRange = (floor((maksimumRange/type))+1)*type;

        if(maksimumRange<=0){
            switch(type){
            case AMPLITUDE:
                maksimumRange = 20;
                break;
         /*   case PHASE:
                maksimumRange = 45; // ------------- póki co nie robimy jeszcze charakerystyki fazowej
                break;                  */
            }
        }
    }

    if (minimumRange<0)
        minimumRange = (floor((minimumRange/type)))*type;
    else
        minimumRange = (floor((minimumRange/type))+1)*type;

}
