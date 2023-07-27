#include"listNode.h"
#include<iostream>
using namespace std;


template<class T>
class List {
    private:
    int _size;
    ListNodePos(T) header;
    ListNodePos(T) trailer;

    protected:
    void init();
    int clear();
    void copyNodes(ListNodePos(T) p,int n);
    void merge(ListNodePos(T)& p,int n1,List<T>& L,ListNodePos(T) q,int n);
    void mergeSort(ListNodePos(T)& p,int n);
    void selectSort(ListNodePos(T) p,int n);
    void insertSort(ListNodePos(T) p,int n);

    public:
    List(){init();}
    List(List<T> const& L);
    List(List<T> const& L,Rank r,Rank n);
    List(ListNodePos(T) p,int n);

    ~List(){};
    Rank size()const {return _size;}
    bool empty(){return _size<=0;}
    T& operator[](Rank r) const;
    ListNodePos(T) first() const{return header->suc;}
    ListNodePos(T) last() const{return trailer->pre;}
    bool vaild(ListNodePos(T) p){
        return p&&(trailer!=p)&&(header!=p);
    }
    int disordered() const;
    ListNodePos(T) find(T const& e)const{
        return find(e,_size,trailer);
    }
    ListNodePos(T) find(T const& e,int n,ListNodePos(T) p) const;
    ListNodePos(T) search(T const&e) const
    {
        return search(e,_size,trailer);
    }
    ListNodePos(T) search(T const& e,int n,ListNodePos(T) p);
    ListNodePos(T) selectMax(ListNodePos(T) p,int n);
    ListNodePos(T) selectMin(ListNodePos(T) p,int n);
    ListNodePos(T) selectMax(){
        return selectMax(header->suc,_size);
    }
    

    //可写接口
    ListNodePos(T) insertFirst(T const& e);
    ListNodePos(T) insertLast(T const& e);
    ListNodePos(T) insertB(ListNodePos(T) p,T const& e);
    ListNodePos(T) insertA(ListNodePos(T) p,T const& e);


    T remove(ListNodePos(T) p);
    void merge(List<T>& L){merge(first(),size,L,L.first());}
    void sort(ListNodePos(T) p,int n);
    void sort(){sort(first(),_size);}
    int deduplicate();
    int uniquify();
    int reserve();

    void traverse(void(*visit) (T&));
    template<class VST>
    void traverse(VST&);

};


template<class T>
void List<T>::init(){
    header= new ListNode<T>;
    trailer= new ListNode<T>;

    header->suc=trailer;
    header->pre=NULL;
    trailer->pre=header;
    trailer->suc=NULL;

    _size=0;
}

template<class T>
List<T>::List(List<T> const& l){
    init();
    copyNodes(l.header->suc,l._size);
}

//从r开始，复制n个
template<class T>
List<T>::List(List<T> const& L,Rank r,Rank n){
    init();
    ListNodePos(T) p=L.header->suc;

    while(r!=0)
    {
        p=p->suc;
        r--;
    }
    copyNodes(p,n);
}

template<class T>
List<T>::List(ListNodePos(T) p,int n){
    init();
    copyNodes(p,n);
}


template<class T>
int List<T>::clear()
{   
    int oldsize=_size;
    while(_size--) remove(header->suc);
    return oldsize;
}

template<class T>
T List<T>::remove(ListNodePos(T) p){
    T e=p->data;
    p->pre->suc=p->suc;
    p->suc->pre=p->pre;
    _size--;
    delete p;
    return e;
}

template<class T>
void List<T>::copyNodes(ListNodePos(T) p,int n){
        init();
        while(n--)
        {
            insertLast(p->data);
            p=p->suc;
        }
}

template<class T>
ListNodePos(T) List<T>::insertLast(T const& e){
    _size++;
    return trailer->insertPre(e);
}

template<class T>
ListNodePos(T) List<T>::insertFirst(T const& e){
    _size++;
    return header->insertSuc(e);
}

template<class T>
ListNodePos(T) List<T>::insertA(ListNodePos(T) p,T const& e){
    _size++;
    return p->insertSuc(e);
}

template<class T>
ListNodePos(T) List<T>::insertB(ListNodePos(T) p,T const& e){
   _size++;
   return p->insertPre(e);
}


//向后查找
template<class T>
ListNodePos(T) List<T>::find(T const& e,int n,ListNodePos(T) p) const{

    while(n--)
    {
        if(p->data==e)
            return p;
        else 
            p=p->suc;
    }
    return NULL;
}

