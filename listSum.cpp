/*Create a class that initializes with a list of numbers and has one method called sum. 
sum should take in two parameters, start_idx and end_idx and return the sum of the list
from start_idx (inclusive) to end_idx` (exclusive).*/

#include <iostream>

class listSum
{
    int* arr;
    int size;
    public:
    listSum(int list[],int size)
    {
        this->size = size;
        //arr = new int[size];
        arr = list;
    }

    int sum(int startIndex,int endIndex) //^ 0 (k) where k = endIndex - startIndex
    {
        //& What is there to optimize here?
        int sum = 0;
        for (int i = startIndex; i < endIndex; i++)
        {
            sum+=arr[i];
        }

        return sum;
        
    }
};

int main()
{
    int list[]{1, 2, 3, 4, 5, 6, 7};

    listSum object(list,7);

    std::cout<<object.sum(2,5)<<'\n';
    return 0;
}