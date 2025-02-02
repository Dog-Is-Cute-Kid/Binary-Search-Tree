# Binary-Search-Tree
#include<stdio.h>
#include<stdlib.h>


typedef int E;


typedef struct tree//树 
{
	E element;
	struct tree* left;
	struct tree* right;
}treenode;


treenode* createTnode(E element)//创建节点
{
	treenode*  Node= malloc(sizeof(treenode));
	Node->element = element;
	Node->left = Node->right = NULL;
	return Node;
}


treenode* insert(treenode* root, E element)//插入
{
	if (root)
	{
		if (element < root->element)
		{
			root->left=insert(root->left, element);
		}
		if (element > root->element)
		{
			root->right=insert(root->right, element);
		}
	}
	else
	{
		root = createTnode(element);//结束递归
	}
	return root;
}


void inOrder(treenode* root)//中
{
	if (!root)return;
	inOrder(root->left);
	printf("%d ", root->element);
	inOrder(root->right);
}


treenode* Find(treenode* root,E element)//找节点
{
	if (!root)return 0;
	if (element < root->element)
		return Find(root->left, element);
	else if (element > root->element)
		return Find(root->right, element);
	else 
		return root;
	return 0;
}


treenode* Findmax(treenode* root)//找最大
{
	if (!root)return 0;
	if (root->right != NULL)
		return Findmax(root->right);
	if (root->right == NULL)
		return root;
}


treenode* delete(treenode* root, E target)//找到了才有三种情况
{
	root = Find(root, target);//没找到的不用管
	if (root == NULL)return 0;
	if (root->right && root->left)
	{
		root->element = Findmax(root->left)->element;
		root->left=delete(root->left, root->element);//更新,接上
	}
	else
	{
		treenode* tmp=root;
		if (root->right)
		{
			root = root->right;
		}
		else
		{
			root = root->left;
		}
		free(tmp);
	}
	return root;
}


	

int main()
{
	treenode* root=insert(NULL, 18);
	insert(root, 12);
	insert(root, 1);
	insert(root, 16);
	insert(root, 20);

	
	delete(root, 12);
	inOrder(root);
	return 0;
}
