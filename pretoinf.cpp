#include <stdio.h>
#include <string.h>
#include <ctype.h>
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
int isoperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return 1;
    else
        return 0;
}
int main()
{
    char pre[MAX];

    printf("Enter the Prefix Expression : ");
    gets(pre);
    int i;
    char  op1[MAX], op2[MAX], inf[MAX],str[100],rev[100];
strcpy(rev,strrev(pre));
    for (i = 0; rev[i] != '\0'; i++)
    {
       str[0]=rev[i];
        	str[1]='\0';
        if (isoperator(rev[i]))
        {
            push(str);
        }
        else
        {
          strcpy(op2, pop());
            strcpy(op1, pop());
            strcpy(inf, op2);
            strcat(inf, str);
            strcat(inf, op1);
            push(inf);
        }
    }
   printf("The Infix Expression is : %s\n", stack[top]);
    return 0;
}

