#ifndef _listNode
#define _listNode

#include<iostream>

typedef int Rank;
#define ListNodePos(T) ListNode<T>*

template<class T>
struct ListNode
{
    T data;
    ListNodePos(T) pre;
    ListNodePos(T) suc;
    ListNode(){}
    ListNode(T e,ListNodePos(T) p=NULL,ListNodePos(T) s=NULL):data(e),pre(p),suc(s){}

    ListNodePos(T) insertPre(T const& e);
    ListNodePos(T) insertSuc(T const& e);
};

template<class T>
ListNodePos(T) ListNode<T>::insertPre(T const& e){
    ListNodePos(T) pred=new ListNode(e,pre,this);
    pre->suc=pred;
    pre=pred;
    return pred;
}

template<class T>
ListNodePos(T) ListNode<T>::insertSuc(T const& e){
    ListNodePos(T) succ=new ListNode(e,this,suc);
    suc->pre=succ;
    suc=succ;
    return succ;
}

#endif