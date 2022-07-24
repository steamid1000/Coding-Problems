/*Hi, here's your problem today. This problem was recently asked by Microsoft:

You are given two linked-lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Example:
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

#include <iostream>
class node
{
public:
    int val;    // value part of the node
    node *next; //pointer to the next node

    node(int value)
    {
        val = value;
        next = NULL;
    }
};

void insert_at_tail(node *&head, int vals)
{
    node *n = new node(vals);
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

void inser_at_head(node *&head, int value)
{
    node *n = new node(value);
    n->next = head;
    head = n;
}
void show(node *head)
{

    while (head != NULL) //passed by value and not reference
    {
        std::cout << head->val << "->";
        head = head->next;
    }
    std::cout << "NULL\n";
    // std::cout<<head->val<<"\n";
}

int linked_list_size(node *head){ //returns the number of nodes in a linked list
    int count = 0;
    while (head!=NULL)
    {
        count++;
        head= head->next;
    }
    return count;
}
//main logic
void list_addition(node *head1, node *head2, node *&ans)
{
    int remainder = 0,nodes; //will store the remainder of  the current node
    nodes = linked_list_size(head1);
    // bool both_are_null = false;
    while(nodes--)
    {
        int addition;
                
        addition = head1->val + head2->val + remainder;
        // std::cout<<"Both are not null\n";
        if (addition > 9 and (head1->next != NULL or head2->next!=NULL))
        {
            int Shesh_result;
            //{ conversion from string to int and vice versa
            /*std::string digits = std::to_string(addition);
            std::string first_digit = ""; first_digit += digits[0]; // what a hassel
            std::string last_digit= ""; last_digit+=digits[1];
            remainder = std::stoi(first_digit);
            int Shesh_result = std::stoi(last_digit);

            std::cout<<Shesh_result<<" "<<remainder<<"\n"; } */
            Shesh_result = addition % 10; // getting the last digit
            remainder = addition / 10;    //getting the first digit
            //the above logic is used becuse i think addition of 2 number of 1 digit each can only
            //result in 2 digits and not more .. hope its that way;

            std::cout<<head2->next<<"\n";
            head1 = head1->next;
            head2 = head2->next;
            insert_at_tail(ans, Shesh_result);
            nodes--;
            // goto here; // jump to the next iterations
            continue;
        }

        // node *digit = new node(addition);

        //next iteration, setting up
        head1 = head1->next;
        head2 = head2->next;
        insert_at_tail(ans, addition);
        // ans = ans->next;
        nodes--;
        // std::cout<<remainder<<"\n";
        
                
        
    }
}


int main()
{
    node *l1 = NULL;
    inser_at_head(l1, 2);  //342 is stored in the first linked list, each digit in a seprate node
    insert_at_tail(l1, 4); //in reverse order
    insert_at_tail(l1, 3);

    node *l2 = NULL; // another list
    inser_at_head(l2, 5);
    insert_at_tail(l2, 6); 
    // insert_at_tail(l2, 4);

    node *anwer_list = NULL;

    list_addition(l1, l2, anwer_list);
    show(l1);
    show(l2);
    show(anwer_list);

    std::cout<<linked_list_size(l1)<<" "<<linked_list_size(l2)<<" "<<linked_list_size(anwer_list)<<"\n";

    // std::cout<<anwer_list->next->val<<anwer_list->next->next->val<<"\n";
    // std::cout<<head->val<<"\n";
    return 0;
}


/*
Problems:
1) it does not work if 2 list have different number of digits (last digit is not shown)
2) if the last digit's addition is greater then 9 then the remainder is still taken out of it ,(answer is 0 for 10)  

    ****number 2 problem is fixed by just checking if the nodes are not null before removing the
     remainder
*/