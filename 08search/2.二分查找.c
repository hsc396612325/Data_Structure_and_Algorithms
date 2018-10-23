#include <stdio.h>
int Binary_Search(int *a,int n,int key){
	int low,high,mid;
	low = 1;
	high = n;
	while(low <= high){
		mid=(low + high)/2;
		if(key < a[mid]){
			high = mid-1;
		}else if(key == a[mid]){
			return mid;
		}else if(key > a[mid]){
			low = mid+1;
		}
	}
	return 0;
}

int main (void){
	int a[11]={0,1,16,24,35,47,59,62,73,88,99};
	printf("%d\n",Binary_Search(a,10,62));
}
