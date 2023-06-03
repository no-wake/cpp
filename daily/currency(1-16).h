
#ifndef Currency_
#define Currency_

#include<iostream>
using namespace std;
enum signType{plus,minus};

class currency{
     public:
        currency(signType theSign= signType::plus,
                 unsigned long theDollars=0,
                 unsigned int theCents = 0)
                  {
                    setValue(theSign,theDollars,theCents);
                  }; //构造函数  外部定义  

        ~currency(){};//析构函数 为空 
        void setValue(signType,unsigned long,unsigned int ); //原型 定义在class 外部 
        currency add(const currency&) const; //此const表示 不改变参数的内容 
        void output() const;
        void input(); //(1)
        currency subtract(const currency&) const;//(2)
        currency percent(double x);//3
        currency mulitiply(double x);
        currency div(double x);
 
 
 
        private :  //只能通过成员函数访问  不能对象私自 访问
            signType sign;
            unsigned long dollars;
            unsigned int cents;
}; 

void currency::setValue(signType theSign,unsigned long theDollars,unsigned int theCents)
{
    if(theCents>99)
        throw "Cents should be < 100";
    sign=theSign;
    dollars=theDollars;
    cents=theCents;
}


void currency::output() const{
    if(sign==signType::minus)cout<<"-";
    cout<<"$"<<dollars<<".";
    if(cents<10)cout<<0;
    cout<<cents<<endl;
}

void currency::input(){
    long temp;
    std::cin>>temp;
    if(temp>=0) sign=signType::plus;
    else temp=-temp,sign=signType::minus;
    
    dollars=temp/100;
    cents=temp-dollars*100;

}

currency currency::subtract(const currency& x) const{
//把x和*this相减
    long a1,a2,a3;
    currency result;

    //转为符号整数
    a1=dollars*100+cents;
    if(sign==signType::minus) a1=-a1;

    a2=x.dollars*100+x.cents;
    if(sign==signType::minus) a2=-a2;

    a3=a1-a2;

    if(a3<0){result.sign=signType::minus;}
    else result.sign=signType::plus;
    result.dollars=a3/100;
    result.cents=a3-result.dollars*100;

    return result;
}

currency currency::percent(double x)
{
    currency result;

    long temp;
    temp=dollars*100+cents;
    temp=temp*x/100;
    result.dollars=temp/100;
    result.cents=temp-result.dollars*100;
    result.sign=sign;

    return result;
}

currency currency::mulitiply(double x){
    currency result;
    long temp;

    temp=dollars*100+cents;
    temp=temp*x;
    result.dollars=temp/100;
    result.cents=temp-result.dollars*100;
    if((x<0&&sign==signType::plus)) result.sign=signType::minus;
    else if((x<0&&sign==signType::minus)) result.sign=signType::plus;
    else result.sign=sign;

    return result;
}

currency currency::div(double x){
    if(x==0)throw "x shouldn't be 0.";
    
    currency result;
    long temp;

    temp=dollars*100+cents;
    temp=temp/x;
    result.dollars=temp/100;
    result.cents=temp-result.dollars*100;
    if((x<0&&sign==signType::plus)) result.sign=signType::minus;
    else if((x<0&&sign==signType::minus)) result.sign=signType::plus;
    else result.sign=sign;

    return result;
}

#endif