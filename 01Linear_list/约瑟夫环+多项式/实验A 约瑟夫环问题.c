#include <stdio.h>
#include <stdlib.h>
struct node
{
    int NO;
    struct node *next;
};
struct node *create(int iCound)
{
    struct node *pHead=NULL,*pEnd,*pNew;
    int i;
    pEnd =pHead=(struct node*)malloc(sizeof(struct node)); 
    for(i=0,pNew=pEnd;i<iCound;i++)
    {
        pEnd=pNew;
        pEnd->NO = pNew ->NO+1;
        pNew=(struct node*)malloc(sizeof(struct node)); 
        pEnd->next=pNew; 
    }
    pEnd->next=pHead;
    return pHead;
}
struct node *f1(struct node *pHead,int iCound,int M)
{
    struct node *pi=pHead,*pi_q=pHead->next;
    int i;
    while(pi_q->next!=pi)
        pi_q=pi_q->next;
    while(pi!=pi->next)
    { 
        for(i=0;i<M-1;i++)
        {
            pi_q=pi;
            pi=pi->next;
        }
        printf("%d ",pi->NO);
              
        pi_q->next=pi->next; 
        pi=pi->next;
    }
    printf("%d\n",pi->NO); 
}
int main(void)
{
    struct node *pHead;
    int iCound,m;
    scanf("%d %d",&iCound,&m); 
    pHead=create(iCound); 
    f1(pHead,iCound,m);
} 