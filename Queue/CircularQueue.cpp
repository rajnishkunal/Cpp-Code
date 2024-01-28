#include<iostream>
using namespace std;
class CircluarQueue{
    public:
    int *arr;
    int size;
    int rear;
    int front;
    CircluarQueue(int n){
        front=rear=-1;
        arr=new int(n);
        size=n;
    }
    //inserting of element
    void enqueue(int element){
        //when queue is full
        if((front==0 && rear==size-1)||(front==(rear+1)%size))
        {
            cout<<"Queue is full"<<endl;
            return;
        }
        //when queue is empty where rear is at last
        else if(rear==size-1 && front!=0)
        {
            rear=0;
            arr[rear]=element;
        }
        //first element
        else if(front==-1){
            rear=front=0;
            arr[rear]=element;
        }
        //normal case
        else{
            rear++;
            arr[rear]=element;
        }
    }
    void dequeue(){
        if(front==-1)
        {
            cout<<"Queue is empty"<<endl;
        }
        else if(front==size-1){
            front=0;
        }
        else if(front==rear){
            front=rear=-1;
        }
        else{
            front++;
        }
    }
    int isfront(){
        return arr[front];
    }
    int isrear(){
        return arr[rear];
    }
};
int main(){
    CircluarQueue *q1=new CircluarQueue(5);
    q1->enqueue(4);
    q1->enqueue(8);
    q1->enqueue(12);
    q1->enqueue(16);
    q1->enqueue(20);
    cout<<q1->isfront()<<" "<<q1->isrear()<<endl;
    q1->dequeue();
    cout<<q1->isfront()<<" "<<q1->isrear()<<endl;
}