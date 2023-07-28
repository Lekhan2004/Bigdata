#include <stdio.h>
#include <stdlib.h>

int n;
int h1(int ele){
	return ele%n;
}
void insert(int ele,int hashtab[]){
	int x,i,hkey;
	x=ele%n;
	for(i=0;i<n;i++)  
   {  
    hkey=(x+(i*i))%n;  
    if(hashtab[hkey] == -1)  
    {  
     hashtab[hkey]=ele;  
      break;  
    }  
   }  
   if(i == n)  
    printf("\nelement cannot be inserted\n");  
}
void search(int ele,int hashtab[]){
	int i,hkey;
	for(i=0;i<n;i++)  
   {  
    hkey=(ele%n+(i))%n;  
    if(hashtab[hkey] == -1)  
    {  
	printf("Not Found\n"); 
    break;  
    }
	else if(hashtab[hkey]==ele){
		printf("Found\n");
		break;
	}  
   }
   if(i==n)  printf("Not Found\n"); 
}
void display(int hashtab[]){
	for(int i=0;i<n;i++)
	printf("At Hashtab[%d] : %d\n",i,hashtab[i]);
}
int main(){
	printf("Enter size of the Hashtable\n");
	scanf("%d",&n);
	int hashtab[n],ele,choice;
	for(int i=0;i<n;i++)hashtab[i]=-1;
	do{
		printf("Enter the operation you want to perform\n1.Insert\n2.Search\n3.Display\n4.Exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:printf("Enter the key you want to insert\n");
				   scanf("%d",&ele);
				   insert(ele,hashtab);
				   break;
			case 2:printf("Enter the key you want to search\n");
				   scanf("%d",&ele);
				   search(ele,hashtab);
				   break;
			case 3:display(hashtab);break;
			case 4:exit(0);	   
		}
	}while(1);
	return 0;
}
