/* Hi, here's your problem today. This problem was recently asked by Apple:

Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library’s sort function for this problem.

Can you do this in a single pass?

Example:
Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
*/

#include <iostream>

void swap(int arr[],int i,int j){ // function to swap to elements at i and j
    int temp = arr[i];
    arr[i] =arr[j];
    arr[j] = temp;
}

void sort_colours(int arr[], int n) // this will make same colours adjacent to each other (DNF Sort, does in a single pass)
{
    int low = 0;
    int mid = 0;
    int high = n-1;
    int counter = 0;
    while(mid<high)
    {
        counter++;
        if (arr[mid]==0)
        {
            swap(arr,mid,low);
            low++;
            mid++;
        }

        if (arr[mid]==1)
        {
            mid++;
        }

        if (arr[mid]==2)
        {
            swap(arr,mid,high);
            high--;
        }
        
        
        
    }
    
    // std::cout<<counter<<"\n";
}
int main()
{
    int inital[]{2,0,2,1,1,0};
    int n = sizeof(inital)/sizeof(int);

    sort_colours(inital,n); //passing array and size of the array

    for (size_t i = 0; i < n; i++)
    {
        std::cout<<inital[i]<<" ";
    }
    
    return 0;
}