#include <iostream>
#include <math.h>

#define MAX_NUM_OF_CYRCLES 5

using namespace std;

struct Point
{
    double x;
    double y;
};

struct Circle
{
    Point center;
    double radius;
};

double Distance(Point P1, Point P2)
{
    double distance = sqrt(pow(P1.x - P2.x, 2) + pow(P1.y - P2.y, 2));
    return distance;
}

bool IsPointInSomeCircle(Point point, Circle circles[], int numberOfCircles)
{
    for (int i = 0; i < numberOfCircles; i++)
    {
        Circle circle = circles[i];
        double distance = Distance(point, circle.center);

        if (distance < circle.radius)
        {
            return true;
        }
    }

    return false;
}

bool CheckCrossing(Circle newCyrcle, Circle cyrcles[], int numberOfCircles)
{
    for (int i = 0; i < numberOfCircles; i++)
    {
        double distance = Distance(newCyrcle.center, cyrcles[i].center);

        if (distance <= (newCyrcle.radius + cyrcles[i].radius))
        {
            return true;
        }
    }
    return false;
}

void WriteCircles(Circle circles[], int numberOfCircles)
{
    for (int i = 0; i < 50; i++)
    {
        double x = 2.0 * i;
        for (int j = 0; j < 50; j++)
        {
            double y = 2.0 * j;
            Point P = { x, y };
            if (IsPointInSomeCircle(P, circles, numberOfCircles))
            {
                cout << "  "; // double space
            }
            else
            {
                cout << "x "; // x and space
            }
        }
        cout << endl;
    }
}

int main()
{
    char answer = 'y';
    int circleCounter = 0;

    Circle circles[MAX_NUM_OF_CYRCLES];
    Circle newCircle;

    do
    {
        cout << "Enter new circle:" << endl;
        cout << "X coord of center:" << endl;
        cin >> newCircle.center.x;
        cout << "Y coord of center:" << endl;
        cin >> newCircle.center.y;
        cout << "Radius of circle:" << endl;
        cin >> newCircle.radius;

        if (!CheckCrossing(newCircle, circles, circleCounter) &&
            newCircle.center.x > 0.0 && newCircle.center.x < 100.0 &&
            newCircle.center.y > .0 && newCircle.center.y < 100.0)
        {
            circles[circleCounter++] = newCircle;
            if (!(circleCounter < MAX_NUM_OF_CYRCLES))
            {
                cout << "Max number of circles is reached!" << endl;
                break;
            }
        }
        else
        {
            cout << "Data about cyrcle are not correct!" << endl;
            cout << "Enter circle again" << endl;
            continue;
        }
        cout << "Add new circle? Enter 'Y' if answer is YES, otherwise 'N'?";
        cin >> answer;
    } while (answer == 'Y' || answer == 'y');

    WriteCircles(circles, circleCounter);

    return 0;
}
