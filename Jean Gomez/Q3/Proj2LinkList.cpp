#include <iostream>
#include <stdlib.h>     
#include <time.h>    
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

struct node {
    int data;
    node* nextN;
};


class LinkedStack {
    private:
    node *head, *top;
    public:
    LinkedStack() {
        head = nullptr;
        top = nullptr;
    }


    bool isEmpty()  { // checks if node is empty //
        if (top == nullptr) // Checks if the first node is empty & will return true if it is, else false
        {
            return true;
        }
        else{ 
            return false;
        }
    }

    void push(int value) { // insert 1 value
      node *n = new node();
      n->data = value; //set new node data to the value we passed in
      n->nextN = top; // set the nextN to point to nullptr;
      top = n; // set the top node pointer to point to the latest node we pushed onto our stack 
      // our first node points to nullptr and each node after that will point to the previous node
      //we update our top node each time we push onto our stack to be the last node we passed in 
    }

    void pop() {
        if(isEmpty()){  // if stack is empty print string
            cout<<"\nStack is Empty!\n";
        }
        else{
            node* n = top; // n will equal top node
            top = top->nextN; // set top to equal to the previous node
            delete(n); // delete the top node

        }
    }

    void topofStack() {
        if(isEmpty()) {// if empty no top node
            cout<<"Stack is empty!\n";
        }
        else { // top will be set to the last node we pushed onto stack so we output the data
            cout<<"Top is: "<<top->data<<endl;
        }
    }

    void printlist() {
        while(top != nullptr) { // while the stack is not empty print out the data values of each node
            cout<<"[ "<<top->data<<" ]"<<endl;
            top = top->nextN; // after printing out the top stack set top equal to the node before it
        }
    }

};

int main() {
    srand(time(NULL));
    LinkedStack myStack;

    auto start = high_resolution_clock::now();

    for(int i = 0; i < 1000001; i++) {
        int x = rand() % 50 + 1;
        myStack.push(x);
    }
    
    //pop
    for (int j = 0; j < 1000001; j++) {
        myStack.pop();
    }
    
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();

    cout << "Time taken by function: "<< duration<< " microseconds" << endl;
}