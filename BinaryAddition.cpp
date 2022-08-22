/*//^Given two binary numbers represented as strings, return the sum of the two binary numbers as a new binary represented as a string. Do this without converting the whole binary string into an integer.

Here's an example and some starter code.
def sum_binary(bin1, bin2):
  # Fill this in.

print(sum_binary("11101", "1011"))
# 101000
*/
#include <iostream>
#include <vector>
#include "util.h"

//& !!!! Note the problem is not solved correctly and will be updated soon !!!!

std::string binaryAddition(std::string num1, std::string num2)
{

    //& Checking which string is smaller and which is longer
    if(num1 > num2) 
        return binaryAddition(num2,num1);
    
    std::string result = "";

    for (int i = 0; i < num2.length() - num1.length(); i++) // leading or tailting zeros
    {
        result.push_back('0');
    }

    num1 = result + num1;
    std::string result2;
    char carry = '0';

    for (int i = num1.length(); i >= 0; i--)
    {

        if (num1[i] == '1' and num2[i] == '1')
        {

            if (carry == '1')
            {
                result2.push_back('1');
                carry = '1';
            }
            else
            {
                result2.push_back('0');
                carry = '1';
            }
        }

        else if (num1[i] == '0' and num2[i] == '0')
        {

            if (carry == '1')
            {
                result2.push_back('1');
                carry = '0';
            }

            else
            {
                result2.push_back('0');
                carry = '0';
            }
        }

        else if (num1[i] != num2[i])
        {
            if (carry == '1')
            {
                result2.push_back('0');
                carry = '1';
            }
            else
            {
                result2.push_back('1');
                carry = '0';
            }
        }
    }

    if (carry == '1')
    {
        result2.push_back(carry);
    }


    std::reverse(result2.begin(), result2.end());



    // std::cout << result2 << "\n";
    return result;
}

int main()
{
    std::cout<<binaryAddition("11101", "1011")<<"\n";
    std::cout<<binaryAddition("11", "10")<<"\n";

    return 0;
}