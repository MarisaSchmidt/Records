//
//  ListT.h
//  
//
//  Created by Marisa Schmidt on 12/2/14.
//
//

#ifndef _EditListT_h
#define _EditListT_h
#include "NavigateList.h"
#include<iostream>
using namespace std;

template <class T>
class List {

public:
    List(); //default constructor. initialize values.
    List( const List<T> &, bool); //copy constructor
    ~List(); //deconstructor
    void Append ( Node<T> * ); //append node
    void Insert ( Node<T> * ); //insert node to sort by age
    void Delete (string); //delete node
    void bubbleSort (); //sort lists by age
    void swap (Node<T> * , Node<T> *); //swap student information
    void Display( Node<T> * subSetPtr = NULL); //to display student list, recursive ascending
    int getNumNodes(); //how many nodes in the list? crucial for sorting
    bool isEmpty();
    Node<T> *getHead() const; //returns head... must be const because head is const variable
    
private:
    Node<T> *head;
};

template <class T>
List<T>::List() { //default constructor
    head = NULL; //default value for head pointer (points to nothing)
}

template <class T>
Node<T> * List<T>::getHead() const{
    return head;
}

template <class T>
List<T>::List( const List<T> & list, bool sortList){ //copy constructor
    
    head = NULL; //default value for head pointer
    Node<T> *curr = list.getHead(); //you need to make sure you refer to original head from list 1
    //t will traverse old list
    
    while (curr!=NULL) { //traverse
        T* tCopy = new T (*(curr-> getObject()));
        //sPtr points to new student with copied information from original student
        Node<T>* nodeCopy = new Node<T>(tCopy); //now new node nodeCopy is connected to student information
        
        if (sortList==true)
            Insert(nodeCopy);
        else if (sortList==false)
            Append(nodeCopy); //append node to newly created list
        
        
        curr = curr->getNext(); //keep traversing list 1
    }
}


template <class T>
List<T>::~List() { //destructor
    Node<T> *nodeToDelete = head; //nodeToDelete will be used to delete node in the list, which will always be at the head of the list
    Node<T> *t = NULL; //t will point to the node's contents we want to destroy
    
    if (head!=NULL) {
   
        if (t==NULL) { //if t points to nothing (at beginning), point it to the start of the list
            t = head;
        }
        else {
            while (t!=NULL){ //while there are still nodes to delete
                nodeToDelete = t;
                t = nodeToDelete->getNext(); //nodeToDelete points to node after t node.
                nodeToDelete -> setNext(NULL); //t's next pointer no longer points to afterT node, break connection.
                delete nodeToDelete; //delete sPtr and its contents from nodeToDelete.
                //nodeToDelete = t; //now node to delete is next node in the list
            }
         }
    }//if head is not null
}//end function


template <class T>
void List<T>::Insert(Node<T> *nodePtr) {
    
    if (head==NULL) {
        head = nodePtr;
    }
    
    else {
        Node<T> *t = head;
        Node<T> *prev = NULL; //to use as comparison in case you need to rearrange
    
        while (t!=NULL) { //traverse
            if((nodePtr->getObject()->getAge()) < (t->getObject()->getAge())) {
                //if prev node value is greater, means you have to insert before the current node
             //CASE 1 - beginning of list
                if (prev==NULL) {
                    head = nodePtr; //make sure if beginning of list, head now points to node which is at beginning of list
                }
             
             //CASE 2 - not beginning of list
                else {
                    prev->setNext(nodePtr); //get prev's next to nodePtr
                }
             
             nodePtr->setNext(t); //get nodePtr's next to point to where t points to
             break; //so you don't traverse rest of list once position found
         }
        
        prev = t;
        t = t->getNext(); //keep traversing
    
        }
    
    
    //CASE 3 - at end of list
    if (t == NULL) {
            prev->setNext(nodePtr); //the last node of list points to nodePtr's node, now you have inserted it to the end of the list
        
        }
    }
}