template<class T>
ListNodePos(T) List<T>::search(T const& e,int n,ListNodePos(T) p){
    //有序区间查找出最大的不大于e的元素
    while(0<=n--)
    {
        if(p->data<=e)
            {p=p->pre;break;}
    }
    return p;
}

template<class T>
int List<T>::deduplicate(){
    if(_size<2) return 0;
    ListNodePos(T) pn=trailer;
    int oldsize=_size;
    Rank r=0;
    while(header!=pn){
        ListNodePos(T) q=find(pn->data,r,pn);
        q?remove(q):r++;
        }
        return oldsize-_size;
    }


template<class T>
int List<T>::uniquify(){
    if(_size<2) return 0;
    int oldsize;
    ListNodePos(T) p=header,q=header->suc;
    while(trailer!=q)
    {
        if(p->data==q->data)
            remove(q);
        else    
            p=q;
            q=q->suc;
    }
    return oldsize-_size;
}


template<class T>
ListNodePos(T) List<T>::selectMax(ListNodePos(T) p,int n){
    ListNodePos(T) q=p->suc;
    while(1<n--)
    {
        if((p->data)<=(q->data))
            p=q,q=q->suc;
        else q=q->suc;
    }
    return p;
}

template<class T>
ListNodePos(T) List<T>::selectMin(ListNodePos(T) p,int n)
{
    ListNodePos(T) q=p->suc;
    while(n--)
    {
        if(p->data>=q->data)
            p=q,q=q->suc;
        else q=q->suc;
    }
    return p;
}

template<class T>
int List<T>::reserve(){
    ListNodePos(T) p;
    ListNodePos(T) q;
    p=header->suc;
    q=trailer->pre;
    T temp;
    int n=_size/2;
    while(n--)
    {
        temp = q->data;
        q->data=p->data;
        p->data=temp;
        p=p->suc;
        q=q->pre;
    }
    return 0;
}

template<class T>
T& List<T>::operator[](Rank r) const{
    ListNodePos(T) p=header->suc;
    while(r--)
    {
        p=p->suc;
    }
        return p->data;
}

//检查是否升序,返回逆序对数量
template<class T>
int List<T>::disordered() const{
    ListNodePos(T) p=header->suc;
    ListNodePos(T) q=p->suc;
    int count=0;
    while(q!=trailer){
        if(p->data>q->data)
            count++;
        p=p->suc;
        q=q->suc;
    }
    return count;
}

template<class T>
void List<T>::traverse(void(*visit)(T&)){
    for(ListNodePos(T) p=header->suc;p!=trailer;p=p->suc)
        visit(p->data);
}

template<class T>  
template<class VST>
void List<T>::traverse(VST&visit){
    ListNodePos(T) p=header->suc;
    for(;p!=trailer;p=p->suc)
        visit(p->data);
}

template <typename T>
void visit(T& element)
{
    std::cout << element << std::endl;
}

template<class T>
void List<T>::insertSort(ListNodePos(T) p,int n){
    for(int r=0;r<n;r++)
    {
        insertA(search(p->data,r,p),p->data);
        p=p->suc;
        remove(p->pre);
    }
}

template<class T>
void List<T>::selectSort(ListNodePos(T) p,int n){
    ListNodePos(T) head=p->pre;
    ListNodePos(T) tail=p;
    for(int i=0;i<n;i++)
        tail=tail->suc;
   
    while(1<n){
        ListNodePos(T) max=selectMax(head->suc,n);
        insertB(tail,max->data);
        remove(max);
        tail=tail->pre;
        n--;
    }
}

template<class T>
void List<T>::sort(ListNodePos(T) p,int n){
    switch (rand()%2)
    {
    case 1:selectSort(p,n);
        break;
    case 2:insertSort(p,n);
        break;
    default:
        break;
    }
}

int main(){
    
    List<int> lp;
    
    lp.insertA(lp.insertFirst(2),1);
    lp.insertLast(3);

    cout<<lp[2]<<endl;
    cout<<lp.disordered()<<endl;

    List<int> lq(lp);
    cout<<lq[2]<<endl;

    List<int> ls(lp,0,2);
    cout<<ls[0]<<' '<<ls[1]<<endl;

    lp.traverse(visit<int>);

    cout<<(lp.selectMax(lp.first(),2))->data<<endl;

    lp.traverse(visit<int>);
    lp.sort(lp.first(),3);
    lp.traverse(visit<int>);
    return 0;

}

