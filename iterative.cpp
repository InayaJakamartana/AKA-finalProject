#include <iostream>
using namespace std;

struct User {
    string username;
    int stars;
};

void iterativeSort(User users[], int n);


void iterativeSort(User users[], int n) {
    for (int i = 0; i < n - 1; ++i) {

        int maxIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (users[j].stars > users[maxIndex].stars) {
                maxIndex = j;
            }
        }

        User temp = users[i];
        users[i] = users[maxIndex];
        users[maxIndex] = temp;
    }
}


int main() {
    int n;
    cout << "Enter the number of users: ";
    cin >> n;

    User users[n];

    if (users <= 0) {
        cout << "Invalid size. Exiting program." << endl;
        return 1;
    }


    for (int i = 0; i < n; ++i) {
        cout << "Enter username: ";
        cin >> users[i].username;
        cout << "Enter stars: ";
        cin >> users[i].stars;
    }


    iterativeSort(users, n);


    cout << "\nLeaderboard:\n";
    for (int i = 0; i < n; ++i) {
        cout << users[i].username << " (" << users[i].stars << " stars)\n";
    }

    return 0;
}
