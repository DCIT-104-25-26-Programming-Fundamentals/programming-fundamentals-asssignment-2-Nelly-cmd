#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// a single student record — name, unique id, and list of scores
struct Student {
    string name;
    int id;
    vector<double> scores;
};

// collects name, id, and scores from user, then appends to the list
void addStudent(vector<Student>& students) {
    Student s;
    cout << "Student name: ";
    cin.ignore();
    getline(cin, s.name);
    cout << "Student ID: ";
    cin >> s.id;

    int numScores;
    cout << "How many scores? ";
    cin >> numScores;

    for (int i = 0; i < numScores; i++) {
        double score;
        cout << "Enter score " << (i + 1) << ": ";
        cin >> score;
        s.scores.push_back(score);
    }

    students.push_back(s);
    cout << "Student \"" << s.name << "\" added successfully." << endl;
}

// returns the average of a student's score list
double calculateAverage(const vector<double>& scores) {
    if (scores.empty()) return 0.0;
    double sum = 0;
    for (double s : scores) sum += s;
    return sum / scores.size();
}

// prints all students with their scores and averages
void displayAllStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students have been added yet." << endl;
        return;
    }

    cout << fixed << setprecision(2);  
    for (const Student& s : students) {
        cout << "Name: " << s.name << endl;
        cout << "ID: " << s.id << endl;
        cout << "Scores: ";
        for (size_t i = 0; i < s.scores.size(); i++) {
            cout << s.scores[i];
            if (i < s.scores.size() - 1) cout << ", ";
        }
        cout << endl;
        cout << "Average: " << calculateAverage(s.scores) << endl;
        cout << "-----------------------------" << endl;
    }
}

// searches by id and prints a single student's average
void findStudentAverage(const vector<Student>& students) {
    int searchId;
    cout << "Enter student ID: ";
    cin >> searchId;

    for (const Student& s : students) {
        if (s.id == searchId) {
            double avg = calculateAverage(s.scores);
            cout << fixed << setprecision(2);
            cout << s.name << "'s average score: " << avg << endl;
            return;
        }
    }

    cout << "Error: Student with ID " << searchId << " not found." << endl;
}

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\n================================" << endl;
        cout << "   STUDENT RECORD SYSTEM MENU" << endl;
        cout << "================================" << endl;
        cout << "1. Add student" << endl;
        cout << "2. Display all students" << endl;
        cout << "3. Calculate average score" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayAllStudents(students);
                break;
            case 3:
                findStudentAverage(students);
                break;
            case 4:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
        }
    } while (choice != 4);

    return 0;
}
