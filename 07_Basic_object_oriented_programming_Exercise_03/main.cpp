#include <iostream>
using namespace std;

class Vector
{
private:
    double m_x, m_y, m_z;
public:
    Vector() {}
    Vector(double x, double y, double z) { Set(x, y, z); }
    ~Vector() {}

    void Set(double x, double y, double z) { m_x = x;   m_y = y; m_z = z; }

    double GetX() { return m_x; }
    double GetY() { return m_y; }
    double GetZ() { return m_z; }

    void ReadVectorFromConsole()
    {
        cout << "X component, Y component, Z component: " << endl;
        cin >> m_x >> m_y >> m_z;
    }

    void Print()
    {
        cout << "Components: X = " << m_x << "   Y = " << m_y << "   Z = " << m_z << endl;
    }

    Vector Add(const Vector& other)
    {
        Vector res;
        res.Set(m_x + other.m_x, m_y + other.m_y, m_z + other.m_z);
        return res;
    }
};

int main()
{
    Vector v1, v2;

    cout << "Enter Components of vector 1: " << endl << endl;
    v1.ReadVectorFromConsole();
    cout << "Enter Components of vector 2: " << endl << endl;
    v2.ReadVectorFromConsole();

    Vector result = v1.Add(v2);

    cout << endl << "Components of result vector are: " << endl;
    result.Print();

    return 0;
}
