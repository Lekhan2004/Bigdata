#include <stdio.h>
void swap(int *a,int *b){
	int tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
}
int partition(int a[],int lb,int ub){
	int pivot=a[lb];
	int i=lb;
	int j=ub;
	while(i<j){
		while(a[i]<=pivot){
		i++;
		}
		while(a[j]>pivot){
		j--;
		}
		if(i<j)swap(&a[i],&a[j]);
	}
	swap(&a[j],&pivot);
	return j;
}
void qs(int a[],int lb,int ub){
	if(lb<ub){
		int loc=partition(a,lb,ub);
		qs(a,lb,loc-1);
		qs(a,loc+1,ub);
	}
}
int main(){
	int i,n;
	printf("Enter array size\n");
	scanf("%d",&n);
	int a[n];
	printf("Enter %d array elements\n",n);
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	qs(a,0,n-1);
	printf("The sorted array is:");
	for(i=0;i<n;i++)printf("%d",a[i]);
	return 0;
}
