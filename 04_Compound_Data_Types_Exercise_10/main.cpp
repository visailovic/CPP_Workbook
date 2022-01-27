#include <iostream>

#define NUMBER_OF_MONTHS 12

using namespace std;

struct Date
{
    int day;
    int month;
    int year;
};

int GetNumberOfDaysFromMonth(int month, Date date)
{
    int numberOfDaysPerMonths[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    switch (month)
    {
    case 1:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
        return numberOfDaysPerMonths[month - 1];
    case 2:
        if (date.year % 4 == 0 && (date.year % 100 != 0 || date.year % 400 == 0))
        {
            return numberOfDaysPerMonths[1] + 1;
        }
        else
        {
            return numberOfDaysPerMonths[1];
        }
    }
}

int CalculateNumberOfDays(Date date1, Date date2)
{
    Date dateFrom = date1.year < date2.year ? date1 : date2;
    Date dateTo = date1.year < date2.year ? date2 : date1;

    if (date1.year == date2.year)
    {
        dateFrom = date1.month < date2.month ? date1 : date2;
        dateTo = date1.month < date2.month ? date2 : date1;

        if (date1.month == date2.month)
        {
            dateFrom = date1.day < date2.day ? date1 : date2;
            dateTo = date1.day < date2.day ? date2 : date1;
        }
    }

    int numberOfDays = 0;

    Date currentDate = dateFrom;

    for (int i = dateFrom.year; i <= dateTo.year; i++)
    {
        int numberOfMonths = currentDate.year == dateTo.year ?
            dateTo.month - 1 : NUMBER_OF_MONTHS;

        for (int j = currentDate.month + 1; j <= numberOfMonths; j++)
        {
            numberOfDays += GetNumberOfDaysFromMonth(j, currentDate);
        }
        currentDate.year += 1;
        currentDate.month = 0;
    }

    int days1 = GetNumberOfDaysFromMonth(dateFrom.month, dateFrom) - dateFrom.day;
    int days2 = dateTo.day;

    if (numberOfDays > 0) numberOfDays += (days1 + days2);
    else                  numberOfDays = dateTo.day - dateFrom.day;

    return numberOfDays;
}

int main()
{
    Date date1, date2;

    cout << "Enter the first date: (dd mm yy)";
    cin >> date1.day >> date1.month >> date1.year;

    cout << "Enter the second date: (dd mm yy)";
    cin >> date2.day >> date2.month >> date2.year;

    int numberOfDays = CalculateNumberOfDays(date1, date2);

    cout << "Number of days from: " << endl << endl;
    cout << date1.day << "\/" << date1.month << "\/" << date1.year << endl;
    cout << "To" << endl << endl;
    cout << date2.day << "\/" << date2.month << "\/" << date2.year << endl;
    cout << endl << "Is :" << numberOfDays << endl;

    return 0;
}
