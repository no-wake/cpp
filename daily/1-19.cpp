#include<iostream>
using namespace std;

int n(int x)
{
    int sum=1;
    for(;x!=1;x--)
    {
        sum*=x;
    }
    return sum;
}



int main(){
    cout<<n(5);
}
