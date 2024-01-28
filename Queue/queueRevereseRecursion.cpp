#include<iostream>
using namespace std;
#include<queue>
void reverese(queue<int> &q){
    //base case
    if(q.empty())
    return;
    int element=q.front();
    q.pop();
    reverese(q);
    q.push(element);
}
int main()
{
    queue<int> q;
    q.push(4);
    q.push(8);
    q.push(12);
    q.push(16);
    q.push(20);
    reverese(q);
    // Printing Reverse Queue
    while (!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
 return 0;
}
