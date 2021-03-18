#include <iostream>
#define MAX_NAME_OR_SURNAME_SIZE 100

using namespace std;

struct Student
{
    char* pName;
    char* pSurname;
};

int GetSize(char string[], int maxSize)
{
    for (int i = 0; i < maxSize; i++)
    {
        if (string[i] == '\0') return i;
    }
}

void CopyData(char* p1, char* p2, int length)
{
    for (int i = 0; i < length; i++)
    {
        //      p1[i] = p2[i];
        *(p1 + i) = *(p2 + i);
    }
}

void AddStudentData(int pos, Student* arrayOfStudents, char name[], char surname[],
    int nameSize, int surnameSize)
{
    Student* pStudent = &arrayOfStudents[pos];

    pStudent->pName = new char[nameSize];
    pStudent->pSurname = new char[surnameSize];

    CopyData(pStudent->pName, name, nameSize);
    CopyData(pStudent->pSurname, surname, surnameSize);
}

Student* AllocateArray(int numOfStudents)
{
    Student* pArray = new Student[numOfStudents];

    for (int i = 0; i < numOfStudents; i++)
    {
        (*(pArray + i)).pName = 0;
        (*(pArray + i)).pSurname = 0;
    }

    return pArray;
}

void DeallocateArray(Student* arrayOfStudents, int numOfStudents)
{
    for (int i = 0; i < numOfStudents; i++)
    {
        if (arrayOfStudents[i].pName) delete[] arrayOfStudents[i].pName;
        if (arrayOfStudents[i].pSurname) delete[] arrayOfStudents[i].pSurname;
    }

    if (arrayOfStudents) delete[] arrayOfStudents;
}

int main()
{
    cout << "Enter the number of students:" << endl;
    int numOfStudents = 0;
    cin >> numOfStudents;

    if (numOfStudents < 1)
    {
        cout << "You have to enter at least one student!";
        return 0;
    }

    Student* arrayOfStudents = AllocateArray(numOfStudents);

    char name[MAX_NAME_OR_SURNAME_SIZE];
    char surname[MAX_NAME_OR_SURNAME_SIZE];

    for (int i = 0; i < numOfStudents; i++)
    {
        cout << "Enter the name of student:" << i + 1 << endl << endl;
        cin >> name;

        cout << "Enter the surname of student:" << i + 1 << endl << endl;
        cin >> surname;

        int nameSize = GetSize(name, MAX_NAME_OR_SURNAME_SIZE);
        int surnameSize = GetSize(surname, MAX_NAME_OR_SURNAME_SIZE);

        AddStudentData(i, arrayOfStudents, name, surname, nameSize, surnameSize);
    }

    DeallocateArray(arrayOfStudents, numOfStudents);
}
