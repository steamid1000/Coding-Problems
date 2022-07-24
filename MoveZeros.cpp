/* Hi, here's your problem today. This problem was recently asked by Facebook:

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:
Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

#include <iostream>

int brute_force_apporch(int arr[],int n)  // O(n ^ number of zeros)
{
    short counter = 0;
    for (size_t i = 0; i < n; i++) 
    {
        if (arr[i]==0) // if the current element is 0 then send it to the end of the array after shifting all the elements to the left by 1 index
        {
            std::cout<<i<<"\n";
            counter++;
            int temp = arr[i]; //will hold the current element
            for (size_t j = i; j < n-1; j++)
            {
                arr[j]=arr[j+1];
                counter++;
                
            }
            for (size_t k = 0; k < n; k++)
            {
                std::cout<<arr[k]<<" ";
                
            }
            std::cout<<"\n";
            arr[n-1] = temp; //assingning the zero to the last index
            
        }
        
    }

    return counter;
    
}

int optimized_apporch(int arr[],int n) // O (n + m) where is m = number of zeros in the list
{
    short counter = 0;

    short index = 0;
    short zeros = 0; //will count the number of zeros in the list
    for (size_t i = 0; i < n; i++)
    {
        if (arr[i]==0) //both the condition happen in constant time so no load at all
        {
            zeros++;
        }
        else{
            arr[index] = arr[i];
            index++; // the value of the index will be +1 when it is used next
        }
        
    }

    // another very short loop to write the zeros into the array

    for (size_t i = index; i < n; i++)
    {
        arr[i] = 0;
        counter++;
    }
     
    
    return counter;
}
int main()
{
    int n = 10;
    int arr[n]{0, 0, 0, 2, 0, 1, 3, 4, 0, 0}; //intial order of the elements


    short count = brute_force_apporch(arr,n); //calling the brute force app

    // short moz = optimized_apporch(arr,n); //much better function


    /*for (size_t i = 0; i < n; i++)
    {
        std::cout<<arr[i]<<" ";
    }
    */
    // std::cout<<"\n"<<count<<"\n";
    return 0;
}