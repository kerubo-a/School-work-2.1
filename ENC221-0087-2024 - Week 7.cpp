
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Base Employee class
class Employee {
private:
    string name;
    int serviceYear;
    double salary;

public:
    // Constructor
    Employee(string name, int serviceYear, double salary) 
        : name(name), serviceYear(serviceYear), salary(salary) {}

    // Getter methods
    string getName() const { return name; }
    int getAge() const { return serviceYear; }
    int getServiceYear() const { return serviceYear; }
    double getSalary() const { return salary; }
    
    // Virtual destructor for proper cleanup
    virtual ~Employee() {}
};

// Manager class extends Employee
class Manager : public Employee {
private:
    string department;

public:
    // Constructor
    Manager(string name, int serviceYear, double salary, string department)
        : Employee(name, serviceYear, salary), department(department) {}

    // Getter for department
    string getDepartment() const { return department; }

    // Display manager information
    void displayInfo() const {
        cout << "Manager Name: " << getName() << endl;
        cout << "Service Years: " << getServiceYear() << endl;
        cout << fixed << setprecision(2);
        cout << "Salary: $" << getSalary() << endl;
        cout << "Department: " << department << endl;
    }
};

// Developer class extends Employee
class Developer : public Employee {
private:
    string programmingLanguage;

public:
    // Constructor
    Developer(string name, int serviceYear, double salary, string progLang)
        : Employee(name, serviceYear, salary), programmingLanguage(progLang) {}

    // Getter for programming language
    string getProgrammingLanguage() const { return programmingLanguage; }

    // Display developer information
    void displayInfo() const {
        cout << "Developer Name: " << getName() << endl;
        cout << "Service Years: " << getServiceYear() << endl;
        cout << fixed << setprecision(2);
        cout << "Salary: $" << getSalary() << endl;
        cout << "Programming Language: " << programmingLanguage << endl;
    }
};

// Test the classes
int main() {
    cout << "=== Employee Management System Test ===" << endl << endl;

    // Create Manager object
    Manager manager("Robert Smith", 8, 95000.0, "Engineering");
    cout << "Manager Information:" << endl;
    manager.displayInfo();

    cout << endl << string(40, '=') << endl << endl;

    // Create Developer objects
    Developer developer1("Emily Chen", 5, 80000.0, "Python");
    cout << "Developer Information:" << endl;
    developer1.displayInfo();

    cout << endl << string(40, '=') << endl << endl;

    Developer developer2("Michael Brown", 3, 70000.0, "Java");
    cout << "Another Developer:" << endl;
    developer2.displayInfo();

    return 0;
}