#include <iostream>
#include <ctype.h>

#define MAX_NAME_SIZE         20
#define MAX_PHONE_NUMBER_SIZE   15

using namespace std;

struct Contact
{
    char name[MAX_NAME_SIZE];
    char surname[MAX_NAME_SIZE];
    char phone[MAX_PHONE_NUMBER_SIZE];
};

void ReadContact(Contact* pContact)
{
    cout << endl;
    cout << "Enter the data for new contact:" << endl;
    cout << "Enter the name, surname and phone number: " << endl;
    cin >> pContact->name >> pContact->surname >> pContact->phone;
}

void PrintContacts(Contact* arrayOfContacts, int size)
{
    cout << endl << endl << endl;

    for (int i = 0; i < size; i++) cout << arrayOfContacts[i].surname << "\t\t" <<
        arrayOfContacts[i].name << "\t\t" <<
        arrayOfContacts[i].phone << endl;
}

bool ShouldChangeOrder(Contact contact1, Contact contact2)
{
    for (int i = 0; i < MAX_NAME_SIZE; i++)
    {
        char c1 = toupper(contact1.surname[i]);
        char c2 = toupper(contact2.surname[i]);
        if (c2 < c1) return true;
        if (c2 > c1) return false;
    }
    for (int i = 0; i < MAX_NAME_SIZE; i++)
    {
        char c1 = toupper(contact1.name[i]);
        char c2 = toupper(contact2.name[i]);
        if (c2 < c1) return true;
        if (c2 > c1) return false;
    }
    return false;
}

void SortContactArray(Contact* arrayOfContacts, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (ShouldChangeOrder(arrayOfContacts[i], arrayOfContacts[j]))
            {
                Contact tmp = arrayOfContacts[i];
                arrayOfContacts[i] = arrayOfContacts[j];
                arrayOfContacts[j] = tmp;
            }
        }
    }
}

int main()
{
    cout << "Enter the number of contacts :" << endl;
    int numberOfContacts = 0;
    cin >> numberOfContacts;

    Contact* arrayOfContacts = new Contact[numberOfContacts];

    if (!arrayOfContacts)
    {
        cout << "Something went wrong with memory allocation!";
        return -1;
    }

    for (int i = 0; i < numberOfContacts; i++)
    {
        ReadContact(&arrayOfContacts[i]);
    }

    SortContactArray(arrayOfContacts, numberOfContacts);

    PrintContacts(arrayOfContacts, numberOfContacts);

    if (arrayOfContacts) delete[] arrayOfContacts;

    return 0;
}
