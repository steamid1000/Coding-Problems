#include <iostream>

int minlensubarray(int ar[],int tar,int size)
{
    int minlen = INT32_MAX; 

    for (int i = 0; i < size; i++)
    {
        int sum = 0;
        int len = 0; //length and sum of the current sub-array
        for (int j = i; j < size; j++)
        {
            if (sum<tar) //if the current sum is less then the target then only add
            {
                sum+=ar[j];
                len++; //increasing the number steps with each addition of element
            }
            
            if (sum>=tar) //if the tar get is met or the sum is greater then the target
            {
                if (minlen>len) //if the len is less then the minlen then update it.
                {
                    minlen = len;
                }
                break; //break as there is no need to find further, target is met
            }

            if (i==0 and j==size-1  and sum<tar) //if at the first iteration and adding all the elements
            {                                    // and still the sum is less then target then it is
                return 0;                        // impossible to find that len as the sum of all the elements
                                                 // in the array is still shorter then the target
            }
                       
        }
        
    }
    

    return minlen; //return the minlen if valid target 
}

int main()
{
    int arr[]{2,3,1,2,4,3};
    int s = 7; //target
    int n = 6; //size of the array
    std::cout<<minlensubarray(arr,s,n);
    return 0;
}