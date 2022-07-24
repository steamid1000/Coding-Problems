/*Hi, here's your problem today. This problem was recently asked by Twitter:

Given an array of integers of size n, where all elements are between 1 and n inclusive, find all of the elements of [1, n] that do not appear in the array. Some numbers may appear more than once.

Example:
Input: [4,5,2,6,8,2,1,5]
Output: [3,7]
*/

#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> missing_num(int *arr,int n)
{
    std::sort(arr,arr+n);

    //main logic

    std::vector<int> list;
    for (int i = 0; i < n-1; i++)
    {
        if (arr[i+1]!=arr[i] and arr[i+1]!=arr[i]+1)
        {
            list.push_back(arr[i]+1); //pushing the current element plus 1
        }
        
    }


    return list;
    
}

int main()
{
    int n = 8;
    int arr[n]{4,5,2,6,8,2,1,5};
    int arrs[7]{4,6,2,6,7,2,1};


    std::vector<int> missing_elems = missing_num(arr,n);
    
    std::vector<int> missing_elems2 = missing_num(arrs,7);

    

    for (auto i : missing_elems2)
    {
        std::cout<<i<<" ";
    }
    
    return 0;
}



// ^ check later if it cane be optimized further