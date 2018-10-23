#include <stdio.h>
#define N 5
int main (void)
{
	int a[N],i,j,t;
	printf("请输入%d个数\n",N);	
	for(i=0;i<N;i++)
		scanf("%d",&a[i]);
	
	// 已知A[0..i-1]已排序，将A[i]插入使得A[0..i]成为新的已排序数组   	
	for(i=1;i<N;i++)
	{
		t=a[i];//X是从无序数组中取出一个元素
		for(j=i-1;t>a[j];j--)//j是有序表中最后一个元素
			a[j+1]=a[j];
		a[j+1]=t;
	}	
	for(i=0;i<N;i++)
		printf("%-5d",a[i]);
	return 0;	
}