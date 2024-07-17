#include <iostream>
#include <string>

using namespace std;

// Base class Person
class Person {
protected:
    string name;
    int age;
    string gender;
    string address;
    string phone;

public:
    // Default constructor
    Person() {}

    // Parameterized constructor
    Person(string name, int age, string gender, string address, string phone) :
        name(name), age(age), gender(gender), address(address), phone(phone) {}

    // Setters and getters
    void setName(string name) { this->name = name; }
    string getName() { return name; }

    void setAge(int age) { this->age = age; }
    int getAge() { return age; }

    void setGender(string gender) { this->gender = gender; }
    string getGender() { return gender; }

    void setAddress(string address) { this->address = address; }
    string getAddress() { return address; }

    void setPhone(string phone) { this->phone = phone; }
    string getPhone() { return phone; }

    // Function to display information of a person
    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
        cout << "Address: " << address << endl;
        cout << "Phone: " << phone << endl;
    }
};

// Derived class Teacher
class Teacher : public Person {
private:
    string qualification;
    double salary;

public:
    // Default constructor
    Teacher() {}

    // Parameterized constructor
    Teacher(string name, int age, string gender, string address, string phone, string qualification, double salary) :
        Person(name, age, gender, address, phone), qualification(qualification), salary(salary) {}

    // Setters and getters
    void setQualification(string qualification) { this->qualification = qualification; }
    string getQualification() { return qualification; }

    void setSalary(double salary) { this->salary = salary; }
    double getSalary() { return salary; }

    // Function to display information of a Teacher
    void displayInfo() {
        Person::displayInfo();
        cout << "Qualification: " << qualification << endl;
        cout << "Salary: " << salary << endl;
    }
};

// Derived class Student
class Student : public Person {
private:
    string previousEducation;
    int obtainedMarks;
    int totalMarks;

public:
    // Default constructor
    Student() {}

    // Parameterized constructor
    Student(string name, int age, string gender, string address, string phone, string previousEducation, int obtainedMarks, int totalMarks) :
        Person(name, age, gender, address, phone), previousEducation(previousEducation), obtainedMarks(obtainedMarks), totalMarks(totalMarks) {}

    // Setters and getters
    void setPreviousEducation(string previousEducation) { this->previousEducation = previousEducation; }
    string getPreviousEducation() { return previousEducation; }

    void setObtainedMarks(int obtainedMarks) { this->obtainedMarks = obtainedMarks; }
    int getObtainedMarks() { return obtainedMarks; }

    void setTotalMarks(int totalMarks) { this->totalMarks = totalMarks; }
    int getTotalMarks() { return totalMarks; }

    // Function to display information of a Student
    void displayInfo() {
        Person::displayInfo();
        cout << "Previous Education: " << previousEducation << endl;
        cout << "Obtained Marks: " << obtainedMarks << endl;
        cout << "Total Marks: " << totalMarks << endl;
    }
};

int main() {
    char choice;
    cout << "Enter Choice: T for Teacher, S for Student:   ";
    cin >> choice;

    if (choice == 'T' || choice == 't') {
        string name, phone, gender, address, qualification;
        int age, salary;

        cout << "\nEnter following Data for Teacher:" << endl;
        cout << "Enter Name: ";
        cin.ignore(); // Ignore the newline character from previous input
        getline(cin, name);
        cout << "Enter Gender: ";
        cin >> gender;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Address: ";
        cin.ignore();
        getline(cin, address);
        cout << "Enter Phone Number: ";
        cin >> phone;
        cout << "Enter Qualification: ";
        cin.ignore();
        getline(cin, qualification);
        cout << "Enter Salary: ";
        cin >> salary;

        Teacher teacher(name, age, gender, address, phone, qualification, salary);

        cout << "\n\nDisplaying Teacher's information:" << endl;
        teacher.displayInfo();
    } else if (choice == 'S' || choice == 's') {
        string name,phone, gender, address, previousEducation;
        int age,  obtainedMarks, totalMarks;

        cout << "\n\nEnter following Data for Student:" << endl;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Gender: ";
        cin >> gender;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Address: ";
        cin.ignore();
        getline(cin, address);
        cout << "Enter Phone Number: ";
        cin >> phone;
        cout << "Enter Previous Education: ";
        cin.ignore();
        getline(cin, previousEducation);
        cout << "Enter Obtained Marks: ";
        cin >> obtainedMarks;
        cout << "Enter Total Marks: ";
        cin >> totalMarks;

        Student student(name, age, gender, address, phone, previousEducation, obtainedMarks, totalMarks);

        cout << "\n\nDisplaying Student's information:" << endl;
        student.displayInfo();
    } else {
        cout << "Invalid Choice!" << endl;
    }

    return 0;
}
