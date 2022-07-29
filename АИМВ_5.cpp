#include <iostream>
#include <math.h>

using namespace std;

class Integral
{
private:
    double a, b;
    double h;
    int n;
    double* x;
    double* y;

public:

    Integral()
    {

        cout << "Введите начало интервала:";
        cin >> a;
        cout << "Введите конец интервала:";
        cin >> b;

        n = 9;
       
        h = (b - a) / 8;

        x = new double[n];
        y = new double[n];

    }

    void FilingArrays()
    {

        x[0] = a;
        y[0] = pow(x[0], 3)/(pow(x[0],8)+3);

        for (int i = 1; i < n; i++)
        {
            x[i]  = x[i-1] + h;
            y[i] = pow(x[i], 3) / (pow(x[i], 8) + 3);

        }

    }

    void DisplayArrays()
    {
        cout.precision(5);

        cout << "X" << "         " << "Y" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << x[i] << "\t" << y[i] << endl;
        }

    }

    double  IntegralCounting()
    {
        double integral = 0;
        for (int i = 0; i < n-1; i++)
        {
            
            integral += ((y[i] + y[i+1]) / 2) * h;

        }

        return integral;
    }


    void FinaleResult()
    {

        double integr = IntegralCounting();

        cout << "Численное значение интеграла на отрезке [" << a << ";" << b << "]:" << integr << endl;
        double absol,otnos;
        double ist;

        ist = (sqrt(3) * atan((sqrt(3) * pow(b, 4)) / 3) / 12) - (sqrt(3) * atan((sqrt(3) * pow(a, 4)) / 3) / 12);

        absol = abs(integr - ist);
        otnos = (absol / ist) * 100;

        cout << "Истинное значение:" << ist << endl;
        cout << "Абсолютная погрешность:" << absol<<endl;
        cout << "Относительная погрешность:" << otnos;

    }

    ~Integral()
    {
        delete[]x;
        delete[]y;
    }

};


int main()
{
    setlocale(LC_ALL, "Russian");
    Integral My;

    My.FilingArrays();
    My.DisplayArrays();
    My.FinaleResult();

}


