#include <iostream>
using namespace std;
#include<queue>
#include<stack>
void interLeave(queue<int> &q){
    if(q.size()%2!=0){
        cout<<"Enter even number of integer"<<endl;
        return;  
    }
    int halfSize=q.size()/2;
    stack<int> s;
    //Pushing 1st half into stack
    for(int i=0;i<halfSize;i++){
        s.push(q.front());
        q.pop();
    }
    //Pushing 1st half back into queue
   while(!s.empty())
   {
       q.push(s.top());
       s.pop();
   }
   //Pushing 1st half into back of queue
   for(int i=0;i<halfSize;i++){
       q.push(q.front());
       q.pop();
   }
   //Pushing 1st half into stack
    for(int i=0;i<halfSize;i++){
        s.push(q.front());
        q.pop();
    }
    
    while(!s.empty()){
        q.push(s.top());
        s.pop();
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
    interLeave(q);
    int length = q.size();
    for (int i = 0; i < length; i++) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}