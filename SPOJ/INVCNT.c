#include <stdio.h>
#include <stdlib.h>
#define MAX 200001

unsigned long long int MergeSort(int *A,int length);
unsigned long long int Merge(int *left,int *right,int *A,int length);

int main(){
	int A[MAX],num_tests,N;
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%d",&N);
		for(int j=0;j<N;j++)
			scanf("%d",A+j);
		printf("%llu\n",MergeSort(A,N));
	}
	return 0;
}

unsigned long long int MergeSort(int *A,int length){
	if(length<2)
		return 0;
	int mid = length/2;
	unsigned long long int left_inv=0,right_inv=0,total_inv=0;
	int *left=NULL,*right=NULL;
	left=(int *)malloc(sizeof(int)*mid);
	right=(int *)malloc(sizeof(int)*(length-mid));
	for(int i=0;i<mid;i++)
		left[i]=A[i];
	for(int i=mid;i<length;i++)
		right[i-mid]=A[i];
	left_inv=MergeSort(left,mid);
	right_inv=MergeSort(right,length-mid);
	total_inv=left_inv+right_inv+Merge(left,right,A,length);
	free(left);
	free(right);
	return total_inv;
}

unsigned long long int Merge(int *left,int *right,int *A,int length){
	unsigned long long int total=0;
	int i=0,j=0,k=0;
	int left_len=length/2, right_len=length-length/2;
	while(i<left_len && j<right_len){
		if(left[i]<=right[j])
			A[k++]=left[i++];
		else{
			total+=(left_len-i);
			A[k++]=right[j++];
		}
	}
	while(i<left_len)
		A[k++]=left[i++];
	while(j<right_len)
		A[k++]=right[j++];
	return total;
}
