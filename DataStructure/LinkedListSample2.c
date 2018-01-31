#include <stdio.h>
#include <stdlib.h>

typedef struct Tree_node
{
	struct Tree_node *left;
	int data;
	struct Tree_node *right;
} Tree_node;

Tree_node *root = NULL;
Tree_node *ptr = NULL;

void insert(int num)
{
	Tree_node *temp = (Tree_node*) malloc(sizeof(Tree_node));
	temp-> left = NULL;
	temp-> data = num;
	temp-> right = NULL;
	if(root==NULL)
	{
		root=temp;
		ptr=root; 
	}
	else
	{
		ptr=root;
		while(root!=NULL)
		{
			if(num <= ptr->data)
			{
				if(ptr -> left==NULL)
				{
					ptr->left=temp;
					break;
				}
				else
				{
					ptr=ptr->left;
				}
			}
			else
			{
				if(ptr -> right==NULL)
				{
					ptr->right=temp;
					break;
				}
				else
				{
					ptr=ptr->right;
				}
			}
		}
	}
}
void inorder(Tree_node *current)
{
	if(current==NULL)
	{
		return;
	}
	inorder(current->left);
	printf("%d \n",current->data);
	inorder(current->right);
}

int main()
{
	for(int i=0;i<5;i++)
	{
		printf("insert\t%d\tdata : ",i+1);
		int num;
		scanf("%d",&num);
		insert(num);
	}
	inorder(root);
}

