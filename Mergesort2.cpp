#include <stdio.h>
void merge(int a[],int lb,int mid,int ub){
	int i,j,k,p,q;
	p=mid-lb+1;
	q=ub-mid;
	int l[p],r[q];
	for(i=0;i<p;i++)l[i]=a[i+lb];
	for(j=0;j<q;j++)r[j]=a[j+mid+1];
	i=0;j=0;
	k=lb;
	while(i<p && j<q){
		if(l[i]<=r[j]){
			a[k]=l[i];
			i++;
		}
		else {
			a[k]=r[j];
			j++;
		}
		k++;
	}
	while(i<p){
			a[k]=l[i];
			i++;k++;
	}
	while(j<q){
			a[k]=r[j];
			j++;k++;
	}
	}
void ms(int a[],int lb,int ub){
	if(lb<ub){
		int mid=(lb+ub)/2;
		ms(a,lb,mid);
		ms(a,mid+1,ub);
		merge(a,lb,mid,ub);
	}
}
void print(int a[], int n) {
  for (int i = 0; i < n; i++)
    printf("%d ", a[i]);

}
int main(){
	int i,n;
	printf("Enter array size\n");
	scanf("%d",&n);
	int a[n];
	printf("Enter %d array elements\n",n);
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	ms(a,0,n-1);
	printf("The sorted array is:");
print(a,n);
	return 0;
}
