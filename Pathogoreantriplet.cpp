/* Hi, here's your problem today. This problem was recently asked by Uber:

Given a list of numbers, find if there exists a pythagorean triplet in that list. A pythagorean triplet is 3 variables a, b, c where a2 + b2 = c2

Example:
Input: [3, 5, 12, 5, 13]
Output: True
Here, 52 + 122 = 132.
*/

#include <iostream>
#include <math.h>

bool tripletpresent(int arr[],int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-1; j++) //time complexity of n^2 and constant space complexity (or O(n) space complexity)
        {
            if (i==j)
            {
                if (i==n-1) // if this is the last iteration, skipping it will go out of bounds
                {
                    break;
                }
                
                continue;
            }

            if(std::pow(arr[i],2) == std::pow(arr[j],2) + std::pow(arr[j+1],2))
            {
                return true;
            }
            
        }
        
    }

    return false;
    
}
int main()
{
    int arr[]{4, 5, 12, 5, 13};
    std::cout<<tripletpresent(arr,sizeof(arr)/sizeof(int));
    return 0;
}