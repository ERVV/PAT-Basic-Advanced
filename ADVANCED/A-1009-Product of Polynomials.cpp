#include<stdio.h>

typedef struct
{
	int exp;
	double coe;
}P;

int main()
{
	double ans[2002] = {0}, coe;
	P A[11];
	int m, n, exp, cnt = 0;
	scanf("%d", &m);
	for(int i=0; i<m; i++)
		scanf("%d %lf", &A[i].exp, &A[i].coe);
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%d %lf", &exp, &coe);
		for(int j=0; j<m; j++)
			ans[exp+A[j].exp] += (coe * A[j].coe);
	}
	for(int i=0; i<2001; i++)
		if(ans[i]!=0) cnt++;
	printf("%d", cnt);
	for(int i=2000; i>=0; i--)
		if(ans[i]!=0)
			printf(" %d %.1lf", i, ans[i]);
	return 0;
}
