#ifndef Arrlist_
#define Arrlist_

#include<iostream>
#include<sstream>
#include<iterator>
#include<algorithm>
using namespace std;

//抽象类
template<class T>
class linearList
{
    public:
        virtual ~linearList(){};
        virtual bool empty() const = 0;
        virtual int size() const = 0;
        virtual T& get(int theIndex) const = 0;
        virtual int indexOf(const T& theElement) const =0;
        virtual void erase(int theIndex) =0;
        virtual void insert(int theIndex,const T& theElement)=0;
        virtual void output(ostream& out) const = 0;
};

//实例化
template<class T>
class arrList:public linearList<T>
{
    public:
        arrList(int initialCapacity=10);
        arrList(const arrList<T>&);
        arrList(const arrList<T>& theList,int newLength);
        ~arrList() {
            delete[] element;
            }

        bool empty() const;
        int size() const;
        T& get(int theIndex) const;
        int indexOf(const T& theElement) const;
        void erase(int theIndex);
        void insert(int theIndex,const T& theElement);
        void output(ostream& out) const;
        void add(T);
        int getLength(){return arrlength;}

        void trimToSize();
        void setSize(int);
        T& operator[](unsigned);
        bool operator==(arrList<T>&);
        bool operator!=(arrList<T>&);
        bool operator<(arrList<T>&);

    protected:
        void checkIndex(int theIndex) const;
        T *element;
        int arrlength;
        int listSize;

};


//构造函数定义
template<class T>
arrList<T>::arrList(int initialCapacity)
{
    if(initialCapacity<1)
    {
        ostringstream s;
        s<<"Initial capacity  = "<<initialCapacity<<" must be >0";
        throw s.str();
    }
    arrlength=initialCapacity;
    element= new T[arrlength];
    listSize=0;
}

//copy函数
template<class T>
void copy(T start,T end,T to)
{
    while(start!=end)
    {
        *to = *start;
        to++,start++; 
    }
}

template<class T>
void changeLength1D(T*&a,int oldLength,int newLength){
    if(newLength<0){}
    
    T*temp=new T[newLength];
    int num =min(oldLength,newLength);
    copy(a,a+num,temp);
    delete[] a;
    a=temp;
}

template<class T>
void arrList<T>::add(T newSth){
    listSize++;
    element[listSize-1]=newSth;
}


//复制构造函数
template<class T>
arrList<T>::arrList(const arrList<T>& theList)
{
    arrlength=theList.arrlength;
    listSize=theList.listSize;
    element=new T[arrlength];
    copy(theList.element,theList.element+listSize,element);
    
}


template<class T>
void arrList<T>::checkIndex(int theIndex) const{
    if(theIndex<0||theIndex>=listSize)
    {

    }
}

template<class T>
T& arrList<T>::get(int theIndex) const
{
    checkIndex(theIndex);
    return element[theIndex];
}

template<class T>
int arrList<T>::indexOf(const T& theElement) const{
    int theIndex=(int)(find(element,element+listSize,theElement)-element);
    if(theIndex==listSize)
        return -1;
    else return theIndex;
}

template<class T>
void arrList<T>::erase(int theIndex){
    checkIndex(theIndex);
    
    copy(element+theIndex+1,element+listSize,element+listSize);

    element[--listSize].~T();//调用析构函数
}

template<class T>
void arrList<T>::insert(int theIndex,const T& insert_value){
    checkIndex(theIndex);
    if(listSize==arrlength){
        //数组空间已满
        changeLength1D(element,arrlength,arrlength*2);
        arrlength*=2;
    }
    //copy_backward(),从最右端元素开始移动
    copy_backward(element+theIndex,element+listSize,element+theIndex+1);

    element[theIndex]=insert_value;
    listSize++;
}

template<class T>
bool arrList<T>::empty()const{
    return listSize==0;
}

template<class T>
int arrList<T>::size()const{
    return listSize;
}

template<class T>
void arrList<T>::output(ostream& out) const
{
    copy(element,element+listSize,ostream_iterator<T>(cout," "));
}


//未验证
//5-3,改变二维数组每一维的长度
template<class T>
void changeLength2D(T**&a,int oldRowLength,int oldCOlLength,int rowLength,int colLength)
{
    if(colLength<0||rowLength<0){

    }
    T*temp=new T[rowLength];
    for(int i=0;i<colLength;i++)
    {
        temp[i]=new T[colLength];
    }
    for(int i=0;i<colLength;i++){
        copy(a[i],a[i+min(oldRowLength,rowLength)],temp[i]);
    }
    delete[] a;
    a=temp;

}

/*行不通
//5-4,增加构造函数，指定一个值，在数组空间满时，改变数组长度，未指定值时，将数组长度加倍
template<class T>
arrList<T>::arrList(const arrList<T>& theList,int newLength){
    if(theList.arrlength==theList.listSize){
        if(newLength==0)
        {
            theList.arrlength;
        }
        else{
            theList.arrlength=newLength;
        }
    }
}*/

//5-5
//使数组长度等于max{listSize，1}
template<class T>
void arrList<T>::trimToSize(){
    listSize=max(listSize,1);
    if(listSize<1){this->add(0);};
}


//5-6
//指定线性表的大小
template<class T>
void arrList<T>::setSize(int newSize)
{
    if(listSize<=newSize)
    {
        listSize=newSize;
    }
    else
        {
            T *temp =new T[newSize];
            copy(element,element+newSize,temp);
            delete[] element;
            element=temp;
        }
}

//5-7
//重载[]，使表达式返回x[i]的  引用，没有第i个元素则抛出异常
template<class T>
T& arrList<T>::operator[](unsigned index)
{
    if(index>=listSize){
        std::cout<<"wrong!"<<endl;
    }
    return element[index];
}

//5-8
//重载==，使x==y返回true或false
template<class T>
bool arrList<T>::operator==(arrList<T>& a){
    int num=min(a.listSize,listSize);

    for(int i=0;i<=num;i++)
    {
        if(a.element[i]!=element[i])
            {
                return false;
            }
    }
    return true;
}

//5-9
//重载！=，使x！=y返回true或false
template<class T>
bool arrList<T>::operator!=(arrList<T>& a){
    return !(*this==a);
}

//5-10
//重载<，使x<y返回true或false
template<class T>
bool arrList<T>::operator<(arrList<T>& a){
    int num=min(a.listSize,listSize);

    for(int i=0;i<=num;i++)
    {
        if(element[i]<a.element[i])
            {
                return true;
            }
    }
    return false;
}

#endif