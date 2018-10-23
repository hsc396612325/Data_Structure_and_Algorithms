#include <stdio.h>
#include <string.h>

#define Max 100
void postpone(char a[],int n){ //置后  参数a需要置后的字符串，参数n字符串所在数组的空间大小
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
//加法，结果存在b数组中 
//参数含义：c = a+b
void add(char a[],char b[],char c[]){   
	
	int i,num,fi=0;
	for(i=Max-1;a[i]!=0||b[i]!=0||fi!=0;i--){
		a[i]==0?a[i]='0':0;
		
		b[i]==0?b[i]='0':0;
		
		num = a[i]-'0'+b[i]-'0'+fi;
		c[i]= num%10 +'0';
		fi = num/10;
	}
}
int main(void){
	char a[Max]={0},b[Max]={0},c[Max]={0};
	gets(a);
	gets(b);
	int bl =strlen(b); 
			
	postpone(a,Max);
	postpone(b,Max); 
	
    add(a,b,c);  //c= a+b
	prin(c,Max);

	return 0;
} 