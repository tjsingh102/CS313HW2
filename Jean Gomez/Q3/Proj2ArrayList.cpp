#include <iostream>
#include <stdlib.h>     
#include <time.h>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

class Ar_Stack {
    private:
        int *array;
        int topStack;
        int size;
    public:
        // initializing the array stack to size s
        Ar_Stack(int s=1000005){
            size = s;
            array = new int[size];
            //everytime we push a int onto our stack we increase the topstack by 1 so it'll have the same index as our last element that we pushed on
            topStack = -1;
        }
        void push(int x);
        void pop();
        void printStack();
        void top();
        bool is_empty();
        bool is_full();
};

void Ar_Stack::push(int x) {
    //check if the array is full and we can keep pushing elements onto our stack
    if(is_full()){
        cout<<"Stack Overflow"<<endl;
    }
    // if not full we move over in the index's and set it equal to the integer we are passing in
    else{
       array[topStack++] = x; 
    }
    // cout<<"Push to stack\n";
    
}

void Ar_Stack::pop() {
    //if the stack is empty then we output the string 
    if(is_empty()) {
        cout<<"Stack Underflow\n";
    }
    // else we decrement the size of our array and set that value equal to 0
    else{
        array[topStack--] = 0;
    }
}

void Ar_Stack::printStack() {
    cout<<"\n";
    // start at the top of stack and print out the value at the index then we decrement till we have no more elements
    for(int i = topStack; i >= 0; i--) {
        cout<<"Pos["<<i<<"] is: "<<array[i]<<endl;
    }
}

void Ar_Stack::top() {
    // if our stack is empty there is no topStack
    if(is_empty()){
        cout<<"Empty stack!!\n";
    }
    // topstack is suppose to have the same index as the latest int we push onto our stack
    else{
        cout<<array[topStack];
    }
}

bool Ar_Stack::is_empty() {
    // topStack is only -1 when there is no elements on our stack so if this condition is true
    // topstack is empty if not it'll return false
    return topStack == -1;
}

bool Ar_Stack::is_full(){
    // once top stack is set to our initial size-1 the stack will be fulled leaving no more space for ints to be pushed on
    return topStack == size - 1; 
}

int main() {
    Ar_Stack my_stack;
    srand(time(NULL));

    auto start = high_resolution_clock::now();
    //loop will run a million times and set x equal to a random value each time
    for(int i = 0; i < 1000001; i++) {
        int x = rand() % 1000 + 1;
        my_stack.push(x);
    }

    // pop off the topstack afterwards until it is empty
    for (int j = 0; j < 1000001; j++) {
        my_stack.pop();
    }
    

    auto end = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(end - start).count();

    cout << "Time taken by function: "<< duration<< " microseconds" << endl;
}
