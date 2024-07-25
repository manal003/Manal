#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Patient class
class Patient {
public:
    string name;
    int age;

    Patient(string n, int a) : name(n), age(a) {}
};

// Custom comparator for priority queue
struct ComparePatients {
    bool operator()(const Patient& p1, const Patient& p2) {
        // Higher age patients have higher priority
        return p1.age < p2.age;
    }
};

// Hospital class
class Hospital {
private:
    priority_queue<Patient, vector<Patient>, ComparePatients> patients;

public:
    // Add patient to the queue
    void addPatient() {
        string name;
        int age;
        cout << "\nEnter patient's name: ";
        cin >> name;
        cout << "Enter patient's age: ";
        cin >> age;
        Patient p(name, age);
        patients.push(p);
        cout << "\nPatient added successfully!!" << endl;
    }

    // Remove patient from the queue
    void removePatient() {
        if (patients.empty()) {
            cout << "\nNo patients in the queue!" << endl;
            return;
        }
        patients.pop();
        cout << "\nPatient removed successfully!" << endl;
    }

    // Display patients in the queue
    void displayPatients() {
        if (patients.empty()) {
            cout << "\nNo patients in the queue!" << endl;
            return;
        }
        cout << "\nPatients in the queue:\n" << endl;
        priority_queue<Patient, vector<Patient>, ComparePatients> temp = patients;
        while (!temp.empty()) {
            Patient p = temp.top();
            cout << "Name: " << p.name << ", Age: " << p.age << endl;
            temp.pop();
        }
    }

    // Exit the program
    void exitProgram() {
        cout << "\nExiting program. Goodbye!" << endl;
        exit(0);
    }

    // Run the hospital program
    void run() {
        int choice;
        while (true) {
            cout << "Hospital Program" << endl;
            cout << "1. Add patient" << endl;
            cout << "2. Remove patient" << endl;
            cout << "3. Display patients" << endl;
            cout << "4. Exit" << endl;
            cout << "\nEnter your choice: ";
            cin >> choice;
            switch (choice) {
                case 1:
                    addPatient();
                    break;
                case 2:
                    removePatient();
                    break;
                case 3:
                    displayPatients();
                    break;
                case 4:
                    exitProgram();
                    break;
                default:
                    cout << "\nInvalid choice. Please try again." << endl;
            }
        }
    }
};

int main() {
    Hospital hospital;
    hospital.run();
    return 0;
}
