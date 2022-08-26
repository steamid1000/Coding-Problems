//^ Given a list of points and a number k, find the k closest points to the origin.


#include <iostream>

bool pairExists(int foundArray[], int key, int size) //* O(k)
{
    for (size_t i = 0; i < size; i++)
    {
        if (foundArray[i] == key)
        {
            return true;
        }
    }

    return false;
}

void closestPointsFromCenter(int arr[][2],int size,int k)
{
    int foundPointIndicies[k]{-1};
    int index = 0;

    int maxXPoint = arr[0][0];
    int maxYPoint = arr[0][1];
    int maxIndex = -1;

    //^ we have to find the max element from the pairs
    for (size_t i = 1; i < size; i++) //* 0(n)
    {
        if (arr[i][0] >= maxXPoint and arr[i][1] > maxYPoint)
        {
            maxXPoint = arr[i][0];
            maxYPoint = arr[i][1];
            maxIndex = i;
        }
        
    }


    for (int i = 0; i < size; i++) //* 0(nxn)
    {
        int currentXPoint = maxXPoint;
        int currentYPoint = maxYPoint;
        int shortestIndex = maxIndex;

        for (int j = 0; j < size; j++)
        {
            //^ Checking if the current point is less then the last point and also checking if it already exists in the foundPoints list
            if ((arr[j][0] <= currentXPoint and arr[j][1] < currentYPoint) and !pairExists(foundPointIndicies,j,index))
            {
                currentXPoint = arr[j][0];
                currentYPoint = arr[j][1];
                shortestIndex = j;
            }
             
        }

        foundPointIndicies[index] = shortestIndex;
        index++;
        
    }

    //* 0(k)
    for (int i = 0; i < k; i++) //^ printing the k closest points from the center 
    {
        std::cout<<arr[foundPointIndicies[i]][0]<<" "<<arr[foundPointIndicies[i]][1]<<"\n";
    }
    
    
    
}

int main()
{
    int points[][2]{
        {1, 1},
        {3, 3},
        {4, 4},
        {2, 2},
        {-1, -1},
        {4,5}};

    int k = 2;

    closestPointsFromCenter(points, 6, k);

    return 0;
}