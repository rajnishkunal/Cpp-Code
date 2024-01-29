#include<iostream>
using namespace std;
#include<queue>
#include<stack>
void reverseFirstK(queue<int> &q, int k){
    stack<int> s;
    for(int i=0;i<k;i++)
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    for(int i=0;i<(q.size()-k);i++){
        q.push(q.front());
        q.pop();
    }
}
int main()
{
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);
    reverseFirstK(q,3);
    int length = q.size();
    for (int i = 0; i < length; i++) {
        cout << q.front() << " ";
        q.pop();
    }

 return 0;
}
