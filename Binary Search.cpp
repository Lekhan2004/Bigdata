#include <stdio.h>
#include <time.h>
int binarysearch(int a[],int n,int x){
	int lb=0,ub=n-1;
	int mid=lb+ub/2,flag=0;
	while(lb<=ub){
		if(x<a[mid])
		{
			lb=0;
			ub=mid-1;
		}
		else if(x>a[mid]){
			lb=mid+1;
			ub=n-1;
		}
		else if(x==a[mid]){
			flag=1;
			break;
		}
		  mid = (lb + ub) / 2; 	}
	return flag;
}
int bsrec(int a[],int lb,int ub,int x)
{
 		
 		 if (lb > ub) {
        return 0;
    }
    int mid=lb+ub/2;
	if(x<a[mid])
		{
			bsrec(a,lb,mid-1,x);
		}
		else if(x>a[mid]){
			bsrec(a,mid+1,ub,x);
		}
		else if(x==a[mid]){
			return 1;
			}
			else return 0;
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
	printf("How do you want to perform Binary Search 1.Non Recursive 2.Recursive");
	scanf("%d",&ch);
	switch(ch){
		case 1:time=clock();
				h=binarysearch(a,n,x);
				if(h==1)
			   printf("Found\n");
			   else 
			   printf("Not Found\n");
			   time=clock();
			   printf("Time taken in Non Recursive is %f",(float)time/CLOCKS_PER_SEC);break;
		case 2:time=clock();
				h=bsrec(a,0,n-1,x);
				if(h==1)
			   printf("Found\n");
			   else 
			   printf("Not Found\n");
			   time=clock()-time;
			   printf("Time taken in Non Recursive is %f",(float)time/CLOCKS_PER_SEC);break;
			   	default :printf("INVALID CHOICE");		   
	}
	return 0;
}
