#include <iostream>

//basic node structure template
class node{
    public:
    int val;
    node* prev;
    node* next;

    node(int data)
    {
        val = data;
        prev = NULL;
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
        head->prev = NULL;
        return;
    }

    node* tm = head;
    while (tm->next!=NULL)
    {
        tm = tm->next;
    }

    tm->next = n;
    n->prev = tm;
    
}


void print(node* head)
{
    while (head->next!=NULL)
    {
        std::cout<<head->val<<"->";
        head = head->next;
    }
    std::cout<<head->val<<"->";
    std::cout<<"NULL\n";

    std::cout<<head->prev->val<<"\n";
}


int main()
{
    node* head = NULL;

    inser(head,10);
    inser(head,20);
    inser(head,30);
    inser(head,40);

    // std::cout<<head->next->prev->val<<"\n";
    print(head);

    return 0;
}