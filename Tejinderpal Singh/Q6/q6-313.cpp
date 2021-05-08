#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;
void reverseWordsInString(string &str, int length)
{
    stack<char> tempStack; // stack that will hold letters that will be reversed
    char empty = ' ';      // first word case
    tempStack.push(empty); //the stacks first index needs to have a empty space that will come after the first word
    int i = 0;
    int k = 0;
    while (i < length) //while loop running until the strings length
    {
        if (isspace(str[i])) //using default c++ function "isspace" to check if the letter at the current index is a space
        {
            while (!tempStack.empty()) //until the stack is empty
            {
                str[k++] = tempStack.top(); //if the current letter in the string is a space,
                                            // take the letters that are currently in the stack and add them to the string
                tempStack.pop();            //empty the stack as you go so that each word is reversed and not the entire string
            }
        }
        tempStack.push(str[i]); // if the current letter is not a space, push it onto the stack
        i++;
    }

    while (!tempStack.empty()) //until the stack is empty
    {
        str[k++] = tempStack.top(); //loop that will add the last word in the stack to the string since there is no space at the end to enter the earlier loop
        tempStack.pop();
    }
}
int main()
{
    string line;
    ifstream myfile("ChuckNorrisJokes.txt"); //bring in the chuck norris file
    if (myfile.is_open())
    {
        while (getline(myfile, line)) //while there are remaining lines to be read
        {
            cout << endl
                 << "The Original Chuck Norris joke: " << line << endl; //while loop that will reverse each line one at a time
            reverseWordsInString(line, line.length());
            cout << "The Chuck Norris joke reveresed: " << line << endl
                 << endl;
        }
        myfile.close(); //closing the file
    }
}
