//^ Traverse an binary tree with inorder-traversal using both iterative and recursive methods

#include <iostream>
#include <stack>

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void inorderTraversal(node *root) //^ recursive method
{
    if (root == NULL)
    {
        return;
    }

    inorderTraversal(root->left);

    std::cout << root->data << ' ';

    inorderTraversal(root->right);
}

void inorderTraversalIterative(node *root)
{
    std::stack<node *> storage;
    node *current = root;
    while (!storage.empty() || current != NULL)
    {
        while (current != NULL)
        {
            storage.push(current);
            current = current->left;
        }

        current = storage.top();
        storage.pop();

        std::cout << current->data << " ";

        current = current->right;
    }
}

int main()
{
    node *tree1 = new node(1);
    tree1->left = new node(7);
    tree1->right = new node(2);
    tree1->left->left = new node(10);
    tree1->right->left = new node(3);
    tree1->right->right = new node(5);

    inorderTraversal(tree1);
    /* Not a accurate biinary tree by the way
             1
           /   \
          7     2
         /    /  \
        10   3   5
    */

    //inorderTraversal(tree1);
    std::cout << '\n';
    inorderTraversalIterative(tree1);
}
