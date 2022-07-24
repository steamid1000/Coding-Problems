/*  Hi, here's your problem today. This problem was recently asked by Microsoft:

You are given an array of integers in an arbitrary order. Return whether or not it is possible to make the array non-decreasing by modifying at most 1 element to any value.

We define an array is non-decreasing if array[i] <= array[i + 1] holds for every i (1 <= i < n).

Example:

[13, 4, 7] should return true, since we can modify 13 to any value 4 or less, to make it non-decreasing.

[13, 4, 1] however, should return false, since there is no way to modify just one element to make the array non-decreasing.

*/
#include <iostream>
bool nonDecreasing(int arr[], int size)
{
    int greaterthenPrevious = 0;
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i + 1] < arr[i]) // if the next element is smaller then the current element
        {
            greaterthenPrevious++;
        }
    }

    if (greaterthenPrevious < 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int arr[]{13, 4, 7};
    int n = sizeof(arr) / sizeof(int);

    std::cout << nonDecreasing(arr, n) << "\n";

    int arr2[]{13, 4, 1};
    n = sizeof(arr2) / sizeof(int);

    std::cout << nonDecreasing(arr2, n) << "\n";

    return 0;
}