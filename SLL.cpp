#include <stdio.h>
#include <stdlib.h>
struct node{
	int x;
	struct node *link;
}*first=NULL,*nn,*last,*temp;
struct node* create(struct node *f)
{
	char ch;
	do {
		nn=(y*)malloc(sizeof(y));
		printf("Enter data\n");
		scanf("%d",&nn->x);
		if(f==NULL)
		{f=nn;
		temp=nn;
		}
		else
		{
			temp->link=nn;
			temp=nn;
		}
		printf("Wanna Continue y/n\n");
		fflush(stdin);
		ch=getchar();
	}while(ch=='y');
	temp->link=NULL;
	last=nn;
	return f;
}
void deletebeg(void){
	y *t;
	if(first==NULL)
	printf("LL empty\n");
	else
	{
		t=first;
		first=t->link;
	}
	t->link=NULL;
	free(t);
}
void deleteend(void){
	y *t;
	if(first==NULL)
	printf("LL empty"\n);
	else {
		temp=first;
		while(temp->link->link!=NULL)
		temp=temp->link;
		t=temp->link;
		temp->link=NULL;
		free(t);
	}
}
void deletepos()
{
	int pos,i,c;
	y *t;
	c=count();
	scanf("%d",&pos);
	if(c==0)
	printf("No LL");
	else if(pos==1)
	deletebeg();
	else if(pos==c)
	deleteend();
	else if(pos>c)
	printf("Invalid Position\n");
	else
	{
		i=1;
		temp=first;
		while(i<pos-1)
		{
			temp=temp->link;
			i++;
		}
		t=temp->link;
		temp->link=t->link;
		t->link=NULL;
		free(t);
	}
}
void deleteall(void)
{
	
}













