#include <iostream>

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void inserAtTail(node *&head, int val)
{
    node *naya = new node(val);
    if (head == NULL)
    {
        head = naya;
        return;
    } // if the linked list is not initialized

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = naya;
}

void show(node *head)
{
    while (head != NULL)
    {
        std::cout << head->data << " ";
        head = head->next;
    }
}

void reversell(node* &head)
{
    node *prev =NULL;
    node* temp=NULL;
    node* &current = head;

    while (current!=NULL)
    {
        temp = current->next; // stores the address of the next node
        current->next = prev; // currents-> will be null
        prev = current; // prev = current node 
        current = temp; //current will be the next node

    }
    
    head = prev;
}
int main()
{

    node *head = NULL;
    inserAtTail(head, 20);
    inserAtTail(head, 2);
    inserAtTail(head, 200);

    std::cout<<head->next->next->data<<"\n";
    show(head);

    node *reversed_list = NULL;    
    reversell(head);

    std::cout<<"\n";
    show(head);
    return 0;
}