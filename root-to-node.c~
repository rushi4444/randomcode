#include<stdio.h>
#include<stdlib.h>

int main(){
	int k=0,c=0,size=0,*a=NULL; //c~= current
	int i=0;

	scanf("%d",&k);
	scanf("%d",&size);
	a = (int *) malloc(sizeof(int) * size);
	for (i = 0 ; i < size ; i++){
		scanf("%d",&a[i]);
	}

	while( k != a[c]){
		printf("%d->,",a[c]);
		c = k<a[c]?2*c+1:k>a[c]?2*c+2:size;

		if(k == a[c])
			printf("%d->",a[c]);
		if(c>=size){
			printf("Node not found\n");
			break;
		}
	}
	return 0;
}
