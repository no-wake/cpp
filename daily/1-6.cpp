#include<iostream>
#include<cstdlib>
using namespace std;

template<class T>
bool is_sorted(T *arr)
{
    int i=0;
    if(arr[0]<arr[1])
    {
        for(i=1;i<(sizeof(arr)/sizeof(arr[0]));i++)
        {
            if(arr[i]>=arr[i+1])
                return false;
            else continue;
        }
    }else
        if(arr[0]>arr[1])
    {
        for(i=1;i<sizeof(arr);i++)
        {
            if(arr[i]<=arr[i+1])
                return false;
        }
    }else
        if(arr[0]==arr[1])
            {return false;}
    
    return true;
}

int main()
{
    int arr[]={1,3,7,42,58,69};
    if(is_sorted(arr))cout<<"true"<<endl;
    else cout<<"false"<<endl;
    return 0;
}