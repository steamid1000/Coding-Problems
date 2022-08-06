//^Given an array of size n, and all values in the array are in the range 1 to n, find all the duplicates

//& Simple method used to solve this problem

#include <iostream>
#include <vector>
#include <algorithm>

void displayAllDuplicates(std::vector<int> numbers)
{
    sort(numbers.begin(),numbers.end());

    for (int i = 0; i < numbers.size()-1; i++)
    {
        if (numbers[i+1]==numbers[i])
        {
            std::cout<<numbers[i]<<" ";
        }
        
    }
    
}

int main()
{
    std::vector<int> numbers = {4,3,2,7,8,2,3,1};

    displayAllDuplicates(numbers);
    return 0;
}