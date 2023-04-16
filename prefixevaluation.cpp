#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define max 100
int top=-1;
char stack[max],PF[max];
void push(char c)
{
	stack[++top]=c;
}
char pop(void)
{
	return (stack[top--]);
}
int main()
{
	 int i,op1,op2;
	 char x,h[max];
	 gets(PF);
	 strcpy(h,strrev(PF));
	 for(i=0;h[i]!='\0';i++)
	 {
	 	if(isalpha(h[i]))
		 {
		 	printf("Enter %c",h[i]);
		 	scanf("%d",&x);
		 	push(x);
		 }
		else
		{
			op1=pop();
			op2=pop();
			switch(h[i])
			{
				 case '+':push(op1+op2);
				 break;
	   			 case '-':push(op1-op2);
				 break;
				 case '*':push(op1*op2);
				 break;
				 case '/':push(op1/op2);
				 break;
				 case '%':push(op1%op2);
				 break;
	   			}
			}	
				
		 	 }
		 	 printf("Result=%d",stack[top]);
	return 0;
}




