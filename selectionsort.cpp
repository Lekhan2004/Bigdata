#include<stdio.h>
#include<time.h>
void selectionsort(int a[],int n){
	int min,loc,i,j,t;
	if(n<=1){
		return;
		for(j=0;j<n-1;j++){
			min=a[j];
			loc=j;
			for(i=j+1;i<n;i++){
				if(min>a[i]){
					min=a[i];
					loc=i;
				}
			}
			if(j!=loc){
				t=a[j];
				a[j]=a[loc];
				a[loc]=t;
			}
		}
	}
	selectionsort(a,n-1);
}
int main(){
	int a[100],i,n;
	printf("enter no. of elements:");
	scanf("%d",&n);
	printf("unsorted array is:");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	selectionsort(a,n);
	printf("sorted array is:");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
}
