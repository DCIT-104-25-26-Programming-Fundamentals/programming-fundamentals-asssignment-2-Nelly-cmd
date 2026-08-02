#include <iostream>
using namespace std;

// Sum
double calculateSum(const double arr[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

// Average
double calculateAverage(double sum, int n) {
    return sum / n;
}

// Maximum number
double findMaximum(const double arr[], int n) {
    double maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) maxVal = arr[i];
    }
    return maxVal;
}

// Minimum number
double findMinimum(const double arr[], int n) {
    double minVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) minVal = arr[i];
    }
    return minVal;
}

int main() {
    int n;
    cout << "How many numbers? ";
    cin >> n;

    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return 1;
    }

    double arr[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> arr[i];
    }

    // compute and display all statistics
    double sum = calculateSum(arr, n);
    double avg = calculateAverage(sum, n);
    double maxVal = findMaximum(arr, n);
    double minVal = findMinimum(arr, n);

    cout << "\nResults:" << endl;
    cout << "Sum:     " << sum << endl;
    cout << "Average: " << avg << endl;
    cout << "Maximum: " << maxVal << endl;
    cout << "Minimum: " << minVal << endl;

    return 0;
}
