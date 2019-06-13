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

/* double Math::wyliczanie_wyjscia (double t)
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
    MatrixConstMult(MatrixB, rectangle1(t, typ_wejscia), TemporaryMatrix1);
    MatrixAdd(TemporaryMatrix0, TemporaryMatrix1, dxMatrix);
}


void Math::calkowanie()
{
    MatrixConstMult(dxMatrix, 0.01, TemporaryMatrix0);
    MatrixAdd(TemporaryMatrix0, MatrixX, MatrixX);
}
*/
