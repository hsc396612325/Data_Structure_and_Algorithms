#include <stdio.h>
#include <string.h>

#define Max 100
void postpone(char a[],int n){ //置后 
	int i;
	int al = strlen(a);
	
	for(i=0;a[i];i++){
		a[n-al+i] = a[i];
		a[i] = 0;
	}
}

void prin(char a[],int n){  //输出置后字符串 
	int i;
	for(i=0;i<n;i++){
		if(a[i]!=0){
			printf("%c",a[i]);
		}
	} 
	
	printf("\n");
}

void add(char a[],char b[],char c[]){  //加法，结果存在a数组中 
	
	int i,num,fi=0;
	for(i=Max-1;a[i]!=0||b[i]!=0||fi!=0;i--){
		a[i]==0?a[i]='0':0;
		
		b[i]==0?b[i]='0':0;
		
		num = a[i]-'0'+b[i]-'0'+fi;
		c[i]= num%10 +'0';
		fi = num/10;
	}
}

void multiplication (char a[],int n,char c[]){  //多位数 X 一位数(0~10) ,结果存在c中 

	int i,num,fi=0;
	for(i=Max-1;a[i]!=0||fi!=0;i--){
		a[i]==0?a[i]='0':0;
	
		num = (a[i]-'0')*n+fi;
		c[i]= num%10 +'0';
		fi = num/10;
		
	}
} 


void  multiplicationMax (char a[],char b[],int bl,char c[]){  //多位数 X 多位数(bl 第二个乘数的长度) ,结果存在c中 
	int i;
	
	char num[Max]={0};
	for(i = Max -bl;i<Max;i++){
		multiplication(a,b[i]-'0',num); 
	
		multiplication(c,10,c);//c = c*10
		add(c,num,c);//c = c+num
	} 
} 

int main(void){
	char a[Max]={0},b[Max]={0},c[Max]={0};
	gets(a);
	gets(b);
	int bl =strlen(b); 
	
		
	postpone(a,Max);
	postpone(b,Max); 
	
    multiplicationMax (a,b,bl,c);
	prin(c,Max);

	return 0;
} 

