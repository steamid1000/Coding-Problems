//^ Given an array of heights, determine whether the array forms a "mountain" pattern. 
//^ A mountain pattern goes up and then down.
/*
Like
  /\
 /  \
/    \
*/


//^ I think checking if the array elements are palindorme will do it
//& Note : I have considered that the peak could be flat and still be considered a valid mountain
/*^ Eg:

    the Top consist of 3 same numbers 3,3,3
    _ _ _
   /     \
  /       \

*/

#include <iostream>

bool isValidMountain(int arr[],int size)
{
    int j = size-1;

    //^ checking for palindome 

    for (int i = 0; i < size/2; i++)
    {
        if (arr[i]!=arr[j])
        {
            return false;
        }
        j--;
        
    }
    
    return true;
}

int main()
{
    int heights[]{1, 2, 3, 2, 1};
    int heights1[]{1, 2, 3,3, 2, 1};

    std::cout<<isValidMountain(heights,5)<<'\n';
    std::cout<<isValidMountain(heights,3)<<'\n';
    std::cout<<isValidMountain(heights1,6);
    return 0;
}