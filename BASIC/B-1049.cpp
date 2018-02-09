#include<stdio.h>

int main()
{
	double n, d, sum = 0;
	scanf("%lf", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%lf", &d);
		sum += d * (n - i) * (i + 1);
	}
	printf("%.2lf", sum);
	return 0;
}
