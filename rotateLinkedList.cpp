//^ Given a linked list and a number k, rotate the linked list by k places.

#include <iostream>

class node // linkded list class
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = nullptr;
    }
};

void displayLinkedList(node *root) // just displays the list
{
    node *temp = root; //^ just for safety
    while (temp != nullptr)
    {
        std::cout << temp->data << ' ';
        temp = temp->next;
    }

    std::cout << '\n';
}

// Rotating function
void rotateLinkedList(node *&root, int k) // currently runs in 0(n+k), where n = number of nodes and k = number of nodes to rotate;
{
    node *temp = root; // temp is assigned as the first node
    node *newroot;

    int count = 0; // this will record how many nodes we have passed
    while (root != nullptr)
    {
        if (count < k and root->next == nullptr) // if the k is greater than the nodes avaliable then just return the original list
        {
            // assign the root to temp which holds the first node address
            std::cout << ""; // what is wrong with the compiler,  when this line is commented then it doesn't trigger the block😆
            root = temp;
            return;
        }

        else if (count < k)
        {
            count++;
            // root = root->next;
            // continue;
        }

        if (count == k)
        {                         // assigning the new root node after k nodes
            newroot = root->next; // when this is set to root instead of root->next then it works but is off by 1 node
            count++;              // this is to avoid running this section again
        }

        else if (root->next == nullptr) // when we reach the end of the linked list then we will point the node to the rotated list node (i.e the first node)
        {
            // std::cout<<"reached the end of the list\n";
            root->next = temp;
        }

        else if (root->next == newroot) // when the next node is the new root node , then we will break the conncetion and make it point to null and break the loop.
        {
            // std::cout<<"broke the connection\n";
            root->next = nullptr;
            break;
        }

        //& when i use else if then it works for some reason.🙄😐

        root = root->next;
    }

    root = newroot; // assign original root to the newroot we found after k nodes
}

int main()
{
    node *head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);

    // Calling beforing rotating
    displayLinkedList(head);

    rotateLinkedList(head, 3);

    // calling after rotating
    displayLinkedList(head);
    return 0;
}

/*
 How the algorithm works:

 1) We save the first node address in the temp node pointer
 2) Create and initialize a counter to 0
 3) Run a while loop until the root is not null
    3.1) if the counter is less then k then increment it
    3.2) when the counter is equal to k then assign the next node to a node* newroot (this will be the new root now)
    3.2.5) Continue the loop until root->next is not equal to null
    3.3) when the root->next == null then assign the temp(the original root) after the current node , root->next = temp
    3.4) when the root->next is equal to the newroot address then assign root->next == null to break the connection
    3.4.5) break the loop
 4) assign the root = newroot
*/