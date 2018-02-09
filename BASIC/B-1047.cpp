#include<stdio.h>

int main()
{
	int n, max = 0, champion;
	int team[1001] = {0};
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		int t, x, grade;
		scanf("%d-%d %d", &t, &x, &grade);
		team[t] += grade;
		if(team[t] > max) 
		{
			max = team[t];
			champion = t;
		}
	}
	printf("%d %d", champion, max);
	return 0;
}
