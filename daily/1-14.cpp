#include<iostream>
using namespace std;

template<class T >
T**changeLength_2D(T ** &array,int row,int col,int oldRow,int oldCol){
    T ** newRow= new T * [row];
     for(int i=0;i <col ;i++){
           newRow[i]= new T[col];
     } //init
      
       for (int i=0;i<oldRow;i++){
            for(int j = 0;j<oldCol;j++){
                 newRow[i][j]= array[i][j]; 
            }
       }
         delete [] array;
         return newRow;
}
int main(){
      int **a = new int *[3];
        for( int i=0;i<3;i++){
             a[i] = new int [5];
        }
          for(int i=0;i<3;i++){
              for(int j=0;j<5;j++){
                   a[i][j]=666;
              }
          }
      int ** new_a= changeLength_2D(a,10,10,3,5);
      new_a[9][9]=999;
       cout<< new_a[2][3]<<' '<<new_a[9][9];
 
       return 0;
}
