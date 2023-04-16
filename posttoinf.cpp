#include <stdio.h>
#include <string.h>
#define MAX 100
char stack[MAX][MAX];
int top = -1;
void push(char* c)
{
    top++;
    strcpy(stack[top], c);
}
char* pop()
{
    return stack[top--];
}
int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return 1;
    else
        return 0;
}
int main()
{
    char post[MAX];
    printf("Enter the Postfix Expression : ");
    gets(post);
    int i;
    char  op1[MAX], op2[MAX], inf[MAX],str[2];

    for (i = 0; post[i] != '\0'; i++)
    {
       str[0]=post[i];
        	str[1]='\0';

        if (isOperator(post[i]))
        {
            strcpy(op2, pop());
            strcpy(op1, pop());
            strcpy(inf, op1);
            strcat(inf, str);
            strcat(inf, op2);
            push(inf);
        }
        else
        {
            push(str);
        }
    }
   printf("The Infix Expression is : %s\n", stack[top]);
    return 0;
}

