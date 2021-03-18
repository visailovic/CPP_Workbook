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

    double DotProduct(const Vector& other)
    {
        double res = m_x * other.m_x + m_y * other.m_y + m_z * other.m_z;

        return res;
    }

    Vector CrossProduct(const Vector& other)
    {
        Vector res;

        res.m_x = m_y * other.m_z - m_z * other.m_y;
        res.m_y = m_z * other.m_x - m_x * other.m_z;
        res.m_z = m_x * other.m_y - m_y * other.m_x;

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

    Vector crossProduct = v1.CrossProduct(v2);
    double dotProduct = v1.DotProduct(v2);

    cout << endl << "Cross product: " << endl;
    crossProduct.Print();

    cout << endl << "Dot product: " << dotProduct << endl;

    return 0;
}
