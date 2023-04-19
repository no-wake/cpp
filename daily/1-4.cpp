#include<iostream>
using namespace std;

template <class T>
void inner_product(T *arr,const T value)
{
    int i;
    for(i=0;i<sizeof(arr);i++)
    {
        arr[i]=value+i;
    }
}


int main(){
    int arr[]={0,43,23,56,3,6,7};
    inner_product(arr,7);

    for(int i=0;i<7;i++)
        cout<<arr[i]<<endl;
    getchar();
    return 0;


}
