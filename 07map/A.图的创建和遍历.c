#include <stdio.h>
#include <stdlib.h>
#define MAXVEX 20
typedef char Vertype;
typedef struct{
	int acre[MAXVEX][MAXVEX];//边信息 
	Vertype vex[MAXVEX]; //顶点信息
	int vexnum; 
	int acrnum;
}AdjMatrix;

AdjMatrix *Create(){     //创建无向图的邻接矩阵 
	AdjMatrix *adj;
	adj = (AdjMatrix *)malloc(sizeof(AdjMatrix));
	
	
	scanf("%d%d",&adj->vexnum,&adj->acrnum);
	int i,j,k;
	getchar();
	for(i=0;i<adj->vexnum;i++){
		scanf("%c",&adj->vex[i]);
	}
	
	for(i=0;i<adj->vexnum;i++)
		for(j=0;j<adj->vexnum;j++)
			adj->acre[i][j]=0;
	
	getchar();
	char a[3];
	for(i=0;i<adj->acrnum;i++){
		gets(a);
		j=0;
		k=0;
		while(adj->vex[j++]!=a[0]);
		while(adj->vex[k++]!=a[1]);
		adj->acre[j-1][k-1]=1;
	}
	return adj;
}
void statistics(AdjMatrix *adj){  //统计出度入度 
	int i,j;
	int countA,countB;
	for(i=0;i<adj->vexnum;i++){
		countA=0;
		countB=0;
		for(j=0;j<adj->acrnum;j++){  
			if(adj->acre[i][j]==1){//出度
				countA++;
			} 
			if(adj->acre[j][i]==1){//入度 
				countB++; 
			}
		} 
		printf("%c %d %d\n",adj->vex[i],countA,countB);
	}
} 
int FirstAdjVex(AdjMatrix *adj,int v){
	int i; 
	
	for(i=0;adj->acre[v][i]!=1&&i<adj->vexnum;i++);
	
	if(i==adj->vexnum)
		return -1;
	else
		return i;
} 
int NextAdhVex(AdjMatrix *adj,int v,int w){
	
	int i; 
	
	for(i=w+1;adj->acre[v][i]!=1&&i<adj->vexnum;i++);
	
	if(i==adj->vexnum)
		return -1;
	else
		return i;
}
int book1[MAXVEX];
void DFS(AdjMatrix *adj,int v){        //广度优先遍历 
	int w;
	printf("%c",adj->vex[v]);
	
	book1[v]=1;
	w=FirstAdjVex(adj,v);
	while(w!=-1){
		if(book1[w]!=1)
			DFS(adj,w);
		w = NextAdhVex(adj,v,w); 
	}	
}

int book2[MAXVEX];
void BFS(AdjMatrix *adj,int v){
	int qeue[50];
	int front=0,rear=0;
	int w;
	
	qeue[rear]=v; //入队 
	rear++;
	book2[v]=1;
	while(rear!=front){
		v=qeue[front];
		if(book2[v]==1){
			printf("%c",adj->vex[v]);
			front++;
		}
			
		w=FirstAdjVex(adj,v);
		while(w!=-1){
			if(book2[w]!=1){
				qeue[rear]=w;
				rear++;
				book2[w]=1;
			}
			w = NextAdhVex(adj,v,w); 
		}
	}
}
int main(void){
	AdjMatrix *adj;
	adj=Create();
	statistics(adj);
	
	DFS(adj,0);
	printf("\n");
	BFS(adj,0);
}