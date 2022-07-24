/*Hi, here's your problem today. This problem was recently asked by Uber:

Imagine you are building a compiler. Before running any code, the compiler must check that the parentheses in the program are balanced. Every opening bracket must have a corresponding closing bracket. We can approximate this using strings. 

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid. 
An input string is valid if:
- Open brackets are closed by the same type of brackets.
- Open brackets are closed in the correct order.
- Note that an empty string is also considered valid.*/

#include "bits/stdc++.h"
#define inp std::cin >>
#define out std::cout <<
int main()
{
    std::string input;
    short i;
    inp input;
    std::stack<char> stacks;

    for (i = 0; i < input.length(); i++) // O(n) time complexity
    {
        if (input[i] == '(' or input[i] == '{' or input[i] == '[')
        {
            stacks.push(input[i]); // pushing half of the string
        }

        if ((input[i] == ')' and stacks.top() == '(') or (input[i] == '}' and stacks.top() == '{') or (input[i] == ']' and stacks.top() == '['))
        {
            stacks.pop(); //pushing out if same and oppsite parathesis is found on the top index
        }
    }

    // std::cout<<stacks.size(); // size of the stack (checking)

    (stacks.size() == 0) ? out "True\n" : out "False\n";

    return 0;
}
