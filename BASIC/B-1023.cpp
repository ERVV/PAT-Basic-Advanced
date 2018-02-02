#include<stdio.h>

int main()
{
	int number[10];
	for(int i=0; i<10; i++) scanf("%d", &number[i]);
	for(int i=1; i<10; i++)
	{
		if(number[i]) 
		{
			number[i]--;
			printf("%d", i);
			break;
		}
	}
	for(int i=0; i<10; i++)
	{
		while(number[i]--) printf("%d", i);
	}
	return 0;
}
