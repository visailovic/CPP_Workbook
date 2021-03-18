#include <iostream>
#include <math.h>
using namespace std;

class Complex
{
private:
    double m_real;
    double m_imag;

public:
    Complex()
    {

    }
    Complex(double realPart, double imagPart)
    {
        m_real = realPart;
        m_imag = imagPart;
    }
    ~Complex()
    {
    }

    /*   double GetRealPart(){return m_real;}*/
    void SetRealPart(double realPart)
    {
        m_real = realPart;
    }

    /*   double GetImagPart(){return m_imag;}*/
    void SetImagPart(double imagPart)
    {
        m_imag = imagPart;
    }

    void Print()
    {
        cout << "Real part: " << m_real << endl;
        cout << "Imaginary part: " << m_imag << endl << endl;
    }

    Complex Add(const Complex& other)
    {
        double real = m_real + other.m_real;
        double imag = m_imag + other.m_imag;
        Complex res(real, imag);
        return res;
        //      return Complex(real, imag);
    }

    Complex multiply(const Complex& other)
    {
        double real = m_real * other.m_real - m_imag * other.m_imag;
        double imag = m_real * other.m_imag + m_imag * other.m_real;

        return Complex(real, imag);
    }

    Complex divide(const Complex& other)
    {
        double tmp = pow(other.m_real, 2.0) + pow(other.m_imag, 2.0);
        double real = (m_real * other.m_real + m_imag * other.m_imag) / tmp;
        double imag = (m_imag * other.m_real - m_real * other.m_imag) / tmp;

        return Complex(real, imag);
    }
};

int main()
{
    double real, imag;

    cout << "For first complex number \n";
    cout << "Enter real and imaginary part respectively:\n";
    cin >> real >> imag;
    Complex z1(real, imag);

    cout << "For second complex number \n";
    cout << "Enter real and imaginary part respectively:\n";
    cin >> real >> imag;
    Complex z2(real, imag);

    Complex product = z1.multiply(z2);
    Complex quotient = product.divide(z2);

    product.Print();
    quotient.Print();
    z1.Print();

    return 0;
}
