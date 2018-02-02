#include<stdio.h>
#include<stdlib.h>
#include <algorithm>
using namespace std;

int main(){
	int n, x, y, i;
	int a[4];
	scanf("%d", &n);
	do {
		for(i=0;i<4;i++){
			a[i] = n % 10;
			n /= 10;
		}
		sort(a, a+4);
		x = 1000 * a[3] + 100 * a[2] + 10 * a[1] + a[0];
		y = 1000 * a[0] + 100 * a[1] + 10 * a[2] + a[3];
		n = x - y;
		if(n!=0) {
			printf("%04d - %04d = %04d", x, y, n);
			if(n != 6174) printf("\n");
		}
		else printf("%04d - %04d = 0000", x, y);
	}while(n != 6174 && n != 0);
	
	return 0;
} 
