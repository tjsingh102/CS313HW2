//Header File: linkedStack.h 

#ifndef H_StackType
#define H_StackType
 
#include <iostream>
#include <cassert> 
 
#include "stackADT.h"

using namespace std;

//making node class so we can use it for a linked list type stack
template <class Type>
struct nodeType
{
    Type info; //will hold the data assigned into node and can be any type
    nodeType<Type> *link; //pointer to the next node in the linked list
};

template <class Type>
class linkedStackType: public stackADT<Type>
{
public:
    const linkedStackType<Type>& operator=
                              (const linkedStackType<Type>&);


    bool isEmptyStack() const; //checks if stack is empty, if it is then true


    bool isFullStack() const; //checks if stack is full


    void initializeStack(); //creates an empty stack


    void push(const Type& newItem); //adds elements to the top of the stack


    Type top() const; //returns the top of the stack unless it is empty


    void pop(); //removes element off the top of the stack


    linkedStackType(); //constructor 


    linkedStackType(const linkedStackType<Type>& otherStack); //copy construcor
  

    ~linkedStackType(); //destructor

private:
    nodeType<Type> *stackTop; //pointer to the stack

    void copyStack(const linkedStackType<Type>& otherStack); //copies the stack we pass in

};


    
template <class Type> 
linkedStackType<Type>::linkedStackType()
{ //constructor that will create empty stack
    stackTop = nullptr;
}

template <class Type>
bool linkedStackType<Type>::isEmptyStack() const
{ //return true if stack is empty, false if not
    return(stackTop == nullptr);
} 

template <class Type>
bool linkedStackType<Type>:: isFullStack() const
{ //returns false since we can always create more linked nodes
    return false;
} 

template <class Type>
void linkedStackType<Type>:: initializeStack()
{
    nodeType<Type> *temp; //temporary pointer 

    while (stackTop != nullptr) //traverse the stack until before the end
    {
        temp = stackTop; //temp will point to the top of the stack
                           
        stackTop = stackTop->link; //the dedicated top pointer will point to the next node
                                   
        delete temp; //delete the temporary pointer for memory
    }
} 

template <class Type>
void linkedStackType<Type>::push(const Type& newElement)
{
    nodeType<Type> *newNode; //pointer for the creation of a new node

    newNode = new nodeType<Type>; //make the node object

    newNode->info = newElement; //set the node to hold the passed in data
    newNode->link = stackTop; //the next node link will be put in the position the top of the stack is pointing to
    stackTop = newNode; //let the top point to this node now       
                             
} //end push


template <class Type>
Type linkedStackType<Type>::top() const
{
    assert(stackTop != nullptr); //checks if the stack is empty, if it is then exit program
                              
    return stackTop->info; //if it is not empty, return the data inside the top of the stack
}//end top

template <class Type>
void linkedStackType<Type>::pop()
{
    nodeType<Type> *temp;  //temporary pointer

    if (stackTop != nullptr) //traverse the stack
    {
        temp = stackTop;  //temporary will point to the top of the stack

        stackTop = stackTop->link; //then have the top of the stack pointer point to the linked node
                                    
        delete temp;    //then delete the "top" held in temp
    }
    else
        cout << "Cannot remove from an empty stack." << endl; //if it is empty then just print statement
}//end pop

template <class Type> 
void linkedStackType<Type>::copyStack
                     (const linkedStackType<Type>& otherStack)
{
    nodeType<Type> *newNode, *current, *last;

    if (stackTop != nullptr) //if it is not an empty stack
        initializeStack(); //call default constructor that makes an empty stack

    if (otherStack.stackTop == nullptr) //if the stack we passed in is empty
        stackTop = nullptr; //set the top of our stack empty as well
    else
    {
        current = otherStack.stackTop;  //current points to the top of our passed in stack that we want to copy

          
        stackTop = new nodeType<Type>;  //create a new node

        stackTop->info = current->info; //copy in the data 
        stackTop->link = nullptr;  //have the linked be set to nullptr
                               
        last = stackTop;        //"last" pointer will point to our created node so the last is the top of stack
        current = current->link;    //"current" will now point to the next node after current

           
        while (current != nullptr) //keep traversing until no more elements
        { //just copies the rest of the passed in stack following same logic as above statements
            newNode = new nodeType<Type>; 

            newNode->info = current->info;
            newNode->link = nullptr;
            last->link = newNode;
            last = newNode;
            current = current->link;
        }
    }
} 

 
template <class Type>   
linkedStackType<Type>::linkedStackType(
                      const linkedStackType<Type>& otherStack)
{ //copy stack
    stackTop = nullptr;
    copyStack(otherStack);
}

  
template <class Type> 
linkedStackType<Type>::~linkedStackType()
{ //destructor since the function called makes an empty stack
    initializeStack();
}
    
template <class Type>   
const linkedStackType<Type>& linkedStackType<Type>::operator=
    			  (const linkedStackType<Type>& otherStack)
{ //want to overload the assignment operator
    if (this != &otherStack) //if our stack is not the same as stack we passed in
        copyStack(otherStack); //copy the stack passed in

    return *this; 
}

#endif