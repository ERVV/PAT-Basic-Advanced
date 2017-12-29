#include<stdio.h>

int main(){
	int n;
	int b, s, t;
	scanf("%d", &n);
	t = n % 10;
	s = (n / 10) % 10;
	b = n / 100;
	while(b--){
		printf("B");
	}
	while(s--){
		printf("S");
	}
	for(int i=0;i<t;i++){
		printf("%d", i+1);
	}
	return 0;
}
