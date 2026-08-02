#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Displays the options
void showMenu() {
    cout << "\n============================" << endl;
    cout << "     TO-DO LIST MENU" << endl;
    cout << "============================" << endl;
    cout << "1. Add task" << endl;
    cout << "2. View tasks" << endl;
    cout << "3. Delete task" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice (1-4): ";
}


void addTask(vector<string>& tasks) {
    cout << "Enter task: ";
    string task;
    cin.ignore();        
    getline(cin, task);    
    tasks.push_back(task);
    cout << "Task added: \"" << task << "\"" << endl;
}


void viewTasks(const vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "Your to-do list is empty. Add some tasks!" << endl;
        return;
    }
    cout << "Your Tasks:" << endl;
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << (i + 1) << ". " << tasks[i] << endl;
    }
}

// shows tasks, asks which number to delete, then removes it
void deleteTask(vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to delete." << endl;
        return;
    }

    viewTasks(tasks);
    cout << "Enter task number to delete: ";
    int num;
    cin >> num;


    if (num < 1 || num > (int)tasks.size()) {
        cout << "Error: Invalid task number." << endl;
        return;
    }

    string removed = tasks[num - 1];
    tasks.erase(tasks.begin() + num - 1); 
    cout << "Task \"" << removed << "\" has been removed." << endl;
}

int main() {
    vector<string> tasks;
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                deleteTask(tasks);
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
