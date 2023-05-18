/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
struct node {
    struct node*r,*l;
    char c;
}*root=NULL,*nn,*p;;
int top=-1;
struct node *stack[5];
void push(struct node *t){
    top++;
    stack[top]=t;
}
struct node *create(struct node *t)
{
    int ch;
    push(NULL);
    nn=(struct node *)malloc(sizeof(struct node ));
    scanf("%c",&nn->c);
    t=nn;
    p=nn;
    while(p!=NULL){
        printf("Right Child for %c ",p->c);
        scanf("%d",&ch);
        if(ch){
               nn=(struct node *)malloc(sizeof(struct node ));
             scanf("%c",&nn->c);
             p->r=nn;push(p->r);
        }
        else 
        p->r=NULL;
         printf("Left Child for %c ",p->c);
           scanf("%d",&ch);
           if(ch){
           nn=(struct node *)malloc(sizeof(struct node ));
             scanf("%c",&nn->c);
             p->l=nn;
             p=nn;
               
           }
             else {
                 p->l=NULL;
                 p=pop();
             }
    }
      return t;
}
/*void preorder(y*t){
    p=t;
    push(NULL);
    
}*/
void main()
{
    int ch,x,h;
    do{
        printf("Select 1CREATE 2INORDER 3 EXIT ");
        scanf("%d",&ch);
        switch(ch){
            case 1:root=create(root);break;
            //case 2:preorder(root);
            default : printf("Wrong");
        }printf("Contine ? 1/0");
        scanf("%d",&x);
    }while(x==1);

}
