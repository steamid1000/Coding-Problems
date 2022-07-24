/*//^Given a sorted list with duplicates, and a target number n, find the range in which the number exists (represented as a tuple (low, high), both inclusive. If the number does not exist in the list, return (-1, -1)).

Here's some examples and some starter code.
def find_num(nums, target):
  # Fill this in.

print(find_num([1, 1, 3, 5, 7], 1))
# (0, 1)

print(find_num([1, 2, 3, 4], 5))
# (-1, -1)
*/

//* Mmore testing is required on the problem
#include <iostream>
#include "util.h"

void findRanges(int arr[], int size, int key) //^ TIme complexity of O(n);
{
    int range[2]{-1, -1};

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            range[0] = i; //^found the first index of the key

            if (arr[i + 1] != key)
            {
                range[1] = i;
                util::arr_dis(range, 2);
                return;
            }

            while (arr[i] == key and i < size)
            {
                range[1] = i; //^ this takes constant time O(1)
                i++; //^ incrementing the original index to save memory and computation time
            }

            util::arr_dis(range, 2);
            return;
        }
    }

    util::arr_dis(range,2);
}
int main()
{
    int elements[]{1, 1, 3, 5, 7};

    findRanges(elements, sizeof(elements) / sizeof(int), 1);

    int elem2[]{1, 2, 3, 4};
    findRanges(elem2,sizeof(elem2) / sizeof(int), 5);

    return 0;
}