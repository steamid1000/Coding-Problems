//Hi, here's your problem today. This problem was recently asked by Facebook:

/*//*You are given a list of numbers, and a target number k. Return whether or not there are two numbers in the list that add up to k.

Example:
Given [4, 7, 1 , -3, 2] and k = 5, 
return true since 4 + 1 = 5.
*/
#include <iostream>
#include <algorithm>

void swap(int arr[], int i, int j) // function to swap elements of the array
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
bool target_finder_bruteForce(int arr[], int size, int tar)
{
    for (short i = 0; i < size; i++) // brute force method O(n*n) or O(n2)
    {
        for (short j = 0; j < size; j++)
        {
            if (j == i)
            {
                continue; //this is to avoid counting the same elements as two different elements
            }

            if (arr[i] + arr[j] == tar)
            {
                // std::cout<<arr[i]<<" "<<arr[j]<<"\n";/
                return true;
                break; // likely will not be executed but for security reasons
            }
        }
    }

    return false; // if the target is not found even after treversing the array
}

bool target_finder_optimized(int arr[], int size, int target)
{

    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > target)
        {
            break;
        }

        if (arr[i] < target and sum + arr[i] != target)
        {
            sum = arr[i];
            continue;
        }

        if (arr[i] < target and sum + arr[i] == target)
        {
            return true;
        }

        if (sum + arr[i] != target)
        {
            sum = arr[i];
        }

        std::cout << sum << "\n";
    }

    return false;
}

void sort(int arr[], int size)
{
    for (short i = 0; i < size; i++)
    {
        for (short j = 0; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr, i, j);
            }
        }
    }
}

void print_array(int arr[], int size)
{
    for (short i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}
int main()
{
    int array[]{4, 7, 1, -3, 2};
    int size = sizeof(array) / sizeof(int); // size of the array

    int target = 5; //target to search in the array

    std::cout << target_finder_bruteForce(array, size, target) << "\n";

    // sort(array,size);

    // std::sort(array, array + size);

    print_array(array, size);
    std::cout << target_finder_optimized(array, size, target);

    return 0;
}