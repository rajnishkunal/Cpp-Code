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
void inOrderTraversal(Node* n){\
    //base case
    if(n==NULL)
    return;
    //L
    inOrderTraversal(n->left);
    //N
    cout<<n->data<<" ";
    //R
    inOrderTraversal(n->right);
    return;
}
int main()
{
    Node* root=NULL;
    root=createTree();
    inOrderTraversal(root);
    return 0;
}
