//#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
	int r = 3;
	int row=-1;

	//for(r=0;r<10;r++){
	//	row = r<3?0:r<6?3:6;
	//	printf("r = %d row = %d\n",r,row);
	//}

	for(int row = 0 ; row < 9 ; row++){
		for(int row = 10; row < 20 ; row++){
			cout << row << endl;
		}
		cout << row << endl;
	}

	return 0;
}
