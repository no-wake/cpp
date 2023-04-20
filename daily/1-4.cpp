#include<iostream>
using namespace std;

template<class T>
T inner_product(T *arr1,T*arr2,int n)
{
    T sum;
    for(int i=0;i<n;i++)
    {
        sum+=arr1[i]*arr2[i];
    }
    return sum;
}

int main()
{
    char arr1[]={1,2,3,4,5,6};
    char arr2[]={9,8,7,6,5,4};
    cout<<inner_product(arr1,arr2,6)<<endl;
    getchar();
    return 0;

}