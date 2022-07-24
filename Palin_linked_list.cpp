#include "util.h"
#include <iostream>

void palin_ll(util::linked_list *head) // the function is defined as void for now but can be changed to a bool type 
{
    /*So this function is very straight forward as it just goes through
      the linked list once and copy all the char into a single seprate string
      or char array And then checks for the palindrome for that string
      Time Complexicity : O (n1 + n2/2) n1 = number of nodes and n2 = number of char in the string */

    std::string chars = "";
    while (head != NULL)
    {
        chars += head->val;
        head = head->next;
    }

    // now checking the palindrome
    std::cout<<chars<<"\n"; // debug purpose
    int j = chars.length() - 1;
    for (int i = 0; i < chars.length() / 2; i++)
    {
        if (chars[i] != chars[j])
        {
            std::cout<<chars[i]<<" "<<chars[j]<<"\n";
            std::cout << "False\n";
            return;
        }
        j--;
    }

    std::cout << "True\n";
}

int main()
{
    util::linked_list *head = NULL; // head of the linked list
    util::linked_list list('!');    // the value given into the constructor is for dummy purpose only
    list.insert(head, 'a');
    list.insert(head, 'b');
    list.insert(head, 'b');
    list.insert(head, 'a');

    list.display(head);

    palin_ll(head);

    return 0;
}