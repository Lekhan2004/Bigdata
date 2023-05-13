#include <stdio.h>
#include <stdlib.h>
struct Node {
    int coef;
    int exp;
    struct Node* next;
}*nn,*temp;
 struct Node* createpoly(struct Node *f)
{
	char ch;
	f=NULL;
	do {
		nn=(struct Node*)malloc(sizeof(struct Node));
		printf("Enter COEF\n");
		scanf("%d",&nn->coef);
		printf("Enter EXP");
		scanf("%d",&nn->exp);
		if(f==NULL)
		{f=nn;
		temp=nn;
		}
		else
		{
			temp->next=nn;
			temp=nn;
		}
		printf("Wanna Continue y/n\n");
		fflush(stdin);
		ch=getchar();
	}while(ch=='y');
	temp->next=NULL;
	return f;
}
struct Node *multiply(struct Node *p1,struct Node*p2){
	struct Node *b=NULL,*t;
	t=p2;
	while(p1!=	NULL){
		while(p2!=NULL){
			nn=(struct Node*)malloc(sizeof(struct Node));
			if(b==NULL)
			{
			b=nn;
			temp=nn;
			}
			else {
			temp->next=nn;
			temp=temp->next;
			}
			nn->coef=p1->coef*p2->coef;
			nn->exp=p1->exp+p2->exp;
			nn->next=NULL;
			p2=p2->next;
		}
		p2=t;
		p1=p1->next;
	}
	return b;
}
void print(struct Node* p) {
    while (p != NULL) {
        printf("%dx^%d ", p->coef, p->exp);
        if (p->next != NULL) {
            printf("+ ");
        }
        p = p->next;
    }
    printf("\n");
}
struct Node * removelp(struct Node*v){
	struct Node*t1=v,*t2,*t;
	while(t1!=NULL){
		t2=t1->next;
		while(t2!=NULL){
			if(t1->exp==t2->exp)
			{t1->coef+=t2->coef;
			t=t2;
			t2=t->next;
			t1->next=t2;			
			free(t);
			}
			else
			t2=t2->next;
				}
				t1=t1->next;
			}return v;
}
int main() {
    struct Node* p1,* p2, *res,*r2;
    p1 = createpoly(p1);
    p2 = createpoly(p2);
    res = multiply(p1,p2);
    printf("pOLY 1");
    print(p1);
    printf("pOLY2: ");
    print(p2);
    r2=removelp(res);
 	printf("Ress= ");
    print(r2);
    return 0;
}
