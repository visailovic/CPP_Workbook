#include <iostream>
#include <cmath>
#define PI 3.1415926535897932384626433832795
using namespace std;

struct Point_X_Y_Z
{
    double x;
    double y;
    double z;
};

struct Point_r_phi_theta
{
    double r;
    double phi;
    double theta;
};

Point_X_Y_Z SphericalToCartesian(Point_r_phi_theta pointSpherical)
{
    Point_X_Y_Z pointCartesian;

    pointCartesian.x = pointSpherical.r * sin(pointSpherical.theta) * cos(pointSpherical.phi);
    pointCartesian.y = pointSpherical.r * sin(pointSpherical.theta) * sin(pointSpherical.phi);
    pointCartesian.z = pointSpherical.r * cos(pointSpherical.theta);

    return pointCartesian;
}

Point_r_phi_theta CartesianToSpherical(Point_X_Y_Z pointCartesian)
{
    Point_r_phi_theta pointSpherical;

    pointSpherical.r = sqrt(pow(pointCartesian.x, 2) + pow(pointCartesian.y, 2) + pow(pointCartesian.z, 2));
    pointSpherical.phi = atan(pointCartesian.y / pointCartesian.x);
    pointSpherical.theta = acos(pointCartesian.z / pointSpherical.r);

    return pointSpherical;
}

int main()
{
    Point_X_Y_Z cartesianPoint;
    Point_r_phi_theta sphericalPoint;

    cout << "Enter coordinates of cartesian point (X, Y, Z):" << endl << endl;

    cin >> cartesianPoint.x;
    cin >> cartesianPoint.y;
    cin >> cartesianPoint.z;

    sphericalPoint = CartesianToSpherical(cartesianPoint);

    cout << "Entered point has the folowing spherical coordinates:" << endl << endl;

    cout << "r = " << sphericalPoint.r << endl;
    cout << "phi = " << sphericalPoint.phi << endl;
    cout << "theta = " << sphericalPoint.theta << endl;


    cout << endl << endl << endl << endl;


    cout << "Enter coordinates of spherical point (r, phi, theta):" << endl << endl;

    bool bAgain;
    do
    {
        cin >> sphericalPoint.r;
        cin >> sphericalPoint.phi;
        cin >> sphericalPoint.theta;

        bAgain = false;

        if (sphericalPoint.r < 0.0 ||
            sphericalPoint.phi < 0.0 || sphericalPoint.phi > PI ||
            sphericalPoint.theta < 0.0 || sphericalPoint.theta > 2.0 * PI)
        {
            cout << "Some of coordinates is wrong. Please, enter again." << endl;
            bAgain = true;
        }
    } while (bAgain);

    cartesianPoint = SphericalToCartesian(sphericalPoint);

    cout << "Entered point has the folowing Cartesian coordinates:" << endl << endl;

    cout << "x = " << cartesianPoint.x << endl;
    cout << "y = " << cartesianPoint.y << endl;
    cout << "z = " << cartesianPoint.z << endl;

    return 0;
}
