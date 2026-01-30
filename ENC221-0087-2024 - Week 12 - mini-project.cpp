
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Forward declarations
class Course;
class Department;

// Student class
class Student {
private:
    string studentId;
    string name;
    string email;

public:
    Student(string studentId, string name, string email)
        : studentId(studentId), name(name), email(email) {}

    string getStudentId() const { return studentId; }
    string getName() const { return name; }
    string getEmail() const { return email; }

    void displayInfo() const {
        cout << "Student ID: " << studentId << endl;
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
    }
};

// Course class
class Course {
private:
    string courseCode;
    string courseName;
    int credits;

public:
    Course(string courseCode, string courseName, int credits)
        : courseCode(courseCode), courseName(courseName), credits(credits) {}

    string getCourseCode() const { return courseCode; }
    string getCourseName() const { return courseName; }
    int getCredits() const { return credits; }

    void displayInfo() const {
        cout << "Course Code: " << courseCode << endl;
        cout << "Course Name: " << courseName << endl;
        cout << "Credits: " << credits << endl;
    }
};

// Department class (Association with Course)
class Department {
private:
    string departmentName;
    string departmentCode;
    vector<Course*> courses;
    int maxCourses;

public:
    Department(string departmentName, string departmentCode, int maxCourses)
        : departmentName(departmentName), departmentCode(departmentCode), 
          maxCourses(maxCourses) {}

    // Add course to department (Association)
    void addCourse(Course* course) {
        if (courses.size() < maxCourses) {
            courses.push_back(course);
            cout << "Course " << course->getCourseCode() 
                 << " added to " << departmentName << endl;
        } else {
            cout << "Cannot add more courses. Department is full." << endl;
        }
    }

    // Display department information
    void displayInfo() const {
        cout << endl << "=== Department Information ===" << endl;
        cout << "Department: " << departmentName << endl;
        cout << "Code: " << departmentCode << endl;
        cout << "Number of Courses: " << courses.size() << endl;
        cout << endl << "Courses Offered:" << endl;
        
        for (size_t i = 0; i < courses.size(); i++) {
            cout << endl << (i + 1) << "." << endl;
            courses[i]->displayInfo();
        }
    }

    string getDepartmentName() const { return departmentName; }
    string getDepartmentCode() const { return departmentCode; }
};

// Registration class (Dependency on Student and Course)
class Registration {
public:
    // Dependency: Registration depends on Student and Course objects
    void registerStudent(const Student& student, const Course& course, 
                        const Department& department) {
        cout << endl << "=== Registration Process ===" << endl;
        cout << "Registering student for course..." << endl;
        cout << "Student: " << student.getName() 
             << " (ID: " << student.getStudentId() << ")" << endl;
        cout << "Course: " << course.getCourseName() 
             << " (" << course.getCourseCode() << ")" << endl;
        cout << "Department: " << department.getDepartmentName() << endl;
        cout << "Registration successful!" << endl;
    }

    // Display registration summary
    void displayRegistrationSummary(const Student& student, const Course& course) {
        cout << endl << "=== Registration Summary ===" << endl;
        student.displayInfo();
        cout << endl;
        course.displayInfo();
    }
};

// Main test program
int main() {
    cout << "=== Department Registration System ===" << endl << endl;

    // Create department
    Department csDepartment("Computer Science", "CS", 5);

    // Create courses
    Course course1("CS101", "Introduction to Programming", 3);
    Course course2("CS201", "Data Structures", 4);
    Course course3("CS301", "Database Systems", 3);

    // Add courses to department (Association)
    csDepartment.addCourse(&course1);
    csDepartment.addCourse(&course2);
    csDepartment.addCourse(&course3);

    // Display department info
    csDepartment.displayInfo();

    // Create student
    Student student1("2024001", "Alice Johnson", "alice.j@university.edu");

    // Create registration object (Dependency)
    Registration registration;

    // Register student for a course (Demonstrates dependency)
    registration.registerStudent(student1, course1, csDepartment);
    registration.displayRegistrationSummary(student1, course1);

    cout << endl << "=== End of Registration System Demo ===" << endl;

    return 0;
}