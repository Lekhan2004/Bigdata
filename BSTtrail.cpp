#include <stdio.h>
#include<stdlib.h>
#include<math.h>
struct node{
	int x;
	struct node *r,*l;
}*root=NULL,*nn,*ptr,*tmp;
int max(int a,int b){
	if(a>b)return a;
	else return b;
}
struct node *newnode(int ele)
{
	struct node *t;
    t=(struct node*)malloc(sizeof(struct node));
    t->x=ele;
	t->l=NULL;
	t->r=NULL;
	return t;
}
int height(struct node *f){
	if(f==NULL)
	return 0;
	return max(height(f->l),height(f->r))+1;
}
struct node *insucc(struct node *f) {
    while (f->l != NULL)
        f = f->l;
    return f;
}

struct node *del(struct node *f, int ele) {
    if (f == NULL) return f;

    if (ele < f->x)
        f->l = del(f->l, ele);
    else if (ele > f->x)
        f->r = del(f->r, ele);
    else {
        if (f->l == NULL) {
            struct node *tmp = f->r;
            free(f);
            return tmp;
        } else if (f->r == NULL) {
            struct node *tmp = f->l;
            free(f);
            return tmp;
        }
        struct node *tmp = insucc(f->r);
        f->x = tmp->x;
        f->r = del(f->r, tmp->x);
    }
    return f;
}

	 
struct node *insert(struct node *f,int ele)//Recursive
   { 
	if(f==NULL){
		return newnode(ele);}
	if(ele<f->x)
	f->l=insert(f->l,ele);
	else if(ele >f->x)
	f->r=insert(f->r,ele);
	return f;	
}
/*struct node* insert(struct node *f,int ele)//Non Recursive
{
	nn=(struct node*)malloc(sizeof(struct node));
	if(f==NULL){
		f=nn;
		nn->x=ele;
		nn->l=NULL;
		nn->r=NULL;
	}
	else{
		ptr=f;
		if(ele==ptr->x)
		printf("Duplicate\n");
		else if(ele<ptr->x)
		{
			while(ptr->l!=NULL){
				if(ele<ptr->x)
					ptr=ptr->l;
				else
					break;
			}
			if(ele<ptr->x)
			ptr->l=nn;
			else ptr->r=nn;
			nn->x=ele;
		    nn->l=NULL;
			nn->r=NULL;
		}
		else {
			while(ptr->r!=NULL){
				if(ele>ptr->x)
					ptr=ptr->r;
				else
					break; 
			}
			if(ele<ptr->x)
			ptr->l=nn;
			else ptr->r=nn;
			nn->x=ele;
		    nn->l=NULL;
			nn->r=NULL;	
		}
	}
    return f;
}*/
/*struct node* search(struct node* f, int ele)
{
    if (f == NULL || f->x == ele)
        return f;
    if (f->x< ele)
        return search(f->r, ele);
    return search(f->l, ele);
}*/
struct node* search(struct node* f, int ele)
{
	if(f==NULL)
	return f;
	if(ele<f->x)
		f=search(f->l,ele);
	else if(ele>f->x)
	f=search(f->r,ele);
	else 
	return f;
}
void inorder(struct node *root)
{
	if(root==NULL)return;
	inorder(root->l);
	printf("%d  ",root->x);
	inorder(root->r);
	
}
void preorder(struct node *root)
{
	if(root==NULL)return;
	printf("%d  ",root->x);
	preorder(root->l);
	preorder(root->r);
	
}void postorder(struct node *root)
{
	if(root==NULL)return;
	postorder(root->l);
	postorder(root->r);
	printf("%d  ",root->x);
	
}
int main(){
	int choice,ele,ht;
	do{
		printf("\n1.Insert\n2.Delete\n3.Inorder\n4.Preorder\n5.Postorder\n6.Search\n7.Height\n10.Exit\n ");
		scanf("%d",&choice);
		switch(choice){
			case 1:printf("Enter the node you want to insert\n");
				   scanf("%d",&ele);
				   root=insert(root,ele);
				   break;
			case 2:printf("Enter the node you want to delete\n");
				   scanf("%d",&ele);
				   root=del(root,ele);
				   break; 
			case 3:printf("Inorder Traversal of the above tree is:\n");
				   inorder(root);
				   break;
			case 4:printf("Preorder Traversal of the above tree is:\n");
				   preorder(root);
				   break;
			case 5:printf("Postorder Traversal of the above tree is:\n");
				   postorder(root);
				   break;
			case 6:printf("Enter the element you want to search\n");
				   scanf("%d",&ele);
				   tmp=search(root,ele);
				   if(tmp==NULL)printf("Not Found\n");
				   else printf("Found\n");
				   break;
			case 7:ht=height(root);
			printf("\nHeight of the tree is %d",ht);break;
				}
				}while(choice!=10);
	
	return 0;
}
