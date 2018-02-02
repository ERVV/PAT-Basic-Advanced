#include <stdio.h>
#include <math.h>

int main()
{
	int N, level;
	char sign;
	scanf("%d %c", &N, &sign);
	level = int(sqrt((N+1)/2));
	int remain = N - level * level * 2 + 1;
	
	int t_level = 0;
	while(t_level < level)
	{
		for(int i=0; i<t_level; i++) printf(" ");
		int n = (level - t_level) * 2 - 1;
		for(int i=0; i<n; i++) printf("%c", sign);
		printf("\n");
		t_level++;
	}
	for(int i=1; i<level; i++)
	{
		for(int j=0; j<level-i-1; j++) printf(" ");
		for(int j=0; j<2*i+1; j++) printf("%c", sign);
		printf("\n");
	}
	if(remain) printf("%d", remain);
	return 0;
}
