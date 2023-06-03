#include<iostream>
using namespace std;

template<class T>
int find(T *array,T ch,int size){
    
    if(array[size]==ch)
        cout<<size+1<<endl;
    else if(size==0)cout<<"no";    
    else find(array,ch,size-1);

    return 0;

}

int main(){
    char ch='w';
    char arr[]={"bapple"};
    find(arr,ch,5);


    int num=7;
    int arr2[]={1,2,3,4,5,6,7};
    find(arr2,num,7);
    
    return 0;
}