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
    void copyNodes(ListNodePos(T),int);
    void merge(ListNodePos(T)&,int,List<T>&,ListNodePos(T),int);
    void mergeSort(ListNodePos(T)&,int);
    void selectSort(ListNodePos(T),int);
    void insertSort(ListNodePos(T),int);

    public:
    List(){init();}
    List(List<T> const& L);
    List(List<T> const& L,Rank r,Rank n);
    List(ListNodePos(T) p,int n);

    ~List();
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
    void merge(List<T>& L){merge(first(),size,L,L.first())}


};