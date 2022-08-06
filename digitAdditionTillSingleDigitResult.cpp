//^Given a number like 159, add the digits repeatedly until you get a single number.
/*For instance, 1 + 5 + 9 = 15.
1 + 5 = 6.
So the answer is 6.
*/

#include <iostream>

int numberBreakDown(int num,int res)
{
    res += num%10; 

    //^ For Debugging purpose only 
    //std::cout<<"result: "<<res<<"\n";

    //& if the result is less then 9 which will be single digit we will return it
    //& And also we can add extra condition that the result must be greater then 0 too 
    //& But i dont think its that important or is it🤔🤔
    if (num<=0 and res < 10) 
    {
        return res;
    }

    //& Even after finishing the digits of the num the result is still greater then 9 then
    //& we will update the result to be the new number and start over again.
    if (num<=0 and res>=10) 
    {
        num = res;
        res = num%10;
    }
    
    return numberBreakDown(num/10,res); //^ reducing the number by one digit

}
int main()
{
    int number = 10081;
    int result = 0; //^ Can we avoid using this ? The value of result was resetting so i used it.
    std::cout<<numberBreakDown(number,result)<<"\n";

    std::cout<<result;
    return 0;
}
