#include <stdio.h>
#include<stdlib.h>
struct node{
	int x,h;
	struct node *l,*r;
}*root=NULL,*nn,*tmp;
int height(struct node *f){
	/*if(f==NULL)
	return 0;
	return f->h;*/
	 int lh, rh;
    if (f == NULL)
    {
        return 0;
    }
    if (f->l == NULL)
        lh = 0;
    else
        lh = 1 + f->l->h;
    if (f->r == NULL)
        rh = 0;
    else
        rh = 1 + f->r->h;
 
    if (lh > rh)
        return (lh);
    return (rh);
}
int max(int a,int b){
	if(a>b)return a;
	else return b;
}
/*int height(struct node *f){
	if(f==NULL)
	return 0;
	return max(height(f->l),height(f->r))+1;
}*/
int balancefactor(struct node *root){
	/*if(f==NULL)return 0;
	return (height(f->l)-height(f->r));*/
	int lh, rh;
    if (root == NULL)
        return 0;
    if (root->l == NULL)
        lh = 0;
    else
        lh = 1 + root->l->h;
    if (root->r == NULL)
        rh = 0;
    else
        rh = 1 + root->r->h;
    return lh - rh;
}
struct node*leftrotate(struct node*a){ //Turns to Right
	struct node *b=a->l;
	a->l=b->r;
	b->r=a;
	a->h=height(a);
	b->h=height(b);
	return a;
}

struct node*rightrotate(struct node*b){ // Turns to Left
	struct node* a=b->r;
	b->r=a->l;
	a->l=b;
	/*a->h=max(height(a->l),height(a->r))+1;
	b->h=max(height(b->l),height(b->r))+1;*/
		a->h=height(a);
	b->h=height(b);
	return b;
}
struct node*createnode(int ele) // Creates a node of type struct node and updates the left and right link as NULL and inserts data 
{ 
	struct node*nn=(struct node*)malloc(sizeof(struct node));
	nn->x=ele;
	nn->r=NULL;
	nn->l=NULL;
	return nn;	
}
struct node*insert(struct node*f,int ele) { //Function to insert data into Tree
	//int bf=balancefactor(f);	
	if(f==NULL)
	return createnode(ele);
	if(ele<f->x)
	{
			f->l=insert(f->l,ele);
			//LL CASE
		if(balancefactor(f)>1 )
		{
			if(ele < f->l->x)
				f=leftrotate(f);
			//LR CASE 
		    else
		     {
			f->l=rightrotate(f->l);
			f=leftrotate(f);
		     }
		}
	}
	else
		{
		f->r=insert(f->r,ele);
		if(balancefactor(f)<-1){ 
		//RR CASE 
		if(ele>f->r->x)
			f=rightrotate(f);
		//RL CASE
	    else
		{
			f->r=leftrotate(f->r);
			f=rightrotate(f);
		}
	}}
		f->h=height(f);
		//	f->h=max(height(f->r),height(f->l));
		return f;
}
struct node*del(struct node *f,int ele){
	struct node *tmp;
	if(f==NULL)
	return NULL;
	if(ele>f->x)
	{
		f->r=del(f->r,ele);
		if(balancefactor(f)==2){
		    if(balancefactor(f->l)>=0)	
		    	f=leftrotate(f);
		    else 
		    {
		    	f->l=rightrotate(f->l);
		    	f=leftrotate(f);
			}
			
			}
	}
	else if(ele<f->x){
		f->l=del(f->l,ele);
		if(balancefactor(f)==-2){
		    if(balancefactor(f->r)<=0)	
		    	f=rightrotate(f);
		    else 
		    {
		    	f->r=leftrotate(f->r);
		    	f=rightrotate(f);
			}
			}
	}
	else {
		 if (f->r != NULL)
        { 
            tmp = f->r;
            while(tmp->l != NULL)
                tmp = tmp->l;
 
            f->x = tmp->x;
            f->r = del(f->r, tmp->x);
            if (balancefactor(f) == 2)
            {
                if (balancefactor(f->l) >= 0)
                {
                    f = leftrotate(f);
                }
                else
                {
                    f->l = rightrotate(f->l);
                    f = leftrotate(f);
                }
            }
        }
        else
        {
            return (f->l);
        }
    }
f->h = height(f);
    return (f);
}
void inorder(struct node *f)
{
	if(f==NULL)return;
	inorder(f->l);
	printf("%d  ",f->x);
	inorder(f->r);
	
}
void preorder(struct node *f)
{
	if(f==NULL)return;
	printf("%d  ",f->x);
	preorder(f->l);
	preorder(f->r);
	
}
void postorder(struct node *r)
{
	if(r==NULL)return;
	postorder(r->l);
	postorder(r->r);
	printf("%d  ",r->x);	
}

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
int main(){

	int choice,ele,ht;
	do{
		printf("\n1.Insert\n2.Delete\n3.Inorder\n4.Preorder\n5.Postorder\n6.Search\n10.Exit\n ");
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
			case 6:printf("Enter the node you want to search?");
				   scanf("%d",&ele);
				   tmp=search(root,ele);
				   if(tmp==NULL)printf("Not Found\n");
				   else printf("Found\n");
				   break;
			case 7:ht=height(root);
			printf("\nHeight of the tree is %d\n",ht);break;
				}
				}while(choice!=10);
	return 0;
}
