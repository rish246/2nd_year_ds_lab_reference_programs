#include "sort.h"

void testSortEmptyListSuccess() {
    LinkedList<int> list;
    list.sort();
    assertEqual(list.toVector(), {});
    std::cout << "Passed sorting empty list test" << std::endl;
}

void testSortNonEmptyListSuccess() {
    LinkedList<int> list;
    int elements[] = {1, 4, 2, 4};
    for (int i=0; i<4; i++) {
        list.insertBack(elements[i]);
    }

    list.sort();
    assertEqual(list.toVector(), {1, 2, 4, 4});
    std::cout << "Passed non empty list sorting test" << std::endl;
}

struct Student {
    int rollNumber;
    std::string name;

    Student() {}
    Student(int _roll, std::string _name): rollNumber(_roll), name(_name) {}
};

std::vector<Student> get5Students() {
    std::vector<Student> result;
    std::string names[] = {"F", "B", "C", "D", "E"};

    for (int i=0; i<5; i++) {
        result.push_back(Student(i, names[i]));
    }
    return result;
}

bool comparator(Student student1, Student student2) {
    return student1.name > student2.name;
}

void testSortCustomClassListsSuccess() {
    LinkedList<Student> students;
    std::vector<Student> studentsVec = get5Students();
    for (Student &student : studentsVec) {
        students.insertBack(student);
    }
    students.sort(comparator);
    for (int i=0; i<5; i++) {
        std::cout << students.at(i).rollNumber << ", " << students.at(i).name << std::endl;
    }
    std::vector<std::string> studentNames;
    for (int i=0; i<students.length(); i++) {
        studentNames.push_back(students.at(i).name);
    }

    assertEqual(studentNames, {"B", "C", "D", "E", "F"});
    std::cout << "Passed sorting custom data types using comparators test" << std::endl;
}


bool compareStudentPtrs(Student* studPtr1, Student* studPtr2) {
    return studPtr1->name > studPtr2->name;
}
void testSortCustomClassPointersSuccess() {
    LinkedList<Student*> studentPtrs;
    std::vector<Student> studentsVec = get5Students();

    for (Student &student : studentsVec) {
        studentPtrs.insertBack(new Student(student.rollNumber, student.name));
    }
    studentPtrs.sort([](Student *a, Student *b) { return a->name > b->name; });
    std::vector<std::string> studentNames;
    for (int i=0; i<studentPtrs.length(); i++) {
        studentNames.push_back(studentPtrs.at(i)->name);
        // std::cout << studentNames.back() << std::endl;
    }

    assertEqual(studentNames, {"B", "C", "D", "E", "F"});
    std::cout << "Passed sorting custom data type pointers using comparators test" << std::endl;
    
}

void testSortCustomClassUsingLambdasSuccess() {
    LinkedList<Student> students;
    std::vector<Student> studentsVec = get5Students();
    for (Student &student : studentsVec) {
        students.insertBack(student);
    }


    students.sort([](Student a, Student b) { return a.name > b.name; });
    
    
    for (int i=0; i<5; i++) {
        std::cout << students.at(i).rollNumber << ", " << students.at(i).name << std::endl;
    }
    std::vector<std::string> studentNames;
    for (int i=0; i<students.length(); i++) {
        studentNames.push_back(students.at(i).name);
        // std::cout << studentNames.back() << std::endl;
    }

    assertEqual(studentNames, {"B", "C", "D", "E", "F"});
    std::cout << "Passed sorting custom data types using lambdas test" << std::endl;
}


void runSortingTests() {
    testSortEmptyListSuccess();
    testSortNonEmptyListSuccess();
    testSortCustomClassListsSuccess();
    testSortCustomClassPointersSuccess();
    testSortCustomClassUsingLambdasSuccess();
}
