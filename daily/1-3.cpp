#include<iostream>
using namespace std;


template<class T>
void fill(T *arr,int start,int end,T value)
{
    for(int i=start;i<end;i++)
    {
        arr[i]=value;
    }

}

int main(){

    char arr[]={};
    fill(arr,0,7,'w');
    for(int i=0;i<7;i++)
    {
        cout<<arr[i]<<endl;
    }
    getchar();
    return 0;

}