#include <stdio.h>
#include <stdlib.h>
struct Node {
    int coef;
    int exp;
    struct Node* next;
}*nn,*temp;
/*struct Node* create(int coef, int exp) {
    nn = (struct Node*) malloc(sizeof(struct Node));
    nn->coef = coef;
    nn->exp = exp;
    nn->next = NULL;
    return nn;
}*/
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
	int p,q,r,s;
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
			}p=p1->coef;
			q=p1->exp;
			r=p2->coef;
			s=p2->exp;
			nn->coef=p*r;
			nn->exp=q+s;
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
int main() {
    struct Node* p1,* p2, *res;
    p1 = createpoly(p1);
    p2 = createpoly(p2);
    res = multiply(p1,p2);
    printf("pOLY 1");
    print(p1);
    printf("pOLY2: ");
    print(p2);
 	printf("Ress= ");
    print(res);
    return 0;
}
