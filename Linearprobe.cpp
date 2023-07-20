#include <stdio.h>
#include <stdlib.h>

int n;
int h1(int ele){
	return ele%n;
}
void insert(int ele,int hashtab[]){
	int x;
	x=h1(ele);
	if(hashtab[x]==-1){
		hashtab[x]=ele;
	}else{
		int i=0;
		while(1){
			x=h1(x)+i;
			if(hashtab[x]==-1){
					hashtab[x]=ele;
					break;
			}
	}
}
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
		printf("Enter the operation you want to perform\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:printf("Enter the key you want to insert\n");
				   scanf("%d",&ele);
				   insert(ele,hashtab);
				   break;
			case 2://del();
			case 3:display(hashtab);break;
			case 4:exit(0);	   
		}
	}while(1);
	return 0;
}
