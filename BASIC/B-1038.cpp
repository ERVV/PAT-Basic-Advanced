#include<stdio.h>

int main()
{
	int n, k;
	int grade[101] = {0}, want[100000];
	int score;
	
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%d", &score);
		grade[score]++;
	}
	scanf("%d", &k);
	for(int i=0; i<k; i++)
	{
		scanf("%d", &score);
		if(i) printf(" ");
		printf("%d", grade[score]);
	}
	return 0;
} 
