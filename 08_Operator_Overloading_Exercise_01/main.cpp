class Vector
{
private:
    double m_x, m_y, m_z;
public:
    Vector(double x, double y, double z) : m_x(x), m_y(y), m_z(z) {};

    const Vector& operator=(const Vector& other)
    {
        m_x = other.m_x;
        m_y = other.m_y;
        m_z = other.m_z;
        return *this;
    }

    const Vector& operator+=(const Vector& other)
    {
        m_x += other.m_x;
        m_y += other.m_y;
        m_z += other.m_z;
        return *this;
    }

    const Vector& operator-=(const Vector& other)
    {
        m_x -= other.m_x;
        m_y -= other.m_y;
        m_z -= other.m_z;
        return *this;
    }

    Vector operator+(const Vector& other)
    {
        return Vector(m_x + other.m_x, m_y + other.m_y, m_z + other.m_z);
    }

    Vector operator-(const Vector& other)
    {
        return Vector(m_x - other.m_x, m_y - other.m_y, m_z - other.m_z);
    }

    Vector operator-()
    {
        return Vector(-m_x, -m_y, -m_z);
    }

    Vector operator+()
    {
        return *this;
    }

    Vector Cross(const Vector& other)
    {
        return Vector(m_y * other.m_z - m_z * other.m_y,
            m_z * other.m_x - m_x * other.m_z,
            m_x * other.m_y - m_y * other.m_x);
    }

    double Dot(Vector& other)
    {
        return m_x * other.m_x + m_y * other.m_y + m_z * other.m_z;
    }
};

int main()
{
    Vector A(1, 2, 3);
    Vector B(3, 2, 1);

    Vector C = A += B;

    Vector D = A.Cross(+B);
    Vector E = A.Cross(-B);
    double a = A.Dot(B);
    double b = (A + B).Dot(C);
    double c = A.Cross(B).Dot(C);
    double d = (-A - B).Dot(C);
}
