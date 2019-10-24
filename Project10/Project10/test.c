#include <stdio.h>
#include <stdlib.h>

int Factor(int n) {
	int ret = 1;
	for (int i = 1; i <= n; ++i){
		ret *= i;
	}
	return ret;
}

int main(){
	int sum = 0;
	for (int i = 1; i <= 10; ++i){
		sum += Factor(i);

	}
	printf("%d\n", sum);
	system("pause");
	return 0;
}