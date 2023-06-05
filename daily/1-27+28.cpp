#include<iostream>
using namespace std;


template<class T1>
T1 accumulate(T1 *arr,int end,T1 initialValue)
{
    for(int i=0;i<=end;i++)
        initialValue+=arr[i];
    return initialValue;
}



template<class T2>
T2 accumulate(T2 *arr, int start,int end,T2 initialValue)
{
    for(int i=start;i<=end;i++)
        initialValue+=arr[i];
    return initialValue;
}

int main(){
    int arr1[]={1,2,3,4,5,6};
    std::cout<<accumulate(arr1,3,0)<<endl;
    std::cout<<accumulate(arr1,0,3,0)<<endl;

    char arr2[]={"!#$%^&"};
    std::cout<<accumulate(arr2,1,'1')<<endl;
    std::cout<<accumulate(arr2,0,1,'1')<<endl;

}