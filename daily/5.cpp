#include<iostream>
#include"ArrList_.h"
using namespace std;

int main(){
    //实例化，创建线性表
    arrList<double> x(100);
    arrList<char> y(5);
    arrList<double> z(x);
    arrList<char> w(y);

    y.add('a');
    y.insert(0,'e');
    y.add('a');

    w.add('c');
    w.add('c');
    w.add('c');

    

    std::cout<<y.size()<<endl;
    std::cout<<y.getLength()<<endl;
    std::cout<<y.indexOf('a')<<endl;
    y.trimToSize();
    std::cout<<y.size()<<endl;

    x.trimToSize();
    std::cout<<x.size()<<endl;
    z.trimToSize();
    std::cout<<z.size()<<endl;

    x.add(1);
    z.add(2);


    y.setSize(4);
    std::cout<<y.size()<<endl;
    std::cout<<w.size()<<endl;

    std::cout<<(z==x?"true":"false")<<endl;
    std::cout<<(z!=x?"true":"false")<<endl;
    std::cout<<(w<y?"true":"false")<<endl; 

    return 0;

}