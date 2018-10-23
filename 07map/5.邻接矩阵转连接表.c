#include<stdio.h>
#include<stdlib.h>
#define MAXVEX 30
//邻接矩阵 
typedef char Vertype;
typedef struct{
	int acre[MAXVEX][MAXVEX];//邻接表
	Vertype Vex[MAXVEX];//顶点信息
	int vexnum;//顶点数量
	int acrenum;//边的数量 
}AdjMatrix;

//邻接表 
typedef struct ArcNode{
	int adhVex;//弧尾 
	struct ArcNode *next; 
}ArcNode;

typedef struct VertexNode{
	Vertype vexdata; //边
	ArcNode *head; 
}VertexNode;

typedef struct{
	VertexNode vertex[MAXVEX];
	int vexnum; // 顶点数
	int arcnum; //边数 
}AdjList;

AdjMatrix *Create(){
	AdjMatrix *adj;
	adj = (AdjMatrix*)malloc(sizeof(AdjMatrix));
	
	printf("请输入图的顶点数和边数:");
	scanf("%d%d",&adj->vexnum,&adj->acrenum);
	
	int i;
	printf("请输入点信息:\n");
	for(i = 0;i < adj->vexnum;i++){
		getchar();
		printf("请输入第%d个顶点:",i+1);
		scanf("%c",&adj->Vex[i]);
	} 

	
	int j,k;
	char a[3];
	for(i=0;i<adj->vexnum;i++) // 初始化 
		for(j=0;j<adj->vexnum;j++)
			adj->acre[i][j]=0;

	getchar();
	printf("\n请输入边信息:如ab\n");
	for(i=0;i<adj->acrenum;i++){
		printf("请输入第%d个边:",i+1);
		gets(a);
		
		j=0;
		k=0;	
		while(adj->Vex[j++] != a[0]&&j<adj->acrenum);
		while(adj->Vex[k++] != a[1]&&k<adj->acrenum);
		adj->acre[j-1][k-1]=1;
	}
	
	printf("\n你输入的邻接矩阵如下:\n");
	for(i=0;i<adj->vexnum;i++){
		for(j=0;j<adj->vexnum;j++){
			printf("%4d",adj->acre[i][j]);
		}
		printf("\n");
	}
	
	return adj;
} 



AdjList *ConvertList(AdjMatrix *adjMatrix){
	AdjList *adjList;
	adjList = (AdjList*)malloc(sizeof(AdjList));
	
	adjList->vexnum = adjMatrix->vexnum;
	adjList->arcnum = adjMatrix->acrenum;
	
	int i,j,flag=0;
	ArcNode *arc,*p;
	for(i=0;i<adjMatrix->vexnum;i++){
		flag=0;
		adjList->vertex[i].vexdata=adjMatrix->Vex[i];
		adjList->vertex[i].head=NULL;
		
		
		for(j=0;j<adjMatrix->vexnum;j++){
			if(adjMatrix->acre[i][j]==1){
				if(flag==0){
					adjList->vertex[i].head=(ArcNode *)malloc(sizeof(ArcNode));
					adjList->vertex[i].head->adhVex=j;
					adjList->vertex[i].head->next=NULL;
					p=adjList->vertex[i].head;
					flag=1;
				}else{
					arc = (ArcNode *)malloc(sizeof(ArcNode));
					arc->adhVex = j;
					arc->next =NULL;
					p->next = arc;
					p=arc;
				}		
			}	
		}
	}


	printf("转换后的邻接表如下:\n");
	for(i=0;i<adjList->vexnum;i++){
		printf("顶点:%c ",adjList->vertex[i].vexdata);
		p = adjList->vertex[i].head;
		
		while(p!=NULL){
			printf("-->%d",p->adhVex);
			p=p->next;	
		}
		printf("\n");
	} 
	return adjList;
} 
int main(void){
	AdjMatrix *adj;
	adj = Create();
	ConvertList(adj);
}


