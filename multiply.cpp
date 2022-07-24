/*//^Given two strings which represent non-negative integers, multiply the two numbers and return the product as a string as well. You should assume that the numbers may be sufficiently large such that the built-in integer type will not be able to store the input (Python does have BigNum, but assume it does not exist).

Here's an example and some starter code.
def multiply(str1, str2):
  # Fill this in.

print(multiply("11", "13"))
# 143
*/


#include <iostream>

std::string multiply(std::string num1,std::string num2)
{
    //^ Converting the string to long int value for multiplication
    long int Num1 = std::stoi(num1);
    long int Num2 = std::stoi(num2);

    long int result = Num1 * Num2;

    return std::to_string(result);


}
int main()
{
    std::cout<<multiply("11","13");
    return 0;
}