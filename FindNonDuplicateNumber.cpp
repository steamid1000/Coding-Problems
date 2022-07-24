/* Hi, here's your problem today. This problem was recently asked by Facebook:

Given a list of numbers, where every number shows up twice except for one number, find that one number.

Example:
Input: [4, 3, 2, 4, 1, 3, 2]
Output: 1
*/


#include "bits/stdc++.h"
int main()
{
    std::vector<int> repating = {4, 3, 2, 4, 1, 3, 2};

    std::sort(repating.begin(),repating.end());

    for (int i = 0; i < repating.size()-1; i++) // linear time complexlity with constant space complexity
    {
        if (repating[i]!=repating[i+1])
        {
            std::cout<<repating[i]<<'\n';
            break;
        }
        
    }
    
    return 0;
}