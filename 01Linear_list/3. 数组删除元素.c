#include <stdio.h>
#define MAXSIZE 50
typedef struct{
	int elem[MAXSIZE];
	int length;
}seqList;

void Delete(seqList *La,int sum){
	int i,x=0;
	for(i = 0 ; i < La->length;i++){
 		if(La->elem[i]==sum){
		 	x++;
		 }else{
 			La->elem[i-x]=La->elem[i];	
 		}
	}
	La->length = La->length-x;
}
int main(void){
	seqList La;
	printf("输入线性表元素的数量:\n");
	scanf("%d",&La.length); 
	int i;
	for(i=0 ;i<La.length ;i++){
		scanf("%d",&La.elem[i]);
	}
	printf("输入你要删除的数:\n");
	int num;
	fflush(stdin); 
	scanf("%d",&num); 
	Delete(&La,num);
	for(i=0 ;i<La.length ;i++){
		printf("%d ",La.elem[i]);
	}
}