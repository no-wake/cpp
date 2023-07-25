#include<vector>
#include<iostream>
using namespace std;
/*

//冒泡排序
template<class T>
void Vector<T>::bubblesort(Rank lo,Rank hi ){
    while(!bubble(lo,hi--));
}

tmplate<class T>
bool Vector<T>::bubble(Rank lo,Rank hi){
    bool sorted=true;
    while (++lo<hi){
        if(_elem[lo-1]<_elem[lo]){
            sorted=false;
            swap(_elem[lo-1],_elem[lo]);
        }
    }
    return sorted;
}


//归并排序
//迭代式算法。每步迭代，比较两个带归并向量的首元素，直到某一向量为空，将另一非空向量整体接至输出向量的末尾。

template<class T>
void Vector<T>::mergeSort(Rank lo,Rank hi)
{
    if(hi-lo<2) return;
    int mi=(lo+hi)/2;
    mergeSort(lo,mi);mergeSort(mi,hi);
    merge(lo,mi,hi);
}

template<classT>
void Vector<T>::merge(Rank lo,Rank mi,Rank hi)
{
    T* A=_elem+lo;
    int lb=mi-lo;T* B=new T[lb];
    int lc=hi-mi;T* C=_elem + mi;
    for(Rank i=0;i<lb;i++)
        B[i]=A[i];
    for(Rank i=0,j=0,k=0;(j<lb)||(k<lc);){
        if((j<lb)&&(!k<lc)||(B[j]<=C[k])) A[i++]=B[j++];
        if((k<lc)&&(!j<lb)||(C[k]<B[k])) A[i++]=C[k++];
    }

    delete[] B;
}
*/