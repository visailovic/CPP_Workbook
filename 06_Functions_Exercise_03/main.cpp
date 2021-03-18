struct Angle
{
    int degree;
    int minute;
    int second;
};

Angle AddAngle(Angle angle1, Angle angle2)
{
    Angle sum;

    sum.second = angle1.second + angle2.second;
    sum.minute = angle1.minute + angle2.minute;
    sum.degree = angle1.degree + angle2.degree;

    if (sum.second >= 60)
    {
        sum.minute += sum.second / 60;
        sum.second %= 60;
    }

    if (sum.minute >= 60)
    {
        sum.degree += sum.minute / 60;
        sum.minute %= 60;
    }
    return sum;
}

int main()
{
    Angle a = { 5, 21, 12 };
    Angle b = { 0, 59, 31 };
    Angle c = AddAngle(a, b);

    return 0;
}
