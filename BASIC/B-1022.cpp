#include<stdio.h>

int main()
{
	int a, b, c, d;
	int k[32], i;
	scanf("%d %d %d", &a, &b, &d);
	c = a + b;
	if(!c) printf("0");
	else
	{
		for(i=0;c;i++)
		{
			k[i] = c % d;
			c /= d;
		}
		for(--i;i>=0;i--)
		{
			printf("%d", k[i]);
		}
	}
	return 0;
} 
