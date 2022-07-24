/* Hi, here's your problem today. This problem was recently asked by Google:

Given a list of numbers with only 3 unique numbers (1, 2, 3), sort the list in O(n) time.

Example 1:
Input: [3, 3, 2, 1, 3, 2, 1]
Output: [1, 1, 2, 2, 3, 3, 3]
*/

#include <iostream>

void swap(int arr[], int i, int j) //swaping function for elements
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void three_element_sort(int arr[], int n)
{
    int low = 0; //creating three pointer to sort the array ( DNF )
    int mid = 0;
    int high = n - 1;

    //experimental
    // int i = 0;
    while (mid != high)
    {
        if (arr[mid] == 3)
        {
            swap(arr, mid, high);
            high--;
        }

        if (arr[mid] == 1)
        {
            swap(arr, mid, low);
            mid++;
            low++;
        }

        if (arr[mid] == 2)
        {
            mid++;
        }
    }

    //final printing
    for (size_t i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
}
int main()
{
    int n = 16;
    int arr[16]{3, 3, 2, 1, 3, 2, 1, 1, 1, 2, 3, 3, 2, 2, 1, 2};

    three_element_sort(arr, n);

    return 0;
}