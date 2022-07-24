/*Given a list of numbers, for each element find the next element that is larger than the current element. Return the answer as a list of indices. If there are no elements larger than the current element, then use -1 instead.

Here's an example and some starter code:
def larger_number(nums):
  # Fill this in.
  
 //^print [2, 2, 3, 4, -1, -1]
print(larger_number([3, 2, 5, 6, 9, 8]))
*/

#include <iostream>
#include <vector>
#include "util.h"

void find_larger_numbers(std::vector<int> numbers)
{
    std::vector<int> indices(numbers.size(),-1); //^ouput vector

    for (int i = 0; i < numbers.size(); i++)
    {   
        int j = i;

        while (j<numbers.size() )
        {
            if(numbers[j]>numbers[i]) {indices[i] = j; break;}

            j++;
        }
        
    }

    util::display_vector(indices);
    
}

int main()
{
    std::vector<int> numbers {3, 2, 5, 6, 9, 8};

    find_larger_numbers(numbers);
    return 0;
}