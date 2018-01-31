/*Sample Input
DBACEGF ABCDEFG
BCAD CBAD
Sample Output
ACBFGED
CDAB*/ 

#include<stdio.h>  
#include<string.h>  
#include<stdlib.h>  
  
typedef struct Tree_node  
{  
	struct Tree_node *left;
    char data;  
	struct Tree_node *right;  
}Tree_node;  

Tree_node *root = NULL;
void plant(int n,Tree_node**ptr,char *s1,char *s2)//�]���O���Ъ����D�ҥH�b�I�s�禡�ɻݭn�ǿ��Ӿ𪺫��Ц�} 
{  
    if(n<=0)  				//�p�G�����F 
    {  
        *ptr=NULL;  
        return;  
    }  
    int m=strchr(s2,s1[0])-s2; //�p��s1[0]�bs2���Ĥ@���X�{����m�A�s2�N�O�bs2���ĴX�� 
    Tree_node *temp=(Tree_node*)malloc(sizeof(Tree_node));  
	temp->data=s1[0]; 
	*ptr=temp;  
	plant(m, &temp->left, s1+1, s2);		//������ 
	plant(n-m-1, &temp->right, s1+m+1, s2+m+1);//���k�� 
}  

void postorder(Tree_node *current)
{
	if(current!=NULL)
	{
		postorder(current->left);
		postorder(current->right);
		printf("%c",current->data);
	}
}

int main()  
{  
    char s1[50],s2[50];  
    int len;  
  
    while(scanf("%s%s",s1,s2)!=EOF)  
    {  
        len=strlen(s1);  
        plant(len,&root,s1,s2); 
        postorder(root);  
        printf("\n");  
    }  
    return 0;  
}  
