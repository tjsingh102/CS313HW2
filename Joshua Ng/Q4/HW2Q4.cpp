//Joshua Ng CS313 Homework 2 Question 4 
#include <iostream>
using namespace std;

//creating our own stack class to make wanted functions 
template <class T> //templated class so the stack can take in any type like int or string
class myStack{
    T* stackArray; //implement as an array
    int size; //size of stack
    int topOfStack; //keep the position of the last added value

    public: 
        //will create the stack based on the size wanted
        void initializeStack(int storage){
            stackArray = new T[storage]; //create an array of any type 
            size = storage;
            topOfStack = -1; //since it's empty we don't have a position for last added value
        }
        
        //push function typical of a stack
        void push(T nextVal){
            if(topOfStack == size - 1){ //if empty, output the line
                cout << "Not enough space on stack\n";
            }
            else{
                topOfStack++; //increment the position since we added a new value
                stackArray[topOfStack] = nextVal; //put the value passed in to function to the top position
                cout << nextVal << " was inserted\n";
            }
        }

        //pop function typical of a stack
        void pop(){
            if(topOfStack < 0){ //if empty, output line
                cout << "Nothing to pop\n";
            }
            else{ //decrement the top of the stack so that the top is pointing to the position below popped value
                cout << stackArray[topOfStack] << " was popped\n";
                topOfStack--;
            }
        }

        //prints the entire stack with the first element being on the bottom
        void printElements(){
            cout << "Stack:\n";
            int topOfStackCopy = topOfStack; //need copy (as an iterator) to keep top of stack consistent for other functions like another push afterwards (not to mess with the stack) 
            while(topOfStackCopy >= 0){ //iterate until the bottom of the stack
                cout << "\t" << stackArray[topOfStackCopy] << endl; //print out value in stack position
                topOfStackCopy--; //iterate down
            }
        }

        //function to change value at a specific position
        void changeValue(int position, T newVal){ //take in the position and the value you want to change to
            if(position > topOfStack) cout << "Nonexistant position\n";
            int iterator = topOfStack; //iterator variable will start at the top of the stack position
            while (iterator > position){ //iterate down the stack until we reach the position we want to change
                iterator--;
            }
            if(iterator == position){ 
                stackArray[iterator] = newVal; //set the value in the position we want to the new value we want
                cout << stackArray[iterator] << " is the new value at position " << position << endl;
            }
        }
};

int main(){
    int size = 100;

    //testing a stack with integer type
    myStack<int> i; //cast int to the stack class
    i.initializeStack(size); //create the stack of our size
    i.push(3); //call push function 
    i.push(4);
    i.push(5);
    i.pop(); //call pop function
    i.printElements(); //print every element
    i.changeValue(1, 2); //change the value in our given position
    i.printElements(); //print again to ensure the proper value was changed

    cout << endl << endl;

    //testing the stack again but with string type
    myStack<string> s;
    s.initializeStack(size);
    s.push("A");
    s.push("B");
    s.push("C");
    s.pop();
    s.printElements();
    s.changeValue(1, "D");
    s.printElements();
}