/*//^Given a list of sorted numbers, and two integers k and x, find k closest numbers to the pivot x.

Here's an example and some starter code:
def closest_nums(nums, k, x):
 # Fill this in.

print(closest_nums([1, 3, 7, 8, 9], 3, 5))
//& # [7, 3, 8]
*/

#include <iostream>
#include <vector>
#include "util.h"

void kClosestElemtents(int num[], int size, int numberOfElements, int pivot) //* Lets brute-force shall we
{
    int closest;
    std::vector<int> differences;
    std::vector<int> output;
    short visited[size]{0}; //^ this will tell us weither we have visited that elemenr before

    //^ Calculating the  difference of each element from the pivot
    for (int i = 0; i < size; i++)
    {
        if (num[i] <= pivot)
        {
            differences.push_back(pivot - num[i]);
        }
        else
        {
            differences.push_back(num[i] - pivot);
        }
    }

    //^ The problem with soritng the diffrence vector will be that we will lose the indexes so for now we will use a computiion heavy technique to get around this issue
    for (int i = 0; i < size; i++)
    {
        if (output.size() == numberOfElements) //* if the all the asked number of elements are filled then break the loop
        {
            break;
        }

        int closest = differences[0];
        int index = i;
        for (int j = 0; j < size; j++)
        {
            if (differences[j] <= closest and visited[j] == 0)
            {
                closest = differences[j];
                index = j;
            }
        }

        if (visited[index] == 0)
        {

            visited[index] = 1; //? Updating the visited array to avoid adding it again
            output.push_back(num[index]);
        }
    }

    util::display_vector(output);
    std::cout << "Size of the output vector: " << output.size() << "\n";
}

int main()
{
    int sizeOfTheArray = 7;
    int elements[sizeOfTheArray]{1,2, 3, 4, 7, 8, 9}; //^ For some reason it can find only n-1 closest elements 
    int pivot = 6, number_of_elements = 3;

    kClosestElemtents(elements, sizeOfTheArray, number_of_elements, pivot);

    return 0;
}