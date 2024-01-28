#include<iostream>
using namespace std;
#include <queue>
#include <stack>
int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    int queueSize=q.size();
    stack<int> st;
    for(int i=0;i<queueSize;i++){
        st.push(q.front());
        q.pop();
    }
    for(int i=0;i<queueSize;i++)
    {
        q.push(st.top());
        st.pop();
    }
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
 return 0;
}


