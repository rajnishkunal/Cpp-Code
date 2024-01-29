#include<iostream>
using namespace std;
class deque
{
public:
int *arr;
int size;
int front;
int rear;
deque(int n){
    front=rear=-1;
    arr=new int[n];
    size=n;
}
void push_front(int element){
    if((front==0 && rear == size-1) ||(front == rear+1) )
    {
        cout<<"Queue is full front"<<endl;
        return;
    }
    //empty
    else if(front==-1 && rear==-1)
    {
        rear=front=0;
        arr[front]=element;
    }
    else if(front==0)
    {
        front=size-1;
        arr[front]=element;
    }
    else
    {
        front--;
        arr[front]=element;
    }
}
void push_back(int element){
     if((front==0 && rear == size-1) ||(front == rear+1) )
    {
        cout<<"Queue is full back"<<endl;
        return;
    }
    else if(front==-1 && rear==-1){
        front=rear=0;
        arr[rear]=element;
    }
    else if(rear==size-1)
    {
        rear=0;
        arr[rear]=element;
    }
    else{
        rear++;
        arr[rear]=element;
    }
}
void pop_front(){
    if(front==-1){
        cout<<"Queue is empty"<<endl;
        return;
    }
    else if(front==rear)
    {
        front=rear=-1;
    }
    else if(front==size-1)
    {
        front=0;
    }
    else{
        front++;
    }
}
void pop_back(){
    if(front==-1)
    {
        cout<<"Queue is empty "<<endl;
        return;
    }
    else if(front==rear)
    {
        front=rear=-1;
    }
    else if(rear==0)
    {
        rear=size-1;
    }
    else{
        rear--;
    }
}
int getFront(){
    if(front==-1)
    {
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    else{
        return arr[front];
    }
}
int getRear(){
    if(front==-1)
    {
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    else{
        return arr[rear];
    }
}
void display() {
    if (front == -1) {
        cout << "Deque is empty" << endl;
        return;
    }

    cout << "Elements in the deque are: ";
    int i = front;
    while (true) {
        cout << arr[i] << " ";
        if (i == rear) break;
        i = (i + 1) % size;
    }
    cout << endl;
}

};
int main()
{
    deque *q=new deque(5);
    q->push_back(5);
    q->push_back(8);
    cout<<q->getRear()<<endl;
    q->push_front(6);
    q->push_front(9);
    cout<<q->getFront()<<endl;
    q->push_front(11);
    q->display();


 return 0;
}
