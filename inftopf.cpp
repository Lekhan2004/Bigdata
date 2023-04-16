#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

char stack[MAX],PF[MAX],inf[MAX],c;
int top=-1;
void push(char c)
{
	stack[++top]=c;
}
char pop(void)
{
	return (stack[top--]);
}
int pre(char p)
{
	switch(p)
	{
		case '*':case '/':case '%': return 5;
	case '+':case '-':return 4;
	default : return 0;
	}
}
int main()
{
    int i,j=0;
	//char c;
	 gets(inf);
	 push('(');
	 strcat(inf,")");
	 for(i=0;inf[i]!='\0';i++)
	 {
	 	if(inf[i]=='(')
	 	  push(inf[i]);
	 	else if(isalpha(inf[i]))
	 	  {
	 	  	PF[j]=inf[i];
	 	  	j++;
			} 
		else if(inf[i]==')')
		    {
		    	while(stack[top]!='(')
		    	   {
		    	   	  PF[j]=pop();
		    	   	  j++;
				   }
				   pop();
			}
        else
            {
            if(pre(stack[top])>=pre(inf[i]))
               {
               	PF[j]=pop();
               	j++;
			   }
			   push(inf[i]);
			}
			PF[j]='\0';
		}   
    	puts(PF);
	return 0;												
}


