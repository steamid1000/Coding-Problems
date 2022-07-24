#include <stdio.h>
#include <stdbool.h>

bool is_palindrome(int num)
{
    int rev = 0;
    int temp =num;//^ 😁😜 forgot that the original copy will be 0 at the end of the while loop, so a copy is required
    while (num>0)
    {
        rev = (rev * 10) + num%10;
        num = num/10;
    }

    if (temp == rev)
    {
        return true;
    }
    
        return false;
    
    
}
int main()
{
    int n = 123321;
    int x = 123;
    printf("%d\n",is_palindrome(n));
    printf("%d\n",is_palindrome(x));
    return 0;
}