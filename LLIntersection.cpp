/* 
Hi, here's your problem today. This problem was recently asked by Apple:

You are given two singly linked lists. The lists intersect at some node. Find, and return the node. Note: the lists are non-cyclical.

Example:

A = 1 -> 2 -> 3 -> 4
B = 6 -> 3 -> 4 

This should return 3 (you may assume that any nodes with the same value are the same node).
*/

#include "bits/stdc++.h"

class node
{
public:
    int val;
    node *next;

    node(int data)
    {
        val = data;
        next = NULL;
    }
};

void insertAtTail(node *&head, int data)
{
    node *n = new node(data);

    if (head == NULL) //creating new head if it does not exist already
    {
        head = n;
        return;
    }

    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = n;
}

void display(node *head)
{
    while (head != NULL)
    {
        std::cout << head->val << "->";
        head = head->next;
    }
    std::cout << "NULL\n";
}

int intersection(node *h1, node *h2) //funtion will take two heads of two linked list
{
    int intersect_point = 0; //0 will be the returned if the intersection is not found
    std::vector<int> elements_of_list_1;

    while (h1 != NULL) //pushing the data at each node into the vector
    {
        elements_of_list_1.push_back(h1->val);
        h1 = h1->next;
    }

    while (h2 != NULL)
    {
        int temp_data = h2->val;
        for (int i = 0; i < elements_of_list_1.size(); i++)
        {
            if (temp_data == elements_of_list_1[i])
            {
                intersect_point = elements_of_list_1[i];
                return intersect_point;
                // std::cout<<elements_of_list_1[i]<<" ";
            }
        }

        h2 = h2->next;
    }

    return intersect_point; //base case is 0 if the intersection is not found
}
int main()
{

    node *A = NULL;

    insertAtTail(A, 1);
    insertAtTail(A, 2);
    insertAtTail(A, 3);
    insertAtTail(A, 4);

    display(A);

    //another list

    node *B = NULL;

    insertAtTail(B, 6);
    insertAtTail(B, 3);
    insertAtTail(B, 4);

    display(B);


    std::cout<<intersection(A,B)<<"\n";


    // node* c = NULL;

    // insertAtTail(c,6);
    // c->next = A->next->next;

    // std::cout<<intersection(A,c)<<'\n';
    return 0;
}