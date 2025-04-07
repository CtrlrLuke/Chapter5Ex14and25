/*
File Name: Chapter5Ex14and25.cpp
Developer: Luke Pritchard
Date: 04/06/2025
Requirements:
- Ask the user how many students are in the class (1 to 25)
- Loop to get each student's first name
- Input valadation on names
- After all names are entered, determine which name comes first and which comes last alphabetically
- Input validation for number of students
*/

#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Function Prototypes
int GetStudentCount();
void GetStudentNames(int count, string&, string&);
bool IsValidName(const string& name);


int main()
{
    int studentCount = GetStudentCount();

    string firstInLine, lastInLine;

    GetStudentNames(studentCount, firstInLine, lastInLine);

    cout << "\nStudent at the front of the line: " << firstInLine << endl;
    cout << "Student at the end of the line: " << lastInLine << endl;

    return 0;
}

/*
   GetStudentCount
   Prompts user for number of students and validates the input (1–25)
*/
int GetStudentCount()
{
    int count;
    cout << "Enter number of students in the class (1-25): ";
    while (!(cin >> count) || count < 1 || count > 25)
    {
        cout << "ERROR: Please enter a number between 1 and 25: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear newline
    return count;
}

/*
   GetStudentNames
   Reads student names and determines who comes first and last alphabetically
*/
void GetStudentNames(int count, string& first, string& last)
{
    string name;
    cout << "\nEnter the first name of each student:\n";

    for (int i = 0; i < count; i++)
    {
        do {
            cout << "Student " << (i + 1) << ": ";
            getline(cin, name);
        } while (!IsValidName(name));

        if (i == 0)
        {
            // First student initializes both
            first = name;
            last = name;
        }
        else
        {
            if (name < first)
                first = name;
            if (name > last)
                last = name;
        }
    }
}
/*
   IsValidName
   Validates that the name is non-empty and contains only letters (no digits, no spaces, no symbols)
*/
bool IsValidName(const string& name)
{
    if (name.empty()) {
        cout << "ERROR: Name cannot be blank.\n";
        return false;
    }

    for (char c : name) {
        if (!isalpha(c)) {
            cout << "ERROR: Name must contain only letters (no spaces, symbols or numbers).\n";
            return false;
        }
    }

    return true;
}
