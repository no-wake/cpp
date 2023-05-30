#include<iostream>
#include<cstdlib>
using namespace std;

template<class T>
bool is_sorted(T *arr,int n)
{
    int i;
    if(arr[0]<arr[1])
    {
        for(i=1;i<n;i++)
        {
            if(arr[i]>=arr[i+1])
                return false;
            else continue;
        }
    }else
        if(arr[0]>arr[1])
    {
        for(i=1;i<n;i++)
        {
            if(arr[i]<=arr[i+1])
                return false;
            else continue;
        }
    }else
        if(arr[0]==arr[1])
            {return false;}

    return true;
}

int main()
{
    int arr1[]={9,8,7,6,5};
    
    if(is_sorted(arr1,5))cout<<"true"<<endl;
    else cout<<"false"<<endl;

    char arr2[]={'c','d','A'};
    if(is_sorted(arr2,3))cout<<"true"<<endl;
    else cout<<"false"<<endl;

    return 0;

}