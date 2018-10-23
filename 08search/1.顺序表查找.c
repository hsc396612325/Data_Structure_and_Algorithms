#include <stdio.h>
//顺序查找, a为查找的数组(数组从1开始存储)，n为数组长度,key为要查找的关键字
int Sequential_Search(int *a,int n,int key){
	int i;
	for(i=1;i<n;i++){
		if(a[i] == key){
			return i;
		} 
	}
	return 0;
} 

//顺序查找, a为查找的数组(数组从1开始存储)，n为数组长度,key为要查找的关键字
int Sequential2_Search(int *a,int n,int key){
	int i;
	a[0]=key;
	for(i=n;a[i]!=key;i--);
	
	return i;
} 
int main (void){
	int a[11]={0,1,16,24,35,47,59,62,73,88,99};
	printf("%d\n",Sequential_Search(a,10,62));
	printf("%d\n",Sequential2_Search(a,10,62));
}
