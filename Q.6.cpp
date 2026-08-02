#include <iostream>
using namespace std;

// part a — prints multiplication table for one number from 1 to 12
void singleTable(int num) {
    cout << "Multiplication Table for " << num << ":" << endl;
    for (int i = 1; i <= 12; i++) {
        cout << num << "  x  " << i << "  =  " << (num * i) << endl;
    }
}

// part b — prints tables for every number from 1 to n with separators
void tablesUpToN(int n) {
    for (int t = 1; t <= n; t++) {
        cout << "Multiplication Table for " << t << ":" << endl;
        for (int i = 1; i <= 12; i++) {
            cout << t << "  x  " << i << "  =  " << (t * i) << endl;
        }
        if (t < n) {
            cout << "---------------------------" << endl;
        }
    }
}

int main() {
    int choice;
    cout << "1. Single multiplication table\n"
         << "2. Tables from 1 to N\n"
         << "Enter choice (1-2): ";
    cin >> choice;

    if (choice == 1) {
        int num;
        cout << "Enter a number: ";
        cin >> num;
        if (num <= 0) {
            cout << "Error: Number must be positive." << endl;
            return 1;
        }
        singleTable(num);
    } else if (choice == 2) {
        int n;
        cout << "Enter N: ";
        cin >> n;
        if (n <= 0) {
            cout << "Error: N must be a positive integer." << endl;
            return 1;
        }
        tablesUpToN(n);
    } else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}
