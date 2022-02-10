#include "LinkedList.h"
#include <string>
/*
Use the tests as a documentation..
Read each test to see the behaviours of various methods.
*/
struct Student {
    int rollNumber;
    std::string name;

    Student() {}
    Student(int _roll, std::string _name): rollNumber(_roll), name(_name) {}
    friend std::ostream &operator << (std::ostream &output, const Student& s);
};

std::ostream &operator << (std::ostream &output, const Student &s) {
    output << "Student(" << s.name << ", " << s.rollNumber << ")";
    return output;
}


std::vector<Student> get5Students() {
    std::vector<Student> result;
    std::string names[] = {"F", "B", "C", "D", "E"};

    for (int i=0; i<5; i++) {
        result.push_back(Student(i, names[i]));
    }
    return result;
}

int main() {
    LinkedList<Student> students;
    std::vector<Student> studentsVec = get5Students();
    for (Student &student : studentsVec) {
        students.insertBack(student);
    }
    
    students.print();
    students.sort([](Student a, Student b) { return a.name > b.name; });
    students.print();
}