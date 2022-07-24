/* Hi, here's your problem today. This problem was recently asked by Microsoft:

You are given an array of integers. Return the largest product that can be made by multiplying any 3 integers in the array.

Example:

[-4, -4, 2, 8] should return 128 as the largest product can be made by multiplying -4 * -4 * 8 = 128.
*/

#include <iostream>

int largest_product(int arr[], int n)
{
    int largest = 0;

    for (size_t i = 0; i <= n - 1; i++)
    {
        for (size_t j = i + 1; j <= n - 2; j++)
        {
            for (size_t k = j + 1; k < n; k++)
            {
                int product = (arr[i] * arr[j] * arr[k]);
                if (largest < product)
                {
                    std::cout << arr[i] << " " << arr[j] << " " << arr[k] << "\n";
                    largest = product;
                }
            }
        }
    }

    return largest;
}
int main()
{
    int n = 4;
    int arr[]{-4, -4, 2, 8};

    for (size_t i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << "\n"
              << largest_product(arr, n) << "\n";
    return 0;
}