//  Created by Marisa Schmidt on 11/25/14.
//
//

#ifndef _StudentT_h
#define _StudentT_h


#include<iostream>
using namespace std;

class Student {
    
public:
    Student();
    void getInfo(); //accessor functions
    void setInfo();
    string getName();//to check for name
    int getAge(); //to check for age
    
private:
    string fname;
    string lname;
    char mi;
    int ss;
    int age;
    
};


Student::Student() {
    //make some default values
    fname = "firstName";
    lname = "lastName";
    mi = 'M';
    age = 0;
    ss = 0;
}

/*
 Student::Student (const Student& s) {
 fname = s.fname;
 lname = s.lname;
 mi = s.mi;
 age = s.age;
 ss = s.ss;
 
 } */

void Student::setInfo() {
    cin >> fname >> lname >> mi >> age >> ss;
}

void Student:: getInfo() {
    cout << "Name: " << lname << ", " << fname << " " << mi << endl;
    cout << "Age: " << age << endl;
    cout << "Social Security Number: " << ss << endl;
    cout << endl;
}

string Student::getName(){
    return fname;
}

int Student::getAge() {
    return age;
}

#endif
