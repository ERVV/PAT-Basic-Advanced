#include<stdio.h>

main(){
	int m, n;
	scanf("%d %d", &n, &m);
	m = m%n;
	int *a = new int[n];
	for(int i=0;i<n;i++) scanf("%d", &a[i]);
	
	bool flag = false;
	for(int i=n-m;i<n;i++){
		if(flag) printf(" ");
		else flag = true;
		printf("%d", a[i]);
	}
	for(int i=0;i<n-m;i++){
		if(flag) printf(" ");
		else flag = true;
		printf("%d",a[i]);
	}
	return 0;
}
