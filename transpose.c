/*//^Given a matrix, transpose it. Transposing a matrix means the rows are now the column and vice-versa.

Here's an example:
def transpose(mat):
  # Fill this in.

mat = [
    [1, 2, 3],
    [4, 5, 6],
]

print(transpose(mat))
# [[1, 4],
#  [2, 5],
#  [3, 6]]
/*/

#include "stdio.h"

void transpose(int rows, int columns, int arr[][columns])
{

    int newArray[columns][rows];

    //? making the row the columns
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            newArray[j][i] = arr[i][j];
        }
        
    }
    
    for (size_t i = 0; i < columns; i++)
    {
        for (int k = 0; k < rows; k++)
        {
            printf("%d " , newArray[i][k]);
        }

        printf("\n");
        
    }
    


}
void main()
{
    int rows = 2, cloumns = 3;

    int arr[2][3] = {
        {1, 2, 3},
        {4, 5, 6}};

    transpose(rows, cloumns, arr);
}