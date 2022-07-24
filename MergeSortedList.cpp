/* Hi, here's your problem today. This problem was recently asked by Twitter:

You are given an array of k sorted singly linked lists. Merge the linked lists into a single sorted linked list and return it.
*/



#include <iostream>
#include <vector>
#include <algorithm>


//linked list class
class node{
    public:
    int val;
    node* next;

    node(int dat)
    {
        val = dat;
        next = NULL;
    }
};

//list functions

void insert(node* &head, int val)
{
    node* n = new node(val); //making a new node to inser at the end of the linked list

    if (head==NULL)
    {
        head = n;
        return;
    }
    
    node* temp = head;
    while (temp->next!=NULL)
    {
        temp = temp->next;
    }
    
    temp->next = n;

}

//to display the lined list
void display(node* head)
{
    while (head!=NULL)
    {
        std::cout<<head->val<<"->";
        head = head->next;
    }
    std::cout<<"NULL\n";
}


//!Warning the below is just a brute-force approach

//this function will extract each element of the linked list which will be stored in a vector in the merge function

void pop_element(node* doka,std::vector<int> &container) // sending the vector with reference
{
    while(doka!=NULL)
    {
        container.push_back(doka->val);
        doka = doka->next;
    }
}

//merging function here

void merge(node* arr[], int k,node* &final_hea)
{
    // node* final_head = NULL; // this will be the final linked list which will be a merger of the k linked lists
    std::vector<int> all_elements;

    for (size_t i = 0; i < k; i++)
    {
        
        pop_element(arr[i],all_elements);
    }
    
    //sorting the finall container which holds all the elements
    std::sort(all_elements.begin(),all_elements.end());

    for (size_t i = 0; i < all_elements.size(); i++)
    {
        // std::cout<<all_elements[i]<<"\n";
        insert(final_hea,all_elements[i]);
    }

    
}


int main()
{
    node* head = NULL;
    insert(head,1);
    insert(head,2);
    insert(head,5);

    node* head2 = NULL;
    insert(head2,2);
    insert(head2,4);
    insert(head2,6);


    //array for holding the heads of the linked list and then send the array to the function
    int k = 2;
    node* arr[k]{head,head2};

    node* head34 = NULL;
    merge(arr,k,head34);

    
    display(head);
    display(head2);


    //finally printing the merged linked list
    display(head34);
    return 0;
}