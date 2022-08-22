/*
You are given an array. Each element represents the price of a stock on that particular day. Calculate and return the maximum profit you can make from buying and selling that stock only once.

For example: [9, 11, 8, 5, 7, 10]

Here, the optimal trade is to buy when the price is 5, and sell when it is 10, so the return value should be 5 (profit = 10 - 5 = 5).
*/

#include <iostream>


//& !!!! Error found with a new test case, need to change the appoarch

int maxprofit(int arr[], int n)
{
    int min=INT16_MAX,max=INT16_MIN,maxProfit = 0; //will store the min and max
    int index=0; //will save the index of the min price, we just have to search ahead of that
    //finding min price

    for (int i = 0; i < n; i++)
    {
        
        for (int j = index; j < n; j++)
        {
            if (i==j)
            {
                continue;
            }

            if (j>i and arr[j] - arr[i] > maxProfit)
            {
                maxProfit = arr[j] - arr[i];
                min = arr[i];
                max = arr[j];
                index = j;
            }
            
            

        }
        
    }
    

    std::cout<<min<<" "<<max<<"\n";
    return max-min;

}
int main()
{
    int n = 6;
    int prices[n]{12, 10, 13, 15, 9, 10};
    //int prices[n]{6, 11, 8, 8, 7, 10};

    //& !!!! Note it is assumed that we can buy the stock and sell it any day after the buying day
    
    int max_profit = maxprofit(prices,n);

    std::cout<<max_profit<<"\n";
    return 0;
}