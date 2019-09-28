#include<stdio.h>
int main(){
	int arr1[3] = { 0, 1, 2 };
	int arr2[3] = { 3, 4, 5 };
	int i = 0;
	int x = 0;
	for (i = 0; i < 3; i++){
		x = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = x;
	}
	for (i = 0; i < 3; i++){
		printf("arr1[%d]=%d\n", i, arr1[i]);
	}
	for (i = 0; i < 3; i++){
		printf("arr2[%d]=%d\n", i, arr2[i]);
	}
	return 0;
}