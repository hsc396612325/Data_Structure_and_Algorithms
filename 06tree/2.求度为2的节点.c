#include <stdio.h>
typedef int Elemtype;
typedef struct Node{
	Elemtype data;
	struct Node *lChild;
	struct Node *rChild;
}BiTNode,*BiTree;

char str[]="ABC^D^^E^^FCK^^^H^M^^";
BiTree CreatBiTree(BiTree root){  //二叉树的建立(由扩展的先序序列建立的二叉树) 
	static int count;
	char ch=str[count];
	count++;
	if(ch=='^')
		return NULL;
		
	root = (BiTNode *)malloc(sizeof(BiTNode));
	root->data = ch;
	root->lChild = CreatBiTree(root->lChild);//以当前节点的左指针为下一级二叉树的跟 
	root->rChild = CreatBiTree(root->rChild);//以当前节点的右指针为下一级二叉树的跟	
	return root;
}
int CountTwoOrder(BiTree root){  //寻找度为2的节点 
	int static count;
	if(root==NULL)
		return;
	if(root->lChild!=NULL&&root->rChild!=NULL)
		count++;	
	printf("%c",root->data);
	CountTwoOrder(root->lChild);
	CountTwoOrder(root->rChild);
	return count;
}
void exchange(BiTree root){     //交换各节点的左右子树 
	BiTree t;
	if(root==NULL)
		return;
	t=root->lChild;
	root->lChild=root->rChild;
	root->rChild=t;
	exchange(root->lChild);
	exchange(root->rChild);
}
void PreOrder(BiTree root){    //先序遍历输出加层次 
	int static count;
	if(root==NULL)
		return;
	count++;	
	printf("(%c,%d)",root->data,count);
	PreOrder(root->lChild);
	PreOrder(root->rChild);
	count--;
}
int main(void){
	BiTree root;
	root=CreatBiTree(root);
	printf("\n度为2的节点有：%d\n",CountTwoOrder(root));
	exchange(root);
	PreOrder(root);
	printf("\n"); 
}