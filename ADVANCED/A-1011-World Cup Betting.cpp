#include<stdio.h>

int main()
{
	int flag[3];
	double profit, max[3] = {0}, odd;
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
		{
			scanf("%lf", &odd);
			if(odd > max[i])
			{
				flag[i] = j;
				max[i] = odd;
			}
		}
	profit = 2*(0.65 * max[0] * max[1] * max[2] - 1);
	for(int i=0; i<3; i++)
		switch(flag[i])
		{
			case 0: printf("W "); break;
			case 1: printf("T "); break;
			case 2: printf("L "); break;
		}
	printf("%.2lf", profit);
	return 0;
}
