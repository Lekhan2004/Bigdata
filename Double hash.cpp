#include <stdio.h>
#include <stdlib.h>
#define n 15
int hash1(int ele) {
    return ele % n;
}
int hash2(int ele) {
	//Set the number here as the nearest prime number less than that of the table size n
    return 13 - (ele % 13);
}

void insert(int ele,int hashtab[]) {
  int i,hkey;
	for(i=0;i<n;i++)  
   {  
    hkey=(hash1(ele)+i*hash2(ele))%n;  
    if(hashtab[hkey] == -1)  
    {  
     hashtab[hkey]=ele;  
      break;  
    }  
   }  
    hashtab[hkey] = ele;
   if(i == n)  
    printf("\nelement cannot be inserted\n"); 
}
void display(int hashtab[]){
	for(int i=0;i<n;i++)
	printf("At Hashtab[%d] : %d\n",i,hashtab[i]);
}
int main(){
/*	printf("Enter size of the Hashtable\n");
	scanf("%d",&n);*/
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
				   //search(ele,hashtab);
				   break;
			case 3:display(hashtab);break;
			case 4:exit(0);	   
		}
	}while(1);
	return 0;
}
