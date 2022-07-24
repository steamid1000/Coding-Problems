#include <iostream>

class node{

public:
        int val;
        node *next;

        node(int dat = -1) // creating the first node
        {
            val = dat;
            next = NULL;
        }

        
    };

    void insert(node *&head, int val) // simple insert function for the linked list
        {
            node *n = new node(val);
            if (head == NULL)
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

        void display(node *head) // displays the linked list
        {
            while (head != NULL)
            {
                std::cout << head->val << "->";
                head = head->next;
            }

            std::cout << "NULL\n";
        }
int main()
{
    node* head = NULL;

    insert(head,10);
    insert(head,20);
    insert(head,30);

    display(head);
    return 0;
}