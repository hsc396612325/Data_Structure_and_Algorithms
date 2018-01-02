#include <stdio.h>
#define IO "souceFile.txt"
bucket[128];
void statistics(){
	FILE *fp;
	char ch;
	fp = fopen("souceFile.txt","rb"); 
	if(fp==NULL)
    {
        printf("文件打开失败\n");
        exit(0);
    }
    while((ch=fgetc(fp))!=EOF){
    	bucket[ch]++;	
    }
    int i; 
    for(i=0;i<128;i++){
    	if(bucket[i]){
	    	printf("%d,%c-->%d\n",i,i,bucket[i]);
	    } 	
    } 
    fclose(fp);
}
int main(void){
	statistics();
}