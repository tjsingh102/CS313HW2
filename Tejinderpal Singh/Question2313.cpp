#include <iostream>
#include <stack>
using namespace std;

bool OperandCheck(char z)
{
    if (isdigit(z))
    {
        return true; //checks if the current character is a digit by using the built in c++ function and returning the result
    }
    else
        return false;
}

double EvaluateExpression(string exp)
{
    stack<double> Stack;

    for (int i = exp.size() - 1; i >= 0; i--) // starting the for loop with i at the end of the string
    {
        if (OperandCheck(exp[i])) //if the operand is a digit, then push it onto the stack
        {
            Stack.push(exp[i] - '0');
        }
        else // if the current character is not a digit then continue
        {
            double o1 = Stack.top(); // storing the top digits in a double by popping then in order to perform operations
            Stack.pop();
            double o2 = Stack.top();
            Stack.pop();

            switch (exp[i]) //using switch we will check which character is at the ith position and perform the chosen operation
            {
            case '+': // adding the two digits and pushing them onto the stack
                Stack.push(o1 + o2);
                break;
            case '-': //subtracting the two operands and pushing them onto the stack
                Stack.push(o1 - o2);
                break;
            case '/': // dividing the two digits and pushing them onto the stack
                if (o2 != 0)
                    Stack.push(o1 / o2);
                else
                {
                    cout << " (Division by 0) "; //if the dividend is 0 then display this error
                }
                break;
            case '*': //multiplying the two digits and push them onto the stack
                Stack.push(o1 * o2);
                break;
            }
        }
    }
    return Stack.top();     //returning the top of the stack which would now contain the final result 
}
int main()
{
    string exp = "+5*4-14";
    cout << "Prefix expression result: " << EvaluateExpression(exp) << endl;
}