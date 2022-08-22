/*A Perfect Number is a positive integer that is equal to the sum of all its positive divisors except itself.

For instance,
28 = 1 + 2 + 4 + 7 + 14

Write a function to determine if a number is a perfect number.
*/

#include <iostream>

bool isPerfectNumber(int num)
{
    int sum = 0;

    for (int i = 1; i <= num/2; i++)
    {
        if (num%i==0)
        {
            //^std::cout<<i<<' '; uncomment this to see the number adding upto sum
            sum+=i;
        }
        if(sum>num) break; //^ will save some iterations
        
    }
    // std::cout<<'\n';

    //^ checking if the sum is the same as the original number
    if (sum==num)
        return true;
    

    return false; //^ else return false
    
}
int main()
{
    std::cout<<isPerfectNumber(28)<<'\n';
    std::cout<<isPerfectNumber(6)<<'\n'; //^ 1 + 2 + 3 = 6
    std::cout<<isPerfectNumber(10); //^ 1 + 2 + 5 = 8 != 10
    return 0;
}