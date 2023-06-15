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


template<class T>
T copy2(T *arr,T *end,T *to)
{
    for(;arr!=end;)
    {
        *to=*arr;
        arr++,to++;
    }
    return 0;
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


    int arr3[]={1,2,3,4,5};
    int arr4[]={3,3,3,3,3};
    copy2(arr3,arr3+4,arr4);
    for(int j=0;j<5;j++)
{
    std::cout<<arr4[j]<<' ';
}

    return 0;

}