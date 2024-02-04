#include<iostream>
using namespace std;
#include<queue>
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
void levelOrderTraversal(Node * root){
    if(root==NULL)
    return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        Node * node=q.front();
        q.pop();
        cout<<node->data<<" ";
        if(node->left!=NULL)
        q.push(node->left);
        if(node->right!=NULL)
        q.push(node->right);
    }
    
}
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
int main()
{
    Node* root=NULL;
    root=createTree();
    levelOrderTraversal(root);
    return 0;
}
