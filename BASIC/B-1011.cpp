#include<stdio.h>

int main()
{
	double a, b, c;
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		scanf("%lf %lf %lf", &a, &b, &c);
		if(i) printf("\n");
		printf("Case #%d: ", i+1);
		if(a+b>c) printf("true");
		else printf("false");
	}
	return 0;
} 
