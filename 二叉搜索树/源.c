#include<stdio.h>
#include<stdlib.h>


typedef int E;


typedef struct tree//�� 
{
	E element;
	struct tree* left;
	struct tree* right;
}treenode;


treenode* createTnode(E element)//�����ڵ�
{
	treenode*  Node= malloc(sizeof(treenode));
	Node->element = element;
	Node->left = Node->right = NULL;
	return Node;
}


treenode* insert(treenode* root, E element)//����
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
		root = createTnode(element);//�����ݹ�
	}
	return root;
}


void inOrder(treenode* root)//��
{
	if (!root)return;
	inOrder(root->left);
	printf("%d ", root->element);
	inOrder(root->right);
}


treenode* Find(treenode* root,E element)//�ҽڵ�
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


treenode* Findmax(treenode* root)//�����
{
	if (!root)return 0;
	if (root->right != NULL)
		return Findmax(root->right);
	if (root->right == NULL)
		return root;
}


treenode* delete(treenode* root, E target)//�ҵ��˲����������
{
	root = Find(root, target);//û�ҵ��Ĳ��ù�
	if (root == NULL)return 0;
	if (root->right && root->left)
	{
		root->element = Findmax(root->left)->element;
		root->left=delete(root->left, root->element);//����,����
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
