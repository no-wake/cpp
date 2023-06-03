#include<iostream>
using namespace std;

int F1_n(int x){
    
    if(x==0) return 0;
    else if(x==1) return 1;
    else return F1_n(x-1)+F1_n(x-2);
    
}

int F2_n(int x)
{
    int f[x];
    f[0]=0;
    f[1]=1;
    for(int i=2;i<=x;i++)
    {
        f[i]=f[i-1]+f[i-2];
    }
    return f[x];
}

//非递归的更好版本
int fib(int n){
      if(n <=2){
           return 1;
      }
    int f,f1=1,f2=1;
       while(n>2){
            f=f1+f2;
            f1=f2;
            f2=f;
            n--;
       }
       return f;
}


int main(){
    int x=6;
    cout<<F1_n(x)<<endl;
    cout<<F2_n(x)<<endl;
    cout<<fib(x)<<endl;
}