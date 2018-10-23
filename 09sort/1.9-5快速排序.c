#include <stdio.h>
int a[20],n;
void quichsort(int left,int right)
{
	int i,j,t,temp;
	if(left>right)
		return;	
	
	temp=a[left];//temp为基准数
	i=left;
	j=right;
	while(i!=j)
	{
		while(a[j]>=temp&&i<j)
			j--;
		while(a[i]<=temp&&i<j)
			i++;
		if(i<j)//如果哨兵没有相遇,交换 
		{
			t=a[i];
			a[i]=a[j];
			a[j]=t; 
		} 
	} 
	a[left]=a[i];//基准数归位 
	a[i]=temp;
	
	quichsort(left,i-1);
	quichsort(i+1,right); 
}
int main(void)
{
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	quichsort(0,n-1);
	
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
} 
/* 思路：当排序完毕后，一个数的右边全部是比他小的数，左边全是比他大的数。根据这个原理进行快排
步骤：1，把最左的数当作基准数，一边从左找一个比他小的数，一边从右找一个比他大的数。
      2，倘若两个哨兵没有相遇交换。
	  3，进行递归，继续对基准数左边和右边的数进行上述过程，直到传过去的数列只有一个数 

思考：为何只能进行从左边开始找起，
		例如 3 1 2 5 4数列
		假如从左边开始找，i找的数为5，j无法过去和i相遇在5的地方，5和3交换，交换后变成5 1 2 3 4
		本次排序没有达到目的，基准数3右边存在比他大的数 
*/ 
