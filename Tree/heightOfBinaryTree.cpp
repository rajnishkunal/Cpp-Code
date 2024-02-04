#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int element){
        data=element;
        left=NULL;
        right=NULL;
    }
};
Node* createTree()
{
    cout<<"Enter the value of data"<<endl;
    int data;
    cin>>data;
    if(data==-1)
        return NULL;

    Node *newNode=new Node(data);
    cout<<"Enter left data for child (-1 for no child) "<<data<<endl;
    newNode ->left= createTree();
    cout<<"Enter right data for child (-1 for no child) "<<data<<endl;
    newNode ->right= createTree();

    return newNode;
}
int heightOfBinaryTree(Node * root){
    if(root==NULL)
    return 0;
    else{
        int leftDepth=heightOfBinaryTree(root->left);
        int rightDepth=heightOfBinaryTree(root->right);
        if(leftDepth>rightDepth)
        return leftDepth+1;
        else
        return rightDepth+1;
    }
}
int main()
{
    Node* root=NULL;
    root=createTree();
    cout<<"Height of Tree is : "<<heightOfBinaryTree(root);
    return 0;
}
