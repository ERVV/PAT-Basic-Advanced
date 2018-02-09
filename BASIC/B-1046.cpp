#include<stdio.h>

int main()
{
	int n;
	int x, y, a, b, u = 0, v = 0;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%d %d %d %d", &x, &a, &y, &b);
		int t = x + y;
		if(a!=b)
		{
			if(a == t) v++;
			if(b == t) u++;
		}
	}
	printf("%d %d", u, v); 
	return 0;
}
