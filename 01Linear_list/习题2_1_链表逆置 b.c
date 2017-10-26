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
	Inverse(H);
	Ergodic(H);
}