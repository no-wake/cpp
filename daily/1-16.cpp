#include"currency(1-16).h"
int main()
{
    currency g,h(signType::plus,3,50),i,j,k,l,m,n,o,p,q;
    g.setValue(signType::plus,2,25);
    
    g.output();
    h.output();
    
    i=h.subtract(g);
    i.output();
    
    k=h.percent(50);
    k.output();
    
    j.input();
    j.output();

    l=h.mulitiply(2);
    l.output();

    m=h.div(2);
    m.output();

    n=h+m;
    n.output();

    h+=g;
    h.output();

    o=l/2;
    std::cout<<o;
    
    p=-3.24;
    std::cout<<p;

    return 0;
}