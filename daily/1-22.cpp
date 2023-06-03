#include<iostream>
#include<math.h>
using namespace std;

int Ack(int x,int y){
    if((x==1)&&(y>=1)) return pow(2,y);
    else if((x>=2)&&(y==1)) return Ack(x-1,2);
    else return Ack((x-1),(Ack(x,y-1)));
}

int main(){

    int x=2,y=2;
    cout<<Ack(x,y);
}
