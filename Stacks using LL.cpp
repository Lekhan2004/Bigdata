#include<stdio.h>
#include <stdlib.h>
struct node{
	int x;
	struct node *link;
}*top=NULL,*nn,*temp,*f;
void push(int e){
	nn=(struct node*)malloc(sizeof(struct node));
	nn->x=e;
	nn->link=top;
	top=nn;
}
int pop(){
	int e;
	struct node* t;
	t=top;
	e=t->x;
		top=top->link;
		top->link=NULL;
		free(t);
		return e;
}
void display(){
	temp =top;
	while(temp!=NULL){
	printf("%d",temp->x);
	temp=temp->link;
	}
}
main(){
	int choice,ele,ch;
	printf("Select 2 PUSH 3 POP 4 DISPLAY\n");
	do{
		printf("Select Choice\n");
		scanf("%d",&choice);
		switch(choice){
			case 2: printf("Enter Element you want to PUSH\n");
					scanf("%d",&ele);
					push(ele);break;
			case 3: ele=pop();
					printf("%d is popped element\n",ele);break;
			case 4: display();break;
			default:printf("Wromg choice");
			}
			printf("Continue ? 1/0");
			scanf("%d",&ch);
		}while(ch==1);
		
	}

