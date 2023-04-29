#include<stdio.h>
#include<stdlib.h>
struct node
{
	int x;
	struct node *link;
}*first=NULL,*temp,*nn,*last;
struct node* create(struct node *f)
{
	char ch;
	do
	{
		nn=(struct node*)malloc(sizeof(struct node));
		printf("Enter in data\n");
		scanf("%d",&nn->x);
		if(f==NULL)
		{
			f=nn;
			temp=nn;
		}
		else
		{
			temp->link=nn;
			temp=nn;
		}
		printf("continue on create y/n\n");
		fflush(stdin);
		ch=getchar();
	}while(ch=='y');
	temp->link=f;
	last=nn;
	return(f);
}
void insertbeg(void)
{
	nn=(struct node*)malloc(sizeof(struct node));
	printf("Enter data");
	scanf("%d",&nn->x);
	if(first==NULL)
	{
		first=nn;
		nn->link=first;
	}
	else
	{
		nn->link=first;
		first=nn;
		last->link=first;
	}
}
void insertend(void)
{
	nn=(struct node*)malloc(sizeof(struct node));
	printf("Enter data");
	scanf("%d",&nn->x);
	if(first==NULL)
	{
	  first=nn;
	  nn->link=first;
      last=nn;
    }
	else
	{
	  last->link=nn;
	  nn->link=first;
	  last=nn;
   }
}
int count(void)
{
	int cnt=1;
	if(first==NULL)
	return(cnt);
	else
	{
		temp=first;
		while(temp->link!=first)
		{
			cnt++;
			temp=temp->link;
		}
		return(cnt);
	}
}

void insertpos(void)
{
	int pos,c,i;
	c=count();
	printf("Enter position");
	scanf("%d",&pos);
	if(pos==1)
	insertbeg();
	else if(pos==c+1)
	insertend();
	else if(pos>c+1)
	printf("wrong choice");
	else
	{
		nn=(struct node*)malloc(sizeof(struct node));
		printf("Enter data");
		scanf("%d",&nn->x);
		temp=first;
		i=1;
		while(i<pos-1)
		{
			temp=temp->link;
			i++;
		}
		nn->link=temp->link;
		temp->link=nn;
	}
}
void insert(void)
{
	int choice;
	char ch;
	do
	{
		printf("1:insertbeg 2:inserend 3:insertpos\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:insertbeg();
			       break;
			case 2:insertend();
			       break;
			case 3:insertpos();
			       break;
			default:printf("wrong choice");
		}
		printf("continue on inserty/n");
		fflush(stdin);
		ch=getchar();
	}while(ch=='y');
}

void delebeg(void)
{
	struct node *t;
	if(first==NULL)
	printf("cll is empty");
	else
	{
		t=first;
		first=first->link;
		t->link=NULL;
		free(t);
		last->link=first;
	}
}
void deleend(void)
{
	struct node *t;
	if(first==NULL)
	printf("cll is empty");
	else
	{
		temp=first;
		while(temp->link->link!=first)
		temp=temp->link;
		t=temp->link;
		temp->link=first;
		free(t);
	}
}
void delepos(void)
{
	struct node *t;
	int i,c,pos;
	c=count();
	scanf("%d",&pos);
	if(c==0)
	printf("cll is empty");
	else if(pos==1)
	delebeg();
	else if(pos==c)
	deleend();
	else if(pos>c)
	printf("Invalid position");
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
void dele(void)
{
	int choice;
	char ch;
	do
	{
		printf("1:deletebeg 2:deleteend 3:deletepos");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:delebeg();
			       break;
			case 2:deleend();
			       break;
			case 3:delepos();
			       break;
			default:printf("wrong choice");
		}
		printf("continue on delete y/n");
		fflush(stdin);
		ch=getchar();
	}while(ch=='y');
}

int search(void)
{
	int ele,flag;
	printf("Enter element to search");
	scanf("%d",&ele);
	if(first==NULL)
	return(0);
	else
	{
		temp=first;
		flag=1;
		do
		{
			if(ele==temp->x)
			{
				flag=2;
				break;
			}
			temp=temp->link;
		}while(temp!=first);
	}
	return(flag);
}

void display(struct node *f)
{
	if(f==NULL)
	printf("sll is empty");
	else
	{
		printf("content of sll is\n");
		temp=f;
		do
		{
			printf("%d ",temp->x);
			temp=temp->link;
		}while(temp!=f);
	}
}
int main()
{
	int choice,f;
	char ch;
	
	do
	{
		printf("1:create 2:insert 3:delete 4:search 5:display\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:first=create(first);
			       break;
			case 2:insert();
			       break;
			case 3:dele();
			       break;
			case 4:f=
			search();
			       if(f==0)
			       printf("cll empty");
			       else if(f==1)
			       printf("element not found");
			       else
			       printf("element found");
			       break;
			case 5:display(first);
			       break;
			default:printf("wrong choice");
		}
		printf("continue on main y/n");
		fflush(stdin);
		ch=getchar();
	}while(ch=='y');
	return(0);
}
