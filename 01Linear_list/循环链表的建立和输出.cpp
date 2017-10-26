#include <stdio.h>
#include <Stdlib.h>
typedef struct node{
	int date;
	struct node *next;
}LNode,*LinkList;

LinkList caeat_Linklist(){
	LinkList H = (LinkList)malloc(sizeof(LinkList));
	H->next =H;
	LNode *s,*r=H;
	int x;
	scanf("%d",&x);
	while(x!=-1){
		//ÉêÇë¿Õ¼ä 
		s=(LinkList)malloc(sizeof(LinkList));
		//Êý¾ÝÌî³ä 
		s->date = x;
		
		s->next = r->next;
		r->next =s;
		r=s;
		scanf("%d",&x);
	}
	return H;
}
void Ergodic(LinkList H){
	LNode *t=H;
	t=t->next;
	while(t->next!=H){
		printf("%d ",t->date);
		t=t->next;
	}
	printf("\n");
}

void Inverse(LinkList H){
	LNode *s = H->next,*t;
	H->next=NULL;
	while(t){
		t=s->next;
		s->next = H->next;
		H->next = s;
		s = t;
	} 
}
int main(void){
	LinkList H;
	H = caeat_Linklist();
	Ergodic(H);
	//Inverse(H);
	//Ergodic(H);
}