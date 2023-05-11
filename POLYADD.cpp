#include <stdio.h>
#include <stdlib.h>
struct Node {
    int coef;
    int exp;
    struct Node* next;
}*nn,*temp;
struct Node* create(int coef, int exp) {
    nn = (struct Node*) malloc(sizeof(struct Node));
    nn->coef = coef;
    nn->exp = exp;
    nn->next = NULL;
    return nn;
}
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
struct Node* add(struct Node* p1, struct Node* p2) {
    struct Node*a = NULL, *b =NULL;
    while (p1 != NULL && p2 != NULL) {
        if (p1->exp > p2->exp) {
            if (b == NULL) {
                a = b = create(p1->coef, p1->exp);
            } else {
                b->next = create(p1->coef, p1->exp);
                b = b->next;
            }
            p1 = p1->next;
        } else if (p1->exp < p2->exp) {
            if (b == NULL) {
                a = b = create(p2->coef, p2->exp);
            } else {
                b->next = create(p2->coef, p2->exp);
                b = b->next;
            }
            p2 = p2->next;
        } else {
            int coefSum = p1->coef + p2->coef;
            if (b == NULL) {
                a = b = create(coefSum, p1->exp);
            } else {
                b->next = create(coefSum, p1->exp);
                b = b->next;
            }
            p1 = p1->next;
            p2 = p2->next; }
    }
    while (p1 != NULL) {
        if (b == NULL) {
            a = b = create(p1->coef, p1->exp);
        } else {
            b->next = create(p1->coef, p1->exp);
            b = b->next;
        }
        p1 = p1->next;
    }
    while (p2 != NULL) {
        if (b == NULL) {
            a = b = create(p2->coef, p2->exp);
        } else {
            b->next = create(p2->coef, p2->exp);
            b = b->next;
        }
        p2 = p2->next;
    }
    return a;
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
    struct Node* p1,* p2, *sum;
    p1 = createpoly(p1);
    p2 = createpoly(p2);
    sum = add(p1,p2);
    printf("pOLY 1");
    print(p1);
    printf("pOLY2: ");
    print(p2);
    printf("Ress= ");
    print(sum);
    return 0;
}
