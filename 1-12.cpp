#include<iostream>
using namespace std;

#include<iostream>
using namespace std;

/*template <class T,class T1>
bool
make2_array(T **&array,int number_OF_rows,T1 row_Size){
        int i=0;
     try{
          array = new T* [number_OF_rows]; //创建数组指针 类型就是 T **
     
         while(i< number_OF_rows){
              array[i] =  new T [ row_Size[i] ];
              i++;
         }
           return 1;
     } 
       catch (bad_alloc){
              return false;
       }
}
int main(){
     char **a;
     int row_size[]{1,2,4,5,6};
      cout<< make2_array(a,3,row_size);
 
      return 1;
}*/


template<class T,class T1>
bool make2dArray(T **&x,int numOfRow,T1 rowSize)
{
    int i=0;
    try{
          x = new T* [numOfRow]; //创建数组指针 类型就是 T **
     
         while(i< numOfRow){
              x[i] =  new T [rowSize[i]];
              i++;
         }
           return true;
     } 
       catch (bad_alloc){
              return false;
       }

}

int main(){
    int rowSize[]={1,2,3,4,5};
    int **x;
    cout<<make2dArray(x,4,rowSize)<<endl;
    for(int i=0;i<4;i++)
        delete [] x[i];
    delete [] x;
    x=NULL;

}