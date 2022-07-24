#include <iostream>
int main()
{
    unsigned int x =  1;
    unsigned int v;
    for (v = 0; x; v++) //& Brian Kernighan’s Algorithm
    {
        x = x & (x - 1); //^ this will be unset the right most bit of the given number and we will count how many steps it took

    }
    
    std::cout<<v<<"\n";
    return 0;
}