template <class T>
void List<T>::Append(Node<T> *ptrNode) {
    
    Node<T> *t = head; //temporary pointer so we can traverse list, points to where head points to
    
    //IF (START OF LIST)
    if (head==NULL) { //if the list is empty (meaning head points to NULL), you are at start of list
        head = ptrNode; //head points to where pointer node points to
        //next of ptrNode already set to NULL because of constructor
    }
    //ELSE (MIDDLE OR END OF LIST)
    else { // head != NULL, t points to where head points to, which is where ptrNode points to
        
        //WHILE (NOT AT END OF LIST)
        while (t -> getNext()) { //while t's next is not NULL, keep traversing list, not at end of list!
            t = t -> getNext(); //traverse list
            //t points to where n pointer is pointing to, so can check until a NULL 'next' pointer found
        } //reached end of list, node pointer points to last node, last node found
        
        // the new node being generated will be attached to the end of the list
        t -> setNext(ptrNode); // This line enables the new node created to have a next pointer and append node to previous node
        
        // list complete!
        
    }
}

template <class T>
void List<T>::Display(Node<T> * subSetPtr) { //start over, subSetPtr gets new value
    if (subSetPtr == NULL) {
        subSetPtr = head; //we are at head of list, let's go ahead and display
        cout << "\n------------------------LIST------------------------\n" << endl;
    }
    
    subSetPtr -> getObject() -> getInfo(); //display student in formation
    
    if (subSetPtr -> getNext() != NULL) { //if we are NOT at the head of the list
        Display(subSetPtr -> getNext()); //call the function at the next node. essentially traversing list
    }
}

template <class T>
void List<T>::Delete(string name) {
    
    if (head==NULL) { //no node to delete
        cout << "ERROR: No node to delete, student cannot be deleted." << endl;
    }
    else { //nodes to delete
        
        Node<T> *t = head; //a local pointer to find the node with target name
        Node<T> *prev = NULL; //pointer to keep track of previous node before target node
        
        //traverse list to find the previous node from the one specified
        while (t!=NULL) { //while not at end of list, traverse list!
            if (t->getObject()->getName() != name) {
                prev = t; //move prev to where t is pointing to
                t = t -> getNext(); //traverse
            }
            else if (t->getObject()->getName() == name) { // you have found name!
                if (prev==NULL) { //name at head of list
                    head = head->getNext();
                    //t->setNext(NULL);
                    }
                else { //name at middle or end of list
                    if (t->getNext()==NULL) { //at end of list
                        prev -> setNext(NULL);
                        }
                    else {
                        prev -> setNext(t->getNext()); //setNext() takes a pointer to node after node to delete, make prev point to where t points to
                        //t's next pointer points to where nPtr's next pointer points t
                        
                        }
                    }
                delete t;   //destructor! delete t pointer, which means connection to nodeToDelete is gone! t points to nothing
            }
        }
        
    }
    
}

template <class T>
void List<T>::bubbleSort() {

    Node<T> *t = head;
    Node<T> *prev = NULL;
    
    if (head==NULL) { //no node to delete
        cout << "ERROR: No nodes." << endl;
        }
    else {
        
        for(int i=0; i < getNumNodes()-1; i++) { //round A, B, etc.
            t = head; //reset to beginning of list
            prev = head;
            
            for(int j=i+1; j < getNumNodes(); j++) { //rounds A.a to A.k… etc
                Node<T> *next = t->getNext();
                    
                if(next->getObject()->getAge() < t->getObject()->getAge()) {
                    swap(next, t); //switch next's student information with t's student information
                    if (prev==NULL) { //at beginning
                        head = t; //head points to where t points to - beginning
                        }
                    }//end if next age greater than t age
                
                //keep traversing
                prev = t;
                t = next;
                    
            } //end loop j
        } //end for loop i
    } //end of else
}// end of function

template <class T>
void List<T>::swap(Node<T> * a, Node<T> * b) {
    T * tempPtr = a->getObject();
    a->setObject(b->getObject());
    b->setObject(tempPtr);
}

template <class T>
int List<T>::getNumNodes() { //how many nodes in the current list?
     int numNodes = 0; //CASE 1: NO NODES
    
    //CASE 2: COUNT HOW MANY NODES
    Node<T> *t = head; //start of list
        while (t!=NULL) { //while t points to something
            t = t -> getNext(); //traverse
            numNodes++; //increment how many nodes there are
        }
    return numNodes;
}

template <class T>
bool List<T>::isEmpty() {
    bool empty = true;
    if (head==NULL)
        empty=true;
    else {
        empty=false;
    }
    return empty;
}





#endif
