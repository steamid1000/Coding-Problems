/*//^ Given a sorted list of size n, with m unique elements (thus m < n), modify the list such that the first m unique elements in the list will be sorted, ignoring the rest of the list. Your solution should have a space complexity of O(1). Instead of returning the list (since you are just modifying the original list), you should return what m is.

Here's an example and some starter code.
def remove_dups(nums):
  # Fill this in.

nums = [1, 1, 2, 3, 4, 4, 4, 4, 4, 5, 5, 6, 7, 9]
print(remove_dups(nums))
# 8
print(nums)
# [1, 2, 3, 4, 5, 6, 7, 9]

*/

//& More work is needed on this problem as currently we are not changing the size of the list but just finding the unique elements and deleting dulplicates between them
#include <iostream>
#include "util.h"

int remove_Duplicate(int nums[],int size)
{
    
    int m = 0;
    for(int i = 0; i<size-1;i++)if(nums[i+1]<=nums[i]) m++; //^ Calculating the number of duplicates

    for (int i = 0; i < size; i++) //^Removing the duplicates in between
    {
       if (nums[i+1]<=nums[i])
       {    
            int temp = i+1;
            while (nums[temp]<=nums[i] and temp<size and i<size)
            {
                temp++;
                
            }
            
            nums[i+1] = nums[temp];
       }
       
       
        
    }

    // std::cout<<m<<"\n";

    return size - m;
}

int main()
{
    int nums[] = {1, 1, 2, 3,3, 4, 4, 4, 4, 4, 5, 5, 6, 7,7, 9,9};
    int size = sizeof(nums)/sizeof(int);

    int unique_items = remove_Duplicate(nums,size);
    std::cout<<"Unique Items: "<<unique_items<<'\n';
    util::arr_dis(nums,unique_items);




    return 0;
}