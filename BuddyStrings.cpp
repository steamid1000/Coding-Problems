/* Hi, here's your problem today. This problem was recently asked by AirBNB:

Given two strings A and B of lowercase letters, return true if and only if we can swap two letters in A so that the result equals B.

Example 1:
Input: A = "ab", B = "ba"
Output: true
Example 2:

Input: A = "ab", B = "ab"
Output: false
Example 3:
Input: A = "aa", B = "aa"
Output: true
Example 4:
Input: A = "aaaaaaabc", B = "aaaaaaacb"
Output: true
Example 5:
Input: A = "", B = "aa"
Output: false
*/

#include <iostream>

bool buddyString(std::string a, std::string b)
{
    int diff = 0;

    if (a.length()==0 or b.length()==0)
    {
        return false;
    }
    
    for (size_t i = 0; i < b.length(); i++)
    {
        if (a[i]!=b[i])
        {
            diff++;
        }
        
    }

    if (diff<3)
    {
        return true;
    }
    
    return false;
    
        
}
int main()
{
    std::string A = "ab", B = "ba";

    std::cout<<buddyString(A,B);
    return 0;
}