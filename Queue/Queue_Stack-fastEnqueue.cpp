#include <iostream>
using namespace std;
#include <stack>
class Queue
{
public:
    stack<int> s1, s2;
    void enqueue(int element)
    {
        s1.push(element);
    }
    void dequeue()
    {
        if (s1.empty())
        {
            return;
        }
        else
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            s2.pop();
            while (!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
        }
    }
    int getFront()
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
    q1->dequeue();
    q1->dequeue();
    cout<<q1->getFront()<<endl;
    return 0;
}
