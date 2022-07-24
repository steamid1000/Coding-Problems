#include <iostream>

class node{
    public:
    int val;
    node* left; //left and right child
    node* right;

    node(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    } 
};
void start(node* &root,int val)
{
    node* n = new node(val);

        root = n;
        return;
}

void leftChild (node* &root, int val)
{
    node* temp = root;

    while (temp->left!=NULL)
    {
        temp = temp->left;
    }
    temp->left = new node(val);
}

void Right_childs(node* &root,int val)
{
    node* temp = root;

    while (temp->right!=NULL)
    {
        temp = temp->right;
    }
    temp->right = new node(val);
}

void display_Nodes(node* head)
{
    node* root2 = head;
    std::cout<<"Root node:\n";
    std::cout<<head->val<<"\n";
    std::cout<<"Left nodes\n";
    while (head->left != NULL)
    {
        std::cout<<head->left->val<<" ";
        head = head->left;
        // std::cout<<"yep\n";
    }

    std::cout<<"\nright nodes\n";

    while (root2->right!=NULL)
    {
        std::cout<<root2->right->val<<" ";
        root2 = root2->right;
    }
    
}

void inorder(node* root) //? Left Root Right
{
    if(root==NULL) return;

    inorder(root->left);
    std::cout<<root->val<<" ";

    inorder(root->right);
    

    
}
int main()
{
    node* root = NULL; 
    start(root,1);

   leftChild(root,10);
   leftChild(root,11);

    Right_childs(root,20);
    Right_childs(root,21);

    display_Nodes(root);

    std::cout<<"\n\n";
    inorder(root);
    return 0;
}