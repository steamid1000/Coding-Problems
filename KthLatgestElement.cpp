/* Hi, here's your problem today. This problem was recently asked by Facebook:

Given a list, find the k-th largest element in the list.
Input: list = [3, 5, 2, 4, 6, 8], k = 3
Output: 5
*/

#include <iostream>
#include <algorithm>
#include <vector>

int sorting_method(int arr[], int size, int k) //if more then on copy of a element exists then this could give wrong answer
{
    std::sort(arr, arr + size);

    return arr[size - k];
}

int longWay_method(int arr[], int size, int k) //finding the third largest element in the array
{

    int largest_elements[3]{0};
    int index = 0;
    for (size_t i = 0; i < 3; i++)
    {
        int largest = arr[0];
        if (index == 0)
        {

            for (size_t j = 0; j < size; j++) //will get the first largest element from the array
            {
                if (largest < arr[j])
                {
                    largest = arr[j];
                }
            }

            largest_elements[index] = largest;
            index++;
        }
        else if (index == 1)
        {
            for (size_t j = 0; j < size; j++) //will get the first largest element from the array
            {
                if (largest < arr[j] and arr[j] != largest_elements[index - 1])
                {
                    largest = arr[j];
                }
            }

            largest_elements[index] = largest;
            index++;
        }
        else
        {
            for (size_t j = 0; j < size; j++) //will get the first largest element from the array
            {
                if (largest < arr[j] and arr[j] != largest_elements[index - 1] and arr[j] != largest_elements[index - 2])
                {
                    largest = arr[j];
                }
            }

            largest_elements[index] = largest;
            index++;
        }
    }


    //finally the returning the third largest element
    return largest_elements[2];
}

int removing_copies(int arr[], int size, int k) //this stores single occurence of a sorted array element in the vector and return the vector.size - k th element 
{
    std::sort(arr,arr+size); //sorting the array

    std::vector<int> another_Array;
    for (size_t i = 0; i < size-1; i++)
    {
        if (arr[i]==arr[i+1])
        {
            another_Array.push_back(arr[i]);
            i++; // experi
        }
        else{
            another_Array.push_back(arr[i]);
        }
    }

    return another_Array[another_Array.size()-k];
    
}
int main()
{
    int n = 6;
    int arr[6]{3, 5, 2, 2, 8, 8};
    int k = 3; // find the kth largest element in the array

    // std::cout<<sorting_method(arr,n,k)<<"\n";
    // std::cout << longWay_method(arr, n, k) << "\n";
    std::cout <<removing_copies(arr, n, k) << "\n";

    return 0;
};