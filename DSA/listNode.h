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

    ListNodePos(T) insertBefore(T &const e);
    ListNodePos(T) insertAfter(T &const e);
};



#endif