#include <iostream>
#define inp std::cin >>
#define out std::cout <<
#define str std::string
#define test_case_int while (t--)

void Occurence(int A[], int target, int n);
int main()
{
    int n = 10;
    int A[10] = {0, 0, 0, 0, 0, 0, 1, 0, 0, 0}; //given sorted array
    int target = 0;                             //given target

    // out first_index << " " << last_index << "\n";
    Occurence(A, target, n);

    return 0;
}

void Occurence(int A[], int target, int n)
{
    int first_index = -1, last_index = -1; //will store the index of the first and last occurence of target
    for (int i = 0; i < n; i++)            // O(n) time complexity
    {
        if (first_index == -1 and A[i] == target)
        {
            first_index = i;
        }
        else if (A[i] == target)
        {
            last_index = i;
        }
    }

    out first_index << " " << last_index;
}