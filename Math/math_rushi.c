#include<stdio.h>
#include<stdlib.h>
#include<math.h>



/*
This function finds out whether the given number is prime or not.
*/
int primes(int X){
	int fac_count = 0, i = 0;
	int n = sqrt(X);

	for( i = 1 ; i <= n ; i++ ){
		if( X % i == 0 ){
			fac_count += 2;
		}
	}
	
	if(fac_count == 2)
		return 1;
	else
		return 0;
}

/*
This function finds out the factors and number of factors of a given number.
The function returns the int pointer.
Index 0 gives the number of factors and after that index 1 onwards actual factors are stored.
*/

int *factors(int X){
	int fac_count = 0, i = 0 ,j = 1;
	int n = sqrt(X);
	int start = 0 ,end = (2 * n) - 1;

	int *temp_arr = (int * ) malloc (2 * n * sizeof(int));
	int *fac_arr;

	for( start = 0 , i = 1 ; start < n && i <= n ; i++ ){
		if(X % i == 0){
			fac_count += 2;
			temp_arr[start++] = i;
			temp_arr[end--] = X/i;
		}
	}
	
	fac_arr = (int *)malloc((2 * fac_count + 1)  * sizeof(int));
	fac_arr[0] = fac_count ;

	for( i = 0 ; i < 2 * n ; i++ ){
		if(temp_arr[i] != 0){
			fac_arr[j++] = temp_arr[i];
		}
	}
	free(temp_arr);
	return fac_arr;
}
