/* 
Hi, here's your problem today. This problem was recently asked by Google:

There are n people lined up, and each have a height represented as an integer. A murder has happened right in front of them, and only people who are taller than everyone in front of them are able to see what has happened. How many witnesses are there?

Example:
Input: [3, 6, 3, 4, 1]  
Output: 3
Explanation: Only [6, 4, 1] were able to see in front of them.

*/


#include <iostream>

void How_Many_Witness(int arr[], int n, int &counter)
{
    for (size_t i = 0; i < n - 1; i++)
    {
        
        if (arr[i] <= arr[i + 1]) //if the behind person is smaller in hieght then, go to next iteration
        {
            continue;
        }

        short valid_hieght = 1; // after the loop if this true then counter will be increanented
        for (size_t j = i; j < n; j++)
        {
            if (arr[j] > arr[i]) // dont have to check for equal hieght as it already checked above
            {
                valid_hieght = 0;
                break;
            }
        }

        if (valid_hieght==1)
        {
            std::cout<<arr[i]<<" ";
            counter++;
        }
    }


}

int main()
{
    int n = 6;
    int arr[n]{3, 6, 3, 4, 1,0}; //hieght of the people standing behind each other
                               // NOTE: the muder scene is beyond the right end of the array or line

    int witness_counter = 1; //will store the number of witness who saw something
                            // 1 because, one person at the front will always see something 
    How_Many_Witness(arr, n, witness_counter);

    std::cout << witness_counter << "\n";
    return 0;
}