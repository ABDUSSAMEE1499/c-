#include <iostream>
#include <string>

using namespace std;

class Course {
public:
    Course(const string& courseName, int capacity);
    Course(const Course& other); // Deep copy constructor
    ~Course();

    string getCourseName() const;
    void addStudent(const string& name);
    void dropStudent(const string& name); // New function
    string getStudents() const;
    int getNumberOfStudents() const;

private:
    string courseName;
    string* students; // Change the data type to string*
    int numberOfStudents;
    int capacity;
};

// Deep copy constructor
Course::Course(const Course& other) {
    numberOfStudents = other.numberOfStudents;
    capacity = other.capacity;
    courseName = other.courseName;
    students = new string[capacity];
    
    for (int i = 0; i < numberOfStudents; i++) {
        students[i] = other.students[i];
    }
}

Course::Course(const string& courseName, int capacity) {
    numberOfStudents = 0;
    this->courseName = courseName;
    this->capacity = capacity;
    students = new string[capacity];
}

Course::~Course() {
    delete[] students;
}

string Course::getCourseName() const {
    return courseName;
}

void Course::addStudent(const string& name) {
    students[numberOfStudents] = name;
    numberOfStudents++;
}

void Course::dropStudent(const string& name) {
    for (int i = 0; i < numberOfStudents; i++) {
        if (students[i] == name) {
            for (int j = i; j < numberOfStudents - 1; j++) {
                students[j] = students[j + 1];
            }
            numberOfStudents--;
            break; // Student found and dropped
        }
    }
}

string Course::getStudents() const {
    string studentList;
    for (int i = 0; i < numberOfStudents; i++) {
        studentList += students[i];
        if (i < numberOfStudents - 1) {
            studentList += ", ";
        }
    }
    return studentList;
}

int Course::getNumberOfStudents() const {
    return numberOfStudents;
}

int main() {
    Course course1("Data Structures", 10);
    Course course2("Database Systems", 15);

    course1.addStudent("Ali");
    course1.addStudent("Ahmed");
    course1.addStudent("Imran");
    course2.addStudent("Rizwan");
    course2.addStudent("Akeel");

    cout << "Number of students in course1: " << course1.getNumberOfStudents() << "\n";
    string students = course1.getStudents();
    cout << "Students in course1: " << students << "\n";

    // Drop a student from course1
    course1.dropStudent("Ahmed");
    cout << "After dropping a student from course1:" << "\n";
    cout << "Number of students in course1: " << course1.getNumberOfStudents() << "\n";
    students = course1.getStudents();
    cout << "Students in course1: " << students << "\n";

    cout << "Number of students in course2: " << course2.getNumberOfStudents() << "\n";
    students = course2.getStudents();
    cout << "Students in course2: " << students << "\n";

    return 0;
}
