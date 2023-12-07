#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;


struct Zodiac {
    string lastName;
    string firstName;
    string zodiacSign;
    int birthDate[3]; 
};


void inputZodiacData(Zodiac* people, int size) {
    
    for (int i = 0; i < size; ++i) {
        cout << "Enter data for person #" << i + 1 << ":" << endl;
        cout << "Last Name: ";
        cin >> people[i].lastName;

        cout << "First Name: ";
        cin >> people[i].firstName;

        cout << "Zodiac Sign: ";
        cin >> people[i].zodiacSign;

        cout << "Birth Date (day month year): ";
        cin >> people[i].birthDate[0] >> people[i].birthDate[1] >> people[i].birthDate[2];
    }
}


void sortZodiacArray(Zodiac* people, int size) {
    
    sort(people, people + size, [](const Zodiac& a, const Zodiac& b) {
        return a.lastName < b.lastName;
        });
}


void printPeopleByZodiac(Zodiac* people, int size, const string& targetZodiacSign) {
    bool found = false;

    cout << "People born under the sign " << targetZodiacSign << ":" << endl;

    
    for (int i = 0; i < size; ++i) {
        if (people[i].zodiacSign == targetZodiacSign) {
            found = true;
            cout << people[i].lastName << " " << people[i].firstName << endl;
        }
    }

    
    if (!found) {
        cout << "No people found with this Zodiac sign." << endl;
    }
}


void readZodiacArrayFromFile(Zodiac* people, int size, const string& filename) {
    ifstream file(filename);

    
    if (!file.is_open()) {
        cout << "Failed to open the file for reading." << endl;
        return;
    }

    
    for (int i = 0; i < size; ++i) {
        file >> people[i].lastName >> people[i].firstName >> people[i].zodiacSign >>
            people[i].birthDate[0] >> people[i].birthDate[1] >> people[i].birthDate[2];
    }

    file.close();
}


void writeZodiacArrayToFile(Zodiac* people, int size, const string& filename) {
    ofstream file(filename);

    
    if (!file.is_open()) {
        cout << "Failed to open the file for writing." << endl;
        return;
    }

    
    for (int i = 0; i < size; ++i) {
        file << people[i].lastName << " " << people[i].firstName << " " << people[i].zodiacSign << " "
            << people[i].birthDate[0] << " " << people[i].birthDate[1] << " " << people[i].birthDate[2] << endl;
    }

    file.close();
}

int main() {
    int size;

    
    cout << "Enter the number of people: ";
    cin >> size;

    
    Zodiac* people = new Zodiac[size];

    
    inputZodiacData(people, size);

    
    sortZodiacArray(people, size);

    
    string filename;
    cout << "Enter the file name to save data: ";
    cin >> filename;
    writeZodiacArrayToFile(people, size, filename);

   
    cout << "Enter the file name to read data from: ";
    cin >> filename;
    readZodiacArrayFromFile(people, size, filename);

    cout << "Sorted list of people by last name:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << people[i].lastName << " " << people[i].firstName << " (" << people[i].zodiacSign << ")" << endl;
    }
    string targetZodiacSign;
    cout << "Enter the Zodiac sign to search for: ";
    cin >> targetZodiacSign;
    printPeopleByZodiac(people, size, targetZodiacSign);



    return 0;
}
