#include<iostream>
using namespace std;
#include<queue>
class Stack{
    public:
    queue <int> q1,q2;
    void push(int element){
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(element);
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }   
    }
    void pop(){
        if(q1.empty()){
            cout<<"Stack Underflow"<<endl;
        }
        else{
            q1.pop();
        }
    }
    int getTop(){
        if(q1.empty()){
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
        return q1.front();
    }
};
int main()
{
    Stack *st=new Stack();
    st->push(5);
    st->push(8);
    st->push(2);
    st->push(0);
    cout<<st->getTop()<<endl;
    st->pop();
    st->pop();
    st->pop();
    st->pop();
    st->pop();
    cout<<st->getTop()<<endl;
 return 0;
}
