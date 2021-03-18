#include <iostream>
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
};

int main()
{
    Complex n1, n2, res;
    double real, imag;

    cout << "For first complex number \n";
    cout << "Enter real and imaginary part respectively:\n";
    cin >> real >> imag;

    n1.SetRealPart(real);
    n1.SetImagPart(imag);
    //   Complex n1(real, imag);

    cout << "For second complex number \n";
    cout << "Enter real and imaginary part respectively:\n";
    cin >> real >> imag;

    n2.SetRealPart(real);
    n2.SetImagPart(imag);
    //   Complex n1(real, imag);

    res = n1.Add(n2);

    cout << endl << "Result: " << endl;

    res.Print();

    return 0;
}
