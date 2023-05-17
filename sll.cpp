#include <stdio.h>
#include <stdlib.h>
struct node{
	int x;
	struct node *link;
}*first=NULL,*nn,*temp;
struct node* create(struct node *f)
{
	char ch;
	do{
	 	nn=(struct node*)malloc(sizeof(struct node));
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
	temp->link=first;
	//last=nn;
	return f;
}
int count(){
	int cnt=0;
	temp=first;
	if(first==NULL)
	return cnt;
	else{
	while(temp->link!=first){
		temp=temp->link;
		cnt++;
	}
	return cnt;
}}
void deletebeg(void){
	struct node *t;
	if(first==NULL)
	printf("LL emptstruct node\n");
	else
	{
		t=first;
		first=t->link;
	}
	//t->link=NULL;
	
	free(t);
}
void deleteend(void){
	struct node *t;
	if(first==NULL)
	printf("LL empty");
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
	struct node *t;
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
	int choice;
	char ch;
	do{
		printf("Select ");
		scanf("%d",&choice);
		switch(choice){
			printf("Enter how to delete");
			case 1:deletebeg();break;
			case 2:deleteend();break;
			case 3:deletepos();break;
			default : printf("Wrong Choice");
		}printf("Continue? y/n");
		fflush(stdin);
		--------ch=getchar();
	}while(ch=='y');
}
void insertbeg(){
	nn=(struct node*)malloc(sizeof(struct node));
	printf("Enter data");
	scanf("%d",&nn->x);
	if(first==NULL)
	{
		first=nn;
		nn->link=NULL;
	}else{
	nn->link=first;
	first=nn;
	}
}
void insertend(){
	nn=(struct node*)malloc(sizeof(struct node));
	printf("Enter data");
	scanf("%d",&nn->x);
	if(first==NULL)
	{
		first=nn;
		nn->link=NULL;
	}
	else{temp=first;
	while(temp->link!=NULL){
		temp=temp->link;
	}
	nn->link=NULL;
	temp->link=nn;
	}
}
void insertpos(){
	int i,pos,c;
	printf("Enter the position you want to insert");
	scanf("%d",&pos);
	c=count();
	if(pos==1)insertbeg();
	else if(pos==c+1)
	insertend();
	else if(pos>c+1)
	printf("Invalid");
	else{
		nn=(struct node*)malloc(sizeof(struct node));
	printf("Enter data");
	scanf("%d",&nn->x);
	temp=first;i=1;
	while(i<pos-1){temp=temp->link;
	i++;
	}
	nn->link=temp->link;
	temp->link=nn;
	}
}
int search(void){
	int ele,flag;
	if(first == NULL)
	return 0;
	else{
		temp=first;
		flag=0;
		while(temp!=NULL)
		{
			if(temp->x==ele){
				flag=2;break;
			}
			temp=temp->link;
		}
	}
}
void display(){
	if(first==NULL)printf("SLL is empoty");
	else{
		printf("The content in the LL is\n");
		temp=first;
		while(temp!=NULL){
			printf("%d",temp->x);
			temp=temp->link;
		}
	}
}
void insertall(void)
{
	int choice;
	char ch;
	do{
		printf("Select ");
		scanf("%d",&choice);
		switch(choice){
			printf("Select How to insert");
			case 1:insertbeg();break;
			case 2:insertend();break;
			case 3:insertpos();break;
			default : printf("Wrong Choice");
		}printf("Continue? y/n");
		fflush(stdin);
		ch=getchar();
	}while(ch=='y');
}
main(){
	int choice ,f;
	char ch;
	printf("Select 1 Create 2 Insert 3 Delete 4 Display");
	do{
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:first =create(first);break;
			case 2:insertall();break;
			case 3:deleteall();break;
			case 4:display();break;
			default:printf("Wrong");
		}
		printf("Cont y/n");
		fflush(stdin);
		ch=getchar();
	}while(ch=='y');
	}


