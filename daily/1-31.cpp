#include<iostream>
#include<algorithm>
using namespace std;

template<class T>
void permutations(T list[],int k,int m){
    int i=0;
    T list_t1[m+1];
    T list_t2[m+1];
    for(i=0;i<=m;i++)
    {
        list_t1[i]=list[i];
        list_t2[i]=list[i];
    }
    cout<<"origin list:"<<endl;
    for(i=0;i<=m;i++)
        cout<<list[i]<<' ';
    cout<<endl;

    cout<<"greater list:"<<endl;
    while (next_permutation(list_t1,list_t1+m+1))
    {
        for(i=0;i<=m;i++)
            cout<<list_t1[i]<<' ';
        cout<<endl;
    }

    cout<<"smaller list:"<<endl;
    while (prev_permutation(list_t2,list_t2+m+1))
    {
        for(i=0;i<=m;i++)
            cout<<list_t2[i]<<' ';
        cout<<endl;
    }
}

int main(){
    int arr[]={5,4,6,3};
    permutations(arr,0,3);
}
