#include <stdio.h>
#include <Stdlib.h>
typedef struct node{
	int date;
	struct node *next;
}LNode,*LinkList;

LinkList caeat_Linklist(){
	LinkList H = (LinkList)malloc(sizeof(LinkList));
	H->next =NULL;
	LNode *s,*r=H;
	int x;
	scanf("%d",&x);
	while(x!=-1){
		s=(LinkList)malloc(sizeof(LinkList));
		s->date = x;
		s->next = r->next;
		r->next =s;
		r=s;
		scanf("%d",&x);
	}
	return H;
}
void Ergodic(LinkList H){
	H=H->next;
	while(H){
		printf("%d ",H->date);
		H=H->next;
	}
	printf("\n");
}

void f1(LinkList H){
	LinkList p,q,pNew,qNew,Ht,Hq;
	pNew=p = (LinkList)malloc(sizeof(LinkList));
	qNew=q = (LinkList)malloc(sizeof(LinkList));
	qNew->next=NULL;
	pNew->next=NULL;
	Ht=H->next;
	while(Ht){
		if(((Ht->date)%2)==1){
			for(pNew=p;pNew->next&&Ht->date > pNew->next->date;pNew=pNew->next);
		
			Hq=Ht->next;
			
			Ht->next=pNew->next;
			pNew->next = Ht;
			
			Ht =Hq;
			Ergodic(p); 
			
		}else{
			for(qNew=q;qNew->next&&Ht->date>qNew->next->date;qNew=qNew->next);
		
			Hq=Ht->next;
			
			Ht->next=qNew->next;
			qNew->next = Ht;
			
			Ht =Hq;
			Ergodic(q); 
		}
	}
	Ergodic(p);
	Ergodic(q);		
}
int main(void){
	LinkList H;
	H = caeat_Linklist();
	Ergodic(H);
	f1(H);
}