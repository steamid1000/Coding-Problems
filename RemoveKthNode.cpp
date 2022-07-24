/* Hi, here's your problem today. This problem was recently asked by AirBNB:

You are given a singly linked list and an integer k. Return the linked list, removing the k-th last element from the list. 

Try to do it in a single pass and using constant space.
*/

#include "bits/stdc++.h"

//basic node structure template
class node{
    public:
    int val;
    node* next;

    node(int data)
    {
        val = data;
        next = NULL;
    }
};


//basic linked list functions
void inser(node* &head, int val)
{
    node* n = new node(val);

    if(head==NULL)
    {
        head=n;
        return;
    }

    node* tm = head;
    while (tm->next!=NULL)
    {
        tm = tm->next;
    }

    tm->next = n;
    
}


//special node creating function for this problem
void Specialinsert(node* &head, int val, int &count)
{
    node* n = new node(val);

    if(head==NULL)
    {
        head=n;
        count++; // increasing count after creation of the first node
        return;
    }

    node* tm = head;
    while (tm->next!=NULL)
    {
        tm = tm->next;
    }

    tm->next = n;
    count++; // increasing the counter after the creation of each node

    //the value of the counter is passed as reference
    
}

//display function
void print(node* head)
{
    while (head!=NULL)
    {
        std::cout<<head->val<<"->";
        head = head->next;
    }
    std::cout<<"NULL\n";
}


//declaration
void KthElement_bruteForce(node* &head,int k);
void KthElement_optimized(node* &head, int k, int count);
int main()
{
    node* head = NULL;
    int counter = 0; //this the counter which will be passed to the special node creating function

    Specialinsert(head,1,counter);
    Specialinsert(head,2,counter);
    Specialinsert(head,3,counter);
    Specialinsert(head,4,counter);
    Specialinsert(head,5,counter);

    print(head);



    //calling the brute force function
    KthElement_optimized(head,3,counter);

    // std::cout<<counter<<"\n";
    print(head);

    return 0;
}



void KthElement_bruteForce(node* &head,int k)
{
    std::vector<int> elements;

    node* tm = head;
    while (tm!=NULL)
    {
        elements.push_back(tm->val);
        tm = tm->next;
    }
    
    /*for ( auto it : elements)
    {
        std::cout<<it<<" ";
    }*/
    
    node* pre = head;
    tm = pre->next; // two pointer to be used for removing purpose
    while (tm!=NULL)
    {   
        
        if (tm->val == elements[elements.size()-k])
        {
            tm = tm->next; //at the last kth element the current pointer 'tm' will point to the next node and the previous pointer's 'pre'
            // next will point to the current pointer skipping the kth node entirely.
            pre->next = tm;
            continue;
        }

        pre = pre->next; //this will start from the head position.
        tm = tm->next; //this will start from the head position plus 1 node or secodn node
        
    }
    
}


void KthElement_optimized(node* &head, int k, int count) //time complexicity is O(n-k), where is the n = total number of node and k = the last kth node which has to be removed, it does it in (n-k)+1 passes or in single pass, we can say that.
{

    int index = 1; //this will help us at what position we are in the linked list
    
    node* tm;   
    node* pre = head;
    tm = pre->next; // two pointer to be used for removing purpose
    while (index!= (count-k)+1)
    {   
        
        if (index == (count - k))
        {
            tm = tm->next; //at the last kth element the current pointer 'tm' will point to the next node and the previous pointer's 'pre'
            // next will point to the current pointer skipping the kth node entirely.
            pre->next = tm;
            break;
        }

        pre = pre->next; //this will start from the head position.
        tm = tm->next; //this will start from the head position plus 1 node or secodn node
        index++; //increasing the index after each failed attemot
    }
    
}   
