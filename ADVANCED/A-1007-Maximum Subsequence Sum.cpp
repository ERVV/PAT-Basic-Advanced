#include<stdio.h>
#include<stdlib.h>

int main()
{
	int N;
	scanf("%d", &N);
	int *data = new int[N], *dp = new int[N], *start_max = new int[N];
	bool flag = false;
	for(int i=0; i<N; i++)
	{
		scanf("%d", &data[i]);
		if(data[i]>=0) flag = true;
	}
	if(!flag)
	{
		printf("0 %d %d", data[0], data[N-1]);
		return 0;
	}
	dp[0] = data[0];
	start_max[0] = 0;
	int max_index = 0;
	for(int i=1; i<N; i++)
	{
		if(dp[i-1] < 0)
		{
			dp[i] = data[i];
			start_max[i] = i;
		}
		else
		{
			dp[i] = data[i] + dp[i-1];
			start_max[i] = start_max[i-1];
		}
		if(dp[i] > dp[max_index]) max_index = i;
	}
	printf("%d %d %d", dp[max_index], data[start_max[max_index]], data[max_index]);
	return 0;
}
