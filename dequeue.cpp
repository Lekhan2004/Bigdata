#include <stdio.h>
#define max 3
int dq[max],e,f=0,r=-1;
void insertf(int p)
{
		f--;
		dq[f]=p;
}

void insertr(int p)
{
		r++;
	dq[r]=p;
}
int delf()
{
	int x;
	if(f==0 && r==-1)
	{
	printf("Empty\n");
	return 0;
	}
	else
	{
	x=dq[f];
	f++;
	return x;
	}
}
int delr()
{
	int x;
	if(f==0 && r==-1)
	{
	printf("Cant delete\n");
	return 0;
	}
	else if(f==r)
	{
		x=dq[r];
		f=0;r=-1;
		return x;
	}
	else
	{
		x=dq[r--];
		return x;
	}
}
void display()
{
	int i;
	for(i=f;i<=r;i++)
	printf("%3d",dq[i]);
}
void isfull()
{
	if(r==max-1 && f==0)
	printf("Full");
	else
	printf("Not Full");
}
void isempty()
{
	if(f==0 && r==-1)
	printf("Empty");
	else 
	printf("Not Empty");
}
main()
{
	int choice;
	char ch;
	do {
		printf("Select 1Insertfront 2 Insterrear 3 Deletefront 4 Deleterear 5 Display 6 Isfull 7Isempty\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:if(f==0)
			        printf("Insertion not psbl");
			       else
			{
			printf("Enter the element you want to insert from front\n");
				   scanf("%d",&e);
				   insertf(e);	
			}
			break;
			case 2:if(r==max-1)
	               printf("FULL\n");
				   else
				   {
				   printf("Enter the element you want to insert from rear\n");
				   scanf("%d",&e);
				   insertr(e);
				   }
				   break;		
			case 3:e=delf();
				   printf("Element deleted from front is %d",e);
				   break;		
			case 4:e=delr();
				   printf("Element deleted from back is %d",e);
				   break;	
			case 5:display();
				   break;
			case 6:isfull();break;
			case 7:isempty();break;
			default : printf("Wrong");	            
		}
		printf("You wanna continue y/n\n");
		fflush(stdin);
		ch=getchar();
		
	}while(ch=='y');
		
}


