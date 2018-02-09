#include<stdio.h>

int main()
{
	char c;
	int n;
	bool flag = false;
	scanf("%d %c", &n, &c);
	for(int i=(n+1)/2; i>0; i--)
	{
		if(flag) printf("\n");
		if(i == (n+1)/2 || i == 1)
		{
			for(int j=0; j<n; j++)
				printf("%c", c);
			flag = true;
		}
		else
		{
			printf("%c",c);
			for(int j=n-2; j>0; j--)
			for(int j=n-2; j>0; j--)
				printf(" ");
			printf("%c",c);
		}
	}
	return 0;
}
