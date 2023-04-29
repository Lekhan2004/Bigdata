#include<stdio.h>
#include<stdlib.h>
struct node{
	int x;
	struct node *link,*rlink;
}*first=NULL,*temp1,*temp2,*nn,*last,*temp;
struct node* createll(struct node *f){
	char ch;
	do{nn=(struct node*)malloc(sizeof(struct node));
	printf("enter int data:");
	scanf("%d",&nn->x);
	if(f==NULL){f=nn;
		temp=nn;
		temp1=nn;
		temp2=nn;
		temp1->link=NULL;
		temp2->rlink=NULL;
		last=nn;
	}
	else{temp2=nn;
		temp1->rlink=temp2;
		temp2->rlink=NULL;
		temp2->link=temp1;
		temp1=temp2;
		last=nn;
	}printf("do you want to add a node y/n \n");
	fflush(stdin);
	ch=getchar();
}while(ch=='y');
return(f);
}
void insertf(){
	nn=(struct node*)malloc(sizeof(struct node));
	printf("enter int data");
	scanf("%d",&nn->x);
	if(first==NULL){
		first=nn;
		temp=nn;
		temp1=nn;
		temp2=nn;
		temp1->link=NULL;
		temp2->rlink=NULL;
		last=nn;
	}
	else{
		nn->link=NULL;
		nn->rlink=first;
		first->link=nn;
		first=nn;
		temp=nn;
		
	}
}
void insertl(){
	nn=(struct node*)malloc(sizeof(struct node));
	printf("enter int data:");
	scanf("%d",&nn->x);
	if(first==NULL){
		first=nn;
		temp=nn;
		temp1=nn;
		temp2=nn;
		temp1->link=NULL;
		temp2->rlink=NULL;
		last=nn;
	}
	else{
		last->rlink=nn;
		nn->link=last;
		last=nn;
		nn->rlink=NULL;
	}
	
}
int count(){
	int cnt=0;
	if(first==NULL)
	return(cnt);
	else{temp=first;
	while(temp->rlink!=NULL)
	{cnt++;
	temp=temp->rlink;
	}return(cnt);
	}
}
void insertpos(){
	int pos,c,i,j;
	c=count();
	printf("enter position");
	scanf("%d",&pos);
	if(pos==1)
	insertf();
	else if(pos==c+1)
	insertl();
	else if(pos>c+1)
	printf("invalid");
	else{
		nn=(struct node*)malloc(sizeof(struct node));
	printf("enter int data:");
	scanf("%d",&nn->x);
	temp1=first;
	temp2=first;
	i=1,j=1;
	while(i<pos-1)
	{temp1=temp1->rlink;
	i++;
	}
		while(j<pos)
	{temp2=temp2->rlink;
	j++;
	}nn->link=temp1;
	nn->rlink=temp2;
	}
}
void insert(){
	int choice;
	char ch;
	do{printf("1.Insert Front 2.Insert Last 3.Insert Position\n");
	scanf("%d",&choice);
	switch(choice){
		case 1:insertf();break;
		case 2:insertl();break;
		case 3:insertpos();break;
		default:printf("wrong choice");
	}printf("continue y/n\n");
	fflush(stdin);
	ch=getchar();
	}while(ch=='y');
}
void deletebeg(void){
	struct node*t;
	if(first==NULL)
	printf("LL empty\n");
	else
	{
		t=first;
		first=first->rlink;
		first->link=NULL;
		free(t);
	}
}
void deleteend(void){
struct node*t;
	if(first==NULL)
	printf("LL empty \n");
	else {
		temp=first;
		while(temp->rlink->rlink!=NULL)
		temp=temp->rlink;
		t=temp->rlink;
		temp->rlink=NULL;
		free(t);
	}
}
void deletepos()
{
	int pos,i,j,c;
	struct node *t;
	c=count();
	printf("enter position:");
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
		t=temp->rlink;
		temp1=first;
	temp2=first;
	i=1,j=1;
	while(i<pos-1)
	{temp1=temp1->rlink;
	i++;
	}
		while(j<pos)
	{temp2=temp2->rlink;
	j++;
	}temp1->rlink=temp2;
	temp2->link=temp1;
	}
		free(t);
}
void del(){
	int choice;
	char ch;
	do{printf("1.Delete Front 2.Delete Last 3.Delete Position\n");
	scanf("%d",&choice);
	switch(choice){
		case 1:deletebeg();break;
		case 2:deleteend();break;
		case 3:deletepos();break;
		default:printf("wrong choice");
	}printf("continue deletion y/n\n");
	fflush(stdin);
	ch=getchar();
	}while(ch=='y');
}
void display(struct node*f)
{if(f==NULL)
printf("empty");
else{printf("content of linked list is\n");
      temp=f;
      while(temp!=NULL)
      {printf("\n%d",temp->x);
       temp=temp->rlink;
      }
    }   
}
int search(void)
{
	int ele,flag;
	printf("enter element to search\n");
	scanf("%d",&ele);
	if(first==NULL)
	return(0);
	else{
		temp=first;
		flag=1;
		while(temp!=NULL){
			if(ele==temp->x){
				flag=2;
				break;
			}temp=temp->rlink;
		}return(flag);
	}
}
int main(){
	int choice,f;
	char ch='y';
	while(ch=='y'){printf("select\n 1.Create 2.Insert 3.Delete 4.Search 5.Display\n");
	scanf("%d",&choice);
	switch(choice){
		case 1:first=createll(first);break;
		case 2:insert();break;
		case 3:del();break;
		case 4:f=search();
					 if(f==0)
					 printf("empty");
					 else if(f==1)
					 printf("element not found");
					 else
					 printf("element found");
					 break;
		case 5:display(first);break;
default:printf("wrong choice");
	}printf("\ncontinue y/n:");
	fflush(stdin);
	ch=getchar();
	}
}
