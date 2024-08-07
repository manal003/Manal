#include <iostream>
#include <string>
using namespace std;

// Class representing a student (Node in the linked list)
class Student {
public:
    string name;
    int marks;
    Student* next;

    Student(string name, int marks) {
        this->name = name;
        this->marks = marks;
        this->next = nullptr;
    }
};

// Class representing the stack using linked list
class Stack {
private:
    Student* top;

public:
    Stack() {
        top = nullptr;
    }

    // Push a new student onto the stack
    void push(string name, int marks) {
        Student* newStudent = new Student(name, marks);
        newStudent->next = top;
        top = newStudent;
    }

    // Pop a student from the stack
    void pop() {
        if (top == nullptr) {
            cout << "Stack is empty. Nothing to pop." << endl;
            return;
        }
        Student* temp = top;
        top = top->next;
        delete temp;
    }

    // Display all students in the stack
    void display() {
        if (top == nullptr) {
            cout << "Stack is empty." << endl;
            return;
        }
        Student* current = top;
        while (current != nullptr) {
            cout << "Name: " << current->name << ", Marks: " << current->marks << endl;
            current = current->next;
        }
    }

    // Sort the stack based on marks in descending order and return a new sorted stack
    Stack sortStack() {
        Stack sortedStack;
        Student* current = top;
        while (current != nullptr) {
            sortedStack.sortedInsert(current->name, current->marks);
            current = current->next;
        }
        return sortedStack;
    }

    // Helper function to insert an element into the sorted stack
    void sortedInsert(string name, int marks) {
        Student* newStudent = new Student(name, marks);
        if (top == nullptr || top->marks <= marks) {
            newStudent->next = top;
            top = newStudent;
        } else {
            Student* current = top;
            while (current->next != nullptr && current->next->marks > marks) {
                current = current->next;
            }
            newStudent->next = current->next;
            current->next = newStudent;
        }
    }

    // Display top 3 students based on marks
    void displayTop3() {
        if (top == nullptr) {
            cout << "Stack is empty." << endl;
            return;
        }

        Stack sortedStack = sortStack();

        // Display top 3 students
        Student* current = sortedStack.top;
        for (int i = 0; i < 3 && current != nullptr; i++) {
            cout << "Name: " << current->name << ", Marks: " << current->marks << endl;
            current = current->next;
        }
    }

    // Destructor to clean up the memory
    ~Stack() {
        while (top != nullptr) {
            pop();
        }
    }
};

int main() {
    Stack stack;
    int choice;
    string name;
    int marks;

    do {
        cout << "1. Add a student to the stack" << endl;
        cout << "2. Remove a student from the stack" << endl;
        cout << "3. Display all students in the stack" << endl;
        cout << "4. Display top 3 students" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter student's name: ";
                cin >> name;
                cout << "Enter student's marks: ";
                cin >> marks;
                stack.push(name, marks);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.display();
                break;
            case 4:
                stack.displayTop3();
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}
