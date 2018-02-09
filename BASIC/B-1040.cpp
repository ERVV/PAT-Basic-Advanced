#include<stdio.h>
#define V 1000000007

int main()
{
	long long num_P = 0,A = 0, num_T = 0;
	long long ap[100000] = {0}, at[100000] = {0};
	long long sum = 0;
	char c;
	while((c = getchar()) != '\n')
	{
		switch(c)
		{
			case 'P': num_P++; break;
			case 'A':
				ap[A] = num_P;
				at[A++] =num_T;
				break;
			case 'T': num_T++; break;
		}
	}
	for(int i=0; i<A; i++)
	{
		sum += (ap[i] * (num_T - at[i]));
		sum %= V;
	}
	printf("%lld", sum);
	return 0;
}
