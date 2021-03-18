#include <iostream>
using namespace std;

struct TimeInterval
{
    int hours;
    int minutes;
    int seconds;
};

void PrintTimeInterval(TimeInterval timeInterval)
{
    cout << "Length of interval: " << timeInterval.hours << ":" << timeInterval.minutes << ":" << timeInterval.seconds << endl;
}

TimeInterval addTimeInterval(TimeInterval time1, TimeInterval time2)
{
    int s = time1.seconds + time2.seconds;
    int m = time1.minutes + time2.minutes;
    int h = time1.hours + time2.hours;

    if (s >= 60) m = m + s / 60;
    s = s % 60;

    if (m >= 60) h = h + m / 60;
    m = m % 60;

    TimeInterval t = { h, m, s };
    return t;
}

int main()
{
    TimeInterval sum = { 0, 0, 0 };
    TimeInterval tmp;

    for (int i = 0; i < 10; i++)
    {
        cout << "Enter interval " << i + 1 << ":" << endl << endl;

        cout << "Hours: ";
        cin >> tmp.hours;
        cout << "Minutes: ";
        cin >> tmp.minutes;
        cout << "Seconds: ";
        cin >> tmp.seconds;

        if (tmp.hours == 0 && tmp.minutes == 0 && tmp.seconds == 0) break;

        sum = addTimeInterval(sum, tmp);
    }

    PrintTimeInterval(sum);

    return 0;
}
