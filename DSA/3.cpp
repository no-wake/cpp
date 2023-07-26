#include"listNode.h"
#include<iostream>
using namespace std;


template<class T>
class List {
    private:
    int _size;
    ListNodePos(T) header,trailer;

    protected:
    void init();
    int clear();
    void copyNodes(ListNodePos(T) p,int n);
    void merge(ListNodePos(T)&,int,List<T>&,ListNodePos(T),int);
    void mergeSort(ListNodePos(T)&,int);
    void selectSort(ListNodePos(T),int);
    void insertSort(ListNodePos(T),int);

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

    void traverse(void(*) (T&));
    template<class VST>
    void traverse(VST&);

};


template<class T>
void List<T>::init(){
    header= new ListNodePos(T);
    trailer= new ListNodePos(T);

    header->suc=trailer;
    header->pre=NULL;
    trailer->pre=header;
    trailer->suc=NULL;

    _size=0;
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
    while(n>0)
    {
        init();
        while(n--)
        {
            insertLast(p->data);
            p=p->suc;
        }
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
    while(n--)
    {
        if(p->data<=e)
            p=p->suc;
        else return p;
    }
}

template<class T>
int List<T>::deduplicate(){
    ListNodePos(T) pn=trailer;
    int oldsize=_size;
    Rank r=0;
    while(header!=pn){
        ListNodePos(T) q=find(pn->data,r,pn);
        q?remove(q):r++;
        }
        return oldsize-_size;
    }




int main(){
    return 0;
}

