#include <stdio.h>
#include <stdlib.h>
struct node{
	int x;
	struct node *link;
}*first=NULL,*nn,*temp,*last;
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
		last=nn;
		printf("Wanna Continue y/n\n");
		fflush(stdin);
		ch=getchar();
	}while(ch=='y');
	temp->link=first;
	last=nn;
	return f;
}

void rev(struct node*f){
		struct node *temp1,*temp2,*temp3;
      temp1=f;
      temp2=temp1->link;
      temp3=temp2;
      f->link=NULL;
   
      while(temp1!=NULL){
      	temp3=temp3->link;
      	temp2->link=temp1;
      	temp1=temp2;
      	temp2=temp3;
	  }
}
void display(void){

	temp=first;
	printf("Content in the Linked List is");
	while(temp!=NULL)
{
	printf("%d",temp->x);
	temp=temp->link;
}
}
void rrevdisplay(struct node*f){

	temp=f;
	
	printf("Content in the Reverse Linked List is");
	do
{
	printf("%d",temp->x);
	temp=temp->link;
}while(temp!=NULL);
}
main (){
//	int a;
	first=create(first);
	//display();
	rev(first);
	rrevdisplay(first);
	
}

