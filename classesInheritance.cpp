//
//  classesInheritance.cpp
//  PLP5
//
//  Created by Stephanie Asitimbay on 11/19/25.
//

#include <iostream>
using namespace std;

//creating basic person class
class Person{
    public:
    //initiating some attributes
        string fname;
        string lname;
        int age;
    
    //creating the constructor
        Person(string fn, string ln, int a) {
            fname = fn;
            lname =ln;
            age = a;
        }
    
    //creating some methods
        void print() {
            cout<< fname << " " << lname << ", age: " << age << endl;
        }
        
        string getFullName() {
            return fname + " " + lname;
        }
    
        int getAge() {
            return age;
        }
    
};

//creating Student class that inherits from Person class
class Student: public Person {
    public:
        string studentID;
        double gpa;
        
    
};

int main() {
    Person p1("Stephanie", "Asitimbay", 20);
    p1.print();
    cout<< p1.getFullName() << endl;
    return 0;
}
