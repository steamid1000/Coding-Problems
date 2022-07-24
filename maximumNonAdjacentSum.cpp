/*//^Given a list of positive numbers, find the largest possible set such that no elements are adjacent numbers of each other.

Here's some example and some starter code
def maxNonAdjacentSum(nums):
  # Fill this in.
  
print(maxNonAdjacentSum([3, 4, 1, 1]))
# 5
# max sum is 4 (index 1) + 1 (index 3)

print(maxNonAdjacentSum([2, 1, 2, 7, 3]))
# 9
# max sum is 2 (index 0) + 7 (index 3)
*/

#include <iostream>
#include <vector>
#include "util.h"

int maxNonAdjacentSum(int nums[],int size)
{   
    int maxSum = INT_MIN; //^ thos will store the max sum

    for(int i = 0;i<size;i++)
    {
        int sumOfPair = 0;
        for(int j = i+1;j<size;j+=2)
        {
            sumOfPair += nums[j];
        }
        
        if (sumOfPair>maxSum)
        {
          maxSum = sumOfPair;
        }
        
    }
    return maxSum;
}

int main()
{
    int nums[]{3, 4, 1, 1};
    int size = sizeof(nums) / sizeof(int);
    std::cout<<maxNonAdjacentSum(nums,size)<<"\n";
    return 0;
}