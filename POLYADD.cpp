#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coef;
    int exp;
    struct Node* next;
};

typedef struct Node* Poly;

Poly createNode(int coef, int exp) {
    Poly nn = (Poly) malloc(sizeof(struct Node));
    nn->coef = coef;
    nn->exp = exp;
    nn->next = NULL;
    return nn;
}

Poly addPolynomial(Poly p1, Poly p2) {
    Poly head = NULL, tail = NULL;
    while (p1 != NULL && p2 != NULL) {
        if (p1->exp > p2->exp) {
            if (tail == NULL) {
                head = tail = createNode(p1->coef, p1->exp);
            } else {
                tail->next = createNode(p1->coef, p1->exp);
                tail = tail->next;
            }
            p1 = p1->next;
        } else if (p1->exp < p2->exp) {
            if (tail == NULL) {
                head = tail = createNode(p2->coef, p2->exp);
            } else {
                tail->next = createNode(p2->coef, p2->exp);
                tail = tail->next;
            }
            p2 = p2->next;
        } else {
            int coefSum = p1->coef + p2->coef;
            if (tail == NULL) {
                head = tail = createNode(coefSum, p1->exp);
            } else {
                tail->next = createNode(coefSum, p1->exp);
                tail = tail->next;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while (p1 != NULL) {
        if (tail == NULL) {
            head = tail = createNode(p1->coef, p1->exp);
        } else {
            tail->next = createNode(p1->coef, p1->exp);
            tail = tail->next;
        }
        p1 = p1->next;
    }
    while (p2 != NULL) {
        if (tail == NULL) {
            head = tail = createNode(p2->coef, p2->exp);
        } else {
            tail->next = createNode(p2->coef, p2->exp);
            tail = tail->next;
        }
        p2 = p2->next;
    }
    return head;
}

void printPolynomial(Poly p) {
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
    Poly p1, p2, sum;
    p1 = createNode(5, 2);
    p1->next = createNode(3, 1);
    p1->next->next = createNode(1, 0);

    p2 = createNode(4, 3);
    p2->next = createNode(2, 2);
    p2->next->next = createNode(1, 1);

    sum = addPolynomial(p1, p2);

    printf("p1: ");
    printPolynomial(p1);

    printf("p2: ");
    printPolynomial(p2);

    printf("sum: ");
    printPolynomial(sum);

    return 0;
}

