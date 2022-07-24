/* Hi, here's your problem today. This problem was recently asked by Apple:

Given an integer k and a binary search tree, find the floor (less than or equal to) of k, and the ceiling (larger than or equal to) of k. If either does not exist, then print them as None.

Here is the definition of a node for the tree.
class Node:
  def __init__(self, value):
    self.left = None
    self.right = None
    self.value = value

def findCeilingFloor(root_node, k, floor=None, ceil=None):
  # Fill this in.

root = Node(8)
root.left = Node(4)
root.right = Node(12)

root.left.left = Node(2)
root.left.right = Node(6)

root.right.left = Node(10)
root.right.right = Node(14)

print findCeilingFloor(root, 5)
# (4, 6)
*/

#include <iostream>
#include <vector>
#include "util.h"

class node
{
public:
    node *left;
    node *right;
    int val;

    node(int dat)
    {
        val = dat;
        left = NULL;
        right = NULL;
    }
};

std::vector<int> findFloorCeil_Brute(node *root, int k)
{
    std::vector<int> log;
    // finding the floor
    node *temp = root;
    while (temp != NULL)
    {
        if (temp->val == k or temp->val == k - 1)
        {
            log.push_back(temp->val);
            break;
        }

        if (k < temp->val)
        {
            temp = temp->left;
            
        }
        else if (k > temp->val)
        {
            temp = temp->right;
        }
    }

     // finding the ceil
    temp = root;
    while (temp != NULL)
    {

        if (temp->val == k or temp->val == k + 1)
        {
            log.push_back(temp->val);
            break;
        }

        if (k < temp->val)
        {
            temp = temp->left;
            
        }
        else if (k > temp->val)
        {
            temp = temp->right;
        }
    }


    return log;
}


int main()
{
    node *root = new node(8);
    root->left = new node(4);
    root->right = new node(12);

    root->left->left = new node(2);
    root->left->right = new node(6);

    root->right->left = new node(10);
    root->right->right = new node(14);

    std::vector<int> ans =findFloorCeil_Brute(root,5); 
    
    util::display_vector(ans);
    
    return 0;
}



//^ Above function FloorCeil is a bruteforce approch and should be optimized as we are already given a ordered tree (balanced tree), so
//! Do that