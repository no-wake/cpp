#include<iostream>
#include<algorithm>
#include<list>
using namespace std;

template<class T>
void permutations(T list[],int k,int m ){
    int i=0;
    sort(list,list+m+1);
    do {
        for(i=0;i<=m;i++)
            cout<<list[i]<<" ";
        cout<<endl;
    }while(next_permutation(list,list+m+1));
}

int main(){
    int list[]={4,3,5,7};

    permutations(list,0,3);
}