#include <stdio.h>
#include <math.h>
int stack[100],top=-1;
void push(int x)
{
	stack[++top]=x;
}
int pop()
{
	return stack[top--];
}
int main()
{
	int i,n,rev=0,m,c=0;
	printf("Enter number");
	scanf("%d",&n);
//	m=n;
	while(n!=0)
	{
		push(n%10);
		n=n/10;
		c++;
	}
	for(i=0;i<c;i++)
	rev=rev+((pop())*pow(10,i));
	printf("%d",rev);
}
