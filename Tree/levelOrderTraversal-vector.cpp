#include<iostream>
using namespace std;
#include<vector>
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
vector<vector<int>> levelOrderTraversal(Node * root){
    vector<vector<int>> ans;
    if(root==NULL)
    return ans;
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        int size=q.size();
        vector<int> level;
        for(int i=0;i<size;i++){
            //creating a node pointer that points the node which is in front of queue
            //this is doen so that left & right call can be done
            Node *node=q.front();
            q.pop();
            if(node->left!=NULL)
            q.push(node->left);
            if(node->right!=NULL)
            q.push(node->right);
            level.push_back(node->data);

        }
        ans.push_back(level);
    }
    return ans;
}
void printVectorOfVectors(vector<vector<int>>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        const vector<int>& innerVec = vec[i];
        for (size_t j = 0; j < innerVec.size(); ++j) {
            int num = innerVec[j];
            cout << num << " ";
        }
        cout << endl; // Print a new line after each inner vector
    }
}
int main()
{
    Node* root=NULL;
    root=createTree();
    vector<vector<int>> ans=levelOrderTraversal(root);
    printVectorOfVectors(ans);

 return 0;
}
