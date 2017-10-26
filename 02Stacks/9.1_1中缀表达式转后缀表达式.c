#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 40
#define TRUE 1
#define FALSE 0 
typedef struct
{
	char string[10]; 
} Elemtype;
typedef struct
{
	Elemtype data[MAXSIZE]; 
	int top; 
}SeqStack; 

//新建一个空栈
SeqStack *InitStack (){
	 
	SeqStack *S;
	S=malloc(sizeof(SeqStack));
	 
	S->top =-1; 
	return S;
}


//判断是否为空栈 
int StackEmpty (SeqStack *S){
	if(S->top==-1)
		return TRUE;
	else 
		return FALSE; 
} 

//入栈
int Push (SeqStack *S,Elemtype e){
	if(S->top==MAXSIZE-1) 
		return FALSE;
	
	S->top++;
	S->data[S->top]= e;
	return TRUE;
} 

//出栈并返回 
int Pop (SeqStack *S,Elemtype *e){
	if(S->top == -1) 
		return FALSE;
		
	*e=S->data[S->top];
	S->top--;	
	return TRUE;
} 

	    
//取出栈顶元素 
int GetTop (SeqStack *S,Elemtype *e){
	if(S->top == -1) 
		return FALSE;
	else{
		*e=S->data[S->top];	
		return TRUE;
	}
} 
SeqStack *result;
int Convert(char str[]) {
	Elemtype e1,e2;
	int i,count=0;
	printf("%s\n",str); 
	for(i=0;str[i];i++){
		
		if(str[i]>='0'&&str[i]<='9'){ //如果是数字
			e1.string[count]=str[i];
			count++;
		} 
		if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'){
			e1.string[count]=0;
			Push(result,e1);//入栈数字
			
			e2.string[0]=str[i];
			e2.string[1]=0;
			Push(result,e2);//入栈符号 
			
			
		 	count=0;//数字的计数器重置 
		}

	}
	//结束时
	e1.string[count]=0;
	Push(result,e1);//入栈数字 
	
	for(i=0;i<result->top+1;i++){
		printf("%s\n",result->data[i].string);
	}
}
int main(void){
	result=InitStack();//创建栈
	char str[100]="123+123-345*12/12";
	//scanf("%s",str); 
	Convert(str);
}