#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }

// division with zero-check to prevent crash
double divide(double a, double b) {
    if (b == 0) {
        cout << "Error: Cannot divide by zero." << endl;
        return 0;
    }
    return a / b;
}

// integer remainder (modulo), also guards against division by zero
int calculateModulus(int a, int b) {
    if (b == 0) {
        cout << "Error: Cannot divide by zero." << endl;
        return 0;
    }
    return a % b;
}

// raises base to the power of exp using cmath's pow()
double exponentiate(double base, double exp) {
    return pow(base, exp);
}

int main() {
    int choice;

    do {
        cout << "\n============================" << endl;
        cout << "     SIMPLE CALCULATOR" << endl;
        cout << "============================" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Modulus" << endl;
        cout << "6. Exponentiation" << endl;
        cout << "7. Quit" << endl;
        cout << "Select an operation (1-7): ";
        cin >> choice;

        if (choice >= 1 && choice <= 6) {
            double a, b;
            cout << "Enter first number : ";
            cin >> a;
            cout << "Enter second number: ";
            cin >> b;

            cout << fixed << setprecision(2);  // format output to 2 decimals

            switch (choice) {
                case 1:
                    cout << "Result: " << a << " + " << b << " = " << add(a, b) << endl;
                    break;
                case 2:
                    cout << "Result: " << a << " - " << b << " = " << subtract(a, b) << endl;
                    break;
                case 3:
                    cout << "Result: " << a << " * " << b << " = " << multiply(a, b) << endl;
                    break;
                case 4:
                    if (b != 0)
                        cout << "Result: " << a << " / " << b << " = " << divide(a, b) << endl;
                    break;
                case 5:
                    cout << "Result: " << (int)a << " % " << (int)b << " = " << calculateModulus((int)a, (int)b) << endl;
                    break;
                case 6:
                    cout << "Result: " << a << " ^ " << b << " = " << exponentiate(a, b) << endl;
                    break;
            }
        } else if (choice == 7) {
            cout << "Goodbye!" << endl;
        } else {
            cout << "Invalid choice. Please select a number between 1 and 7." << endl;
        }
    } while (choice != 7);  // loop until user quits

    return 0;
}
