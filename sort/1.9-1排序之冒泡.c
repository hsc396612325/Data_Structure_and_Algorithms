#include <stdio.h>
#define N 5
int main (void)
{
	int a[N],i,j;
	printf("ÇëÊäÈë%d¸öÊı\n",N);	
	for(i=0;i<N;i++)
		scanf("%d",&a[i]);
	for(i=0;i<N;i++)
		for(j=0;j<N-1-i;j++)
			if(a[j+1]>a[j])
			{
				a[j+1]=a[j+1]+a[j];
				a[j]=a[j+1]-a[j];
				a[j+1]=a[j+1]-a[j];
			}
	for(i=0;i<N;i++)
		printf("%-5d",a[i]);
	return 0;
}