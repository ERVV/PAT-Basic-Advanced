#include<stdio.h>

int main()
{
    int i, sum = 0, a[5];
	char c;
	while((c = getchar()) != '\n') sum += (c-'0');
    if(!sum) printf("ling");
	for(i=0; sum>0; i++)
	{
		a[i] = sum % 10;
		sum /= 10;
	}
	for(i-=1; i>=0; i--)
	{
		switch(a[i])
		{
			case 0: printf("ling"); break;
			case 1: printf("yi"); break;
			case 2: printf("er"); break;
			case 3: printf("san"); break;
			case 4: printf("si"); break;
			case 5: printf("wu"); break;
			case 6: printf("liu"); break;
			case 7: printf("qi"); break;
			case 8: printf("ba"); break;
			case 9: printf("jiu"); break;
		}
		if(i) printf(" ");
	}
	return 0;
}
