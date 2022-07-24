/* Hi, here's your problem today. This problem was recently asked by Twitter:

Implement a class for a stack that supports all the regular functions (push, pop) and an additional function of max() which returns the maximum element in the stack (return None if the stack is empty). Each method should run in constant time.
*/

#include <vector>
#include <iostream>

int top = -1; // max eli will store the max value of the stack and will be updated while pushing
int elems[10];
int maxs[10]; // will store the max elements present in the stack in asending order.
int maxeli = 0;   // will be used as a pointer to the present top element in the stack

void push(int val)
{

    top++;
    elems[top] = val; // will push the element in the stack
    if (top == 0)
    {
        maxs[maxeli] = elems[top]; // for the initail value of the max elems
        maxeli++;
        
    }

    if (elems[top] > maxs[maxeli-1])
    {
        maxs[maxeli] = elems[top]; //updating the max element
        maxeli++;
    }
    std::cout<<"Pushed\n";
}

void pop()
{
    if (top > -1)
    {
        if (elems[top] == maxs[maxeli-1])
        {
            maxeli--; // reducing the max elements as it is removed from the stack
            // maxeli--;
        }

        top--;
    }

    std::cout<<"popped\n";
}

void max()
{
    
    if (top == -1)
    {
        std::cout << "None\n";
    }

    std::cout << maxs[maxeli-1] << "\n";
    std::cout<<"Enter the max function\n";
}
void displayMax(){
for(size_t i = 0; i < 4; i++)
{
    std::cout<<maxs[i]<<" ";
}
std::cout<<"\n";
}
int main()
{
    // std::cout<<"WHY is it not working\n";

    // push(10);
    // push(20);
    // push(30);
    // push(2);
    // push(40);
    // max();
    // pop();
    // pop();
    // max();
    
    // displayMax();
    // return 0;

    // std::cout<<"WHY is it not working\n";

    push(2);
    push(10);
    push(20);
    push(30);
    push(40);
    max();
    pop();
    pop();
    // pop();
    pop();
    pop();
    max();
    
    displayMax();
    return 0;
}