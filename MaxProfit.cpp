/* Hi, here's your problem today. This problem was recently asked by Apple:

You are given an array. Each element represents the price of a stock on that particular day. Calculate and return the maximum profit you can make from buying and selling that stock only once.

For example: [9, 11, 8, 5, 7, 10]

Here, the optimal trade is to buy when the price is 5, and sell when it is 10, so the return value should be 5 (profit = 10 - 5 = 5).
*/

#include <iostream>

int maxprofit(int arr[], int n)
{
    int min=arr[0],max=arr[0]; //will store the min and max
    int index; //will save the index of the min price, we just have to search ahead of that
    //finding min price
    for (size_t i = 1; i < n; i++)
    {
        if (arr[i]<min)
        {
            min = arr[i];
            index = i;
        }
        
    }


    //finding the max price
    for (size_t i = index; i < n; i++)
    {
        if (arr[i]>max)
        {
            max = arr[i];
        }
        
    }
    
    return max-min;

}
int main()
{
    int n = 6;
    int prices[n]{9, 11, 8, 5, 7, 10};

    int max_profit = maxprofit(prices,n);

    std::cout<<max_profit<<"\n";
    return 0;
}