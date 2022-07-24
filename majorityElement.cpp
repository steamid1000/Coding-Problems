/*//^A majority element is an element that appears more than half the time. Given a list with a majority element, find the majority element.

Here's an example and some starting code.
def majority_element(nums):
  # Fill this in.

print(majority_element([3, 5, 3, 3, 2, 4, 3]))
# 3

*/
#include <iostream>
#include <unordered_map>

int majorityElement(int arr[],int size)
{
    std::unordered_map<int,int> uniqueElements;
    int majorityElement; //^ this will store the majority element

    for (int i = 0; i < size; i++) //^ finding occurence of each elements
    {
      if (uniqueElements.find(arr[i]) == uniqueElements.end())
      {
          uniqueElements.insert(std::make_pair(arr[i],1));
      }
      else
      {
          uniqueElements[arr[i]]++;
      }
      
      
    }

    for (auto it:uniqueElements) //^ finding the majority element in the map
    {
       if (it.second > size/2)
       {
          majorityElement = it.first;
       }
       
    }
    

    
    return majorityElement;

}

int main()
{
    int elements[]{3, 5, 3, 3, 2, 4, 3}; 

    std::cout<<majorityElement(elements,sizeof(elements)/sizeof(int));
    return 0;
}