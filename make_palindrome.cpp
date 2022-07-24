/*
Given a string, determine if you can remove any character to create a palindrome.

Here's some examples and some starter code:
def create_palindrome(s):
  # Fill this in.

^print(create_palindrome("abcdcbea"))
?# True
^print(create_palindrome("abccba"))
?# False
^print(create_palindrome("abccaa"))
?# False
*/

#include <iostream>
#include "util.h"

bool palindrome_maker(std::string input) //* Brute Force apporach, time complexcity of O(n + n-i)
{
    //^ as if the string is alreeady a palindrome then removing any character will make it a non-paindrome so we will return false if thet is the case
    if (util::isPalin(input))
    {
        //std::cout<<"Triggered base condition\n";
        return false;
    }
    

    for (size_t i = 0; i < input.length(); i++)
    {
        std::string temp = input;

        temp.erase(i,1); //! This will remove the current element and then we will check if the new string is a palindrome or not

        if (util::isPalin(temp)) //& if this fucntion return true then return true as the answer or continue ahead
        {
            return true;
        }
        
    }
    
    return false;
}


int main()
{
    std::string input = "abcdba";

    std::cout<<palindrome_maker(input);

    return 0;
}