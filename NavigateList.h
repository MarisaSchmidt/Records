//  NavigateList.h
//  
//
//  Created by Marisa Schmidt on 11/25/14.
//
//

#ifndef _____D__
#define _____D__

#include <stdio.h>
#include "PersonData.h"
using namespace std;


template <class T>
class Node {
    
public:
    Node ();
    ~Node();
    Node(T *);
    Node *getNext();
    T *getObject(); 
    void setNext(Node<T>* );
    void setObject(T *);
    
private:
    Node *next;
    T *tPtr;
};


template <class T>
Node<T>::Node() {
    next = NULL; //default value next
    tPtr = NULL; //default value sPtr
}

template <class T>
Node<T>::~Node() {
    //if (tPtr!=NULL) {
      //  tPtr = NULL;
        delete tPtr;
        //}
}

template <class T>
Node<T>::Node( T *tempPtr ) {
    tPtr = tempPtr; //sPtr points to where s pointer points to
    next = NULL; //default value next
}

template <class T>
Node<T> * Node<T>::getNext(){
    return next; //where that next pointer is pointing to
}

template <class T>
T* Node<T>::getObject(){
    return tPtr; //where that sPtr is pointing to
}

template <class T>
void Node<T>::setObject( T *ttptr){
    tPtr = ttptr;
}

template <class T>
void Node<T>::setNext(Node<T>* n) {
    next = n; //set next pointer to where n
