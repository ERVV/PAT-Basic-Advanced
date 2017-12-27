#include<stdio.h>

typedef struct 
{
	char name[11];
	char num[11];
	int gra;
} rec;

int main()
{
	int n, max = 0, min = 0;
	scanf("%d", &n);
	rec l[n];
	for(int i=0; i<n; i++)
	{
		scanf("%s %s %d", l[i].name, l[i].num, &l[i].gra);
		if(l[i].gra > l[max].gra) max = i;
		if(l[i].gra < l[min].gra) min = i;
	}
	printf("%s %s", l[max].name, l[max].num);
	printf("\n");
	printf("%s %s", l[min].name, l[min].num);
	return 0;
} 
