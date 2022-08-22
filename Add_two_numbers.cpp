//Hi, here's your problem today. This problem was recently asked by Facebook:

/*//*You are given a list of numbers, and a target number k. Return whether or not there are two numbers in the list that add up to k.

Example:
Given [4, 7, 1 , -3, 2] and k = 5, 
return true since 4 + 1 = 5.
*/
#include <iostream>
#include <algorithm>


bool target_finder_bruteForce(int arr[], int size, int tar) //^ O (n x n)
{
   
    for (short i = 0; i < size; i++) 
    {
        for (short j = 0; j < size; j++)
        {
           
            if (j == i or arr[j]>=tar)
            {
                continue; //this is to avoid counting the same elements as two different elements
            }

            if (arr[i] + arr[j] == tar)
            {
                return true;
            }
        }
    }

    return false; // if the target is not found even after treversing the array

}

int main()
{
    int array[]{4, 7, 1, -3, 2};
    int size = sizeof(array) / sizeof(int); // size of the array

    int target = 1; //target to search in the array

    std::cout << target_finder_bruteForce(array, size, target) << "\n";

    return 0;
}