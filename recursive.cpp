
#include <iostream>
using namespace std;

struct Person {
    string name;
    int number;
};

void sortDescending(Person people[], int size) {
    if (size <= 1) return;


    for (int i = 1; i < size; i++) {
        if (people[0].number < people[i].number) {

            Person temp = people[0];
            people[0] = people[i];
            people[i] = temp;
        }
    }


    sortDescending(people + 1, size - 1);
}


int main() {
    int size;

    cout << "Enter the number of people: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid size. Exiting program." << endl;
        return 1;
    }


    Person* people = new Person[size];


    for (int i = 0; i < size; i++) {
        cout << "Enter username: ";
        cin >> people[i].name;
        cout << "Enter stars: ";
        cin >> people[i].number;
    }


    sortDescending(people, size);


    cout << "\nLeaderboard:\n";
    for (int i = 0; i < size; i++) {
        cout << people[i].name <<  " (" << people[i].number << " stars)\n";
    }


    delete[] people;

    return 0;
}
