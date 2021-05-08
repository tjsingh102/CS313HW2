//***********************************************************
// Author: D.S. Malik
//
// Program: Postfix Calculator  
// This program evaluates postfix expressions.
//***********************************************************
  
#include <iostream>  
#include <iomanip>
#include <fstream>
#include "mystack.h"
 
using namespace std; 

//declarations of functions to define after main but will still allow us to call them in main
void evaluateExpression(ifstream& inpF, ofstream& outF, 
                        stackType<double>& stack,
                        char& ch, bool& isExpOk);
void evaluateOpr(ofstream& out, stackType<double>& stack,
                 char& ch, bool& isExpOk);
void discardExp(ifstream& in, ofstream& out, char& ch);
void printResult(ofstream& outF, stackType<double>& stack,
                 bool isExpOk);

int main()
{
    bool expressionOk;
    char ch;
    stackType<double> stack(100); //stack of size 100 that stores doubles is initialized
    ifstream infile;
    ofstream outfile;
 
    infile.open("RpnData.txt"); //accessing a file to read through

    if (!infile) //if the file does not exist then we exit program
    {
        cout << "Cannot open the input file. "
             << "Program terminates!" << endl;
        return 1;
    }
     
    outfile.open("RpnOutput.txt"); //open up the file we want to write into

    outfile << fixed << showpoint; //fixed will write floating point values in fixed point notation (with all its digits), showpoint prints with a decimal point
    outfile << setprecision(2); //sets number to have only 2 digits after the decimal

    infile >> ch; //taking in characters 
    while (infile) //traverse through the file we are reading from
    {
        stack.initializeStack(); 
        expressionOk = true; 
        outfile << ch; //outputting the same character we took in earlier

        evaluateExpression(infile, outfile, stack, ch, 
                           expressionOk);
        printResult(outfile, stack, expressionOk);
        infile >> ch; //begin processing the next expression
    } //end while 

    //close up the files we read in and wrote in 
    infile.close();
    outfile.close();

    return 0;

} //end main

//take in references to the read in file, the output file, the stack we initialized, the character we read in
void evaluateExpression(ifstream& inpF, ofstream& outF, stackType<double>& stack,char& ch, bool& isExpOk)
{
    double num;

    while (ch != '=') //as long as the character is not an equal sign
    {
        switch (ch) //set of different cases depending on the character 
        {
        case '#': //if it is a # symbol
            inpF >> num; //read in a double from input file
            outF << num << " "; //write the double in the output stream
            if (!stack.isFullStack()) //if stack is not full
                stack.push(num); //insert the double to the top of the stack
            else
            { //if stack is full exit program
                cout << "Stack overflow. "
                     << "Program terminates!" << endl;
                exit(0);  //terminate the program
            }

            break;
        default: //when none of the cases work then call the other function
            evaluateOpr(outF, stack, ch, isExpOk); 
        }//end switch

        if (isExpOk) //if no error
        {
            inpF >> ch; //read in the char
            outF << ch; //then output it

            if (ch != '#')
                outF << " "; //if the char isnt # then put a space
        }
        else
            discardExp(inpF, outF, ch); //if there is an error, call discard function
    } //end while (!= '=')
} //end evaluateExpression

//take in reference to the ofstream, stack, character, and whether the expression is fine
void evaluateOpr(ofstream& out, stackType<double>& stack,
              char& ch, bool& isExpOk)
{
    double op1, op2;

    if (stack.isEmptyStack()) //if no elements in the stack
    {
        out << " (Not enough operands)"; //output 
        isExpOk = false; //change the expression from good to not good
    }
    else //if the stack is not empty 
    {
        op2 = stack.top(); //set the op2 to the double at the top of the stack
        stack.pop(); //then remove this double from the top of the stack

        if (stack.isEmptyStack()) //repeat again to do a second time, if empty then output and change expression to error
        {
            out << " (Not enough operands)";
            isExpOk = false;
        }
        else
        {
            op1 = stack.top(); //now take the value of the new top of the stack 
            stack.pop(); //get rid of the top of the stack

            //more set of different cases depending on character
            switch (ch)
            {
            case '+': //if char is + then add the two numbers previously at the top of the stack and push it back on top
                stack.push(op1 + op2);
                break;
            case '-': //if char is - then subtract the two numbers previously at the top of the stack (the second top - first top) and push it back on top
                stack.push(op1 - op2); 
                break;
            case '*': //if char is * then multiply the two numbers previously at the top of the stack and push it back on top
                stack.push(op1 * op2);
                break;
            case '/': //if char is / then divie the two numbers previously at the top of the stack (the second top / first top) and push it back on top but only if the first top aka denominator isnt 0
                if (op2 != 0)
                    stack.push(op1 / op2);
                else
                { //if the denominator is 0 then it gives an error
                    out << " (Division by 0)";
                    isExpOk = false;
                }
                break;
            default:  //any other character besides these arithemtic operations is not allowed
                out << " (Illegal operator)";
                isExpOk = false;
            }//end switch
        } //end else
    } //end else
} //end evaluateOpr


void discardExp(ifstream& in, ofstream& out, char& ch)
{
    while (ch != '=') //keep taking in char as long as it isnt =
    {
        in.get(ch); //take in the char
        out << ch; //print char in the out stream
    }
} //end discardExp

void printResult(ofstream& outF, stackType<double>& stack,
                 bool isExpOk)
{
    double result;

    if (isExpOk) //if no error, print the result
    {
        if (!stack.isEmptyStack()) //if stack has elements
        {
            result = stack.top(); //put the top of the stack as the result
            stack.pop(); //take off the top

            if (stack.isEmptyStack())
                outF << result << endl; //output the result to the out stream only if the stack is empty after popping the top (result)
            else
                outF << " (Error: Too many operands)" << endl; 
        } //end if
        else
            outF << " (Error in the expression)" << endl; 
    }
    else
        outF << " (Error in the expression)" << endl;

    outF << "_________________________________" 
         << endl << endl;
} //end printResult