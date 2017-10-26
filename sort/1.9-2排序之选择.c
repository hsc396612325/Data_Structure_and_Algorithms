#include <stdio.h>
#define N 5
int main (void)
{
	int a[N],i,j,t,f;
	printf("请输入%d个数\n",N);	
	for(i=0;i<N;i++)
		scanf("%d",&a[i]);
	for(i=0;i<N-1;i++)
	{
		t=i;				
		for(j=i+1;j<N;j++)
			if(a[j]>a[t])
				t=j;     //寻找最大值下标 
		if(t!=i)//交换 
		{
			a[i]=a[i]+a[t];
			a[t]=a[i]-a[t];
			a[i]=a[i]-a[t];
		}
	}
	for(i=0;i<N;i++)
		printf("%-5d",a[i]);
	return 0;
}