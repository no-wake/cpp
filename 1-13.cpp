#include<iostream>
using namespace std;

template<class T>
T *changeLength(T *arr,int oldLength,int newLength){
    T *newArr= new T [newLength];
    if(oldLength>newLength)
    {
        for(int i=0;i<newLength;i++)
        {
            newArr[i]=arr[i];
        }
    }else
        if(oldLength<=newLength)
        {
            for(int i=0;i<oldLength;i++)
            {
                newArr[i]=arr[i];
            }
        }   
    delete [] arr;
    return newArr;
}


int main()
{
    int arr[]={9,8,5,2,1};
    for(int i=0;i<7;i++)
        cout<<(changeLength(arr,5,7))[i]<<endl;

    char arr2[]={'a','c','d','w','e','r'};
    for(int i=0;i<4;i++)
        cout<<(changeLength(arr2,6,4))[i]<<endl;
    return 0;
}