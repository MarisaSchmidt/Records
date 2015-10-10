//  Created by Marisa Schmidt on 11/25/14.
//
//


#include "EditList.h"
#include<iostream>
using namespace std;




void setBool(bool s){
    s = true;
}


int main() {
    
    //WELCOME
    cout << "\nThis program allows you to enter a list of students' information and edit that list accordingly." << endl; //indicate beginning of entry
    

    //DECLARE VARIABLES for INPUT
    char anotherEntry, list1Delete, list1Delete2, answerSorted, editList, editing, addStudent, list2Delete; //for input
    string name; //name to delete
    
    
    //MAKE LIST 1 and DISPLAY
    List<Student> list1; //call default constructor
    do {
        //List 1
            cout << "Please enter person's first name, last name, middle initial, age, and social security number:" << endl;
            Student *student = new Student(); //instantiate student pointer that points to new student object. calls default constructor
            student -> setInfo();
            Node<Student> *nPtr = new Node<Student>(student); //instantiate Node pointer nPtr, and have it point to new node object that takes student argument.
            list1.Append(nPtr); //append new node that you have created
            cout << "\nWould you like to make another entry? If so, type 'Y'. If not, type anything else." << endl;
            cin >> anotherEntry;
        } while (anotherEntry=='Y'||anotherEntry=='y');
    list1.Display();
    
    
    
    //DELETING ENTRIES FROM LIST 1
    cout << "\nWould you like to delete any items from the list? if so, type 'Y'. If not, type anything else." << endl;
    cin >> list1Delete;
    if (list1Delete=='Y'||list1Delete=='y') {
        do {
            cout << "Enter the first name of the person you would like to delete:" << endl;
            cin >> name;
            
            list1.Delete(name);
            
            cout << "Would you like to delete another item from the list? If so, type 'Y'. If not, type anything else." << endl;
            cin >> list1Delete2;
        }while(list1Delete2=='Y'||list1Delete2=='y');
    }
    cout << "Your list after deletion(s): " << endl;
    list1.Display();
    
   
    //COPY LIST TO MAKE LIST 2 and DISPLAY
    bool sorted = true;
    cout << "Now copying your list to a second list...if you would like to have a copied list sorted by age, press 'S'. If not, type anything else." << endl;
    cin >> answerSorted;
        if (answerSorted=='S'||answerSorted=='s')
            sorted = true; //sorted list
        else
            sorted=false; //exact copy, not sorted
    List<Student> list2(list1, sorted); // call copy constructor
    
    cout << "\nSecond list is as follows:" << endl;
    list2.Display();
    
    
    //EDIT LIST 2?
    cout << "If you would like to edit new list 2, type 'Y'. If not, type anything else." << endl;
    cin >> editList;
    if (editList=='Y'||editList=='y') {
        cout << "Press 'D' to delete a person, or 'A' to add a person. To keep this list as is, simply type anything else." << endl;
        cin >> editing;
        if (editing=='A'||editing=='a'){
            do { //List 2
                cout << "Please enter person's first name, last name, middle initial, age, and social security number:" << endl;
                Student *student2 = new Student(); //instantiate student pointer that points to new student object. calls default constructor
                student2 -> setInfo();
                Node<Student> *nPtr2 = new Node<Student>(student2); //instantiate Node pointer nPtr, and have it point to new node object that takes student argument.
                list2.Append(nPtr2); //append new node that you have created
                cout << "\nWould you like to make another entry? If so, type 'Y'. If not, type anything else." << endl;
                cin >> addStudent;
            } while (addStudent=='Y'||addStudent=='y');
        }
        else if (editing=='D'||editing=='d') {
            do {
                cout << "Enter the first name of the person you would like to delete:" << endl;
                cin >> name;
            
                list2.Delete(name);
            
                cout << "Would you like to delete another item from the list? If so, type 'Y'. If not, type anything else." << endl;
                cin >> list2Delete;
            }while(list2Delete=='Y'||list2Delete=='y');
        }
    }
    
    //BUBBLESORT BOTH LISTS
    cout << "\nNow sorting both List 1 and List 2 by age...." << endl;
    list1.bubbleSort();
    list2.bubbleSort();
    
    //DISPLAY FINAL LISTS
    cout << "\nYour final list1 and list2! : \n" << endl;
    cout << "\nLIST 1: " << endl;
    list1.Display();
    cout << endl;
    cout << "LIST 2: " << endl;
    list2.Display();
    
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    //TEMPLATES
    
    
    //allow user to specified template type
    char type, entryNum, entryChar, entryString, entryDoub;
    
    
    //integer list
    List<int> integerList; 
    int *ptrInt;
    int number;
    
    //character list
    List<char> charList;
    char *ptrChar;
    char character;
    
    //string list
    List<string> stringList;
    string *ptrString;
    string someString;
    
    //doubles list
    List<double> doubleList;
    double *ptrDoub;
    double someDoubles;
    
    
    cout <<"\nNow testing different templates for List class... Please type 'I' if you would like a list of integers, 'C' for list of characters, 'S' for list of strings, and 'D' for list of doubles..." << endl;
    cin >> type;
    if (type=='I'||type=='i') {
        do {
            //List integer
            cout << "Please enter an integer: " << endl;
            cin >> number;
            ptrInt = new int(number); //instantiate student pointer that points to new student object. calls default constructor
            Node<int> *inPtr = new Node<int>(ptrInt); //instantiate Node pointer, and have it point to new node object that takes int argument.
            integerList.Append(inPtr); //append new node that you have created
            cout << "\nWould you like to make another entry? If so, type 'Y'. If not, type anything else." << endl;
            cin >> entryNum;
        } while (entryNum=='Y'||entryNum=='y');
        
        Node<int>* printNode = integerList.getHead();
        cout << "\nFINAL LIST:" << endl;
        while (printNode!=NULL) {
            cout << *(printNode->getObject()) << endl;
            printNode = printNode->getNext(); //traverse
        }
        cout << endl;
        //printNode->setNext(NULL);
        delete printNode;
    }
    else if (type=='C'||type=='c') {
        do {
            //List integer
            cout << "Please enter a character: " << endl;
            cin >> character;
            ptrChar = new char(character); //instantiate student pointer that points to new student object. calls default constructor
            Node<char> *cnPtr = new Node<char>(ptrChar); //instantiate Node pointer, and have it point to new node object that takes char argument.
            charList.Append(cnPtr); //append new node that you have created
            cout << "\nWould you like to make another entry? If so, type 'Y'. If not, type anything else." << endl;
            cin >> entryChar;
        } while (entryChar=='Y'||entryChar=='y');
        
        Node<char>* printNode = charList.getHead();
        cout << "\nFINAL LIST:" << endl;
        while(printNode!=NULL){
            cout << *(printNode->getObject()) << endl;
            printNode = printNode->getNext();
        }
        cout << endl;
        //printNode->setNext(NULL);
        delete printNode;
    }
    else if (type=='S'||type=='s') {
        do {
            //List integer
            cout << "Please enter your string: " << endl;
            cin >> someString;
            ptrString = new string(someString); //instantiate student pointer that points to new student object. calls default constructor
            Node<string> *snPtr = new Node<string>(ptrString); //instantiate Node pointer, and have it point to new node object that takes string argument
            stringList.Append(snPtr); //append new node that you have created
            cout << "\nWould you like to make another entry? If so, type 'Y'. If not, type anything else." << endl;
            cin >> entryString;
        } while (entryString=='Y'||entryString=='y');
        
        Node<string>* printNode = stringList.getHead();
        cout << "\nFINAL LIST:" << endl;
        while (printNode!=NULL) {
            cout << *(printNode->getObject()) << endl;
            printNode = printNode->getNext();
       }
        cout << endl;
        //printNode->setNext(NULL);
        delete printNode;
    }
    else if (type=='D'||type=='d') {
        do {
            //List integer
            cout << "Please enter your numbers: " << endl;
            cin >> someDoubles;
            ptrDoub = new double(someDoubles);
            Node<double> *dnPtr = new Node<double>(ptrDoub); //instantiate Node pointer, and have it point to new node object that takes double argument
            doubleList.Append(dnPtr); //append new node that you have created
            cout << "\nWould you like to make another entry? If so, type 'Y'. If not, type anything else." << endl;
            cin >> entryDoub;
        } while (entryDoub=='Y'||entryDoub=='y');
        
        Node<double>* printNode = doubleList.getHead();
        cout << "\nFINAL LIST:" << endl;
        while (printNode!=NULL) {
            cout << *(printNode->getObject()) << endl;
            printNode = printNode->getNext();
        }
        cout << endl;
        //printNode->setNext(NULL);
        delete printNode;
    }

    delete ptrInt;
    delete ptrChar;
    delete ptrString;
    delete ptrDoub;


    return 0;
    
} //end program
