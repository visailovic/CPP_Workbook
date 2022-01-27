#include <iostream>

using namespace std;

struct Latitude
{
    int degree;
    int minute;
    int second;
};

typedef Latitude Longitude;

struct GeoPosition
{
    Longitude longitude;
    Latitude latitude;
    double altitude;
};

struct MeasuringPoint
{
    GeoPosition position;
    double rainPerSquareMeter;
};

void PrintDataAboutPoint(MeasuringPoint* point)
{
    cout << "Longitude: " << point->position.longitude.degree << ' ';
    cout << point->position.longitude.minute << ' ';
    cout << point->position.longitude.second << endl;
    cout << "Latitude:  " << point->position.latitude.degree << ' ';
    cout << point->position.latitude.minute << ' ';
    cout << point->position.latitude.second << endl;
    cout << "Altitude:  " << point->position.altitude << endl;
    cout << "Rain (liters per square meter):" << point->rainPerSquareMeter << endl;
}

bool ImportLongitude(Longitude* longitude)
{
    cout << "Import Longitude:" << endl;

    cout << "Degrees:" << endl;
    cin >> longitude->degree;

    cout << "Minutes:" << endl;
    cin >> longitude->minute;

    cout << "Seconds:" << endl;
    cin >> longitude->second;

    if (longitude->degree > 180 || longitude->degree < -180 ||
        longitude->minute > 60 || longitude->minute < 0 ||
        longitude->second > 60 || longitude->second < 0)
        return false;
    else
        return true;
}

bool ImportLatitude(Latitude* latitude)
{
    cout << "Import Latitude:" << endl;

    cout << "Degrees:" << endl;
    cin >> latitude->degree;

    cout << "Minutes:" << endl;
    cin >> latitude->minute;

    cout << "Seconds:" << endl;
    cin >> latitude->second;

    if (latitude->degree > 90 || latitude->degree < -90 ||
        latitude->minute > 60 || latitude->minute < 0 ||
        latitude->second > 60 || latitude->second < 0)
        return false;
    else
        return true;
}

bool ImportMeasuringPoint(MeasuringPoint* point)
{
    bool bLongitude = ImportLongitude(&point->position.longitude);
    bool bLatitude = ImportLatitude(&point->position.latitude);

    cout << "Import Altitude: " << endl;
    cin >> point->position.altitude;

    cout << "Import data about rain (amount in liters per square meter): " << endl;
    cin >> point->rainPerSquareMeter;

    return bLongitude && bLatitude;
}

void FindMinMaxPoints(MeasuringPoint* array, int size, MeasuringPoint** pMin,
    MeasuringPoint** pMax)
{
    int indexOfMin = 0, indexOfMax = 0;

    double min = array[0].rainPerSquareMeter;
    double max = array[0].rainPerSquareMeter;

    for (int i = 1; i < size; i++)
    {
        MeasuringPoint* point = &array[i];

        if (point->rainPerSquareMeter < min)
        {
            min = point->rainPerSquareMeter;
            indexOfMin = i;
        }

        if (point->rainPerSquareMeter > max)
        {
            max = point->rainPerSquareMeter;
            indexOfMax = i;
        }
    }

    *pMin = &array[indexOfMin];
    *pMax = &array[indexOfMax];
}

int main()
{
    cout << "Enter the number of measured points: " << endl;
    int measuredPointCount = 0;
    cin >> measuredPointCount;

    MeasuringPoint* measuringPointsArray = new MeasuringPoint[measuredPointCount];

    int counter = 0;
    do
    {
        cout << endl << endl << "Enter data for point: " << counter + 1 << endl;
        if (ImportMeasuringPoint(measuringPointsArray + counter))
            counter++;
        else
            cout << "Enter the point again, some of data is wrong!" << endl;

    } while (counter < measuredPointCount);

    MeasuringPoint* pointerToMin, * pointerToMax;
    FindMinMaxPoints(measuringPointsArray, measuredPointCount,
        &pointerToMin, &pointerToMax);

    cout << endl << endl;
    cout << "Max rain point: " << endl;
    PrintDataAboutPoint(pointerToMax);

    cout << "Min rain point: " << endl;
    PrintDataAboutPoint(pointerToMin);

    delete[] measuringPointsArray;

    return 0;
}
