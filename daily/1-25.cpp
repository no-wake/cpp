#include<iostream>
using namespace std;
void Subset(char a[], int n, int len) {
 
	if (n == 0) {  // 递归终止条件
 
		for (int i = 0; i < len; i++) cout << a[i];
		cout << endl;
		delete[] a;  // 这里的a 就是temp
		return;
	}
 
	for (int j = 0; j <= 1; j++) { //每次需要做两种决策
 
		char *temp = new char[len];  
		
		for (int i = 0; i < len; i++) temp[i] = a[i];  //用临时数组来覆盖原来数组
 
		if (j == 0) { 
			temp[n - 1] = '0';
		}else {
			temp[n - 1] = '1'; 
		}
		Subset(temp, n - 1,len);
		
	}
	
}
 
 
int main()
{
	char a[3] = { 'a','b','c'};
	Subset(a, 3,3);
	
    return 0;
}

