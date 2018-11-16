#include<stdio.h>
#include<stdlib.h>

struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
}*root = NULL ,*node = NULL,*temp = NULL;

struct tree *insert(int,struct tree*);
struct tree *delet(struct tree*,int);
struct tree *search(int,struct tree*);
struct tree *minvalue(struct tree*);
struct tree *maxvalue(struct tree*);
void preorder(struct tree*);
void inorder(struct tree*);
void postorder(struct tree*);

int main()
{
	int ch,key;
	while(ch!=9)
	{
		printf("\t------Enter your choice-------\n");
		printf("1.) Insert \n2.) Delete \n3.) Preorder display\n 4.) inorder display\n 5.) postorder display \n6.) Search \n7.) Min value \n8.) Max value \n9.)Exit");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter value to insert : ");
				scanf("%d",&key);
				root = insert(key,root);
				break;
			
			case 2:
				printf("Enter value to delete : ");
				scanf("%d",&key);
				delet(root,key);
				break;
			
			case 3:
				printf("Preorder traversal of tree is : ");
				preorder(root);
				break;
				
			case 4:
				printf("inorder traversal of tree is : ");
				inorder(root);
				break;
				
			case 5:
				printf("postorder traversal of tree is : ");
				postorder(root);
				break;
				
			case 6:
				printf("enter the value to be searched : ");
				scanf("%d",&key);
				search(key,root);
				break;
				
			case 7:
				if(minvalue(root)==NULL)
					printf("Tree is empty");
				else
					printf("minimum value is %d",minvalue(root)->data);
				break;
				
			case 8:
				if(maxvalue(root)==root)
					printf("Tree is empty");
				else
					printf("maximum value is %d",maxvalue(root)->data);
				break;
				
			case 9:
				exit(0);
				break;
			default:
				printf("invalid choisce s empty ");
		}
	}
	return 0;
}

struct tree *insert(int key,struct tree *leaf)
{
	if(leaf == NULL)
	{
		struct tree *temp;
		temp = (struct tree*)malloc(sizeof(struct tree));
		temp->data=key;
		temp->left=0;
		temp->right=0;
		printf("data is inserted succesfully");
		return temp;
	}
	
	else
	{
		if(key < leaf->data)
		{
			leaf->left=insert(key,leaf->left);
		}
		else
		{
			leaf->right=insert(key,leaf->right);
		}
		return leaf;
	}
}
	struct tree *search(int key,struct tree *leaf)
	{
		if(leaf != NULL)
		{
			if(key == leaf->data)
			{
				printf("element is found");
				return leaf;
			}
			else
			{
				if(key < leaf->data)
				{
					return search(key,leaf->left);
				}
				else
				{
					return search(key,leaf->right);
				}
			}
		
		}
		else
		{
			printf("the data is not found ");
			return NULL;
		}
	}

struct tree *minvalue(struct tree *leaf)
{
	if(leaf == NULL)
	{
		return NULL;
	}
	if(leaf->left)
	{
		return minvalue(leaf->left);
	}
	else
	{
		return leaf;
	}
}

struct tree *maxvalue(struct tree *leaf)
{
	if(leaf==NULL)
	{
		return NULL;
	}
	if(leaf->right)
	{
		return maxvalue(leaf->right);
	}
	else
	{
		return leaf;
	}
}

void preorder(struct tree *leaf)
{
	if(leaf==NULL)
	{
		return;
	}
	printf("data is : %d\n",leaf->data);
	preorder(leaf->left);
	preorder(leaf->right);
}

void inorder(struct tree *leaf)
{
	if(leaf==NULL)
	{
		return;
	}
	preorder(leaf->left);
	printf("data is : %d\n",leaf->data);
	preorder(leaf->right);
}

void postorder(struct tree *leaf)
{
	if(leaf==NULL)
	{
		return;
	}
	preorder(leaf->left);
	preorder(leaf->right);
	printf("data is %d\n",leaf->data);
}


struct tree* delet(struct tree *leaf ,int key)
 {
	if(leaf == NULL)
		printf("Element Not Found!\n");
	else if(key < leaf->data)
		leaf->left = delet(leaf->left, key);
	else if(key > leaf->data)
		leaf->right = delet(leaf->right, key);
	else 
	{
		if(leaf->right && leaf->left) 
		{

			/* Replace with minimum element in the right sub tree */
			temp = minvalue(leaf->right);
			leaf->data = temp->data;

			/* Delete that node */
			leaf->right = delet(leaf->right,temp->data);
		}	
		else
		 {
			/* If there is only one or zero children then directly remove it from the tree and connect its parent to its child */
			temp = leaf;
			if(leaf->left == NULL) 
				leaf = leaf->right;
			else if(leaf->right == NULL)
				leaf = leaf->left;
			free(temp);
			printf("Data delete successfully!\n");
		}
	}									
}

