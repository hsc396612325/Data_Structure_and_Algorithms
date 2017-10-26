#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h> 

struct node
{
	int date; 
	struct node *next;
};
struct node *create(int iCound)//???????? 
{
	struct node *pHead=NULL,*pEnd,*pNew;
	int i;
	pEnd =pHead=(struct node*)malloc(sizeof(struct node)); 
	for(i=0;i<iCound;i++)
	{
		pNew=(struct node*)malloc(sizeof(struct node));
		pNew->date=rand()%100;
		pEnd->next=pNew;
		pEnd=pNew;
	}
	pNew->next=NULL;
	return pHead;
}
void output(struct node *pHead)
{
	pHead=pHead->next;
	while(pHead)
	{

		printf("%-5d",pHead->date);
		pHead=pHead->next;
	}
	printf("\n");
}
void merge(struct node *pHead_x,struct node *pHead_y)
{
	struct node *Lx,*Lx_h,*Ly,*Lz;
	Lx=pHead_x->next;
	Ly=pHead_y->next;
	Lz=pHead_x;
	while(Lx)
	{
		Lz->next=Lx;
		Lx_h=Lx->next;
		
		Lx->next=Ly;
		Lz=Ly;
		
		Lx=Lx_h;
		Ly=Ly->next;
		
	}
	Lz->next=Ly;	
}
int main(void)
{
	struct node *pHead_a,*pHead_b;
	srand((unsigned)time(NULL));
	int iCound_a=rand()%20+1,iCound_b=rand()%20+1;//a,b???????? 
	pHead_a=create(iCound_a); 
	pHead_b=create(iCound_b);
	output(pHead_a);
	output(pHead_b);
	if(iCound_a<=iCound_b)
	{
		merge(pHead_a,pHead_b);
		output(pHead_a);
		free(pHead_b);
	}
	else
	{
		merge(pHead_b,pHead_a);
		output(pHead_b);
		free(pHead_a);
	}	
} 