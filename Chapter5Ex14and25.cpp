/*
File Name: Chapter5Ex14and25.cpp
Developer: Luke Pritchard
Date: 04/06/2025
Requirements:
- Open LineUp.txt and read all student names from it
- Determine who is first and last in alphabetical order
- Input validation: file must open successfully
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function Prototype
bool ReadNamesFromFile(const string& filename, string& first, string& last);

int main()
{
    string firstInLine, lastInLine;

    if (ReadNamesFromFile("LineUp.txt", firstInLine, lastInLine))
    {
        cout << "\nStudent at the front of the line: " << firstInLine << endl;
        cout << "Student at the end of the line: " << lastInLine << endl;
    }
    else
    {
        cout << "ERROR: Could not open LineUp.txt or file is empty." << endl;
    }

    return 0;
}

/*
   ReadNamesFromFile
   Opens the file, reads names line-by-line, and tracks first/last alphabetically
   Returns true if successful, false if file couldn't open or was empty
*/
bool ReadNamesFromFile(const string& filename, string& first, string& last)
{
    ifstream inputFile(filename);
    string name;

    if (!inputFile) {
        return false;
    }

    bool firstLine = true;

    while (getline(inputFile, name))
    {
        if (name.empty()) continue; // Skip blank lines

        if (firstLine)
        {
            first = last = name;
            firstLine = false;
        }
        else
        {
            if (name < first) first = name;
            if (name > last)  last = name;
        }
    }

    inputFile.close();

    return !firstLine; // Returns false if no valid names were read
}
