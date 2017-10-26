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
struct node *create(int iCound,int num)// iCound 链表节点个数，num等差数列的公差 
{
	struct node *pHead=NULL,*pEnd,*pNew;
	int i,j;
	pEnd =pHead=(struct node*)malloc(sizeof(struct node));	 
	for(i=0,j=0;i<iCound;i++)
	{
		pNew=(struct node*)malloc(sizeof(struct node));
		pNew->date=j;
		j+=num;
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
struct node *merge(struct node *pHead_a,struct node *pHead_b)
{
	struct node *La,*Lb,*Lc,*La_t,*Lb_t;
	La=pHead_a->next;
	Lb=pHead_b->next;
	Lc=pHead_a;
	while(La&&Lb)
	{
		if((La->date)<(Lb->date))
		{
			Lc->next = La;
			Lc=La;
			La=La->next;			
		}
		else
		{
			Lc->next = Lb;
			Lc=Lb;
			Lb=Lb->next;	
		}
	}

	if(La)
	{
		Lc->next=La;	
	}
	else
	{
		Lc->next=Lb;	
	}
	free(pHead_b);
	return pHead_a;
}
int main(void)
{
	struct node *pHead_a,*pHead_b;
	srand((unsigned)time(NULL));
	int iCound_a=rand()%20+1,iCound_b=rand()%20+1;//a,b节点长度随机 
	int a=rand()%4+1,b=rand()%4+1;//a,b公差随机 
	pHead_a=create(iCound_a,a); 
	pHead_b=create(iCound_b,b);
	output(pHead_a);
	output(pHead_b);
	pHead_a=merge(pHead_a,pHead_b);
	output(pHead_a);
} 