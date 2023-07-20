#include <stdio.h>
#include <time.h>
int linearsearch(int a[],int n,int x){
	int i=0,f=0;
	while(i<n){
		if(a[i]==x){
		f=1;break;}
		else f=0;
		i++;
	}
	return f;
}
int lsrec(int a[], int n, int x) {
    if (n == 0)
        return 0;
    else if (a[n - 1] == x)
        return 1;
    else
        return lsrec(a, n - 1, x);
}
int main(){
	int n;
	printf("Enter no of elements");
	scanf("%d",&n);
	clock_t time;
	int a[n],x,h,ch;
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("Enter the element you want to search\n");
	scanf("%d",&x);
	printf("How do you want to perform Linear Search 1.Non Recursive 2.Recursive");
			scanf("%d",&ch);
	switch(ch){
		case 1:time=clock();
				h=linearsearch(a,n,x);
				if(h==1)
			   printf("Found\n");
			   else 
			   printf("Not Found\n");
			   time=clock();
			   printf("Time taken in Non Recursive is %f",(float)time/CLOCKS_PER_SEC);break;
		case 2:if(lsrec(a,n,x))
			   printf("Found\n");
			   else 
			   printf("Not Found\n");
			   time=clock()-time;
			   printf("Time taken in  Recursive is %f",(float)time/CLOCKS_PER_SEC);break;
		       break;
		default :printf("INVALID CHOICE");		   
	}
	return 0;
}
