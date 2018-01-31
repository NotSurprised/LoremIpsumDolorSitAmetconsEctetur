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
void plant(int n,Tree_node**ptr,char *s1,char *s2)//因為是指標的問題所以在呼叫函式時需要傳輸整個樹的指標位址 
{  
    if(n<=0)  				//如果做完了 
    {  
        *ptr=NULL;  
        return;  
    }  
    int m=strchr(s2,s1[0])-s2; //計算s1[0]在s2中第一次出現的位置，減掉s2就是在s2的第幾個 
    Tree_node *temp=(Tree_node*)malloc(sizeof(Tree_node));  
	temp->data=s1[0]; 
	*ptr=temp;  
	plant(m, &temp->left, s1+1, s2);		//做左邊 
	plant(n-m-1, &temp->right, s1+m+1, s2+m+1);//做右邊 
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
