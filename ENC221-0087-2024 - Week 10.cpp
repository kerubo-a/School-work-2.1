
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

// Base class for all employees
class Employee {
private:
    string firstName;
    string initial;
    string lastName;

public:
    // Constructor
    Employee(string firstName, string initial, string lastName)
        : firstName(firstName), initial(initial), lastName(lastName) {}

    // Getters
    string getFirstName() const { return firstName; }
    string getInitial() const { return initial; }
    string getLastName() const { return lastName; }
    
    string getFullName() const {
        return firstName + " " + initial + ". " + lastName;
    }
    
    // Virtual function for polymorphism
    virtual void displayInfo() const = 0;
    
    // Virtual destructor
    virtual ~Employee() {}
};

// SalaryEmployee class
class SalaryEmployee : public Employee {
private:
    double monthlySalary;

public:
    // Constructor
    SalaryEmployee(string firstName, string initial, string lastName, double monthlySalary)
        : Employee(firstName, initial, lastName), monthlySalary(monthlySalary) {}

    // Calculate annual salary
    double getAnnualSalary() const {
        return monthlySalary * 12;
    }

    // Override displayInfo
    void displayInfo() const override {
        cout << "Salary Employee: " << getFullName() << endl;
        cout << fixed << setprecision(2);
        cout << "Monthly Salary: $" << monthlySalary << endl;
        cout << "Annual Salary: $" << getAnnualSalary() << endl;
    }
};

// HourlyEmployee class
class HourlyEmployee : public Employee {
private:
    double hourlyRate;
    int hoursWorked;

public:
    // Constructor
    HourlyEmployee(string firstName, string initial, string lastName, 
                   double hourlyRate, int hoursWorked)
        : Employee(firstName, initial, lastName), 
          hourlyRate(hourlyRate), hoursWorked(hoursWorked) {}

    // Calculate wages
    double getWages() const {
        return hourlyRate * hoursWorked;
    }

    // Override displayInfo
    void displayInfo() const override {
        cout << "Hourly Employee: " << getFullName() << endl;
        cout << fixed << setprecision(2);
        cout << "Hourly Rate: $" << hourlyRate << endl;
        cout << "Hours Worked: " << hoursWorked << endl;
        cout << "Total Wages: $" << getWages() << endl;
    }
};

// Test application for polymorphism
int main() {
    cout << "=== Employee Information ===" << endl << endl;

    // Create salary employee
    SalaryEmployee salaryEmp("John", "A", "Smith", 5000.0);
    salaryEmp.displayInfo();

    cout << endl;

    // Create hourly employee
    HourlyEmployee hourlyEmp("Jane", "B", "Doe", 25.0, 160);
    hourlyEmp.displayInfo();

    // Demonstrate polymorphism with pointers
    cout << endl << "=== Polymorphism Demo ===" << endl;
    vector<Employee*> employees;
    employees.push_back(&salaryEmp);
    employees.push_back(&hourlyEmp);

    for (Employee* emp : employees) {
        cout << "Employee: " << emp->getFullName() << endl;
    }

    cout << endl << "=== Calling displayInfo polymorphically ===" << endl;
    for (Employee* emp : employees) {
        cout << endl;
        emp->displayInfo();
    }

    return 0;
}