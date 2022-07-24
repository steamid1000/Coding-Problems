/*Hi, here's your problem today. This problem was recently asked by Apple:

//^Given a string, we want to remove 2 adjacent characters that are the same, and repeat the process with the new string until we can no longer perform the operation.

Here's an example and some starter code:
def remove_adjacent_dup(s):
  # Fill this in.

print(remove_adjacent_dup("cabba"))
# Start with cabba
# After remove bb: caa
# After remove aa: c
# print c 
*/


#include <iostream>

std::string adjecentCharacterRemoval(std::string &input) //^ Simple recursion solution with a time complexicity of O (n + x), where x is the number of adjacent pairs
{
    for (int i = 0; i < input.length()-1; i++)
    {
        if (input[i]==input[i+1])
        {
            input.erase(i,2);
            return adjecentCharacterRemoval(input);
        }
        
    }

    return input;
    
}

int main()
{
    std::string input = "caabbaax";

    std::cout<<adjecentCharacterRemoval(input);
    return 0;
}