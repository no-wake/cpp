#include<iostream>
using namespace std;

int abc(int a,int b,int c)
{
    if(a<0&&b<0&&c<0)throw 1;
    else 
        if(a==0&&b==0&&c==0)
            throw 2;
        else
            if(a<2&&b<2&&c<2)
                throw "a,b,c are smaller than 2.";
            else 
                if(a<5&&b<5&&c<5)
                    throw "a,b,c are smaller than 5.";
    return a*b+c;
}

int main(){
    try{cout<<abc(1,4,1)<<endl;}
    catch(int c)
    {
        cout<<"wrong!"<<endl;
        cout<<c<<endl;
        return 3;
    }
    catch(const char* e)
    {
        cout<<e<<endl;
    }
    return 0;
}