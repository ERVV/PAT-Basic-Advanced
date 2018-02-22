#include<stdio.h>

typedef struct P
{
	int exp;
	double coe;
}Poly;

int main()
{
	Poly A[12], B[12], C[22];
	int cnt = 0;
	int m, n;
	scanf("%d", &m);
	for(int i=0; i<m; i++)
		scanf("%d %lf", &A[i].exp, &A[i].coe);
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d %lf", &B[i].exp, &B[i].coe);
	int i_a, i_b;
	for(i_a=0, i_b=0; i_a<m && i_b<n;)
	{
		if(A[i_a].exp == B[i_b].exp)
		{
			double tmp = A[i_a].coe +B[i_b].coe;
			if(tmp != 0)
			{
				C[cnt] = A[i_a];
				C[cnt++].coe = tmp;
			}
			i_a++;
			i_b++;
		}
		else if(A[i_a].exp > B[i_b].exp)
			C[cnt++] = A[i_a++];
		else if(A[i_a].exp < B[i_b].exp)
			C[cnt++] = B[i_b++];
	}
	while(i_a<m)
		C[cnt++] = A[i_a++];
	while(i_b<n)
		C[cnt++] = B[i_b++];
	printf("%d", cnt);
	for(int i=0; i<cnt; i++)
		printf(" %d %.1lf", C[i].exp, C[i].coe);
	return 0;
}
