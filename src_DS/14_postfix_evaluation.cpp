#include <iostream>
#include <string>
#include <stack>
/*
Evaluation of a postfix expression. Here we use the following steps
1. We use a list / stack to store the operands as we scan the expression and keep
   adding the operands 
2. Whenever we encounter an operator, we pop the last two oprands from the stack 
   and perform the operation corresponding to the operator and then push the
   result into the stack again
3. We do this step until we scan the entire expression and in the end we are only
   left with a single value which is the  
*/

// to check whether the character we scanned is a number or operator, we need
// functions

bool isNumericChar(char c)
{   
    // check if the character in the expression is a number
    if (c>='0' && c<='9') return true;
    else return false;
}

bool isOperatorChar(char c)
{
    // check if the character in the expression is a operator
    if (c == '+' || c == '-' || c == '*' || c == '/') return true;
    else return false;
}

int performOperation(int operand1, int operand2, char operation)
{   
    // perform the given operation on the operands
    if (operation == '+') return operand1 + operand2;
    else if (operation == '-') return operand1 - operand2;
    else if (operation == '*') return operand1 * operand2;
    else if (operation == '/') return operand1 / operand2;

	else 
    {
        std::cout << "Unexpected Error" << std::endl;
	    return -1;
    }
}

int evaluatePostfix(std::string expression)
{
    // initialize a stack in which we store the numbers
    std::stack<int> S;

    // get the length of the expression
    int exp_length = expression.length();

    for(int i=0; i < exp_length; i++)
    {
		// Scanning each character from left. 
		// If character is a delimitter, move on. 
		if(expression[i] == ' ' || expression[i] == ',') continue; 

        // if character is an operator, pop two elements from the stack and perfomr
        // the operation and push the result back into the stack
        else if (isOperatorChar(expression[i]))
        {
            // get the latest number from the stack and pop (Do it for two times)
            int operand1 = S.top(); S.pop();
            int operand2 = S.top(); S.pop();

            int result = performOperation(operand1, operand2, expression[i]);
            S.push(result);
        }

        // if character is an operand, then push the elements into the stack
        else if (isNumericChar(expression[i]))
        {
            int operand = 0;

            // loop until we are getting the numneric digits (to capture numbers > 10)
            while(i<exp_length && isNumericChar(expression[i]))
            {   
                /*
                For the case of the number 123,
                a) operand = (0*10) + 1
                b) operand = (1*10) + 2
                c) operand = (12*10) + 3 = 123
                Using this method, we don't have to worry about the number of 
                digits in the number. Here we keep multiplying the digits by 10
                and that takes care of the numeric representation in base 10 
                */
                operand = (operand*10) + (expression[i]-'0');
                i++;
            }

            // top avoid double increment of "i" due to the while loop (after scanning)
            // the number and due to the for loop, we decrease "i" to avoid skipping
            // characters in the expression
            i--;

            // push the numbers to the stack
            S.push(operand);
        }
    }

    // return the final result of the expression
    return S.top();
}

int main()
{
    std::string expression;
    std::cout<<"Enter an expression:  "; // input expression from STDIN/Console
    std::getline(std::cin,expression);
    int result = evaluatePostfix(expression);
    std::cout << "Evaluation result: " << result << std::endl;
}