#include<iostream>
using namespace std;
#include<stack>
class Queue{
    public:
    stack<int> s1,s2;
    void enqueue(int element){
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(element);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    void dequeue(){
      if(s1.empty())
      {
        cout<<"Queue Is Empty"<<endl;
      }
      else{
        s1.pop();
      }  
    }
    int getFront(){
        if (s1.empty())
        {
            cout<<"Queue Is Empty"<<endl;
            return -1;
        }
        else{
            return s1.top();
        }   
    }
        int getRear()
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        int front = s2.top();
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return front;
    }
};
int main()
{
    Queue *q1=new Queue();
    q1->enqueue(5);
    q1->enqueue(6);
    q1->enqueue(7);
    cout<<q1->getRear()<<endl;
    cout<<q1->getFront()<<endl;
    q1->dequeue();
    q1->dequeue();
    cout<<q1->getFront()<<endl;

 return 0;
}
