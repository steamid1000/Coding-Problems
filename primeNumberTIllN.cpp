#include <iostream>

void primeNumbersTillN(int n)
{
    int i=1,j;
    std::cout<<i<<" ";
    for (i = 1; i <= n; i+=2) //? Skipping the even number as it will always be factor of 2
    {
        for ( j = 2; j <=i; j++)
        {
            if (j==i)
            {
                std::cout<<i<<" ";
                
            }

            else if (i%j==0)
            {
                // std::cout<<"value of j is: "<<j<<"\n\n";
                break;
            }
            
        }


    }
}

int main()
{
    primeNumbersTillN(40) ;
    return 0;
}