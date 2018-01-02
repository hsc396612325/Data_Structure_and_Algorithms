#include<stdio.h>
#include<stdlib.h>
#define MAXVEX 30
typedef char Vertype;
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

typedef struct{
	int acre[MAXVEX][MAXVEX];//邻接表
	Vertype Vex[MAXVEX];//顶点信息
	int vexnum;//顶点数量
	int acrenum;//边的数量 
}AdjMatrix;
AdjList *Create(){
	AdjList *adj;
	
	adj = (AdjList *)malloc(sizeof(AdjList)); 
	printf("请输入图的顶点的数量和边的数量:");
	scanf("%d%d",&adj->vexnum,&adj->arcnum);
	int i;
	printf("请输入点信息:\n");
	for(i = 0;i < adj->vexnum;i++){
		getchar();
		printf("请输入第%d个顶点:",i+1);
		scanf("%c",&adj->vertex[i].vexdata);
		adj->vertex[i].head = NULL;
	} 
	
	
	getchar();
	int j,k;
	char a[3];
	ArcNode *arc;
	ArcNode *p;
	printf("\n请输入边信息如ab:\n");
	for(i=0;i<adj->arcnum;i++){
		printf("请输入第%d个边:",i+1);
		gets(a);                                                                                                                                                                                                                                  
		j=0;
		k=0;	
		while(adj->vertex[j].vexdata != a[0] &&j++<adj->vexnum);
		
		while(adj->vertex[k].vexdata != a[1] &&k++<adj->vexnum);
		
		arc = (ArcNode *)malloc(sizeof(ArcNode));
	 	
		arc->adhVex = k;
		arc->next = adj->vertex[j].head;
		adj->vertex[j].head = arc; 
	}
	
	printf("\n你输入的邻接表如下:\n");
	for(i=0;i<adj->vexnum;i++){
		printf("顶点:%c ",adj->vertex[i].vexdata);
		p = adj->vertex[i].head;
		
		while(p!=NULL){
			printf("-->%d",p->adhVex);
			p=p->next;	
		}
		printf("\n");
	} 
 	return adj;
}
AdjMatrix *ConvertMatrix(AdjList *adjList){
	
	AdjMatrix *adjMatrix;
	adjMatrix = (AdjMatrix *)malloc(sizeof(AdjMatrix));
	
	adjMatrix->vexnum = adjList->vexnum;
	adjMatrix->acrenum = adjList->arcnum;
	 
	int  i,j;
	ArcNode *q;
	for(i=0;i<adjMatrix->vexnum;i++) // 初始化 
		for(j=0;j<adjMatrix->vexnum;j++)
			adjMatrix->acre[i][j]=0;
			
	for(i=0;i<adjList->vexnum;i++){
		
		adjMatrix->Vex[i]= adjList->vertex[i].vexdata;	
		q=adjList->vertex[i].head;
		while(q!=NULL){
			adjMatrix->acre[i][q->adhVex]=1;
			q=q->next;
		}
	} 
	
	printf("\n转换后的邻接矩阵如下:\n");
	for(i=0;i<adjMatrix->vexnum;i++){
		for(j=0;j<adjMatrix->vexnum;j++){
			printf("%4d",adjMatrix->acre[i][j]);
		}
		printf("\n");
	}
} 
int main(void){
	AdjList *adj;
	adj = Create();
	printf("\n");
	ConvertMatrix(adj);
} 