#include <iostream>

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

int main()
{
    Complex z1, z2, res;

    cout << "For first complex number \n";
    cout << "Enter real and imaginary part respectively:\n";
    cin >> z1.real >> z1.imag;

    cout << "For second complex number \n";
    cout << "Enter real and imaginary part respectively:\n";
    cin >> z2.real >> z2.imag;

    res = add(z1, z2);

    cout << endl << "Result: " << endl;
    cout << "Real part: " << res.real << endl;
    cout << "Imaginary part: " << res.imag << endl << endl;

    return 0;
}
