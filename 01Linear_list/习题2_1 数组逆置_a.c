#include <stdio.h>
#define MAXSIZE 50
typedef struct{
	int elem[MAXSIZE];
	int length;
}seqList;

void Inverse(seqList *La){
	int i,t;
	for(i = 0 ; i < La->length/2;i++){
 		t = La->elem[i];
		La->elem[i] = La->elem[La->length-i-1];
		La->elem[La->length-i-1] = t;
	}
}
int main(void){
	seqList La;
	printf("输入线性表元素的数量");
	scanf("%d",&La.length); 
	int i;
	for(i=0 ;i<La.length ;i++){
		scanf("%d",&La.elem[i]);
	}
	
	Inverse(&La);
	for(i=0 ;i<La.length ;i++){
		printf("%d ",La.elem[i]);
	}
}