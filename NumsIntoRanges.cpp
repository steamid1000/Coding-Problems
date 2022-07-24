/* Hi, here's your problem today. This problem was recently asked by Facebook:

Given a sorted list of numbers, return a list of strings that represent all of the consecutive numbers.

Example:
Input: [0, 1, 2, 5, 7, 8, 9, 9, 10, 11, 15]
Output: ['0->2', '5->5', '7->11', '15->15']
Assume that all numbers will be greater than or equal to 0, and each element can repeat.
*/

#include <iostream>
#include <vector>

std::vector<std::string> find_ranges(int *arr, int n)
{
    std::vector<std::string> range; //! this vector woll be returned

    //& Brute Force Approach (little bit improved then the original bruteforce apparch which had two for loops)

   for (int i = 0; i < n; i++)  //! Time Complexity: O (n) as the index is set to the last index of the range which prevents recounting or reconsidering
   {
       int start = i;   //^ Two pointer to record the number of valid elements in that range
       int end = i;
       while (arr[end+1]==arr[end] or arr[end+1]==arr[end]+1) 
       {
           //* While next element is equal to the current element or until the next element is equal to the current + 1
           //^ For single blocks (i.e 5->5) the start and end will be at the same position
           end++;
       }

       range.push_back(std::to_string(arr[start])+"->"+std::to_string(arr[end]));
       i = end; //! Updating the i to the last point of the range to avoid considering them agian 
       
   }
   

    return range;
}

void display(std::vector<std::string> arr)
{
    for (auto i : arr)
    {
        std::cout << i << "\n";
    }
}

int main()
{

    int n = 11;
    int arr[n]{0, 1, 2, 5, 7, 8, 9, 9, 10, 11, 15};

    //^ IMP point the array is already sorted

    std::vector<std::string> ranges = find_ranges(arr, n);
    display(ranges);

 

    return 0;
}