#include <iostream>
#include <stack>
#include <string>

/*
Infix to postfix conversion. We follow the steps below
1. We use a list / stack to store the operands as we scan the expression and keep
   adding the operands 
2. Whenever we encounter an operator, we will check the precedence of the current 
   operator with the top of the stack, and if the top of stack is of higher precedence
   than the current operator, then we pop the top element and append it to the post
   fix expression, and then push the current operator to the stack. Addtionally,
   we also check for brackets opening and closing.
*/

bool isOperator(char c)
{   
    // check if the character in the expression is an operator
    if (c == '+' || c == '-' || c == '*' || c == '/') return true;
    else return false;
}

bool isOperand(char c)
{
    // check if the character in the expression is an operand
    if (c >= '0' && c <= '9') return true;
    else if (c >= 'a' && c <= 'z') return true;
    else if (c >= 'A' && c <= 'Z') return true;
    else return false;
}

int getOperatorWeight(char operatorChar)
{
    int weight = -1;
    switch(operatorChar)
    {
	case '+':
	case '-':
		weight = 1;
        break;
	case '*':
	case '/':
		weight = 2;
        break;
	case '$':
		weight = 3;
        break;
    }
    return weight;
}

bool hasHigherPrecedence(char operator1, char operator2)
{
    // check the precedence between the operators
    int op1weight = getOperatorWeight(operator1);
    int op2weight = getOperatorWeight(operator2);

    return op1weight > op2weight? true: false;
}

std::string infixToPostfix(std::string expression)
{
    // declare a stack to store the operators
    std::stack<char> S;

    // initialize a postfix string to which we append the char
    std::string postfix = "";

    // get the length of the expression
    int exp_length = expression.length();

    // loop through the expression
    for (int i=0 ; i < exp_length; i++)
    {   
        // continue parsing the expression if we encounter space or comma
        if (expression[i] == ' ' || expression[i] == ',')
        {
            continue;
        } 

        // when char isoperand
        else if (isOperand(expression[i]))
        {
            postfix += expression[i];
        }

        // when char is operator
        else if (isOperator(expression[i]))
        {
            while(!S.empty() && S.top() != '(' && hasHigherPrecedence(S.top(), expression[i]))
            {
                postfix += S.top();
                S.pop();
            }
            S.push(expression[i]);
        }

        else if (expression[i] == '(')
        {
            S.push(expression[i]);
        }

        else if (expression[i] == ')')
        {
            while(!S.empty() && S.top() != '(')
            {
                postfix += S.top();
                S.pop();
            }

            // to pop the char '(' which is left at the end of while loop
            S.pop(); 
        }
    }

    // pop all the remaining operators in the stack and add them to the postfix
	while(!S.empty()) 
    {
		postfix += S.top();
		S.pop();
	}
    return postfix;
}

int main()
{
    std::string expression;
    std::cout << "Enter the infix expression: ";
    std::getline(std::cin, expression);
    std::string postfix = infixToPostfix(expression);
    std::cout << "Infix to Postfix: " << postfix << std::endl;
}