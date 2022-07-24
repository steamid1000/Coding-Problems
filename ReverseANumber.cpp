//*Given an integer, reverse the digits. Do not convert the integer into a string and reverse it.
/*
Here's some examples and some starter code.
def reverse_integer(num):
  # Fill this in.

print(reverse_integer(135))
# 531

print(reverse_integer(-321))
# -123
*/

#include <iostream>

int reverseNumber(int num)
{

    int rev = 0;
    while (num !=0) //& normal num>0 will not work here as the negative number is already less than 0 so this is the solution
    {
        int rem = num % 10;
        rev = rev * 10 + rem;
        num = num / 10;
    }
        num = rev;
    

    return num;
}
int main()
{
    std::cout << reverseNumber(135) << "\n";
    std::cout << reverseNumber(-321) << "\n";


    return 0;
}