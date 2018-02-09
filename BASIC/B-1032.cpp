#include<stdio.h>

typedef struct
{
	int num;
	int sum;
}rec;

int main()
{
	int N;
	int x, y;
	scanf("%d", &N);
	rec school[N] = {0}, max = {0};
	for(int i=0; i<N; i++)
	{
		scanf("%d %d", &x, &y);
		school[x].num = x;
		school[x].sum += y;
		if(school[x].sum > max.sum)
			max = school[x];
	}
	printf("%d %d", max.num, max.sum);
	return 0;
} 
