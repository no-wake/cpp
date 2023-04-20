#include<iostream>
using namespace std;

template<class T>
int mismatch(T *arr1,T *arr2,int n) //n为两数组中较大一个的长度
{
    int i=0;
    while(arr1[i]==arr2[i])
    {
        i++;
    }
    if(i>=n)return -1;
    else return i;

}

int main(){
    int arr1[]={1,4,3,2,5,6};
    int arr2[]={1,4,3,2,5,6,8};
    cout<<mismatch(arr1,arr2,7)<<endl;

    char arr3[]={'a','c','z','y'};
    char arr4[]={'a','c','z','y'};
    cout<<mismatch(arr3,arr4,4)<<endl;
    return 0;
}