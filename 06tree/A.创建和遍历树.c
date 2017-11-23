#include <stdio.h>
typedef char Elemtype;
typedef struct Node{
	Elemtype data;
	struct Node *lChild;
	struct Node *rChild;
}BiTNode,*BiTree;

char str[50];

BiTree CreatBiTree(BiTree root);//二叉树的建立
void PreOrder(BiTree root);//前序遍历
void InOrder(BiTree root);//中序遍历
void PostOrder(BiTree root);//后序遍历
 
BiTree CreatBiTree(BiTree root){
	static int count;
	char ch=str[count];
	count++;
	if(ch=='#')
		return NULL;
		
	root = (BiTNode *)malloc(sizeof(BiTNode));
	root->data = ch;
	root->lChild = CreatBiTree(root->lChild);//以当前节点的左指针为下一级二叉树的跟 
	root->rChild = CreatBiTree(root->rChild);//以当前节点的右指针为下一级二叉树的跟	
	return root;
}

void PreOrder(BiTree root){
	int static count;
	if(root==NULL)
		return;
		
	printf("%c",root->data);
	PreOrder(root->lChild);
	PreOrder(root->rChild);
}
void InOrder(BiTree root){
	if(root==NULL)
		return;
		
	InOrder(root->lChild);
	printf("%c",root->data);
	InOrder(root->rChild);
}
void PostOrder(BiTree root){
	if(root==NULL)
		return;
		
	PostOrder(root->lChild);
	PostOrder(root->rChild);
	printf("%c",root->data);
}

void InOrder2(BiTree root){
	if(root==NULL)
		return;
	if(root->lChild==NULL&&root->rChild==NULL)
		printf("%c",root->data); 
	InOrder2(root->lChild);
	InOrder2(root->rChild);
} 

int Depth(BiTree root){
	int static count;
	int dep;
	if(root==NULL)
		return 0;
	dep=Depth(root->lChild)>Depth(root->rChild)?Depth(root->lChild)+1:Depth(root->rChild)+1;
	return dep;
} 
int main(void){
	BiTree root;
	gets(str);
	root=CreatBiTree(root);
	//printf("前序遍历：");
	PreOrder(root); 
	printf("\n");
	//printf("\n中序遍历：");
	InOrder(root);
	printf("\n");
	//printf("\n先序遍历: ");
	PostOrder(root); 
	printf("\n");
}