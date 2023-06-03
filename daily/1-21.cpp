#include<iostream>
using namespace std;

int f_n(int x)
{
    if(x%2==0) return x/2;
    else return (3*x+1)/2;
}

int f2_n(int x)
{
    if(x%2==0) return x/2;
    else
        return f_n(3*x+1);
}

int main(){
    int x=10;
    cout<<f_n(x)<<endl;
    cout<<f2_n(x)<<endl;
}