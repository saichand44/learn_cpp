#include <iostream>
#include <stack>
#include <string>

/*
Here we are checking the balancing of the paranthesis. We follow the steps
1. scan the expression from left to right (ignore characters that are not "()", "{}", "[]")
2. if there is an opening symbol, then we add that opening symbol to the stack
   using the push function in the stack.
3. if there is a closing symbol, then we check if it is corresponding to the last 
   opened symbol and if it, then we remove the opening symbol from the stack using pop.
4. if the expression is balanced, then the final outcome of the list is "empty".
*/

bool arePair(char openSymbol, char closeSymbol)
{   
    // This fucntion checks whether two characters are opening and closing pairs
    if (openSymbol=='(' && closeSymbol==')') return true;
    else if (openSymbol=='{' && closeSymbol=='}') return true;
    else if (openSymbol=='[' && closeSymbol==']') return true;
    else return false;
}

bool areParanthesesBalanced(std::string exp)
{
    // This fucntion checks if the parantheses are balanced
    std::stack<char> S;
    int exp_length = exp.length();
    std::cout << exp_length;
    // loop through the expression and check for opening and closing pair
    for (int i=0 ; i < exp_length ; i++)
    {   
        std::cout << exp[i];
        // ensure that we are pushing only the symbols of interest i.e. parantheses
        if (exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
        {
            S.push(exp[i]);
        }

        else if (exp[i]==')' || exp[i]=='}' || exp[i]==']')
        {
            if (S.empty() || !arePair(S.top(),exp[i]))
            {
                return false;
            }
            else
            {
                S.pop();
            }
        }
    }

    // check if the stack if empty and return true / false accordingly
    return S.empty()? true : false;
}

int main()
{
	/*Code to test the function AreParanthesesBalanced*/
	std::string expression;
	std::cout<<"Enter an expression:  "; // input expression from STDIN/Console
	std::cin>>expression;
	if(areParanthesesBalanced(expression))
		std::cout<<"Balanced\n";
	else
		std::cout<<"Not Balanced\n";
}