#include<stdio.h>
#include<stdlib.h>

int main()
{
	int N, next, now = 0;
	int ans = 0;
	scanf("%d", &N);
	while(N--)
	{
		scanf("%d", &next);
		if(next < now)
		{
			ans += 4 * (now - next);
		}
		else if(next > now)
		{
			ans += 6 * (next - now);
		}
		now = next;
		ans += 5;
	}
	printf("%d", ans);
	return 0;
}
