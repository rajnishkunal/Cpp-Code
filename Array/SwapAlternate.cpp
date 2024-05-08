#include<iostream>
using namespace std;
int main()
{   int size=10;
    int arr[size]={1,2,3,4,5,6,7,8,9,10};
        for(int i=0;i<size;i=i+2){
            int j=i+1;
            if(arr[i]<size){
                swap(arr[i],arr[j]);
            }
        }
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
 return 0;
}
