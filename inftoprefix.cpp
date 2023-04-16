 #include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 100
char pf[MAX],inf[MAX];
int stack[MAX],top=-1;
int prec(char x)
{
 switch(x)
   {
     case '+':
	   case '-':return 6;
	   case '*':
	   case '/':return 8;
     case '(':
     case ')':return 0;
   }
}
void push(char c)
{
  stack[++top]=c;
}
char pop()
{
  return stack[top--];
}
int main()
{
  int j=0;
  char c,h[100];
  gets(inf);
  strcpy(h,strrev(inf));
  push(')');
  strcat(h,"(");
  for(int i=0;h[i]!='\0';i++)
    {
      if(h[i]==')')
	      push(h[i]);
	    else if(isalpha(h[i]))
	      {
	        pf[j]=h[i];
		      j++;
		    }
	    else if(h[i]=='(')
	      {
	 	      while(stack[top]!=')')
		        {
		          pf[j]=pop();
			        j++;
		        }
		      c=pop();
		    }
	    else
	      {
	        while(prec(stack[top])>prec(h[i]))
		        {
		          pf[j]=pop();
			        j++;
			      }
		      push(h[i]);
		    }
	  }
  pf[j]='\0';
  puts(strrev(pf));
}
