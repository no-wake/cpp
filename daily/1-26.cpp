#include<iostream>
using namespace std;

void hd(int n){
    if(n==1)cout<<1<<' ';
    else
        {
            hd(n-1);
            cout<<n<<' ';
            hd(n-1);
        }
    return;
}

int main()
{
    int x=5;
    hd(x);
}