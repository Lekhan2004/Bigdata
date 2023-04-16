#include <stdio.h>
#include <string.h>
#define MAX 100
char stack[MAX][MAX];
int top = -1;

void push(char* item)
{
    top++;
    strcpy(stack[top], item);
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
    char  op1[MAX], op2[MAX], pre[MAX],str[100];

    for (i = 0; post[i] != '\0'; i++)
    {
       str[0]=post[i];
        	str[1]='\0';

        if (isOperator(post[i]))
        {
            strcpy(op2, pop());
            strcpy(op1, pop());

            strcpy(pre, str);
            strcat(pre, op1);
            strcat(pre, op2);

            push(pre);
        }
        else
        {
            push(str);
        }
    }
   printf("The Prefix Expression is : %s\n", stack[top]);
    return 0;
}

