#include <stdio.h>
#include <stdlib.h>
struct node{
	int x;
	struct node *link,*rlink;
}*f=NULL,*nn,*r=NULL;
void enque(int ele){
	nn=(struct node*)malloc(sizeof(struct node));
		printf("Enter data\n");
		scanf("%d",&nn->x);
		if(f==NULL && r==NULL)
		{
			f=nn;
			r=nn;
			r->link=NULL;
				r->rlink=NULL;
		}
		else{
			r->rlink=nn;
			t=r;
			r=nn;
			r->link=t;
			r->rlink=NULL;
		}
}
void deque(){
	struct node *t;
		if(f==NULL && r==NULL)
		printf("LQ Empty");
		else{
			t=f;
			f=t->link;
			t->rlink=NULL;
			f->link=NULL;
			printf("Deleted element is %d",t->x);
			free(t);
		}
}
main(){
	int choice,ch,ele;
	printf("Select 1Insert 2Delete 3 Dispklay");
	do{
		switch(choice){
			case 1: printf("Enter element you want to insert");
			scanf("%d",&ele);
			enque(ele);break;
			case 2:deque();break;
			case 3: display();break;
			default : printf("Wrong Choice");
		}
		printf("")
	}
}

