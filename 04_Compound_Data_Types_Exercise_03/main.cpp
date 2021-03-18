#include <iostream>
#include <math.h>

using namespace std;

struct Complex
{
    double real;
    double imag;
};

Complex add(Complex number1, Complex number2)
{
    Complex result;

    result.real = number1.real + number2.real;
    result.imag = number1.imag + number2.imag;

    return(result);
}

Complex multiply(Complex number1, Complex number2)
{
    Complex result;

    result.real = number1.real * number2.real - number1.imag * number2.imag;
    result.imag = number1.real * number2.imag + number1.imag * number2.real;

    return(result);
}

Complex divide(Complex number1, Complex number2)
{
    Complex result;

    double tmp = pow(number2.real, 2.0) + pow(number2.imag, 2.0);

    result.real = (number1.real * number2.real + number1.imag * number2.imag) / tmp;
    result.imag = (number1.imag * number2.real - number1.real * number2.imag) / tmp;

    return(result);
}

int main()
{
    Complex z1, z2, res;

    cout << "For first complex number \n";
    cout << "Enter real and imaginary part respectively:\n";
    cin >> z1.real >> z1.imag;

    cout << "For second complex number \n";
    cout << "Enter real and imaginary part respectively:\n";
    cin >> z2.real >> z2.imag;

    Complex product = multiply(z1, z2);
    Complex quotient = divide(product, z2);

    //  Test
    cout << "Real: " << product.real << " Imag: " << product.imag << endl;
    cout << "Real: " << quotient.real << " Imag: " << quotient.imag << endl;
    cout << "Real: " << z1.real << " Imag: " << z1.imag << endl;

    return 0;
}
