#include <iostream>

#define MAX_NUM_OF_STUDENTS 50
#define MAX_NAME_SiZE 20

using namespace std;

struct Student
{
    char name[MAX_NAME_SiZE];
    char surname[MAX_NAME_SiZE];
    int ID;
    int classYear;
};

void PrintInfo(Student S)
{
    cout << S.name << " ";
    cout << S.surname << endl;
    cout << S.ID << "\/";
    cout << S.classYear << endl << endl;
}

int main()
{
    Student arrayOfStudents[MAX_NUM_OF_STUDENTS];

    cout << "Enter the number of students: ";

    int numberOfStudents = 0;
    cin >> numberOfStudents;

    if (numberOfStudents > MAX_NUM_OF_STUDENTS)
    {
        cout << "Max number of studenats is 50!";
        return 0;
    }

    for (int i = 0; i < numberOfStudents; i++)
    {
        cout << endl;
        cout << "Enter name, surname, ID number and class year: " << endl;

        cout << "Name: " << endl;
        cin >> arrayOfStudents[i].name;

        cout << "Surname: " << endl;
        cin >> arrayOfStudents[i].surname;

        cout << "ID number: " << endl;
        cin >> arrayOfStudents[i].ID;

        cout << "Class year: " << endl;
        cin >> arrayOfStudents[i].classYear;
    }

    Student oneStudent = arrayOfStudents[0];
    int theOldestClassYear = oneStudent.classYear;

    for (int i = 1; i < numberOfStudents; i++)
    {
        oneStudent = arrayOfStudents[i];

        if (oneStudent.classYear < theOldestClassYear)
        {
            theOldestClassYear = oneStudent.classYear;
        }
    }
    cout << endl << endl << endl;
    cout << "Students from the oldest generation are: " << endl << endl;
    for (int i = 0; i < numberOfStudents; i++)
    {
        oneStudent = arrayOfStudents[i];

        if (oneStudent.classYear == theOldestClassYear) PrintInfo(oneStudent);
    }

    return 0;
}
