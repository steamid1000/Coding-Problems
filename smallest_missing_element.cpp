/* Hi, here's your problem today. This problem was recently asked by Facebook:

You are given an array of integers. Return the smallest positive integer that is not present in the array. The array may contain duplicate entries.

For example, the input [3, 4, -1, 1] should return 2 because it is the smallest positive integer that doesn't exist in the array.

Your solution should run in linear time and use constant space.

Here's your starting point:
*/

#include <iostream>
#include <algorithm>

int find_missing_ele(int arr[], int n) // we will modify the array and sort it first in this method
{
    std::sort(arr, arr + n); // sorting the array

    for (size_t i = 0; i < n - 1; i++)
    {
        if (arr[i] <= 0) // as the 0 is not considered a positive so this will skip
        {
            continue;
        }

        if (arr[i + 1] != arr[i] and arr[i + 1] != arr[i] + 1) // the next element should be either same as the last element or greater then 1 of the last element
        {
            return arr[i] + 1; // this will be the missing positive interger element in the array
        }
    }

    return -1; // all the elements in the range is present in the array
}
int main()
{
    int ele[]{3, 4, -1, 1, 2, 6}; // the 0 is not considered a positive integer nor a negative integer

    int res = find_missing_ele(ele, sizeof(ele) / sizeof(int)); // sending arr and its size to the function

    std::cout << res << "\n";

    return 0;
}