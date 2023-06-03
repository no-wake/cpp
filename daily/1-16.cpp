#include"currency(1-16).h"
int main()
{
    currency g,h(signType::plus,3,50),i,j,k,l,m;
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


    return 0;
}