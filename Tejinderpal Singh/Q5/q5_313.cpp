#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Ar_Stack
{
private:
    int *array;
    int topStack; // parts of the stack
    int size;

public:
    Ar_Stack(int size_input)
    {
        size = size_input;     //takes in size and assigns it to the size variable
        array = new int[size]; //making a dynamic array of the size that is passed throughn
        topStack = 0;          //intializing the top of the stack to 0
    }

    void push(int x) //push function takes in a integer to push onto the stack
    {
        if (is_full()) //calls the is_full function and checks if the stack size is full
        {
            cout << "Stack Overflow" << endl; // displays error message if the stack is full
            return;
        }
        else
        {
            array[topStack++] = x; //else add the integer to the top of the satck
        }
    }

    void pop()
    {
        if (is_empty())
        {
            cout << "Stack Underflow\n"; //calls is_empty function to check if the stack is empty
        }
        else
        {
            array[topStack--] = 0; //take the integer that is at the top of the stack and set it to 0 while decreasing the value of topStack by 1
        }
    }

    void printStack()
    {
        cout << "\n"; //basic print function to print the stack from top down
        for (int i = topStack - 1; i >= 0; i--)
        {
            cout << "Pos[" << i << "] is: " << array[i] << endl;
        }
    }

    void top()
    {
        if (is_empty())
        {
            cout << "Empty stack!!\n"; //display error message if stack is empty
        }
        else
        {
            cout << array[topStack]; //else display the integer at the top of the stack
        }
    }

    bool is_empty()
    {
        return topStack == -1; //if topstacks value is negative return false
    }

    bool is_full()
    {
        return topStack == size; //if the top of the stack is equal to the size then return true
    }
    int position(int x)
    {
        return array[x]; // returns the integer at the x'th index
    }

    int LISLength(int size) //function that passes in the size of the stack passed in then outputs the longest increasing subsequence length
    {
        Ar_Stack lis(size); //creates a dummy stack that is the same size of the stack being checked

        lis.push(1);

        for (int i = 1; i < size; i++) //makes every postion of the lis(hence longest increasing...) stack  one
        {                              //because every postion has atleast a sequence of 1 being the number itself
            lis.array[i] = 1;
            for (int j = 0; j < i; j++) //inner loop that will check if the ith number is larger than the jth number
            {
                if (array[i] > array[j] && lis.array[i] < lis.array[j] + 1) // also checks if the jith in the lis array has a greater sequence tan the ith position
                {
                    lis.array[i] = lis.array[j] + 1; // if the value of value i is greater than j but the j has a greater squence, then has the same sequence of j because it comes after j
                }
            }
        }
        return *max_element(lis.array, lis.array + size); //using a c++ built in function that will return the largest integer that is in the lis stack which is reallt the LIS
    }
};

int main()
{
    int size = 10;

    Ar_Stack my_stack(size);
    srand(time(NULL));

    for (int i = 0; i < size; i++)
    {
        int x = rand() % 100 + 1; //psuhing random values into the stack
        my_stack.push(x);
    }

    my_stack.printStack();

    cout << endl
         << "The Longest Increasing Subsequence is of length: " << my_stack.LISLength(size) << endl; // displaing largest increasing subsequence
}