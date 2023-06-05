#include<iostream>
using namespace std;

template<class T>
T *copy(T *arr,int end,int to)
{
    T *arr2=new T [(end+to)];
    for(int i=0;i<=end;i++)
        arr2[i]=arr[i];
    
    for(int j=to;j<=(end+to);j++)
        arr2[j]=arr[j-to];

    return arr2;
}

int main(){
    int arr1[]={1,2,3,4,5};
    for(int i=0;i<=6;i++)
    {
        std::cout<<copy(arr1,4,2)[i]<<' ';
    }
    std::cout<<endl;

    char arr2[]={"abcdefg"};
    for(int i=0;i<=6;i++)
    {
        std::cout<<copy(arr2,6,3)[i]<<' ';
    }
    std::cout<<endl;

    return 0;

}