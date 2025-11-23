#include <iostream>
using namespace std;

class Roommate {
private:
    string name;
    int age;
    string hobby;

public:
    // Constructor
    Roommate(string n, int a, string h) {
        name = n;
        age = a;
        hobby = h;
    }

    // Method to introduce roommie
    void introduce() {
        cout << "Hi, I'm " << name << ", " 
             << age << " years old and I enjoy " 
             << hobby << "!" << endl;
    }

    // Method to simulate an activity
    void doActivity() {
        cout << name << " is currently " << hobby << "." << endl;
    }
};

int main() {
    Roommate r1("Jane", 22, "playing netball");
    r1.introduce();
    r1.doActivity();

    return 0;
}
