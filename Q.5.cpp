
#include <iostream>
using namespace std;

// part a — generates and prints the first n fibonacci terms using a loop
void printFibonacciTerms(int n) {
    int a = 0, b = 1, next;
    cout << "Fibonacci sequence: ";
    for (int i = 0; i < n; i++) {
        cout << a;
        if (i < n - 1) cout << " ";
        next = a + b;   
        a = b;
        b = next;
    }
    cout << endl;
}

// part b — checks if a number appears in the fibonacci sequence
bool isFibonacci(int num) {
    if (num < 0) return false;
    int a = 0, b = 1;
    while (a <= num) {
        if (a == num) return true;
        int next = a + b;
        a = b;
        b = next;
    }
    return false;
}

// Example
void checkFibonacciNumber() {
    int num;
    cout << "Enter a number to check: ";
    cin >> num;

    if (isFibonacci(num)) {
        cout << num << " is a Fibonacci number." << endl;
    } else {
        cout << num << " is NOT a Fibonacci number." << endl;
    }
}

int main() {
    int choice;
    cout << "1. Print first N terms\n"
         << "2. Check if a number is Fibonacci\n"
         << "Enter choice (1-2): ";
    cin >> choice;

    if (choice == 1) {
        int n;
        cout << "How many terms? ";
        cin >> n;
        if (n <= 0) {
            cout << "Error: N must be a positive integer." << endl;
            return 1;
        }
        printFibonacciTerms(n);
    } else if (choice == 2) {
        checkFibonacciNumber();
    } else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}
