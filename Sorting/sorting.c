#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

int partition(int *list, int start, int end){
	int temp ;
	int pivot = list[start],low,upper;
	low = start;
	upper = end;

	while(low < upper){
		while(pivot >= list[low]){
			low++;
		}
		while(pivot < list[upper]){
			upper--;
		}
		if( low < upper){
			temp = list[low];
			list[low] = list[upper];
			list[upper] = temp;
		}
	}
	temp = list[start];
	list[start] = list[upper];
	list[upper] = temp;
	return upper;
}

void quicksort(int *list,int start,int end){
	int p;
	if(start < end){
		//find partition
		p = partition(list, start, end);
		quicksort(list,start,p-1);
		quicksort(list,p+1,end);
	}
}

void merge(int * array, int start, int mid , int end){
	int *temp = (int *) malloc ((end-start+1)* sizeof(int));
	int i = start;
	int j = mid+1;
	int k = 0 ;

	while( i <= mid && j <= end ){
		if( array[i] < array[j] ){
			temp[k] = array[i];
			k++;i++;
		}
		else if(array[i] >= array[j]){
			temp[k] = array[j];
			k++;j++;	
		}
	}
	while(i <= mid){
		temp[k] = array[i];
		k++;i++;
	}
	while(j <= end){
		temp[k] = array[j];
		k++;j++;
	}
	k--;
	while(k >= 0){
		array[end] = temp[k];
		k--;end--;
	}

	free(temp);
}
void mergesort(int *list, int start, int end){
	int mid = (start+end)/2;
	if(start < end){
		mergesort(list , start, mid);
		mergesort(list , mid+1 , end);
		merge(list,start,mid,end);
	}
}
